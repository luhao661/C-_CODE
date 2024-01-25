#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX13_11_3_H 
#define BCLX13_11_3_H
#include <iostream>

class DmaABC
{
private:
	char* label;
    int rating;

public:
	DmaABC(const char*s="no data",int r=0);
    //������⣺
    //DmaABC(const DmaABC& d); ������಻��Ҫ���ƹ��캯����
    //��Ϊ������಻��������Ķ��󣬲�����ֽ�һ�������ʼ��Ϊ��һ����������
    //��ȷ��⣺
    //DmaABC(const DmaABC& d);Ҫд
    //��Ϊ������Ĺ��캯��baseDMA(const baseDMA& rs)����ʵ�ֻ���
    //��Ա��ʼ���б���ó������ĸ��ƹ��캯��
    //���Ҵ���ʹ����new�����Ա�����ʽ�ض���������
    DmaABC(const DmaABC& d);
	virtual ~DmaABC()=0;
    DmaABC& operator=(const DmaABC& d);
	virtual void View()const=0;
    //friend std::ostream& operator<<(std::ostream& os,
    //    const baseDMA& rs);//***ע***�����ɶ��󣬿��Բ�ʹ��

protected://***ע***���������಻��ֱ�ӷ��ʳ�������˽�г�Ա��
    char* See_label(void)const;//���Խ�����������ͨ��protected��Ա�����ʳ�������˽�г�Ա
    int See_rating(void)const;//������������������public�Ļ�����ͻ��ͷ��������ܷ����ˣ�
};                                             //����ʹ��protected����

class baseDMA:public DmaABC
{
//����û��private��Ա

public:
    baseDMA(const char* l = "null", int r = 0);//���캯��

    //����������û��ʹ��new�����Կ��Բ���ʽ�ض���������
    baseDMA(const baseDMA& rs);//���ƹ��캯��
    virtual ~baseDMA();//����������
    baseDMA& operator=(const baseDMA& rs);//��ֵ��������غ���

    virtual void View(void)const;
};

class lacksDMA :public DmaABC
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    virtual void View(void)const;
};

class hasDMA :public DmaABC
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);//���캯��
    hasDMA(const char* s, const baseDMA& rs);//���캯��
    hasDMA(const hasDMA& hs);//������ʽ�ĸ��ƹ��캯��
    ~hasDMA();//������ʽ����������
    hasDMA& operator=(const hasDMA& rs);//������ʽ�ĸ�ֵ��������غ���
    virtual void View()const;
};

#endif
