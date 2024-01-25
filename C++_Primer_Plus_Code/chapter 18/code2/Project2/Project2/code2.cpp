#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//18.11 ��ϰ��
//1.
//������
#if 0
#include <string>
#include <vector>
//#include <initializer_list>

class Z200
{
private:
	int j;
	char ch;
	double z;
public:
	Z200(int jv, char chv, double zv) : j(jv), ch(chv), z(zv) {}
};

int main()
{
	double x{ 8.8 };
	std::string s{ "What a bracing effect!" };
	int k{ 99 };
	Z200 zip{200, 'Z', 0.675};
	std::vector<int> ai{3,9,4,7,1};
}
#endif
 

//6.
//������
#if 0
template <typename T >
void show2(double x, T& fp)
{
	std::cout << x << " -> " << fp(x) << '\n';
}

//double f1(double x)
//{
//	return 1.8 * x + 32;
//}

//��lambda�������溯������
auto f1 = [](double x) {	return 1.8 * x + 32;	};

int main()
{
	show2(18.0,f1);

	return 0;
}

//***ע***����д������
//int main()
//{
//	show2(18.0, [](double x) {	return 1.8 * x + 32; });
//
//	return 0;
//}
#endif


//7.
//������
#if 1
//�޸�ǰ��
#if 0
#include <array>

const int Size = 5;

template<typename T>
	void sum(std::array<double, Size> a, T& fp);

class Adder
{
	double tot;
public:
	Adder(double q = 0) :tot(q) {}
	void operator() (double w) { tot += w; }
	double tot_v() const { return tot; };
};

int main()
{
	double total = 0.0;
	Adder ad(total);//ad�����tot���ݳ�ԱֵΪ0

	std::array<double, Size>temp_c = { 32.1,34.3,37.8,35.2,34.7 };

	sum(temp_c, ad);
	total = ad.tot_v();

	std::cout << "total:" << ad.tot_v() << '\n';
	return 0;
}

template<typename T>
void sum(std::array<double, Size> a, T & fp)
{
	for (auto pt = a.begin(); pt != a.end(); ++pt)
	{
		fp(*pt);
	}
}
#endif
//�޸ĺ�
#if 0
#include <array>

const int Size = 5;

template<typename T>
void sum(std::array<double, Size> a, T& fp);

int main()
{
	double total = 0.0;

	std::array<double, Size>temp_c = { 32.1,34.3,37.8,35.2,34.7 };

	auto ad = [&total](double w) {	total += w;	};

	sum(temp_c, ad);

	std::cout << "total:" << total << '\n';
	return 0;
}

template<typename T>
void sum(std::array<double, Size> a, T& fp)
{
	for (auto pt = a.begin(); pt != a.end(); ++pt)
	{
		fp(*pt);
	}
}
#endif
#endif