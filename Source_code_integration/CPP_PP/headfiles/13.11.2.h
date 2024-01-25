#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX13_11_2_H 
#define BCLX13_11_2_H
// base class
class Cd
{// represents a CD disk
private:
	char* performers;
	char* label;
	int selections; // number of selections
	double playtime;// playing time in minutes

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;// reports all CD data
	Cd& operator= (const Cd& d);
};

class Classic :public Cd
{
private:
	char *composition;

public:
	Classic();
	Classic(const char* s1, const char* s2, const char* s3,
		int n, double x);
	virtual ~Classic();
	Classic(const Classic& c);
	virtual void Report() const;// reports all CD data
	Classic& operator=(const Classic&d);
	//***ע***��ʹ��������Ĭ�ϵĸ�ֵ��������غ���Classic & operator=(const Classic&);
	//��������������ὫͬһƬ�ڴ��ͷŶ��Σ���ɴ���
};

#endif
