#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD18_2_H
#define CXQD18_2_H

// interface
class Useless
{
private:
    int n;          // number of elements
    char* pc;      // pointer to data

    //静态数据成员
    static int ct;  // number of objects
    
    void ShowObject() const;

public:
    //默认构造函数
    Useless();
    //构造函数，也可作为类型转换用途
    explicit Useless(int k);
    //构造函数
    Useless(int k, char ch);
    //复制构造函数
    Useless(const Useless& f); // regular copy constructor
    //移动构造函数
    Useless(Useless&& f);      // move constructor
    //析构函数
    ~Useless();
    //+运算符重载函数
    Useless operator+(const Useless& f)const;
    // need operator=() in copy and move versions
    void ShowData() const;
};

#endif
