#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// version 00
#include <iostream>
#include "cxqd10.1.h"

void Stock::acquire(const std::string& co, long n, double pr)
{
    company = co;

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
            << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;

    share_val = pr;

    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;

    //�洢�޸ĸ�ʽǰ�����б�ǣ����ò����澫��
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize precision = cout.precision(3);

    cout << "Company: " << company
        << "  Shares: " << shares << '\n'
        << "  Share Price: $" << share_val;

    cout.precision(2);//�޸ľ���Ϊ#.##
    cout<< "  Total Worth: $" << total_val << '\n';

    //�ָ�ԭ��ʽ
    cout.setf(orig,ios_base::floatfield);
    cout.precision(precision);
}

#endif
