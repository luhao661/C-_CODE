#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
extern int tom;         // tom defined elsewhere
static int dick = 10;   // overrides external dick 
                                   //����ʽ��������ʼ��һ���ڲ����ӵľ�̬����
                                   //***ע1***����д���������ⲿ���ӵľ�̬����
                                   //***ע2***����д��int dick=10;

int harry = 200;        // external variable definition,
                                  // no conflict with twofile1 harry

void remote_access()
{
    using namespace std;

    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
#endif