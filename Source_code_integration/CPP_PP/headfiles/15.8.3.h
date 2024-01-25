#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_3_H
#define BCLX_15_8_3_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

class bad_hmean :public std::logic_error//***ע***����Ҫ����Ϊ���м̳У������������ʹ��what()����
{
private:
    double m_a;
    double m_b;

public:
    bad_hmean(double a,double b,
        const std::string& s = "�������ƽ����ʧ��\n")
        :std::logic_error(s),m_a(a),m_b(b)
    {}
    //***ע***����д��������������logic_error�಻����Ĭ�Ϲ��캯�������Ա������ʹ����ʽ��ʼ��
    /*bad_hmean():m_a(0),m_b(0)
    {}*/
    bad_hmean():m_a(0),m_b(0), std::logic_error("none")
    {}
    void report(void)const
    {
        cout << "��������"<<m_a<<"��"<<m_b << endl;
        cout << "hmean()���������쳣"<<endl;
    }
};

class bad_gmean :public std::logic_error
{
private:
    double m_a;
    double m_b;

public:
    bad_gmean(double a, double b, 
        const std::string& s = "���㼸��ƽ����ʧ��\n")
        :std::logic_error(s), m_a(a), m_b(b)
    {}
    bad_gmean() :m_a(0), m_b(0), std::logic_error("none")
    {}
    void report(void)const
    {
        cout << "��������" << m_a << "��" << m_b << endl;
        cout << "gmean()���������쳣" << endl;
    }
};

#endif