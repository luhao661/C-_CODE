#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//9.6�����ϰ
//1.
//����9.6.1.cpp
#if 0
#include "9.6.1.h"
#include <new>
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "������Ҫ���Ľṹ������";
	int count;
	while (!(cin >> count))
	{
		cout << "Bad input. Please enter a number:  ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cin.get();
	//struct golf golf_structure[count];//����count�����Ǳ���
	//�����1��
	/*const int c_count = count;
	struct golf golf_structure[c_count];*/  //�˷������У�c_count������Ϊ����

	//��ȷ������
	struct golf* p_golfstructure =new golf[count];

	int biaoji = 1;
	int i;
	for(i=0;i<count;i++)
	{
		cout << "�������"<<i+1<<"���ṹ������"<<endl;
		biaoji=setgolf(*(p_golfstructure+i));

		if (!biaoji)
			break; 
	}
	//***����count��ֵ�����Դ���ṹ������ֵ***
	count = i;

	cout << "Ҫ�޸Ľṹ�����е�handicap��Ա��ֵ��(����y��n)";
	char answer;
	while (cin.get(answer))
	{
		while (cin.get() != '\n')
			continue;
		answer = tolower(answer);

		if (strchr("yn", answer) == NULL)
			cout << "������y��n : ";
		else
			break;
	}

	if (answer == 'y')
	{
		cout << "������Ҫ�޸ĵ����������ֵ��";
		int num;
		while (!(cin >> num))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cout << "������Ҫ�޸ĵ������handicap��ֵ��";
		int handicap_num;
		while (!(cin >> handicap_num))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cin.get();

		handicap(*(p_golfstructure+num), handicap_num);
		cout << "��"<< num+1 <<"���ṹ�޸���ɣ�"<<endl;
	}

	cout << "\n�������£�"<<endl;
	for (int i = 0; i < count; i++)
	{
		showgolf(*(p_golfstructure + i));
	}

	return 0;
}
#endif


//2.
#if 0
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string str);

int main()
{
	using namespace std;

	string input;
	cout << "Enter a line:\n";
	getline(cin,input);

	while (input!="")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";//***ע***��get()��ȡ���к�����ʧЧλ
		getline(cin, input);
	}
	cout << "Bye\n";

	return 0;
}

void strcount(const std::string str)
{
	using namespace std;

	static int total = 0;        // static local variable ֻ���ڵ�һ�ε��ú���ʱ���г�ʼ��

	cout << "\"" << str << "\" contains ";

	int count = 0;               // automatic local variable
	//while (str[count])               // go to end of string
	//	count++;

	//������
	count = str.size();/*  count=str.length();  */

	total += count;

	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#endif


//3.
#if 0
#include <new>
#define SIZE 50
struct chaff
{
	char dross[20];
	int slag;
};

char buffer[SIZE];

int main()
{
	using std::cout;

	struct chaff* p = new (buffer)struct chaff[2];

	const char* data = "abcdefg";
	strcpy(p->dross, data);
	p->slag = 1;
	strcpy((p+1)->dross, data);
	(p + 1)->slag = 2;

	for (int i = 0; i < 2; i++)
	{
		cout << (p + i)->dross << "\t";
		cout << (p + i)->slag <<std::endl;
	}

	delete[]p;

	return 0;
}
#endif


//4.
//����9.6.4.cpp
#if 0
#include "9.6.4.h"

int main()
{
	using SALES::Sales;
	using SALES::setSales;

	Sales Sales_Structure[2];

	setSales(Sales_Structure[0]);

	double data[2]{1.1,2.2};
	setSales(Sales_Structure[1],data,2);

	SALES::showSales(Sales_Structure[0]);
	showSales(Sales_Structure[1]);

	return 0;
}
#endif
