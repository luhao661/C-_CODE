#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STRNGBAD_H_
#define STRNGBAD_H_

#include <iostream>

class StringBad
{
private:
    char * str;                // pointer to string
    int len;                   // length of string
    static int num_strings;    // number of objects
public:
    StringBad(const char * s); // constructor
    StringBad();               // default constructor
    ~StringBad();              // destructor
// friend function
    friend std::ostream & operator<<(std::ostream & os, 
                       const StringBad & st);
};
#endif
