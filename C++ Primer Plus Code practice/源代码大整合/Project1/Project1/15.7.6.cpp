#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//15.7 ��ϰ��
//6.
//������
#if 0
#include "15.7.6.h"
#include <cstdlib>//srand(), rand()
#include <ctime>//time()

Grand* GetOne(void);

int main()
{
    std::srand(std::time(0));

    Grand* pg;
    Superb* ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb*>(pg))//�����н׶��ж��Ƿ���԰�ȫ��
            ps->Say();                                          //������ĵ�ַ�����ض����͵�ָ��
                                                                       //***ע***�麯���Ĺ��ܱ���       
        /*if (typeid(*pg) == typeid(Superb))
            (Superb*)pg->Say();*///***ע***�����������
    }                                           //ԭ�򣺻���ָ��ֻ�ܵ��û������еķ���P399     
    // std::cin.get();
    return 0;
}

Grand* GetOne(void)    // generate one of three kinds of objects randomly
{
    Grand* p;
    p = (Grand*)0;//***ע***����д��Grand* p��(Grand*)0;

    switch (std::rand() % 3)
    {
    case 0: p = new Grand(std::rand() % 100);
        break;
    case 1: p = new Superb(std::rand() % 100);
        break;
    case 2: p = new Magnificent(std::rand() % 100,
        'A' + std::rand() % 26);
        break;
    }

    return p;
}
#endif