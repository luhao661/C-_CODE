#define _CRT_SECURE_NO_WARNINGS 1

#ifndef A_9_6_4_H
#define A_9_6_4_H

namespace SALES
{
	const int QUARTERS = 4;

	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	//��ar[]�п���n�����ݵ��ṹ���е�sales�����У�
	//���㲢�洢����������Ա��ֵ,
	//sales�������п��еĿռ䣬����пռ��Ԫ�ظ�ֵΪ0
	void setSales(Sales& s, const double ar[],int n);
	//����ʽ�ش���4��slaes��ֵ��������ṹ���е�sales�����У�
	//���㲢�洢����������Ա��ֵ��
	void setSales(Sales &s);
	//��ʾ�ṹ�д洢��������Ϣ
	void showSales(const Sales &s);
};

#endif   /*A_9_6_4_H*/
