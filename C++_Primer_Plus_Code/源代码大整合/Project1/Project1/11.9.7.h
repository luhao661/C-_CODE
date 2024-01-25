#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX11_9_7
#define BCLX11_9_7

#include <iostream>

class Complex
{
private:
	double m_real_part;
	double m_imaginary_part;
public:
	Complex();
	Complex(double real,double imaginary);
	~Complex();

	friend std::istream& operator>>(std::istream& is, Complex& com);
	friend std::ostream& operator<<(std::ostream& os, const Complex& com);

	Complex operator+(const Complex &com)const;
	Complex operator-(const Complex& com)const;
	Complex operator-()const;
	Complex operator~()const;

	//�����������
	Complex operator*(const Complex& com)const;
	//������ʵ�����
	Complex operator*(double x)const;
	friend Complex operator*(double x,const Complex& com );
};

#endif /*BCLX11_9_7*/