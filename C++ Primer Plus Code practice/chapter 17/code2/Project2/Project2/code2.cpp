#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//17.7 ��ϰ��
//6.
//������
#if 0
#include <iomanip>

using namespace std;

int main()
{
	cout << "������һ��������";
	int num;
	cin >> num;

	cout << left;
	cout << setw(10)<<"ʮ���ƣ�"<<num<<endl;
	cout << setw(10) << "�˽��ƣ�"<<oct<<num<<endl;
	cout << setw(10) << "ʮ�����ƣ�" << hex << num << endl;

	cout << showbase;
	cout << setw(15) << dec << num
		<< setw(15) << oct << num
		<< setw(15) << hex << num;

	return 0;
}
#endif


//7.
//������
#if 0
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	cout << "Enter your name : ";
	string st1;
	getline(cin,st1);

	cout << "Enter your hourly wages : ";
	double wages;
	while (!(cin >> wages))
	{
		cout << "error, please try again : ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	
	cout << "Enter number of hours worked : ";
	double work;
	while (!(cin >> work))
	{
		cout << "error, please try again : ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}

	cout << "First format : " << endl;
	cout << right << setw(30) << st1 << " : " <<left<<
		setw(5) << "$"
		<< fixed << setprecision(2) << wages << " : " << setw(5)
		<<setprecision(1)<< work << endl;
	cout << "Second format : " << endl;
	cout << left<<setw(30)<<st1<<" : " << "$" << setw(9)
		<< fixed << setprecision(2)<<wages<<" : "
		<< setprecision(1) <<work;

	return 0;
}
//�����޸ĵĵ㣺
//��"��$"��Ϊһ���������������Ļ
#endif


//8.
//������
#if 0
int main()
{
	using namespace std;
	char ch;
	int ct1 = 0;

	cin >> ch;
	while(ch!='q')
	{
		ct1++;
		cin >> ch;
	}

	int ct2 = 0;
	cin.get(ch);
	while (ch != 'q')
	{
		ct2++;
		cin.get(ch);
	}

	cout << "ct1 = " << ct1 << "; ct2 = "<<ct2<<"\n";

	return 0;
}
#endif


//9.
//������
//***ע***
//ignore()�������ܲ���
#if 0
using namespace std;

int main()
{
	char ch1;
	cin >> ch1;

#if 0
	cin.ignore(5,'\n');
	char ch2;
	cin >> ch2;

	cout << ch1 << "\t"<<ch2;
	//����1234567
	//�����1��7
#endif

#if 1
	cin.ignore(10, '\n');
	char ch2;
	cin.get(ch2);

	cout << ch1 << "\t" << ch2;
	//����1234567(����Enter����)��������\n
	//�����1��\n

	//���ۣ�
	//ignore()�����ȼ�⵽\n�����ȡ������\n�ַ���\n֮ǰ������
#endif

	return 0;
}
#endif