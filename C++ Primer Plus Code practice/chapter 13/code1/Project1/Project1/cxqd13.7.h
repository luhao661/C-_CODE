#define _CRT_SECURE_NO_WARNINGS 1

// brass.h  -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

// Brass Account Class
class Brass
{
private:
    std::string fullName;//�ͻ�����
    long acctNum;         //�˺�
    double balance;       //��ǰ����
public:
    //�����˺�
    Brass(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0);
    //���
    void Deposit(double amt);
    //(�鷽��)ȡ��
    virtual void Withdraw(double amt);
    //��ǰ����
    double Balance() const;
    //(�鷽��)��ʾ�˻���Ϣ
    virtual void ViewAcct() const;
    //(�鷽��)��������
    virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
    //���͸֧���
    double maxLoan;
    //͸֧��������
    double rate;
    //��ǰ��͸֧�ܶ�
    double owesBank;
public:
    //�����๹�캯��
    BrassPlus(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0, double ml = 500,
        double r = 0.11125);
    //�����๹�캯��(ʹ�û�������ʼ�����������)
    BrassPlus(const Brass& ba, double ml = 500,
        double r = 0.11125);
    //(�鷽��)
    virtual void ViewAcct()const;
    //(�鷽��)
    virtual void Withdraw(double amt);
    //�޸Ŀͻ������͸֧��
    void ResetMax(double m) { maxLoan = m; }
    //�޸Ŀͻ�������
    void ResetRate(double r) { rate = r; };
    //��¼�ͻ���Ƿ���еĽ��
    void ResetOwes() { owesBank = 0; }
};

#endif
