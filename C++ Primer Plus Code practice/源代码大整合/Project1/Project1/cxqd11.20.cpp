#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// stonewt1.cpp -- Stonewt class methods + conversion functions
#include "cxqd11.19.h"
#include <iostream>
using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;    // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// conversion functions
Stonewt::operator int() const
{

    return int(pounds + 0.5);//ʵ�ֶ�С�����ֵ���������
                                              //��poundsֵΪ1.4���򷵻�1
}                                             //��poundsֵΪ1.5���򷵻�2

Stonewt::operator double()const
{
    return pounds;
}
#endif