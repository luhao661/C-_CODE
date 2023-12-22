#define _CRT_SECURE_NO_WARNINGS 1

#ifndef yinhangzhanghu
#define yinhangzhanghu

class Account
{
	static const int LEN = 50;//����LEN���������洢������
	char m_name[LEN];
	enum { LLEN = 80 };//�������ų���
	char m_identification[LLEN];
	double m_savings;
public:
	Account(const char* name, const char* identification, double savings = 0);//����һ�����캯��
	Account();//����һ��Ĭ�Ϲ��캯��
	~Account();//����һ����������
	void show() const;
	void  deposit(double savings);
	void  draw(double savings);
};

#endif  /*yinhangzhanghu*/