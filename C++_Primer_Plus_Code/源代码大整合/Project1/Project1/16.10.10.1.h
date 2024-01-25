#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_16_10_10_1_H
#define BCLX_16_10_10_1_H
#include <string>
#include <iostream>
#include <memory>

struct Review
{
    std::string title;
    int rating;
    double price;
};

using std::shared_ptr;

bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& p);

//C++ �ǳ�Ա�����Ҫ�������ͻ�ö�����͵Ĳ���,
bool operator<(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);//����ĸ˳��
bool anpinjishengxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anpinjijiangxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anjiageshengxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anjiagejiangxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);

void menu(void);

//�޸�˼·��
//��Ȼ���ܰ�shared_ptr�Զ�ת������ָͨ�룬��ô�ͰѺ����βζ�
//�ĳ�shared_ptr&����
#endif