#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_H
#define BCLX12_10_H

class Cow
{
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char *nm,const char *ho,double wt);
	Cow(const Cow &c);
	~Cow();
	Cow& operator=(const Cow& c);//��ֵ��������غ���
	void ShowCow()const;
};

#endif