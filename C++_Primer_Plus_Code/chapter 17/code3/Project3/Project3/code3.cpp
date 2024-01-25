#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//17.8 编程练习
//1.
//链接无
#if 0
using namespace std;

int main()
{
//法一：
//***字符串输入***

#if 0
	char data[50];
	cin.getline(data,50,'$');
	int count = 0;
	for (int i = 0; data[i]!='\0'; i++)
	{
		count++;
	}
	cout << count << endl;
	char ch;
	ch = cin.get();
	cout << "输入流中第一个字符是：" << ch << endl;
	//***注***getline()将丢弃分界符$
#endif

#if 0
	char data[50];
	cin.get(data, 50, '$');
	int count = 0;
	for (int i = 0; data[i] != '\0'; i++)
	{
		count++;
	}
	cout << count << endl;
	char ch;
	ch = cin.get();
	cout << "输入流中第一个字符是：" << ch << endl;
	//***注***get()将分界符$仍保留在输入流中
#endif

//法二：
//***字符输入***

	char data[50];
	int index = 0;
	int count = 0;
	char ch;
	cin.get(ch);
	while (ch != '\n')
	{
		data[index++] = ch;
		count++;

		if (cin.peek() == '$')
			break;

		cin.get(ch);
	}

	//写法二：
	/*
	while (cin.peek() != '$')
	{
		cin.get(ch);
		count++;
	}
	*/

	cout << count << endl;
	char ch1;
	ch1 = cin.get();
	cout << "输入流中第一个字符是：" << ch1 << endl;

	return 0;
}
#endif


//2.
//链接无
#if 0
#include <fstream>

using namespace std;

int main(int argc,char **argv)
{
	ofstream fout;

	if (argc > 2)
	{
		exit(EXIT_FAILURE);
	}

	//***注***
	//错误写法：
	//fout.open(*argv);
	//fout.open(*argv,ios_base::out);
	//正确写法：
	fout.open(*(argv+1));

	if (fout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	cin.get(ch);
	while (cin)
	{
		fout << ch;

		cin.get(ch);
	}

	return 0;
}
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\x64\Debug
#endif


//3.
//链接无
#if 0
#include <fstream>

using namespace std;

int main(int argc,char** argv)
{
	ifstream fin;
	ofstream fout;

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cerr << "error 1\n";
		exit(EXIT_FAILURE);
	}

	fout.open(argv[2]);
	if (!fout.is_open())
	{
		cerr << "error 2\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	fin.get(ch);
	while (fin)
	{
		fout << ch;

		fin.get(ch);
	}

	fin.close();
	fout.close();

	cout << "Done !\n";

	return 0;
}
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\x64\Debug
//Project3.exe 17.8.3.1.txt 17.8.3.2.txt
#endif


//4.
//链接无
#if 0
#include <fstream>
#include <algorithm>

using namespace std;

const char* file1 = "17.8.4.1.txt";
const char* file2 = "17.8.4.2.txt";
const char* file3 = "17.8.4.3.txt";

int duan = 1;

int main()
{
	ifstream fin1,fin2;
	ofstream fout;

	fin1.open(file1);
	if (!fin1.is_open())
	{
		cerr << "error 1\n";
		exit(EXIT_FAILURE);
	}

	fin2.open(file2);
	if (!fin2.is_open())
	{
		cerr << "error 2\n";
		exit(EXIT_FAILURE);
	}

	fout.open(file3);
	if (!fout.is_open())
	{
		cerr << "error 3\n";
		exit(EXIT_FAILURE);
	}

	char temp1[80] = {'\0'};
	char temp2[80] = {'\0'};

	fin1.getline(temp1,80);
	fin2.getline(temp2, 80);

	cout << "第" << duan++ << "段" << endl;
	cout << "fin1：" << endl;
	cout << fin1.eof() << "\t" << fin1.fail()
		<< endl;

	cout << "fin2：" << endl;
	cout << fin2.eof() << "\t" << fin2.fail()
		<< endl;

	while (fin1 || fin2)
	{
		if (fin1 && fin2)
		{
			//寻找此段末尾的\0
			char* p=find(temp1,temp1+80,'\0');

			//将此段末尾的\0替换成' '
			*p = ' ' ;
			//结尾再添加空字符
			*(p + 1) = '\0';

			//拼接字符串
			strncat(temp1, temp2, 79);
			temp1[79] = '\0';

			fout << temp1<<endl;
		}										
		else if (fin1)//***注1***       
		{									     
			fout << temp1 << endl;

			cout << "fin1：" << endl;
			cout << fin1.eof()<<"\t"<<fin1.fail()
				<<endl;

			cout << "fin2：" << endl;
			cout << fin2.eof() << "\t" << fin2.fail()
				<< endl;
		}
		else
			fout << temp2<<endl;

		fin1.getline(temp1, 80);
		fin2.getline(temp2, 80);

		cout << "第" << duan++ << "段" << endl;
		cout << "fin1：" << endl;
		cout << fin1.eof() << "\t" << fin1.fail()
			<< endl;

		cout << "fin2：" << endl;
		cout << fin2.eof() << "\t" << fin2.fail()
			<< endl;
	}

	cout << "最终：" << endl;
	cout << endl << fin1.fail() << " " << fin2.fail() << endl;
	cout << endl<<fin1.bad() <<" "<< fin2.bad() << endl;

	return 0;
}
//***注***
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\Project3
//下添加文件后可以直接编译运行，不用命令行环境

//注1：
//理解：
//此处不能写成fin1.good()，因为读到
//最后一行后eofbit就被置1，那么此语句块不会被执行
//而fin1，相当于!fin1.fail()，
 
//***注***
//从键盘输入时，检测到 EOF 后，
//cin将两位（eofbit和 failbit）都设置为1。
//而从文件输入时，检测到EOF后
//fin仅将eof()设置为1

//***细节***
//文件作为输入的情况下，
//当getline()读入一行后，
//若下一行就是EOF
//则fin.eof()为1，fin.fail()为0
//继续运行，由于fin没能读到想要的内容，
//则fin.eof()和fin.fail()都为1
//如果用的是getline函数，则又不一样，
//要读到EOF时eof()才为1，fail()也为1
//(见D:\CODE\CPP_CODE\Dev-C++\LanQiao\code10 - 副本)
//(可以按照键盘输入的情况来理解)
#endif


//从键盘输入时，cin读到EOF时的流状态
#if 0
#include <fstream>
#include <string>
using namespace std;

int main()
{
//**********************对于cin**********************

	char ch1;
	cin >> ch1;//此处输入^Z模拟EOF

	cout << cin.eof() << " " << cin.fail() << endl;

	if (cin)
		cout << "good"<<endl;

	cout << ch1<<endl;

	cin.clear();

//**********************对于cin.get()**********************

	char ch2[10] = "123456789";
	cin.get(ch2,10);//此处输入^Z或输入正常的内容
	//若直接输入^Z则ch2[0]为空字符，
	//若输入正常的内容，则ch2中原来的内容会被输入的
	//内容和空字符所覆盖
	cout << cin.eof() << " " << cin.fail() << endl;

	//基于范围的for循环，会遍历整个数组，就是说不能添加
	//终止条件，比如检测到空字符就停止
	//for (auto x : ch2)
	//{
	//	cout << x;
	//}
	for (int index = 0; ch2[index]; index++)
	{
		cout << ch2[index];
	}
	cout.put('\n');

	cin.clear();

//**********************对于cin.getline()**********************

	char ch3[10] = "123456789";
	cin.getline(ch3, 10);//此处输入^Z或输入正常的内容
	//若直接输入^Z则ch2[0]为空字符，
	//若输入正常的内容，则ch2中原来的内容会被输入的
	//内容和空字符所覆盖
	cout << cin.eof() << " " << cin.fail() << endl;

	for (int index = 0; ch3[index]; index++)
	{
		cout << ch3[index];
	}
	cout.put('\n');

	cin.clear();

	return 0;
}
#endif
#if 0
//修改：
//使用string对象，两个文件输入的段落不是先拼接再输出
//而是利用两个if语句直接输出
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const char* file1 = "17.8.4.1.txt";
const char* file2 = "17.8.4.2.txt";
const char* file3 = "17.8.4.3.txt";

int main()
{
	ifstream fin1, fin2;
	ofstream fout;

	fin1.open(file1);
	if (!fin1.is_open())
	{
		cerr << "error 1\n";
		exit(EXIT_FAILURE);
	}

	fin2.open(file2);
	if (!fin2.is_open())
	{
		cerr << "error 2\n";
		exit(EXIT_FAILURE);
	}

	fout.open(file3);
	if (!fout.is_open())
	{
		cerr << "error 3\n";
		exit(EXIT_FAILURE);
	}

	//char temp1[80] = { '\0' };
	//char temp2[80] = { '\0' };

	//fin1.getline(temp1, 80);
	//fin2.getline(temp2, 80);

	string str;

	while (!fin1.eof() || !fin2.eof())
	{
		if (getline(fin1, str) && str.size() > 0)
			fout << str<<' ';

		if (getline(fin2, str) && str.size() > 0)
			fout << str<<' ';

		fout << endl;
	}

	//写法二：
	/*
	while (fin1 || fin2)
	{
		if (getline(fin1, str))
			fout << str << ' ';

		if (getline(fin2, str))
			fout << str << ' ';

		fout << endl;
	}
	*/

	return 0;
}
#endif


//5.
//链接无
#if 0
//*****************************注************************************
//编译报错：
//无法使用带圆括号的初始值设定项初始化数组
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

const int LIMIT = 20;

bool FillData(set<char[LIMIT]>&);

int main()
{
	set<char[LIMIT]>data_Mat;

	cout << "请输入姓名：\n";
	FillData(data_Mat);
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char [LIMIT]>data_Pat;

	cout << "请输入姓名：\n";
	FillData(data_Pat);
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char[LIMIT]>data_M_and_P;
	//法一：使用针对集合操作的函数
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//使用插入迭代器

	//法二：
	//***注***必须插入在容器首位置
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

	//法三：
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//错误写法：(原因：书P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//错误写法：错误使用back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	cout << "两人的朋友有：\n";
	for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	return 0;
}
bool FillData(set<char[LIMIT]>& data)
{
	bool status = 1;

	char temp[LIMIT];

	cin.getline(temp,LIMIT);
	while (cin && temp[0] != '\0')
	{
		data.insert(temp);
		cin.getline(temp, LIMIT);
	}

	if (cin)
		cin.clear();

	if (data.size() == 0)
		status = 0;

	return status;
}
#endif
#if 0
//***注***
//编译报错：
//无法使用带圆括号的初始值设定项初始化数组
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

const int LIMIT = 20;

bool FillData(set<char*>&);

int main()
{
	set<char*>data_Mat;

	cout << "请输入姓名：\n";
	FillData(data_Mat);
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char*>data_Pat;

	cout << "请输入姓名：\n";
	FillData(data_Pat);
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char*>data_M_and_P;
	//法一：使用针对集合操作的函数
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//使用插入迭代器

	//法二：
	//***注***必须插入在容器首位置
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

	//法三：
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//错误写法：(原因：书P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//错误写法：错误使用back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	cout << "两人的朋友有：\n";
	for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	ofstream fout;
	ifstream fin;
	fout.open("17.8.5.txt",ios_base::binary);

	fout.write((char*) &data_Mat, sizeof data_Mat);

	set<char*>data;
	fin.read((char*)&data, sizeof data_Mat);
	for (auto p = data.begin(); p != data.end(); p++)
	{
		cout << *p << '\n';
	}
	//***注***
	//经过测试，set<char*>data不能实现删除相同的字符串，因为
	//两个字符串的地址不同，则视为不同
	//而且不能将内容存入文件，因为拷贝的不是字符串数据，
	//而是字符串的存储地址

	return 0;
}
bool FillData(set<char*>& data)
{
	bool status = 1;

	char temp[LIMIT];

	cin.getline(temp, LIMIT);
	while (cin && temp[0] != '\0')
	{
		char* p = new char[LIMIT];//被调函数过期时，只会销毁p，
		strcpy(p,temp);					 //不会销毁p指向的内容
													 //有内存泄漏的风险
		data.insert(p);
		cin.getline(temp, LIMIT);
	}

	if (cin)
		cin.clear();

	if (data.size() == 0)
		status = 0;

	return status;
}
#endif
//思路：首先还是使用string对象存字符串
//待set容器处理完重复数据后，再将数据处理为C风格字符串，
//或者由于是文本模式下写入数据，所以可以使用string对象
//向文件写入数据
#if 0
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

bool FillData(set<string>&);
int main()
{

//若还没有Mat朋友和Pat朋友的文件，则先激活此段
#if 0

	ofstream fout;
	ifstream fin;

	set<string>data_Mat;

	cout << "请输入姓名：\n";
	FillData(data_Mat);
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	fout.open("17.8.5.1.txt");
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		fout << (* p) << '\n';
	}
	fout.close();

	set<string>data_Pat;

	cout << "请输入姓名：\n";
	FillData(data_Pat);
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	fout.open("17.8.5.2.txt");
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		fout << (* p).c_str() << '\n';
	}
	fout.close();
#endif

#if 1

	ofstream fout("17.8.5.3.txt");
	ifstream fin;

	fin.open("17.8.5.1.txt");
	string temp;
	set<string>data_Mat;
	while (getline(fin, temp))
	{
		data_Mat.insert(temp);
	}
	fin.close();

	fin.open("17.8.5.2.txt");
	set<string>data_Pat;
	while (getline(fin, temp))
	{
		data_Pat.insert(temp);
	}
	fin.close();

	set<string>data_M_and_P;
	//法一：使用针对集合操作的函数
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//使用插入迭代器

	//法二：
	//***注***必须插入在容器首位置
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

	//法三：
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//错误写法：(原因：书P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//错误写法：错误使用back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	fout << "两人的朋友有：\n";
	for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
	{
		fout << *p << '\n';
	}

	std::cout << "Done !\n";

#endif

	return 0;
}
bool FillData(set<string>& data)
{
	bool status = 1;

	string temp;

	getline(cin, temp);
	while (cin && temp != "")
	{
		data.insert(temp);
		getline(cin, temp);
	}

	if (cin)
		cin.clear();

	if (data.size() == 0)
		status = 0;

	return status;
}
//***注***
//此处string对象过期时其指向字符串的指针和
//字符串内容均会被销毁
//但 set<string>data_Mat
//data.insert(temp);
//data_Mat的set容器中的string对象已经把
//temp内容拷贝好了
#endif


//6.
//链接17.8.6.cpp
#if 0
#include "17.8.6.h"
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 10;
abstr_emp* pc[MAX];

void menu(void);
char get_choice(void);

int main(void)
{
	/*
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;//***注***若派生类中没有重定义<<运算符重载函数，
	em.ShowAll();				//则会默认使用基类的<<运算符重载函数
	cout.put('\n');

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout.put('\n');

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	cout.put('\n');

	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	cout.put('\n');

	cout << "Press a key for next phase:\n";
	cin.get();

	highfink hf2;
	hf2.SetAll();
	cout.put('\n');

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp* tri[4] = { &em,&fi,&hf,&hf2 };

	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
	*/

	//***注***
	//在对象数据写入文件时，在数据前面已经加上一个指示对象类型的整数
	enum classkind {Employee,Manager,Fink,Highfink};

	ifstream fin("17.8.6.txt");
	int index = 0;
	//若文件存在，则输出文件原来的内容
	if (fin.is_open())
	{
		std::cout << "Here are the current contents of the "
			<< "17.8.6.txt" << " file:\n";

		int classtype;

		while (fin >> classtype)
		{
			fin.get();

//***注***
//写成
//while ((fin >> classtype).get())
//{
//程序运行不正常

			switch (classtype)
			{
			case Employee:
				pc[index] = new employee;
				pc[index]->getall(fin);
				break;
			case Manager:
				pc[index] = new manager;
				pc[index]->getall(fin);
				break;
			case Fink:
				pc[index] = new fink;
				pc[index]->getall(fin);
				break;
			case Highfink:
				pc[index] = new highfink;
				pc[index]->getall(fin);
				break;
			}

			index++;
		}

		fin.close();
	}

	//错误写法：
	//fin.seekg(0,ios_base::beg);
	//for (int i = 0; i < index; i++)
	//	pc[i]->getall(fin);

	for (int i = 0; i < index; i++)
		pc[i]->ShowAll();

	//写入数据：

	index = 0;
	while (index < 10)
	{
		menu();
		char choice = get_choice();

		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'a':
			pc[index] = new employee;
			break;
		case 'b':
			pc[index] = new manager;
			break;
		case 'c':
			pc[index] = new fink;
			break;
		case 'd':
			pc[index] = new highfink;
			break;
		}

		pc[index]->SetAll();

		index++;
	}

	//***注***
	
	//错误理解：
	//错误写法：每次写入对象的内容后，传入writeall(...)
	//的fout的输出指针指向的位置还是文件开头

	//正确理解：
	//fout只是个ofstream对象，其包含一个输出指针
	//fout打开模式都是追加内容模式，fout含的输出指针会移到文件末尾
	ofstream fout;
	for (int i = 0; i < index; i++)
		pc[i]->writeall(fout);

	cout << "写入完成！";

	return 0;
}

void menu(void)
{
	cout << "请输入要创建的对象前对应的字母：\n";
	cout << left<<setw(15)<<"a) employee"
		<<setw(8)<<"b) manager"<<endl
		<< setw(15) << "c) fink"
		<< setw(8) << "d) highfink" << endl;
}
char get_choice(void)
{
	char ch;
	while (cin.get(ch))
	{
		while (cin.get() != '\n')
			continue;
		ch = tolower(ch);

		if (strchr("abcdq", ch) == NULL)
			cout << "请输入a、b、c、d或q : ";
		else
			break;
	}

	return ch;
}
#endif


//7.
//链接无
#if 0
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

void ShowStr(const std::string&);

class Store
{
private:
	std::ofstream m_fout;

	struct 
	{
		char temp[50];

		char* data(void)
		{
			return temp;
		}
	}s;

public:
	Store()
	{}
	Store(std::ofstream& fout)
	{
		//m_fout = fout;  报错
		//如何让m_fout也打开"strings.dat"，而且模式和fout一样？？？
	}

	void operator()(const std::string& st)
	{
		int len = st.length();

		strcpy(s.temp,st.c_str());

		m_fout.write((char*)&len,sizeof(std::size_t));
		m_fout.write(s.data(),len);
	}

	~Store()
	{}
};

void GetStrs(std::ifstream& ,std::vector<std::string>& );

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;

	// acquire strings
	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr是函数对象

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each (vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	//***注***
	//Store(fout)调用的是构造函数，生成一个匿名的函数对象，
	//而该函数对象应有operator()方法

	//recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const std::string& st)
{
	std::cout << st << std::endl;
}
#endif
//改正：
//7.
//链接无
#if 0
#include <vector>
#include <string>
//#include <sstream>
#include <fstream>
#include <algorithm>

void ShowStr(const std::string&);

class Store
{
private:
	std::ofstream* m_fout;//声明一个指向ofstream对象的指针

public:
	//Store()
	//{}

	//***注***第一个&表示引用，第二个&表示取地址
	Store(std::ofstream& fout):m_fout (&fout)
	{}

	void operator()(const std::string& st)
	{
		//***注***
		//记录要存储的字符串需要占用的空间
		int len = st.length()+1;

		if (m_fout->is_open())
		{
			m_fout->write((char*)&len, sizeof len);
			m_fout->write(st.data(), len);//***注***string类有data()方法
			//其返回一个指针，指向存储了字符串的数组
		}
	}

	//***注***
	//以下写法不可行，原因书P633
	//m_fout->write((char*)&st, len);
	//以下写法均可行：
	//m_fout->write(st.data(), len);
	//m_fout->write(st.c_str(), len);

	~Store()
	{}
};

void GetStrs(std::ifstream&, std::vector<std::string>&);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;

	// acquire strings
	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr是函数对象

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	//***注***
	//Store(fout)调用的是构造函数，生成一个匿名的函数对象，
	//而该函数对象应有operator()方法

	//recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const std::string& st)
{
	std::cout << st << std::endl;
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& v)
{
	int len;
	char* p;

	while (fin.read((char*)&len, sizeof len))
	{
		p = new char[len];
		fin.read(p,len);
		v.push_back(p);//用C风格字符串向空的string对象赋值
	}
}
#endif


//能用字符数组向string对象赋值吗
//链接无
#if 0
#include <string>

using namespace std;

int main()
{
	char data[2] = {'a','b'};
	string str;

	str = data;
	cout << str << endl;

	//结论：
	//可以赋值，但由于无空字符，会导致后的字符是乱码

	return 0;
}
#endif


//string的c_str()方法和data()方法
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	{
		string s = "12345";
		char test[10];
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			test[i] = 'z';
		}

		strncpy(test, s.c_str(), 6);
		for (i = 0; i < 10; i++)
		{
			printf("%c ", test[i]);
		}

		cout << endl;
	}

	{
		string s = "12345";
		char test[10];
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			test[i] = 'z';
		}

		strncpy(test, s.data(), 6);
		for (i = 0; i < 10; i++)
		{
			printf("%c ", test[i]);
		}

		cout << endl;
	}

	return 0;
}
//https://blog.csdn.net/stpeace/article/details/50640317
//结论：两者相同的效果，都返回C风格字符串
#endif