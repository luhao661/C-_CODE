#define _CRT_SECURE_NO_WARNINGS 1

#include <string>

// create the pers and debts namespaces
//����pers��debts���ƿռ�
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };//����һ���ṹ���֣���ǩΪPerson
    void getPerson(Person&);
    void showPerson(const Person&);
}

namespace debts
{
    using namespace pers;//���������ƿռ���ʹ��using����ָ���using����

    struct Debt
    {
        Person name;//Ƕ�׽ṹ
        double amount;
    };//����һ���ṹ���֣���ǩΪDebt

    void getDebt(Debt&);
    void showDebt(const Debt&);
    double sumDebts(const Debt ar[], int n);
}
