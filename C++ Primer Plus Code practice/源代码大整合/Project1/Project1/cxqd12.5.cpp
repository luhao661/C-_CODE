#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// string1.cpp -- String class methods
#include <cstring>                 // string.h for some
#include "cxqd12.4.h"               // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member ������֮��Ծ�̬�����ݳ�Ա��ʼ��
int String::num_strings = 0;

// static method ��̬��Ա����ֻ�ܷ��ʾ�̬���ݳ�Ա
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];  // allot storage
    std::strcpy(str, s);             // initialize pointer
    num_strings++;               // set object count
}

String::String()                   // default constructor
{
    len = 4;

    //д��һ��***ע***ʹ�ô�д���Ļ�������������cout<<str
    //�ڴ�ӡ����ָ��ָ�������(ʵ����û���κ�����)���ǿ��ֹͣ����
    //str = nullptr;
    //д������
    str = new char[1];//***ע***�˴�Ϊ����delete[]����
    str[0] = '\0';                 // default string

    num_strings++;
}

String::String(const String& st)//�ṩ���ƹ��캯���Ķ��壬�������
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    cout << "\"" <<str<< "\" object deleted, ";
    --num_strings;                    // required
    cout << num_strings << " left\n"; 
    delete[] str;                    // required
}

// overloaded operator methods    
// assign a String to a String
String& String::operator=(const String& st)
{
    if (this == &st)//1.����Ƿ������Ҹ���
        return *this;

    delete[] str;//2.�ͷ�strָ���ԭ��������

    len = st.len;//3.Ϊ���ַ��������㹻���ڴ�ռ�
    str = new char[len + 1];
    std::strcpy(str, st.str);
    
    return *this;//4.ʵ��������ֵ
}

// assign a C string to a String 
String& String::operator=(const char* s)
{
    delete[] str;

    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];

    is.get(temp, String::CINLIM);//������CINLIM-1���ַ��������ַ�ĩβ�Զ���ӿ��ַ�

    if (is)//���û�ж�ȡ������
        st = temp;

    while (is && is.get() != '\n')//���û�ж�ȡ��������cin.get()��û�������з�
        continue;

    return is;//����istream�����ֵ
}

#endif