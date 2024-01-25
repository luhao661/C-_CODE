#define _CRT_SECURE_NO_WARNINGS 1

// workermi.h  -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_

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
                                                            //***ע***
class Waiter : virtual public Worker//ʹ�������ʹ���ʹ�ô������
{                                                          //���������������Ķ���ֻ�̳�һ���������                                                            
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter(const std::string& s, long n, int p = 0)
        : Worker(s, n), panache(p) 
    {}
    Waiter(const Worker& wk, int p = 0)
        : Worker(wk), panache(p) 
    {}
    Waiter() : Worker(), panache(0) 
    {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {
        other, alto, contralto, soprano,
        bass, baritone, tenor
    };
    enum { Vtypes = 7 };
    void Data() const;
    void Get();

private:
    static char* pv[Vtypes];    // string equivs of voice types
    int voice;

public:
    Singer(const std::string& s, long n, int v = other)
        : Worker(s, n), voice(v)
    {}
    Singer(const Worker& wk, int v = other)
        : Worker(wk), voice(v) 
    {}
    Singer() : Worker(), voice(other) 
    {}
    void Set();
    void Show() const;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();

public:
    SingingWaiter(const Worker& wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) 
    {}//***ע***Worker(wk)��ʽ�ص��ù��캯��worker(const Worker&)
      //���������Ϸ��������ڷ�������ǷǷ���
    SingingWaiter(const std::string& s, long n, int p = 0,  int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) 
    {}
    SingingWaiter(const Waiter& wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) 
    {}
    SingingWaiter(const Singer& wt, int p = 0)
        : Worker(wt), Waiter(wt, p), Singer(wt) 
    {}
    SingingWaiter() 
    {}
    void Set();
    void Show() const;
};

#endif
