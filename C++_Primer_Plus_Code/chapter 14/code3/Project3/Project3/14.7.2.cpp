#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "14.7.2.h"

using std::cout;
using std::cin;
using std::endl;

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:std::string(l), PairArray((int*)yr, (int*)bot, y)//***ע***����Ҫ��ǿ������ת��
{
	number_of_years = y;
}

Wine::Wine(const char* l, int y) : std::string(l), PairArray(y, y)
{
	number_of_years = y;
}

void Wine::GetBottles(void)
{
	cout << "Enter " << (const std::string&)*this << " data for " << number_of_years << " year(s) : " << endl;

	//***ע***
	//valarray�໹�з���resize()����������Ĵ�С
	//��������ʹ�ã�
	//д��һ��
	/*this->first().resize(number_of_years);
	this->second().resize(number_of_years);*/
	//д������
	/*Pair::first().resize(number_of_years);
	Pair::second().resize(number_of_years);*/
	//д������
	first().resize(number_of_years);
	second().resize(number_of_years);

	for (int i = 0; i < number_of_years; i++)
	{
		cout << "Enter year : ";
		cin >> (PairArray::first())[i];//��дΪ��this->first()[i]
		cout << "Enter bottles for that year: ";
		cin >> (PairArray::second())[i];
	}
}

void Wine::Show(void) const
{
	cout << "Wine : " << (const std::string&)*this << endl;
	cout << "Year\t" << "Bottles\n";

	for (int i = 0; i < number_of_years; i++)
	{
		cout << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;
	}
}

const std::string& Wine::Label(void)const
{
	return (const std::string&)*this;
}

int Wine::sum(void)const
{
	return PairArray::second().sum();
}

#endif