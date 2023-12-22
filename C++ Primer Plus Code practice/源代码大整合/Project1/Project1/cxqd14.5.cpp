#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// studenti.cpp -- Student class using private inheritance
#include "cxqd14.4.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;


// private method
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}


// public methods
double Student::Average() const
{
    if (ArrayDb::size() > 0)             //ʹ���������������������������û���ķ���
        //return ArrayDb::sum() / ArrayDb::size();
        return sum() / valarray<double>::size();//P404������ķ������Է��ʻ���ķ���
    else                                           //��ʹ��string::size()��ԭ����valarray���string�඼��size()����
        return 0;                               //�˴�ָ��Ҫ��valarray���size()����
}

const string& Student::Name() const
{
    return (const string&)*this;//ʹ��ǿ������ת�������ʻ���Ķ���
}

double& Student::operator[](int i)
{
    return ArrayDb::operator[](i);         // use ArrayDb::operator[]()
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}


// friends
// use String version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
    is >> (string&)stu;
    return is;
}

// use string friend getline(ostream &, const string &)
istream& getline(istream& is, Student& stu)
{
    getline(is, (string&)stu);
    return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{                                         //ʹ��ǿ������ת�������ʻ������Ԫ����
    os << "Scores for " << (const string&)stu << ":\n";
    stu.arr_out(os);  // use private method for scores
    return os;
}

#endif