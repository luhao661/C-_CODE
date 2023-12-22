#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_18_2_1_H
#define CXQD_18_2_1_H

// interface
class Useless
{
private:
    int n;          // number of elements
    char* pc;      // pointer to data

    static int ct;  // number of objects

    void ShowObject() const;

public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless& f); // regular copy constructor
    Useless(Useless&& f);      // move constructor
    ~Useless();
    Useless operator+(const Useless& f)const;
    // need operator=() in copy and move versions
    void ShowData() const;
};

#endif