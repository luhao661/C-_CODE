#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "cxqd13.4.h"
#include <iostream>

//����ķ���
TableTennisPlayer::TableTennisPlayer(const string& fn,
    const string& ln, bool ht) 
    : firstname(fn), lastname(ln), hasTable(ht)
{}
//***ע***
//���Բ��ó�Ա��ʼ���б�
//�����ں������н���string�����ĸ�ֵ������Ҫ�ȶ�firstname����Ĭ�Ϲ��캯���ٵ��ø�ֵ��������غ�����
//���ó�Ա��ʼ���б��ֱ�ӵ��ø��ƹ��캯��������Ч�ʸ���

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

//*****************************************************************************************************************

//������ķ���
RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
    const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{//***ע***����Ķ���Ӧ���ڳ�����������๹�캯��֮ǰ������
    rating = r;
}
//***ע***
//���Բ��ó�Ա��ʼ���б�
//�������е�����Ҳ�������޸ģ������û����Ĭ�Ϲ��캯��

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
    : TableTennisPlayer(tp), rating(r)//�����û����Ĭ�ϵĸ��ƹ��캯��
{
}
#endif