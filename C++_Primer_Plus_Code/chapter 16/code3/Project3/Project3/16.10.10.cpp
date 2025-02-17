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

    cout << "请选择要显示书籍的方式：" << endl;
    cout << "1.按原始顺序显示  2.按字母表顺序显示" << endl;
    cout << "3.按评级升序显示  4.按评级降序显示" << endl;
    cout << "5.按价格升序显示  6.按价格降序显示" << endl;
    cout << "7.退出" << endl;
}
#endif