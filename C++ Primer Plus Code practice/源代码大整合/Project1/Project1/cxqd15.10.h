#define _CRT_SECURE_NO_WARNINGS 1

// exc_mean.h  -- exception classes for hmean(), gmean()
//�쳣�� bad_hmean��bad_gmean
#ifndef CXQD_15_10_H
#define CXQD_15_10_H

#include <iostream>

class bad_hmean
{
private:
    double v1;
    double v2;

public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    void mesg();
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
        << "invalid arguments: a = -b\n";
}

class bad_gmean
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    const char* mesg();
};

inline const char* bad_gmean::mesg()
{
    return "gmean() arguments should be >= 0\n";
}

#endif