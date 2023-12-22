#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "18.12.2.h"
#include <iostream>

using std::cout;
using std::endl;

//Ĭ�Ϲ��캯��
Cpmv::Cpmv()
{
	cout << "default constructor called\n";

	//***ע***��������Ҫ�У�
	//��û�еĻ���piֵΪnullptr
	pi = new Info;

	pi->qcode = "no data";
	pi->zcode = "no data";

	Display();
}
//���캯��
Cpmv::Cpmv(std::string q, std::string z)
{
	cout << "constructor called\n";

	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;

	Display();
}
//���ƹ��캯��
Cpmv::Cpmv(const Cpmv& cp)
{
	cout << "copy const called\n";

	pi = new Info;
	pi->qcode = (cp.pi)->qcode;
	pi->zcode = (cp.pi)->zcode;

	Display();
}
//�ƶ����ƹ��캯��
Cpmv::Cpmv(Cpmv&& mv)
{
	cout << "move constructor called\n";

	//��ȡ��ַ
	this->pi = mv.pi;

	mv.pi = nullptr;

	Display();
}
//��������
Cpmv::~Cpmv()
{
	cout << "destructor called\n";

	Display();

	delete pi;
}
//��ֵ��������غ���
Cpmv& Cpmv::operator= (const Cpmv& cp)
{
	cout << "operator=() called" << endl;

	if (this == &cp)
		return *this;

	//�ͷ�ԭ��piָ��Ľṹ��ռ�õ��ڴ�
	delete pi;

	pi = new Info;
	pi->qcode = (cp.pi)->qcode;
	pi->zcode = (cp.pi)->zcode;

	Display();

	return *this;
}
//�ƶ���ֵ��������غ���
Cpmv& Cpmv::operator= (Cpmv&& mv)
{
	cout << "move operator=() called" << endl;

	if (this == &mv)
		return *this;

	//***ע***�ͷ�ԭ��piָ��Ľṹ��ռ�õ��ڴ�
	delete pi;

	pi = mv.pi;//��ȡ��ַ������Ȩ

	mv.pi = nullptr;

	Display();

	return *this;
}
//+��������غ���
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
		cout << "pi�����ó��˿�ָ��\n";
	else
	{
		cout << "q��" << pi->qcode <<"\t";
		cout << "z��" << pi->zcode << endl;
	}
}

#endif