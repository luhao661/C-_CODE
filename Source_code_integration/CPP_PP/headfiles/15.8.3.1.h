#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_3_1_H
#define BCLX_15_8_3_1_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

class unexpected_mean :public std::logic_error//***ע***����Ҫ����Ϊ���м̳У������������ʹ��what()����
{
private:
    double m_a;
    double m_b;

public:
    unexpected_mean(double a=0, double b=0,//���캯����Ĭ�Ϲ��캯��
        const std::string& s = "����ƽ����ʱ����\n")
        :m_a(a), m_b(b), logic_error(s)
    {}
    virtual ~unexpected_mean()
    {}

    virtual void message(void)const = 0//���麯����
    {                                                   //unexpected_mean�����ΪABC
        cout << "��������" << m_a << "��" << m_b << endl;
    }                                                    
};

class bad_hmean :public unexpected_mean
{
public:
    bad_hmean(double a, double b,
        const std::string& s = "�������ƽ����ʧ��\n")
        :unexpected_mean(a,b,s)
    {}
    void message(void)const
    {
        cout << "hmean()���������쳣" << endl;
        cout << what();
        unexpected_mean::message();
    }
};

class bad_gmean :public unexpected_mean
{
public:
    bad_gmean(double a, double b,
        const std::string& s = "���㼸��ƽ����ʧ��\n")
        :unexpected_mean(a, b, s)
    {}
    void message(void)const
    {
        cout << "gmean()���������쳣" << endl;
        cout << what();
        unexpected_mean::message();
    }
};

#endif