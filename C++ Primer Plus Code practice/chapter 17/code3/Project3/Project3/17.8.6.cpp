#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "17.8.6.h"
const char* filename = "17.8.6.txt";
//***注***
//为了让程序之后知道要读取的的项目是四个对象中的哪一个
//在对象数据写入文件时，在数据前面加上一个指示对象类型的整数
enum classkind { Employee, Manager, Fink, Highfink };

using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp()
	:fname("no data"), lname("no data"), job("no data")
{}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
	const std::string& j)
	: fname(fn), lname(ln), job(j)
{}

void abstr_emp::ShowAll()const// labels and shows all data
{
	cout << "姓名：" << lname << " " << fname << endl;
	cout << "工作：" << job << endl;
}

void abstr_emp::SetAll() // prompts user for values
{
	cout << "请输入姓：";
	cin >> lname;
	cout << "请输入名：";
	cin >> fname;
	cout << "请输入工作：";
	cin >> job;

	while (cin.get() != '\n')
		continue;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "姓名：" << e.lname << " " << e.fname;

	return os;
}

abstr_emp::~abstr_emp()//***注***必须在ABC的实现文件中要定义纯虚析构函数
{}

const std::string abstr_emp::showfname(void) const
{
	return fname;
}

const std::string abstr_emp::showlname(void) const
{
	return lname;
}
const std::string abstr_emp::showjob(void) const
{
	return job;
}

void abstr_emp::getall(std::ifstream& fin)
{
	using std::getline;

	getline(fin,fname);
	getline(fin, lname);
	getline(fin, job);
}

/****************************************************************************/

employee::employee() :abstr_emp()
{}

employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j) : abstr_emp(fn, ln, j)
{}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::writeall(std::ofstream& fout)
{
	fout.open(filename,std::ios_base::out|std::ios_base::app);

	fout << Employee << endl;
	fout << showfname()<<endl;
	fout << showlname() << endl;
	fout << showjob() << endl;

	//******注******
	//若不写fout.close();
	//则别的对象的数据无法写入文件！！！
	//因为别的对象的writeall()方法又
	//试图用fout打开一个输入流
	fout.close();
	//***注***
	//法二：
	//在ABC中声明并定义writeall()成员函数，
	//这样就不用showfname()等成员函数了。
	//而此被调函数的内容则改写为abstr_emp::writeall(fout);
}

void employee::getall(std::ifstream& fin)
{
	abstr_emp::getall(fin);
}

/****************************************************************************/

manager::manager() :abstr_emp(), inchargeof(0)
{}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)//使用abstr_emp类的默认复制构造函数
{}

manager::manager(const manager& m)
	: abstr_emp(m)//向上强制转换
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "工资：" << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入工资：";
	cin >> inchargeof;

	if (!cin)
		cin.clear();

	while (cin.get() != '\n')
		continue;
}

void manager::writeall(std::ofstream& fout)
{
	fout.open(filename, std::ios_base::out | std::ios_base::app);

	fout << Manager << endl;
	fout << showfname() << endl;
	fout << showlname() << endl;
	fout << showjob() << endl;
	fout << inchargeof<<endl;

	fout.close();
}

void manager::getall(std::ifstream& fin)
{
	abstr_emp::getall(fin);
	fin >> inchargeof;

	//while (fin.get() != '\n')
	//	continue;
	fin.get();
}

/****************************************************************************/

fink::fink() :abstr_emp(), reportsto("no data")
{}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink& e)
	: abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto : " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入reportsto：";
	cin >> reportsto;

	if (!cin)
		cin.clear();

	while (cin.get() != '\n')
		continue;
}

void fink::writeall(std::ofstream& fout)
{
	fout.open(filename, std::ios_base::out | std::ios_base::app);

	fout << Fink << endl;
	fout << showfname() << endl;
	fout << showlname() << endl;
	fout << showjob() << endl;
	fout << reportsto << endl;
	
	fout.close();
}

void fink::getall(std::ifstream& fin)
{
	abstr_emp::getall(fin);
	std::getline(fin,reportsto);
}

/****************************************************************************/

highfink::highfink()
	:manager(), fink(), abstr_emp()//或不写，则调用默认的构造函数
{}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	: manager(fn, ln, j, ico), fink(fn, ln, j, rpo), abstr_emp(fn, ln, j)
{}

highfink::highfink(const abstr_emp& e, const std::string& rpo,
	int ico)
	: manager(e, ico), fink(e, rpo), abstr_emp(e)
{}

highfink::highfink(const fink& f, int ico)
	: manager(f, ico), fink(f), abstr_emp(f)
{}

highfink::highfink(const manager& m, const std::string& rpo)
	: manager(m), fink(m, rpo), abstr_emp(m)
{}

highfink::highfink(const highfink& h)
	: manager(h), fink(h), abstr_emp(h)
{}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "工资：" << manager::InChargeOf() << endl;
	cout << "reportsto : " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入工资：";
	cin >> InChargeOf();
	cout << "请输入reportsto：";
	cin >> ReportsTo();

	if (!cin)
		cin.clear();

	while (cin.get() != '\n')
		continue;
}

void highfink::writeall(std::ofstream& fout)
{
	fout.open(filename, std::ios_base::out | std::ios_base::app);

	fout << Highfink << endl;
	fout << showfname() << endl;
	fout << showlname() << endl;
	fout << showjob() << endl;
	fout << InChargeOf() << endl;
	fout << ReportsTo() << endl;

	fout.close();
}

void highfink::getall(std::ifstream& fin)
{
	manager::getall(fin);
	std::getline(fin, ReportsTo());
}

#endif