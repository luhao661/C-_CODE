#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_16_10_10_H
#define BCLX_16_10_10_H
#include <string>

struct Review
{
    std::string title;
    int rating;
    double price;
};

bool FillReview(Review& rr);
void ShowReview(const Review *p);

//C++ �ǳ�Ա�����Ҫ�������ͻ�ö�����͵Ĳ���,
//���Բ�����const Review*p1
bool operator<(const Review p1, const Review p2);//����ĸ˳��
bool worseThan(const Review* r1, const Review* r2);

void menu(void);
bool a(const Review* r1, const Review* r2);

//�޸�˼·��
//��Ȼ���ܰ�shared_ptr�Զ�ת������ָͨ�룬��ô�ͰѺ����βζ�
//�ĳ�shared_ptr&����
#endif