#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD18_2_H
#define CXQD18_2_H

// interface
class Useless
{
private:
    int n;          // number of elements
    char* pc;      // pointer to data

    //��̬���ݳ�Ա
    static int ct;  // number of objects
    
    void ShowObject() const;

public:
    //Ĭ�Ϲ��캯��
    Useless();
    //���캯����Ҳ����Ϊ����ת����;
    explicit Useless(int k);
    //���캯��
    Useless(int k, char ch);
    //���ƹ��캯��
    Useless(const Useless& f); // regular copy constructor
    //�ƶ����캯��
    Useless(Useless&& f);      // move constructor
    //��������
    ~Useless();
    //+��������غ���
    Useless operator+(const Useless& f)const;
    // need operator=() in copy and move versions
    void ShowData() const;
};

#endif
