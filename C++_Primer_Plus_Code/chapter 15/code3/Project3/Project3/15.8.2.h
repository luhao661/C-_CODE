#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_2_H
#define BCLX_15_8_2_H

#include <iostream>
#include <stdexcept>

class bad_hmean:public std::logic_error//***ע***����Ҫ����Ϊ���м̳У������������ʹ��what()����
{
public:
    bad_hmean(const std::string& s = "�������ƽ����ʧ��\n")
        :std::logic_error(s)
    {}
};

class bad_gmean:public std::logic_error
{
public:
    bad_gmean(const std::string& s = "���㼸��ƽ����ʧ��\n")
        :std::logic_error(s)
    {}
};

#endif