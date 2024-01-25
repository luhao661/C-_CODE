#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "18.12.2.h"
#include <iostream>

using std::cout;
using std::endl;

//默认构造函数
Cpmv::Cpmv()
{
	cout << "default constructor called\n";

	//***注***此语句必须要有，
	//若没有的话，pi值为nullptr
	pi = new Info;

	pi->qcode = "no data";
	pi->zcode = "no data";

	Display();
}
//构造函数
Cpmv::Cpmv(std::string q, std::string z)
{
	cout << "constructor called\n";

	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;

	Display();
}
//复制构造函数
Cpmv::Cpmv(const Cpmv& cp)
{
	cout << "copy const called\n";

	pi = new Info;
	pi->qcode = (cp.pi)->qcode;
	pi->zcode = (cp.pi)->zcode;

	Display();
}
//移动复制构造函数
Cpmv::Cpmv(Cpmv&& mv)
{
	cout << "move constructor called\n";

	//窃取地址
	this->pi = mv.pi;

	mv.pi = nullptr;

	Display();
}
//析构函数
Cpmv::~Cpmv()
{
	cout << "destructor called\n";

	Display();

	delete pi;
}
//赋值运算符重载函数
Cpmv& Cpmv::operator= (const Cpmv& cp)
{
	cout << "operator=() called" << endl;

	if (this == &cp)
		return *this;

	//释放原来pi指向的结构体占用的内存
	delete pi;

	pi = new Info;
	pi->qcode = (cp.pi)->qcode;
	pi->zcode = (cp.pi)->zcode;

	Display();

	return *this;
}
//移动赋值运算符重载函数
Cpmv& Cpmv::operator= (Cpmv&& mv)
{
	cout << "move operator=() called" << endl;

	if (this == &mv)
		return *this;

	//***注***释放原来pi指向的结构体占用的内存
	delete pi;

	pi = mv.pi;//窃取地址的所有权

	mv.pi = nullptr;

	Display();

	return *this;
}
//+运算符重载函数
Cpmv Cpmv::operator+ (const Cpmv& obj) const
{
	Cpmv temp;

	temp.pi = new Info;
	(temp.pi)->qcode = pi->qcode + (obj.pi)->qcode;
	(temp.pi)->zcode = pi->zcode + (obj.pi)->zcode;

	return temp;
}

void Cpmv::Display() const
{
	if (pi == nullptr)
		cout << "pi被设置成了空指针\n";
	else
	{
		cout << "q：" << pi->qcode <<"\t";
		cout << "z：" << pi->zcode << endl;
	}
}

#endif