#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//11.8 ��ϰ��
//1.
//����11.8.1.cpp
#if 0
#include "11.8.1.h"
int main()
{
	using std::cout;
	using std::endl;

	Stonewt w1(10,8);

	Stonewt w2 = 2*w1 ;

	cout << double(w2) <<"�����൱��";//ʹ����ʽǿ������ת��

	w2.show_stn();

	return 0;
}
#endif


//7.
//����11.8.7.cpp
#if 0
#include "11.8.7.h"
int main()
{
	using namespace VECTOR;
	using namespace std;

	Vector v1(1,1);

	double length = double(v1);

	cout << length << endl;

	return 0;
}
#endif