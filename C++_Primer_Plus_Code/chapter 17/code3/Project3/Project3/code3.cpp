#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//17.8 �����ϰ
//1.
//������
#if 0
using namespace std;

int main()
{
//��һ��
//***�ַ�������***

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
	cout << "�������е�һ���ַ��ǣ�" << ch << endl;
	//***ע***getline()�������ֽ��$
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
	cout << "�������е�һ���ַ��ǣ�" << ch << endl;
	//***ע***get()���ֽ��$�Ա�������������
#endif

//������
//***�ַ�����***

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

	//д������
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
	cout << "�������е�һ���ַ��ǣ�" << ch1 << endl;

	return 0;
}
#endif


//2.
//������
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

	//***ע***
	//����д����
	//fout.open(*argv);
	//fout.open(*argv,ios_base::out);
	//��ȷд����
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
//������
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
//������
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

	cout << "��" << duan++ << "��" << endl;
	cout << "fin1��" << endl;
	cout << fin1.eof() << "\t" << fin1.fail()
		<< endl;

	cout << "fin2��" << endl;
	cout << fin2.eof() << "\t" << fin2.fail()
		<< endl;

	while (fin1 || fin2)
	{
		if (fin1 && fin2)
		{
			//Ѱ�Ҵ˶�ĩβ��\0
			char* p=find(temp1,temp1+80,'\0');

			//���˶�ĩβ��\0�滻��' '
			*p = ' ' ;
			//��β����ӿ��ַ�
			*(p + 1) = '\0';

			//ƴ���ַ���
			strncat(temp1, temp2, 79);
			temp1[79] = '\0';

			fout << temp1<<endl;
		}										
		else if (fin1)//***ע1***       
		{									     
			fout << temp1 << endl;

			cout << "fin1��" << endl;
			cout << fin1.eof()<<"\t"<<fin1.fail()
				<<endl;

			cout << "fin2��" << endl;
			cout << fin2.eof() << "\t" << fin2.fail()
				<< endl;
		}
		else
			fout << temp2<<endl;

		fin1.getline(temp1, 80);
		fin2.getline(temp2, 80);

		cout << "��" << duan++ << "��" << endl;
		cout << "fin1��" << endl;
		cout << fin1.eof() << "\t" << fin1.fail()
			<< endl;

		cout << "fin2��" << endl;
		cout << fin2.eof() << "\t" << fin2.fail()
			<< endl;
	}

	cout << "���գ�" << endl;
	cout << endl << fin1.fail() << " " << fin2.fail() << endl;
	cout << endl<<fin1.bad() <<" "<< fin2.bad() << endl;

	return 0;
}
//***ע***
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\Project3
//������ļ������ֱ�ӱ������У����������л���

//ע1��
//��⣺
//�˴�����д��fin1.good()����Ϊ����
//���һ�к�eofbit�ͱ���1����ô�����鲻�ᱻִ��
//��fin1���൱��!fin1.fail()��
 
//***ע***
//�Ӽ�������ʱ����⵽ EOF ��
//cin����λ��eofbit�� failbit��������Ϊ1��
//�����ļ�����ʱ����⵽EOF��
//fin����eof()����Ϊ1

//***ϸ��***
//�ļ���Ϊ���������£�
//��getline()����һ�к�
//����һ�о���EOF
//��fin.eof()Ϊ1��fin.fail()Ϊ0
//�������У�����finû�ܶ�����Ҫ�����ݣ�
//��fin.eof()��fin.fail()��Ϊ1
//����õ���getline���������ֲ�һ����
//Ҫ����EOFʱeof()��Ϊ1��fail()ҲΪ1
//(��D:\CODE\CPP_CODE\Dev-C++\LanQiao\code10 - ����)
//(���԰��ռ����������������)
#endif


//�Ӽ�������ʱ��cin����EOFʱ����״̬
#if 0
#include <fstream>
#include <string>
using namespace std;

int main()
{
//**********************����cin**********************

	char ch1;
	cin >> ch1;//�˴�����^Zģ��EOF

	cout << cin.eof() << " " << cin.fail() << endl;

	if (cin)
		cout << "good"<<endl;

	cout << ch1<<endl;

	cin.clear();

//**********************����cin.get()**********************

	char ch2[10] = "123456789";
	cin.get(ch2,10);//�˴�����^Z����������������
	//��ֱ������^Z��ch2[0]Ϊ���ַ���
	//���������������ݣ���ch2��ԭ�������ݻᱻ�����
	//���ݺͿ��ַ�������
	cout << cin.eof() << " " << cin.fail() << endl;

	//���ڷ�Χ��forѭ����������������飬����˵�������
	//��ֹ�����������⵽���ַ���ֹͣ
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

//**********************����cin.getline()**********************

	char ch3[10] = "123456789";
	cin.getline(ch3, 10);//�˴�����^Z����������������
	//��ֱ������^Z��ch2[0]Ϊ���ַ���
	//���������������ݣ���ch2��ԭ�������ݻᱻ�����
	//���ݺͿ��ַ�������
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
//�޸ģ�
//ʹ��string���������ļ�����Ķ��䲻����ƴ�������
//������������if���ֱ�����
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

	//д������
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
//������
#if 0
//*****************************ע************************************
//���뱨��
//�޷�ʹ�ô�Բ���ŵĳ�ʼֵ�趨���ʼ������
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

const int LIMIT = 20;

bool FillData(set<char[LIMIT]>&);

int main()
{
	set<char[LIMIT]>data_Mat;

	cout << "������������\n";
	FillData(data_Mat);
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char [LIMIT]>data_Pat;

	cout << "������������\n";
	FillData(data_Pat);
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char[LIMIT]>data_M_and_P;
	//��һ��ʹ����Լ��ϲ����ĺ���
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

	//������
	//***ע***���������������λ��
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

	//������
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//����д����(ԭ����P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//����д��������ʹ��back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	cout << "���˵������У�\n";
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
//***ע***
//���뱨��
//�޷�ʹ�ô�Բ���ŵĳ�ʼֵ�趨���ʼ������
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

	cout << "������������\n";
	FillData(data_Mat);
	for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char*>data_Pat;

	cout << "������������\n";
	FillData(data_Pat);
	for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
	{
		cout << *p << '\n';
	}
	cout.put('\n');

	set<char*>data_M_and_P;
	//��һ��ʹ����Լ��ϲ����ĺ���
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

	//������
	//***ע***���������������λ��
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

	//������
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//����д����(ԭ����P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//����д��������ʹ��back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	cout << "���˵������У�\n";
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
	//***ע***
	//�������ԣ�set<char*>data����ʵ��ɾ����ͬ���ַ�������Ϊ
	//�����ַ����ĵ�ַ��ͬ������Ϊ��ͬ
	//���Ҳ��ܽ����ݴ����ļ�����Ϊ�����Ĳ����ַ������ݣ�
	//�����ַ����Ĵ洢��ַ

	return 0;
}
bool FillData(set<char*>& data)
{
	bool status = 1;

	char temp[LIMIT];

	cin.getline(temp, LIMIT);
	while (cin && temp[0] != '\0')
	{
		char* p = new char[LIMIT];//������������ʱ��ֻ������p��
		strcpy(p,temp);					 //��������pָ�������
													 //���ڴ�й©�ķ���
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
//˼·�����Ȼ���ʹ��string������ַ���
//��set�����������ظ����ݺ��ٽ����ݴ���ΪC����ַ�����
//�����������ı�ģʽ��д�����ݣ����Կ���ʹ��string����
//���ļ�д������
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

//����û��Mat���Ѻ�Pat���ѵ��ļ������ȼ���˶�
#if 0

	ofstream fout;
	ifstream fin;

	set<string>data_Mat;

	cout << "������������\n";
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

	cout << "������������\n";
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
	//��һ��ʹ����Լ��ϲ����ĺ���
	//set_union(data_Mat.begin(), data_Mat.end(), 
	//    data_Pat.begin(), data_Pat.end(),
	//    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

	//������
	//***ע***���������������λ��
	//copy(data_Mat.begin(), data_Mat.end(),
	//	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));
	//copy(data_Pat.begin(), data_Pat.end(),
	//	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

	//������
	data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
	data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

	//����д����(ԭ����P569)
	//copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

	//����д��������ʹ��back_insert_iterator
	/*copy(data_Mat.begin(), data_Mat.end(),
		back_insert_iterator<set<string> >(data_M_and_P));*/

	fout << "���˵������У�\n";
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
//***ע***
//�˴�string�������ʱ��ָ���ַ�����ָ���
//�ַ������ݾ��ᱻ����
//�� set<string>data_Mat
//data.insert(temp);
//data_Mat��set�����е�string�����Ѿ���
//temp���ݿ�������
#endif


//6.
//����17.8.6.cpp
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
	cout << em << endl;//***ע***����������û���ض���<<��������غ�����
	em.ShowAll();				//���Ĭ��ʹ�û����<<��������غ���
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

	//***ע***
	//�ڶ�������д���ļ�ʱ��������ǰ���Ѿ�����һ��ָʾ�������͵�����
	enum classkind {Employee,Manager,Fink,Highfink};

	ifstream fin("17.8.6.txt");
	int index = 0;
	//���ļ����ڣ�������ļ�ԭ��������
	if (fin.is_open())
	{
		std::cout << "Here are the current contents of the "
			<< "17.8.6.txt" << " file:\n";

		int classtype;

		while (fin >> classtype)
		{
			fin.get();

//***ע***
//д��
//while ((fin >> classtype).get())
//{
//�������в�����

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

	//����д����
	//fin.seekg(0,ios_base::beg);
	//for (int i = 0; i < index; i++)
	//	pc[i]->getall(fin);

	for (int i = 0; i < index; i++)
		pc[i]->ShowAll();

	//д�����ݣ�

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

	//***ע***
	
	//������⣺
	//����д����ÿ��д���������ݺ󣬴���writeall(...)
	//��fout�����ָ��ָ���λ�û����ļ���ͷ

	//��ȷ��⣺
	//foutֻ�Ǹ�ofstream���������һ�����ָ��
	//fout��ģʽ����׷������ģʽ��fout�������ָ����Ƶ��ļ�ĩβ
	ofstream fout;
	for (int i = 0; i < index; i++)
		pc[i]->writeall(fout);

	cout << "д����ɣ�";

	return 0;
}

void menu(void)
{
	cout << "������Ҫ�����Ķ���ǰ��Ӧ����ĸ��\n";
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
			cout << "������a��b��c��d��q : ";
		else
			break;
	}

	return ch;
}
#endif


//7.
//������
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
		//m_fout = fout;  ����
		//�����m_foutҲ��"strings.dat"������ģʽ��foutһ��������
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
	for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr�Ǻ�������

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each (vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	//***ע***
	//Store(fout)���õ��ǹ��캯��������һ�������ĺ�������
	//���ú�������Ӧ��operator()����

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
//������
//7.
//������
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
	std::ofstream* m_fout;//����һ��ָ��ofstream�����ָ��

public:
	//Store()
	//{}

	//***ע***��һ��&��ʾ���ã��ڶ���&��ʾȡ��ַ
	Store(std::ofstream& fout):m_fout (&fout)
	{}

	void operator()(const std::string& st)
	{
		//***ע***
		//��¼Ҫ�洢���ַ�����Ҫռ�õĿռ�
		int len = st.length()+1;

		if (m_fout->is_open())
		{
			m_fout->write((char*)&len, sizeof len);
			m_fout->write(st.data(), len);//***ע***string����data()����
			//�䷵��һ��ָ�룬ָ��洢���ַ���������
		}
	}

	//***ע***
	//����д�������У�ԭ����P633
	//m_fout->write((char*)&st, len);
	//����д�������У�
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
	for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr�Ǻ�������

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	//***ע***
	//Store(fout)���õ��ǹ��캯��������һ�������ĺ�������
	//���ú�������Ӧ��operator()����

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
		v.push_back(p);//��C����ַ�����յ�string����ֵ
	}
}
#endif


//�����ַ�������string����ֵ��
//������
#if 0
#include <string>

using namespace std;

int main()
{
	char data[2] = {'a','b'};
	string str;

	str = data;
	cout << str << endl;

	//���ۣ�
	//���Ը�ֵ���������޿��ַ����ᵼ�º���ַ�������

	return 0;
}
#endif


//string��c_str()������data()����
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
//���ۣ�������ͬ��Ч����������C����ַ���
#endif