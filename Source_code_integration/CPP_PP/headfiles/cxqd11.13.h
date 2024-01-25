#define _CRT_SECURE_NO_WARNINGS 1

// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

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
        double mag;         // length of vector
        double ang;          // direction of vector in degrees
        Mode mode;        // RECT or POL ����һ��ö�ٱ���
    // private methods for setting values 
        void set_mag();
        void set_ang();
        void set_x();
        void set_y()//Ҳ����д����������
        {
            y = mag * sin(ang);
        }
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
        double magval() const { return mag; }   // report magnitude
        double angval() const { return ang; }   // report angle

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
#endif
