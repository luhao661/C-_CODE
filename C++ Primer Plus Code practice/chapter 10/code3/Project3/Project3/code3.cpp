#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//10.10 �����ϰ
//1.
//����10.10.1.cpp
#if 0
#include "10.10.1.h"
int main()
{
	using namespace std;

	cout << "��������ʼ��account1(��ʽ����Ĭ�Ϲ��캯��)\n";
	Account account1;
	account1.show();

	cout << "��������ʼ��account2(��ʽ���ù��캯��)\n";
	Account account2("Xiao Min","123456789876");
	account2.show();

	cout << "С������10��Ǯ��\n";
	account2.deposit(10);
	account2.show();

	cout << "С��ȡ��5��Ǯ��\n";
	account2.draw(5);
	account2.show();

	cout << "Done !\n";

	return 0;
}
#endif


//2.
//����10.10.2.cpp
#if 0
#include "10.10.2.h"

int main()
{
	using namespace std;

	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy","Sam");

	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;

	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;

	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;

	return 0;
}
#endif


//3.
//����10.10.3.cpp
#if 0
#include "10.10.3.h"
int main()
{
	Golf golf1("Xiao min",1);
	golf1.showgolf();
	golf1.handicap(0);
	golf1.showgolf();

	Golf golf2;
	golf2.showgolf();

	return 0;
}
#endif


//4.
//����10.10.4.cpp
#if 0
#include "10.10.4.h"
int main()
{
	using namespace SALES;

	double data[1] = {1.1};
	Sales sales1(data,1);
	sales1.ShowSales();

	Sales sales2;
	sales2.ShowSales();

	return 0;
}
#endif


//5.
//����10.10.5.cpp
#if 0
#include "10.10.5.h"
#include <cctype>
using namespace std;

void show_order(void);
char get_choice(void);
void fill_stack(Stack& st);
void delete_item(Stack& st);

int main() 
{
	Stack stack;

	show_order();
	char ch=get_choice();

	while (ch != 'c')
	{
		switch (ch)
		{
		case 'a':
			fill_stack(stack);
			break;
		case 'b':
			delete_item(stack);
			break;
		}
		show_order();
		ch = get_choice();
	}

	return 0;
}
void show_order(void)
{
	cout << "���������ܶ�Ӧ����ĸ��";
	cout << "\na) ��ӹ˿�"<<'\t'<<"b) ɾ���˿�\n";
	cout << "c) �˳�\n";
}
char get_choice(void)
{
	char answer;
	while (cin.get(answer))
	{
		while (cin.get() != '\n')
			continue;
		answer = tolower(answer);

		if (strchr("abc", answer) == NULL)
			cout << "\a����a��b��c : ";
		else
			break;
	}
	return answer;
}
void fill_stack(Stack& st)
{
	if (st.isfull())
	{
		cout << "ջ������";
		return;
	}

	Item item;
	cout << "������˿͵����֣�";
	char temp[35];
	double money = 0.0;
	while (cin.get(temp, 34))//get()��ȡ���к������ʧЧλ   ***ע***����д��	while (cin.get(temp, 34).get())
	{
		cout << "������˿͸���";
		while (!(cin >> money))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cin.get();

		strcpy(item.fullname,temp);
		item.payment = money;
		st.push(item);
		cout << "������˿͵����֣�(ֻ����Enter��ֹͣ)";
	}

	cin.clear();//***ע***�˾��д
	cin.get();//���ĵ����з�(����ջ�����������)
}
void delete_item(Stack& st)
{
	if(st.isempty())
	{
		cout << "ջΪ�գ�";
		return;
	}

	Item item;
	st.pop(item);

	cout << "ջ����Ա ��" << item.fullname<<'\t'
		<<item.payment<< " popped\n";

	static double sum = 0.0;
	sum += item.payment;

	cout << "����"<<sum<<"Ԫ\n\n";
}
#endif


//6.
//����10.10.6.cpp
#if 0
#include "10.10.6.h"

int main()
{
	Move move;
	move.showmove();

	Move temp(1,1);
	move = move.add(temp);//�������ֵ
	move.showmove();

	move.rest();
	move.showmove();

	return 0;
}
#endif


//7.
//����10.10.7.cpp
#if 0
#include "10.10.7.h"

int main()
{
	BetelPlorg b1;
	b1.show();

	BetelPlorg b2("Xiao min",20);
	b2.show();

	b2.modification(80);
	b2.show();

	return 0;
}
#endif


//8.(���ͣ�����ʵ����ʽ����ʽ�ṹ)
//����10.10.8.cpp
#if 0
#include "10.10.8.h"
void showmovies(Item& item);

char* s_gets(char* string, int num);

int main(void)
{
	List movies;//����һ�������movies(��ʽ����Ĭ�Ϲ��캯��������ʽ��ʼ��)

	Item temp;//����һ��film�ṹ���ֵĽṹtemp

////��ʼ�������ͷָ��
//	InitializeList(&movies);
	if (movies.ListIsFull())
	{
		fprintf(stderr, "�������������Ѵﵽ���ֵ��");
		exit(1);
	}

	//��ȡ�û����벢�洢
	puts("�������Ӱ�ı��⣺");
	while (s_gets(temp.title, LENGTH) != NULL && temp.title[0] != '\0')
	{
		puts("��������������(0-10)��");
		scanf("%d", &temp.rating);

		while (getchar() != '\n')
			continue;

		if (movies.AddItem(temp) == false)
		{
			fprintf(stderr, "���󣬷����ڴ�ʧ�ܣ�");
			break;
		}
		if (movies.ListIsFull())
		{
			puts("���������Ѵﵽ���ֵ��");
			break;
		}

		puts("��������һ����Ӱ�ı���(����^Z��������˳�)��");
	}

	//��ʾ
	if (movies.ListIsEmpty())
		printf("û���������룡\n");
	else
	{
		printf("�����ǵ�ӰĿ¼\n");
		movies.Visit(showmovies);
	}
	printf("��������%d����Ӱ\n", movies.ListItemCount());

	//����
	movies.EmptyTheList();
	printf("�ټ���\n");

	return 0;
}
void showmovies(Item &item)
{
	printf("��Ӱ��:%-20s��Ӱ����:%d\n", item.title, item.rating);
}
char* s_gets(char* string, int num)
{
	char* fanhui;
	char* find;

	fanhui = fgets(string, num, stdin);

	if (fanhui)
	{
		if (find = strchr(string, '\n'))
			*find = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}

	return fanhui;
}
#endif


//8.����(���ͣ�ջ��ʵ����ʽ������)
//ͷ�ļ���ջ����