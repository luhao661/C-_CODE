#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX11_9_2
#define BCLX11_9_2

#include <iostream>
#include <cmath>

namespace VECTOR
{
    class Vector
    {
    public:
        // RECT for rectangular, POL for Polar modes
        // RECT��ֱ������ϵ�£�POL��������ϵ��
        //����һ��ö�����ͣ�û�д���ö�ٱ������������˷��ų���
        enum Mode { RECT, POL };
    private:
        double x;               // horizontal value
        double y;               // vertical value
        Mode mode;        // RECT or POL ����һ��ö�ٱ���
    public:
        // default constructor
        Vector();

        // construct vector from rectangular coordinates if form is RECT (the default) 
        // or else from polar coordinates if form is POL
        //�˹��캯���ܸ�������Ĳ�������ʼ��Vector������˽�����ݳ�Ա
        //����һ�ֱ�ʾʸ������ʽ�����Զ�������һ�ֱ�ʾ��ʽ��
        // x, y, mag, ang ��������ֵ
        Vector(double n1, double n2, Mode form = RECT);

        // reset vector from rectangular coordinates if form is
        // RECT (the default) or else from polar coordinates if
        // form is POL
        //�˷�����ʹ�û��޸���ʸ����һ�ֱ�ʾ�󣬶����Զ�������һ�ֱ�ʾ
        void reset(double n1, double n2, Mode form = RECT);

        // destructor
        ~Vector();

        //���з���(д����������)
        double xval() const { return x; }       // report x value
        double yval() const { return y; }       // report y value
        double magval() const//д����������
        { return sqrt(x * x + y * y); }   // report magnitude
        double angval() const 
        { //***ע***atan2(0,0)δ���壬��Ҫ�ֶ�����ֵ
            if (x == 0.0 && y == 0.0)
                return 0.0;
            else
                return atan2(y, x);
        }   // report angle

        //���з���(д�ɷ�װ��ʽ)
        void polar_mode();                    // set mode to POL
        void rect_mode();                     // set mode to RECT

        // operator overloading
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // friends
        //���ض�Ԫ�����(�����������������)ʱ��������Ҫ��Ԫ
        // multiply n by Vector a
        friend Vector operator*(double n, const Vector& a);
        // display rectangular coordinates if mode is RECT,
        // else display polar coordinates if mode is POL
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };

}   // end namespace VECTOR

#endif  /*BCLX11_9_2*/
