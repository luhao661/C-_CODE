#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//�����ϰ
//4.
#if 0
int main(void)
{
	using namespace std;

	long seconds;
	cout << "������������";
	cin >> seconds;
	int days, hours, minutes,temp;

	temp = seconds;

	const int day_to_seconds = 86400;
	const int hour_to_seconds = 3600;
	const int minute_to_seconds = 60;

	days = seconds / day_to_seconds;
	seconds = seconds % day_to_seconds;
	hours = seconds / hour_to_seconds;
	seconds = seconds % hour_to_seconds;
	minutes = seconds / minute_to_seconds;
	seconds %= minute_to_seconds;

	cout << temp << "seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	return 0;
}
#endif


//7.
#if 1
int main(void)
{
	using namespace std;

	cout << "������ÿ�ٹ������ĵ�������(��)��";
	double E_consume;
	cin >> E_consume;										//��λ��(��/100����)

	const double Seng_to_Jialun = 1.0 / 3.785;
	const double Gongli_to_Yinli = 0.6214;

	auto temp = E_consume * Seng_to_Jialun; //��λ��(����/100����)
	temp /=100 ;//ÿһ�������(����)				   ��λ��(����/����)
	temp = 1 / temp;											//��λ��(����/����)

	auto A_consume =  temp* Gongli_to_Yinli;//��λ��(Ӣ��/����)

	//������
	//double A_consume = 62.14 / (E_consume/3.785);

	cout << "�൱��" << A_consume << "mpg";

	return 0;
}
#endif