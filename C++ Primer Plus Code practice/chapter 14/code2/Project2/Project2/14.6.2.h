#define _CRT_SECURE_NO_WARNINGS 1

#ifndef FXT14_6_2_H
#define FXT14_6_2_H

#include <iostream>
using std::cout;

class Frabjous
{
private:
	char fab[20];

public:
	//Frabjous(const char* s = "C++") :fab(s) ����charָ���ֵ���ܳ�ʼ��char�ַ����� 
	Frabjous(const char* s = "C++")
	{
		strcpy(fab,s);
	}
	virtual void tell() 
	{
		cout << fab; 
	}
};

class Gloam
{
private:
	Frabjous fb;
	int glip;

public:
	Gloam(int g = 0, const char* s = "C++");//���캯����Ĭ�Ϲ��캯��
	Gloam(int g, const Frabjous& f);//���ƹ��캯��
	void tel1();
};

#endif /*FXT14_6_2_H*/