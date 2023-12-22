#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//C++11新功能
//1.新类型
//2.统一的初始化
//3.简化声明
//4.智能指针
//5.异常
//6.作用域内枚举
//7.对类的修改  explicit
//8.模板和STL方面的修改
//9.右值引用


//程序清单 18.1 右值引用
//链接无
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


//程序清单18.2 移动构造函数
//链接cxqd18.2.cpp
#if 0
#include "cxqd18.2.h"

using namespace std;

// application
int main()
{
    {
        Useless one(10, 'x');
        //调用复制构造函数
        Useless two = one; // calls copy constructor
        
        //***注***若写成
        //Useless two;
        //two = one;
        //就会发生赋值运算符浅复制，调用析构函数
        //会释放同一片内存两次，导致程序异常终止

        Useless three(20, 'o');
        cout.put('\n');

        //调用+运算符重载函数
        //调用移动构造函数
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


//程序清单18.2.1 使用强制移动move()
//链接cxqd18.2.1.cpp
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


//程序清单18.3 移动语义用于构造函数和赋值运算符重载函数
//链接cxqd18.3.cpp
#if 0
#include <utility>
#include "cxqd18.3.h"

// application
int main()
{
    using std::cout;
    {
        Useless one(10, 'x');

        //调用+运算符重载函数
        //和移动构造函数
        Useless two = one + one;   // calls move constructor
        
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();

        Useless three, four;

        cout << "three = one\n";
        //调用赋值运算符重载函数
        three = one;              // automatic copy assignment
        cout << "now object three = ";
        three.ShowData();
        cout << "and object one = ";
        one.ShowData();

        cout << "four = one + two\n";
        //***注***
        //调用+运算符重载函数
        //和移动构造函数(返回的对象用于对临时对象初始化，
        //然后析构函数马上释放返回的对象占用的内存)
        //和移动赋值运算符重载函数(用于将临时对象的数据
        //直接修改为four的数据，最后再次调用析构函数
        //释放临时对象占用的内存)
        four = one + two;         // automatic move assignment
        cout << "now object four = ";
        four.ShowData();

        cout << "four = move(one)\n";
        //移动赋值运算符重载函数
        four = std::move(one);    // forced move assignment
        cout << "now object four = ";
        four.ShowData();
        cout << "and object one = ";
        one.ShowData();
    }
    //std::cin.get();
}
#endif


//程序清单18.4 使用lambda函数
//链接无
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
    //generate()第三个参数是个不接受任何参数的函数对象(函数符)
    std::generate(numbers.begin(), numbers.end(), std::rand);

    cout << "Sample size = " << Size1 << '\n';

    //使用函数指针(即函数名)
    // using function pointers
    //count_if()第三个参数是个返回值为true或false的函数对象
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    //使用函数对象
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

    //使用lambda函数
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
//引入lambda函数，是为了将类似于函数的表达式用于接受函数指针
//或函数符的函数的参数

//使用lambda函数的好处：
//定义和使用在一处，查看与修改与编辑方便
//简洁度高
//不会阻止内联，效率高
#endif


//程序清单18.5 lambda函数的额外功能
//链接无
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

    //使用两个独立的lambda函数，不使用lambda函数的额外功能
    // using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&count13](int x) {count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    //使用一个lambda函数，利用它的额外功能：可访问作用域内
    //的任何动态变量，可将其名称放在中括号内
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


//程序清单18.7 模板的低效性
//链接无
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
//可以看出：
//模板use_f()有5个不同的实例化
#endif


//程序清单18.8 使用包装器function
//类模板function定义了一个对象，可用于包装调用特征标相同的
//函数指针、函数对象或lambda表达式，
//使模板仅进行一次实例化
//链接无
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
    
    //写法一：
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = sqrt1;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 = [](double u) {return u * u; };
    function<double(double)> ef6 = [](double u) {return u + u / 2.0; };
    
    //写法二：
    cout << use_f(y, function<double(double)>(dub)) << endl;
    //或写作：
    typedef function<double(double)> fdd;
    cout << use_f(y, fdd(sqrt1)) << endl;

    //(写法一后续：)
    cout << use_f(y, ef3) << endl;
    cout << use_f(y, ef4) << endl;
    cout << use_f(y, ef5) << endl;
    cout << use_f(y, ef6) << endl;

    //std::cin.get();
    return 0;
}
#endif
//写法三：要修改模板的模板类型参数
//而且要在调用函数时进行显式实例化
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


//程序清单18.9 可变参数模板
//链接无
#if 0
#include <string>

// definition for 0 parameters -- terminating call
void show_list3() {}
//***注***此函数必须有
//因为函数参数列表递归后每次减少一项
//到最后是0项，必须要有函数能处理0个参数的情况

// definition for 1 or more parameters
//模板参数包Args
//函数参数包args
template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);//此处...表示将函数参数包展开
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


//程序清单18.10 可变参数模板，使用上的改进
//链接无
#if 0
#include <string>

// definition for 0 parameters
//void show_list() {}
//***注***此函数可以没有
//因为递归调用到参数只剩1项时，将调用
//template<typename T>
//void show_list(const T& value)
//而它没有再调用show_list()，故将终止递归

// definition for 1 parameter
template<typename T>
void show_list(const T& value)
{
    std::cout << value << '\n';
}

// definition for 2 or more parameters
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{                           //使用引用以提高传输效率
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


//程序清单18.11 使用Boost库中的Conversion库，
//进行数值和字符串之间的简单转换
//(Boost库未下载，所以无法通过编译)
//链接无
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