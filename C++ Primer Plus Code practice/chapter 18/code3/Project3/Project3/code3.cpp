#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//18.12 �����ϰ
//1.
//������
#if 0
#include <initializer_list>

using namespace std;

#if 0
template <typename T>						//***ע***�޷�д��decltype(T)
auto average_list(const initializer_list<T>& li) ->decltype(*li.begin())
{
	T sum = 0;

	for(auto p=li.begin();p!=li.end();p++)
	{
		sum += *p;
	}

	return sum / li.size();
}
#endif

//***ע***
//��Ҫ����ֵ�����ͺ�ģ������Ͳ���һ�£���ҲΪT��
//��ӦдΪ��
template <typename T>						
T average_list(const initializer_list<T>& li) 
{
	T sum = 0;

	for (auto p = li.begin(); p != li.end(); p++)
	{
		sum += *p;
	}

	return sum / li.size();
}

int main()
{
	using namespace std;

	// list of double deduced from list contents
	auto q = average_list({ 15.4,10.7,9.0 });
	cout << q << endl;

	// list of int deduced from list contents
	//����Ӧ��Ϊ28.1666666666666666
	//�������������ͽ��нض�
	cout << average_list({ 20,30,19,17,45,38 }) << endl;
	
	// forced list of double
	auto ad = average_list<double>({ 'A',70,65.33 });
	cout << ad << endl;
	
	return 0;
}
#endif


//2.
//������
#if 0
#include "18.12.2.h"

using namespace std;

int main()
{
	{
		cout << "����cv1����"<<endl;
		Cpmv cv1;

		cout <<endl<< "����cv2����"<<endl;
		Cpmv cv2("abc", "123");

		cout << endl<<"����cv3����"<<endl;
		Cpmv cv3(cv1);

		cout << endl<<"����cv4����"<<endl;
		Cpmv cv4(cv1+cv2);

		cout << endl<<"����cv5����"<<endl;
		Cpmv cv5;
		cv5 = cv4;

		cout <<endl<< "����cv6����"<<endl;
		Cpmv cv6;
		cv6 = cv5 + cv2;

		cout << endl;
	}

	return 0;
}
#endif


//3.
//������
#if 0
#include <iomanip>

// definition for 1 parameter
template<typename T>
long double  sum_value(const T& value)
{
	sum += value;

	return sum;
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_value(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
	static T sum = 0;

	sum += value;

	sum_value(args...);//��ֻʣ��һ������ʱ������������Ǹ�����ģ��
							//���ǲ����޷����ݸ������Ǹ�����ģ��
	
}

int main()
{
	auto res1 =	sum_value(1,2,3,4,5);

	auto res2 = sum_value(1.5,2.5,3.5);

	return 0;
}
#endif
//3.����
//������
#if 0
#include <iomanip>

// definition for 1 parameter
template<typename T>
long double  sum_value(const T& value)
{
	return value;
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_value(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
	return value + sum_value(args...);
}

int main()
{
	auto res1 = sum_value(1, 2, 3, 4, 5);
	auto res2 = sum_value(1.5, 2.5, 3.5);
	auto res3 = sum_value('A', 1, 2 );

	std::cout << res1 << std::endl
		<< res2 << std::endl
		<< res3 << std::endl;

	return 0;
}
#endif


//4.
//������
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

#include <functional>

//��������(������)
//������()�������������������ʹ�ú�������ʹ�������
//template<class T>  // functor class defines operator()()
//class TooBig
//{
//private:
//	T cutoff;
//
//public:
//	TooBig(const T& t) : cutoff(t)
//	{}
//	bool operator()(const T& v)
//	{
//		return v > cutoff;
//	}
//};

//void outint(int n)
//{
//	std::cout << n << " ";
//}

int main()
{
	using std::cout;
	using std::endl;

	using std::list;
	using std::for_each;
	using std::remove_if;

	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);

	//  C++0x can use the following instead
	//  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	//  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

	auto outint = [](int n) { cout << n << " ";  };

	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
								//ʹ��������lambda���ʽ
	yadayada.remove_if([](int n) { return n > 100; });               

	//д��һ��
								
	etcetera.remove_if([](int n) { return n > 200; });  

	//д������
	//etcetera.remove_if(std::bind2nd(std::greater<int>(), 200));

	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	// std::cin.get();
	return 0;
}
#endif