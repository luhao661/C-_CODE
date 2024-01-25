#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "14.7.5.h"

using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp()
	:fname("no data"),lname("no data"),job("no data")
{}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
	const std::string& j)
	: fname(fn), lname(ln), job(j)
{}

void abstr_emp::ShowAll()const// labels and shows all data
{
	cout << "������"<<lname<<" " << fname << endl;
	cout << "������"<<job<<endl;
}

void abstr_emp::SetAll() // prompts user for values
{
	cout << "�������գ�";
	cin >> lname;
	cout << "����������";
	cin >> fname;
	cout << "�����빤����";
	cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os<< "������" << e.lname <<" " << e.fname;

	return os;
}

abstr_emp::~abstr_emp()//***ע***������ABC��ʵ���ļ��ж��崿����������
{}

/****************************************************************************/

employee::employee():abstr_emp()
{}

employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j): abstr_emp(fn,ln,j)
{}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

/****************************************************************************/

manager::manager():abstr_emp(),inchargeof(0)
{}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j),inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)//ʹ��abstr_emp���Ĭ�ϸ��ƹ��캯��
{}

manager::manager(const manager& m)
	: abstr_emp(m)//����ǿ��ת��
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "���ʣ�"<<inchargeof<<endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "�����빤�ʣ�";
	cin >> inchargeof;
}

/****************************************************************************/

fink::fink():abstr_emp(),reportsto("no data")
{}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	:abstr_emp(fn,ln,j),reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const std::string& rpo)
	:abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink& e)
	:abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto : "<< reportsto<<endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "������reportsto��";
	cin >> reportsto;
}

/****************************************************************************/

highfink::highfink()
	:manager(),fink(),abstr_emp()//��д�������Ĭ�ϵĹ��캯��
{}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo,int ico)
	:manager(fn,ln,j,ico),fink(fn,ln,j,rpo),abstr_emp(fn,ln,j)
{}

highfink::highfink(const abstr_emp& e, const std::string& rpo,
	int ico)
	:manager(e,ico),fink(e,rpo),abstr_emp(e)
{}

highfink::highfink(const fink& f, int ico)
	:manager(f,ico),fink(f),abstr_emp(f)
{}

highfink::highfink(const manager& m, const std::string& rpo)
	:manager(m), fink(m,rpo), abstr_emp(m)
{}

highfink::highfink(const highfink& h)
	: manager(h), fink(h), abstr_emp(h)
{}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "���ʣ�"<<manager::InChargeOf()<<endl;
	cout << "reportsto : " << ReportsTo()<<endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "�����빤�ʣ�";
	cin >> InChargeOf();
	cout << "������reportsto��";
	cin >> ReportsTo();
}

#endif