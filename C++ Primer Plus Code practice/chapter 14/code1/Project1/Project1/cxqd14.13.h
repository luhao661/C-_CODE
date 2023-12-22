#define _CRT_SECURE_NO_WARNINGS 1

// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>//typename(��class)��ʾType�Ǹ�ͨ������˵����
class Stack                             //Type��������(���ͱ�ʶ��)
{
private:
    enum { MAX = 10 };  // constant specific to class ��ʾ����
    Type items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type& item); // add item to stack
    bool pop(Type& item);        // pop top into item
};

//***ע***
//ģ�岻�ܵ������롣���ܽ�ģ���Ա�������ڶ�����ʵ���ļ���
//ģ��������ض���ģ��ʵ����һ��ʹ�ã����Ӧ����.h�ļ��У�
//��Ҫʹ����Щģ����ļ��а�����ͷ�ļ�

template <class Type>//ÿ������ͷ��Ҫ����ͬ��ģ��������ͷ
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type& item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type& item)
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
