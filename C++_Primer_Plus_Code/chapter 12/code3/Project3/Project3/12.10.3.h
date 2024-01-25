#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_3_H
#define BCLX12_10_3_H
#include <string>

class Stock
{
private:
    char * str;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char *p, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show()const;
    const Stock& topval(const Stock& s) const;

    friend std::ostream& operator<<(std::ostream &os,const Stock &s);
//***ע***
//���д��(..., const Stock s)�����������Ĭ�ϵĸ��ƹ��캯������ʼ������s��
//����Ǵ˺�������ʱ�����������������ջ��Stock stocks[STKS]ȫ���ͷŵ���
//���º����ӡ�������룬�����ڵڶ��ε�����������ʱ��������
//��һ��Ҫд��(..., const Stock s)������붨�帴�ƹ��캯��
};

#endif /*BCLX12_10_3_H*/
