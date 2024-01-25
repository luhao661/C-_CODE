#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// studentc.cpp -- Student class using containment
#include "cxqd14.1.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;


// private method
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = scores.size();

    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
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


//public methods
double Student::Average() const
{
    if (scores.size() > 0)                          //�෽���п���ͨ������������
        return scores.sum() / scores.size();//����������������ķ���
    else
        return 0;
}

const string& Student::Name() const
{
    return name;
}

double& Student::operator[](int i)//�����޸�����
{
    return scores[i];         // use valarray<double>::operator[]()
}

double Student::operator[](int i) const//������ʾ����
{
    return scores[i];
}


// friends
// ʹ��string��ķ�����operator>>()�汾
// use string version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
    is >> stu.name;//ʹ��string��ķ���������洢��string������
    return is;
}

// use string friend getline(ostream &, const string &)
istream& getline(istream& is, Student& stu)
{
    getline(is, stu.name);
    return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << stu.name << ":\n";//����operator<<(ostream&, const string& )
    stu.arr_out(os);  // use private method for scores
    return os;           //***ע***
}                              //�˴�����stu.arr_out()������ԭ����valarray��û���ṩ
                               //��ʾ�������ݵķ��������Ա����Լ����巽����ʵ����ʾ�����е�����
#endif                    //���ڴ���Ԫ�����н��ж����ԭ���ǿ��԰����ҵ�ϸ�ڷ���˽�в��֣�ʹ��Ԫ�����ı�д������