#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//17.7 复习题
//6.
//链接无
#if 0
#include <iomanip>

using namespace std;

int main()
{
	cout << "请输入一个整数：";
	int num;
	cin >> num;

	cout << left;
	cout << setw(10)<<"十进制："<<num<<endl;
	cout << setw(10) << "八进制："<<oct<<num<<endl;
	cout << setw(10) << "十六进制：" << hex << num << endl;

	cout << showbase;
	cout << setw(15) << dec << num
		<< setw(15) << oct << num
		<< setw(15) << hex << num;

	return 0;
}
#endif


//7.
//链接无
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
//可以修改的点：
//将"：$"作为一个整体来输出到屏幕
#endif


//8.
//链接无
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
//链接无
//***注***
//ignore()方法功能测试
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
	//输入1234567
	//则输出1和7
#endif

#if 1
	cin.ignore(10, '\n');
	char ch2;
	cin.get(ch2);

	cout << ch1 << "\t" << ch2;
	//输入1234567(按下Enter键后)，再输入\n
	//则输出1和\n

	//结论：
	//ignore()方法先检测到\n，则读取并丢弃\n字符和\n之前的内容
#endif

	return 0;
}
#endif