#define _CRT_SECURE_NO_WARNINGS 1

// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>  

class Stock  // class declaration ��������������Ʊ����ΪStock
{
private://˽�нӿ�
    std::string company;//��˾����     //���Ա
    long shares;//���ֹ�Ʊ����
    double share_val;//ÿ�ɵļ۸�
    double total_val;//��Ʊ��ֵ
    void set_tot() { total_val = shares * share_val; }

public://�����ӿ�
    void acquire(const std::string& co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end

#endif   /*STOCK00_H_*/