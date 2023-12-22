#define _CRT_SECURE_NO_WARNINGS 1

// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    //const int MAX = 10;//�����Ǿ�̬��Ա���ñ������ض��������
    //***ע***
    //const int a = 10;��ͨ������(C++11���ڳ�ʼ��)
    enum { MAX = 10 };    // constant specific to class �������ų���
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();            //����һ��Ĭ�Ϲ��캯��
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item& item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item& item);          // pop top into item
};
#endif

