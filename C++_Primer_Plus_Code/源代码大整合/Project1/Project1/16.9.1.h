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
	//默认构造函数
	RQ1()
	{
		st = " ";
	}
	//构造函数
	RQ1(const char* s)
	{
		st = *s;
	}

	//P352
	//可以使用自动生成的
	//默认析构函数、复制构造函数、赋值运算符重载函数
	void show(void)
	{
		std::cout << st << std::endl;
	}
};

#endif