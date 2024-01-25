#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX18_12_2_H
#define BCLX18_12_2_H

#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};

private:
	Info* pi;

public:
	//默认构造函数
	Cpmv();
	//构造函数
	Cpmv(std::string q, std::string z);
	//复制构造函数
	Cpmv(const Cpmv& cp);
	//移动复制构造函数
	Cpmv(Cpmv &&mv);
	//析构函数
	~Cpmv();

	//赋值运算符重载函数
	Cpmv& operator= (const Cpmv& cp);
	//移动赋值运算符重载函数
	Cpmv& operator= (Cpmv&& mv);
	//+运算符重载函数
	Cpmv operator+ (const Cpmv& obj) const;

	void Display() const;
};

#endif