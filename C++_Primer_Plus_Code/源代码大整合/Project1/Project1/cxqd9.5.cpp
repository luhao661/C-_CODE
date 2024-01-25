#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
extern double warming;  // use warming from another file ����ʽ����

// function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt)      // modifies global variable
{
    extern double warming;  // optional redeclaration ��ѡ������ʽ����
    warming += dt;          // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()                // uses local variable ʹ���Զ��������������ļ���ͷ��warming����
{
    double warming = 0.8;   // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the
    // scope resolution operator
    cout << "But global warming = " << ::warming;//***ע***
    cout << " degrees.\n";                                           // ::��������������
}                                                                                    //��ʾʹ�øñ�����ȫ�ְ汾
#endif