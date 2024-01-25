#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_4_H
#define BCLX12_10_4_H

typedef unsigned long Item;

class Stack
{
private:
    //***ע***
    //const int MAX = 10;//��ͨ������(���ԣ�C++11���ڳ�ʼ��)
    //���ǲ�����Ϊ���ų�������Ϊ������൱���ڹ��캯���ó�Ա��ʼ���б�����ʼ��MAX
    //�����������൱�ڻ�û����MAX
    enum { MAX = 10 };    // constant specific to class �������ų���
    Item *pitems;    // holds stack items
    int size;             //�����Ԫ�ظ���
    int top;             //��������ݸ���
public:
    Stack(int n=MAX);            //����һ�����캯��
                            //(Ҳ����ΪĬ�Ϲ��캯����Ҳ����Ϊ����ת��)
    Stack(const Stack& st);    //����һ�����ƹ��캯��
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item& item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item& item);          // pop top into item

    Stack& operator=(const Stack & st);//��ֵ��������غ���

    void traverse(void(*pf)(Item&))const;
};

#endif /*BCLX12_10_4_H*/
