#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "14.6.2.h"
#include <iostream>
using std::cout;
using std::endl;

Gloam::Gloam(int g, const char* s):fb(s)//���캯����Ĭ�Ϲ��캯��
{
	glip = g;
}

Gloam::Gloam(int g, const Frabjous& f):fb(f)//���ƹ��캯��
{
	glip = g;
}

void Gloam::tel1()
{
	fb.tell();
	cout << endl << glip;
}

#endif