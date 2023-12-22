#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//C++11�¹���
//1.������
//2.ͳһ�ĳ�ʼ��
//3.������
//4.����ָ��
//5.�쳣
//6.��������ö��
//7.������޸�  explicit
//8.ģ���STL������޸�
//9.��ֵ����


//�����嵥 18.1 ��ֵ����
//������
#if 0
#include <iostream>

inline double f(double tf)
{
    return 5.0 * (tf - 32.0) / 9.0; 
}

int main()
{
    using namespace std;

    double tc = 21.5;

    double&& rd1 = 7.07;
    double&& rd2 = 1.8 * tc + 32.0;
    double&& rd3 = f(rd2);

    cout << " tc value and address: " << tc << ", " << &tc << endl;
    cout << "rd1 value and address: " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 value and address: " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 value and address: " << rd3 << ", " << &rd3 << endl;
   
    // cin.get();
    return 0;
}
#endif


//�����嵥18.2 �ƶ����캯��
//����cxqd18.2.cpp
#if 0
#include "cxqd18.2.h"

using namespace std;

// application
int main()
{
    {
        Useless one(10, 'x');
        //���ø��ƹ��캯��
        Useless two = one; // calls copy constructor
        
        //***ע***��д��
        //Useless two;
        //two = one;
        //�ͻᷢ����ֵ�����ǳ���ƣ�������������
        //���ͷ�ͬһƬ�ڴ����Σ����³����쳣��ֹ

        Useless three(20, 'o');
        cout.put('\n');

        //����+��������غ���
        //�����ƶ����캯��
        Useless four(one + three);  // calls operator+(), move constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
    // cin.get();
}
#endif


//�����嵥18.2.1 ʹ��ǿ���ƶ�move()
//����cxqd18.2.1.cpp
#if 0
#include "cxqd18.2.1.h"
#include <utility>

using namespace std;

int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;          // calls copy constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        Useless three = move(one);
        cout << "object three: ";
        three.ShowData();
    }

    //cin.get();
}
#endif


//�����嵥18.3 �ƶ��������ڹ��캯���͸�ֵ��������غ���
//����cxqd18.3.cpp
#if 0
#include <utility>
#include "cxqd18.3.h"

// application
int main()
{
    using std::cout;
    {
        Useless one(10, 'x');

        //����+��������غ���
        //���ƶ����캯��
        Useless two = one + one;   // calls move constructor
        
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();

        Useless three, four;

        cout << "three = one\n";
        //���ø�ֵ��������غ���
        three = one;              // automatic copy assignment
        cout << "now object three = ";
        three.ShowData();
        cout << "and object one = ";
        one.ShowData();

        cout << "four = one + two\n";
        //***ע***
        //����+��������غ���
        //���ƶ����캯��(���صĶ������ڶ���ʱ�����ʼ����
        //Ȼ���������������ͷŷ��صĶ���ռ�õ��ڴ�)
        //���ƶ���ֵ��������غ���(���ڽ���ʱ���������
        //ֱ���޸�Ϊfour�����ݣ�����ٴε�����������
        //�ͷ���ʱ����ռ�õ��ڴ�)
        four = one + two;         // automatic move assignment
        cout << "now object four = ";
        four.ShowData();

        cout << "four = move(one)\n";
        //�ƶ���ֵ��������غ���
        four = std::move(one);    // forced move assignment
        cout << "now object four = ";
        four.ShowData();
        cout << "and object one = ";
        one.ShowData();
    }
    //std::cin.get();
}
#endif


//�����嵥18.4 ʹ��lambda����
//������
#if 0
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main()
{
    using std::cout;

    std::vector<int> numbers(Size1);

    std::srand(std::time(0));
    //generate()�����������Ǹ��������κβ����ĺ�������(������)
    std::generate(numbers.begin(), numbers.end(), std::rand);

    cout << "Sample size = " << Size1 << '\n';

    //ʹ�ú���ָ��(��������)
    // using function pointers
    //count_if()�����������Ǹ�����ֵΪtrue��false�ĺ�������
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    //ʹ�ú�������
    // using a functor
    class f_mod
    {
    private:
        int dv;
    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) { return x % dv == 0; }
    };

    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers again
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';

    //ʹ��lambda����
    // using lambdas
    count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    // std::cin.get();
    return 0;
}
//����lambda��������Ϊ�˽������ں����ı��ʽ���ڽ��ܺ���ָ��
//�������ĺ����Ĳ���

//ʹ��lambda�����ĺô���
//�����ʹ����һ�����鿴���޸���༭����
//���ȸ�
//������ֹ������Ч�ʸ�
#endif


//�����嵥18.5 lambda�����Ķ��⹦��
//������
#if 0
#include <vector>
#include <algorithm>
//#include <cmath>
#include <ctime>
#include <cstdlib>
const long Size = 390000L;

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

    cout << "Sample size = " << Size << '\n';

    //ʹ������������lambda��������ʹ��lambda�����Ķ��⹦��
    // using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&count13](int x) {count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    //ʹ��һ��lambda�������������Ķ��⹦�ܣ��ɷ�����������
    //���κζ�̬�������ɽ������Ʒ�����������
    // using a single lambda
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    // std::cin.get();
    return 0;
}
#endif


//�����嵥18.7 ģ��ĵ�Ч��
//������
#if 0
#include <cmath>
#include "cxqd18.6.h"

using namespace std;

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << "  " << use_f(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
    cout << "  " << use_f(y, sqrt1) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f(y, [](double u) {return u * u; }) << endl;
    cout << "Lambda expresson 2:\n";
    cout << "  " << use_f(y, [](double u) {return u + u / 2.0; }) << endl;

    //cin.get();
    return 0;
}
//���Կ�����
//ģ��use_f()��5����ͬ��ʵ����
#endif


//�����嵥18.8 ʹ�ð�װ��function
//��ģ��function������һ�����󣬿����ڰ�װ������������ͬ��
//����ָ�롢���������lambda���ʽ��
//ʹģ�������һ��ʵ����
//������
#if 0
#include "cxqd18.6.h"
#include <math.h>
#include <functional>

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    using std::cout;
    using std::endl;
    using std::function;

    double y = 1.21;
    
    //д��һ��
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = sqrt1;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 = [](double u) {return u * u; };
    function<double(double)> ef6 = [](double u) {return u + u / 2.0; };
    
    //д������
    cout << use_f(y, function<double(double)>(dub)) << endl;
    //��д����
    typedef function<double(double)> fdd;
    cout << use_f(y, fdd(sqrt1)) << endl;

    //(д��һ������)
    cout << use_f(y, ef3) << endl;
    cout << use_f(y, ef4) << endl;
    cout << use_f(y, ef5) << endl;
    cout << use_f(y, ef6) << endl;

    //std::cin.get();
    return 0;
}
#endif
//д������Ҫ�޸�ģ���ģ�����Ͳ���
//����Ҫ�ڵ��ú���ʱ������ʽʵ����
#if 0
#include <math.h>
#include <functional>
using namespace std;

template <typename T>
T use_f(T v, std::function<T(T)> f)
{
    static int count = 0;
    count++;
    cout << "  use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp
{
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator()(double p) { return z_ * p; }
};
class Fq
{
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return z_ + q; }
};

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << "  " << use_f<double>(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
    cout << "  " << use_f<double>(y, sqrt1) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f<double>(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f<double>(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f<double>(y, [](double u) {return u * u; }) << endl;
    cout << "Lambda expression 2:\n";
    cout << "  " << use_f<double>(y, [](double u) {return u + u / 2.0; }) << endl;

    //cin.get();
    return 0;
}
#endif


//�����嵥18.9 �ɱ����ģ��
//������
#if 0
#include <string>

// definition for 0 parameters -- terminating call
void show_list3() {}
//***ע***�˺���������
//��Ϊ���������б�ݹ��ÿ�μ���һ��
//�������0�����Ҫ�к����ܴ���0�����������

// definition for 1 or more parameters
//ģ�������Args
//����������args
template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);//�˴�...��ʾ������������չ��
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list3(n, x);

    std::cout.put('\n');

    show_list3(x * x, '!', 7, mr);

    return 0;
}
#endif


//�����嵥18.10 �ɱ����ģ�壬ʹ���ϵĸĽ�
//������
#if 0
#include <string>

// definition for 0 parameters
//void show_list() {}
//***ע***�˺�������û��
//��Ϊ�ݹ���õ�����ֻʣ1��ʱ��������
//template<typename T>
//void show_list(const T& value)
//����û���ٵ���show_list()���ʽ���ֹ�ݹ�

// definition for 1 parameter
template<typename T>
void show_list(const T& value)
{
    std::cout << value << '\n';
}

// definition for 2 or more parameters
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
    std::cout << value << ", ";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);
    return 0;
}
#endif


//�����嵥18.11 ʹ��Boost���е�Conversion�⣬
//������ֵ���ַ���֮��ļ�ת��
//(Boost��δ���أ������޷�ͨ������)
//������
#if 0
#include <string>
#include "boost/lexical_cast.hpp"
int main()
{
    using namespace std;
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " to ";  // string operator+()
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;
    return 0;
}
#endif