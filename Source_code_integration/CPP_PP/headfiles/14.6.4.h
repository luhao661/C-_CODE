#define _CRT_SECURE_NO_WARNINGS 1

#ifndef FXT14_6_4_H
#define FXT14_6_4_H

#include <string>

class Worker   // an abstract base class �������
{
private:
    std::string fullname;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker(const std::string& s, long n)//���캯��
        : fullname(s), id(n)
    {}
    Worker() : fullname("no one"), id(0L)//Ĭ�Ϲ��캯��
    {}
    virtual ~Worker() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

/**************************************************************************/

template <class Thing >//typename(��class)��ʾType�Ǹ�ͨ������˵����
class Stack                             //Type��������(���ͱ�ʶ��)
{
private:
    enum { MAX = 10 };  // constant specific to class ��ʾ����
    Thing items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Thing& item); // add item to stack
    bool pop(Thing& item);        // pop top into item
};

//***ע***
//ģ�岻�ܵ������롣���ܽ�ģ���Ա�������ڶ�����ʵ���ļ���
//ģ��������ض���ģ��ʵ����һ��ʹ�ã����Ӧ����.h�ļ��У�
//��Ҫʹ����Щģ����ļ��а�����ͷ�ļ�

template <class Thing >
Stack<Thing>::Stack()
{
    top = 0;
}

template <class Thing >
bool Stack<Thing>::isempty()
{
    return top == 0;
}

template <class Thing >
bool Stack<Thing>::isfull()
{
    return top == MAX;
}

template <class Thing >
bool Stack<Thing>::push(const Thing& item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Thing >
bool Stack<Thing>::pop(Thing& item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif