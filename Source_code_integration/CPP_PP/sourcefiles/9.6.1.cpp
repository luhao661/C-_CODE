#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "9.6.1.h"
#include <cstring>
//�ǽ����汾
void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}
//�����汾
int setgolf(golf& g)
{
	using std::cout;
	using std::cin;

	int biaoji = 1;

	cout << "����������(����Enter�Խ�������)��";
	char temp[Len];
	cin.getline(temp,Len);

	if (!strlen(temp))
	{
		biaoji = 0;
		return biaoji;
	}

	cout << "������ȼ���";
	int handicap;
	while (!(cin >> handicap))
	{
		cout << "Bad input. Please enter a number:  ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cin.get();

	setgolf(g,temp, handicap);

	return biaoji;
}
//��������handicap��Ա��ֵ
void handicap(golf& g, int hc)
{
	g.handicap = hc;
}
//��ʾgolf�ṹ�����еĳ�Ա������
void showgolf(const golf& g)
{
	using std::cout;
	using std::endl;

	cout << "������"<<g.fullname<<endl;
	cout << "�м��ȼ���"<<g.handicap<<endl;
}
#endif