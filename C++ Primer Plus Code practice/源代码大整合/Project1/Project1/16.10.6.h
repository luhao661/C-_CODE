#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_12_10_6_H
#define BCLX_12_10_6_H

// This queue will contain Customer items
class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime(0) {}//��Ա��ʼ���б�ֻ������(Ĭ��)���캯��
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

#endif
