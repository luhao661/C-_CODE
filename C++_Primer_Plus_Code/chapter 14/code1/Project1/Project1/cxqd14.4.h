#define _CRT_SECURE_NO_WARNINGS 1

// studenti.h -- defining a Student class using private inheritance
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <string>   
#include <valarray>
                        //���ؼ̳�(�˴�ʹ������������)
class Student : private std::string, private std::valarray<double>
{                       //˽�м̳��ṩ�����������Ƶ��Ӷ����Ա
private:            //��������಻��Ҫ�����˽�����ݳ�Ա
    typedef std::valarray<double> ArrayDb;
    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;
public:
    Student(const std::string& s, int n)//���캯��
        : std::string(s), ArrayDb(n)//***ע***�ڳ�ʼ���б���ʹ�õ�������
    {}
    Student(const std::string& s, const ArrayDb& a)
        : std::string(s), ArrayDb(a) 
    {}
    Student(const char* str, const double* pd, int n)
        : std::string(str), ArrayDb(pd, n)
    {}
    Student() : std::string("Null Student"), ArrayDb() 
    {}

    explicit Student(const std::string& s)
        : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}

    ~Student() {}

    double Average() const;
    double& operator[](int i);
    double operator[](int i) const;
    const std::string& Name() const;
    // friends
    // input
    friend std::istream& operator>>(std::istream& is,
        Student& stu);  // 1 word
    friend std::istream& getline(std::istream& is,
        Student& stu);     // 1 line
    // output
    friend std::ostream& operator<<(std::ostream& os,
        const Student& stu);
};

#endif
