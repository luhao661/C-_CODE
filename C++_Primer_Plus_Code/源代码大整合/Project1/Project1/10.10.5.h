#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STACK_H_
#define STACK_H_

typedef struct customer
{
    char fullname[35];
    double payment;
}Item;

class Stack
{
private:
    //const int MAX = 10;//�����Ǿ�̬��Ա���ñ������ض��������
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

#endif  /*STACK_H_*/
