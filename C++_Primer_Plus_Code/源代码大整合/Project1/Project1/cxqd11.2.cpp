#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// mytime0.cpp  -- implementing Time methods
#include <iostream>
#include "cxqd11.1.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

const Time Time::Sum(const Time& t) const//***ע***�β������ã�Ϊ��ʹ���������ٶȸ��죬���β��Ƕ���Ч����ͬ
{                                                                         //���Ƿ���ֵ���������ã���Ϊsum���Զ��������ں�������ʱ�����٣����ý�ָ��һ�����ٴ��ڵĶ���
    Time sum;

    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;

    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}

#endif 