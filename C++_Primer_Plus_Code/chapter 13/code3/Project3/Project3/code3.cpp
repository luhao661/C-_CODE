#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//13.11 �����ϰ
//1.
//����13.11.1.cpp
#if 0
#include "13.11.1.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd & disk)//���Խ��ж�̬����(����ʹ�ö�����������ķ���)
{												//���virtual�麯��
	disk.Report();
}
#endif


//2.
//����13.11.2.cpp
#if 0
#include "13.11.2.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd& disk)//���Խ��ж�̬����(����ʹ�ö�����������ķ���)
{												//���virtual�麯��
	disk.Report();
}
#endif


//3.
//����13.11.3.cpp
#if 0
#include "13.11.3.h"

const int SIZE = 3;
char* getlabel(void);        //���ַ�����ռ���ڴ���ж�̬����

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DmaABC* p_dma[SIZE];//����һ�����飬ÿ��Ԫ�ض���ָ���������ָ��
    char* p_label_data;
    int rating;
    char kind;
    char color_data[40];
    char style[40];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the label name: ";
        p_label_data = getlabel();
        cout << "Enter the number of rating: ";
        cin >> rating;
        
        cout << "Enter 1 for baseDMA or "
            << "2 for lacksDMA or "<<"3 for hasDMA:";

        while (!(cin >> kind) || (kind != '1' && kind != '2'&&kind!='3'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 or 3 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        cin.get();//���ĵ����з�

        if (kind == '1')
            p_dma[i] = new baseDMA(p_label_data,rating);
        else if(kind=='2')
        {
            cout << "Enter the color: ";
            cin.getline(color_data,40);
            p_dma[i] = new lacksDMA(color_data, p_label_data, rating);
        }
        else
        {
            cout << "Enter the style: ";
            cin.getline(style, 40);
            p_dma[i] = new hasDMA(style, p_label_data, rating);
        }

        delete p_label_data;
        //while (cin.get() != '\n')//���ĵ����з�������getline()����ȡ�����ڶ��μ�֮�������
        //    continue;//����Ҫ����Ϊgetline��ѻ��з��滻��'\0'
    }

    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete p_dma[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}

char* getlabel(void)        // return pointer to new string
{
    using std::cout;
    using std::cin;

    char temp[80];      // temporary storage �������������ӣ��Զ��洢��

    cin >> temp;        //temp�����ݴ����������

    char* pn = new char[strlen(temp) + 1];//����������ַ���������̬����һ���ڴ�ռ�

    strcpy(pn, temp); // copy string into smaller space 
                                 //***ע***strcpy()��⵽temp�е�'\0'���'\0'Ҳ������pnָ����ڴ�ռ����Ӧλ�ã�Ȼ��ֹͣ����
    return pn;          // temp lost when function ends
}//��������ʱ��pn�����٣�����ָ����ڴ�����(��)��������

#endif


//4.
//����13.11.4.cpp
#if 0
int main()
{


    return 0;
}
#endif