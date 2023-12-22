#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_6_H
#define BCLX12_10_6_H

class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime(0) {}//��Ա��ʼ���б�ֻ������(Ĭ��)���캯��
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    enum { Q_SIZE = 10 };//������ʾ����(���ų���)��Q_SIZE��ʾĬ�ϵĶ�����󳤶�
    struct Node { Item item; struct Node* next; };
    Node* front;       // pointer to front of Queue
    Node* rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    //ʹ�ö���ĸ��ƹ��캯���͸�ֵ��������غ�����
    //������private�У����Ա�����󱻳�ʼ����������������ݻ���ж����ĸ�ֵ����
    // preemptive definitions to prevent public copying
    Queue(const Queue& q) : qsize(0) { }//�����ṩ��������ʹ��Ĭ�ϵĸ��ƹ��캯����������غ��
    Queue& operator=(const Queue& q) { return *this; }
public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item& item); // add item to end
    bool dequeue(Item& item);       // remove item from front
};

#endif /*BCLX12_10_6_H*/