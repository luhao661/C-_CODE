#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_17_8_6_H
#define BCLX_17_8_6_H

#include <iostream>
#include <string>
#include <fstream>

class abstr_emp//抽象基类
{
private:
	std::string fname; // abstr_emp's first name
	std::string lname; // abstr_emp's last name
	std::string job;

public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual void ShowAll()const;// labels and shows all data
	virtual void SetAll(); // prompts user for values
	friend std::ostream&
		operator<<(std::ostream& os, const abstr_emp& e);
	//just displays first and last name
	virtual ~abstr_emp() = 0; // virtual base class 纯虚函数

	//为将数据保存到文件中，设计一个虚函数writeall()
	//基类中此为纯虚函数
	virtual void writeall(std::ofstream& fout) = 0;

	//由于不能创建抽象基类对象，所以
	//以下语句public和protected效果一样，
	//都能保护私有数据数据
	const std::string showfname(void) const;
	const std::string showlname(void) const;
	const std::string showjob(void) const;

	virtual void getall(std::ifstream& fin);
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	/*
	~employee()		//可以不写，直接使用默认的析构函数
	{}
	*/

	virtual void writeall(std::ofstream& fout);
	virtual void getall(std::ifstream& fin);
};

class manager : virtual public abstr_emp//虚基类
{
private:
	int inchargeof; // number of abstr_emps managed

protected:
	int InChargeOf() const { return inchargeof; }// output
	int& InChargeOf() { return inchargeof; } // input

public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
	~manager()
	{}

	virtual void writeall(std::ofstream& fout);
	virtual void getall(std::ifstream& fin);
};

class fink : virtual public abstr_emp
{
private:
	std::string reportsto; // to whom fink reports

protected:
	const std::string ReportsTo()const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }

public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);
	virtual void ShowAll() const;
	virtual void SetAll();
	~fink()
	{}

	virtual void writeall(std::ofstream& fout);
	virtual void getall(std::ifstream& fin);
};

class highfink : public manager, public fink // management fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo,
		int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	~highfink()
	{}

	virtual void writeall(std::ofstream& fout);
	virtual void getall(std::ifstream& fin);
};
#endif