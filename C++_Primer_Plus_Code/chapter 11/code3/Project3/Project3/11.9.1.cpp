#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <cmath>
#include "11.9.1.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    //��������ʼ��һ��ֻ������Rad_to_deg
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);//atan()���ص��Ǹ�����
    // should be about 57.2957795130823 ��1���ȵ���57.29��

    // private methods ˽�г�Ա����
    // calculates magnitude from x and y
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);//ȡֵ��ΧΪ(-pi,pi]
    }

    // set x from polar coordinate
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    // public methods ���г�Ա����
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;

        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector()     ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()    // set to polar mode
    {
        mode = POL;
    }

    void Vector::rect_mode()     // set to rectangular mode
    {
        mode = RECT;
    }

    // operator overloading
    // add two Vectors
    //�汾һ��
    /*Vector Vector::operator+(const Vector& b) const
    {
        Vector sum;

        sum.x = x + b.x;
        sum.y = y + b.y;
        sum.set_ang();
        sum.set_mag();

        return sum;
    }*/
    //�汾����
    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);//��ʽ���ù��캯���������ڶԶ���ֵ
    }

    // subtract Vector b from a ���ؼ��������
    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector �������ص��������������(��������)
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // multiply vector by n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // friend methods
    // multiply n by Vector a
    Vector operator*(double n, const Vector& a)
    {
        return a * n;
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        if (v.mode == Vector::RECT)//��Ԫ�������������������ڣ����ɼ����е����ݣ����ֻ��д��Vector::RECT
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", "
                << v.ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }

}  // end namespace VECTOR

#endif    