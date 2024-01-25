#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "13.11.3.h"
#include <cstring>

/***********************************************************************************/

// DmaABC methods
DmaABC::DmaABC(const char* s, int r)
{
    label = new char[std::strlen(s) + 1];
    std::strcpy(label, s);
    rating = r;
}

DmaABC::DmaABC(const DmaABC& d)
{
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    rating = d.rating;
}

DmaABC::~DmaABC()
{
    delete[]label;
}

DmaABC& DmaABC::operator=(const DmaABC& d)
{
    if (this == &d)
        return *this;

    delete[] label;
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);

    rating = d.rating;

    return *this;
}

char* DmaABC::See_label()const
{
    return label;
}

int DmaABC::See_rating()const
{
    return rating;
}

/***********************************************************************************/

// baseDMA methods
baseDMA::baseDMA(const char* l, int r):DmaABC(l,r)
{}

baseDMA::baseDMA(const baseDMA& rs):DmaABC(rs)
{}

baseDMA::~baseDMA()//***ע***����baseDMA����û����new��̬������ڴ�
{}                                      //���Կ��Բ���delete
    
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if (this == &rs)
        return *this;

    DmaABC::operator=(rs);

    return *this;
}

void baseDMA::View(void)const
{
    std::cout << "Label: " <<See_label() << std::endl;
    std::cout<< "Rating: " << See_rating() << std::endl;
}

/***********************************************************************************/

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
    : DmaABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
    : DmaABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View(void) const
{
    std::cout << "Label: " << See_label() << std::endl;
    std::cout << "Rating: " << See_rating() << std::endl;
    std::cout << "Color: " << color << std::endl;
}

/***********************************************************************************/

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
    : DmaABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
    : DmaABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA::hasDMA(const hasDMA& hs)
    : DmaABC(hs)  //��ʽʹ�û��ิ�ƹ��캯��(ָ���������ÿ���ָ����������)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if (this == &hs)
        return *this;

    DmaABC::operator=(hs);  //��ʽ���û��ำֵ������ĺ�����ʾ��

    //***ע***
    //����д���������ʾ��
    //*this = hs;    //��Ϊ����д���õ���hasDMA::operator=()�����γɵݹ����

    delete[] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void hasDMA::View()const
{
    std::cout << "Label: " << See_label() << std::endl;
    std::cout << "Rating: " << See_rating() << std::endl;
    std::cout << "Style: " << style << std::endl;
}

#endif