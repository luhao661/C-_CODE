#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// stack.cpp -- Stack member functions
#include "cxqd10.10.h"
Stack::Stack()    // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item& item)
{
    if (top < MAX)
    {
        items[top++] = item;//***ע***top��������ֵ
        return true;                 //�ȴ�items[0]����������
    }                                       //������ɺ�top=1���������Ԫ�ظ���
    else                                  //���ٴε���push������top������Ϊ����ֵ������ΪԪ�ظ���
        return false;
}

bool Stack::pop(Item& item)
{
    if (top > 0)                    //***ע***top����Ԫ�ظ���
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}
#endif