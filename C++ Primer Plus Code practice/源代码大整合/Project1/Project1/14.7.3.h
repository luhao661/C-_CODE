#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_14_7_3_H
#define BCLX_14_7_3_H

//class Customer
//{
//private:
//    long arrive;        // arrival time for customer
//    int processtime;    // processing time for customer
//public:
//    Customer() : arrive(0), processtime(0) {}//��Ա��ʼ���б�ֻ������(Ĭ��)���캯��
//    void set(long when);
//    long when() const { return arrive; }
//    int ptime() const { return processtime; }
//};

//typedef Customer Item;

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
    SingingWaiter(const std::string& s, long n, int p = 0, int v = other)
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

/********************************************************************************************/

template <typename T>
class QueueTp
{
private:
    enum { Q_SIZE = 10 };//������ʾ����(���ų���)��Q_SIZE��ʾĬ�ϵĶ�����󳤶�

    struct Node
    {
        T item; 
        struct Node* next; 
    };

    Node* front;       // pointer to front of Queue
    Node* rear;        // pointer to rear of Queue
    
    int items;           // current number of items in Queue
    const int qsize; // maximum number of items in Queue

    //ʹ�ö���ĸ��ƹ��캯���͸�ֵ��������غ�����
    //������private�У����Ա�����󱻳�ʼ����������������ݻ���ж����ĸ�ֵ����
    QueueTp(const QueueTp& q) : qsize(0) { }//�����ṩ��������ʹ��Ĭ�ϵĸ��ƹ��캯����������غ��
    QueueTp& operator=(const QueueTp& q) { return *this; }
public:
    QueueTp(int qs = Q_SIZE); // create queue with a qs limit
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T& item); // add item to end
    bool dequeue(T& item);       // remove item from front
};


/****************************************************************************************************/

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)//��Ա��ʼ���б�
{
    front = rear = NULL;    // or nullptr
    items = 0;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
    Node* temp;
    while (front != NULL)   // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}

template <typename T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}

template <typename T>
bool  QueueTp<T>::isfull() const
{
    return items == qsize;
}

template <typename T>
int  QueueTp<T>::queuecount() const
{
    return items;
}

// Add item to queue
template <typename T>
bool  QueueTp<T>::enqueue(const T& item)
{
    if (isfull())
        return false;

    Node* add = new Node;  // create node
// on failure, new throws std::bad_alloc exception

    add->item = item;       // set node pointers
    add->next = NULL;       // or nullptr;

    items++;

    if (front == NULL)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear

    rear = add;             // have rear point to new node

    return true;
}

// Place front item into item variable and remove from queue
template <typename T>
bool  QueueTp<T>::dequeue(T& item)
{
    if (front == NULL)
        return false;

    item = front->item;     // set item to first item in queue

    items--;

    Node* temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item

    if (items == 0)
        rear = NULL;

    return true;
}


#endif /*BCLX_14_7_3_H*/