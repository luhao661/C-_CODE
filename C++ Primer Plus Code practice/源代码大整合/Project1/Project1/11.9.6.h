#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX11_9_6
#define BCLX11_9_6

#include <iostream>

class Stonewt
{
private:
    enum { pds_per_stn = 14 };      // pounds per stone
    int stone;                                   // whole stones
    double pds_left;                       // fractional pounds
    double pounds;                       // entire weight in pounds
public:
    Stonewt(double pds);               // constructor for double pounds
    Stonewt(int stn, double pds);  // constructor for stone, pounds
    Stonewt();                                  // default constructor
    ~Stonewt();
    void show_pds() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format

    //***ע***
    //ִ�����빦�ܵĺ�����û���õ�const����Ϊ�βκͷ���ֵ�����ܻ�ı�
    //iostream�Ķ�������Ϊconst�󣬶����Ϊ�����޸ĵĳ������޷���ʵ���������ʾ�Ĺ���
    friend std::istream& operator>>(std::istream& is, Stonewt& st);
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);

    bool operator<(const Stonewt& s)const;
    bool operator<=(const Stonewt& s)const;
    bool operator>(const Stonewt& s)const;
    bool operator>=(const Stonewt& s)const;
    bool operator==(const Stonewt& s)const;
    bool operator!=(const Stonewt& s)const;
};
#endif /*BCLX11_9_6*/
