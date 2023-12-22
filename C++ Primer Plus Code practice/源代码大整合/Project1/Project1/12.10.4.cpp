#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "12.10.4.h"
#include <cstring>//memcpy()
#include <iostream>

Stack::Stack(int n):size(n),top(0)//��Ա��ʼ���б�
{
    pitems = new Item[n];
    /*//***ע***�����������е�Ԫ�س�ʼ������
    //������ӡ��������ֵΪ0�ϵ�����������ֵ
    for (int index = 0; index < n; index++)
        *(pitems+index)=-1;*/
    //���Բ���ʼ������top��ֵ���ж��Ƿ��ӡ���ʹ�ӡ��������
}

Stack::Stack(const Stack& st)
{
    pitems = new Item[st.size];
    Item* st_temp;
    int index;
    for (index = 0,st_temp = st.pitems; index < st.top; index++)
    {
        *(pitems + index) = *(st_temp+index);
    }
    //ͨ��������ʵ�ֱ�����ָ��Item��ָ���ֵʵ����û�䣬
    //���Կ��Բ�����ʱָ��st_temp

    //��ʹ��memcpy()
    //memcpy(pitems,st.pitems,st.size*sizeof(Item));
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete[]pitems;//�ȼ���if(pitems!=nullptr)   delete[]pitems;
}

bool Stack::isempty() const
{
    return top == 0;//�ȼ���if(top==0) return true; else return false;
}

bool Stack::isfull() const
{
    return top == size;//***ע***�˴���дΪtop==size-1
}                                   //�˴�top��������

bool Stack::push(const Item& item)
{
    if (!isfull())
    {
        *(pitems+top) = item;//***ע***���뺯����ʱtop��������ֵ
        ++top;
        return true;                 //�ȴ�items[0]����������
    }                                       //������ɺ�top=1���������Ԫ�ظ���
    else                                  //���ٴε���push������top������Ϊ����ֵ������ΪԪ�ظ���
        return false;
}

bool Stack::pop(Item& item)
{
    if (!isempty())                    //***ע***���뺯����ʱtop��������
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack& Stack::operator=(const Stack& st)//��ֵ��������غ���
{
    if (this == &st)//1.����Ƿ������Ҹ���
        return *this;

    delete[] pitems;//2.�ͷ�pitemsָ���ԭ��������

    pitems = new Item [st.size];//3.Ϊ���ַ��������㹻���ڴ�ռ�
   
    memcpy(pitems, st.pitems, st.size * sizeof(Item));

    size = st.size;
    top = st.top;

    return *this;//4.ʵ��������ֵ
}

void Stack::traverse(void(*pf)(Item&))const//***ע***�˴�void(*pf)(Item&)Ϊ����ԭ���޷�
{
    int index;
    for(index=0;index<top;index++) //***ע***�˴�top����Ԫ�ظ���
    {
        if (index == 0)
            std::cout << "���������Ϊ��";
        (*pf)(*(pitems+index));
    }
    if (!index)
        std::cout << "û���������룡";
//Ҳ�������ж�index==top��д "û���������룡"��䣬���д����������ݵ����
    std::cout.put('\n');
}

#endif