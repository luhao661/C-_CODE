#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "16.10.10.h"

bool FillReview(Review& rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);

    if (rr.title == "quit")
        return false;

    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;

    std::cout << "Enter book price: ";
    std::cin >> rr.price;

    if (!std::cin)
        return false;

    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;

    return true;
}

void ShowReview(const Review* p)
{
    std::cout << p->rating << "\t" << p->title <<"\t" 
        << p->price <<std::endl;
}

bool operator<(const Review p1, const Review p2)
{
    if (p1.title < p2.title)
        return true;
    else
        return false;
}

//bool worseThan(const Review* r1, const Review* r2)
//{
//    if (r1.rating < r2.rating)
//        return true;
//    else
//        return false;
//}

void menu(void)
{
    using std::cout;
    using std::endl;

    cout << "��ѡ��Ҫ��ʾ�鼮�ķ�ʽ��" << endl;
    cout << "1.��ԭʼ˳����ʾ  2.����ĸ��˳����ʾ" << endl;
    cout << "3.������������ʾ  4.������������ʾ" << endl;
    cout << "5.���۸�������ʾ  6.���۸�����ʾ" << endl;
    cout << "7.�˳�" << endl;
}
#endif