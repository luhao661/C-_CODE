#define _CRT_SECURE_NO_WARNINGS 1

#ifndef FXT_16_9_1_H
#define FXT_16_9_1_H
#include <string>
#include <iostream>

class RQ1
{
private:
	std::string st;

public:
	//Ĭ�Ϲ��캯��
	RQ1()
	{
		st = " ";
	}
	//���캯��
	RQ1(const char* s)
	{
		st = *s;
	}

	//P352
	//����ʹ���Զ����ɵ�
	//Ĭ���������������ƹ��캯������ֵ��������غ���
	void show(void)
	{
		std::cout << st << std::endl;
	}
};

#endif