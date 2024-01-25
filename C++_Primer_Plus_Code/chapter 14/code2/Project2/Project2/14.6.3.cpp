#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include "14.6.3.h"
#include <iostream>
using std::cout;
using std::endl;

Gloam::Gloam(int g, const char* s) :Frabjous(s)//构造函数，默认构造函数
{
	glip = g;
}
Gloam::Gloam(int g, const Frabjous& f) : Frabjous(f)//复制构造函数
{
	glip = g;
}
void Gloam::tel1()
{
	Frabjous::tell();
	cout << endl << glip;
}

#endif