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
    Customer() : arrive(0), processtime(0) {}//成员初始化列表只能用在(默认)构造函数
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

#endif
