#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//8.7��ϰ��
//2.
#if 0
void song(const char *name="O.My Papa", int times = 1);
#endif


//3.
#if 0
void iquote(int num)
{
    cout << "\"" << num << "\"" << endl;
}
void iquote(double num)
{
    cout << "\"" << num << "\"" << endl;
}
void iquote(std::string str)
{
    cout << "\"" << str << "\"" << endl;
}
#endif


//4.
#if 0
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show(box& r_box)
{
	using namespace std;
	cout << r_box.maker << endl;
	cout << r_box.height << endl;
	cout << r_box.width << endl;
	cout << r_box.length << endl;
	cout << r_box.volume << endl;
}
void fill_volume(box& r_box)
{
	r_box.volume = r_box.length * r_box.width * r_box.height;
}
#endif


//5.
#if 0
#include <array>//array��
#include <string>//string��

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//����һ��const array���󣬸ö������4��string����

void fill(std::array<double, Seasons>& );//�βΣ�ָ��array���������
void show(const std::array<double, Seasons>& );//�βΣ�ָ��array���������

int main()
{
    std::array<double, Seasons> expenses;//����һ��array���󣬰���4��double���͵�ֵ

    fill(expenses);//***ע***ʵ�β���������Ԫ�صĵ�ַ��������������
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons>& r_a)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >>r_a[i];
    }
}

void show(const std::array<double, Seasons> &r_a)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << r_a[i] << '\n';
        total += r_a[i];
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//6.
#if 0
//a.
//ʹ��Ĭ��ֵ��
double mass(double density,double volume=1.0);
//ʹ�ú������ط�
double mass(double density, double volume);
double mass(double density);

//b.
//void repeat(int num=5, const char*);//����Ĭ��ʵ�β����β��б�Ľ�β
//ʹ�ú������ط�
void repeat(int num, const char*);
void repeat(const char*);

//c.
int average(int,int);
double average(double, double);

//d.
/*
char mangle(char* );
const char* mangle(char*);  //***ע***������������ͬ���޷�ʵ�ֺ�������
*/
#endif


//7.
#if 0
template <typename T1,typename T2>
auto bigger(T1 t1, T2 t2)->decltype(t1 > t2 ? t1 : t2)
{
    return (t1 > t2 ? t1 : t2);
}
#endif


//8.
#if 0
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

template <typename T>
T& bigger(T &, T &);

template <>box& bigger(box& b1, box& b2);


template <typename T>
T& bigger(T&x, T& y)
{
    return x > y ? x : y;
}

template <>box& bigger(box& b1, box& b2)
{
    if (b1.volume > b2.volume)
        return b1;
    else
        return b2;
}
#endif