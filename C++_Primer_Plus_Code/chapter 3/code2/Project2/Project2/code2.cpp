#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//3.6��ϰ��
//5.
#if 0
int main(void)
{
	using namespace std;

	char grade1 = 65;
	char grade2 = 'A';

	cout << grade1 << endl;
	cout << grade2 << endl;			//˵�������������ͨ��

	return 0;
}
#endif


//6.
#if 0
int main(void)
{
	using namespace std;
	cout.put(88);//��һ						��дΪ��cout.put((char)88);
	putchar('\n');
	cout << (char)88;//����
	putchar('\n');
	char ch = 88;
	cout << ch;//����

	return 0;
}
#endif


//7.
#if 0
#include <climits>
//�к궨�壺
//#define LONG_MAX      2147483647L										��10λ��Чλ��double���͵ı������Ա�ʾ����û���������
//#define LLONG_MAX     9223372036854775807i64				��19λ��Чλ������double���͵ı��������������

int main(void)
{
	long int a = 123456789;
	//float b = a;//����	C4244	����ʼ���� : �ӡ�long��ת������float�������ܶ�ʧ����	

	//double b = a;//�޾���
	double b = 123456789123456789LL;//����	C4305	����ʼ���� : �ӡ�__int64������double���ض�

	return 0;
}
#endif


//9.
#if 0
int main(void)
{
	double x1 = 1.6;
	double x2 = 2.5;

	int a;
	a = (int)x1 + (int)x2;

	int b;
	b = x1 + x2;				//��b=(int)(x1+x2);

	std::cout << a;
	putchar('\n');
	std::cout << b;
	
	return 0;
}
#endif