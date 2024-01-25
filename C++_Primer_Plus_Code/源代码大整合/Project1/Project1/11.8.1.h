#define _CRT_SECURE_NO_WARNINGS 1

#ifndef fxt11_8_1
#define fxt11_8_1

#define FANGFA1  1//����1����򲻼���

class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs);          // construct from double pounds
    Stonewt(int stn, double lbs); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format

    //��һ��������������غ�������Ԫ����
#if FANGFA1==1
    Stonewt operator*(double a)const;

    friend Stonewt operator*(double a,const Stonewt& st);
#else
    //���������ù��캯���Զ�����ת�����ٴ�����������غ���
    friend Stonewt operator*(const Stonewt& st1,const Stonewt &st2);
#endif

    //�����C++�������������ת������(���ڳ�Ա����)
    // conversion functions
    explicit operator int() const;
    explicit operator double() const;
};
#endif /*fxt11_8_1*/
