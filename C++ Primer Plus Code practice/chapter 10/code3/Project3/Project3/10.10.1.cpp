#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "10.10.1.h"
#include <cstring>

Account::Account(const char* name, const char* identification, double savings)
{
	strncpy(m_name, name, LEN - 1);//��࿽��LEN-1���ַ�(����������LEN-1���ַ��Ϳ��ַ�)
	m_name[LEN - 1] = '\0';
	memcpy(m_identification, identification, strlen(identification) * sizeof(char) + 1);//�����Ŀ��ַ�Ҳ��������
	m_savings = savings;
}
Account::Account()
{
	strcpy(m_name, "no name");
	strcpy(m_identification, "no ID");
	m_savings = 0.0;
}
Account::~Account()
{}
void Account::show() const
{
	using std::cout;
	using std::endl;

	cout << "����������"<<m_name<<endl;
	cout << "�˺ţ�"<<m_identification<<endl;
	cout << "��"<<m_savings<<endl<<endl;
}
void  Account::deposit(double savings)//***ע***д��inline void  Account::deposit(double savings) �ᱨ��
{
	m_savings += savings;
}
void  Account::draw(double savings)
{
	m_savings -=savings;
}

#endif