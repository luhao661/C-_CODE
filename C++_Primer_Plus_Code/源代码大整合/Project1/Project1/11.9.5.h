#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX11_9_5
#define BCLX11_9_5
#include <iostream>

class Stonewt
{
public:
    enum Mode {STONE,INTEGER_POUNDS,FLOAT_POUNDS};
private:
    Mode mode;
    enum { pds_per_stn = 14 };      // pounds per stone
    int stone;                                   // whole stones
    double pds_left;                       // fractional pounds
    double pounds;                       // entire weight in pounds
public:
    //***ע***�˹��캯����������ʽ����ת��
    Stonewt(double pds,Mode form= FLOAT_POUNDS);// constructor for double pounds
    Stonewt(int stn, double pds, Mode form = STONE);  // constructor for stone, pounds
    Stonewt();                                  // default constructor
    ~Stonewt();

    void change_mode(Mode form);
    //void show_pds() const;        // show weight in pounds format
    //void show_stn() const;        // show weight in stone format
    friend  std::ostream& operator<<(std::ostream &os,const Stonewt &st);

    Stonewt operator+(const Stonewt &s)const;
    //Stonewt operator+(int stn, double pds)const;//����������������Ĳ�������
    Stonewt operator-(const Stonewt &s)const;
    Stonewt operator-()const;

    Stonewt operator*(double x)const;
    friend Stonewt operator*(double x,const Stonewt& s);
};
#endif /*BCLX11_9_5*/
