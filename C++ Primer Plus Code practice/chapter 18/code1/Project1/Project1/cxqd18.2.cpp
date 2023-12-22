#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "cxqd18.2.h"

using namespace std;

// implementation
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless& f) : n(f.n)
{
    ++ct;
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

//移动构造函数
Useless::Useless(Useless&& f) : n(f.n)
{                       //***右值引用***  (由于修改了f对象，所以不使用const)
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc;       // steal address 窃取地址的所有权
    //实际数据内容还留在原来的地方，而只修改了记录，
    //这称为***移动语义***

    //对右值这个临时对象的私有成员进行处理，好让调用析构函数时运行正常
    f.pc = nullptr;  // give old object nothing in return
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete[] pc;
}

Useless Useless::operator+(const Useless& f)const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);

    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];

    cout << "temp object:\n";
    cout << "Leaving operator+()\n";

    return temp;//返回的是个右值，调用移动构造函数
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void*)pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

#endif