#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_14_7_1_H
#define BCLX_14_7_1_H

#include <string>
#include <valarray>
#include <iostream>

template <class T1, class T2 = int>//����Ϊ���Ͳ����ṩĬ��ֵ
class Pair
{
private:
    T1 a;      //T1���滻��valarray<int>
    T2 b;

public:
    //Pair(const T1& aval, const T2& bval) : a(aval), b(bval)//����valarray��ĸ��ƹ��캯��
    //{}//***ע***ʹ�ô˹��캯���Ļ����ᱨ���β���ʵ�����Ͳ�ƥ��
    //***ע***��������û��������Ҫ��ôд��������

    //��һ��
#if 0
    Pair(const int* aval,const int* bval,int y) : a(aval,y), b(bval,y)
    {}
    Pair(int a, int b) : a(a), b(b)//����һ����a��int����ֵ�����飬��һ����b��int����ֵ������
    {}
#endif

    //������
#if 1
    //***ע***
    //���������������Ը�Ϊ������ʾ�ķ���������Ҫ����Wine��Ĺ��캯�����岿�ֵı�д
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval)
    {}
    //Pair(int a, int b) : a(a), b(b)//����һ����a��int����ֵ�����飬��һ����b��int����ֵ������
    //{}   �˷�����д
#endif
    Pair()
    {}
    T1& first();//�����޸�a
    T2& second();
    T1 first() const //����ֻ��ȡa   ***ע***����ͬ��������Ȼ��������ͬ
    {                       //��һ����const��Ա������һ������
        return a;
    }
    T2 second() const
    {
        return b;
    }
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}


class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;

    std::string name;
    PairArray year_and_bottles;
    int number_of_years;

public:
    Wine(const char*l,int y,const int yr[],const int bot[]);
    Wine(const char* l,int y);

    void GetBottles(void);
    void Show(void)const;
    const std::string& Label(void)const;
    int sum(void)const;
};

#endif