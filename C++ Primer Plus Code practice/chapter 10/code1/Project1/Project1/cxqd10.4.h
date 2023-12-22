#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STOCK1_H_
#define STOCK1_H_

#include <string>

class Stock
{
private:
    std::string m_company;//ǰ�����m_�������Ƿ�ֹ�������βκ����Ա��������ͬ
    long m_shares;
    double m_share_val;
    double m_total_val;
    void set_tot() { m_total_val = m_shares * m_share_val; }
public:
    // default constructor ����Ĭ�Ϲ��캯��
    Stock();     
    //�������캯��(������Ӳ���Ĭ��ֵ)
    Stock(const std::string& co, long n = 0, double pr = 0.0);
    // noisy destructor ������������
    ~Stock();       
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;//���﷨     ����show()�����޸Ķ���
};

#endif
