#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//6.11�����ϰ
//1.
#if 0
#include <cctype>

int main(void)
{
	using namespace std;

	char ch;
	while (cin.get(ch) && ch != '@')
	{
		if (isdigit(ch))
			continue;

		if (islower(ch))
			cout.put(toupper(ch));//***ע***��дΪcout<<toupper(ch);���ӡ�����ַ���Ӧ��ASCIIֵ
		else if (isupper(ch))
			cout.put(tolower(ch));
		else
			cout << ch;
	}
	cout << "�ټ���";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "���������10��ֵ"<<endl;

	double donation[10];
	int index = 0;
	double sum = 0.0;

	while (index<10 && cin >> donation[index])//���������ʱcin����false
	{
		++index;
		sum += donation[index - 1];
	}
	//index�˳�ѭ���󣬴���Ԫ�ظ���

	double average = sum / index;
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		if (donation[i] > average)
			count++;
	}

	cout << "������"<<index<<"������"<<endl;
	cout << "ƽ��ֵ��"<<average<<endl;
	cout << "��������"<<count<<"�����ִ���ƽ��ֵ"<<endl;

	return 0;
}
#endif


//3.
#if 0
#include <cstring>
void showmenu(void);
char get_choice(void);
using namespace std;

int main(void)
{
	showmenu();
	char choice = get_choice();

	switch (choice)
	{
	case 'c':
		cout << "ccccc\n";
		break;
	case 'p':
		cout << "ppppp\n";
		break;
	case 't':
		cout << "A maple is a tree.\n";
		break;
	case 'g':
		cout << "ggggg\n";
		break;
	defalut:
		cout << "Error !\n";
	}

	return 0;
}
void showmenu(void)
{
	cout << "Please enter one of the following choices :"<<endl;
	cout << "c) carnivore p) pianist"<<endl;
	cout << "t) tree g)game"<<endl;
}
char get_choice(void)
{
	char ch;

	/*�Ϸ�����
	while(ch!='c'&&ch!='p'&&ch!='t'&&ch!='g')
	{
			cin.get();
			cout << "������c��p��t��g : " ;
			cin.get(ch);
	}
	*/

	while (cin.get(ch))
	{
		while (cin.get() != '\n')
			continue;
		ch = tolower(ch);

		if (strchr("cptg", ch) == NULL)
			cout << "������c��p��t��g : " ;
		else
			break;
	}

	return ch;
}
#endif


//4.
#if 0
#include <cstring>
#include <cctype>

const int strsize = 30;
void showmenu(void);
char get_choice(void);
void display_by_name(struct bop *p_BopStructure);
void display_by_title(struct bop* p_BopStructure);
void display_by_bopname(struct bop* p_BopStructure);
void display_by_preference(struct bop* p_BopStructure);

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

using namespace std;
int main(void)
{
//***ע***C99��C11Ϊ�ṹ�ṩ��ָ����ʼ������designated initializer��1�����﷨�������ָ����ʼ�������ơ�
//���ǣ��ṹ��ָ����ʼ����ʹ�õ�������ͳ�Ա���������Ƿ����ź��±꣩��ʶ�ض���Ԫ�ء�
//���ǣ�C++��֧�֡�
	struct bop BopStructure[5] = {
		{"Wimp Macho","Programmer","MIPS",0},
		{"Raki Rhodes", "Junior Programmer","\0",1},
		{"Celia Laiter","\0","MIPS",2},
		{"Hoppy Hipman","Analyst Trainee","\0",1 },
		{"Pat Hand","\0","LOOPY",2}
	
	};

	showmenu();
	char choice;

	while ((choice = get_choice())&&choice!='q')
	{
		switch (choice)
		{
		case 'a':
			display_by_name(BopStructure);
			break;
		case 'b':
			display_by_title(BopStructure);
			break;
		case 'c':
			display_by_bopname(BopStructure);
			break;
		case 'd':
			display_by_preference(BopStructure);
			break;
		default:
			cout << "Error !";
			return 1;
		}
		cout << "Next choice : ";
	}

	cout << "Bye !";
	return 0;
}
void showmenu(void)
{
	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name         b. display by title" << endl;
	cout << "c. display by bopname  d. display by preference" << endl;
	cout << "q. quit"<<endl;
	cout << "Enter your choice : ";
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
void display_by_name(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
	{
		//�����Ƶ�д����
		/*if (strlen((p_BopStructure + i)->fullname) == 0)
			continue;
		else*/
			cout << (p_BopStructure + i)->fullname << endl;
	}
}
void display_by_title(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		cout << (p_BopStructure + i)->title<< endl;
}
void display_by_bopname(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		cout << (p_BopStructure + i)->bopname << endl;
}
void display_by_preference(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		switch ((p_BopStructure + i)->preference)
		{
		case 0:
			cout << (p_BopStructure + i)->fullname << endl;
			break;
		case 1:
			cout << (p_BopStructure + i)->title << endl;
			break;
		case 2:
			cout << (p_BopStructure + i)->bopname << endl;
			break;
		}
}
//������
//��main�����������ṹ���飬�������ʼ��
//�����Ļ����������������βζ�������void
#endif


//5.
#if 0
int main(void)
{
	using namespace std;

	cout << "�������������룺";
	long income;
	double tax=0;

	while (cin >> income && income >= 0)
	{
		if (income <= 5000)
			tax = 0;
		else if (income > 5000 && income <= 15000)
			tax = 0 + (income - 5000) * 0.1;
		else if (income > 15000 && income <= 35000)
			tax = (15000 - 5000) * 0.1 + (income - 15000) * 0.15;
		else
			tax = (15000 - 5000) * 0.1 + (35000 - 15000) * 0.15 + (income - 35000) * 0.2;
	
		cout << "��Ӧ����˰�"<<tax<<endl;
	}

	return 0;
}
#endif


//6.
#if 0
#include <string>//getline()

typedef struct
{
	std::string name;
	double donation;
}PeopleTypedef;

int main(void)
{
	using namespace std;
	cout << "�����������������";
	long num=0;
	while (!(cin >> num))//����ǹ涨������ʱcin����false
	{
		cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

		while (cin.get() != '\n')
			continue;    //���ĵ����������

		cout << "Please enter a number: ";//��ʾ�û�������
	}
	cin.get();

	PeopleTypedef* p_PeopleTypedef = new PeopleTypedef [num];

	for (int i = 0; i < num; i++)
	{
		cout << "������������";
		getline(cin, (p_PeopleTypedef + i)->name);

		cout << "��������";
		while (!(cin >> (p_PeopleTypedef + i) ->donation ))//����ǹ涨������ʱcin����false
		{
			cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

			while (cin.get() != '\n')
				continue;    //���ĵ����������

			cout << "Please enter a number: ";//��ʾ�û�������
		}

		cin.get();
	}

	int biaoji1, biaoji2;
	biaoji1 = biaoji2 = 0;

	cout << "\nGrand Patrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation > 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji1 = 1;
		}	
	}
	if (!biaoji1)
		cout << "none\n";

	cout << "\nPatrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation <= 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji2 = 1;
		}
	}
	if (!biaoji2)
		cout << "none\n";

	return 0;
}
#endif


//7.
#if 0
#include <cstring>//strcmp()
#include<cctype>//isupper()

void string_tolower(char *p);
void delete_punctuation(char *p);

int main(void)
{
	using namespace std;
	cout << "Enter words (q to quit) : "<<endl;
	char words[30];
	int length = 0;
	int index,jishu=0;
	int vowels=0, consonants=0,others=0;

	while (cin >> words && strcmp(words, "q"))//ÿ�ζ������˻�һ��Ϊ�հ׵��ַ�
	{
		//�����˻�һ��Ϊ�հ׵��ַ������Ǵ�д��ĸ����ת��ΪСд
		string_tolower(words);
		//�����˻�һ��Ϊ�հ׵��ַ�,���еı�������'\0'�滻
		delete_punctuation(words);

		//�ж����˻�һ��Ϊ�հ׵��ַ��Ƿ��ǵ���
		length=strlen(words);
		for (index = 0; index < length; index++)
		{
			if (isalpha(words[index]))
				++jishu;
		}

		//���ǵ���
		if (jishu == length)
		{
			switch (words[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowels++;
				break;
			/*default:
				consonants++;*/			//����if�������д��
			}

			if (strchr("bcdfghjklmnpqrstvwxyz", words[0]))
				consonants++;
		}
		else//�����ǵ���
			others++;

		jishu = 0;
	}

	cout << "\n"<<vowels<<" words beginning with vowels"<<endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;

	return 0;
}
void string_tolower(char* p)
{
	int length = strlen(p);
	for (int index = 0; index < length; index++)
	{
		if (isupper(*(p+index)))
			*(p + index)=tolower(*(p + index));
	}

	return;
}
void delete_punctuation(char* p)
{
	int length = strlen(p);
	for (int index = 0; index < length; index++)
	{
		if (ispunct(*(p + index)))
			*(p + index) = '\0';
	}

	return;
}
/*�������ݣ�
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
*/
#endif


//8.
#if 0
#include <fstream>                  // file I/O support
													//1.����ͷ�ļ�fstream(���ж�����ifstream��)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main(void)
{
	using namespace std;

	ifstream inFile;                       // object for handling file input
													//2.����һ��ifstream����                                                   

// ifstreamĬ�������뷽ʽ���ļ������ڶ��ļ�
//	ofstreamĬ���������ʽ���ļ�������д�ļ�

	cout << "Enter name of data file: ";
	char filename[SIZE];
	cin.getline(filename, SIZE);

	inFile.open(filename);           // associate inFile with a file
													//3.���ö�����һ���ļ���������

	//����ļ��Ƿ񱻳ɹ���
	if (!inFile.is_open())//failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		// cin.get();    //keep window open
		exit(EXIT_FAILURE);
	}

	char ch;
	int count = 0;                       

	inFile >> ch;                     // get first value
												   //4.��ʹ��cin����ʹ�ø�ifstream����

	while (inFile.good())   // while input good and not at EOF
	{
		++count;                
		inFile >> ch;  
	}

	//ȷ��ѭ����ֹ��ԭ��
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else//inFile.bad()Ϊtrue
		cout << "Input terminated for unknown reason.\n";

	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "���ļ����� " << count <<"���ַ�"<< endl;
	}

	//5.ʹ�����ļ�����close()����ر�
	inFile.close();         // finished with the file

	return 0;
}
//6.11.8.txt
#endif


//9.
#if 0
#include <string>//getline()
#include <fstream>
#include <cstdlib> 

typedef struct
{
	std::string name;
	double donation;
}PeopleTypedef;

int main(void)
{
	using namespace std;

	ifstream inFile;

	inFile.open("6.11.9.txt");

	//cout << "�����������������";

	//����ļ��Ƿ񱻳ɹ���
	if (!inFile.is_open())//failed to open file
	{
		cout << "Could not open the file " << "6.11.9.txt" << endl;
		cout << "Program terminating.\n";
		// cin.get();    //keep window open
		exit(EXIT_FAILURE);
	}

	long num = 0;
	while (!(inFile >> num))//����ǹ涨������ʱcin����false
	{
		cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

		while (cin.get() != '\n')
			continue;    //���ĵ����������

		cout << "Please enter a number: ";//��ʾ�û�������
	}
	inFile.get();

	PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

	for (int i = 0; i < num; i++)
	{
		//cout << "������������";
		getline(inFile, (p_PeopleTypedef + i)->name);

		//cout << "��������";
		while (!(inFile >> (p_PeopleTypedef + i)->donation))//����ǹ涨������ʱinFile����false
		{
			inFile.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

			while (inFile.get() != '\n')
				continue;    //���ĵ����������

			cout << "Please enter a number: ";//��ʾ�û�������
		}

		inFile.get();
	}

	int biaoji1, biaoji2;
	biaoji1 = biaoji2 = 0;

	cout << "\nGrand Patrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation > 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji1 = 1;
		}
	}
	if (!biaoji1)
		cout << "none\n";

	cout << "\nPatrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation <= 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji2 = 1;
		}
	}
	if (!biaoji2)
		cout << "none\n";

	inFile.close();

	return 0;
}
#endif
