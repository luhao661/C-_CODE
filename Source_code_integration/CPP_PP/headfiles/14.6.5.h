#define _CRT_SECURE_NO_WARNINGS 1

#ifndef FXT14_6_5_H
#define FXT14_6_5_H

#include <string>

class Worker   // an abstract base class 抽象基类
{
private:
    std::string fullname;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker(const std::string& s, long n)//构造函数
        : fullname(s), id(n)
    {}
    Worker() : fullname("no one"), id(0L)//默认构造函数
    {}
    virtual ~Worker() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};


template <class Type>//typename(或class)表示Type是个通用类型说明符
class Stack                             //Type：泛型名(泛型标识符)
{
private:
    enum { MAX = 10 };  // constant specific to class 明示常量
    Type items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type& item); // add item to stack
    bool pop(Type& item);        // pop top into item
};

//***注***
//模板不能单独编译。不能将模板成员函数放在独立的实现文件中
//模板必须与特定的模板实例化一起使用，因此应放在.h文件中，
//在要使用这些模板的文件中包含此头文件

template <class Type>//每个函数头都要用相同的模板声明开头
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
