#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>    //ʹ��string��
#include <valarray>//ʹ��valarray��

class Student
{
private:
    typedef std::valarray<double> ArrayDb;//�Ѱ���double�������ݵ�
                                                                        //valarray��ȡ����ΪArrayDb
    std::string name;       // contained object
    ArrayDb scores;         // contained object
    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;

public:
    Student(const std::string& s, int n)//���캯��
        : name(s), scores(n)//***ע***�ڳ�ʼ���б���ʹ�õ��ǳ�Ա��
    {}
    Student(const std::string& s, const ArrayDb& a)
        : name(s), scores(a)
    {}
    Student(const char* str, const double* pd, int n)
        : name(str), scores(pd, n) 
    {}
    Student() : name("Null Student"), scores()//Ĭ�Ϲ��캯��
    {}//ʹ���˳�Ա��ʼ���б���name��scores��ʼ��
       //���е�����string��Ĺ��캯����scores���Ĭ�Ϲ��캯��

    //ʹ���˹��캯��������ת�����ԣ�Ȼ��ֻ������ʽ����ת��
    explicit Student(const std::string& s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}

    ~Student() {}

    double Average() const;
    const std::string& Name() const;
    double& operator[](int i);
    double operator[](int i) const;
    // friends
    // input
    friend std::istream& operator>>(std::istream& is,
        Student& stu);  // 1 word
    friend std::istream& getline(std::istream& is,
        Student& stu);  // 1 line
    // output
    friend std::ostream& operator<<(std::ostream& os,
        const Student& stu);
};

#endif
