#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <iostream>
#include "11.9.5.h"

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double pds,Mode form)
{
    if ((form != FLOAT_POUNDS)&&(form!= INTEGER_POUNDS))
    {
        cout << "�����ģʽ��\n";
        mode= FLOAT_POUNDS;
    }else
    mode = form;

    stone = int(pds) / pds_per_stn;    // integer division ��������
                     //��ģ��õ�����һӢʯ�İ���������pds��С������
    pds_left = int(pds) % pds_per_stn + pds - int(pds);
    pounds = pds;    
}

// construct Stonewt object from stone, double values
//���캯������
Stonewt::Stonewt(int stn, double pds,Mode form)
{
    if (form != STONE)
    {
        cout << "�����ģʽ��\n";
        mode = STONE;
    }
    else
        mode = form;

    stone = stn;
    pds_left = pds;
    pounds = stn * pds_per_stn + pds;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    mode = FLOAT_POUNDS;
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

/*
// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_pds() const
{
    cout << pounds << " pounds\n";
}
*/

void Stonewt::change_mode(Mode form)
{
    mode = form;
}

//***ע***
//����ֵ��������Ϊconst����Ϊ��Ϊconst��osΪ�����޸ĵ���ֵ
//����const���ܸ�ֵ����const�������β�osҲ������Ϊconst
std::ostream& operator<<(std::ostream& os, const Stonewt &st)
{
    if (st.mode == Stonewt::STONE)//***ע***��Ԫ�ܷ��ʶ����˽�г�Ա�����䲻�����������ڣ�Ҫ��������Ϊ�����ʾ�����Ļ�Ҫ����������������
        os << st.stone << " stone, " << st.pds_left << " pounds\n";
    else if (st.mode == Stonewt::FLOAT_POUNDS)
        os<< st.pounds << " pounds\n";
    else if (st.mode == Stonewt::INTEGER_POUNDS)
        os<< int(st.pounds + 0.5) << " pounds\n";
    else
        os<< "mode is invaild ! \n";

    return os;
}

Stonewt Stonewt::operator+(const Stonewt& s)const
{
    /*Stonewt result;

    result.pounds=pounds+s.pounds;

    return result;*/
    return Stonewt(pounds+s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& s)const
{
    return Stonewt(pounds-s.pounds);
}
Stonewt Stonewt::operator-()const
{
    return Stonewt(-pounds);
}

Stonewt Stonewt::operator*(double x)const
{
    return Stonewt(pounds*x);
}

Stonewt operator*(double x, const Stonewt &s)
{
    return s * x;
}

#endif