#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "14.7.3.h"
#include <cstdlib>         // (or stdlib.h) for rand(), NULL
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/**********************************************************************/

// Worker methods
Worker::~Worker() { }//***ע***����Ҫд

// protected methods
void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

/**********************************************************************/

// Waiter methods
void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

// protected methods
void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

/**********************************************************************/

// Singer methods

char* Singer::pv[Singer::Vtypes] = { (char*)"other", (char*)"alto", (char*)"contralto",//����һ���ñ���������Ԫ�ظ���������
    (char*)"soprano", (char*)"bass", (char*)"baritone", (char*)"tenor" };   //ÿ������Ԫ�ض���ָ��char���͵�ָ��

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

// protected methods
void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << '\n';
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    while (cin.get() != '\n')
        continue;
}

/**********************************************************************/

// SingingWaiter methods

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Show() const                //***ע***
{                                                                       //��ֱ��ʹ��void SingingWaiter::Show() const    
    cout << "Category: singing waiter\n";    //{Singer::Show(); Waiter::Show();}
    Worker::Data();                                           //������Worker::Show()����
    Data();                             //����ʹ��ģ�黯��ʽ
}                                           //������Data()�������

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
//void Customer::set(long when)
//{
//    processtime = std::rand() % 3 + 1;
//    arrive = when;
//}

#endif