#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//2.7�����ϰ
//1.
#if 0
int main(void)
{
	using std::cout;
	cout << "����";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "������һ����longΪ��λ�ľ��룺";
	int distance;
	cin >> distance;
	cout << "���������൱��" << distance * 220 << "��";

	return 0;
}
#endif


//3.
#if 0
using namespace std;
void function1(void);
void function2(void);

int main(void)
{
	function1();
	function1();
	function2();
	function2();

	return 0;
}
void function1(void)
{
	cout << "Three blind mice"<<endl;
}
void function2(void)
{
	cout << "See how they run\n";
}
#endif


//4.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter your age: ";
	int age;
	cin >> age;
	cout << "�����������"<<age*12<<"����";

	return 0;
}
#endif



//5.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "�����������¶�ֵ��";
	double temperature;
	cin >> temperature;
	cout << temperature <<"���൱��" << function(temperature) << "���϶�";

	return 0;
}
double function(double num)
{
	return num * 1.8 + 32.0;
}
#endif


//6.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "���������ֵ��";
	double light_years;
	cin >> light_years;
	cout << light_years << "����=" << function(light_years) << "���ĵ�λ";

	return 0;
}
double function(double num)
{
	return num * 63240;
}
#endif


//7.
#if 0
using namespace std;
void function(int a,int b);

int main(void)
{
	int a, b;
	cout << "Enter the number of hours: ";
	cin >> a;
	cout << "Enter the number of minutes: ";
	cin >> b;
	function(a,b);

	return 0;
}
void function(int a, int b)
{
	cout <<"Time : " << a << ":" << b;				//***ע***�޷���ֵ�ĺ������Բ�ʹ��return��䣬�������������е����һ�䣬Ȼ���Զ�����
	//return;
}
#endif
