#define _CRT_SECURE_NO_WARNINGS 1

#ifndef N_S
#define N_S

namespace SALES
{
	class Sales
	{
		enum {QUARTERS=4};
		double sales[QUARTERS];
		double m_average;
		double m_max;
		double m_min;
	public:
		//��ar[]�п���n�����ݵ��ṹ���е�sales�����У�
		//���㲢�洢����������Ա��ֵ,
		//sales�������п��еĿռ䣬����пռ��Ԫ�ظ�ֵΪ0
		Sales(const double ar[], int n);
		//����ʽ�ش���4��slaes��ֵ��������ṹ���е�sales�����У�
		//���㲢�洢����������Ա��ֵ��
		Sales();
		//��ʾ�����˽�����ݲ����д洢��������Ϣ
		void ShowSales()const;
	};
}

#endif  /*N_S*/