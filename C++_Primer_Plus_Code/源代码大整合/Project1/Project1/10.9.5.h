#define _CRT_SECURE_NO_WARNINGS 1

#ifndef yinhangzhanghu
#define yinhangzhanghu

class Account
{
	static const int LEN = 50;//����LEN���������洢������
	char m_name[LEN];//���m_ǰ׺�Ա��ⷽ�����β�����������ݳ�Ա����ͬ(����ͬ��)
	enum {LLEN=80};//�������ų���
	char m_identification[LLEN];
	double m_savings;
public:
	Account(const char *name,const char *identification,double savings);//����һ�����캯��
	/****ע***���������������书����ͬ
	void init_account(const char *name,const char*identification,double savings);*/
	Account();//����һ��Ĭ�Ϲ��캯��
	~Account();//����һ����������
	void show() const;
	void  deposit(double savings);
	void  draw(double savings);
};

#endif  /*yinhangzhanghu*/