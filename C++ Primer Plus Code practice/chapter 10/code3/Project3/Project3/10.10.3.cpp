#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include<iostream>
#include "10.10.3.h"

//�ǽ����汾(���캯��)
Golf::Golf(const char *p_data,const int hc)
{
	strcpy(golf_structure.fullname,p_data);
	this->golf_structure.handicap = hc;
}

//Ĭ�Ϲ��캯��
Golf::Golf()
{
	using std::cout;
	using std::cin;

	int biaoji = 1;

	cout << "����������(����Enter�Խ�������)��";
	char temp[Len];
	cin.getline(temp, Len);

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

	//Golf(temp, handicap);//���󣺹��캯���������������󣬶�����ͨ������ͷ���������
	strcpy(this->golf_structure.fullname,temp);
	this->golf_structure.handicap = handicap;

	return;
}

//��������
Golf::~Golf()
{}

void Golf::handicap(const int hc)
{
	golf_structure.handicap = hc;
}

void Golf::showgolf() const
{
	using std::cout;
	using std::endl;

	cout << "������" << golf_structure.fullname << endl;
	cout << "�м��ȼ���" << golf_structure.handicap << endl;
}

#endif