#define _CRT_SECURE_NO_WARNINGS 1

// string1.h -- fixed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;             // pointer to string
    int len;                 // length of string
    static int num_strings; // number of objects ����һ����̬�����ݳ�Ա
    static const int CINLIM = 80;  // cin input limit ������Ϊ��ĳ���
public:
    // static function ��̬���Ա����
    static int HowMany();

    // constructors and other methods
    String(const char* s); // constructor
    String();               // default constructor
    String(const String&); //���ƹ��캯��(ע�����ƹ��캯��������һ��ĸ�ֵ)
    ~String();              // destructor
    int length() const { return len; }//��Ա����д��������ʽ

    // overloaded operator methods    
    String& operator=(const String&);//��ֵ��������غ���
    String& operator=(const char*);//��ֵ��������غ���������
                                                    //���ã���ߴ���Ч�ʣ������ٵ��ù��캯������������ת����
                                                    //�ٵ��ø�ֵ��������غ������и�ֵ���Ҫ������������
    char& operator[](int i);
    const char& operator[](int i) const;//���ص��Ǹ������޸ĵ���ֵ
    //��д�ɣ�char operator[](int i) const;

    // overloaded operator friends
    friend bool operator<(const String& st, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);
};
#endif
