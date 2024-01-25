#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include  "13.11.1.h"
#include <iostream>
//����ķ���

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strncpy(performers,s1,49);
	performers[49] = '\0';

	strncpy(label,s2,19);
	label[19] = '\0';

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);

	strcpy(label, d.label);
	
	selections = d.selections;

	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy(performers,"no input");
	strcpy(label,"no input");
	selections = playtime = 0;
}

Cd::~Cd()
{}

void Cd::Report() const// reports all CD data
{
	using std::cout;
	using std::endl;

	cout << "Performers : "<<performers<<endl;
	cout << "Label : "<<label<<endl;
	cout << "Selections : "<<selections<<endl;
	cout << "Playtime : " << playtime<<endl;
}

Cd& Cd::operator= (const Cd& d)
{
	if (this == &d)
		return *this;

	strcpy(performers, d.performers);
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

//������ķ���

Classic::Classic():Cd()
{
	strcpy(composition,"no input");
}

Classic::Classic(const char* s1, const char* s2, const char* s3,
	int n, double x):Cd(s1,s2,n,x)
{
	strncpy(composition,s3,19);
	composition[19] = '\0';
}

//***ע***
//����д����
//Classic::~Classic()::~Cd()
//{}
//��ȷд����
Classic::~Classic()
{}//ִ��˳�����ȵ���������������������ٵ��û������������(�빹�캯���ĵ���˳�������෴)

void Classic::Report() const// reports all CD data
{
	Cd::Report();
	std::cout << "Composition : "<<composition<<std::endl;
}

#endif
