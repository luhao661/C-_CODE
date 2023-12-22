#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "9.6.4.h"

namespace SALES
{
	//��ar[]�п���n�����ݵ��ṹ���е�sales�����У�
	//���㲢�洢����������Ա��ֵ,
	//sales�������п��еĿռ䣬����пռ��Ԫ�ظ�ֵΪ0
	void setSales(Sales& s, const double ar[], int n)
	{
		if (n > QUARTERS)
			n = QUARTERS;

		memcpy(s.sales,ar,n*sizeof(double));

		while (n != QUARTERS)//��nΪ1��������1��2��3��Ӧ��Ԫ��ֵ��Ϊ0
			s.sales[n++] = 0;

		double sum = 0,max,min;
		max = min = s.sales[0];

		for (int i = 0; i < n; i++)
		{
			sum += s.sales[i];

			s.sales[i] > max ? max = s.sales[i] : max;

			if (s.sales[i] < min)
				min = s.sales[i];
		}
		
		s.average = sum / n;
		s.max = max;
		s.min = min;
	}
	//����ʽ�ش���4��slaes��ֵ��������ṹ���е�sales�����У�
	//���㲢�洢����������Ա��ֵ��
	void setSales(Sales& s)
	{
		using std::cout;
		using std::cin;

		cout << "������4������ֵ��";

		for (int i = 0; i < QUARTERS; i++)
			while (!(cin >> s.sales[i]))
			{
				cout << "Bad input. Please enter a number:  ";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}

		//������
		/* int i=0;
		    double ar[QUARTERS]={};
			do
			{
				cout << "������һ�����֣�";
				if (!(cin >> ar[i]))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "Bad input. Please enter a number:  ";
					cin >> ar[i];
				}
			i++;
			}while(i<QUAQUARTERS);*/

		cin.get();
		double sum = 0, max, min;
		max = min = s.sales[0];

		for (int i = 0; i < QUARTERS; i++)
		{
			sum += s.sales[i];

			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}

		s.average = sum / QUARTERS;
		s.max = max;
		s.min = min;
	}
	//��ʾ�ṹ�д洢��������Ϣ
	void showSales(const Sales& s)
	{
		using std::cout;
		using std::endl;

		cout << "sales: ";
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << "  ";

		cout.put('\n');
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
};

//������
/*
using namespace SALES;

void setSales(Sales& s, const double ar[], int n)
{

}
..........

*/

#endif