#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include "14.6.3.h"
#include <iostream>
using std::cout;
using std::endl;

Gloam::Gloam(int g, const char* s) :Frabjous(s)//���캯����Ĭ�Ϲ��캯��
{
	glip = g;
}
Gloam::Gloam(int g, const Frabjous& f) : Frabjous(f)//���ƹ��캯��
{
	glip = g;
}
void Gloam::tel1()
{
	Frabjous::tell();
	cout << endl << glip;
}

#endif