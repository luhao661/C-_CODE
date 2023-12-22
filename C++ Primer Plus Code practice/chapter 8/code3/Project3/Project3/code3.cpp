#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//8.8�����ϰ
//1.
#if 0
void print(const char*,int num=0);

int main(void)
{
	const char* p = "ABCdefg";

	for (int i = 0; i < 5; i++)
		print(p,i);

	return 0;
}
void print(const char*p, int num)
{
	using namespace std;
	if(num==0)
	cout << p<<endl<<endl;
	else
	cout << p <<"\t";				//����δ����ɵ��ڶ���������Ϊ0ʱ����ӡ�Ĵ���Ϊ�������õĴ���
}
#endif
//1.����
#if 0
void print(const char*, int num = 0);

int main(void)
{
	const char* p = "ABCdefg";

	print(p);
	print(p);
	print(p,1);


	return 0;
}
void print(const char* p, int num)
{
	using namespace std;

	static int count = 0;						//��������ľ�̬����count���ڴ洢���ú����Ĵ���

	count++;
	if (num == 0)
	{
		cout <<"�ڶ�������Ϊ0\t"<< p << endl;
	}
	else
		for (int i = 0; i < count; i++)
			cout << "�ڶ���������Ϊ0\t" << p << endl;
}
#endif


//2.
#if 0
#include <cstring>

struct CandyBar
{
	char brand[30];
	double weight;
	int calories;
};

void fill_struct(CandyBar&,const char* string="Millennium Munch",
	double weight=2.85, int calories=350);
void show(const CandyBar&);

int main(void)
{
	CandyBar CandyBarStructure;

	fill_struct(CandyBarStructure);
	show(CandyBarStructure);

	return 0;
}
void fill_struct(CandyBar& CB, const char* string,
	const double weight, const int calories)
{
	//strcpy(CB.brand,string);
	//Ҳ����memcpy������ȱ���й�����ĳ��ȵ���Ϣ������strlen()���
	memcpy(CB.brand,string,strlen(string)*sizeof(char)+1);
	CB.weight = weight;
	CB.calories = calories;
}
void show(const CandyBar& CB)
{
	using namespace std;

	cout << CB.brand << endl;
	cout << CB.weight << endl;
	cout << CB.calories << endl;
}
#endif


//3.
#if 0
#include <string>
#include <cstring>
#include <cctype>

void convert(std::string &);

int main()
{
	using namespace std;

	string str;
	cout << "Enter a string (q to quit)��";
	while (getline(cin, str) &&str!="q")
	{
		convert(str);
		cout << str<<endl;
		cout << "Next string (q to quit)��";
	}
	cout << "Bye.";

	return 0;
}
void convert(std::string& shuju)
{
	for (int i = 0; shuju[i]; i++)
	{
		if (islower(shuju[i]))
			shuju[i] = toupper(shuju[i]);
	}
}
//������
#if 0
void convert(std::string& shuju)
{
	for (int i = 0; i<shuju.size(); i++)
	{
		if (islower(shuju[i]))
			shuju[i] = toupper(shuju[i]);
	}
}
#endif
#endif


//4.
#if 0
using namespace std;

#include <cstring> // for strlen(),strcpy()

struct stringy {
	char* str; // points to a string
	int ct; // length of string (not counting'\0')
};

// prototypes for set(),show(),and show()go here
void set(stringy&,const char*);
void show(const stringy&,int num=1);
void show(const char*,int num=1);
//��дΪ��
//void show(const string& st,int num=1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);// first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block,copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); // prints member string twice

	cout << endl << endl;
	
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3);// prints testing string thrice
	show("Done!");
	
	return 0;
}
void set(stringy&r_stringy, const char* p)
{
	r_stringy.str = new char[strlen(p)+1];
	strcpy(r_stringy.str,p);

	r_stringy.ct = strlen(p);
}
void show(const stringy& r_stringy, int num)
{
	if (num < 0)
		num = 1;

	while(num--)
	cout << r_stringy.str;
}
void show(const char*p, int num)
{
	if (num < 0)
		num = 1;

	while (num--)
		cout << p;
}
#endif


//5.
#if 0
template <typename T>
T max5(const T *p);

int main(void)
{
	using namespace std;

	int shuju1[5] = {1,2,3,4,5};
	double shuju2[5] = {1.1,2.2,3.3,4.4,5.5};

	cout <<max5(shuju1)<<endl;//��ʽʵ����
	cout << max5(shuju2) << endl;

	return 0;
}
template <typename T>
T max5(const T* p)
{
	T max = *p;

	for (int i = 0; i < 5; i++)
		if (*(p + i) > max)
			max = p[i];

	return max;
}
#endif


//6.
#if 0
#include <cstring>
template <typename T>
T maxn(const T * p, int num);

//template <>const char* maxn(const char** p, int num);//��ʽ���廯
//����
//û����ָ������ƥ��ĺ���ģ��maxnʵ��

//***ע1***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע2***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
	using namespace std;

	int shuju1[6] = { 1,2,3,4,5,6 };
	double shuju2[4] = { 1.1,2.2,3.3,4.4};

	cout << maxn(shuju1,6)<<endl;
	cout << maxn(shuju2, 4) << endl<<endl;

	const char* shuzu[5] = {"a","bc","defgh","ij","klm"};
	cout << maxn(shuzu,5)<<endl;

	return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
	T max = *p;

	for (int i = 0; i < num; i++)
		if (*(p + i) > max)
			max = p[i];

	return max;
}
/*
template <>const char* maxn(const char** p, int num) 
{
	const char* max = *p;

	for (int i = 0; i < num; i++)
		if (strlen(*(p + i)) >strlen(max))
			max = p[i];

	return max;
}
*/
#endif
//6.�Ľ��汾1
//***�޸İ취***����ƶ���maxn(shuzu, 5)��maxn�������������Զ��ƶϳ� T Ӧ����Ϊʲô����
//�ɴ˿��Դ�����ʽ���廯
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

template <>const char* maxn<const char*>(const char* const* p, int num);

//***ע1***
// T ������Ϊconst char*
//const char* const* p
//ʵ�����Ƕ�����һ��ָ���ַ����Ķ���ָ�룬�ڶ���const����һ��ָ��ָ������ݲ����޸ģ���һ����const���ƶ���ָ��ָ������ݲ����޸ġ�
//https://blog.csdn.net/xc889078/article/details/8909498

//***ע2***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע3***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
	using namespace std;

	int shuju1[6] = { 1,2,3,4,5,6 };
	double shuju2[4] = { 1.1,2.2,3.3,4.4 };

	cout << maxn(shuju1, 6) << endl;
	cout << maxn(shuju2, 4) << endl << endl;

	const char* shuzu[5] = { "a","bc","defgh","ij","klm" };
	cout << maxn(shuzu, 5) << endl;

	return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
	T max = *p;

	for (int i = 0; i < num; i++)
		if (*(p + i) > max)
			max = p[i];

	return max;
}
template <>const char* maxn<const char*>(const char* const* p, int num)
{
	const char* max = *p;

	for (int i = 0; i < num; i++)
		if (strlen(*(p + i)) > strlen(max))
			max = p[i];

	return max;
}
#endif
//6.�Ľ��汾2
#if 0
#include <cstring>
template <typename T>
const T maxn(const T* p, int num);

template <> const char*const maxn<const char*>(const char* const* p, int num);//��ʽ���廯

//***ע1***
// T ������Ϊconst char*
//const char* const* p
//ʵ�����Ƕ�����һ��ָ���ַ����Ķ���ָ�룬�ڶ���const����һ��ָ��ָ������ݲ����޸ģ���һ����const���ƶ���ָ��ָ������ݲ����޸ġ�
//https://blog.csdn.net/xc889078/article/details/8909498

//***ע2***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע3***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
	using namespace std;

	int shuju1[6] = { 1,2,3,4,5,6 };
	double shuju2[4] = { 1.1,2.2,3.3,4.4 };

	cout << maxn(shuju1, 6) << endl;
	cout << maxn(shuju2, 4) << endl << endl;

	const char* shuzu[5] = { "a","bc","defgh","ij","klm" };
	cout << maxn(shuzu, 5) << endl;

	return 0;
}
template <typename T>
const T maxn(const T* p, int num)
{
	T max = *p;

	for (int i = 0; i < num; i++)
		if (*(p + i) > max)
			max = p[i];

	return max;
}
template <> const char* const maxn(const char* const* p, int num)
{
	const char* max = *p;

	for (int i = 0; i < num; i++)
		if (strlen(*(p + i)) >strlen(max))
			max = p[i];

	return max;
}
#endif
//6.�Ľ��汾3 ʹ��string����
#if 0
#include <cstring>
template <typename T>
 T maxn( const T* p, int num);

template <>  std::string maxn<std::string>(const std::string* p, int num);//��ʽ���廯

int main(void)
{
	using namespace std;

	int shuju1[6] = { 1,2,3,4,5,6 };
	double shuju2[4] = { 1.1,2.2,3.3,4.4 };

	cout << maxn(shuju1, 6) << endl;
	cout << maxn(shuju2, 4) << endl << endl;

	string shuzu[5] = { "a","bc","defgh","ij","klm" };
	cout << maxn(shuzu, 5) << endl;//ʵ�Σ���һ������string����ĵ�ַ

	return 0;
}
template <typename T>
 T maxn(const T* p, int num)
{
	T max = *p;

	for (int i = 0; i < num; i++)
		if (*(p + i) > max)
			max = p[i];

	return max;
}
 std::string maxn<std::string>(const std::string* p, int num)
 {
	 std::string max = *p;

	for (int i = 0; i < num; i++)
		if ((*(p + i)).size() > max.size())
			max = p[i];

	return max;
}
#endif
 //6.�汾4  ʹ��string���󣬵����ô���C����ַ������ַ���������
//���޷�ͨ������
#if 0
#include <cstring>
 template <typename T>
 T maxn(T* p, int num);

 template <>  char* maxn(char**, int num);//��ʽ���廯

 int main(void)
 {
	 using namespace std;

	 int shuju1[6] = { 1,2,3,4,5,6 };
	 double shuju2[4] = { 1.1,2.2,3.3,4.4 };

	 cout << maxn(shuju1, 6) << endl;
	 cout << maxn(shuju2, 4) << endl << endl;

	 string shuzu[5] = { "a","bc","defgh","ij","klm" };
	 cout << maxn(shuzu, 5) << endl;//ʵ�Σ���һ������string����ĵ�ַ

	 return 0;
 }
 template <typename T>
 T maxn(const T* p, int num)
 {
	 T max = *p;

	 for (int i = 0; i < num; i++)
		 if (*(p + i) > max)
			 max = p[i];

	 return max;
 }
 template <>  char* maxn(char** p, int num)
 {
	 char* max = *p;

	 for (int i = 0; i < num; i++)
		 if (strlen(*(p + i)) > strlen(max))
			 max = p[i];

	 return max;
 }
#endif


//7.
#if 0
template <typename T>            // template A ����ʵ�����������ƣ���ָ��������Ԫ�ص�ָ��
void ShowArray(T arr[], int n);

template <typename T>            // template B ����ʵ����ָ��һ��ָ��������Ԫ�ص�ָ��
void ShowArray(T** arr, int n);

template <typename T>          
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T **arr, int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	//************************************************************************
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	cout << "Listing Mr. E's counts of things:\n";
	// things is an array of int
	ShowArray(things, 6);  // uses template A
	cout<<SumArray(things,6)<<endl;
//************************************************************************

	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};

	double* pd[3];//����һ��ָ������
	// set pointers to the amount members of the structures in mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;//��ָ�������ÿ��Ԫ��(��ÿ��ָ��)��ֵ�������ǽṹ�ĳ�Աamount�ĵ�ַ

	cout << "Listing Mr. E's debts:\n";
	// pd is an array of pointers to double
	ShowArray(pd, 3);      // uses template B (more specialized)
	cout << SumArray(pd,3) << endl;
//************************************************************************

	// cin.get();
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;

	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	cout << endl;
}

template <typename T>
void ShowArray(T** arr, int n)
{
	using namespace std;

	cout << "template B\n";
	for (int i = 0; i < n; i++)
		/*cout << *arr[i] << ' ';*/cout << **(arr + i) << ' ';
	cout << endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
	T sum=0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

template <typename T>
T SumArray(T** arr, int n)
{
	T sum=0;

	for (int i = 0; i < n; i++)
		sum += *arr[i];

	return sum;
}
#endif