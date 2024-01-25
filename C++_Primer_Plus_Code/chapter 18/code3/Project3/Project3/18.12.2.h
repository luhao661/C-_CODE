#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX18_12_2_H
#define BCLX18_12_2_H

#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};

private:
	Info* pi;

public:
	//Ĭ�Ϲ��캯��
	Cpmv();
	//���캯��
	Cpmv(std::string q, std::string z);
	//���ƹ��캯��
	Cpmv(const Cpmv& cp);
	//�ƶ����ƹ��캯��
	Cpmv(Cpmv &&mv);
	//��������
	~Cpmv();

	//��ֵ��������غ���
	Cpmv& operator= (const Cpmv& cp);
	//�ƶ���ֵ��������غ���
	Cpmv& operator= (Cpmv&& mv);
	//+��������غ���
	Cpmv operator+ (const Cpmv& obj) const;

	void Display() const;
};

#endif