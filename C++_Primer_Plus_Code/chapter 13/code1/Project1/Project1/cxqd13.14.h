#define _CRT_SECURE_NO_WARNINGS 1

// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// ����
// Base Class Using DMA
class baseDMA
{
private:
    char* label;
    int rating;

public:
    baseDMA(const char* l = "null", int r = 0);//���캯��
    baseDMA(const baseDMA& rs);//���ƹ��캯��
    virtual ~baseDMA();//����������
    baseDMA& operator=(const baseDMA& rs);//��ֵ��������غ���
    friend std::ostream& operator<<(std::ostream& os,
        const baseDMA& rs);
};

// �������ʵ�ֲ�ʹ��new�����
// derived class without DMA 
// ����ʽ������������(ʹ��Ĭ�ϵ������������Զ�ʹ�û������������)
// no destructor needed
// ʹ��Ĭ�ϵĸ��ƹ��캯���ͺ���Ĭ�ϵĸ��ƹ��캯���ĺ���ͷ��ʽʹ�û���ĸ��ƹ��캯��
// uses implicit copy constructor 
// ʹ��Ĭ�ϵĸ�ֵ��������غ������Զ�ʹ�û���ĸ�ֵ��������غ���
// uses implicit assignment operator
class lacksDMA :public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& os,
        const lacksDMA& rs);
};

// �������ʵ��ʹ��new�����
// derived class with DMA
class hasDMA :public baseDMA
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);//���캯��
    hasDMA(const char* s, const baseDMA& rs);//���캯��
    ~hasDMA();//������ʽ����������
    hasDMA(const hasDMA& hs);//������ʽ�ĸ��ƹ��캯��
    hasDMA& operator=(const hasDMA& rs);//������ʽ�ĸ�ֵ��������غ���
    friend std::ostream& operator<<(std::ostream& os,
        const hasDMA& rs);
};

#endif
