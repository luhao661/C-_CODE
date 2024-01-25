#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//chapter
//code


//chapter 2
//code1.cpp
#if 1
//程序清单2.1 初见C++程序
//法一：使用std::前缀
#if 0
#include <iostream>
int main()
{
	std::cout << "感受一下C++程序。";
	std::cout << std::endl;
	std::cout << "你不会后悔的！" << std::endl;

	return 0;
}
#endif
//法二：使用using编译指令
#if 0
#include <iostream>
int main()
{
	using namespace std;//名称空间编译指令		声明std名称空间中的所有名称都可用
	cout << "感受一下C++程序。";
	cout << endl;
	cout << "你不会后悔的！" << endl;

	return 0;
}
#endif
//法二(改进)：使用using声明
#if 0
#include <iostream>//C++风格的头文件，包含名称空间std，定义着cout,endl
int main()
{
	using std::cout;//using声明只使所需的名称可用		使用名称空间std中的预定义对象cout，cout表示输出流，读为 "c out"即标准输出
	using std::endl;//使用名称空间std中的控制符endl

	cout << "感受一下C++程序。";
	cout << endl;
	cout << "你不会后悔的！" << endl;

	return 0;
}
#endif


//程序清单2.2 声明并使用变量，使用cout打印变量的值
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	carrots = 25;

	cout << "I have ";
	cout << carrots;
	cout << " carrots\n";

	carrots -= 1;
	cout << "吃了1根，现在我还有" << carrots << "根胡萝卜(carrots)" << endl;

	return 0;
}
#endif


//程序清单2.3 使用cin
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	cout << "您有多少根胡萝卜？ ";
	cin >> carrots;
	//写法1：
	//cout << "吃了1根，现在我还有" << carrots-1 << "根胡萝卜(carrots)" << endl;
	//写法2：(适用于长代码行)
	cout << "吃了1根，现在我还有"
		<< carrots - 1
		<< "根胡萝卜(carrots)"
		<< endl;

	return 0;
}
#endif


//程序清单2.4 调用C库中的函数
#if 0
#include <iostream>
#include <cmath>

int main(void)
{
	using namespace std;

	double area;
	cout << "请输入一个大于0的小数：";
	cin >> area;

	double side;
	side = sqrt(area);
	cout << "该数的算数平方根是";
	cout << side << endl;

	return 0;
}
#endif


//程序清单2.5 调用用户自定义的函数(1)
#if 0
#include <iostream>
void function(int);
//或写为：
//using namespace std;//这样写的话，两个函数都能访问名称空间std

int main(void)
{
	using namespace std;

	function(3);

	cout << "请输入数字：";
	int n;										//***注***变量名不能和函数名相同，否则编译器不知道应该用变量还是该调用函数
	cin >> n;									//不能在同一个函数中同时将cout用作对象名和变量名，否则编译器也会糊涂
	function(n);
	//关键字(如int return等)不能做他用
	return 0;
}
void function(int n)
{
	using namespace std;

	cout << "显示：";
	cout << n << endl;
}
#endif


//程序清单2.6 调用用户自定义的函数(2)
#if 0
#include <iostream>
int function(int);

int main(void)
{
	using namespace std;

	cout << "请输入数字：";
	int n;
	cin >> n;
	n = function(n);
	cout << "扩大2倍后，得到" << n << endl;

	return 0;
}
int function(int n)
{
	n *= 2;

	return n;//或：return n*=2;
}
#endif
#endif


//chapter 2
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//2.7编程练习
//1.
#if 0
int main(void)
{
	using std::cout;
	cout << "测试";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "请输入一个以long为单位的距离：";
	int distance;
	cin >> distance;
	cout << "哈哈，这相当于" << distance * 220 << "码";

	return 0;
}
#endif


//3.
#if 0
using namespace std;
void function1(void);
void function2(void);

int main(void)
{
	function1();
	function1();
	function2();
	function2();

	return 0;
}
void function1(void)
{
	cout << "Three blind mice" << endl;
}
void function2(void)
{
	cout << "See how they run\n";
}
#endif


//4.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter your age: ";
	int age;
	cin >> age;
	cout << "该年龄包含：" << age * 12 << "个月";

	return 0;
}
#endif



//5.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "请输入摄氏温度值：";
	double temperature;
	cin >> temperature;
	cout << temperature << "度相当于" << function(temperature) << "华氏度";

	return 0;
}
double function(double num)
{
	return num * 1.8 + 32.0;
}
#endif


//6.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "请输入光年值：";
	double light_years;
	cin >> light_years;
	cout << light_years << "光年=" << function(light_years) << "天文单位";

	return 0;
}
double function(double num)
{
	return num * 63240;
}
#endif


//7.
#if 0
using namespace std;
void function(int a, int b);

int main(void)
{
	int a, b;
	cout << "Enter the number of hours: ";
	cin >> a;
	cout << "Enter the number of minutes: ";
	cin >> b;
	function(a, b);

	return 0;
}
void function(int a, int b)
{
	cout << "Time : " << a << ":" << b;				//***注***无返回值的函数可以不使用return语句，这样函数会运行到最后一句，然后自动返回
	//return;
}
#endif
#endif


//chapter 3
//code1.cpp
#if 1
#include <iostream>
//
#if 1
#endif


//使用以下划线开头的变量名的变量会发生什么
#if 0
int main(void)
{
    using namespace std;
    int _ceshi = 1;

    cout << _ceshi << endl;           //在本系统中运行无异常

    return 0;
}
#endif


//程序清单3.1 查看类型的长度
#if 0
#include <climits>              // use limits.h for older systems
int main()
{
    using namespace std;
    int n_int = INT_MAX;        // initialize n_int to max int value
    short n_short = SHRT_MAX;   // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    // cin.get();
    return 0;
}
#endif


//C++11新增初始化变量的方式——{}方式，是一种通用初始化方式
#if 0
int main(void)
{
    using namespace std;

    int num1 = {};
    int num2{ 10 };
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}
#endif


//程序清单3.2 变量超越类型的范围限制(产生上溢或下溢)时产生的后果
#if 0
#define ZERO 0        // makes ZERO symbol for 0 value
#include <climits>  // defines INT_MAX as largest int value
int main()
{
    using namespace std;
    short sam_money = SHRT_MAX;    // initialize a variable to max value
    unsigned short sue_money = sam_money;// okay if variable sam_money already defined

    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl
        << "Add $1 to each account." << endl << "Now ";
    sam_money = sam_money + 1;
    sue_money = sue_money + 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited.\nPoor Sam!" << endl;
    sam_money = ZERO;
    sue_money = ZERO;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";
    sam_money = sam_money - 1;
    sue_money = sue_money - 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.3 三种整型字面值
#if 0
int main()
{
    using namespace std;
    int chest = 42;     // decimal integer literal
    int waist = 0x42;   // hexadecimal integer literal
    int inseam = 042;   // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    // cin.get();
    return 0;
}
#endif


//程序清单3.4 使用控制符dec、hex、oct修改cout的默认格式(即十进制)
#if 0
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;      // manipulator for changing number base
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;      // manipulator for changing number base
    cout << "inseam = " << inseam << " (octal for 42)" << endl << endl;

    inseam = 042;//以八进制形式存储
    cout << "inseam = " << inseam << " (octal for 042)" << endl;
    cout << dec;
    cout << "inseam = " << inseam << " (decimal for 042)" << endl;//以十进制形式显示

    // cin.get();
    return 0;
}
#endif


//***注***使用using编译指令时，cout不能再用作变量名；但使用std::cout时，cout还可以用作变量名
#if 0
int main(void)
{
    std::cout << "测试" << std::endl;
    int cout = 1;
    std::cout << cout << std::endl;

    return 0;
}
#endif


//程序清单3.5 使用char型变量
#if 0
int main()
{
    using namespace std;
    char ch;        // declare a char variable

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.6 使用cout.put()显示单个字符
#if 0
int main()
{
    using namespace std;
    char ch = 'M';   // assign ASCII code for M to ch
    int i = ch;          // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;          // change character code in ch
    i = ch;               // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);                                                                                                //此语句可用来替换cout<<ch
    cout << endl << ch;
    // using cout.put() to display a char constant
    cout.put('!');
    putchar('\n');

    char ch1;
    cin >> ch1;
    int cunchudezhi_ch1 = ch1;

    cout << ch1 << "ASCII的值是" << cunchudezhi_ch1 << endl;

    //打印字符常量
    cout << 'a';
    cout.put('a');

    // cin.get();
    return 0;
}
#endif


//程序清单3.7 使用转义序列
#if 0
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//使用wchar_t(宽字符类型)表示扩展字符集，使用新类型char16_t，char32_t
#if 0
int main(void)
{
    using namespace std;
    wchar_t zifu = L'P';//P是一个宽字符常量
    wcout << L"kuanzifuchuan" << endl;

    char16_t ch1 = u'q';
    char32_t ch2 = U'\U0000222B';

    return 0;
}
#endif


//程序清单3.8 float和double表示数字时在有效位数方面的差异
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point使用定点计数法

    float tub = 10.0 / 3.0;     // good to about 6 places   至少6位有效位
    double mint = 10.0 / 3.0;   // good to about 15 places   至少15位有效位
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;                     //证明float类型在该系统上能表示的有效位是前7位

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.9 float型数据运算时可能产生精度的下降
#if 0
int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;                                             //float类型在该系统上能表示的有效位是前7位，因此修改第23位对这个值没有任何影响

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.10 使用算数运算符
#if 0
int main()
{
    using namespace std;
    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;

    cout << 10 / 3 << endl;                                                           //***注***若两个操作数都是整数，则结果为商的整数部分，小数部分被丢弃
    hats = 10 / 3;//得3，再转化成float型，在3后面添加小数点和0
    cout << hats << endl;

    hats = 10.0 / 3;//得3.333333
    cout << hats << endl;

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.11 除法运算
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9 / 5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1.e7 / 9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f / 9.0f << endl;

    cout << 1.e7 / 9.0f << endl;//涉及两种类型的运算，两个值会被分别转换成两种类型的更高级别。

    // cin.get();
    return 0;
}
#endif


//程序清单3.12 求模运算符
#if 0
int main()
{
    using namespace std;
    const int Lbs_per_stn = 14;//1英石等于14磅
    int lbs;

    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;      // whole stone
    int pounds = lbs % Lbs_per_stn;     // remainder in pounds
    cout << lbs << " pounds are " << stone
        << " stone, " << pounds << " pound(s).\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.13 类型转换
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int converted to float                            整型可以转化成浮点型
    int guess = 3.9832; // float converted to int
    int debt = 7.2E12;  // ***注***result not defined in C++   情况1：小数部分丢失，情况2：原来的值可能超出目标类型的取值范围，在这种情况下，结果将是不确定的

    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    // cin.get();
    return 0;
}
#endif


//用{}方式初始化变量时的类型转换
#if 0
int main(void)
{
    using namespace std;
    //int a = {1.23};               //不允许缩窄
    //char a={128};               //不允许缩窄

    //int x = 66;
    //char a = {x};                 //编译器看来，x是个变量，其值可能很大，编译器判定为从int转换到char，不允许缩窄   (若改为char x=66，则可以)

    const int x = 66;          //***注***
    char a = { x };                 //此种情况允许，编译器认为只读变量x的值是66（可以理解为#define x 66），在char的范围内，可对a初始化      

    cout << a << endl;

    /*int x = 128;
    char a = x;
    cout << a << endl;*/              //若不使用{}方式初始化变量，则允许缩窄

    return 0;
}
#endif


//程序清单3.14 强制类型转换
#if 0
int main()
{
    using namespace std;
    int auks, bats, coots;// 海雀，蝙蝠，水鸟

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;                  //19.99+11.99=31.98则auks=31

    // these statements add values as int
    bats = (int)19.99 + (int)11.99;   // old C syntax               C语法
    coots = int(19.99) + int(11.99);  // new C++ syntax       C++新语法
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // print as char
    cout << int(ch) << endl;                               // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;        // using static_cast

   // cin.get();
    return 0;
}
#endif
#endif


//chapter 3
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//3.6复习题
//5.
#if 0
int main(void)
{
    using namespace std;

    char grade1 = 65;
    char grade2 = 'A';

    cout << grade1 << endl;
    cout << grade2 << endl;			//说明上述两个语句通用

    return 0;
}
#endif


//6.
#if 0
int main(void)
{
    using namespace std;
    cout.put(88);//法一						或写为：cout.put((char)88);
    putchar('\n');
    cout << (char)88;//法二
    putchar('\n');
    char ch = 88;
    cout << ch;//法三

    return 0;
}
#endif


//7.
#if 0
#include <climits>
//有宏定义：
//#define LONG_MAX      2147483647L										即10位有效位，double类型的变量可以表示，且没有舍入误差
//#define LLONG_MAX     9223372036854775807i64				即19位有效位，存入double类型的变量会有舍入误差

int main(void)
{
    long int a = 123456789;
    //float b = a;//警告	C4244	“初始化” : 从“long”转换到“float”，可能丢失数据	

    //double b = a;//无警告
    double b = 123456789123456789LL;//警告	C4305	“初始化” : 从“__int64”到“double”截断

    return 0;
}
#endif


//9.
#if 0
int main(void)
{
    double x1 = 1.6;
    double x2 = 2.5;

    int a;
    a = (int)x1 + (int)x2;

    int b;
    b = x1 + x2;				//或：b=(int)(x1+x2);

    std::cout << a;
    putchar('\n');
    std::cout << b;

    return 0;
}
#endif
#endif


//chapter 3
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//编程练习
//4.
#if 0
int main(void)
{
    using namespace std;

    long seconds;
    cout << "请输入秒数：";
    cin >> seconds;
    int days, hours, minutes, temp;

    temp = seconds;

    const int day_to_seconds = 86400;
    const int hour_to_seconds = 3600;
    const int minute_to_seconds = 60;

    days = seconds / day_to_seconds;
    seconds = seconds % day_to_seconds;
    hours = seconds / hour_to_seconds;
    seconds = seconds % hour_to_seconds;
    minutes = seconds / minute_to_seconds;
    seconds %= minute_to_seconds;

    cout << temp << "seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

    return 0;
}
#endif


//7.
#if 1
int main(void)
{
    using namespace std;

    cout << "请输入每百公里消耗的汽油量(升)：";
    double E_consume;
    cin >> E_consume;										//单位：(升/100公里)

    const double Seng_to_Jialun = 1.0 / 3.785;
    const double Gongli_to_Yinli = 0.6214;

    auto temp = E_consume * Seng_to_Jialun; //单位：(加仑/100公里)
    temp /= 100;//每一公里耗油(加仑)				   单位：(加仑/公里)
    temp = 1 / temp;											//单位：(公里/加仑)

    auto A_consume = temp * Gongli_to_Yinli;//单位：(英里/加仑)

    //法二：
    //double A_consume = 62.14 / (E_consume/3.785);

    cout << "相当于" << A_consume << "mpg";

    return 0;
}
#endif
#endif


//chapter 4
//code1.cpp
#if 1
#include <iostream>
//
#if 1
#endif


//程序清单4.1 使用数组
#if 0
int main()
{
    using namespace std;
    int yams[3];    // creates array with three elements
    yams[0] = 7;   // assign value to first element                                             //数组的赋值
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = { 20, 30, 5 }; // create, initialize array                            //数组的初始化                                                                                                                                                                    
// NOTE: If your C++ compiler or translator can't initialize
// this array, use static int yamcosts[3] instead of int yamcosts[3]

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n";

    char petkind[2][2] = { '\0' };
    petkind[1][0] = 'a';
    printf("%s", petkind[1]);                                                                //证明petkind数组初始化后元素都为'\0'
                                                                                                           //原因：部分初始化，编译器把其他未显式地初始化的元素均设为0
    // cin.get();                                                                                    //而ASCII码0，对应的正好是空字符。
    return 0;
}
#endif


//程序清单4.2 使用字符串数组
#if 0
#include <cstring>  // for the strlen() function
int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];                             // empty array(存的是垃圾值)
    char name2[Size] = "C++owboy";  // initialized array
    // NOTE: some implementations may require the static keyword
    // to initialize the array name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';                // set to null character
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.3 用cin获取字符数组的输入时只会读取一个单词
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.4 用cin.getline()读取一行字符输入
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);  // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.5 用cin.get()读取一行字符输入
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.get(name, ArSize);    // read string, newline
    cin.get();                                                                  //写法一

    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, ArSize).get();                                 //写法二

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.6 混合读入字符和数字
#if 0
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();//或：cin.get(ch);                  
                  //或将两个类成员函数拼接写：(cin>>year).get()                 目的是消耗掉输入缓冲区的换行符

    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}
#endif


//程序清单4.7 使用string类型的变量来存储字符串(每次读入一个单词)；string对象与字符数组之间异同
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;

    char char_arr1[20];                    // create an empty array
    char char_arr2[20] = "ceshi1"; // create an initialized array
    string str1;                                 // create an empty string object 创建一个string类型的变量str1          (创建一个string类的对象str1)
    string str2 = "ceshi2";              // create an initialized string 创建并初始化一个string类型的变量str2

    cout << "Enter a kind of feline: ";
    cin >> char_arr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;                                // use cin for input    ***注***使用类对象str1的好处是，str1的长度可根据输入自动调整
    cout << "Here are some felines:\n";
    cout << char_arr1 << " " << char_arr2 << " "
        << str1 << " " << str2         // use cout for output
        << endl;
    cout << "The third letter in " << char_arr2 << " is "
        << char_arr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
        << str2[2] << endl;              // use array notation 访问元素的方法也是用索引值

    return 0;
}
#endif


//程序清单4.8 string对象的新特性(相比于数组)
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;
    string s1{ "penguin" };//数组和string类对象均可使用列表初始化
    string s2, s3;

    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;//通过使用string类对象，可以直接用=号拷贝字符串
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";//string类对象支持C风格的初始化方式
    cout << "s2: " << s2 << endl;

    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;//通过使用string类对象，可以直接用+号拼接字符串
    cout << "s3: " << s3 << endl;
    cout << "You can append strings.\n";
    s1 += s2;//通过使用string类对象，可以直接用+=号把s2字符串附加到s1字符串
    cout << "s1 += s2 yields s1 = " << s1 << endl;
    s2 += " for a day";//S2字符串还可以为自身附加一个字符串字面量
    cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

    //cin.get();
    return 0;
}
#endif


//程序清单4.9 对比用于字符数组的技术和用于string对象的技术
#if 0
#include <string>               // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // assignment for string objects and character arrays  (assignment：赋值这里理解为拷贝)
    str1 = str2;                        // copy str2 to str1
    strcpy(charr1, charr2);     // copy charr2 to charr1

    // appending for string objects and character arrays
    str1 += " paste";             // add paste to end of str1
    strcat(charr1, " juice");   // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();         // obtain length of str1                            //格式：   类对象名.类方法
    int len2 = strlen(charr1);  // obtain length of charr1

    cout << "The string " << str1 << " contains "
        << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains "
        << len2 << " characters.\n";
    // cin.get();

    return 0;
}
#endif


//程序清单4.10 使用string类型的变量来存储字符串(每次读入一行)
#if 0                                       //对比程序清单4.7 使用string类型的变量来存储字符串(每次读入一个单词)
#include <string>                // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
        << strlen(charr) << endl;//***注***未初始化的数组的内容是未定义的(垃圾值)，strlen()检测空字符，所以空字符出现的位置是随机的
    cout << "Length of string in str before input: "
        << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length     //可参考程序清单4.4 用cin.getline()读取一行字符输入
    cout << "You entered: " << charr << endl;                //***注***cin.getline()是处理字符串数组的函数

    cout << "Enter another line of text:\n";
    getline(cin, str);          // cin now an argument; no length specifier   //getline()不是类方法
    cout << "You entered: " << str << endl;                    //***注***getline(cin,str)是处理string类对象的函数

    cout << "Length of string in charr after input: "
        << strlen(charr) << endl;
    cout << "Length of string in str after input: "
        << str.size() << endl;
    // cin.get();

    return 0;
}
#endif


//使用C++新增类型：原始字符串
#if 0
int main(void)
{
    using namespace std;

    cout << R"(不使用转义序列输出""     \n   "\n")" << endl << '\n';

    cout << "使用转义序列输出" << "\"\"   \\n  \"\\n\"\n\n";

    return 0;
}
#endif


//程序清单4.11 使用结构
#if 0
#include <string>
struct inflatable   // structure declaration 声明一个标记为inflatable的结构布局(结构模板)
{
    char name[20];
    float volume;
    double price;
};

struct ceshi
{
    std::string name;//string类对象也可以作为结构成员   前提条件：添加#include <string>；必须提供一条using编译指令，或者用std::string来引用它
    float volumn;
};

int main()
{
    using namespace std;
    inflatable guest =                              //声明并初始化一个以inflatable结构布局的结构变量
    {
        "Glorious Gloria",  // name value
        1.88,               // volume value
        29.99               // price value
    };  // guest is a structure variable of type inflatable
        // It's initialized to the indicated values
    inflatable pal                                     //C++11支持将列表初始化用于结构，且=号可不写
    {
        "Audacious Arthur",
        3.12,
        32.99
    };  // pal is a second variable of type inflatable



    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    // pal.name is the name member of the pal variable
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.12 拷贝结构
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable bouquet =
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;

    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;  // assign one structure to another 拷贝结构
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.13 使用结构数组
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2] =          // initializing an array of structs
    {
        {"Bambi", 0.5, 21.99},      // first structure in array
        {"Godzilla", 2000, 565.99}  // next structure in array
    };

    cout << "The guests " << guests[0].name << " and " << guests[1].name
        << "\nhave a combined volume of "
        << guests[0].volume + guests[1].volume << " cubic feet.\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.14 使用&运算符
#if 0
int main()
{
    using namespace std;
    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cups)
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.15 使用指针
#if 0
int main()
{
    using namespace std;
    int updates = 6;        // declare a variable
    int* p_updates;        // declare pointer to an int

    p_updates = &updates;   // assign address of int to pointer 对指针变量赋值

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.16 初始化指针
#if 0
int main()
{
    using namespace std;
    int higgens = 5;
    int* pt = &higgens;

    cout << "Value of higgens = " << higgens
        << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
        << "; Value of pt = " << pt << endl;
    // cin.get();
    return 0;
}
#endif


//C++对于指针赋值操作更加严格
#if 0
int main(void)
{
    int* pt;
    //pt = 0x00b8;     //C允许，但C++不允许  报错：不能将整数赋给指向int类型的指针
    pt = (int*)0x00b8;//C++允许，因为赋值语句两边都是整数的地址
                                  //***注***指针pt本身的类型不一定是int
    return 0;
}
#endif


//程序清单4.17 使用C++的new和delete运算符
#if 0
int main()
{
    using namespace std;

    int nights = 1001;
    int* pt = new int;         // allocate space for an int
    *pt = 1001;                 // store a value there

    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double* pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    delete(pt);
    delete(pd);

    // cin.get();
    return 0;
}
#endif


//程序清单4.18 使用动态数组并访问数组中的元素
#if 0
int main()
{
    using namespace std;

    double* p3 = new double[3]; // space for 3 doubles
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";                          //或写作：*(p3+1)

    p3 = p3 + 1;                  // increment the pointer

    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 - 1;                  // point back to beginning

    delete[] p3;                 // free the memory
    // cin.get();
    return 0;
}
#endif


//程序清单4.19 指针算术
#if 0
int main()
{
    using namespace std;

    double wages[3] = { 10000.0, 20000.0, 30000.0 };
    short stacks[3] = { 3, 2, 1 };

    // Here are two ways to get the address of an array
    double* pw = wages;     // name of an array = address
    short* ps = &stacks[0]; // or use address operator with array element

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";//使用数组的索引值访问两个元素
    cout << "stacks[0] = " << stacks[0]
        << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";//使用指针表示法访问两个元素
    cout << "*stacks = " << *stacks
        << ", *(stacks + 1) =  " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.20 创建动态字符串数组
#if 0
#include <cstring>              // declare strlen(), strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";   // animal holds bear
    const char* bird = "wren"; // bird holds address of string
    char* ps;                  // uninitialized

    cout << animal << " and ";  // display bear
    cout << bird << "\n";       // display wren
    // cout << ps << "\n";      //may display garbage, may cause a crash

    //输入字符串
    cout << "Enter a kind of animal: ";
    cin >> animal;              // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps doesn't point to allocated space

    ps = animal;                // set ps to point to string
    cout << ps << "!\n";       // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;//强制类型转换，目的是显示字符串的地址
    cout << ps << " at " << (int*)ps << endl;

    //获得字符串的副本
    ps = new char[strlen(animal) + 1];  // get new storage
    strcpy(ps, animal);         // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;                   //以上是使用C风格字符串，对比程序清单4.8和4.9，
                                                                                             //C++string类型更为简单
    delete[] ps;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.21 用new创建动态结构
#if 0
struct inflatable   // structure definition
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;

    inflatable* ps = new inflatable; // allot memory for structure
    //或：
    //struct inflatable* ps = new inflatable;

    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);            // method 1 for member access

    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;               // method 2 for member access

    cout << "Enter price: $";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;                        // method 2
    cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
    cout << "Price: $" << ps->price << endl;                        // method 1
    delete ps;                        // free memory used by structure
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.22 使用new和delete来存储通过键盘输入的字符串(使用动态分配的内存的应用)
#if 0
#include <cstring>      // or string.h

using namespace std;
char* getname(void);   // function prototype

int main()
{
    char* name;        // create pointer but no storage

    name = getname();   // assign address of string to name

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed

    name = getname();   // reuse freed memory

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed again
    // cin.get();
    // cin.get();
    return 0;
}

//***注***动态分配内存以高效地使用内存
char* getname()        // return pointer to new string
{
    char temp[80];      // temporary storage 块作用域，无链接，自动存储期

    cout << "Enter last name: ";
    cin >> temp;        //temp数组暂存输入的内容

    char* pn = new char[strlen(temp) + 1];//计算输入的字符数量并动态分配一个内存空间

    strcpy(pn, temp); // copy string into smaller space 
                                 //***注***strcpy()检测到temp中的'\0'后把'\0'也拷贝入pn指向的内存空间的相应位置，然后停止拷贝
    return pn;          // temp lost when function ends
}
#endif


//程序清单4.23 使用数组、结构、指针
#if 0
struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc. */
};

int main()
{
    //------------------------------------------------------------------------------
    antarctica_years_end jiegou_shuzu[3]; //声明一个数组，内含三个结构

    jiegou_shuzu[0].year = 2003;

    std::cout << jiegou_shuzu->year << std::endl;
    //------------------------------------------------------------------------------

    antarctica_years_end jiegou01, jiegou02, jiegou03;//声明三个结构

    jiegou01.year = 1998;

    antarctica_years_end* p = &jiegou02;//声明并初始化一个指向结构的指针
    p->year = 1999;


    const antarctica_years_end* zhizhen_shuzu[3] = \
    { &jiegou01, & jiegou02, & jiegou03 };//声明一个数组，内含三个指针

    std::cout << zhizhen_shuzu[1]->year << std::endl;
    //------------------------------------------------------------------------------

    const antarctica_years_end** p_zhizhen_shuzu_1 \
        = zhizhen_shuzu;//声明并初始化一个指向指针的指针

    auto p_zhizhen_shuzu_2 = zhizhen_shuzu; //***注***C++11的auto可以为声明一个类型提供方便
                                                                           //编译器知道zhizhen_shuzu的类型，所以能够推断出p_zhizhen_shuzu_2的类型
    //也可以声明为 const antarctica_years_end ** p_zhizhen_shuzu_2 = zhizhen_shuzu; 

    std::cout << (*p_zhizhen_shuzu_1)->year << std::endl;
    std::cout << (*(p_zhizhen_shuzu_2 + 1))->year << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单4.25 比较数组、vector对象、array对象
#if 0
#include <vector>   // STL(Standard Template Library，STL) C++98
#include <array>    // C++0x
int main()
{
    using namespace std;
    //------------------------------------------------------------------------------

    // C, original C++
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    //------------------------------------------------------------------------------

    // C++98 STL
    vector<double> a2(4);   // create vector with 4 elements
    //vector<double> a2(4) = { 1.0 / 3.0 , 1.0 / 5.0 , 1.0 / 7.0 , 1.0 / 9.0 }; 
                                                //不能将列表初始化用于vector对象(C++11可以这样做)
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    //vector<double> a5(4);
    //a5 = a2;                              //可以将一个vector对象赋给另一个vector对象
    //------------------------------------------------------------------------------

    // C++11-- create and initialize array object
    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };//能将列表初始化用于array对象
    array<double, 4> a4;
    a4 = a3;                                //可以将一个array对象赋给另一个array对象
    //------------------------------------------------------------------------------

    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    //  cin.get();
    return 0;
}
#endif
#endif


//chapter 4
//code2.cpp
#if 0
#include <iostream>
#include <vector>//STL vector类
#include <array>//STL array类
#include <string>//string类
//
#if 1
#endif


//4.12复习题
//1.
#if 0
int main(void)
{
    char actor[30];
    short betsie[100];
    float chuck[13];
    long double dipsea[64];

    return 0;
}
#endif


//2.
#if 0
int main(void)
{
    using namespace std;

    array<char, 30>actor;
    array<short, 100>betsie;
    array<float, 13>chuck;
    array<long double, 64>dipsea;

    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    int shuju[5] = { 1,3,5,7,9 };

    return 0;
}
#endif


//4.
#if 0
int main(void)
{
    int shuju[5] = { 1,3,5,7,9 };
    int even;
    even = shuju[0] + shuju[4];
    //或：even = *(shuju)+ *(shuju+4);

    return 0;
}
#endif


//5.~7.
#if 0
int main(void)
{
    float ideas[10]{ 1,2 };
    std::cout << ideas[1];

    char shuju[20] = "cheeseburger";//或：char shuju[]="cheeseburger";
    std::string str = "Waldorf Salad";

    return 0;
}
#endif


//8.~9.
#if 0
struct fish
{
    char pinzhong[20];
    int weight;
    double length;
};

int main(void)
{
    struct fish fish_canshu = { "鲈鱼",1,2.2 };

    return 0;
}
#endif


//10.
#if 0
enum Response { No, Yes, Maybe };
#endif


//11.
#if 0
int main(void)
{
    double ted = 1.1;
    double* p = &ted;

    std::cout << *p;

    return 0;
}
#endif


//12.
#if 0
int main(void)
{
    float treacle[10] = { 1.0,2.0,3.0 };
    treacle[9] = 10.0;

    float* p = treacle;

    std::cout << *(p) << std::endl;
    std::cout << *(p + 9) << std::endl;

    return 0;
}
#endif


//13.
#if 0
int main(void)
{
    using namespace std;
    cout << "请输入要写入的整数数量：";
    int num;
    cin >> num;

    int* p = new int[num];
    //或：
    //vector<int>p(num);

    delete[]p;

    return 0;
}
#endif


//15.
#if 0
struct fish
{
    char pinzhong[20];
    int weight;
    double length;
};

int main(void)
{
    using namespace std;

    //struct fish fish_canshu = { "鲈鱼",1,2.2 };
    //struct fish* p1 = &fish_canshu;

    struct fish* p = new fish;
    //或：fish* p = new fish;
    cin >> p->pinzhong;
    cin >> p->weight;
    cin >> p->length;

    cout << p->pinzhong << endl;
    cout << p->weight << endl;
    cout << p->length << endl;

    return 0;
}
#endif


//17.
#if 0
int main(void)
{
    const int num = 10;//理解成	#define		num		 (10)
    std::vector<std::string>a_array(num);
    std::array<std::string, num>b_array;

    return 0;
}
#endif
#endif


//chapter 4
//code3.cpp
#if 0
#include <iostream>
#include <vector>//STL vector类
#include <array>//STL array类
#include <string>//string类
#include <cstring>//strcat()
//
#if 1
#endif


//4.13编程练习
//1.
#if 0
int main(void)
{
    using namespace std;
    const int SIZE = 20;

    cout << "What is your first name ? ";
    char f_name[SIZE];
    cin.getline(f_name, SIZE);

    cout << "What is your last name ? ";
    char l_name[SIZE];
    cin.getline(l_name, SIZE);

    cout << "What letter grade do you deserve ? ";
    char grade;
    cin >> grade;

    cout << "What is your age ? ";
    int age;
    cin >> age;

    cout << "Name :" << l_name << ", " << f_name << endl;
    cout << "Grade :" << char(grade + 1) << endl;//***注***grade+1，使结果数字的类型升级成int，要用强制类型转换，变成char
    cout << "Age :" << age << endl;						//cout才能打印字符

    return 0;
}
#endif


//2.
#if 0
int main()
{
    using namespace std;

    const int ArSize = 20;
    string name;
    string dessert;

    cout << "Enter your name:\n";
    getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter your first name : ";
    char f_name[20];
    cin.getline(f_name, 20);
    cout << "Enter your last name : ";
    char l_name[60];
    cin.getline(l_name, 20);

    char temp[3] = ", ";
    strcat(l_name, temp);
    strcat(l_name, f_name);

    cout << "Here's the information in a single string : ";
    cout << l_name;

    return 0;
}
#endif


//4.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter your first name : ";
    string f_name;
    getline(cin, f_name);
    cout << "Enter your last name : ";
    string l_name;
    getline(cin, l_name);

    string temp = ", ";
    l_name += temp;
    l_name += f_name;

    cout << "Here's the information in a single string : ";
    cout << l_name;

    return 0;
}
#endif


//5.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;
    CandyBar snack{ "Mocha Munch",2.3,350 };

    cout << snack.brand << endl;
    cout << snack.weight << endl;
    cout << snack.calorie << endl;

    return 0;
}
#endif


//6.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;
    CandyBar snack[3]{
    {"Mocha Munch", 2.3, 350} ,
     {"Aaa Bbb", 2.3, 350} ,
     {"Ccc Ddd", 2.3, 350} };

    for (int i = 0; i < 3; i++)
    {
        cout << snack[i].brand << endl;
        cout << snack[i].weight << endl;
        cout << (snack + i)->calorie << endl;
    }

    return 0;
}
#endif


//7.
#if 0
const int SIZE = 20;

struct pizza
{
    char company[SIZE];
    double diameter;
    double weight;
};

int main(void)
{
    using namespace std;

    struct pizza xinxi;

    cout << "请输入披萨饼公司的名称：";
    cin.getline(xinxi.company, SIZE);
    cout << "请输入披萨饼的直径：";
    cin >> xinxi.diameter;
    cout << "请输入披萨饼的重量：";
    cin >> xinxi.weight;

    cout << xinxi.company << endl;
    cout << xinxi.diameter << endl;
    cout << xinxi.weight << endl;

    return 0;
}
#endif


//8.
#if 0
const int SIZE = 20;

struct pizza
{
    char company[SIZE];
    double diameter;
    double weight;
};

int main(void)
{
    using namespace std;

    struct pizza* p = new pizza;

    cout << "请输入披萨饼的直径：";
    cin >> p->diameter;
    cin.get();

    cout << "请输入披萨饼公司的名称：";
    cin.getline(p->company, SIZE);

    cout << "请输入披萨饼的重量：";
    cin >> p->weight;

    cout << p->company << endl;
    cout << p->diameter << endl;
    cout << p->weight << endl;

    delete p;

    return 0;
}
#endif


//9.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;

    CandyBar* p = new CandyBar[3];
    *p = { "Mocha Munch", 2.3, 350 };
    *(p + 1) = { "Aaa Bbb", 2.3, 350 };
    *(p + 2) = { "Ccc Ddd", 2.3, 350 };

    for (int i = 0; i < 3; i++)
    {
        cout << p[i].brand << endl;
        cout << p[i].weight << endl;
        cout << (p + i)->calorie << endl;
        //或
        //cout << (* (p + i)).calorie << endl;
    }
    delete[]p;

    return 0;
}
#endif


//10.
#if 0
int main(void)
{
    using namespace std;
    const int cishu = 3;

    array<double, cishu>chengji;

    cout << "请输入3次40米跑的成绩：";
    cin >> chengji[0];
    cin >> chengji[1];
    cin >> chengji[2];//每输入一个成绩就换行，或每输入一个成绩就用空格分开，均能正常运行

    cout << cishu << "次跑步的平均成绩是：" << (chengji[0] + chengji[1] + chengji[2]) / 3;

    return 0;
}
#endif
#endif


//chapter 5
//code1.cpp
#if 0
#include <iostream>
#include <string>//string 类
#include <cstring>// prototype for strcmp()
//
#if 1
#endif


//程序清单5.3 注意运算符优先级
#if 0
int main()
{
    using namespace std;
    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout.setf(ios_base::boolalpha);   //a newer C++ feature

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    /// cin.get();
    return 0;
}                                                           //口诀：算数移位关系，按位逻辑赋值
#endif


//程序清单5.4 用for循环实现阶乘(for循环与数组协同工作)
#if 0
const int ArSize = 16;      // example of external declaration
int main()
{
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;//0!=1，1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单5.5 修改步长
#if 0
int main()
{
    using std::cout;    // a using declaration
    using std::cin;
    using std::endl;

    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.6 用for循环访问字符串
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // display letters in reverse order
    for (int i = word.size() - 1; i >= 0; i--)
        cout << word[i];

    cout << "\nBye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.9 将数组中字符顺序反转
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // physically modify string object
    char temp;

    //法一：
    //for (int i = 0, j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //法二：
    int i, j;
    for (i = 0, j = word.size() - 1; i < j; ++i, --j)
    {                       // start block
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }                       // end block

    //***注***
    //for (int i = 0, int j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //报错：j未声明，原因：书P116

    cout << word << "\nDone\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.10 注意=与==运算符的区别
#if 0
int main()
{
    using namespace std;
    int quizscores[10] =
    { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is a 20\n";

    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++)
        cout << "quiz " << i << " is a 20\n";

    // cin.get();
    return 0;
}
#endif


//程序清单5.11 for循环和strcmp()协同工作(使用的是C风格字符串)
#if 0
int main()
{
    using namespace std;
    char word[5] = "?ate";

    for (char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单5.12 for循环和string类字符串的特性协同工作(使用的是string类字符串)
#if 0
int main()
{
    using namespace std;
    string word = "?ate";

    for (char ch = 'a'; word != "mate"; ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单5.13 while循环
#if 0
const int ArSize = 20;
int main()
{
    using namespace std;
    char name[ArSize];

    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;                  // start at beginning of string
    while (name[i] != '\0')     // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif
//程序清单5.13 while循环(使用string类)
#if 0
const int ArSize = 20;
int main()
{
    using namespace std;
    string name;

    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;                  // start at beginning of string
    while (name[i] != '\0')     // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.14 编写延时循环，使用wait或使用clock()
#if 0
#include <ctime> // describes clock() function, clock_t type

int main()
{
    //方法1：
    long wait = 0;
    while (wait < 1000000000)
        wait++;


    //方法2：
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    //CLOCKS_PER_SEC：每秒钟包含的系统时间单位数
    clock_t delay = secs * CLOCKS_PER_SEC;  // convert to clock ticks
                                                                          //将秒为单位的数转化为系统时间单位为单位的数
    cout << "starting\a\n";
    clock_t start = clock();

    while (clock() - start < delay)        // wait until time elapses
        ;                                   // note the semicolon

    cout << "done \a\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.15 do...while循环
#if 0
int main()
{
    using namespace std;
    int n;

    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do
    {
        cin >> n;       // execute body
    } while (n != 7);   // then test
    //或：
    //for (;;)
    //{
    //    cin >> n;
    //    if (n == 7)
    //        break;
    //}

    cout << "Yes, 7 is my favorite.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//基于范围的for循环(C++11)
#if 0
int main(void)
{
    //依次显示数组的元素
    double prices[5] = { 4.99,10.99,6.87,7.99,8.49 };
    for (double x : prices)
        std::cout << x << std::endl;

    putchar('\n');

    //依次修改数组的元素，并显示出来
    for (double& x : prices)
        x = x * 0.8;
    for (double x : prices)
        std::cout << x << std::endl;

    return 0;
}
#endif


//程序清单5.16 读取来自键盘的文本输入，利用哨兵字符'#' (cin不读入空白字符)
#if 0
int main()
{
    using namespace std;
    char ch;
    int count = 0;      // use basic input

    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;          // get a character

    while (ch != '#')   // test the character
    {
        cout << ch;     // echo the character
        ++count;        // count the character
        cin >> ch;      // get the next character
    }

    cout << endl << count << " characters read\n";
    // get rid of rest of line
         // while (cin.get() != '\n')
            // ;
    //cin.get();
    return 0;
}
#endif


//程序清单5.17 读取来自键盘的文本输入，利用哨兵字符'#' (cin.get()会读入空格字符)
#if 0
int main()
{
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);        // use the cin.get(ch) function

    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);    // use it again
    }

    cout << endl << count << " characters read\n";
    // get rid of rest of line
        // while (cin.get() != '\n')
        //    ;
        //cin.get();
    return 0;
}
#endif


//程序清单5.18 读取来自键盘或文件的文本输入，通过cin的fail()来表示检测到EOF
#if 0
int main()
{
    using namespace std;

    char ch;
    int count = 0;

    cin.get(ch);        // attempt to read a char

    while (cin.fail() == false)  // test for EOF
    {
        cout << ch;     // echo character
        ++count;
        cin.get(ch);    // attempt to read another char
    }

    cout << endl << count << " characters read\n";

    return 0;
}
//***注***
//可以键盘输入^Z来模拟EOF让程序停止运行，也可以直接在命令行环境用<让程序读入一个文件
//命令行环境下输入cd D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 5\code1\Project1\x64\Debug
//再输入Project1.exe<5.18.txt
#endif


//读取来自键盘或文件的文本输入，通过C++的istream和ostream类中
//类似C语言的getchar()和putchar()功能的成员函数来检测EOF
#if 0
int main()
{
    using namespace std;

    char ch;
    int count = 0;

    ch = cin.get();

    while (ch != EOF)
    {
        cout.put(ch);

        if (ch != '\n')
            ++count;

        ch = cin.get();
    }
    //或：
    //while ((ch=cin.get()) != EOF)
    //{
    //    cout.put(ch);

    //    if (ch != '\n')
    //        ++count;
    //}

    cout << endl << count << " characters read\n";

    return 0;
}
//***注***此系统的char默认为有符号char，所以可以存EOF代表的-1，把ch声明为char没问题，
// 否则，要声明为int ch并且改为cout.put(char(ch))
#endif


//程序清单5.20 声明并初始化二维数组，显示二维数组的内容
#if 0
const int Cities = 5;
const int Years = 4;

int main()
{
    using namespace std;
    const char* cities[Cities] =   // array of pointers
    {                               // to 5 strings
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    //或法二：
    //const char cities[Cities][25] =   // array of pointers
    //{                               // to 5 strings
    //    "Gribble City",
    //    "Gribbletown",
    //    "New Gribble",
    //    "San Gribble",
    //    "Gribble Vista"
    //};
    //或法三：
    //const string cities[Cities] =   // array of pointers
    //{                               // to 5 strings
    //    "Gribble City",
    //    "Gribbletown",
    //    "New Gribble",
    //    "San Gribble",
    //    "Gribble Vista"
    //};

    int maxtemps[Years][Cities] =   // 2-D array
    {
        {96, 100, 87, 101, 105},   // values for maxtemps[0]
        {96, 98, 91, 107, 104},   // values for maxtemps[1]
        {97, 101, 93, 108, 107}, // values for maxtemps[2]
        {98, 103, 95, 109, 108}   // values for maxtemps[3]
    };

    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";

        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";

        cout << endl;
    }
    // cin.get();
    return 0;
}
#endif
#endif


//chapter 5
//code2.cpp
#if 0
#include <iostream>
//5.8复习题
//6.
#if 1
int main(void)
{
    for (int i = 1; i <= 64; i *= 2)
        std::cout << i << '\t';

    return 0;
}
#endif
#endif


//chapter 5
//code3.cpp
#if 0
#include <iostream>
#include <array>
#include <string>
#include <cstring>//strcmp()
//
#if 1
#endif


//5.9编程练习
//1.
#if 0
int main(void)
{
    using namespace std;
    cout << "请输入两个整数：";

    int start, end;
    cin >> start;
    cin >> end;

    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += i;

    cout << start << "~" << end << "之间所有整数的和为" << sum;

    return 0;
}
#endif


//2.
#if 0
const int ArSize = 100;      // example of external declaration

int main()
{
    std::array<long double, ArSize>factorials;

    factorials[1] = factorials[0] = 1.0L;//0!=1，1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    using namespace std;

    cout << "请输入数字：";
    int num, sum = 0;

    while (1)
    {
        cin >> num;
        sum += num;

        if (num != 0)
        {
            cout << "所有输入的累计和为" << sum << endl;
            cout << "请输入数字：";
        }
        else
            break;
    }
    //法二：
    /*do
    {
        cin >> num;
        sum += sum;
    } while (num!=0);
    cout << "所有输入的累计和为" << sum << endl;*/
    return 0;
}
#endif


//4.
#if 0
//#define JUST_CHECKING
int main(void)
{
    using namespace std;

    double benjin_dap = 100.0, benjin_cle = 100.0;
    const double lilv_dap = 0.1;
    const double lilv_cle = 0.05;

    double lixi_dap, lixi_cle;

    double money_dap = benjin_dap;
    double money_cle = benjin_cle;
    int years = 0;

    do
    {
        years++;

        lixi_dap = lilv_dap * benjin_dap;
        money_dap += lixi_dap;

#ifdef JUST_CHECKING//条件编译
        cout << "第" << years << "年：" << "Daphne " << money_dap << "\t";
#endif

        lixi_cle = lilv_cle * money_cle;
        money_cle += lixi_cle;
#ifdef JUST_CHECKING
        cout << "第" << years << "年：" << "Cleo " << money_cle << endl;
#endif

    } while (money_cle <= money_dap);

    cout << "第" << years << "年：" << "Daphne " << money_dap << "\t";
    cout << "Cleo " << money_cle << endl;

    return 0;
}
#endif


//5.
#if 0
int main(void)
{
    using namespace std;

    int xiaoshouliang[12];
    //错误：“const char *“ 类型的值不能用于初始化 “char *“ 类型的实体
    //char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
    //***注***正确写法：
    const char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
    //写法二：
    //const string yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };

    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << "请输入" << yuefen[i] << "的销售量：";
        cin >> xiaoshouliang[i];
        sum += xiaoshouliang[i];
    }

    cout << "这一年销售量为" << sum << "本" << endl;

    return 0;
}
#endif


//6.
#if 0
int main(void)
{
    using namespace std;

    int xiaoshouliang[3][12];
    //错误：“const char *“ 类型的值不能用于初始化 “char *“ 类型的实体
    //char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
    //***注***正确写法：
    const char* nianfen[3] = { "1999年","2000年","2001年" };
    const char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
    //写法二：
    //const string yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };

    int sum[3 + 1] = {};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        cout << nianfen[i] << "：" << endl;

        for (j = 0; j < 12; j++)
        {
            cout << "请输入" << yuefen[j] << "的销售量：";
            cin >> xiaoshouliang[i][j];
            sum[i] += xiaoshouliang[i][j];
        }
    }

    cout.put('\n');
    for (int i = 0; i < 3; i++)
    {
        cout << nianfen[i] << "销售量为" << sum[i] << "本" << endl;
        sum[3] += sum[i];
    }
    cout << "总销售量为" << sum[3] << "本" << endl;

    return 0;
}
#endif


//7.
#if 0
struct car
{
    std::string manufacturer;
    int year;
};

int main(void)
{
    using namespace std;

    cout << "How many cars do you wish to catalog ?";
    int num;
    cin >> num;
    cin.get();//消耗掉换行符

    struct car* p_car = new car[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << "：" << endl;
        cout << "Please enter the make :";
        getline(cin, (p_car + i)->manufacturer);
        cout << "Please enter the year made :";
        cin >> (p_car + i)->year;
        cin.get();
    }

    if (num != 0)
    {
        cout << "Here is your collection :" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << (p_car + i)->year << " ";
            cout << (p_car + i)->manufacturer << endl;
        }
    }
    else
        cout << "No data entered !";

    delete[]p_car;

    return 0;
}
#endif


//8.
#if 0
int main(void)
{
    using namespace std;
    cout << "Enter words (to stop, type the word done) :" << endl;
    char shuju[20];
    int count = 0;

    /*do
    {
        cin >> shuju;
        ++count;
    } while (strcmp(shuju, "done"));
    count -= 1;*/

    /*shuju[0] =0;
    for (; strcmp(shuju, "done"); ++count)
    {
        cin >> shuju;
    }
    count -= 1;*/

    while (1)
    {
        cin >> shuju;
        if (strcmp(shuju, "done"))
            ++count;
        else
            break;
    }

    cout << "You entered a total of " << count << " words";

    return 0;
}
#endif


//9.
#if 0
int main(void)
{
    using namespace std;
    cout << "Enter words (to stop, type the word done) :" << endl;
    string shuju;
    int count = 0;

    while (1)
    {
        cin >> shuju;
        if (shuju != "done")
            ++count;
        else
            break;
    }

    cout << "You entered a total of " << count << " words";

    return 0;
}
#endif


//10.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter number of rows : ";
    int num;
    cin >> num;//***注***在输入缓冲区中还有'\n'

    int i, j, k;
    for (i = 1; i <= num; i++)//行号
    {
        for (j = 1; j <= num - i; j++)
            cout << ". ";
        for (k = 1; k <= i; k++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}
#endif
#endif


//chapter 6
//code1.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//程序清单6.1 循环与分支语句配合使用
#if 0
int main()
{
    using std::cin;     // using declarations
    using std::cout;

    char ch;
    int spaces = 0;
    int total = 0;

    cin.get(ch);
    while (ch != '.')   // quit at end of sentence
    {
        if (ch == ' ')  // check if ch is a space
            ++spaces;

        ++total;        // done every time
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.2 分支语句：if...else...语句
#if 0
int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";

    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;        // done if newline
        else
            std::cout << ++ch;   // done otherwise

        std::cin.get(ch);
    }
    // try ch + 1 instead of ++ch for interesting effect
    //***细节比较***
    //++ch后ch类型仍为char
    //ch+1后ch类型升级为int

    std::cout << "\nPlease excuse the slight confusion.\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}
#endif


//程序清单6.3 if...else...if...else结构
#if 0
const int Fave = 27;

int main()
{
    using namespace std;
    int n;

    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: ";

    do
    {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again: ";
        else if (n > Fave)
            cout << "Too high -- guess again: ";
        else
            cout << Fave << " is right!\n";

    } while (n != Fave);
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.4 cin只读取一个字符，并用 if...else...if...else结构，||逻辑运算符
#if 0
int main()
{
    using namespace std;
    cout << "This program may reformat your hard disk\n"
        "and destroy all your data.\n"
        "Do you wish to continue? <y/n> ";//利用字符串的拼接特性

    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')             // y or Y
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')        // n or N
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
        "can't follow\ninstructions, so "
        "I'll trash your disk anyway.\a\a\a\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.5 循环、&&逻辑运算符、分支运算符的应用
#if 0
const int ArSize = 6;
int main()
{
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients) "
        << "of\nyour neighbors. Program terminates "
        << "when you make\n" << ArSize << " entries "
        << "or enter a negative value.\n";

    int i = 0;
    float temp;

    cout << "First value: ";
    cin >> temp;

    while (i < ArSize && temp >= 0) // 2 quitting criteria
    {
        naaq[i] = temp;
        ++i;// i可以指示输入了多少个值

        if (i < ArSize)             // room left in the array,
        {
            cout << "Next value: ";
            cin >> temp;            // so get next value
        }
    }

    if (i == 0)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";

        float you;
        cin >> you;

        int count = 0;

        for (int j = 0; j < i; j++)
            if (naaq[j] > you)
                ++count;

        cout << count;
        cout << " of your neighbors have greater awareness of\n"
            << "the New Age than you do.\n";
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.6 使用一系列 if...else...if...else结构
#if 0
const char* qualify[4] =       // an array of pointers*/
{                               // to strings
    "10,000-meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festival.\n"
};

int main()
{
    using namespace std;

    int age;
    cout << "Enter your age in years: ";
    cin >> age;

    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "You qualify for the " << qualify[index];
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.7 !逻辑运算符
#if 0
#include <climits>

bool is_int(double);

int main()
{
    using namespace std;
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))    // continue while num is not int-able
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }

    int val = int(num);    // type cast
    cout << "You've entered the integer " << val << "\nBye\n";
    // cin.get();
    // cin.get();
    return 0;
}

bool is_int(double x)//double 类型足以存储典型的int值，然后对输入的值进行逻辑判断
{
    if (x <= INT_MAX && x >= INT_MIN)   // use climits values
        return true;
    else
        return false;
}
#endif


//程序清单6.8 使用头文件cctype中提供的函数
#if 0
#include <cctype>              // prototypes for character functions

int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
        " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);                // get first character
    while (ch != '@')            // test for sentinel
    {
        if (isalpha(ch))         // is it an alphabetic character?
            chars++;
        else if (isspace(ch))    // is it a whitespace character?
            whitespace++;
        else if (isdigit(ch))    // is it a digit?
            digits++;
        else if (ispunct(ch))    // is it punctuation?
            punct++;
        else
            others++;
        cin.get(ch);            // get next character
    }

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.9 条件运算符:?
#if 0
int main()
{
    using namespace std;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "The larger of " << a << " and " << b;

    int c = a > b ? a : b;   // c = a if a > b, else c = b

    cout << " is " << c << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.10 switch语句
#if 0
using namespace std;

void showmenu();   // function prototypes
void report();
void comfort();

int main()
{
    showmenu();

    int choice;
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:   cout << "\a\n";
            break;
        case 2:   report();
            break;
        case 3:   cout << "The boss was in all day.\n";
            break;
        case 4:   comfort();
            break;
        default:   cout << "That's not a choice.\n";
        }

        showmenu();
        cin >> choice;
    }
    //***注***
    //若输入字母，则会一直执行default标签对应的功能。

    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
        "1) alarm           2) report\n"
        "3) alibi           4) comfort\n"
        "5) quit\n";
}
void report()
{
    cout << "It's been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think\n"
        "you are the finest CEO in the industry.\n";
}
#endif


//程序清单6.11 将枚举量用作标签
#if 0
// create named constants for 0 - 6
enum { red, orange, yellow, green, blue, violet, indigo };
//只使用符号常量对应的枚举量，而不使用枚举类型的变量，则可以省略枚举类型的名称

int main()
{
    using namespace std;

    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;

    while (code >= red && code <= indigo)
    {
        switch (code)
        {
        case red: cout << "Her lips were red.\n"; break;
        case orange: cout << "Her hair was orange.\n"; break;
        case yellow: cout << "Her shoes were yellow.\n"; break;
        case green: cout << "Her nails were green.\n"; break;
        case blue: cout << "Her sweatsuit was blue.\n"; break;
        case violet: cout << "Her eyes were violet.\n"; break;
        case indigo: cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.12 continue语句，break语句
#if 0
const int ArSize = 80;

int main()
{
    using namespace std;

    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);

    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";

    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];    // display character

        if (line[i] == '.') // quit if it's a period
            break;
        if (line[i] != ' ') // skip rest of loop
            continue;

        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.13 读取数字的循环(当输入了非规定的数据时结束循环)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
        << " fish <q to terminate>.\n";
    cout << "fish #1: ";

    int i = 0;                                                      // i 是数组的索引值
    while (i < Max && cin >> fish[i]) {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
    //退出循环后 i 的值相当于数组的元素数量
// calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];

    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
        << i << " fish\n";

    cout << "Done.\n";
    // code to keep VC execution window open if q is entered
    //	if (!cin)  // input terminated by non-numeric response
    //	{
    //	    cin.clear();  // reset input
    //	    cin.get();    // read q
    //	}
    //	cin.get();    // read end of line after last input
    //	cin.get();    // wait for user to press <Enter>
    return 0;
}
#endif


//程序清单6.14 读取数字的循环(当输入了非规定的数据时继续读取输入)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";

    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i + 1 << ": ";

        while (!(cin >> golf[i]))//输入非规定的数据时cin返回false
        {
            cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

            while (cin.get() != '\n')
                continue;    //消耗掉错误的输入

            cout << "Please enter a number: ";//提示用户再输入
        }

    }

    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    // report results
    cout << total / Max << " = average score "
        << Max << " rounds\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.15 向文件输入内容
#if 0
#include <fstream>                  // for file I/O        
                                                    //1.包含头文件fstream(其中定义了ofstream类)
int main()
{
    using namespace std;

    ofstream outFile;                    // create object for output
                                                     //2.声明一个ofstream对象                                                   
    outFile.open("carinfo.txt");    // associate with a file
                                                     //3.将该对象与一个文件关联起来
    cout << "Enter the make and model of automobile: ";
    char automobile[50];
    cin.getline(automobile, 50);

    cout << "Enter the model year: ";
    int year;
    cin >> year;

    cout << "Enter the original asking price: ";
    double a_price;
    cin >> a_price;
    double d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using outFile instead of cout
    //4.像使用cout那样使用该ofstream对象
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    //5.使用完文件后，用close()将其关闭
    outFile.close();                // done with file

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.16 读取文件内容
#if 0
#include <fstream>                  // file I/O support
                                                    //1.包含头文件fstream(其中定义了ifstream类)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main()
{
    using namespace std;

    ifstream inFile;                       // object for handling file input
                                                    //2.声明一个ifstream对象                                                   
    cout << "Enter name of data file: ";
    char filename[SIZE];
    cin.getline(filename, SIZE);

    inFile.open(filename);           // associate inFile with a file
                                                    //3.将该对象与一个文件关联起来

    //检查文件是否被成功打开
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;                         // number of items read

    inFile >> value;                     // get first value
                                                   //4.像使用cin那样使用该ifstream对象

    while (inFile.good())   // while input good and not at EOF
    {
        ++count;                // one more item read
        sum += value;       // calculate running total
        inFile >> value;     // get next value
    }

    //或写为：
    /*while (inFile >> value)   //inFile >> value返回inFile，执行bool转换后为true或false
    {
        ++count;
        sum += value;
    }*/

    //确定循环终止的原因
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else//inFile.bad()为true
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    //5.使用完文件后，用close()将其关闭
    inFile.close();         // finished with the file
    // cin.get();
    return 0;
}
//***注***
//不使用命令行环境也能顺利读取文件
//scores.txt
#endif
#endif


//chapter 6
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//6.10复习题
//3.
#if 0
using namespace std;
int main()
{
    char ch;
    int ct1, ct2;

    ct1 = ct2 = 0;
    while ((ch = cin.get()) != '$')
    {
        cout << ch;
        ct1++;
        if (ch = '$')
            ct2++;
        cout << ch;
    }
    cout << "ct1= " << ct1 << ", ct2=" << ct2 << endl;

    return 0;
}
/*输入：
Hi!
Send $10 or $20 now!
*/
#endif


//4.
#if 0
weight >= 115 && weight < 125
    ch == 'q' || ch == 'Q'
    x % 2 == 0 && x != 26
    x % 2 == 0 && x % 26 != 0
    (donation >= 1000 && donation <= 2000) || guest == 1
    (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
#endif


    //6.
#if 0
    x>0 ? x : -x
#endif


    //7.
#if 0
    switch (ch)
    {
    case 'A':
        a_grade++;
        break;
    case 'B':
        b_grade++;
        break;
    case 'C':
        c_grade++;
        break;
    case 'D':
        d_grade++;
        break;
    default:
        f_grade++;
    }
#endif


//9.
#if 0
int main(void)
{
    using namespace std;

    int line = 0;
    char ch;
    while (cin.get(ch) && ch != 'Q')
    {
        if (ch == '\n')
            line++;

        //cout << ch;
    }
}
#endif
#endif


//chapter 6
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//6.11编程练习
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
            cout.put(toupper(ch));//***注***若写为cout<<toupper(ch);则打印的是字符对应的ASCII值
        else if (isupper(ch))
            cout.put(tolower(ch));
        else
            cout << ch;
    }
    cout << "再见！";

    return 0;
}
#endif


//2.
#if 0
int main(void)
{
    using namespace std;
    cout << "请输入最多10个值" << endl;

    double donation[10];
    int index = 0;
    double sum = 0.0;

    while (index<10 && cin >> donation[index])//输入非数字时cin返回false
    {
        ++index;
        sum += donation[index - 1];
    }
    //index退出循环后，代表元素个数

    double average = sum / index;
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        if (donation[i] > average)
            count++;
    }

    cout << "输入了" << index << "个数字" << endl;
    cout << "平均值：" << average << endl;
    cout << "数组中有" << count << "个数字大于平均值" << endl;

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
    cout << "Please enter one of the following choices :" << endl;
    cout << "c) carnivore p) pianist" << endl;
    cout << "t) tree g)game" << endl;
}
char get_choice(void)
{
    char ch;

    /*老方法：
    while(ch!='c'&&ch!='p'&&ch!='t'&&ch!='g')
    {
            cin.get();
            cout << "请输入c、p、t或g : " ;
            cin.get(ch);
    }
    */

    while (cin.get(ch))
    {
        while (cin.get() != '\n')
            continue;
        ch = tolower(ch);

        if (strchr("cptg", ch) == NULL)
            cout << "请输入c、p、t或g : ";
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
void display_by_name(struct bop* p_BopStructure);
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
    //***注***C99和C11为结构提供了指定初始化器（designated initializer）1，其语法与数组的指定初始化器类似。
    //但是，结构的指定初始化器使用点运算符和成员名（而不是方括号和下标）标识特定的元素。
    //但是，C++不支持。
    struct bop BopStructure[5] = {
        {"Wimp Macho","Programmer","MIPS",0},
        {"Raki Rhodes", "Junior Programmer","\0",1},
        {"Celia Laiter","\0","MIPS",2},
        {"Hoppy Hipman","Analyst Trainee","\0",1 },
        {"Pat Hand","\0","LOOPY",2}

    };

    showmenu();
    char choice;

    while ((choice = get_choice()) && choice != 'q')
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
    cout << "q. quit" << endl;
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
            cout << "请输入a、b、c、d或q : ";
        else
            break;
    }

    return ch;
}
void display_by_name(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
    {
        //更完善的写法：
        /*if (strlen((p_BopStructure + i)->fullname) == 0)
            continue;
        else*/
        cout << (p_BopStructure + i)->fullname << endl;
    }
}
void display_by_title(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
        cout << (p_BopStructure + i)->title << endl;
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
//法二：
//在main函数外声明结构数组，并对其初始化
//这样的话，各被调函数的形参都可以是void
#endif


//5.
#if 0
int main(void)
{
    using namespace std;

    cout << "请输入您的收入：";
    long income;
    double tax = 0;

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

        cout << "您应缴纳税款：" << tax << endl;
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
    cout << "请输入捐献者人数：";
    long num = 0;
    while (!(cin >> num))//输入非规定的数据时cin返回false
    {
        cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

        while (cin.get() != '\n')
            continue;    //消耗掉错误的输入

        cout << "Please enter a number: ";//提示用户再输入
    }
    cin.get();

    PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

    for (int i = 0; i < num; i++)
    {
        cout << "请输入姓名：";
        getline(cin, (p_PeopleTypedef + i)->name);

        cout << "请输入捐款额：";
        while (!(cin >> (p_PeopleTypedef + i)->donation))//输入非规定的数据时cin返回false
        {
            cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

            while (cin.get() != '\n')
                continue;    //消耗掉错误的输入

            cout << "Please enter a number: ";//提示用户再输入
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

void string_tolower(char* p);
void delete_punctuation(char* p);

int main(void)
{
    using namespace std;
    cout << "Enter words (q to quit) : " << endl;
    char words[30];
    int length = 0;
    int index, jishu = 0;
    int vowels = 0, consonants = 0, others = 0;

    while (cin >> words && strcmp(words, "q"))//每次读入两端或一端为空白的字符
    {
        //将两端或一端为空白的字符，若是大写字母，则转化为小写
        string_tolower(words);
        //将两端或一端为空白的字符,其中的标点符号用'\0'替换
        delete_punctuation(words);

        //判断两端或一端为空白的字符是否是单词
        length = strlen(words);
        for (index = 0; index < length; index++)
        {
            if (isalpha(words[index]))
                ++jishu;
        }

        //若是单词
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
                    consonants++;*/			//下面if语句的替代写法
            }

            if (strchr("bcdfghjklmnpqrstvwxyz", words[0]))
                consonants++;
        }
        else//若不是单词
            others++;

        jishu = 0;
    }

    cout << "\n" << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;

    return 0;
}
void string_tolower(char* p)
{
    int length = strlen(p);
    for (int index = 0; index < length; index++)
    {
        if (isupper(*(p + index)))
            *(p + index) = tolower(*(p + index));
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
/*测试数据：
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
*/
#endif


//8.
#if 0
#include <fstream>                  // file I/O support
                                                    //1.包含头文件fstream(其中定义了ifstream类)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main(void)
{
    using namespace std;

    ifstream inFile;                       // object for handling file input
                                                    //2.声明一个ifstream对象                                                   

// ifstream默认以输入方式打开文件，用于读文件
//	ofstream默认以输出方式打开文件，用于写文件

    cout << "Enter name of data file: ";
    char filename[SIZE];
    cin.getline(filename, SIZE);

    inFile.open(filename);           // associate inFile with a file
                                                    //3.将该对象与一个文件关联起来

    //检查文件是否被成功打开
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
                                                   //4.像使用cin那样使用该ifstream对象

    while (inFile.good())   // while input good and not at EOF
    {
        ++count;
        inFile >> ch;
    }

    //确定循环终止的原因
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else//inFile.bad()为true
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "该文件包含 " << count << "个字符" << endl;
    }

    //5.使用完文件后，用close()将其关闭
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

    //cout << "请输入捐献者人数：";

    //检查文件是否被成功打开
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << "6.11.9.txt" << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    long num = 0;
    while (!(inFile >> num))//输入非规定的数据时cin返回false
    {
        cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

        while (cin.get() != '\n')
            continue;    //消耗掉错误的输入

        cout << "Please enter a number: ";//提示用户再输入
    }
    inFile.get();

    PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

    for (int i = 0; i < num; i++)
    {
        //cout << "请输入姓名：";
        getline(inFile, (p_PeopleTypedef + i)->name);

        //cout << "请输入捐款额：";
        while (!(inFile >> (p_PeopleTypedef + i)->donation))//输入非规定的数据时inFile返回false
        {
            inFile.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

            while (inFile.get() != '\n')
                continue;    //消耗掉错误的输入

            cout << "Please enter a number: ";//提示用户再输入
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
#endif


//chapter 7
//code1.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//程序清单7.2 函数原型，函数调用，函数定义
#if 0
void cheers(int);       // prototype: no return value
double cube(double x);  // prototype: returns a double

int main()
{
    using namespace std;

    cheers(5);          // function call

    cout << "Give me a number: ";
    double side;
    cin >> side;

    double volume = cube(side);    // function call

    cout << "A " << side << "-foot cube has a volume of ";
    cout << volume << " cubic feet.\n";

    cheers(cube(2));    // prototype protection at work
    //C++能自动将传递的值转化为原型中指定的类型
    //2转化为2.0，cube函数返回8.0，8.0转化为8，进入cheers函数

    // cin.get();
    // cin.get();
    return 0;
}

void cheers(int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << "Cheers! ";
    cout << endl;
}
double cube(double x)
{
    return x * x * x;
}
#endif


//程序清单7.3 一般而言，被调函数中对数据的操作不会影响主调函数中的数据的值
//因为被调函数将创建一个新的变量(形参)并对其初始化为实参的值，相当于是实参的值的副本
#if 0
using namespace std;

void n_chars(char, int);

int main()
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    while (ch != 'q')        // q to quit
    {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times); // function with two arguments
        cout << "\nEnter another character or press the"
            " q-key to quit: ";
        cin >> ch;
    }
    cout << "The value of times is " << times << ".\n";
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}

void n_chars(char c, int n) // displays c n times
{
    while (n-- > 0)         // continue until n reaches 0
        cout << c;
}
#endif


//程序清单7.4 接受两个参数的函数的应用
#if 0
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
        "the number of picks allowed:\n";

    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices);      // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;

    return result;
}
#endif


//程序清单7.5 使用指向数组的指针作为函数的形参
#if 0
const int ArSize = 8;

int sum_arr(int arr[], int n);        // prototype

int main()
{
    using namespace std;
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
    // some systems require preceding int with static to
    // enable array initialization

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}
#endif


//程序清单7.6 数组名代表数组的第一个元素的地址
//***注***
//&数组名得整个数组的地址，而不是单个元素的地址，见书P176
#if 0
const int ArSize = 8;

int sum_arr(int arr[], int n);

// use std:: instead of using directive
int main()
{
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

    std::cout << "array address = " << cookies;
    //  some systems require a type cast: unsigned (cookies)

    std::cout << ", sizeof cookies = " << sizeof cookies << std::endl;
    //sizeof cookies：指整个数组的长度(以字节为单位)
    int sum = sum_arr(cookies, ArSize);

    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, 3);        // a lie
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);    // another lie
    //或写为
    //sum = sum_arr(&cookies[4], 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";
    // std::cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;
    std::cout << "arr = " << arr;
    // some systems require a type cast: unsigned (arr)

    std::cout << ", sizeof arr = " << sizeof arr << std::endl;
    //***注***sizeof arr是指针变量的长度，而不是数组中的元素的长度

    for (int i = 0; i < n; i++)
        total = total + arr[i];

    return total;
}
#endif


//程序清单7.7 填充数组、保护和显示数组、修改数组的函数
//将数组起始处的指针作为一个参数，将数组长度作为第二个参数
#if 0
const int Max = 5;

// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);

    show_array(properties, size);

    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;

        ar[i] = temp;
    }
    return i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}
#endif


//程序清单7.8 另一种给函数提供所需信息的方法
//一个指针标识数组的开头，一个指针标识数组结尾后面的一个位置
#if 0
const int ArSize = 8;

int sum_arr(const int* begin, const int* end);

int main()
{
    using namespace std;
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies + 3);        // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, cookies + 8);    // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(const int* begin, const int* end)
{
    const int* pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}
#endif


//程序清单7.9 用函数处理字符串
#if 0
unsigned int c_in_str(const char* str, char ch);

int main()
{
    using namespace std;
    char mmm[15] = "minimum";    // string in an array
// some systems require preceding char with static to
// enable array initialization

    const char* wail = "ululate";    // wail points to string

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    // cin.get();
    return 0;
}

//不必将字符串长度作为参数传递给函数
unsigned int c_in_str(const char* str, char ch)
{
    unsigned int count = 0;

    while (*str)        // quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++;        // move pointer to next char
    }
    return count;
}
#endif


//程序清单7.10 返回C风格字符串的函数
#if 0
char* buildstr(char c, int n);     // prototype

int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char* ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;                   // free memory

    ps = buildstr('+', 20);         // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps;                   // free memory
    // cin.get();
    // cin.get();
    return 0;
}

// builds string made of n c characters
char* buildstr(char c, int n)
{
    char* pstr = new char[n + 1];

    while (n-- > 0)
        pstr[n] = c;        // fill rest of string

    pstr[n] = '\0';         // terminate string

    return pstr;//***注***此函数结束时，指针pstr所占的内存将被释放，
}                      //而new申请的动态分配的内存空间不会被释放,
                       //由于函数返回了指针pstr上存的地址，因此main()仍可以用ps来访问创建的字符串
#endif  


//程序清单7.11 传递并返回结构
#if 0
struct travel_time
{
    int hours;
    int mins;
};

const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
    using namespace std;
    travel_time day1 = { 5, 45 };    // 5 hrs, 45 min
    travel_time day2 = { 4, 55 };    // 4 hrs, 55 min

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = { 4, 32 };
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    // cin.get();

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = t1.hours + t2.hours +
        (t1.mins + t2.mins) / Mins_per_hr;
    return total;
}

void show_time(travel_time t)
{
    using namespace std;
    cout << t.hours << " hours, "
        << t.mins << " minutes\n";
}
#endif


//程序清单7.12 传递并返回结构  实际应用
#if 0
#include <cmath>//sqrt()、atan2()

struct rect
{
    double x;             // horizontal distance from origin
    double y;             // vertical distance from origin
};

struct polar
{
    double distance;      // distance from origin
    double angle;         // direction from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)  // slick use of cin
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);

    return answer;      // returns a polar structure
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}
#endif


//程序清单7.13 传递结构的地址
#if 0
#include <cmath>

// structure templates
struct rect
{
    double x;             // horizontal distance from origin
    double y;             // vertical distance from origin
};

struct polar
{
    double distance;      // distance from origin
    double angle;         // direction from origin
};

// prototypes
void rect_to_polar(const rect* pxy, polar* pda);
void show_polar(const polar* pda);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);    // pass addresses
        show_polar(&pplace);        // pass address
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect* pxy, polar* pda)
{
    using namespace std;
    pda->distance =
        sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}

// show polar coordinates, converting angle to degrees
void show_polar(const polar* pda)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle * Rad_to_deg;
    cout << " degrees\n";
}
#endif


//程序清单7.14 用string对象数组代替二维数组
#if 0
#include <string>

using namespace std;

const int SIZE = 5;

void display(const string sa[], int n);

int main()
{
    string list[SIZE];     // an array holding 5 string object

    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list:\n";
    display(list, SIZE);//list==&list[0]：string数组的首行的整个string对象的地址
    // cin.get();

    return 0;
}

void display(const string sa[], int n)//形参：指向string对象的指针
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << sa[i] << endl;
    //写法二：    
    //cout << i + 1 << ": " << *(sa+i) << endl;
}
#endif


//程序清单7.15 array模板可以存储类对象，并成为一个array对象，也可以代替二维数组
//函数访问array对象的方式(写法)有些不同
#if 0
#include <array>//array类
#include <string>//string类

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//声明一个const array对象，该对象包含4个string对象

//******************注***********************
/*法二
//const char *Snames[Seasons] =
//{ "Spring", "Summer", "Fall", "Winter" };
*/
/*法三
const char Snames[Seasons][20] =
{ "Spring", "Summer", "Fall", "Winter" };
*/

void fill(std::array<double, Seasons>* pa);//形参：指向array对象的指针
void show(std::array<double, Seasons> da);//形参：array对象

int main()
{
    std::array<double, Seasons> expenses;//声明一个array对象，包含4个double类型的值

                               //***注***
    fill(&expenses);//实参：array整个对象的地址，而不是&array[0]
    show(expenses);//实参：整个array对象
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons>* pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> (*pa)[i];//此处写法唯一
        //std::cin >> *(pa + i);//***注***错误：每次+1都增加1个array对象所占的字节数
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//程序清单7.16 递归
#if 0
void countdown(int n);

int main()
{
    countdown(4);           // call the recursive function
    // std::cin.get();
    return 0;
}

void countdown(int n)
{
    using namespace std;

    cout << "Counting down ... " << n << " (n at " << &n << ")" << endl;
    if (n > 0)
        countdown(n - 1);     // function calls itself
    cout << n << ": Kaboom!" << " (n at " << &n << ")" << endl;
}
#endif


//程序清单7.17 包含多个递归调用的递归
#if 0
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main()
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';//第2个元素至第Len-2个元素都为空格

    ruler[Len - 1] = '\0';//第Len个(最后一个)元素为空字符

    int max = Len - 2;
    int min = 0;                            //min和max都为索引值
    ruler[min] = ruler[max] = '|';//第1个元素和第Len-1个元素为'|'

    std::cout << ruler << std::endl;//打印第一行

    for (i = 1; i <= Divs; i++)//处理第 i +1 行
    {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;

        //清理数组中的'|'字符(可以不写)
        //for (int j = 1; j < Len - 2; j++)
        //    ruler[j] = ' ';  // reset to blank ruler
    }
    // std::cin.get();

    return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0)
        return;

    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);//左侧
    subdivide(ar, mid, high, level - 1);//右侧
}
#endif


//程序清单7.18 使用函数指针
#if 0
double betsy(int);
double pam(int);

// second argument is pointer to a type double function that
// takes a type int argument
void estimate(int lines, double (*pf)(int));

int main()
{
    using namespace std;
    int code;

    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
    // cin.get();
    // cin.get();
    return 0;
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n";
}
#endif


//程序清单7.19 深入探讨函数指针
#if 0
// 1.various notations, same signatures 不同的函数名，但相同的函数返回值和参数列表
const double* f1(const double ar[], int n);//形参：指向const double 类型值得指针；数组的元素个数
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
    using namespace std;

    double av[3] = { 1112.3, 1542.6, 2227.9 };

    //************************************************************************************************************************************************************************
        // 2.可以在声明函数指针的同时进行初始化
    const double* (*p1)(const double*, int) = f1;//①声明一个函数指针p1
                                                                              //*p1表明p1是函数指针，函数返回值： const double*(const double类型值的地址)，函数形参：(const double*, int)

    auto p2 = f2;  // 3.声明一个函数指针p2，并对其初始化。对单值初始化可用auto自动类型推断来进行初始化
    //写法二：
    // const double *(*p2)(const double *, int) = f2;

    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    //显示const double 值的地址；显示const double 值
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    //************************************************************************************************************************************************************************

    const double* (*pa[3])(const double*, int) = { f1,f2,f3 };//②声明一个数组pa，包含3个元素，每个元素都是函数指针，pa指向函数指针数组的首元素，pa存函数指针数组的首元素的地址
    // pb a pointer to first element of pa
    auto pb = pa;//③声明一个指向函数指针数组的首元素的指针pb，并对其初始化。
                           // 4.***注***auto不能适用于推断列表初始化对应的类型声明，此处用auto声明的pb，pb存函数指针数组的首元素的地址
    //写法二：
    // const double *   (**pb)    (const double *, int) = pa;

    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    //************************************************************************************************************************************************************************

        //④***注***错误理解：
        //声明一个指向函数指针数组的首元素的指针pa的指针pc，pc存函数指针数组的首元素的指针pa的地址
        //***正确理解***：
        //声明一个指向整个函数指针数组的指针pc，pc存整个函数指针数组的地址
    auto pc = &pa;
    //写法二：
    // const double *(*(*pc)[3])(const double *, int) = &pa;

    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address  Value\n";
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    // hard way to declare pd
    const double* (*(*pd)[3])(const double*, int) = &pa;
    // store return value in pdb
    const double* pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    // alternative notation
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    // cin.get();
    return 0;
}

// some rather dull functions
const double* f1(const double* ar, int n)
{
    return ar;
}
const double* f2(const double ar[], int n)
{
    return ar + 1;
}
const double* f3(const double ar[], int n)
{
    return ar + 2;
}
#endif
//扩展：
//可以利用typedef让声明更加清晰易懂
#if 0
typedef const double* (*p_fun)(const double*, int);//把指向此种函数返回值和函数参数的函数的函数指针命名为p_fun

// 1.various notations, same signatures 不同的函数名，但相同的函数返回值和参数列表
const double* f1(const double ar[], int n);//形参：指向const double 类型值得指针；数组的元素个数
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
    using namespace std;

    double av[3] = { 1112.3, 1542.6, 2227.9 };

    //************************************************************************************************************************************************************************

    p_fun p1 = f1;//①声明一个函数指针p1

    auto p2 = f2;  //声明一个函数指针p2，并对其初始化。对单值初始化可用auto自动类型推断来进行初始化
    //写法二：
    //p_fun p2= f2;

    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    //显示const double 值的地址；显示const double 值
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    //************************************************************************************************************************************************************************

    p_fun pa[3] = { f1,f2,f3 };//②声明一个数组pa，包含3个元素，每个元素都是函数指针，pa指向函数指针数组的首元素，pa存函数指针数组的首元素的地址

    auto pb = pa;//③声明一个指向函数指针数组的首元素的指针pb，并对其初始化。
                           //***注***auto不能适用于推断列表初始化对应的类型声明，此处用auto声明的pb，pb存函数指针数组的首元素的地址
    //写法二：
    //p_fun* pb = pa;

    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    //************************************************************************************************************************************************************************

        //④***注***错误理解：
        //声明一个指向函数指针数组的首元素的指针pa的指针pc，pc存函数指针数组的首元素的指针pa的地址
        //***正确理解***：
        //声明一个指向整个函数指针数组的指针pc，pc存整个函数指针数组的地址
    auto pc = &pa;
    //写法二：
    // p_fun(*pc)[3] = &pa;   

    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address  Value\n";
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    // hard way to declare pd
    const double* (*(*pd)[3])(const double*, int) = &pa;
    // store return value in pdb
    const double* pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    // alternative notation
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    // cin.get();
    return 0;
}

// some rather dull functions
const double* f1(const double* ar, int n)
{
    return ar;
}
const double* f2(const double ar[], int n)
{
    return ar + 1;
}
const double* f3(const double ar[], int n)
{
    return ar + 2;
}
#endif
#endif


//chapter 7
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//7.12复习题
//2.
#if 0
void igor(void);
float tofu(int);
double mpg(double, double);
long summation(long* p, int num);
double doctor(const char* string);
void ofcourse(struct boss bos);
char* plot(struct map* p_structure);
#endif


//3.
#if 0
void Array_Init(int* p_data, int num, int data);

void Array_Init(int* p_data, int num, int data)
{
    for (int i = 0; i < num; i++)
        *(p_data + i) = data;

    return;
}
#endif


//4.
#if 0
void fill_array(int* begin, int* end, int num)
{
    int* temp;
    for (temp = begin; temp != end; temp++)
        *temp = num;

    //法二：
    /*while (begin!=end)
    {
        *begin = num;
        begin++;
    }*/
}
#endif


//5.
#if 0
double FindMax(const double* p, int num)
{
    double max = *p;
    for (int i = 0; i < num - 1; i++)
        (*(p + i) >= *(p + i + 1)) ? (max = *(p + i)) : (max = *(p + i + 1));

    //法二：
    /*for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = *(p+i);*/

    return max;
}
#endif


//8.
#if 0
int replace(char* str, char c1, char c2)
{
    int count = 0;

    while (str)
    {
        if (*str == c1)
        {
            *str = c2;
            count++;
        }
        str++;
    }

    return count;
}
#endif


//11.
#if 0
int judge(int (*p_fun) (const char* string));
#endif


//12.
#if 0
struct applicant
{
    char name[30];
    int credit_ratings[3];
};

struct applicant applicant_structure;

void show(struct applicant applicant_structure)
{
    std::cout << applicant_structure.name << "\n";
    for (int i = 0; i < 3; i++)
        std::cout << applicant_structure.credit_ratings[i] << std::endl;
}

void show(const struct applicant* p_applicant_structure)
{
    std::cout << p_applicant_structure->name << "\n";
    for (int i = 0; i < 3; i++)
        std::cout << p_applicant_structure->credit_ratings[i] << std::endl;
}
#endif


//13.
#if 0
struct applicant
{
    char name[30];
    int credit_ratings[3];
};

void f1(applicant* a);
const char* f2(const applicant* a1, const applicant* a2);

typedef void (*p_fun1)(applicant*);
typedef const char* (*p_fun2)(const applicant*, const applicant*);

int main(void)
{
    p_fun1 p1 = f1;
    p_fun2 p2 = f2;

    p_fun1 ap[5] = { f1,f1,f1,f1,f1 };

    p_fun2 f2_array[10] = { f2,f2 ,f2 ,f2 ,f2  ,f2  ,f2  ,f2  ,f2  ,f2 };
    p_fun2(*pa)[10] = &f2_array;

    std::cout << "Done !";
    return 0;
}
void f1(applicant* a)
{}
const char* f2(const applicant* a1, const applicant* a2)
{
    return 0x00;
}
#endif
#endif


//chapter 7
//code3.cpp
#if 0
#include <iostream>
//
#if 0
int main(void)
{
    using namespace std;

    return 0;
}
#endif


//7.13 编程练习
//1.
#if 0
double harmonic_average_fun(double a, double b);

int main(void)
{
    using namespace std;

    cout << "请输入两个数字：";

    double a, b;
    double harmonic_average;
    while (cin >> a >> b && a != 0 && b != 0)
    {
        harmonic_average = harmonic_average_fun(a, b);
        cout << "数字" << a << "和" << b << "的调和平均数是：" << harmonic_average << endl;
        cout << "请输入两个数字：";
    }

    return 0;
}
double harmonic_average_fun(double a, double b)
{
    double result = 2.0 * a * b / (a + b);

    return result;
}
#endif


//2.
#if 0
int fill_array(double* p_num);
void show(const double* p_num, int);
double average(const double* p_num, int);

using namespace std;


int main(void)
{
    cout << "请输入最多10个高尔夫成绩(输入0以结束输入)：";
    double scores[10];
    int count = fill_array(scores);

    show(scores, count);

    double averagenum = average(scores, count);
    cout << "平均成绩：" << averagenum << endl;

    return 0;
}
int fill_array(double* p_num)
{
    int count = 0;
    double temp;

    for (int i = 0; i < 10; i++)
    {
        while (!(cin >> temp))
        {
            cin.clear();

            while (cin.get() != '\n')
                continue;    //消耗掉错误的输入

            cout << "请输入数字！" << endl;
        }

        if (temp != 0)
        {
            p_num[i] = temp;
            count++;
        }
        else
            break;
    }

    return count;
}
void show(const double* p_num, int num)
{
    cout.put('\n') << "输入的成绩为：";
    for (int i = 0; i < num; i++)
        cout << *(p_num + i) << "  ";
    cout << endl;
}
double average(const double* p_num, int num)
{
    double sum = 0.0;
    for (int i = 0; i < num; i++)
        sum += *(p_num + i);

    return (double)(sum / num);
}
#endif


//4.
#if 0
long double probability(unsigned numbers, unsigned picks,
    unsigned numbers1, unsigned picks1);

int main()
{
    using namespace std;
    double total, choices;
    double total1, choices1;
    cout << "请输入普通数字的区间(1~X)和允许选择的号码个数\n";

    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "请输入特选数字的区间(1~X)和允许选择的号码个数\n";
        cin >> total1 >> choices1;

        cout << "You have one chance in ";
        cout << probability(total, choices, total1, choices1);      // compute the odds
        cout << " of winning.\n";
        cout << "请输入普通数字的区间(1~X)和允许选择的号码个数\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks,
    unsigned numbers1, unsigned picks1)
{
    long double result = 1.0, result1 = 1.0; // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    for (n = numbers1, p = picks1; p > 0; n--, p--)
        result1 = result1 * n / p;

    return result * result1;
}
#endif


//5.
#if 0
long long temp = 1;
long long jiecheng(long long num);

int main(void)
{
    using namespace std;

    cout << "请输入要阶乘的整数：";
    long long num, result;
    while (cin >> num)
    {
        result = jiecheng(num);
        cout << num << "! = " << result << endl;
        temp = 1;
        cout << "请输入要阶乘的整数：";
    }

    return 0;
}

//法一：递归的返回值不使用
#if 0
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        temp *= num;
        jiecheng(--num);
    }

    return temp;
}
#endif

/*
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        temp = num * jiecheng(num--);//错误：这样会无限调用函数jiecheng()
        return temp;
    }
}
*/

//法二：
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    if (num > 1)
    {
        temp = num * jiecheng(num - 1);
        //***注***
        //若写成--num，则此语句先是把num递减，然后把*号左侧用num递减后的值代替，再进入调用的函数，所以得2!=1
        //若写成num--，则此语句先是把*号左侧用num的值代替，然后把num递减，再进入调用的函数，但是在第二次进入函数时(用监视器查看num值可知)num又变回了原值，导致程序无限循环
        // 理解：书P112：
        //此语句末尾是个顺序点，C++只能保证此语句后面，num的值会减少1，并不保证在此语句进行的某个时刻，使num值减1
        return temp;
    }
}
#endif


//6.对比程序清单5.9 反转数组的另一种方法
#if 0
void reverse_array(double* ar, int size)
{
    double temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = ar[i];
        arr[i] = ar[size - i - i];
        arr[size - i - 1] = temp;
    }
}
#endif


//7.
#if 0
const int Max = 5;

// function prototypes
double* fill_array(double ar[], double*);
void show_array(const double ar[], double*);  // don't change data
void revalue(double r, double ar[], double*);

int main()
{
    using namespace std;
    double properties[Max];

    double* end = fill_array(properties, properties + Max);

    show_array(properties, end);

    if (end - properties > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

double* fill_array(double ar[], double* end)
{
    using namespace std;
    double temp;
    int i = 0;
    double* the_end;

    for (; ar != end; ar++)
    {
        cout << "Enter value #" << (++i) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;

        *ar = temp;
    }
    the_end = ar;

    return the_end;
}

//the following function can use, but not alter,
//the array whose address is ar
void show_array(const double ar[], double* end)
{
    using namespace std;
    for (int i = 0; i < end - ar; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

//法二：
#if 0
void show_array(const double ar[], double* end)
{
    using namespace std;

    int* p_num = new int[end - ar];
    int index;
    for (index = end - ar - 1; index >= 0; index--)
        *(p_num + index) = index;

    index = 0;
    for (; ar != end; ar++, index++)
    {
        cout << "Property #" << *(p_num + index) + 1 << ": $";
        cout << *ar << endl;
    }

    delete[]p_num;
}
#endif

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double* end)
{
    for (; ar < end; ar++)
        *ar *= r;
}
#endif


//8.a.
#if 0
const int Seasons = 4;

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double* p_num, int NumToFill);
void show(const double* p_num, int NumToShow);

int main()
{
    double expenses[Seasons];

    fill(expenses, Seasons);
    show(expenses, Seasons);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(double* p_num, int NumToFill)
{
    for (int i = 0; i < NumToFill; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> *(p_num + i);
    }
}

void show(const double* p_num, int NumToShow)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < NumToShow; i++)
    {
        std::cout << Snames[i] << ": $" << *(p_num + i) << '\n';
        total += *(p_num + i);
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//8.b.
#if 0
const int Seasons = 4;

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

typedef struct
{
    double expenses[Seasons];
}Expenses_Typedef;

void fill(Expenses_Typedef* p_structure, int NumToFill);
void show(const Expenses_Typedef* p_structure, int NumToShow);

int main()
{
    Expenses_Typedef Expenses_structure;

    fill(&Expenses_structure, Seasons);
    show(&Expenses_structure, Seasons);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(Expenses_Typedef* p_structure, int NumToFill)
{
    for (int i = 0; i < NumToFill; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> p_structure->expenses[i];
    }
}

void show(const Expenses_Typedef* p_structure, int NumToShow)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < NumToShow; i++)
    {
        std::cout << Snames[i] << ": $" << *(p_structure->expenses + i) << '\n';
        total += *(p_structure->expenses + i);
    }
    //***注***
    /*
    p_structure->expenses[0] = 0;
    */
    //此语句不被允许，因为把Expenses_Typedef布局的结构变量声明为了const
    //即结构变量中的值都不可以改变
    std::cout << "Total: $" << total << '\n';
}
#endif


//9.
#if 0
#include <cstring>//strlen()，memcpy()
using namespace std;

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(struct student* p_structure, int num);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main(void)
{
    cout << "Enter class size : ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student* ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);
    cout << "\n学生信息如下\n";
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete[]ptr_stu;
    cout << "Done !\n";

    return 0;
}
int getinfo(struct student* p_structure, int num)
{
    int count = 0;
    char temp[SLEN];

    for (int i = 0; i < num; i++)
    {
        cout << "请填充第" << i + 1 << "个结构——" << endl;
        cout << "请输入学生全名(按Enter以结束输入)：";
        cin.getline(temp, SLEN);
        if (temp[0] == '\0')
            break;
        else
            memcpy((p_structure + i)->fullname, temp, strlen(temp) * sizeof(char) + 1);
        //***注***
        //若上述语句写为strlen(temp)*sizeof(char) 则无法拷贝空字符，造成后续打印的有意义的内容的后面是乱码
        cout << "请输入该学生的兴趣爱好：";
        cin.getline((p_structure + i)->hobby, SLEN);
        cout << "请输入该学生的面向对象编程的熟练等级：";
        while (!(cin >> (p_structure + i)->ooplevel))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "请输入整数数字！" << endl;
        }
        cin.get();

        count++;
    }

    return count;
}
void display1(student st)
{
    cout << "学生姓名：" << st.fullname << endl;
    cout << "学生的爱好：" << st.hobby << endl;
    cout << "学生的面向对象编程的熟练等级：" << st.ooplevel << endl << endl;
}
void display2(const student* ps)
{
    cout << "学生姓名：" << ps->fullname << endl;
    cout << "学生的爱好：" << ps->hobby << endl;
    cout << "学生的面向对象编程的熟练等级：" << ps->ooplevel << endl << endl;
}
void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "学生姓名：" << (pa + i)->fullname << endl;
        cout << "学生的爱好：" << (pa + i)->hobby << endl;
        cout << "学生的面向对象编程的熟练等级：" << (pa + i)->ooplevel << endl << endl;
    }
}
#endif


//10.
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x, double y);
int main(void)
{
    using namespace std;

    double result;

    cout << "请输入两个数字：";
    double a, b;
    while (cin >> a >> b)
    {
        result = calculate(a, b, add);
        cout << a << "+" << b << "结果为" << result << endl;

        result = calculate(a, b, sub);
        cout << a << "-" << b << "结果为" << result << endl;

        cout << "请输入两个数字(输入非数字以退出程序)：";
    }

    return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
    double result;

    result = p_fun(x, y);

    return result;
}

double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
#endif


//10.使用函数指针数组
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x, double y);
double mul(double, double);

int main(void)
{
    using namespace std;

    double (*pf[3])(double, double) = { add,sub,mul };//创建并初始化一个函数指针数组
    const char* p_string[3] = { "+","-","*" };

    double result;

    cout << "请输入两个数字：";
    double a, b;
    while (cin >> a >> b)
    {
        for (int i = 0; i < 3; i++)
        {
            result = calculate(a, b, pf[i]);
            cout << a << p_string[i] << b << "结果为" << result << endl;
        }
        cout << "请输入两个数字(输入非数字以退出程序)：";
    }

    return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
    double result;

    result = p_fun(x, y);

    return result;
}

double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
double mul(double x, double y)
{
    return x * y;
}
#endif
#endif


//chapter 8
//code1.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//程序清单8.1 C++通常用内联函数代替C语言的类函数宏
#if 0
// an inline function definition
inline double square(double x) { return x * x; }//内联函数一般把函数原型省略，将整个定义放在头文件中

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);   // can pass expressions

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    //***注***
    //此语句末尾是个顺序点，C++只能保证此语句后面，c的值会增加1
   //传入square()的是递增前的c的值
    //宏不能按值传递，而是通过文本替换实现功能
    //内联函数能按值传递
    cout << "Now c = " << c << "\n";

    // cin.get();
    return 0;
}
#endif


//程序清单8.2 创建引用变量
#if 0
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   // rodents is a reference
                                        //创建指向rats的引用变量rodents
                                        //rodents作为rats变量的别名，两者都指向同一个值和内存单元
                                        //int &   :指向int类型变量的引用
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;//递增的不是地址值，而是rats的值
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    // some implementations require type casting the following
    // addresses to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单8.3 引用一旦在声明时被初始化后，就一直绑定了该变量
#if 0
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   //声明并初始化引用，rodents引用rats

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;       // can we change the reference?
                                           //可以改变rodents引用的变量吗？
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;//rodents的地址仍与rats的地址相同
    // cin.get();
    return 0;
}
#endif


//程序清单8.4 比较传递函数参数的三种方法
//1.按值传递，2.按指针传递，3.按引用传递
#if 0
void swapv(int a, int b);       // a, b are new variables
void swapp(int* p, int* q);   // p, q are addresses of ints
void swapr(int& a, int& b);   // a, b are aliases for ints

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);   // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);   // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    // cin.get();
    return 0;
}

void swapv(int a, int b)        // try using values
{
    int temp;

    temp = a;      // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int* p, int* q)    // use pointers
{
    int temp;

    temp = *p;      // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

void swapr(int& a, int& b)    // use references
{
    int temp;

    temp = a;       // use a, b for values of variables
    a = b;
    b = temp;
}
#endif


//程序清单8.5 声明时引用不带const和带const，对于实参有问题时的不同反应
#if 0
double cube(double a);
double refcube(double& ra);
double refcude_1(const double& ra);

int main()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;

    cout << refcube(x);
    //***注***若写成refcude(3)，则会报错：非常量引用的初始值必须是左值
    //因为字面量3，属于非左值，而且引用变量没有设为const，所以C++不会创建临时变量，而是直接报错
    cout << " = cube of " << x << endl;

    int a = 3;
    cout << refcude_1(a);
    cout << " = cube of " << a << endl;
    //***注***若函数声明时对引用不加const，则会报错：无法用int类型的值初始化double&类型的引用(非常量限定)

    // cin.get();
    return 0;
}

double cube(double a)           // x=3.0传入，返回值27.0传出
{
    a *= a * a;
    return a;
}

double refcube(double& ra)  // ra是x的别名，函数修改了x，x的值变为27.0
{
    ra *= ra * ra;
    return ra;
}                                               //***注***若想使用引用，但不对这些信息修改，则应该使用常量引用
                                                //double refcube(const double& ra)

double refcude_1(const double& ra)
{
    return ra * ra * ra;
}                                               //***注***由于实参传的是3，所以C++会创建一个匿名临时变量
#endif                        


//程序清单8.6 将引用用于结构
//返回引用和按值返回的不同之处
#if 0
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
//返回值：指向结构的引用
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
    free_throws one = { "Ifelsa Branch", 13, 14 };
    free_throws two = { "Andor Knott", 10, 16 };
    free_throws three = { "Minnie Max", 7, 9 };
    free_throws four = { "Whily Looper", 5, 9 };
    free_throws five = { "Long Long", 6, 14 };
    free_throws team = { "Throwgoods", 0, 0 };
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // use return value as argument 使用返回值作为参数
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    //***注***
    //函数的返回值必须是引用，若函数是按值返回，则后续的程序无法访问返回的值，此语句不能通过编译
    //而且按值返回的值(是临时值)不能作为赋值表达式语句的左值，只能作为右值
    display(team);

    // use return value in assignment 使用返回值作为赋值表达式的右值
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);

    set_pc(four);
    // ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
    // std::cin.get();
    return 0;
}

void set_pc(free_throws& ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

void display(const free_throws& ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}
#endif


//程序清单8.7将引用用于类对象
#if 0
#include <string>
using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);  // has side effect
const string& version3(string& s1, const string& s2);  // bad design

int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);

    copy = input;

    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    // cin.get();
    // cin.get();
    return 0;
}

string version1(const string& s1, const string& s2)//***注***虽然实参是string和const *char，但由于const引用的特性，程序将创建一个正确类型的临时变量，s2是指向该临时变量的引用
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
    //***注***
    //不能返回指向temp的引用，因为temp是个自动变量，该函数执行完毕后，它将不再存在
}   //此处temp被复制到一个临时位置，主调函数的result可以访问这个临时位置

const string& version2(string& s1, const string& s2)   // has side effect
{
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}

const string& version3(string& s1, const string& s2)   // bad design
{
    string temp;

    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
    //***注***
    //不能返回指向temp的引用，因为temp是个自动变量，该函数执行完毕后，它将不再存在
}   //对比version1()函数
#endif


//程序清单8.8 基类引用可以指向基类或派生类对象，而无需进行强制类型转换
#if 0
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);//形参：指向ostream对象的引用
const int LIMIT = 5;

int main()
{
    ofstream fout;//以输出方式打开文件，用于写文件
    const char* filename = "ep-data.txt";

    fout.open(filename);

    if (!fout.is_open())
    {
        cout << "Can't open " << filename << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
        "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
        << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);//向文件写入数据
    file_it(cout, objective, eps, LIMIT);//在显示屏上显示数据
    cout << "Done\n";
    // cin.get();
    // cin.get();
    return 0;
}

//形参：指向ostream对象的引用，物镜焦距fo，指向目镜焦距数组首元素的指针，数组长度
//***注***
//os可以指向ostream对象，也可以指向ofstream对象
void file_it(ostream& os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    //fmtflags：格式状态标志位，是存储格式化信息的数据类型
    //声明一个fmtflags类型的变量initial
    initial = os.setf(ios_base::fixed, ios_base::floatfield);
    //initial用来保存最初的格式化状态

    std::streamsize sz = os.precision(0);

    os << "Focal length of objective: " << fo << " mm\n";
    os.precision(1);
    os.width(12);//此设置仅在显示下一个值时有效
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }

    os.setf(initial);
    // restore initial formatting state 将所有的格式化设置恢复到原来的值
    //方法setf()返回调用它之前有效的所有格式化设置(被存储在initial中)
    os.precision(sz);
}
#endif


//程序清单8.9 使用默认参数
#if 0
const int ArSize = 80;

char* left(const char* str, int n = 1);//n的默认值是1

int main()
{
    using namespace std;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char* ps = left(sample, 4);
    cout << ps << endl;
    delete[] ps;       // free old string

    ps = left(sample);
    cout << ps << endl;
    delete[] ps;       // free new string
    // cin.get();
    // cin.get();
    return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;
    char* p = new char[n + 1];//利用动态内存分配，使创建的数组在被调函数结束时仍存在

    //法二：
    /*
    int len = strlen(str);
    n = (n < len) ? n:len;

    char* p = new char[n + 1];
    */
    //法三：
    /*
    int m=0;
    while(m<n&&str[m])
    m++;

    char* p = new char[n + 1];
    */

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;//指针p属于自动变量，在返回给主调函数其所存的地址值后，p将不再存在
}
#endif


//程序清单8.10 使用函数重载
#if 0
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main()
{
    using namespace std;
    unsigned long n = 12345678; // test value
    const char* trip = "Hawaii!!";   // test value

    char* temp;

    for (int i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;

        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; // point to temporary storage
    }
    // cin.get();
    return 0;
}

// This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;       // return 0 if no digits

    while (n /= 10)
        digits++;   //计算数字num有几位

    if (digits > ct)//若位数大于要保留的位数(从高位到低位保留)
    {
        ct = digits - ct;//计算要删除几位(从低位向高位删除)

        while (ct--)
            num /= 10;
        return num;         // return left ct digits
    }
    else //若位数小于或等于要保留的位数(从高位到低位保留)
        return num;     // return the whole number
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;

    char* p = new char[n + 1];

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;
}
#endif


//程序清单8.11 使用函数模板
#if 0
// function template prototype 声明一个函数模板
template <typename T>  // or class T 或使用关键字class   将类型命名为T
void Swap(T& a, T& b);

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y);  // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y << ".\n";
    // cin.get();
    return 0;
}

// function template definition 定义函数模板
template <typename T>  // or class T
void Swap(T& a, T& b)
{
    T temp;   // temp a variable of type T 创建一个T类型的变量temp
    temp = a;
    a = b;
    b = temp;
}
#endif


//程序清单8.12 使用重载的模板
#if 0
template <typename T>     // original template
void Swap(T& a, T& b);

template <typename T>     // new template
void Swap(T* a, T* b, int n);

const int Lim = 8;
void Show(int a[]);

int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);              // matches original template
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = { 0,7,0,4,1,7,7,6 };
    int d2[Lim] = { 0,7,2,0,1,9,6,9 };
    cout << "Original arrays:\n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);        // matches new template
    cout << "Swapped arrays:\n";
    Show(d1);
    Show(d2);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];
    cout << endl;
}
#endif


//程序清单8.13 使用显式具体化
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//声明一个常规模板，将类型命名为T
void Swap(T& a, T& b);

// explicit specialization 
template <> void Swap<job>(job& j1, job& j2);
//显式具体化
//不使用Swap()模板来生成函数定义，而使用专门为job类型显式地定义的函数定义
//或写成：
//template <> void Swap<>(job& j1, job& j2);
//template <> void Swap(job& j1, job& j2);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);    //隐式实例化，生成 void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = { "Susan Yaffee", 73000.60, 7 };
    job sidney = { "Sidney Taffee", 78060.72, 9 };
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);

    cout << "After job swapping:\n";
    Swap(sue, sidney); // uses void Swap(job &, job &)
    Show(sue);
    Show(sidney);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template <> void Swap<job>(job& j1, job& j2)  // specialization
//写法二：
//template <> void Swap<>(job& j1, job& j2)  // specialization
//写法三：
//template <> void Swap(job& j1, job& j2)  // specialization
{
    double t1;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    int t2;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif
//程序清单8.13 改：
//调用函数时来创建显式实例化需要注意的点
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//声明一个常规模板，将类型命名为T
void Swap(T& a, T& b);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10;
    double j = 20.2;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap<double>(i, j);    //显式实例化，根据模板，生成 void Swap(double &, double &)
    //***注***
    //虽然传入函数的都是double类型的值，但是主调函数中的 i 仍是int类型，所以不能产生指向int类型的 i 的引用
    cout << "Now i, j = " << i << ", " << j << ".\n";

    // cin.get();
    return 0;
}

template <typename T>
void Swap(const T& a, const T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;

    return;
}

void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif



//使用显式实例化
//法一：声明时创建显式实例化
#if 0
template <typename T>
T add(T a, T b);

template double add<double>(double, double);//使用add()模板生成一个使用double类型的实例(函数定义)

int main(void)
{
    using namespace std;

    double m = 6;
    double n = 10.2;

    cout << add(m, n) << endl;

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif
//法二：调用函数时来创建显式实例化
#if 0
template <typename T>
T add(T a, T b);

int main(void)
{
    using namespace std;

    int m = 6;
    double n = 10.2;

    cout << add<double>(m, n) << endl;//显示实例化，使用add()模板生成一个使用double类型的实例

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif


//程序清单8.14 重载解析，演示部分排序规则
#if 0
template <typename T>            // template A 假设实参是数组名称，即指向数组首元素的指针
void ShowArray(T arr[], int n);

template <typename T>            // template B 假设实参是指向一个指针数组首元素的指针
//void ShowArray(T* arr[], int n);
//写法二：
void ShowArray(T** arr, int n);

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
//************************************************************************

    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double* pd[3];//声明一个指针数组
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;//对指针数组的每个元素(即每个指针)赋值，赋的是结构的成员amount的地址

    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
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
#endif


//程序清单8.15 编写合适的函数调用，指示编译器使用用户所希望的函数或模板函数
#if 0
template<class T>
T lesser(T a, T b)         // #1
{
    return a < b ? a : b;
}

int lesser(int a, int b)  // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;

    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;       // use #2
    cout << lesser(x, y) << endl;       // use #1 with double
    cout << lesser<>(m, n) << endl;     // use #1 with int
    cout << lesser<int>(x, y) << endl; // use #1 with int

    // cin.get();
    return 0;
}
#endif


//C++11的关键字decltype 用于确定形参进行运算后得到的值的类型，以及确定函数的返回值的类型
#if 0
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y);// ->decltype(x+y) 说明返回类型是x+y运算后的值的类型

int main(void)
{
    using namespace std;

    int a = 1;
    double b = 2.2;
    cout << add(a, b) << endl;

    return 0;
}
/*
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    decltype(x + y) sum = x + y;

    return sum;
}
*/
//也可以使用typedef，给类型增加一个方便使用的标签(取个别名)
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    typedef decltype(x + y)  LeiXin;
    LeiXin sum = x + y;

    return sum;
}
#endif
#endif


//chapter 8
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//8.7复习题
//2.
#if 0
void song(const char* name = "O.My Papa", int times = 1);
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
#include <array>//array类
#include <string>//string类

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//声明一个const array对象，该对象包含4个string对象

void fill(std::array<double, Seasons>&);//形参：指向array对象的引用
void show(const std::array<double, Seasons>&);//形参：指向array对象的引用

int main()
{
    std::array<double, Seasons> expenses;//声明一个array对象，包含4个double类型的值

    fill(expenses);//***注***实参不是数组首元素的地址，而是整个数组
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
        std::cin >> r_a[i];
    }
}

void show(const std::array<double, Seasons>& r_a)
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
//使用默认值法
double mass(double density, double volume = 1.0);
//使用函数重载法
double mass(double density, double volume);
double mass(double density);

//b.
//void repeat(int num=5, const char*);//报错：默认实参不在形参列表的结尾
//使用函数重载法
void repeat(int num, const char*);
void repeat(const char*);

//c.
int average(int, int);
double average(double, double);

//d.
/*
char mangle(char* );
const char* mangle(char*);  //***注***函数特征标相同，无法实现函数重载
*/
#endif


//7.
#if 0
template <typename T1, typename T2>
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
T& bigger(T&, T&);

template <>box& bigger(box& b1, box& b2);


template <typename T>
T& bigger(T& x, T& y)
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
#endif


//chapter 8
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//8.8编程练习
//1.
#if 0
void print(const char*, int num = 0);

int main(void)
{
    const char* p = "ABCdefg";

    for (int i = 0; i < 5; i++)
        print(p, i);

    return 0;
}
void print(const char* p, int num)
{
    using namespace std;
    if (num == 0)
        cout << p << endl << endl;
    else
        cout << p << "\t";				//错误：未能完成当第二个参数不为0时，打印的次数为函数调用的次数
}
#endif
//1.改正
#if 0
void print(const char*, int num = 0);

int main(void)
{
    const char* p = "ABCdefg";

    print(p);
    print(p);
    print(p, 1);


    return 0;
}
void print(const char* p, int num)
{
    using namespace std;

    static int count = 0;						//块作用域的静态变量count用于存储调用函数的次数

    count++;
    if (num == 0)
    {
        cout << "第二个参数为0\t" << p << endl;
    }
    else
        for (int i = 0; i < count; i++)
            cout << "第二个参数不为0\t" << p << endl;
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

void fill_struct(CandyBar&, const char* string = "Millennium Munch",
    double weight = 2.85, int calories = 350);
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
    //也能用memcpy，函数缺少有关数组的长度的信息可以用strlen()获得
    memcpy(CB.brand, string, strlen(string) * sizeof(char) + 1);
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

void convert(std::string&);

int main()
{
    using namespace std;

    string str;
    cout << "Enter a string (q to quit)：";
    while (getline(cin, str) && str != "q")
    {
        convert(str);
        cout << str << endl;
        cout << "Next string (q to quit)：";
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
//法二：
#if 0
void convert(std::string& shuju)
{
    for (int i = 0; i < shuju.size(); i++)
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
void set(stringy&, const char*);
void show(const stringy&, int num = 1);
void show(const char*, int num = 1);
//或写为：
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
void set(stringy& r_stringy, const char* p)
{
    r_stringy.str = new char[strlen(p) + 1];
    strcpy(r_stringy.str, p);

    r_stringy.ct = strlen(p);
}
void show(const stringy& r_stringy, int num)
{
    if (num < 0)
        num = 1;

    while (num--)
        cout << r_stringy.str;
}
void show(const char* p, int num)
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
T max5(const T* p);

int main(void)
{
    using namespace std;

    int shuju1[5] = { 1,2,3,4,5 };
    double shuju2[5] = { 1.1,2.2,3.3,4.4,5.5 };

    cout << max5(shuju1) << endl;//隐式实例化
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
T maxn(const T* p, int num);

//template <>const char* maxn(const char** p, int num);//显式具体化
//报错：
//没有与指定类型匹配的函数模板maxn实例

//***注1***
//可行的显式具体化：
//template <>char maxn(const char* p,int num);
//错误的显式具体化：
//template <>char* maxn(const char**p, int num);
//错误原因：T被解释为char*，但是函数的第一个参数为const char* *p，无法通过编译，因为const char* * 不是个类型名

//***注2***
//const char* maxn(const char** p, int num);此函数能完成预期目标，但这不是模板函数

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
//6.改进版本1
//***修改办法***光标移动到maxn(shuzu, 5)的maxn处，编译器会自动推断出 T 应解释为什么类型
//由此可以创建显式具体化
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

template <>const char* maxn<const char*>(const char* const* p, int num);

//***注1***
// T 被解释为const char*
//const char* const* p
//实质上是定义了一个指向字符串的二级指针，第二个const限制一级指针指向的内容不能修改，第一个的const限制二级指针指向的内容不能修改。
//https://blog.csdn.net/xc889078/article/details/8909498

//***注2***
//可行的显式具体化：
//template <>char maxn(const char* p,int num);
//错误的显式具体化：
//template <>char* maxn(const char**p, int num);
//错误原因：T被解释为char*，但是函数的第一个参数为const char* *p，无法通过编译，因为const char* * 不是个类型名

//***注3***
//const char* maxn(const char** p, int num);此函数能完成预期目标，但这不是模板函数

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
//6.改进版本2
#if 0
#include <cstring>
template <typename T>
const T maxn(const T* p, int num);

template <> const char* const maxn<const char*>(const char* const* p, int num);//显式具体化

//***注1***
// T 被解释为const char*
//const char* const* p
//实质上是定义了一个指向字符串的二级指针，第二个const限制一级指针指向的内容不能修改，第一个的const限制二级指针指向的内容不能修改。
//https://blog.csdn.net/xc889078/article/details/8909498

//***注2***
//可行的显式具体化：
//template <>char maxn(const char* p,int num);
//错误的显式具体化：
//template <>char* maxn(const char**p, int num);
//错误原因：T被解释为char*，但是函数的第一个参数为const char* *p，无法通过编译，因为const char* * 不是个类型名

//***注3***
//const char* maxn(const char** p, int num);此函数能完成预期目标，但这不是模板函数

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
        if (strlen(*(p + i)) > strlen(max))
            max = p[i];

    return max;
}
#endif
//6.改进版本3 使用string对象
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

template <>  std::string maxn<std::string>(const std::string* p, int num);//显式具体化

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    string shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;//实参：第一行整个string对象的地址

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
//6.版本4  使用string对象，但仍用处理C风格字符串的字符串处理函数
//但无法通过编译
#if 0
#include <cstring>
template <typename T>
T maxn(T* p, int num);

template <>  char* maxn(char**, int num);//显式具体化

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    string shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;//实参：第一行整个string对象的地址

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
template <typename T>            // template A 假设实参是数组名称，即指向数组首元素的指针
void ShowArray(T arr[], int n);

template <typename T>            // template B 假设实参是指向一个指针数组首元素的指针
void ShowArray(T** arr, int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T** arr, int n);

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
    cout << SumArray(things, 6) << endl;
    //************************************************************************

    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double* pd[3];//声明一个指针数组
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;//对指针数组的每个元素(即每个指针)赋值，赋的是结构的成员amount的地址

    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
    cout << SumArray(pd, 3) << endl;
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
    T sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

template <typename T>
T SumArray(T** arr, int n)
{
    T sum = 0;

    for (int i = 0; i < n; i++)
        sum += *arr[i];

    return sum;
}
#endif
#endif


/********************************************************************************以下是含多文件的程序*****************************************************************************************************************************************************************************************/
//chapter 9
//code1.cpp
//程序清单9.1 使用头文件
//链接cxqd9.1.cpp
#if 1
#include "cxqd9.1.h" // structure templates, function prototypes
using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)  // slick use of cin
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    // keep window open in MSVC++
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单9.4 自动变量只在包含它们的函数或代码块中可见
#if 0
void oil(int x);

int main()
{
    using namespace std;

    int texas = 31;
    int year = 2011;
    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;
    // cin.get();
    return 0;
}

void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In oil(), x = " << x << ", &x = ";
    cout << &x << endl;

    {                               // start a block
        int texas = 113;
        cout << "In block, texas = " << texas;
        cout << ", &texas = " << &texas << endl;
        cout << "In block, x = " << x << ", &x = ";
        cout << &x << endl;
    }                               // end a block

    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}
#endif


//程序清单9.5 外部链接的静态变量
//链接cxqd9.5.cpp
#if 0
// external variable
double warming = 0.3;       // warming defined

// function prototypes
void update(double dt);
void local();

int main()                  // uses global variable
{
    using namespace std;

    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);            // call function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local();                // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";
    // cin.get();
    return 0;
}
#endif


//程序清单9.6 内部链接的静态变量可以隐藏(覆盖)外部链接的静态变量
//链接cxqd9.6.cpp
#if 0
int tom = 3;            // external variable definition
int dick = 30;          // external variable definition
static int harry = 300; // static, internal linkage

// function prototype
void remote_access();

int main()
{
    using namespace std;

    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();

    // cin.get();
    return 0;
}
#endif


//程序清单9.9 使用无链接的静态变量
#if 0
// constants
const int ArSize = 10;

// function prototype
void strcount(const char* str);

int main()
{
    using namespace std;

    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);          //读取换行符，或数据长度过长时读取余下的第一个字符
        while (next != '\n')    //丢弃余下字符
            cin.get(next);

        strcount(input);

        cout << "Enter next line (empty line to quit):\n";//***注***当get()读取空行后将设置失效位
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    // code to keep window open for MSVC++
    /*
    cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}

void strcount(const char* str)
{
    using namespace std;

    static int total = 0;        // static local variable 只会在第一次调用函数时进行初始化

    cout << "\"" << str << "\" contains ";

    int count = 0;               // automatic local variable
    while (*str++)               // go to end of string
        count++;

    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}
#endif


//程序清单9.10 new运算符的变体——定位new运算符
#if 0
#include <new> // for placement new 定位new运算符的原型

const int LSIZE = 512;
char buffer[LSIZE];      // chunk of memory 存储在一块用于存储静态变量的内存中

const int SIZE = 5;

int main()
{
    using namespace std;

    double* pd1, * pd2;
    int i;

    cout << "Calling new and placement new:\n";
    pd1 = new double[SIZE];                // use heap 
                                                              //从堆中分配到满足要求的内存块
    pd2 = new (buffer) double[SIZE];  // use buffer array 
                                                              //从buffer数组中分配空间给
                                                              //一个包含SIZE个元素的double数组
    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;

    cout << "Memory addresses:\n"
        << "(pd1)heap: " << pd1 << endl
        << "   buffer: " << (void*)buffer << endl//强制类型转换，使cout显示地址而不是字符串
        << "      pd2: " << pd2
        << endl;

    cout << "Memory contents:\n";
    cout << "pd1指向的数组               pd2指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double* pd3, * pd4;
    pd3 = new double[SIZE];                // find new address
                                                              //从堆中分配到满足要求的新的内存块
    pd4 = new (buffer) double[SIZE];  // overwrite old data
                                                              //再次从buffer数组中分配空间给
                                                              //一个包含SIZE个元素的double数组
    for (i = 0; i < SIZE; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;

    cout << "Memory contents:\n";
    cout << "pd3指向的数组             pd4指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;                                    //释放pd1指向的内存块，但不会删除pd1指针本身
    pd1 = new double[SIZE];                //从堆中分配到满足要求的新的内存块
    pd2 = new (buffer + SIZE * sizeof(double)) double[SIZE];
    //再次从buffer数组中分配空间给
    //一个包含SIZE个元素的double数组
    //***注***
    //定位到从buffer开头位置算起，偏移量为SIZE * sizeof(double)的位置
    //SIZE * sizeof(double)等于40字节，用十六进制表示是0x28

    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;

    cout << "Memory contents:\n";
    cout << "pd1指向的数组             pd2指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete[] pd1;
    delete[] pd3;

    //***注***
    //不能加上delete[] pd2; 或  delete[] pd4;
   //程序会崩溃，因为buffer在存储静态变量的内存中，而不是用new分配的堆中

    return 0;
}
#endif


//程序清单9.13 名称空间的特性
//链接cxqd9.12.cpp
#if 0
#include <iostream>
//#include "D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 9\code1\Project1\Project1\cxqd9.13.h"
//或写为
#include "cxqd9.13.h"

void other(void);
void another(void);

int main(void)
{
    using debts::Debt;
    using debts::showDebt;//要使用名称空间中的函数，也只需给出名称
    Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
    showDebt(golf);

    other();
    another();
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;//using编译指令具有可传递性，
                                             //所以此语句可导入名称空间debts和名称空间pers

    Person dg = { "Doodles", "Glister" };
    showPerson(dg);
    cout << endl;

    Debt zippy[3];//创建一个结构数组
    int i;

    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);

    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);

    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;

    return;
}

void another(void)
{
    using pers::Person;//使用using声明

    Person collector = { "Milo", "Rightshift" };

    pers::showPerson(collector);//使用作用域解析运算符::
    std::cout << std::endl;
}
#endif


//chapter 9
//code2.cpp
//9.5复习题
//3.
#if 0
int main()
{
    double x;
    std::cout << "Enter value:  ";
    while (!(std::cin >> x))
    {
        std::cout << "Bad input. Please enter a number:  ";
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << "Value = " << x << std::endl;

    return 0;
}
#endif


//4.
#if 0
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x;
    cout << "Enter value:  ";
    while (!(cin >> x))
    {
        cout << "Bad input. Please enter a number:  ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    cout << "Value = " << x << endl;

    return 0;
}
#endif


//chapter 9
//code3.cpp
//9.6编程练习
//1.
//链接9.6.1.cpp
#if 0
#include "9.6.1.h"
#include <new>
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "请输入要填充的结构数量：";
    int count;
    while (!(cin >> count))
    {
        cout << "Bad input. Please enter a number:  ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    cin.get();
    //struct golf golf_structure[count];//错误：count不能是变量
    //解决法1：
    /*const int c_count = count;
    struct golf golf_structure[c_count];*/  //此方法不行，c_count还是视为变量

    //正确方法：
    struct golf* p_golfstructure = new golf[count];

    int biaoji = 1;
    int i;
    for (i = 0; i < count; i++)
    {
        cout << "请输入第" << i + 1 << "个结构的内容" << endl;
        biaoji = setgolf(*(p_golfstructure + i));

        if (!biaoji)
            break;
    }
    //***重置count的值，用以代表结构数量的值***
    count = i;

    cout << "要修改结构数组中的handicap成员的值吗？(输入y或n)";
    char answer;
    while (cin.get(answer))
    {
        while (cin.get() != '\n')
            continue;
        answer = tolower(answer);

        if (strchr("yn", answer) == NULL)
            cout << "请输入y或n : ";
        else
            break;
    }

    if (answer == 'y')
    {
        cout << "请输入要修改的数组的索引值：";
        int num;
        while (!(cin >> num))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cout << "请输入要修改的数组的handicap的值：";
        int handicap_num;
        while (!(cin >> handicap_num))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cin.get();

        handicap(*(p_golfstructure + num), handicap_num);
        cout << "第" << num + 1 << "个结构修改完成！" << endl;
    }

    cout << "\n数据如下：" << endl;
    for (int i = 0; i < count; i++)
    {
        showgolf(*(p_golfstructure + i));
    }

    return 0;
}
#endif


//2.
#if 0
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string str);

int main()
{
    using namespace std;

    string input;
    cout << "Enter a line:\n";
    getline(cin, input);

    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";//***注***当get()读取空行后将设置失效位
        getline(cin, input);
    }
    cout << "Bye\n";

    return 0;
}

void strcount(const std::string str)
{
    using namespace std;

    static int total = 0;        // static local variable 只会在第一次调用函数时进行初始化

    cout << "\"" << str << "\" contains ";

    int count = 0;               // automatic local variable
    //while (str[count])               // go to end of string
    //	count++;

    //法二：
    count = str.size();/*  count=str.length();  */

    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}
#endif


//3.
#if 0
#include <new>
#define SIZE 50
struct chaff
{
    char dross[20];
    int slag;
};

char buffer[SIZE];

int main()
{
    using std::cout;

    struct chaff* p = new (buffer)struct chaff[2];

    const char* data = "abcdefg";
    strcpy(p->dross, data);
    p->slag = 1;
    strcpy((p + 1)->dross, data);
    (p + 1)->slag = 2;

    for (int i = 0; i < 2; i++)
    {
        cout << (p + i)->dross << "\t";
        cout << (p + i)->slag << std::endl;
    }

    delete[]p;

    return 0;
}
#endif


//4.
//链接9.6.4.cpp
#if 0
#include "9.6.4.h"

int main()
{
    using SALES::Sales;
    using SALES::setSales;

    Sales Sales_Structure[2];

    setSales(Sales_Structure[0]);

    double data[2]{ 1.1,2.2 };
    setSales(Sales_Structure[1], data, 2);

    SALES::showSales(Sales_Structure[0]);
    showSales(Sales_Structure[1]);

    return 0;
}
#endif


//chapter 10
//code1.cpp
//程序清单10.3 声明一个类对象，使用类方法
//链接cxqd10.2.cpp
#if 0
#include "cxqd10.1.h"

int main()
{
    Stock   fluffy_the_cat;

    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    // std::cin.get();
    return 0;
}
#endif


//程序清单10.6 构造函数和析构函数以及C++11的列表初始化用于类
//链接cxqd10.5.cpp
#if 0
#include "cxqd10.4.h"

int main()
{
    {//此对大括号提供了一个代码块，使得stock1,stock2,stock3等这些自动变量
     //将在程序运行至代码块外时消失，执行析构函数可以被观察到
     //否则将在main()块结束时(程序结束时)调用析构函数，但在窗口环境下无法直观观察到
        using std::cout;
        cout << "Using constructors to create new objects\n";
        //隐式调用构造函数
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();

        //显式调用构造函数
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();

        //可以将一个对象的内容赋给另一个
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        //使用构造函数重置对象的内容(显式调用构造函数)
        //构造函数除了用来初始化对象，也可以用来给对象赋值
        cout << "Using a constructor to reset an object\n";
        //***注***
        //构造函数创建一个临时对象，将其赋值给stock1后调用析构函数删除临时对象
        stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
        cout << "Revised stock1:\n";
        stock1.show();

        //隐式调用默认构造函数
        Stock stock3;
        stock3.show();

        //C++11的列表初始化用于类
        Stock stock4 = { "abc def",20,20.0 };//显式调用构造函数
        stock4.show();
        Stock stock5 = {};//隐式调用构造函数
        stock5.show();

        cout << "Done\n";
    }

    return 0;
}
#endif


//程序清单10.9 对象数组，this指针
//链接cxqd10.8
#if 0
#include "cxqd10.7.h"

const int STKS = 4;
int main()
{
    {
        // create an array of initialized objects
        Stock stocks[STKS] =
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
        };

        std::cout << "Stock holdings:\n";
        int i;
        for (i = 0; i < STKS; i++)
            stocks[i].show();

        // set pointer to first element 声明并初始化一个指向Stock类对象的指针top
        const Stock* top = &stocks[0];
        for (i = 1; i < STKS; i++)
            top = &(top->topval(stocks[i]));//指针也可以用->来访问对象的方法成员

        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        top->show();

        putchar('\n');
        int shares = stocks[0].fanhui_shares();
        //***注***声明为const的值不能赋给非const数据，
        //但是若const数据是作为返回值返回的，则其先被复制入临时存储单元，临时存储单元的内容
        //在被复制入shares变量中，所以除去返回引用的情况外，传统返回值有无const无伤大雅
        std::cout << shares << std::endl;
    }

    // std::cin.get();
    return 0;
}
#endif


//程序清单10.12 使用ADT——栈
//链接cxqd10.11.cpp
#if 0
#include <cctype>  // or ctype.h
#include "cxqd10.10.h"

int main()
{
    using namespace std;

    Stack st; // create an empty stack (隐式调用默认构造函数进行隐式初始化)

    unsigned long data;
    cout << "Please enter A to add a purchase order,"
        << "P to delete, or Q to quit.\n";
    char ch;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a number to add: ";
            while (!(cin >> data))
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "请输入数字：";
            }
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(data);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(data);//弹出栈的值会赋给data
                cout << "栈顶成员 ：" << data << " popped\n";
            }
            break;
        }
        cout << "Please enter A to add a purchase order,"
            << "P to delete, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
#endif


//chapter 10
//code2.cpp
//10.9 复习题
//第5.第7.第9.题
#if 1
#endif


//chapter 10
//code3.cpp
//10.10 编程练习
//1.
//链接10.10.1.cpp
#if 0
#include "10.10.1.h"
int main()
{
    using namespace std;

    cout << "声明并初始化account1(隐式调用默认构造函数)\n";
    Account account1;
    account1.show();

    cout << "声明并初始化account2(隐式调用构造函数)\n";
    Account account2("Xiao Min", "123456789876");
    account2.show();

    cout << "小明存入10块钱后\n";
    account2.deposit(10);
    account2.show();

    cout << "小明取出5块钱后\n";
    account2.draw(5);
    account2.show();

    cout << "Done !\n";

    return 0;
}
#endif


//2.
//链接10.10.2.cpp
#if 0
#include "10.10.2.h"

int main()
{
    using namespace std;

    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

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
//链接10.10.3.cpp
#if 0
#include "10.10.3.h"
int main()
{
    Golf golf1("Xiao min", 1);
    golf1.showgolf();
    golf1.handicap(0);
    golf1.showgolf();

    Golf golf2;
    golf2.showgolf();

    return 0;
}
#endif


//4.
//链接10.10.4.cpp
#if 0
#include "10.10.4.h"
int main()
{
    using namespace SALES;

    double data[1] = { 1.1 };
    Sales sales1(data, 1);
    sales1.ShowSales();

    Sales sales2;
    sales2.ShowSales();

    return 0;
}
#endif


//5.
//链接10.10.5.cpp
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
    char ch = get_choice();

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
    cout << "请输入各项功能对应的字母：";
    cout << "\na) 添加顾客" << '\t' << "b) 删除顾客\n";
    cout << "c) 退出\n";
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
            cout << "\a请输a、b或c : ";
        else
            break;
    }
    return answer;
}
void fill_stack(Stack& st)
{
    if (st.isfull())
    {
        cout << "栈已满！";
        return;
    }

    Item item;
    cout << "请输入顾客的名字：";
    char temp[35];
    double money = 0.0;
    while (cin.get(temp, 34))//get()读取空行后会设置失效位   ***注***不能写成	while (cin.get(temp, 34).get())
    {
        cout << "请输入顾客付款额：";
        while (!(cin >> money))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cin.get();

        strcpy(item.fullname, temp);
        item.payment = money;
        st.push(item);
        cout << "请输入顾客的名字：(只输入Enter以停止)";
    }

    cin.clear();//***注***此句必写
    cin.get();//消耗掉换行符(即清空缓冲区的数据)
}
void delete_item(Stack& st)
{
    if (st.isempty())
    {
        cout << "栈为空！";
        return;
    }

    Item item;
    st.pop(item);

    cout << "栈顶成员 ：" << item.fullname << '\t'
        << item.payment << " popped\n";

    static double sum = 0.0;
    sum += item.payment;

    cout << "共计" << sum << "元\n\n";
}
#endif


//6.
//链接10.10.6.cpp
#if 0
#include "10.10.6.h"

int main()
{
    Move move;
    move.showmove();

    Move temp(1, 1);
    move = move.add(temp);//给类对象赋值
    move.showmove();

    move.rest();
    move.showmove();

    return 0;
}
#endif


//7.
//链接10.10.7.cpp
#if 0
#include "10.10.7.h"

int main()
{
    BetelPlorg b1;
    b1.show();

    BetelPlorg b2("Xiao min", 20);
    b2.show();

    b2.modification(80);
    b2.show();

    return 0;
}
#endif


//8.(类型：链表，实现形式：链式结构)
//链接10.10.8.cpp
#if 0
#include "10.10.8.h"
void showmovies(Item& item);

char* s_gets(char* string, int num);

int main(void)
{
    List movies;//创建一个类对象movies(隐式调用默认构造函数进行隐式初始化)

    Item temp;//创建一个film结构布局的结构temp

//初始化链表的头指针
//InitializeList(&movies);
    if (movies.ListIsFull())
    {
        fprintf(stderr, "错误，链表数量已达到最大值！");
        exit(1);
    }

    //获取用户输入并存储
    puts("请输入电影的标题：");
    while (s_gets(temp.title, LENGTH) != NULL && temp.title[0] != '\0')
    {
        puts("请输入您的评分(0-10)：");
        scanf("%d", &temp.rating);

        while (getchar() != '\n')
            continue;

        if (movies.AddItem(temp) == false)
        {
            fprintf(stderr, "错误，分配内存失败！");
            break;
        }
        if (movies.ListIsFull())
        {
            puts("链表数量已达到最大值！");
            break;
        }

        puts("请输入下一个电影的标题(输入^Z或空行以退出)：");
    }

    //显示
    if (movies.ListIsEmpty())
        printf("没有数据输入！\n");
    else
    {
        printf("以下是电影目录\n");
        movies.Visit(showmovies);
    }
    printf("你输入了%d部电影\n", movies.ListItemCount());

    //清理
    movies.EmptyTheList();
    printf("再见！\n");

    return 0;
}
void showmovies(Item& item)
{
    printf("电影名:%-20s电影评分:%d\n", item.title, item.rating);
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


//8.法二(类型：栈，实现形式：数组)
//头文件与栈类似


//chapter 11
//code1.cpp
//程序清单11.3 不使用运算符重载，实现计算时间的程序
//链接cxqd11.2.cpp
#if 0
#include "cxqd11.1.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();

    cout << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单11.6 使用运算符重载，实现计算时间的程序
//链接cxqd11.5.cpp
#if 0
#include "cxqd11.4.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time morefixing(3, 28);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // operator notation 法一：使用运算符表示法
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    // function notation 法二：使用operator+()方法
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    // std::cin.get();
    return 0;
}
#endif


//程序清单11.9 使用其他重载运算符(+-*)，实现计算时间的程序
//链接cxqd11.8.cpp
#if 0
#include "cxqd11.7.h"

int main()
{
    using std::cout;
    using std::endl;

    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;   // use operator+()
    total.Show();
    cout << endl;

    diff = weeding - waxing;    // use operator-()
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;      // use operator*()
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;
    // std::cin.get();    
    return 0;
}
#endif


//程序清单11.12 使用友元函数(用于处理第一个操作数不是类对象的情况)
//链接cxqd11.11.cpp
#if 0
#include "cxqd11.10.h"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;

    //使用重载运算符函数operator+()
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    //使用重载运算符函数operator*()
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;

    //使用ostream类的operator<<()重载运算符函数
    cout << "10.0 * Tosca: "
        //使用Time类的operator*()友元函数，
        //然后使用Time类的operator<<()友元函数
        << 10.0 * tosca
        //使用ostream类的operator<<()重载运算符函数
        << endl;

    return 0;
}
#endif


//程序清单11.15 使用Vector类模拟随机漫步问题
//链接cxqd11.14.cpp
#if 0
#include "cxqd11.13.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        while (result.magval() < target_distance)
        {
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
            steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单11.18 使用转换函数——只接受一个参数的构造函数
//实现类的自动转换和强制类型转换(基本类型到类类型的转换)
//实现计重方法转换程序
//链接cxqd11.17.cpp
#if 0
#include "cxqd11.16.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
    //初始化写法一：
    //显式调用构造函数，也叫显式强制类型转换
    //Stonewt p1 = Stonewt (275); // uses constructor to initialize

    //初始化写法二：
    //隐式调用构造函数 
    //Stonewt p1(275);

    //初始化写法三：
    //自动类型转换，也叫隐式类型转换
    //使用构造函数作为转换函数，首先将275转换为275.0，
    //然后使用Stonewt(double pds)构造函数来初始化对象p1
    //将int类型的值转化为Stonewt类型
    Stonewt p1 = 275; // uses constructor to initialize

    //赋值写法：
    //Stonewt p1;
    //p1 = 275;

    Stonewt p2(285.7);    // same as Stonewt wolfe = 285.7;

    //此处理解：C++自动将传递的值转换为原型中指定的类型，
    //条件是两者都是算术类型(引用除外)
    //8被自动转换成8.0后再传入构造函数
    Stonewt p3(21, 8);

    cout << "The p1 weighed ";
    p1.show_stn();
    cout << "The p2 weighed ";
    p2.show_stn();
    cout << "The p3 weighed ";
    p3.show_pds();

    p1 = 276.8;          // uses constructor for conversion
    p3 = 325;             // same as p3 = Stonewt(325);

    cout << "After dinner, the p1 weighed ";
    p1.show_stn();

    cout << "After dinner, the p3 weighed ";
    p3.show_pds();

    display(p3, 2);

    cout << "The wrestler weighed even more.\n";
    //***注***
    //422转换为422.0，然后使用Stonewt(double pds)构造函数
    //生成一个临时Stonewt对象，传入display()
    display(422, 2);

    //cout << "No stone left unearned\n";//没有什么是不劳而获的
    // std::cin.get();
    return 0;
}

void display(const Stonewt& st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}
#endif


//程序清单11.21 使用转换函数——特殊的C++运算符函数
//实现类类型到基本类型的转换
//链接cxqd11.20.cpp
#if 0
#include "cxqd11.19.h"

int main()
{
    using std::cout;

    Stonewt poppins(9, 2.8);     // 9 stone, 2.8 pounds

    //隐式类型转换
    double p_wt = poppins;      // implicit conversion

    //显式强制类型转换
    //double p_wt = double(poppins); 

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";
    // std::cin.get();
    return 0;
}
#endif


//chapter 11
//code2.cpp
//11.8 复习题
//1.
//链接11.8.1.cpp
#if 0
#include "11.8.1.h"
int main()
{
    using std::cout;
    using std::endl;

    Stonewt w1(10, 8);

    Stonewt w2 = 2 * w1;

    cout << double(w2) << "磅，相当于";//使用显式强制类型转换

    w2.show_stn();

    return 0;
}
#endif


//7.
//链接11.8.7.cpp
#if 0
#include "11.8.7.h"
int main()
{
    using namespace VECTOR;
    using namespace std;

    Vector v1(1, 1);

    double length = double(v1);

    cout << length << endl;

    return 0;
}
#endif


//chapter 11
//code3.cpp
//11.9 编程练习
//1.
//链接11.9.1.cpp
#if 0
#include "11.9.1.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    /*
    //若要向文件写入内容，则可有选择地把后面的out改为fout
    ofstream fout;
    fout.open("randwalk.txt");
    */

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        cout << "Target Distance : " << target_distance
            << ", Step Size : " << step_size << endl;

        while (result.magval() < target_distance)
        {
            if (steps == 0)
                cout << "0 : (x,y) = (0,0)" << endl;

            steps++;
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
                                                 //所以临时对象赋给result对象后，result对象为RECT模式
            cout << steps << " : (x,y) = " << "(" << result.xval() << ","
                << result.yval() << ")" << endl;
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//2.
//链接11.9.2.cpp
#if 0
#include "11.9.2.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        while (result.magval() < target_distance)
        {
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
            steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//3.
//链接11.9.3.cpp
#if 0
#include "11.9.3.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

void show_average(double*, int);

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit) :  ";
    double target_distance;
    double step_size;
    int num;
    double* p_data = (double*)0;//***注***此处必须先对指针初始化
                                                    //将指针设置为地址0    (书P335)
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        cout << "请输入测试次数：";
        cin >> num;
        p_data = new double[num];//动态分配内存

        for (int i = 0; i < num; i++)
        {
            while (result.magval() < target_distance)
            {
                //设置向随机角度的方向行走
                direction = rand() % 360;

                //注，只写POL，编译器会报错
                //可写成VECTOR::Vector::POL, 或写成Vector::POL
                step.reset(step_size, direction, Vector::POL);

                result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                     //而构造函数的参数form的默认值为RECT
                steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
            }

            /*cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
            cout << result << endl;

            result.polar_mode();
            cout << " or\n" << result << endl;*/

            *(p_data + i) = result.magval() / steps;
            cout << "Average outward distance per step = "
                << result.magval() / steps << endl << endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }

        show_average(p_data, num);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";

    delete[]p_data;
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}

void show_average(double* p, int n)
{
    using std::cout;
    using std::endl;

    double min, max, sum = 0.0;
    min = max = *p;

    for (int i = 0; i < n; i++)
    {
        *(p + i) > max ? max = *(p + i) : 1;
        *(p + i) < min ? min = *(p + i) : 1;
        sum += *(p + i);
    }

    cout.put('\n');
    cout << n << "次测试中：\n最高平均步数：" << max
        << "\n最低平均步数：" << min << endl
        << n << "次测试的平均步数：" << sum / n << endl << endl;
}
#endif


//4.
//链接11.9.4.cpp
#if 0
#include "11.9.4.h"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;

    //使用重载运算符函数operator+()
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    //使用重载运算符函数operator*()
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;

    //使用ostream类的operator<<()重载运算符函数
    cout << "10.0 * Tosca: "
        //使用Time类的operator*()友元函数，
        //然后使用Time类的operator<<()友元函数
        << 10.0 * tosca
        //使用ostream类的operator<<()重载运算符函数
        << endl;

    return 0;
}
#endif


//5.
//链接11.9.5.cpp
#if 0
#include "11.9.5.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
    //使用默认构造函数
    Stonewt p0;
    cout << "The p0 weighed ";
    cout << p0;

    //使用构造函数的类型转换功能；form为FLOAT_POUNDS
    Stonewt p1 = 100.1;
    cout << "The p1 weighed ";
    cout << p1;

    //使用构造函数的类型转换功能；form为INTEGER_POUNDS
    Stonewt p2(200.6, Stonewt::INTEGER_POUNDS);//使用作用域为类的明示常量
    cout << "The p2 weighed ";
    cout << p2;

    //使用构造函数第二个版本；form为STONE
    //此处理解：C++自动将传递的值转换为原型中指定的类型，
    //条件是两者都是算术类型(引用除外)
    //8被自动转换成8.0后再传入构造函数
    Stonewt p3(21, 8);
    cout << "The p3 weighed ";
    cout << p3;

    //使用构造函数的类型转换和赋值功能
    p1 = 150.8;          // uses constructor for conversion
    cout << "After the change the p1 weighed ";
    cout << p1;

    Stonewt temp;
    temp = p1 + p2;
    cout << "p1+p2=" << temp;

    temp = p2 - p1;
    cout << "p2-p1=" << temp;

    temp = -p1;
    cout << "-p1=" << temp;

    temp = p1 * 2;
    cout << "p1*2=" << temp;

    temp = 2 * p1;
    cout << "2*p1=" << temp;

    cout << "The wrestler weighed even more.\n";
    //***注***
    //422转换为422.0，然后使用Stonewt(double pds,Mode form= FLOAT_POUNDS)构造函数
    //生成一个临时Stonewt对象，传入display()
    display(422, 2);

    //若输入的模式不正确
    Stonewt p4(1.5, Stonewt::STONE);
    cout << p4;
    Stonewt p5(1, 5, Stonewt::FLOAT_POUNDS);
    cout << p5;

    return 0;
}

void display(const Stonewt& st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        cout << st;
    }
    cout.put('\n');
}
#endif


//6.
//链接11.9.6.cpp
#if 0
#include "11.9.6.h"

void show_report(const Stonewt* p, int num);

int main()
{
    //声明一个Stonewt类型的数组，并初始化前三个对象
    Stonewt array[6]
    {
    1.1,(2.2),Stonewt(3.3)
    };

    std::cout << "请输入第4~6个对象的pounds的值：";
    for (int index = 3; index < 6; index++)
    {
        while (!(std::cin >> array[index]))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "错误的输入内容！\n";
        }
    }

    show_report(array, 6);

    return 0;
}

void show_report(const Stonewt* p, int num)
{
    using std::cout;
    using std::endl;

    Stonewt stone11(11, 0);//即154pounds
    int count = 0;

    Stonewt min, max;
    min = max = *p;

    for (int i = 0; i < num; i++)
    {
        if (*(p + i) > max)
            max = *(p + i);
        if (*(p + i) < min)
            min = *(p + i);
        if (*(p + i) >= stone11)
            count++;
    }

    cout << "\n最小重量：" << min << endl
        << "最大重量：" << max << endl
        << "大于或等于11英石的数量：" << count << endl;
}
#endif


//7.
//链接11.9.7.cpp
#if 0
using namespace std;
#include "11.9.7.h"
int main()
{
    Complex a(3.0, 4.0);// initialize to(3,4i)
    Complex c;
    cout << "Enter a complex number (q to quit) : \n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is" << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done ! \n";
    return 0;
}
#endif


//chapter 12
//code1.cpp
//程序清单12.3 研究一个不完善的类
//链接12.2.cpp
#if 0
#include "cxqd12.1.h"
using std::cout;
using std::endl;

void callme1(StringBad&);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{
    {
        cout << "Starting an inner block.\n";
        StringBad s1("Celery Stalks at Midnight");
        StringBad s2("Lettuce Prey");
        StringBad s3("Spinach Leaves Bowl for Dollars");
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        cout << "s3: " << s3 << endl;

        //错误：只调用了默认的复制构造函数，进行了浅复制
        //导致静态成员不变
        callme1(s1);
        cout << "s1: " << s1 << endl;
        callme2(s2);
        cout << "s2: " << s2 << endl;

        cout << "Initialize one object to another:\n";
        //错误：只调用了默认的复制构造函数，进行了浅复制
        //导致静态成员不变，只是赋值了指针的值(这直接导致后面调用析构函数时会出现释放两次内存，其结果是不确定的)
        StringBad s4 = s1;
        cout << "s4: " << s4 << endl;

        cout << "Assign one object to another:\n";
        //错误：只调用了默认的赋值运算符重载函数，进行了浅复制
        //导致的后果与上述的一致
        StringBad s5;
        s5 = s1;
        cout << "s5: " << s5 << endl;

        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    // std::cin.get();
    return 0;
}

void callme1(StringBad& r_s)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << r_s << "\"\n";
}

void callme2(StringBad s)
{
    cout << "String passed by value:\n";
    cout << "    \"" << s << "\"\n";
}
#endif


//程序清单12.6 使用一个比较完善的String类，实现字符串的存储和比较
//链接cxqd12.5.cpp
#if 0
#include "cxqd12.4.h" 
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    {
        String name;
        cout << "Hi, what's your name?\n>> ";
        cin >> name;

        cout << name << ", please enter up to " << ArSize
            << " short sayings <empty line to quit>:\n";
        String sayings[ArSize];     // array of objects
        char temp[MaxLen];          // temporary string storage

        int i;
        for (i = 0; i < ArSize; i++)
        {
            cout << i + 1 << ": ";
            cin.get(temp, MaxLen);

            while (cin && cin.get() != '\n')//输入不为空行且没读取到换行符
                continue;

            if (!cin || temp[0] == '\0')    // empty line? ***注***temp[0]=='\0'，用于旧版实现，此处可不写
                break;              // i not incremented
            else
                sayings[i] = temp;  //使用赋值运算符重载函数的重载，进行字符串到对象的赋值
        }
        int total = i;              // total # of lines read

        if (total > 0)
        {
            cout << "Here are your sayings:\n";
            for (i = 0; i < total; i++)
                cout << sayings[i][0] << ": " << sayings[i] << endl;

            int shortest = 0;//创建索引
            int first = 0;
            for (i = 1; i < total; i++)
            {
                if (sayings[shortest].length() > sayings[i].length())//比较字符串长度
                    shortest = i;
                if (sayings[first] > sayings[i])//比较字符串首字母的顺序
                    first = i;
            }
            cout << "Shortest saying:\n" << sayings[shortest] << endl;;
            cout << "First alphabetically:\n" << sayings[first] << endl;
            cout << "This program used " << String::HowMany()
                << " String objects. Bye.\n";
        }
        else
            cout << "No input! Bye.\n";
        // keep window open 
        /*    if (!cin)
                cin.clear();
            while (cin.get() != '\n')
                continue; */
    }
    cin.clear();
    cin.get();

    return 0;
}
#endif


//程序清单12.7 使用指向对象的指针
//链接cxqd12.5.cpp
#if 0
#include "cxqd12.4.h"
#include <cstdlib>      // (or stdlib.h) for rand(), srand()
#include <ctime>        // (or time.h) for time()

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];               // temporary string storage

    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
            break;                   // i not incremented
        else
            sayings[i] = temp;       // overloaded assignment
    }
    int total = i;                   // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        //声明并初始化指向对象的指针
        // use pointers to keep track of shortest, first strings
        String* shortest = &sayings[0]; // initialize to first object
        String* first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (shortest->length() > sayings[i].length())
                shortest = &sayings[i];
            if (*first > sayings[i])        // compare values
                first = &sayings[i];     // assign address
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total; // pick index at random
        //使用对象来初始化新的String对象
        // use new to create, initialize new String object
        String* favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;//***注***此处仅delete对象，
                                 //因此第一步仅释放str指针和len成员的空间，
                                 //并不释放str指向的内存，
                                 //第二步才调用析构函数，释放str指向的内存
    }
    else
        cout << "Not much to say, eh?\n";
    cout << "Bye.\n";
    // keep window open
    /*    if (!cin)
            cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单12.8 使用定位new运算符，用于对象(有瑕疵)
//无链接的文件
#if 0
#include "cxqd12.8.h"
#include <new> //定位new的特性
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //使用默认构造函数创建匿名对象 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//使用构造函数初始化新创建的匿名对象
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" <<
        "pc1: " << pc1 << endl <<
        "buffer: " << (void*)buffer << endl <<//***注***若不写(void *)，则打印buffer上存的数据，由于buffer上存的是对象，无法直接打印出对象私有成员的内容，故打印的是乱码
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);//pc3指向的对象把pc1指向的对象覆盖了
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 调用析构函数        
    delete pc4;                          // free Heap2 调用析构函数
    delete[] buffer;                    // free buffer
    cout << "Done\n";             //***注***
    // std::cin.get();                   //执行delete[] buffer;后不会为定位new创建的对象调用析构函数
    return 0;                              //因为new/delete系统只知道已分配的512字节块buffer，而不知道定位new对这块内存作了何处理
}
#endif


//程序清单12.9 使用定位new运算符，用于对象(已修复问题)
//链接无
#if 0
#include "cxqd12.8.h"
#include <new> //定位new的特性
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //使用默认构造函数创建匿名对象 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//使用构造函数初始化新创建的匿名对象
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" <<
        "pc1: " << pc1 << endl <<
        "buffer: " << (void*)buffer << endl <<//***注***若不写(void *)，则打印buffer上存的数据，由于buffer上存的是对象，无法直接打印出对象私有成员的内容，故打印的是乱码
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer + sizeof(JustTesting))
        JustTesting("Better Idea", 6);//pc3指向的对象和pc1指向的对象，两个内存区域不重叠
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 调用析构函数        
    delete pc4;                          // free Heap2 调用析构函数

    //显式调用析构函数，与创建时相反的顺序删除对象
    // explicitly destroy placement new objects
    pc3->~JustTesting();  // destroy object pointed to by pc3
    pc1->~JustTesting();  // destroy object pointed to by pc1

    //所有对象都被销毁后，才能释放用于存储这些对象的存储区
    delete[] buffer;                    // free buffer

    return 0;
}
#endif


//程序清单12.12 
//链接cxqd12.11.cpp
#if 0
#include "cxqd12.10.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);                 //创建对象并用构造函数初始化
                                              // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;              //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line


// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // have newcomer
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.enqueue(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty())//当队列空闲且有节点时
        {
            line.dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
            wait_time = temp.ptime(); //wait_time即进行交易所花的时间

            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;//加入队列的人数
        cout << "  customers served: " << served << endl;//已服务完的人数
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}
#endif


//chapter 12
//code2.cpp
#if 0
int main()
{
    //const char a[]; 无效的声明，不能在函数体中声明指针时用[]
    //a = "abc";
}
#endif


//chapter 12
//code3.cpp
//12.10 编程练习
//1.
//链接12.10.1.cpp
#if 0
#include "12.10.1.h"

int main()
{
    using namespace std;

    Cow cow1;
    cow1.ShowCow();

    Cow cow2("abc", "programming", 70);//调用构造函数
    cow2.ShowCow();

    Cow cow3("def", "relaxing", 60);
    cow3.ShowCow();

    cow1 = cow2 = cow3;//调用赋值运算符重载函数
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    Cow cow4(cow3);//调用复制构造函数
    cow4.ShowCow();

    Cow cow5[2] = { {"ghj","aaa",50} };
    cow5[0].ShowCow();
    cow5[1].ShowCow();

    return 0;
}
#endif


//2.
//链接12.10.2.cpp
#if 0
using namespace std;
#include "12.10.2.h"

int main()
{
    String s2 = "Please enter your name: ";
    String s3;

    cout << s2; // overloaded << operator
    cin >> s3; // overloaded >> operator

    s2 = "My name is " + s3; // overloaded =,+ operators
    cout << s2 << ".\n";

    String s1(" and I am a C++ student.");
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase

    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";

    s1 = " red";  // String (const char *),
    String rgb[3] = { String(s1),String("green"),String("blue") };

    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again !\n";
    }
    cout << "Bye\n";
    return 0;
}
#endif


//3.
//链接12.10.3.cpp
#if 0
#include "12.10.3.h"

const int STKS = 4;
int main()
{
    {
        // create an array of initialized objects
        Stock stocks[STKS] =
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
        };

        std::cout << "Stock holdings:\n";
        int i;
        for (i = 0; i < STKS; i++)
            std::cout << stocks[i];

        // set pointer to first element 声明并初始化一个指向Stock类对象的指针top
        const Stock* top = &stocks[0];
        for (i = 1; i < STKS; i++)
            top = &(top->topval(stocks[i]));//指针也可以用->来访问对象的方法成员

        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        std::cout << *top;
    }

    // std::cin.get();
    return 0;
}
#endif


//4.
//链接12.10.4.cpp
#if 0
#include <cctype>  // or ctype.h
#include "12.10.4.h"

bool fill_data(Stack& s, Item& data);
void showdata(Item& item);

int main()
{
    using namespace std;

    Stack st(3);

    Item data;
    cout << "Please enter A to add a purchase order,"
        << "P to delete, S to show, or Q to quit.\n";
    char ch;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            if (!fill_data(st, data))
                cout << "stack already full\n";
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(data);//弹出栈的值会赋给data
                cout << "栈顶成员 ：" << data << " popped\n";
            }
            break;
        case 'S':
        case 's':
            st.traverse(showdata);
            break;
        }
        cout << "Please enter A to add a purchase order,"
            << "P to delete, S to show, or Q to quit.\n";
    }

    cout << "使用复制构造函数：" << endl;
    Stack st1(st);
    cout << "st1的内容是：";
    st1.traverse(showdata);

    cout << "使用赋值运算符重载函数：" << endl;
    Stack st2;
    st2 = st;
    cout << "st2的内容是：";
    st2.traverse(showdata);

    cout << "Bye\n";
    return 0;
}

bool fill_data(Stack& s, Item& data)
{
    if (s.isfull())
        return false;

    using std::cout;
    using std::cin;

    cout << "Enter a number to add: ";
    while (!(cin >> data))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "请输入数字：";
    }
    s.push(data);
    return true;
}
void showdata(Item& item)
{
    using std::cout;
    using std::endl;

    cout << item << "     ";
}
#endif


//5.
//链接12.10.5.cpp
#if 0
#include "12.10.5.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);                 //创建对象并用构造函数初始化
                                              // line queue holds up to qs people

    cout << "The number of simulation hours : 100小时\n";
    int hours = 100;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Calculating the average number of customers per hour: \n......\n";
    double perhour = 10;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line

    do {
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        //***注***每次模拟完成后，要对各参数归0
        turnaways = customers = served = sum_line\
            = wait_time = line_wait = 0;

        //***注***
        //错误：下次运行时队列的节点没有清空
        //改正：
        while (!line.isempty())
            line.dequeue(temp);

        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty())//当队列空闲且有节点时
            {
                line.dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
                wait_time = temp.ptime(); //wait_time即进行交易所花的时间

                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }

    } while (((double)line_wait / served) <= 1.0/*|| ((double)line_wait / served) >= 1.1*/);

    // reporting results
    if (customers > 0)
    {
        cout << "每小时到达的客户数：" << perhour << endl;
        cout << "customers accepted: " << customers << endl;//加入队列的人数
        cout << "  customers served: " << served << endl;//已服务完的人数
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}
#endif


//6.
//链接12.10.6.cpp
#if 0
#include "12.10.6.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Maximum size of queue: 10\n";
    //int qs;
    //cin >> qs;
    //Queue line(qs);                 //创建对象并用构造函数初始化
    //										  // line queue holds up to qs people
    Queue line[2];

    //***注***由于把赋值运算符重载函数放在了private，所以不能实现对象间赋值
    //line[0] = Queue(qs);

    cout << "The number of simulation hours : 100 小时\n";
    int hours = 100;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Calculating the average number of customers per hour: \n......\n";
    double perhour = 10;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间


    Item temp;              //***注***客户是一个，不能放到结构体中

    typedef struct			//存储两个队列的排队情况
    {
        long turnaways;     //  turned away by full queue
        long customers;     //  joined the queue
        long served;        //  served during the simulation
        long sum_line;      //  cumulative line length
        int wait_time;      //  time until autoteller is free
        long line_wait;     //  cumulative time in line
    }x;

    x x_struct[2];//***注***无法使用C的初始化器

    double temp1, temp2, result;

    do
    {
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        //***注***每次模拟完成后，要对各参数归0
        for (int i = 0; i < 2; i++)
        {
            x_struct[i].customers = x_struct[i].line_wait = x_struct[i].served
                = x_struct[i].sum_line = x_struct[i].turnaways
                = x_struct[i].wait_time = 0;
        }

        //***注***
        //错误：下次运行时队列的节点没有清空
        //改正：
        while (!line[0].isempty())
            line[0].dequeue(temp);

        while (!line[1].isempty())
            line[1].dequeue(temp);

        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line[0].isfull())
                    x_struct[0].turnaways++;

                if (line[1].isfull())
                    x_struct[1].turnaways++;

                if (!line[0].isfull() || !line[1].isfull())
                {
                    if (line[0].queuecount() <= line[1].queuecount())
                    {
                        x_struct[0].customers++;
                        temp.set(cycle);    // cycle = time of arrival
                        line[0].enqueue(temp); // add newcomer to line
                    }
                    else
                    {
                        x_struct[1].customers++;
                        temp.set(cycle);    // cycle = time of arrival
                        line[1].enqueue(temp); // add newcomer to line
                    }
                }
            }

            if (x_struct[0].wait_time <= 0 && (!line[0].isempty()))//当队列空闲且有节点时
            {
                line[0].dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
                x_struct[0].wait_time = temp.ptime(); //wait_time即进行交易所花的时间
                x_struct[0].line_wait += cycle - temp.when();
                x_struct[0].served++;
            }

            if (x_struct[1].wait_time <= 0 && (!line[1].isempty()))//当队列空闲且有节点时
            {
                line[1].dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
                x_struct[1].wait_time = temp.ptime(); //wait_time即进行交易所花的时间
                x_struct[1].line_wait += cycle - temp.when();
                x_struct[1].served++;
            }

            if (x_struct[0].wait_time > 0)
                x_struct[0].wait_time--;

            if (x_struct[1].wait_time > 0)
                x_struct[1].wait_time--;

            x_struct[0].sum_line += line[0].queuecount();
            x_struct[1].sum_line += line[1].queuecount();
        }

        temp1 = (double)x_struct[0].line_wait / x_struct[0].served;
        temp2 = (double)x_struct[1].line_wait / x_struct[1].served;

        result = (temp1 + temp2) / 2;

    } while (result <= 1.0);
    //(((double)x_struct[0].line_wait / x_struct[0].served) <= 1.0
    //	|| ((double)x_struct[0].line_wait / x_struct[0].served) >= 1.1)
    //	|| (((double)x_struct[1].line_wait / x_struct[1].served) <= 1.0
    //		|| ((double)x_struct[1].line_wait / x_struct[1].served) >= 1.1)

    // reporting results
    cout << "每小时到达的客户数：" << perhour << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "customers accepted: " << x_struct[i].customers << endl;//加入队列的人数
        cout << "  customers served: " << x_struct[i].served << endl;//已服务完的人数
        cout << "         turnaways: " << x_struct[i].turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)x_struct[i].sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)x_struct[i].line_wait / x_struct[i].served << " minutes\n";
    }

    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}
#endif


//chapter 13
//code1.cpp
//程序清单13.3 使用一个简单的基类
//链接cxqd13.2.cpp
#if 0
#include "cxqd13.1.h"

int main(void)
{
    using std::cout;

    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单13.6 使用派生类，演示派生类和基类的关系
//链接cxqd13.5.cpp 
#if 0
#include "cxqd13.4.h"

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    player1.Name();           // 基类对象使用基类的方法
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";

    //声明并初始化派生类对象
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();          // 派生类对象使用基类的方法
    //写法二：
    //rplayer1.TableTennisPlayer::Name();

    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    //使用基类对象初始化派生类对象
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    RatedPlayer rplayer3(333, "Aaa", "Bbb", true);
    TableTennisPlayer player3(rplayer3);//使用派生类对象初始化基类对象
    player3.Name();
    cout.put('\n');

    RatedPlayer rplayer4(444, "Ccc", "Ddd", true);
    TableTennisPlayer player4;//使用派生类对象赋值给基类对象
    player4 = rplayer4;
    player4.Name();
    cout.put('\n');

    // std::cin.get();
    return 0;
}
#endif


//程序清单13.9 测试含虚函数的基类和派生类(但不使用虚方法的特性)
//链接cxqd13.8.cpp
#if 0
#include "cxqd13.7.h"

void fv(BrassPlus b)
{
    b.ViewAcct();
}

void fv_1(Brass* pb)
{
    pb->ViewAcct();
}

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl << endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);//使用Brass类的Withdraw方法，不支持透支
    cout << "Pigg account balance: $" << Piggy.Balance() << endl << endl;

    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);//使用BrassPlus类的Withdraw方法，支持透支
    Hoggy.ViewAcct();
    // std::cin.get();
    cout.put('\n');
    fv(Piggy);//Brass对象传递给BrassPlus类型的形参的函数，会先调用派生类构造函数进行类型转换，再使用fv()函数
    cout.put('\n');
    fv_1(&Hoggy);

    return 0;
}
#endif


//程序清单13.10 类的多态(同一个方法在派生类和基类中的行为不同)——虚函数
//链接cxqd13.8.cpp
#if 0
#include "cxqd13.7.h"
#include <string>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass* p_clients[CLIENTS];//声明一个数组，每个元素都是指向Brass类的指针
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";

        while (!(cin >> kind) || (kind != '1' && kind != '2'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                tmax, trate);
        }
        while (cin.get() != '\n')//消耗掉换行符，否则getline()将读取不到第二次及之后的输入
            continue;
    }

    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}
#endif


//程序清单13.13 关键字protected，纯虚函数，抽象基类ABC
//链接cxqd13.12.cpp
#if 0
#include <string>
#include "cxqd13.11.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC* p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                tmax, trate);
        }

        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    // cin.get();
    return 0;
}

#endif


//程序清单13.16 派生类使用动态内存分配和派生类如何访问基类的友元函数
//链接cxqd13.15.cpp
#if 0
#include "cxqd13.14.h"

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;

    lacksDMA balloon("red", "Blimpo", 4);
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;

    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;

    lacksDMA balloon2(balloon);//使用默认的复制构造函数
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;//使用显式的赋值运算符重载函数
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    // std::cin.get();
    return 0;
}
#endif


//chapter 13
//code2.cpp
//13.10 复习题
//14.
//链接无
#if 0
int main()
{


    return 0;
}
#endif


//chapter 13
//code3.cpp
//13.11 编程练习
//1.
//链接13.11.1.cpp
#if 0
#include "13.11.1.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Using object directly:\n";
    c1.Report();// use Cd method
    c2.Report(); ;// use Classic method
    cout << endl;

    cout << "Using type cd * pointer to objects:\n";
    Cd* pcd = &c1;
    pcd->Report();// use Cd method for cd object
    pcd = &c2;
    pcd->Report();// use Classic method for classic object
    cout << endl;

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy.Report();
    copy = c2;
    copy.Report();

    return 0;
}
void Bravo(const Cd& disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
    disk.Report();
}
#endif


//2.
//链接13.11.2.cpp
#if 0
#include "13.11.2.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Using object directly:\n";
    c1.Report();// use Cd method
    c2.Report(); ;// use Classic method
    cout << endl;

    cout << "Using type cd * pointer to objects:\n";
    Cd* pcd = &c1;
    pcd->Report();// use Cd method for cd object
    pcd = &c2;
    pcd->Report();// use Classic method for classic object
    cout << endl;

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy.Report();
    copy = c2;
    copy.Report();

    return 0;
}
void Bravo(const Cd& disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
    disk.Report();
}
#endif


//3.
//链接13.11.3.cpp
#if 0
#include "13.11.3.h"

const int SIZE = 3;
char* getlabel(void);        //对字符串所占的内存进行动态分配

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DmaABC* p_dma[SIZE];//声明一个数组，每个元素都是指向抽象基类的指针
    char* p_label_data;
    int rating;
    char kind;
    char color_data[40];
    char style[40];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the label name: ";
        p_label_data = getlabel();
        cout << "Enter the number of rating: ";
        cin >> rating;

        cout << "Enter 1 for baseDMA or "
            << "2 for lacksDMA or " << "3 for hasDMA:";

        while (!(cin >> kind) || (kind != '1' && kind != '2' && kind != '3'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 or 3 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        cin.get();//消耗掉换行符

        if (kind == '1')
            p_dma[i] = new baseDMA(p_label_data, rating);
        else if (kind == '2')
        {
            cout << "Enter the color: ";
            cin.getline(color_data, 40);
            p_dma[i] = new lacksDMA(color_data, p_label_data, rating);
        }
        else
        {
            cout << "Enter the style: ";
            cin.getline(style, 40);
            p_dma[i] = new hasDMA(style, p_label_data, rating);
        }

        delete p_label_data;
        //while (cin.get() != '\n')//消耗掉换行符，否则getline()将读取不到第二次及之后的输入
        //    continue;//不需要，因为getline会把换行符替换成'\0'
    }

    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete p_dma[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}

char* getlabel(void)        // return pointer to new string
{
    using std::cout;
    using std::cin;

    char temp[80];      // temporary storage 块作用域，无链接，自动存储期

    cin >> temp;        //temp数组暂存输入的内容

    char* pn = new char[strlen(temp) + 1];//计算输入的字符数量并动态分配一个内存空间

    strcpy(pn, temp); // copy string into smaller space 
                                 //***注***strcpy()检测到temp中的'\0'后把'\0'也拷贝入pn指向的内存空间的相应位置，然后停止拷贝
    return pn;          // temp lost when function ends
}//函数结束时，pn会销毁，但其指向的内存区域(堆)不会销毁

#endif


//4.
//链接13.11.4.cpp
#if 0
int main()
{


    return 0;
}
#endif


//chapter 14
//code1.cpp
//程序清单14.3 has-a关系，使用包含技术(即创建一个包含其他类对象的类)
//使用复合类
//链接cxqd14.2.cpp
#if 0
#include "cxqd14.1.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };
    //使用了构造函数的类型转换特性(显式类型转换)

    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//程序清单14.6 has-a关系，使用私有继承技术
//链接cxqd14.5.cpp
#if 0
#include "cxqd14.4.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };

    int i;
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//程序清单14.9 使用公有单重继承
//链接cxqd14.8.cpp
#if 0
#include "cxqd14.7.h"
const int LIM = 4;

int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

    int i;
    for (i = 2; i < LIM; i++)
        pw[i]->Set();

    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.12 使用公有多重继承(公有MI)
//链接cxqd14.11.cpp
#if 0
#include <cstring>
#include "cxqd14.10.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";

        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':   lolas[ct] = new Waiter;
            break;
        case 's':   lolas[ct] = new Singer;
            break;
        case 't':   lolas[ct] = new SingingWaiter;
            break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单14.14 使用类模板，使用模板生成string栈
//链接无
#if 0
#include "cxqd14.13.h"
#include <string>
#include <cctype>

using std::cin;
using std::cout;

int main()
{                                          //模板的显式实例化
    Stack<std::string> st;   // create an empty stack 创建并用默认构造函数初始化一个空栈
                                           //***注***必须显式地提供所需的类型
    std::string po;

    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    char ch;
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
            }
        }

        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单14.16 使用类模板，使用模板用动态内存分配生成指针栈
//链接无
#if 0
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()
#include "cxqd14.15.h"

const int Num = 10;

int main()
{
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    // create an empty stack with stacksize slots
    Stack<const char*> st(stacksize);//创建一个动态内存分配的指针栈

    // in basket                                                   //生成指针数组
    const char* in[Num] = {
            " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
            " 3: Betty Rocker", " 4: Ian Flagranti",
            " 5: Wolfgang Kibble", " 6: Portia Koop",
            " 7: Joy Almondo", " 8: Xaverie Paprika",
            " 9: Juan Moore", "10: Misha Mache"
    };
    // out basket
    const char* out[Num];

    std::srand(std::time(0)); // randomize rand()
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num)   // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }

    for (int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;

    std::cout << "Bye\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.18 使用类模板，使用非模板类型参数来提供常规数组的大小
//并实现递归调用模板，生成二维数组
//链接无
#if 0
#include "cxqd14.17.h"

int main(void)
{
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums;//创建int sums[10]
    ArrayTP<double, 10> aves;//创建double aves[10]
    ArrayTP< ArrayTP<int, 5>, 10> twodee;//创建int twodee[10][5]


    int i, j;

    for (i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double)sums[i] / 5;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }

    cout << "Done.\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.19 使用类模板，使用多个类型参数
//链接无
#if 0
#include <string>

template <class T1, class T2 = int>//可以为类型参数提供默认值
class Pair
{
private:
    T1 a;
    T2 b;

public:
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval)
    { }
    Pair()
    {}
    T1& first();//用于修改a
    T2& second();
    T1 first() const//用于只读取a
    {
        return a;
    }
    T2 second() const
    {
        return b;
    }
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    Pair<string, int> ratings[4] =
    {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);

    cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
        << ratings[i].first() << endl;

    cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t "
        << ratings[3].first() << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.20 使用成员模板
//一个模板类将另一个模板类和模板函数作为其成员(在模板内定义)
//链接无
#if 0
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:                                    //嵌套模板类成员
    template <typename V>  // nested template class member
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    };

    hold<T> q;             // template object 创建基于T类型的hold对象
    hold<int> n;           // template object

public:
    beta(T t, int i) : q(t), n(i) {}

    template<typename U>   // template method
    U blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }

    void Show() const
    {
        q.show(); n.show();
    }
};

int main()
{
    beta<double> guy(3.5, 3);

    cout << " beta<double> guy(3.5, 3);" << endl;
    cout << "T was set to double\n\n";

    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n\n";

    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n\n";

    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n\n";
    cout << "Done\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.20 使用成员模板
//一个模板类将另一个模板类和模板函数作为其成员(在模板外定义，此编译器不支持)
//链接无
#if 0
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:                                    //嵌套模板类成员声明
    template <typename V>
    class hold;
    /* {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    }; */

    hold<T> q;             // template object 创建基于T类型的hold对象
    hold<int> n;           // template object

public:
    beta(T t, int i) : q(t), n(i) {}

    template<typename U>   // template method
    U blab(U u, T t);
    /*{
        return (n.Value() + q.Value()) * u / t;
    }*/

    void Show() const
    {
        q.show(); n.show();
    }
};

int main()
{
    beta<double> guy(3.5, 3);

    cout << " beta<double> guy(3.5, 3);" << endl;
    cout << "T was set to double\n\n";

    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n\n";

    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n\n";

    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n\n";
    cout << "Done\n";
    // std::cin.get();
    return 0;
}

template <typename T>
template<typename V>
class beta<T>::hold//写全类名和作用域解析运算符
{
private:
    V val;
public:
    hold(V v = 0) : val(v)
    {}
    void show() const
    {
        cout << val << endl;
    }
    V Value() const
    {
        return val;
    }
};

template <typename T>
template <typename U>
U beta<T>::blab(U u, T t)
{
    return (n.Value() + q.Value()) * u / t;
}
#endif


//程序清单14.21 使用类模板，使用模板作为类型参数
//链接无
#if 0
#include "cxqd14.21.h"

template <template <typename T> class Thing>//***注***
class Crab                                                  //此处的Thing是通用类型说明符
{                                                                  //此处的类型是一个模板类
private:
    Thing<int> s1;
    Thing<double> s2;

public:
    Crab() {};

    // assumes the thing class has push() and pop() members
    bool push(int a, double x)
    {
        return s1.push(a) && s2.push(x);
    }
    bool pop(int& a, double& x)
    {
        return s1.pop(a) && s2.pop(x);
    }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Crab<Stack> nebula;
    // Stack must match template <typename T> class thing   
    //Stack 替换了 Thing

    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;

    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单14.22 模板类的非模板友元函数
//链接无
#if 0
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;

public:
    HasFriend(const T& i) : item(i)
    {
        ct++;
    }
    ~HasFriend()
    {
        ct--;
    }
    friend void counts();//成为模板所有实例化的友元
    friend void reports(HasFriend<T>&); // template parameter
    //***注***
    //不能写成friend void report (HasFriend& );
    //若要提供模板类参数，必须指明具体化
};

//每个具体化都有自己的静态成员
// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
void reports(HasFriend<int>& hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double>& hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();

    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.23 模板类的约束模板友元函数
//链接无
#if 0
using std::cout;
using std::endl;

//第一步：在类声明前声明每个模板函数
// template prototypes
template <typename T> void counts();
template <typename T> void report(T&);

// template class
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT& i) : item(i) { ct++; }
    ~HasFriendT() { ct--; }

    //第二步：在类声明中再次将函数模板声明为友元
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT>&);//模板具体化
};

template <typename T>
int HasFriendT<T>::ct = 0;

//第三步：为友元写模板函数的定义
// template friend functions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T& hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();

    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    report(hfi1);  // generate report(HasFriendT<int> &)
    report(hfi2);  // generate report(HasFriendT<int> &)
    report(hfdb);  // generate report(HasFriendT<double> &)

    cout << "counts<int>() output:\n";//每种T类型都有自己的友元函数count()
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.24 模板类的非约束模板友元函数
//链接无
#if 0
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
    T item;

public:
    ManyFriend(const T& i) : item(i)
    {}
    template <typename C, typename D> friend void show2(C&, D&);
};

template <typename C, typename D> void show2(C& c, D& d)
{
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);
    // std::cin.get();
    return 0;
}
#endif


//chapter 14
//code2.cpp
//14.6 复习题
//4.
#if 0
//题目问生成的类声明
//所以生成
class Stack  <Worker*>
{
private:
    enum { MAX = 10 };  // constant specific to class 明示常量
    Worker* items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Worker*& item); // add item to stack
    bool pop(Worker*& item);        // pop top into item
};
#endif


//5.
//链接无
#if 0
#include <string>
#include <valarray>
#include "14.6.5.h"

int main()
{
    std::valarray<std::string>s_shuzu;

    //错误：这样生成的是指针栈
    /*double a[20] = {};
    Stack<double *>s1;*/
    //改正：
    //cxqd14.17.h中有ArrayTP类模板
    //Stack< ArrayTP<double,100> >  stack;

    //Worker* p_w = Worker w1;//报错：不允许创建抽象基类的对象
    Worker* p_w;//此时未生成Worker类对象P473
    Stack<Worker*>s2[20];

    //或：
    //ArrayTP<Stack<Worker*>, 100>arr_stk;

    return 0;
}
#endif


//chapter 14
//code3.cpp
//14.7 编程练习
//1.
//链接14.7.1.cpp
#if 0
#include "14.7.1.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "Enter number of years:";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);// store label,years,give arrays yrs elements
    holding.GetBottles();// solicit input for year,bottle count
    holding.Show(); // display object contents

    const int YRS = 3;
    int y[YRS] = { 1993,1995,1998 };
    int b[YRS] = { 48,60,72 };

    // create new object,initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for" << more.Label()// use Label()method
        << ": " << more.sum() << endl; // use sum () method
    cout << "Bye\n";
    return 0;
}
#endif


//2.
//链接14.7.2.cpp
#if 0
#include "14.7.2.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "Enter number of years:";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);// store label,years,give arrays yrs elements
    holding.GetBottles();// solicit input for year,bottle count
    holding.Show(); // display object contents

    const int YRS = 3;
    int y[YRS] = { 1993,1995,1998 };
    int b[YRS] = { 48,60,72 };

    // create new object,initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for" << more.Label()// use Label()method
        << ": " << more.sum() << endl; // use sum () method
    cout << "Bye\n";
    return 0;
}
#endif


//3.
//链接14.7.3.cpp
#if 0
#include <cstring>
#include "14.7.3.h"
const int SIZE = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    //***注***原来的方法是用指针数组存指向Worker的指针，
    //现在仅需声明一个指针，并用指针队列来存
    Worker* lolas = (Worker*)0x00;
    QueueTp<Worker*>lolas_stack;//模板隐式实例化P464

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {

        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";

        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':  lolas = new Waiter;//***注***虽然lolas的地址不变，但其每次循环中存的地址都会改变
            break;
        case 's':   lolas = new Singer;
            break;
        case 't':   lolas = new SingingWaiter;
            break;
        }

        cin.get();
        lolas->Set();
        lolas_stack.enqueue(lolas);
    }


    Worker* lolas_1 = (Worker*)0x01;
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas_stack.dequeue((lolas_1));
        lolas_1->Show();
    }

    //for (i = 0; i < ct; i++)
    //	delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//4.
//链接14.7.4.cpp
#if 0
#include <cstring>
#include "14.7.4.h"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "g: Gunslinger  p: PokerPlayer  "
            << "b: BadDude q: quit\n";

        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'g':   lolas[ct] = new Gunslinger;
            break;
        case 'p':   lolas[ct] = new PokerPlayer;
            break;
        case 'b':   lolas[ct] = new BadDude;
            break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//5.
//链接14.7.5.cpp
#if 0
using namespace std;
#include "14.7.5.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;//***注***若派生类中没有重定义<<运算符重载函数，则会默认使用基类的<<运算符重载函数
    em.ShowAll();
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

    /*abstr_emp tri[4] = {em,fi,hf,hf2};
    for (int i = 0; i < 4; i++)
        tri[i].ShowAll();*/

    return 0;
}
#endif


//chapter 15
//code1.cpp
//程序清单15.3 使用友元类
//链接cxqd15.2.cpp
#if 0
#include "cxqd15.1.h"

int main()
{
    using std::cout;

    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.onoff();
    s42.chanup();
    s42.settings();

    Remote grey;

    cout << "\n42\" settings after using remote:\n";
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
    // std::cin.get();
    return 0;
}
#endif


//程序清单15.4 仅让特定的类成员成为另一个类的友元
//链接cxqd15.4.cpp
#if 0
#include "cxqd15.4.h"

int main()
{
    using std::cout;

    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.onoff();
    s42.chanup();
    s42.settings();

    Remote grey;

    cout << "\n42\" settings after using remote:\n";
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
    // std::cin.get();
    return 0;
}
#endif


//程序清单15.6 在模板类中使用嵌套类
//链接无
#if 0
#include <string>
#include "cxqd15.5.h"

int main()
{
    using std::string;
    using std::cin;
    using std::cout;

    QueueTP<string> cs(5);
    string temp;

    while (!cs.isfull())
    {
        cout << "Please enter your name. You will be "
            "served in the order of arrival.\n"
            "name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";

    while (!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
    // cin.get();
    return 0;
}
#endif


//程序清单15.7 使用abort()
//链接无
#if 0
#include <cstdlib>

double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
            << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        std::cout << "untenable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
#endif


//程序清单15.8 返回错误码
//链接无
#if 0
#include <cfloat>  // (or float.h) for DBL_MAX

bool hmean(double a, double b, double* ans);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        if (hmean(x, y, &z))
            std::cout << "Harmonic mean of " << x << " and " << y
            << " is " << z << std::endl;
        else
            std::cout << "One value should not be the negative "
            << "of the other - try again.\n";
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

bool hmean(double a, double b, double* ans)
{
    if (a == -b)
    {
        *ans = DBL_MAX;
        return false;
    }
    else
    {
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}
#endif


//程序清单15.9 使用异常机制来处理错误
//链接无
#if 0
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {                       //表明要注意这些代码可能引发的异常
            z = hmean(x, y);
        }
        catch (const char* s)  //使用异常处理程序来捕获匹配的异常类型
        {//此代码块表示要采取的措施
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }                       // end of handler
        std::cout << "Harmonic mean of " << x << " and " << y
            << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        //throw表示引发异常
        throw "bad hmean() arguments: a = -b not allowed";
    return 2.0 * a * b / (a + b);
}
#endif


//程序清单15.11 将对象用作异常类型
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "cxqd15.10.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", "
                << hg.v2 << endl;//v1和v2是属于公有数据成员，所以对象可以访问
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
#endif


//程序清单15.12 栈解退
//链接无
#if 0
#include "cxqd15.12.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    {
        demo d1("found in block in main()");
        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {
            try {                  // start of try block
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y
                    << " is " << z << endl;
                cout << "Enter next pair: ";
            } // end of try block
            catch (bad_hmean& bg)    // start of catch block
            {
                bg.mesg();
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean& hg)
            {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", "
                    << hg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            } // end of catch block
        }
        d1.show();
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double means(double a, double b)
{
    double am, hm, gm;//算数平均数，调和平均数，几何平均数
    demo d2("found in means()");

    am = (a + b) / 2.0;    // arithmetic mean

    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean& bg) // start of catch block
    {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;             // rethrows the exception 相当于throw bad_hmean(a,b)
    }                           //重新引发异常，将向上把异常发送给main()
                                //若main()中没有try-catch块，则程序异常终止
    d2.show();

    return (am + hm + gm) / 3.0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);

    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);

    return std::sqrt(a * b);
}
#endif


//程序清单15.12.1 使用exception类
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "cxqd15.12.1.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout << bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
        //***注***
        //也可以选择在同一个基类处理程序中捕获它们
        //catch(std::exception &e) {...}
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();//调用bad_hmean类的默认构造函数以创建对象
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
#endif


//程序清单15.13 new引发bad_alloc异常
//链接无
#if 0
#include <new> //包含bad_alloc类声明
#include <cstdlib>  // for exit(), EXIT_FAILURE

using namespace std;

struct Big
{
    double stuff[200000000];
};

int main()
{
    Big* pb;

    try {
        cout << "Trying to get a big block of memory:\n";
        pb = new Big[10000]; // 1,600,000,000 bytes 声明结构数组
        cout << "Got past the new request:\n";
    }
    catch (bad_alloc& ba)
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;

    delete[] pb;
    // cin.get();
    return 0;
}
#endif


//程序清单15.13.1 关闭new引发的bad_alloc异常，即new失败时返回空指针
//链接无
#if 0
#include <new> //包含bad_alloc类声明
#include <cstdlib>  // for exit(), EXIT_FAILURE

using namespace std;

struct Big
{
    double stuff[200000000];
};

int main()
{
    Big* pb;

    try {
        cout << "Trying to get a big block of memory:\n";
        pb = new (std::nothrow)Big[10000]; // 1,600,000,000 bytes 声明结构数组
        cout << "Got past the new request:\n";
    }
    catch (bad_alloc& ba)
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (pb == 0)
    {
        cout << "请求分配内存失败！\n";
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;

    delete[] pb;
    // cin.get();
    return 0;
}
#endif


//程序清单15.16 类，异常，继承 (对嵌套类进行继承)
//链接cxqd15.15.cpp
#if 0
#include "cxqd15.14.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "First try block:\n";

    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {

            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {

            cout << sales2[i] << ' ';//当i为12时，索引值超界，引发异常
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    catch (LabeledSales::nbad_index& bad)//***注***两个catch块的顺序不能颠倒，P511
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }
    catch (Sales::bad_index& bad)
    {
        cout << bad.what();
        cout << "bad index: " << bad.bi_val() << endl;
    }

    cout << "\nNext try block:\n";

    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;//***注***此处索引值超界，operator[]()引发异常
        cout << "End of try block 2.\n";
    }
    catch (LabeledSales::nbad_index& bad)
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }
    catch (Sales::bad_index& bad)
    {
        cout << bad.what();
        cout << "bad index: " << bad.bi_val() << endl;
    }
    cout << "done\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单15.17 使用RTTI(运行阶段类型识别)——dynamic_cast()
//更严格的类型转换运算符——dynamic_cast()
//假设 High和Low是两个类，而 ph 和 pl的类型分别为High* 和Low* ，
//则仅当Low 是 High 的可访问基类（直接或间接）时，
//下面的语句才将一个Low* 指针赋给pl∶
//pl = dynamic_cast<Low*> ph;
//否则，该语句将空指针赋给pl。
//该运算符的用途是，使得能够在类层次结构中进行【向上转换】
//（由于 is-a 关系，这样的类型转换是安全的），而不允许其他转换
//链接无
#if 0
#include "cxqd15.17.h"
#include <cstdlib>//srand(), rand()
#include <ctime>//time()

Grand* GetOne(void);

int main()
{
    std::srand(std::time(0));

    Grand* pg;
    Superb* ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb*>(pg))//在运行阶段判断是否可以安全地
            ps->Say();                                          //将对象的地址赋给特定类型的指针
    }                           //***注***虚函数的功能保留                            
    // std::cin.get();
    return 0;
}

Grand* GetOne(void)    // generate one of three kinds of objects randomly
{
    Grand* p;
    p = (Grand*)0;//***注***不能写成Grand* p＝(Grand*)0;

    switch (std::rand() % 3)
    {
    case 0: p = new Grand(std::rand() % 100);
        break;
    case 1: p = new Superb(std::rand() % 100);
        break;
    case 2: p = new Magnificent(std::rand() % 100,
        'A' + std::rand() % 26);
        break;
    }

    return p;
}
#endif


//程序清单15.18 使用RTTI(运行阶段类型识别)——typeid()
//链接无
#if 0
#include "cxqd15.17.h"
#include <cstdlib>//srand()
#include <ctime>//time()
#include <typeinfo>//type_info类

Grand* GetOne();

int main()
{
    srand(time(0));

    Grand* pg;
    Superb* ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "Now processing type " << typeid(*pg).name() << ".\n";
        pg->Speak();

        if (ps = dynamic_cast<Superb*>(pg))
            ps->Say();
        if (typeid(Magnificent) == typeid(*pg))//typeid返回对type_info对象的引用
            cout << "Yes, you're really magnificent.\n";
    }
    // std::cin.get();
    return 0;
}

Grand* GetOne()
{
    Grand* p;
    p = (Grand*)0;

    switch (rand() % 3)
    {
    case 0: p = new Grand(rand() % 100);
        break;
    case 1: p = new Superb(rand() % 100);
        break;
    case 2: p = new Magnificent(rand() % 100, 'A' + rand() % 26);
        break;
    }

    return p;
}
#endif


//程序清单15.19 更严格的类型转换运算符——const_cast
//链接无
#if 0
using std::cout;
using std::endl;

void change(const int* pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000;

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);//***注***const_cast可以修改指向一个值的指针
                                         //但不能作用于声明为const的值
                                         //若使用，则结果不确定
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    // std::cin.get();
    return 0;
}

void change(const int* pt, int n)
{
    int* pc;

    pc = const_cast<int*>(pt);
    *pc += n;
}
#endif


//程序清单15.9.1 更严格的类型转换运算符——static_cast、reinterpret_cast
//链接无
#if 0
int main()
{
    enum meiju { a, b, c };

    meiju y;
    int x = 1;
    y = static_cast<meiju>(x);//支持【向上转换】或【向下转换】

    std::cout << y << std::endl;

    struct data
    {
        short a;
        short b;
    };

    long value = 0xA224B118;
    data* pd = reinterpret_cast<data*>(&value);

    std::cout << pd->a << std::endl;

    return 0;
}
#endif


//chapter 15
//code2.cpp
//15.7 复习题
//6.
//链接15.7.6.cpp
#if 0
#endif


//chapter 15
//code3.cpp
//15.8 编程练习
//1.
//链接15.8.1.cpp
#if 0
#include "15.8.1.h"

int main()
{
    using std::cout;

    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.onoff();
    s42.chanup();
    s42.settings();

    Remote grey;

    cout << "\n42\" settings after using remote:\n";
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();

    cout << "\n遥控器当前的模式：\n";
    grey.show_moshi();
    Tv v1(Tv::On);
    cout << "\n电视v1\" settings:\n";
    v1.settings();
    cout << "切换遥控器的交互模式：\n";

    if (v1.switch_moshi(grey))
    {
        cout << "遥控器当前的模式：\n";
        grey.show_moshi();
    }
    else
        cout << "电视机未打开！\n";

    return 0;
}
#endif


//2.
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.2.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout << bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
#endif


//3.
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.3.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout << bg.what();
            bg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            hg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
#endif
//3.改正
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.3.1.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (unexpected_mean& um)    // start of catch block
        {                                   //um是unexpected_mean类对象的引用

            //um.message();//***注***以下语句的实现效果与此语句相同
            //以下语句与此语句的不同之处在第4题体现(体现在：基类指针或引用不能调用基类中没有的但派生类有的方法)

            if (typeid(um) == typeid(bad_hmean))
            {
                bad_hmean* bh = dynamic_cast<bad_hmean*>(&um);//此处&um是bad_hmean类对象的地址
                bh->message();                                                  //理解：传入给unexpected_mean类的引用um的内容是bad_hmean类对象
                break;
            }
            else if (typeid(um) == typeid(bad_gmean))
            {
                bad_gmean* bg = dynamic_cast<bad_gmean*>(&um);//此处&um是unexpected_mean类对象的地址
                bg->message();
                break;
            }
        }
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
#endif


//4.
//链接无
#if 0
#include "15.8.4.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "First try block:\n";

    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {

            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {

            cout << sales2[i] << ' ';//当i为12时，索引值超界，引发异常
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    /*catch (LabeledSales::nbad_index& bad)//***注***两个catch块的顺序不能颠倒，P511
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }*/
    catch (Sales::bad_index& bad)
    {
        //想法一：是否可以用类名+作用域解析运算符来控制what()打印的内容？
        //即对于不同的类中的异常，用类名+作用域解析运算符来打印不同的字符串内容
        //cout << bad.bad_index::what();//***注***指定使用bad_index类公有继承的logic_error类的what()方法
        //以上方法不可用，因为nbad_index继承了bad_index类，而
        //而LabeledSales类对象出现异常后，初始化了nbad_index对象，
        //同时也初始化了bad_index类对象，而bad_index继承的logic_error类的what()方法的字符串内容为Index error in LabeledSales object
        //即LabeledSales类对象出现异常后，上面的方法打印不了Index error in Sales object
        //想法一失败

        //想法二：
        //使用RTTI来判断索引值错误是在Sales类中还是LabeledSales类中
        //由于只要求在合适时调用label_val()
        //相当于要根据不同的异常，调用label_val()和bi_val() 或只调用bi_val()
        if (typeid(bad) == typeid(LabeledSales::nbad_index))
        {
            //LabeledSales::nbad_index bad1("chushihua",1);
            //bad1 = dynamic_cast<LabeledSales::nbad_index &>(bad);//只允许隐式向上强制转换，相当于只允许nbad_index到nbad_index

            //法二：dynamic_cast用于指针
            LabeledSales::nbad_index* bad1 = dynamic_cast<LabeledSales::nbad_index*>(&bad);
            cout << bad1->what();
            cout << "Company: " << bad1->label_val() << endl;
            cout << "bad index: " << bad1->bi_val() << endl;
        }
        else
        {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }

    cout << "\nNext try block:\n";

    try
    {
        sales1[20] = 23345;//***注***此处索引值超界，operator[]()引发异常
        sales2[2] = 37.5;
        cout << "End of try block 2.\n";
    }
    /*catch (LabeledSales::nbad_index& bad)
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }*/
    catch (Sales::bad_index& bad)
    {
        if (typeid(bad) == typeid(LabeledSales::nbad_index))
        {
            LabeledSales::nbad_index bad1("chushihua", 1);
            bad1 = dynamic_cast<LabeledSales::nbad_index&>(bad);//只允许隐式向上强制转换，相当于只允许nbad_index到nbad_index

            cout << bad1.what();
            cout << "Company: " << bad1.label_val() << endl;
            cout << "bad index: " << bad1.bi_val() << endl;
        }
        else
        {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }
    cout << "done\n";
    // std::cin.get();
    return 0;
}
#endif


//chapter 16
//code1.cpp
//程序清单16.1 使用string类的7个构造函数
//链接无
#if 0
#include <string>
// using string constructors

int main()
{
    using namespace std;

    string one("Lottery Winner!");     // ctor #1
    cout << one << endl;               // overloaded <<

    string two(20, '$');               // ctor #2
    cout << two << endl;

    string three(one);                 // ctor #3
    cout << three << endl;

    one += " Oops!";                   // overloaded +=
    cout << one << endl;

    two = "Sorry! That was ";
    three[0] = 'P';
    string four;                       // ctor #4
    four = two + three;                // overloaded +, =
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 50);              // ctor #5 
    cout << five << "!\n";//***注***若超过了C风格字符串的长度，则仍将复制请求数目的字符
                                        //而且C风格字符串的尾部的\0，并不会被复制到five
    string six(alls + 6, alls + 10);     // ctor #6  需要传入的是两个地址值
    cout << six << ", ";
    string seven(&five[6], &five[10]); // ctor #6 again
    cout << seven << "...\n";

    string eight(four, 7, 16);         // ctor #7
    cout << eight << " in motion!" << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.2 使用string输入函数从文件中读取输入，使用指定分界符的getline()方法
//链接无
#if 0
#include <fstream>
#include <string>//getline()
#include <cstdlib>//EXIT_FAILURE

int main()
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;

    getline(fin, item, ':');
    while (fin)  // while input is good
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }

    cout << "Done\n";
    fin.close();
    // std::cin.get();
    // std::cin.get();
    return 0;
}
//***注***
//用命令行环境运行的方法：
//1.找到该可执行程序所在的文件路径(如本程序名为Project1.exe，其所在路径为)
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\x64\Debug
//2.用VS自带的工具中的命令行工具
//键入cd和空格和路径名，以改变路径
//键入Project1.exe tobuy.txt

//法二：不使用命令行环境：
//在该路径下D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\Project1
//创建tobuy.txt，程序也可正常运行
//fin.open("tobuy.txt");可以改成
//fin.open("D:\\CODE\\CPP_CODE\\C++ Primer Plus Code practice\\chapter 16\\code1\\Project1\\Project1\\tobuy.txt");
//其中\\是转义序列，相当于\

#endif


//程序清单16.3 使用find()方法实现拼字游戏
//链接无
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()

const int NUM = 26;
using std::string;
const string wordlist[NUM] = { "apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy" };

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];

        int length = target.length();//或写为target.size();

        string attempt(length, '-');

        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        string badchars;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos//若尝试了相同的字母
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);//返回该字符首次出现的位置的索引值
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //***注***当输入了一个正确的字符后，继续检查target数组，把其
                //把含有的所有该字符都拷贝到attempt数组的相应位置
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }

        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
#endif


//程序清单16.4 size()，capacity()，reserve()方法
//C++实现通常会分配一个比实际字符串大的内存块
//链接无
#if 0
#include <string>

int main()
{
    using namespace std;

    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";

    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "//请求最小长度为50的内存空间
        << empty.capacity() << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单16.5 使用智能指针
//功能：当指针过期时，其所指向的内存能够自动释放
//链接无
#if 0
#include <string>
#include <memory>//智能指针模板类
#include "cxqd16.5.h"

int main()
{
    {   //double* p_to_d ＝1.5 可以改写成：

        //正确写法：
            //double替换掉模板的泛型名(类型参数)，new double返回的值
                                                                             //作为构造函数的实参
        std::auto_ptr<double>p_to_d(new double);
        *p_to_d = 1.5;
        std::cout << *p_to_d << std::endl;

        //错误写法：
        /*double num = 1.5;
        std::auto_ptr<double>p(&num);*/
        //原因：delete不能用于非堆内存
    }
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();   // use -> to invoke a member function
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    // std::cin.get();  
    return 0;
}
#endif


//程序清单16.6 不适合使用auto_ptr的情况
//比较auto_ptr，shared_ptr，unique_ptr
//链接无
#if 0
#include <string>
#include <memory>

#define use_auto_ptr     0
#define use_shared_ptr  1

int main()
{
    using namespace std;
#if use_auto_ptr==1
    auto_ptr<string> films[5] =
    {
        auto_ptr<string>(new string("Fowl Balls")),
        auto_ptr<string>(new string("Duck Walks")),
        auto_ptr<string>(new string("Chicken Runs")),
        auto_ptr<string>(new string("Turkey Errors")),
        auto_ptr<string>(new string("Goose Eggs"))
    };

    //***注***若使用auto_ptr，则会在程序运行阶段崩溃
    auto_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#elif use_shared_ptr==1

    shared_ptr<string> films[5] =
    {
        shared_ptr<string>(new string("Fowl Balls")),
        shared_ptr<string>(new string("Duck Walks")),
        shared_ptr<string>(new string("Chicken Runs")),
        shared_ptr<string>(new string("Turkey Errors")),
        shared_ptr<string>(new string("Goose Eggs"))
    };

    //***注***shared_ptr支持共享所有权，即智能指针间的赋值
    shared_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    //***注***若使用unique_ptr，则会在编译阶段报错
    /*unique_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership   */
    //但unique_ptr允许unique_ptr类型的临时右值赋给unique_ptr指针
    //或使用move()将一个unique_ptr赋给另一个(智能指针间的赋值)

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#endif

    //以下操作可行：
    //相当于shared_ptr之间的赋值
    /*
    shared_ptr<double> pd;
    double* p_reg = new double;
    *p_reg = 1.1;
    pd = (shared_ptr<double>)p_reg;  //必须使用显式强制类型转换

    std::cout << *pd << endl;
    */

    // cin.get();
    return 0;
}
#endif
//使用move()，将一个unique_ptr赋给另一个
#if 0
#include <memory>
#include <string>
using std::string;
using std::unique_ptr;

unique_ptr <string> demo(const char* s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main()
{
    unique_ptr<string> ps1, ps2;
    ps1 = demo("123abc");
    ps2 = move(ps1);
    ps1 = demo("456def");
    std::cout << *ps2 << *ps1 << std::endl;

    return 0;
}
#endif


//程序清单16.7 泛型编程，使用vector模板类，创建vector模板对象
//链接无
#if 0
#include <vector>
#include <string>

const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<string> titles(NUM);
    vector<int> ratings(NUM);

    cout << "You will do exactly as told. You will enter\n"
        << NUM << " book titles and your ratings (0-10).\n";

    int i;
    for (i = 0; i < NUM; i++)
    {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Thank you. You entered the following:\n"
        << "Rating\tBook\n";

    for (i = 0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    // cin.get();

    return 0;
}
#endif


//程序清单16.8 使用迭代器iterator 
//使用STL容器的方法：size()，begin()，end()，swap()
//部分STL容器才有的方法：push_back()，erase()，insert()
//链接cxqd16.8.cpp
#if 0
#include <string>
#include <vector>
#include "cxqd16.8.h"

int main()
{
    using std::cout;
    using std::vector;

    vector<Review> books;//创建一个vector类对象，元素类型为
                                             //Review结构布局
    Review temp;//创建一个Review结构模板的结构temp

    while (FillReview(temp))
        books.push_back(temp);//将元素添加到矢量数组末尾

    int num = books.size();

    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
            << "Rating\tBook\n";

        //遍历元素方法一：
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);

        cout << "Reprising:\n"
            << "Rating\tBook\n";

        //使用类名和作用域解析运算符，访问迭代器iterator
        //为vector的Review类型声明一个迭代器pr
        vector<Review>::iterator pr;

        //遍历元素方法二：
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        //遍历元素法三：使用for_each();

        //遍历元素法四：使用基于范围的for循环(还支持修改容器的内容)

        //更多详见：遍历容器方法总结

        vector <Review> oldlist(books);// copy constructor used

        if (num > 3)
        {
            // remove 2 items
            //***注***
            //删除索引值1和索引值2位置上的元素，即
            //删除第二个和第三个元素
            books.erase(books.begin() + 1, books.begin() + 3);

            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);

            // insert 1 item
            //在第一个元素前面插入oldlist的第二个元素
            books.insert(books.begin(), oldlist.begin() + 1,
                oldlist.begin() + 2);

            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }

        //books的元素与oldlist的元素进行交换
        //***注***使用的是vector成员函数而不是STL提供的非成员函数swap()
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";

        cout << "books数组的内容:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        cout << "oldlist数组的内容:\n";
        for (pr = oldlist.begin(); pr != oldlist.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.9 使用STL函数(非成员函数) for_each()，sort()，random_shuffle()
//链接cxqd16.9.cpp
#if 0
#include "cxqd16.9.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()

int main()
{
    using namespace std;

    vector<Review> books;

    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        //可用于替换程序清单16.8中的for循环
        for_each(books.begin(), books.end(), ShowReview);

        //用sort()和内置的<operator()对vector数组的元素进行排序
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用sort()和自定义的函数对vector数组的元素进行排序
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用random_shuffle()进行随机排序，即打乱数组的元素
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//使用基于范围的for循环，遍历容器方法总结
//链接无
#if 0
#include <vector>
#include <algorithm>//for_each()

void show(double);
void alter(double&);

int main()
{
    using std::vector;
    using std::cout;
    using std::endl;
    //using std::iterator;  错误：应使用容器类中定义的迭代器
    using std::for_each;

    vector<double> data = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    //遍历元素方法一：(使用索引)
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << '\t';
    }
    cout.put('\n');

    //遍历元素方法二：(使用迭代器)
    //写法一：
    /*vector<double>::iterator p;
    for (p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }*/
    //写法二：
    for (auto p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }
    cout.put('\n');

    //遍历元素方法三：(使用STL函数)
    for_each(data.begin(), data.end(), show);
    cout.put('\n');

    //遍历元素方法四：(基于范围的for循环)
    //写法一：
    /*for (double x : data)
        show(x);*/
        //写法二：
    for (auto x : data)
        show(x);
    cout.put('\n');

    //使用遍历元素方法四修改元素的值：
    for (auto& x : data)
        alter(x);
    for (auto x : data)
        show(x);
    cout.put('\n');

    //遍历元素方法五：(将内容复制到输出流(使用输出迭代器输出))
#include <iterator>
    copy(data.begin(), data.end(),
        std::ostream_iterator<double, char>(cout, "\t"));

    return 0;
}
void show(double a)
{
    std::cout << a << '\t';
}
void alter(double& num)
{
    num++;
}
#endif


//程序清单16.10 使用copy()，输出迭代器，反向迭代器，sort()
//链接无
#if 0
#include <vector>
#include <iterator>//ostream_iterator模板，是个适配器，可以将
                                  //一些其他接口转换为STL使用的接口
#include <algorithm>//sort()

int main()
{
    using namespace std;

    int casts[10] = { 6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5 };
    vector<int> dice(10);

    // create an ostream iterator
    //要将信息复制到显示器上，则要有一个输出迭代器
    //可以用ostream_iterator模板创建这种迭代器
    //把数据输出接口cout转换为STL使用的接口(即输出迭代器)
    //让输出流能使用迭代器接口
    ostream_iterator<int, char> out_iter(cout, " ");

    //将15赋给指针指向的位置，然后将指针加1
    *(out_iter++) = 15;
    cout.put('\n');

    // copy from array to vector
                                        //***注***最后一个参数应为输出迭代器
    cout << "将casts的内容复制到dice\n";
    copy(casts, casts + 10, dice.begin());
    cout << "完成！\n";

    // copy from vector to output
    //将dice容器的整个区间复制到输出流中，即显示容器的内容
    //写法一：
    //copy(dice.begin(), dice.end(), out_iter);
    //写法二：不创建命名的迭代器，而直接构建一个匿名迭代器
    cout << "在显示器上显示dice的内容\n";
    copy(dice.begin(), dice.end(),
        ostream_iterator<int, char>(cout, " "));
    cout << endl;

    cout << "Implicit use of reverse iterator.\n";
    //实参一：指向超尾的反向迭代器；实参二：指向第一个元素的反向迭代器
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    // vector<int>::reverse_iterator ri;  // use if auto doesn't work
    for (auto ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

    //使用STL函数sort
    sort(dice.begin(), dice.end());
    copy(dice.begin(), dice.end(),
        std::ostream_iterator<int, char>(cout, " "));

    cout << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单16.11 使用两种插入迭代器
//链接无
#if 0
#include <string>
#include <iterator>//back_insert_iterator、insert_iterator
#include <vector>
#include <algorithm>//copy()

void output(const std::string& s)
{
    std::cout << s << " ";
}

int main()
{
    using namespace std;

    string s1[4] = { "fine", "fish", "fashion", "fate" };
    string s2[2] = { "busy", "bats" };
    string s3[2] = { "silly", "singers" };

    //创建一个vector数组，其含4个元素，每个元素类型均为string
    vector<string> words(4);

    //***注***s1 + 4是超尾迭代器，标识超尾的位置
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous back_insert_iterator object
    //创建匿名的back_insert_iterator迭代器
    copy(s2, s2 + 2,
        back_insert_iterator<vector<string> >(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous insert_iterator object
    //创建匿名的insert_iterator迭代器
    copy(s3, s3 + 2,
        insert_iterator<vector<string> >(words, words.begin()));
    copy(words.begin(), words.end(),
        std::ostream_iterator<string, char>(cout, " "));//使用迭代器输出
    cout << endl;           //***注***
                                      //发送给输出流的数据类型：string
    // cin.get();               //输出流使用的字符类型：char
    return 0;
}
#endif


//程序清单16.12 使用list的insert()、remove()、splice()、
//unique()、sort()、merge()方法
//链接无
#if 0
#include <iterator>
#include <list>//成员函数insert()等
#include <algorithm>//STL函数(非成员函数)：for_each()

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using namespace std;

    //创建一个由5个int类型的值2组成的序列
    list<int> one(5, 2); // list of 5 2s

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //创建一个空序列
    list<int> two;

    //将整个stuff数组的内容插入到two的首元素前
    int stuff[5] = { 1,2,4,8, 6 };
    //法一：(使用insert()成员函数)
    two.insert(two.begin(), stuff, stuff + 5);
    //法二：(使用insert_iterator插入迭代器)
    /*copy(stuff,stuff+5,
        insert_iterator<list<int>>(two,two.end()));*/

    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);

    //调用复制构造函数进行类型复制
    list<int> three(two);

    int more[6] = { 6, 4, 2, 4, 6, 5 };
    three.insert(three.end(), more, more + 6);

    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);

    //从双向链表中删除值为2的所有实例
    three.remove(2);
    cout << endl << "List three (删除了值为2的实例): ";
    for_each(three.begin(), three.end(), outint);

    //将链表one的内容插入到three头结点的前面
    //***注***one将清空
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //将连续的相同元素压缩为单个元素
    three.unique();
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    //排序(默认递增)
    three.sort();
    //***注***
    //不能使用STL函数sort()，
    //因为非成员函数sort()需要随机访问迭代器，
    //而list不支持随机访问
    //sort(three.begin(),three.end());

    //合并同类项
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    //排序(默认递增)
    two.sort();
    //将两个链表合并
    //***注***前提：两个链表必须已经排序
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);

    cout << endl;
    // cin.get();

    return 0;
}
#endif


//程序清单16.13 使用关联容器set
//使用insert()、set_union()、set_intersection()、set_difference()、
//lower_bound()、upper_bound()
//链接无
#if 0
#include <string>
#include <set>//关联容器set
#include <algorithm>//set_union()、set_intersection()、set_difference()
#include <iterator>

int main()
{
    using namespace std;

    const int N = 6;
    string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
    string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    //让输出流能使用迭代器接口
    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";

    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
        insert_iterator<set<string> >(C, C.begin()));//使用插入迭代器

    //***注***错误写法：
    //set_union(A.begin(), A.end(), B.begin(), B.end(), C.begin());
    //最后一个参数不能写成C.begin()，
    //因为对于关联集合，
    //将键看作常量，C.begin()返回的是迭代器是常量迭代器
    //而不是输出迭代器
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
    // cin.get();
    return 0;
}
//lower_bound() 函数查找升序数组中大于等于（ >= ）指定元素的第一个元素。
//upper_bound()函数查找升序数组中大于（ > ）指定元素的第一个元素。
#endif


//程序清单16.14 使用关联容器multimap
//使用方法insert()、count()、equal_range()
//链接无
#if 0
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
//键的类型          存储的值类型
typedef std::pair<const KeyType, std::string> Pair;
//multimap：值与键类型不同，一个键可以与多个值相关联
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;

    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Brooklyn"));
    //codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: "
        << codes.count(415) << endl;
    cout << "Number of cities with area code 718: "
        << codes.count(718) << endl;
    cout << "Number of cities with area code 510: "
        << codes.count(510) << endl;

    cout << "Area Code   City\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "    " << (*it).first << "     "
        << (*it).second << endl;

    //pair<MapCode::iterator, MapCode::iterator>
    auto range
        = codes.equal_range(718);

    cout << "Cities with area code 718:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;

    // cin.get();
    return 0;
}
#endif
//map中，值与键类型一定不同吗
#if 0
#include <map>

using namespace std;

int main()
{
    multimap<int, int > m;

    m.insert(pair<int, int>(2, 5));
    m.insert(pair<int,int>(1,2));
    m.insert(pair<int, int>(1, 3));

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout.put('\n');

    auto range = m.equal_range(1);

    //使用有名称的lambda函数
    auto print = [](const char* string,
        const pair<multimap<int, int>::iterator,
        multimap<int, int>::iterator >& pa)
    {
        cout << string << endl;

        for (auto r1 = pa.first; r1 != pa.second; r1++)
            cout << r1->first << " " << r1->second << endl;
    };

    print("打印键为1对应的值",range);

    return 0;
}
//说明map中，值与键的类型可以相同
#endif


//程序清单16.15 使用函数对象、使用方法remove_if()
//链接无
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

#include <functional>

//函数对象(函数符)
//重载了()运算符的类对象，则可以像使用函数那样使用类对象
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T& t) : cutoff(t)
    {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

void outint(int n)
{
    std::cout << n << " ";
}

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

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    //remove_if()成员将谓词(即返回bool值的一元函数)作为参数
    //由于类中定义了()运算符重载函数，所以可以把此类对象
    //当成函数名(或指向函数的指针)看待
    TooBig<int> f100(100); // limit = 100
    yadayada.remove_if(f100);               // use a named function object

    //写法一：
                                //创建匿名的类对象
    //etcetera.remove_if(TooBig<int>(200));   // construct a function object

    //写法二：
    etcetera.remove_if(std::bind2nd(std::greater<int>(), 200));

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.16 使用函数适配器
//链接无
#if 0
#include <vector>
#include <iterator>
#include <algorithm> //for_each()、transform()
#include <functional> //bind1st()

void Show(double);
const int LIM = 6;

int main()
{
    using namespace std;

    double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
    double arr2[LIM] = { 63, 65, 69, 75, 80, 99 };

    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);

    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;

    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);

    //plus<double>()生成一个匿名对象，同时其可作为函数对象
    //是个二元函数，接受两个参数
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(),
        plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);

    //multiplies<double>()生成一个匿名对象，同时其可作为函数对象
    //是个二元函数，接受两个参数
    //通过使用函数适配器bind1st()，
    //把二元函数对象捆绑成为一个一元函数对象
    //将常数赋给第一个参数，即第一个参数固定
    transform(gr8.begin(), gr8.end(), prod.begin(),
        bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);

    cout << endl;
    // cin.get();
    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}
#endif


//程序清单16.17 string类使用STL接口
//链接无
#if 0
#include <string>
#include <algorithm> //sort()、next_permutation()

int main()
{
    using namespace std;
    string letters;

    cout << "Enter the letter grouping (quit to quit): ";

    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;

        //next_permutation()将区间的内容转换为下一种排序方式
        //***注***必须先对内容进行排序
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;

        cout << "Enter next sequence (quit to quit): ";
    }

    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单16.18 对比STL方法(成员函数)和STL函数(非成员函数)的remove()
//链接无
#if 0
#include <list>
#include <algorithm>

void Show(int);
const int LIM = 10;

int main()
{
    using namespace std;

    int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };

    list<int> la(ar, ar + LIM);
    list<int> lb(la);

    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    la.remove(4);
    cout << "After using the remove() method:\n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;

    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);

    cout << endl;
    // cin.get();    
    return 0;
}

void Show(int v)
{
    std::cout << v << ' ';
}
#endif


//程序清单16.19 使用STL实现统计单词出现次数的程序
//链接无
#if 0
#include <vector>
#include <string>
#include <set>//关联容器set
#include <map>//关联容器map
#include <iterator>
#include <algorithm> //transform
#include <cctype> //tolower()

using namespace std;

char toLower(char ch)
{
    return tolower(ch);
}

string& ToLower(string& st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string& s);

int main()
{
    //将输入的单词添加到矢量中
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);

    //按输入顺序显示单词
    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    //按字母顺序显示单词
    //关联容器set自动对内容进行排序
    // place words in set, converting to lowercase
    set<string> wordset;
    //首先ToLower()把string元素都处理为小写字符，
    //然后transform()把每个string元素交给ToLower()处理
    //插入到set中会自动排序
    transform(words.begin(), words.end(),
        insert_iterator<set<string> >(wordset, wordset.begin()),
        ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    //记录每个单词被输入的次数
    // place word and frequency in map
    //map：值与键类型不同，键唯一，每个键对应一个值
    map<string, int> wordmap;
    set<string>::iterator si;//为set的string类型声明一个迭代器si

    for (si = wordset.begin(); si != wordset.end(); si++)
        //写法一：  
 /*       wordmap.insert(
            pair<string, int>
            (
                *si, count(words.begin(), words.end(), *si)
             )
                                  );                                              
 */
    //写法二：(可以用数组表示法(将键用作索引值)来存储键与值)
    wordmap[*si] = count(words.begin(), words.end(), *si);

   // display map contents
    cout << "\nWord frequency:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        //可以用数组表示法(将键用作索引值)来访问存储的值
        cout << *si << ": " << wordmap[*si] << endl;

    // cin.get();
    // cin.get();
    return 0;
}

void display(const string& s)
{
    cout << s << " ";
}
#endif


//程序清单16.20 比较vector、valarray各自的优势
//链接无
#if 0
#include <vector>//vector支持面向容器的操作
#include <valarray>//valarray面向数值计算
#include <algorithm>

int main()
{
    using namespace std;

    vector<double> data;
    double temp;

    cout << "Enter numbers (<=0 to quit):\n";
    while (cin >> temp && temp > 0)
        data.push_back(temp);

    sort(data.begin(), data.end());
    int size = data.size();

    valarray<double> numbers(size);
    int i;
    //写法一：
    //for (i = 0; i < size; i++)
    //    numbers[i] = data[i];
    //写法二：可能在其他环境下不可行，尤其是出现&numbers[size]时
    //copy(data.begin(),data.end(),&numbers[0]);
    //写法三：C++11提供的begin()，这样就满足了STL接口需求
    copy(data.begin(), data.end(), begin(numbers));

    //valarray类重载了数学函数，接受一个valarray参数，返回一个valarray对象
    //也可以使用apply()方法，其支持非重载函数作为参数
    valarray<double> sq_rts(size);
    //写法一：
    //sq_rts = sqrt(numbers);
    //写法二：
    sq_rts = numbers.apply(sqrt);

    //valarray类重载了所有算术运算符
    valarray<double> results(size);
    results = numbers + 2.0 * sq_rts;

    cout.setf(ios_base::fixed);
    cout.precision(4);

    for (i = 0; i < size; i++)
    {
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.width(8);
        cout << results[i] << endl;
    }
    cout << "done\n";
    // cin.get();
    // cin.get();

    return 0;
}
#endif


//程序清单16.21 valarray的其他特性
//用一维数组表示二维数组的数据内容
//链接无
#if 0
#include <valarray>
#include <cstdlib>

typedef std::valarray<int> vint;     // simplify declarations
const int SIZE = 12;
void show(const vint& v, int cols);

int main()
{
    using std::slice;                // from <valarray>
    using std::cout;
    vint valint(SIZE);               // think of as 4 rows of 3

    int i;
    for (i = 0; i < SIZE; ++i)
        valint[i] = std::rand() % 10;

    cout << "Original array:\n";
    show(valint, 3);                 // show in 3 columns

    //向vcol传入valint索引1、4、7和10对应的数据
    vint vcol(valint[slice(1, 4, 3)]); // extract 2nd column
    cout << "Second column:\n";
    show(vcol, 1);                   // show in 1 column

    //向vrow传入valint索引3、4和5对应的数据
    vint vrow(valint[slice(3, 3, 1)]); // extract 2nd row
    cout << "Second row:\n";
    show(vrow, 3);

    //valint的索引2，5，8和11对应的数据改为10
    valint[slice(2, 4, 3)] = 10;      // assign to 2nd column
    cout << "Set last column to 10:\n";
    show(valint, 3);

    cout << "Set first column to sum of next two:\n";
    // + not defined for slices, so convert to valarray<int>
    //valarray类才有+运算符重载函数
    valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)])
        + vint(valint[slice(2, 4, 3)]);
    show(valint, 3);

    // std::cin.get();
    return 0;
}

void show(const vint& v, int cols)
{
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];

        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }
    if (lim % cols != 0)
        cout << endl;
}
#endif


//程序清单16.22 使用模板initializer_list
//链接无
#if 0
#include <initializer_list>

//按值传递initializer_list对象
double sum(std::initializer_list<double> il);
//按引用传递initializer_list对象
double average(const std::initializer_list<double>& ril);

int main()
{
    using std::cout;

    cout << "List 1: sum = " << sum({ 2,3,4 })
        << ", ave = " << average({ 2,3,4 }) << '\n';

    std::initializer_list<double> dl = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "List 2: sum = " << sum(dl)
        << ", ave = " << average(dl) << '\n';

    dl = { 16.0, 25.0, 36.0, 40.0, 64.0 };
    cout << "List 3: sum = " << sum(dl)
        << ", ave = " << average(dl) << '\n';
    // std::cin.get();
    return 0;
}

double sum(std::initializer_list<double> il)
{
    double tot = 0;

    std::initializer_list<double>::iterator p;
    for (p = il.begin(); p != il.end(); p++)
        tot += *p;
    return tot;
}

double average(const std::initializer_list<double>& ril)
{
    double tot = 0;
    int n = ril.size();
    double ave = 0.0;

    if (n > 0)
    {
        for (auto p = ril.begin(); p != ril.end(); p++)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}
//提供 initializer_list类的初衷旨在
//让您能够将一系列值传递给构造函数或其他函数。
//比如说，vector类就有接受initializer_list作为参数的构造函数
//因此才可以这么写：vector<int> v {1,2,3};
#endif


//chapter 16
//code2.cpp
//16.9 复习题
//1.
//链接无
#if 0
#include "16.9.1.h"

int main()
{
    RQ1 st1;
    st1.show();

    RQ1 st2("abc");
    st2.show();

    RQ1 st3(st2);
    st3.show();

    RQ1 st4;
    st4 = st3;
    st4.show();

    return 0;
}
#endif


//3.
//链接无
#if 0
#include <string>
#include <cctype>
void alter(std::string&);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string st;

    cin >> st;
    alter(st);

    cout << st;

    return 0;
}
void alter(std::string& s)
{
    for (auto p = s.begin(); p != s.end(); p++)
    {
        if (islower(*p))
            *p = toupper(*p);
    }
}
#endif


//10.
//链接16.9.10.cpp
#if 0
#include "16.9.10.h"
#include <list>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()

int main()
{
    using namespace std;

    list<Review> books;

    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        //可用于替换程序清单16.8中的for循环
        for_each(books.begin(), books.end(), ShowReview);

        //***注***
        //不能使用STL的非成员sort()
        //修改一：
        books.sort();
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //修改二：
        books.sort(worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用random_shuffle()进行随机排序，即打乱数组的元素
        //random_shuffle(books.begin(), books.end());

        //cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";

    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//11.
//链接无
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

//函数对象(函数符)
//重载了()运算符的类对象，则可以像使用函数那样使用类对象
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T& t) : cutoff(t)
    {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

void outint(int n)
{
    std::cout << n << " ";
}

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

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    //remove_if()成员将谓词(即返回bool值的一元函数)作为参数
    //由于类中定义了()运算符重载函数，所以可以把此类对象
    //当成函数名(或指向函数的指针)看待
    TooBig<int> f100(100); // limit = 100
    yadayada.remove_if(f100);               // use a named function object

                                //创建匿名的类对象
    etcetera.remove_if(TooBig<int>(200));   // construct a function object

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    bool bo = TooBig<int>(10)(9);
    cout << bo << endl;
    // std::cin.get();
    return 0;
}
#endif


//chapter 16
//code3.cpp
//16.10 编程练习
//1.
//链接无
#if 0
#include <string>
bool huiwen(std::string& st);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;

    cout << "请输入字符串：";
    string st;
    cin >> st;
    bool bo = huiwen(st);

    if (bo)
        cout << "是回文\n";
    else
        cout << "不是回文\n";

    return 0;
}
bool huiwen(std::string& st)
{
    int length = st.size();//长度3，则索引0、1、2  索引只要0，长度5，索引只要0、1，长度7，索引只要0、1、2
    int local = 0;				   //长度4，索引只要0、1，长度6，索引只要0、1、2，长度8，索引只要0、1、2、3

    //不需要分奇偶
    //if(length%2)//奇数个
    for (int i = 0; i < int(length / 2); i++)
    {
        int j = length - i - 1;
        if (st[i] == st[j])
            continue;
        else
            return false;
    }
    //else//偶数个
    //	for (int i = 0; i < int(length / 2); i++)
    //	{
    //		int j = length - i - 1;

    //	}

    return true;
}
#endif
//***注***
//algorithm头文件中实用的函数：
//min()、max()、abs()
//find()、upper_bound()、lower_bound()
//count()、for_each() 
//__gcd()
//fill()、copy()、transform()
//swap()、reverse()、sort() 
//set_intersection()、set_union()、set_difference() 
//next_permutation()

//法二：使用algorithm中的reverse()
//链接无
#if 0
#include <algorithm>
#include <string>
bool huiwen(std::string& st);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;

    cout << "请输入字符串：";
    string st;
    cin >> st;
    bool bo = huiwen(st);

    if (bo)
        cout << "是回文\n";
    else
        cout << "不是回文\n";

    return 0;
}
bool huiwen(std::string& st)
{
    std::string temp(st);

    reverse(temp.begin(), temp.end());

    /*  if (temp == st)
          return true;
      else
          return false;*/

    return (temp == st);
}
#endif


//2.
//链接无
#if 0
#include <cctype>
#include <algorithm>
#include <iterator>

bool huiwen(std::string& st);

char ToLower(char a)
{
    return tolower(a);
}

using std::string;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    //测试erase()的功能
    /*
    string st = "abcdefghijklmn";
    string::iterator si=st.begin();
    //st.erase(3,1);
    //或写成：
    st.erase(si+3, si+4);
    */

    string st;
    cin >> st;

    //处理为纯字母内容
    for (int index = 0; index < st.size(); index++)
    {
        if (!isalpha(st[index]))
        {
            st.erase(index, 1);
            --index;//***注***若没写此语句，则输入连续的非字母的字符时会留有一个未删去，如输入,,,则会留下,
        }
    }
    cout << st << endl;

    string st1;
    //transform(st.begin(), st.end(),st1.begin(),ToLower); //第三个参数必须使用插入迭代器
    transform(st.begin(), st.end(), std::back_insert_iterator<string>(st1), ToLower);

    cout << st1 << endl;

    bool bo = huiwen(st1);

    if (bo)
        cout << "是回文\n";
    else
        cout << "不是回文\n";

    return 0;
}
#if 0
bool huiwen(std::string& st)
{
    int length = st.size();//长度3，则索引0、1、2  索引只要0，长度5，索引只要0、1，长度7，索引只要0、1、2
    int local = 0;				   //长度4，索引只要0、1，长度6，索引只要0、1、2，长度8，索引只要0、1、2、3

    for (int i = 0; i < int(length / 2); i++)
    {
        int j = length - i - 1;
        if (st[i] == st[j])
            continue;
        else
            return false;
    }

    return true;
}
#endif
//法二：忽略非字母的内容，定义头尾指针，
//头尾指针向中间逼近
#if 1
bool huiwen(std::string& st)
{
    std::string::iterator phead, ptail;

    phead = st.begin();
    ptail = st.end() - 1;//***注***此处要减一，否则解引用后会崩溃

    while (phead < ptail)
    {
        if (!isalpha(*phead))
        {
            phead++;
            continue;
        }

        if (!isalpha(*ptail))
        {
            ptail--;
            continue;
        }

        if (tolower(*phead) == tolower(*ptail))
        {
            phead++;
            ptail--;
        }
        else
            return false;
    }

    return true;
}
#endif

#endif


//3.
//链接无
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()
#include <vector>
#include <fstream>

//const string wordlist[NUM] = { "apiary", "beetle", "cereal",
//    "danger", "ensign", "florid", "garage", "health", "insult",
//    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
//    "plaid", "quilt", "remote", "stolid", "train", "useful",
//    "valid", "whence", "xenon", "yearn", "zippy" };

using namespace std;

int main()
{
    vector<string>source;

    ifstream fin;
    fin.open("abc.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    //不能使用getline
    //getline(fin, target);
    //while (fin)  // while input is good
    //{
    //    cout << target <<'\t';
    //    getline(fin, target);
    //}

    string temp;
    int NUM = 0;

    fin >> temp;
    while (fin)
    {
        source.push_back(temp);
        NUM++;

        fin >> temp;
    }

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = source[std::rand() % NUM];

        int length = target.length();//或写为target.size();

        string attempt(length, '-');

        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        string badchars;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos//若尝试了相同的字母
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);//返回该字符首次出现的位置的索引值
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //***注***当输入了一个正确的字符后，继续检查target数组，把其
                //把含有的所有该字符都拷贝到attempt数组的相应位置
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }

        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
#endif


//4.
//链接无
#if 0
#include <list>

int reduce(long ar[], int n);

int main()
{
    long ar[] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int len = sizeof ar / sizeof(long);

    int num = reduce(ar, len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//n值为15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    for (int index = 0; index < num; index++)
    {
        result[index] = l1.front();
        l1.pop_front();
    }


    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
#endif
//其他方法：
//链接无
#if 0
#include <list>
#include <algorithm>

int reduce(long ar[], int n);
long mycopy(long a);

int main()
{
    long ar[] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int len = sizeof ar / sizeof(long);

    int num = reduce(ar, len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//n值为15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    /*for (int index = 0; index < num; index++)
    {
        result[index] = l1.front();
        l1.pop_front();
    }*/

    //法二：
    //copy(l1.begin(),l1.end(),result);
    //法三：
    transform(l1.begin(), l1.end(), result, mycopy);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
long mycopy(long a)
{
    long result = a;
    return result;
}
#endif


//5.
//链接无
#if 0
#include <list>
#include <algorithm>
//#include <vector>

template <class T>
int reduce(T* ar, int n);

int main()
{
    long ar[15] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int num = reduce(ar, 15);
    std::cout << num << std::endl;

    std::string s1[4] = { "abc","ghj","cdf","bef" };
    num = reduce(s1, 4);
    std::cout << num;

    return 0;
}
template <class T>
int reduce(T* ar, int n)
{
    std::list<T> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    T* result = new T[num];

    copy(l1.begin(), l1.end(), result);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index] << ' ';
    }
    std::cout.put('\n');

    return num;
}
#endif


//6.
//链接16.10.6.cpp
#if 0
#include "16.10.6.h"
#include <queue>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item>line;                 //创建对象并用构造函数初始化
                                              // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;              //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line

// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // have newcomer
        {
            if (line.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.push(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.empty())//当队列空闲且有节点时
        {
            temp = line.front();     //排第一个的顾客在队列中被排除，其开始进行交易
            line.pop();
            wait_time = temp.ptime(); //wait_time即进行交易所花的时间

            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;//加入队列的人数
        cout << "  customers served: " << served << endl;//已服务完的人数
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}

#endif


//7.
//链接无
#if 0
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<int> lotto(int num_of_dot, int num_of_choose);

int main()
{
    vector<int> winners;
    winners = lotto(51, 6);

    cout << "\n彩票中奖数字：\n";
    for (auto p = winners.begin(); p < winners.end(); p++)
    {
        cout << *p << '\t';
    }

    return 0;
}
vector<int> lotto(int num_of_dot, int num_of_choose)
{
    vector<int> data(num_of_dot);
    for (int i = 1; i <= num_of_dot; i++)
    {
        data[i - 1] = i;
    }

    cout << "数字：";
    vector<int>::iterator p;
    for (p = data.begin(); p < data.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    srand(time(0));//***注***此处产生的种子能供random_shuffle函数使用
    random_shuffle(data.begin(), data.end());

    vector<int> win(num_of_choose);
    for (int index = 0; index < num_of_choose; index++)
    {
        win[index] = data[index];
    }

    return win;
}
#endif
//更优质的取数：
//for (int i = 0; i < sdot; i++)
//{
//
//    for (int j = 0; j < dot; j++)
//        temp.push_back(rand()%dot);
//
//    random_shuffle(temp.begin(),temp.end());
//
//    result.push_back(*temp.begin());
//}


//8.
//链接无
#if 0
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool FillData(set<string>&);
int main()
{
    set<string>data_Mat;

    cout << "请输入姓名：\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_Pat;

    cout << "请输入姓名：\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_M_and_P;
    //法一：使用针对集合操作的函数
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//使用插入迭代器

    //法二：
    //***注***必须插入在容器首位置
    copy(data_Mat.begin(), data_Mat.end(),
        insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));
    copy(data_Pat.begin(), data_Pat.end(),
        insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

    //法三：
    //data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
    //data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

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
//temp内容拷贝了
#endif


//9.
//链接无
#if 0
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void show(int);
int main()
{
    vector<int>vi0;

    srand((int)time(0));
    for (int i = 0; i < 100000; i++)
        vi0.push_back(rand());

#if 0
    for_each(vi0.begin(), vi0.end(), show);
    cout << endl;
#endif

    vector<int>vi(vi0);
    list<int>li(vi0.size());
    copy(vi0.begin(), vi0.end(), li.begin());

    cout << "STL的sort()函数所用的时间：\n";
    //计算对数组内容排序所需的时间
    clock_t start = clock();//(以毫秒为单位)
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    cout << "list的sort()方法所用的时间：\n";
    //计算对链表内容排序所需的时间
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    cout << "链表内容复制到数组，再对vi进行排序再将结果复制到li\
所需的时间：\n";
    copy(vi0.begin(), vi0.end(), li.begin());

    //计算链表内容复制到数组，对vi进行排序，再将结果复制到li所需的时间
    /*
    start = clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    */

    start = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end());
    li.assign(vi.begin(), vi.end());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    //***注***使用assign()方法，而不用copy方法会更快
    return 0;
}
void show(int num)
{
    cout << num << " ";
}
#endif


//10.
//链接16.10.10.cpp
#if 0
#include "16.10.10.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;

    //创建一个vector数组，每个元素都是智能指针，指向Review类型的值
    auto p_temp = new Review;
    vector<shared_ptr<Review>> books;
    /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//指向下一个可用于存储Review的内存区域
    }

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
                //错误	C2664	“void(const Review*)” :
                //无法将参数 1 从“std::shared_ptr<Review>”转换为“const Review * ”
                //即：智能指针类型不能自动转化成普通指针类型
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case '2':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(*books_kaobei.begin(), *books_kaobei.end());

            }
            default:
                cout << "输入有误，请重新输入！" << endl;
                break;
            }//可用于替换程序清单16.8中的for循环

            ////用sort()和内置的<operator()对vector数组的元素进行排序
            //sort(books.begin(), books.end());
            //cout << "Sorted by title:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////用sort()和自定义的函数对vector数组的元素进行排序
            //sort(books.begin(), books.end(), worseThan);
            //cout << "Sorted by rating:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////用random_shuffle()进行随机排序，即打乱数组的元素
            //random_shuffle(books.begin(), books.end());
            //cout << "After shuffling:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//10.改正
//链接16.10.10.1cpp
#if 0
#include "16.10.10.1.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;

    //待改进的方法：
    //这只支持最多10组数据
    //而且输入选择的数字'7'后，程序会崩溃
    //Expression: _CrtisvalidHeapPointer(block) 发生问题
#if 0
    //创建一个vectoir数组，每个元素都是智能指针，指向Review类型的值
    auto p_temp = new Review[10];
    vector<shared_ptr<Review>> books;
    /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {                                   //使用强制类型转换
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//指向下一个可用于存储Review的内存区域
    }
#endif

    //改进后的方法：
#if 0
    //创建一个vectoir数组，每个元素都是智能指针，指向Review类型的值
    vector<shared_ptr<Review>> books;

    auto p_temp = new Review;
    while (FillReview(*p_temp))
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp = new Review;
    }
#endif

    //改进后的方法(更好)：
#if 1
    vector<shared_ptr<Review>> books;
    Review temp;

    while (FillReview(temp))
    {                    //***注***此处使用了初始化动态分配的变量(书P263)
        shared_ptr<Review> p(new Review(temp));

        //写法二：
        //shared_ptr<Review> p (new Review);
        //*p = temp;

        books.push_back(p);//属于智能指针间的赋值，而不是初始化
    }
#endif

    if (books.size() > 0)
    {
        cout << "Thank you. You entered "
            << books.size() << " books !\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '2':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end());
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '3':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anpinjishengxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '4':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anpinjijiangxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '5':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anjiageshengxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '6':
            {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anjiagejiangxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            default:
                cout << "输入有误，请重新输入！" << endl;
                break;
            }

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";

    return 0;
}
#endif


//chapter 17
//code1.cpp
//(void *)用于打印地址的数值表示
//链接无
#if 0
using namespace std;

int main()
{
    int eggs = 12;
    const char* amount = "abc";

    cout << &eggs << endl;

    cout << amount << endl;
    cout << (void*)amount << endl;

    return 0;
}
#endif


//程序清单17.1 使用write()逐个显示字符
//链接无
#if 0
#include <cstring>  // or else string.h

int main()
{
    using std::cout;
    using std::endl;

    const char* state1 = "Florida";
    const char* state2 = "Kansas";
    const char* state3 = "Euphoria";

    int len2 = std::strlen(state2);
    cout << "Increasing loop index:\n";

    int i;
    for (i = 1; i <= len2; i++)
    {
        cout.write(state2, i);
        cout << endl;
    }

    // concatenate output
    cout << "Decreasing loop index:\n";
    for (i = len2; i > 0; i--)
        cout.write(state2, i) << endl;

    //write()方法不会在遇到空字符时停止打印字符
    //而是打印指定数目的字符
    // exceed string length
    cout << "Exceeding string length:\n";
    cout.write(state2, len2 + 5) << endl;//显示：Kansas

    //write()也可用于数值数据
    long val = 560031841;//long变量占4个字节
    //这4个字节将一个字节一个字节地进行传输
    //所以输出是每个字节的ASCII码的解释
    cout.write((char*)&val, sizeof(long));
    // std::cin.get();
    return 0;
}
#endif


//强制刷新缓冲区:endl、flush
//链接无
#if 0
using namespace std;

int main()
{
    cout << "123" << endl;
    cout << "456" << flush;

    return 0;
}
#endif


//程序清单17.2 默认的cout输出格式
//即浮点数的总位数最多显示6位，小数部分结尾的0不显示，
//根据位数选择定点记数法或科学计数法(E计数法)(但仍只显示6位的浮点数)
//链接无
#if 0
int main()
{
    using std::cout;
    cout << "12345678901234567890\n";

    char ch = 'K';
    int t = 273;
    cout << ch << ":\n";
    cout << t << ":\n";
    cout << -t << ":\n";

    double f1 = 1.200;
    cout << f1 << ":\n";
    cout << (f1 + 1.0 / 9.0) << ":\n";

    double f2 = 1.67E2;
    cout << f2 << ":\n";
    f2 += 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n";

    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.3 使用控制符修改整数计数系统
//链接无
#if 0
int main()
{
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n     n*n\n";
    cout << n << "     " << n * n << " (decimal)\n";

    // set to hex mode
    cout << hex;
    cout << n << "     ";
    cout << n * n << " (hexadecimal)\n";

    // set to octal mode
    cout << oct << n << "     " << n * n << " (octal)\n";

    // alternative way to call a manipulator
    dec(cout);//(写法二)
    cout << n << "     " << n * n << " (decimal)\n";

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单17.4 使用width()方法修改字段宽度
//链接无
#if 0
int main()
{
    using std::cout;

    //***注***
    //width()方法只影响接下来显示的一个项目

    int w = cout.width(30);//返回之前的字段宽度
    cout << "default field width = " << w << ":\n";

    cout.width(5);
    cout << cout.width() << std::endl;//返回当前字段宽度
    cout << "N" << ':';
    cout.width(8);
    cout << "N * N" << ":\n";

    for (long i = 1; i <= 100; i *= 10)
    {
        cout.width(5);
        cout << i << ':';
        cout.width(8);
        cout << i * i << ":\n";
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.5 使用fill()方法修改字段中填充的字符
//链接无
#if 0
int main()
{
    using std::cout;

    //***注***
    //fill()方法长期有效

    cout.fill('*');

    const char* staff[2] =
    { "Waldo Whipsnade", "Wilmarie Wooper" };
    long bonus[2] = { 900, 1350 };

    for (int i = 0; i < 2; i++)
    {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.6 使用precise()方法修改浮点数的显示精度
//***注***
//此处设置的是默认模式下的精度，即总位数最多为6位
//链接无
#if 0
int main()
{
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    float f = 100000.1;
    cout << f << std::endl;//只显示100000

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";

    //***注***
    //precise()方法长期有效

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.7 使用ios_base类的setf()方法，用showpoint格式常量
//使cout显示末尾小数点，精度合适时，会显示小数部分结尾的0
//此处精度指的是默认模式下的精度，即总位数
//链接无
#if 0
int main()
{
    using std::cout;
    using std::ios_base;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    //showpoint是ios_base类声明中定义的类级静态常量
    //类外要访问时要用作用域解析运算符

    //***注***
    //格式常量对标记的修改长期有效

    cout.setf(ios_base::showpoint);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";//20.4000
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";//2.78889

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";//20.
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";//2.8
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.8 使用名称空间std中的ios_base类中的
//一些类内常量(格式常量)配合setf()来控制格式化
//链接无
#if 0
int main()
{
    using std::cout;
    using std::endl;

    int temperature = 63;

    cout << "Today's water temperature: ";
    cout.setf(std::ios_base::showpos);    // show plus sign
    cout << temperature << endl;

    cout << "For our programming friends, that's\n";
    cout << std::hex << temperature << endl; // use hex
    cout.setf(std::ios_base::uppercase);  // use uppercase in hex
    cout.setf(std::ios_base::showbase);   // use 0X prefix for hex

    cout << "or\n";

    cout << temperature << endl;
    cout << "How " << true << "!  oops -- How ";

    cout.setf(std::ios_base::boolalpha);//控制格式为bool值，即true或false
    cout << true << "!\n";
    // std::cin.get();
    return 0;
}
#endif


//定点表示法(计数法)和科学表示法(计数法)与默认的表示法的区别
//链接无
#if 0
using namespace std;

int main()
{
    float num = 123.456789999;
    cout << num << endl;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << num << endl;

    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << num << endl;

    float num1 = 123.400000;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout.setf(ios_base::showpos);
    cout << num1 << endl;

    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << num1;

    //小数点后最多为6位，
    //显示末尾的0

    return 0;
}
#endif


//程序清单17.9 使用接受两个参数的setf()
//链接无
#if 0
#include <cmath>

int main()
{
    using namespace std;
    // use left justification, show the plus sign, show trailing
    // zeros, with a precision of 3
    cout.setf(ios_base::showpos);//显示正数前的+
    cout.setf(ios_base::showpoint);//显示末尾的小数点
    cout.precision(3);//精度设为3，总位数为3

    //左对齐
    cout.setf(ios_base::left, ios_base::adjustfield);
    //保存原来的格式
    //use e-notation and save old format setting
    ios_base::fmtflags old =
        //E计数法，指数计数法，那么精度的意思是小数点后的位数为3
        cout.setf(ios_base::scientific, ios_base::floatfield);

    cout << "Left Justification:\n";
    long n;
    for (n = 1; n <= 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    //符号或基数前缀左对齐，值右对齐
    // change to internal justification
    cout.setf(ios_base::internal, ios_base::adjustfield);

    //使用默认计数法
    // restore default floating-point display style    
    //***注***    
    //对比以下两条语句
#if 1
    cout.setf(old, ios_base::floatfield);
    //仅将floatfield相关的位设置为原始格式，即默认计数法
#endif    

#if 0
    cout.setf(old);
    //***注***
    //old存的格式是
    //显示正数前的 +
    //显示末尾的小数点
    //精度为3
    //左对齐
    //默认计数法

    //测试时，上面的cout.setf(ios_base::internal, ios_base::adjustfield);
    //要注释掉，否则左对齐和符号基数左，值右对齐这两个位都被设置
    //最终的显示效果还是右对齐
    //但为什么显示的还是科学计数法？？？
    //因为科学计数法对应的位并没有置0

#endif    

    cout << "Internal Justification:\n";
    for (n = 1; n <= 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    //右对齐，
    cout.setf(ios_base::right, ios_base::adjustfield);
    //使用定点计数法
    // use right justification, fixed notation
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Right Justification:\n";
    for (n = 1; n <= 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    // std::cin.get();
    return 0;
}
#endif


//关于cout.setf()的返回值的细节
//链接无
#if 0
using namespace std;

int main()
{
    ios_base::fmtflags initial;

    cout << 10 << ' ' << 15.0 << '\n';
    initial = cout.setf(ios_base::fixed);
    cout << 10 << ' ' << 15.0 << '\n';
    //***注***
    //由于initial存的是原来的默认计数法
    //但是 initial = cout.setf(ios_base::fixed); 将格式设置为
    //定点计数法后cout.setf(initial);并不会将定点计数法对应的位置0
    //所以输出效果仍是定点计数法
    cout.setf(initial);
    cout << 10 << ' ' << 15.0 << '\n';

    return 0;
}
#endif


//程序清单17.10 简化设置输出格式的语句
//一：使用标准控制符简化接受两个参数的setf()方法
//二：使用头文件iomanip中提供的控制符
//将使用precise()、width()、fill()方法
//简化为使用setprecise()、setfill()、setw()接受参数的控制符
//链接无
#if 0
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;

    //使用标准控制符替代cout.setf(... , ...);
    // use new standard manipulators
    cout << fixed << right;

    //使用头文件iomanip中提供的控制符
    // use iomanip manipulators
    cout << setw(6) << "N" << setw(14) << "square root"
        << setw(15) << "fourth root\n";

    double root;
    for (int n = 10; n <= 100; n += 10)
    {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ')
            << setw(12) << setprecision(3) << root
            << setw(14) << setprecision(4) << sqrt(root)
            << endl;
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单17.11 cin>>如何检查输入
//链接无
#if 0
int main()
{
    using namespace std;
#if 1
    cout << "Enter numbers: ";

    int sum = 0;
    int input;
    while (cin >> input)
    {
        sum += input;
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    /* keeping output window open */
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
#endif

    //对比C语言的scanf("%d",&num)
#if 0
    int num;
    scanf("%d", &num);

    cout << num;//输入123z，则num为123
#endif
    return 0;
}
#endif


//程序清单17.12 I/O和异常
//链接无
#if 0
#include <exception>

int main()
{
    using namespace std;

    //流状态由3个ios_base元素组成

    //rdstate()成员函数，exceptions()成员函数
    cout << cin.rdstate() << endl;
    cout << cin.exceptions() << endl;

    //exceptions()成员函数
    //返回一个位掩码，指出哪些标记可以导致异常被触发
    // have failbit cause an exception to be thrown
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";

    int sum = 0;
    int input;
    try
    {
        while (cin >> input)
        {
            sum += input;
        }
    }
    //***注***
    //cin >> input操作可能会修改流，
    //修改流涉及操作clear(...)
    //clear()方法将当前流状态与exceptions()返回的位字段
    //(即三个位状态)进行比较
    //前面的cin.exceptions(ios_base::failbit);
    //表示failbit位异常能被响应，返回的位字段的failbit位已被设置
    //若clear()方法提供的当前流状态的failbit也被设置，则
    //clear()将引发ios_base::failure异常
    //ios_base::failure是个类，从std::expection类派生而来，
    //含what()方法
    catch (ios_base::failure& badflag)
    {
        cout << badflag.what() << endl;
        cout << "O! the horror!\n";
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    /* keeping output window open */
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */

    return 0;
}
#endif


//程序清单17.13 使用ignore()方法
//链接无
#if 0
const int Limit = 255;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char input[Limit];

    cout << "Enter a string for getline() processing:\n";
    cin.getline(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 1\n";

    char ch;
    cin.get(ch);
    cout << "The next input character is " << ch << endl;

    //ignore(... , ...)方法
    //读取并丢弃输入流中的接下来的255个字符，或读取并丢弃内容到行尾(包括\n)
    if (ch != '\n')
        cin.ignore(Limit, '\n');    // discard rest of line

    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2\n";

    cin.get(ch);
    cout << "The next input character is " << ch << endl;

    //结论：getline()会丢弃分界符#，而get()不会

    /* keeping output window open */
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单17.14 使用putback()或peek()方法实现同一种处理结果
//链接无
#if 0
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    //  read and echo input up to a # character
    char ch;

    while (cin.get(ch))          // terminates on EOF
    {
        if (ch != '#')
            cout << ch;
        else
        {                                  //若读到#，则将#放回到输入字符串中
            cin.putback(ch);    // reinsert character
            break;
        }
    }

    if (!cin.eof())//若是读到分界符#后退出循环
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else//若是读到文件尾后退出循环
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#')    // look ahead
    {
        cin.get(ch);
        cout << ch;
    }

    if (!cin.eof())//若是读到分界符#后退出循环
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else//若是读到文件尾后退出循环
        cout << "End of file reached.\n";

    // keeping output window open 
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单17.15 使用peek()来确定是否读取了整行
//链接无
#if 0
const int SLEN = 10;

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[SLEN];

    cout << "Enter your name: ";
    cin.get(name, SLEN);
    if (cin.peek() != '\n')
        cout << "Sorry, we only have enough room for "
        << name << endl;
    eatline();

    char title[SLEN];
    cout << "Dear " << name << ", enter your title: \n";
    cin.get(title, SLEN);
    if (cin.peek() != '\n')
        cout << "We were forced to truncate your title.\n";
    eatline();

    cout << " Name: " << name
        << "\nTitle: " << title << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单17.16 使用ofstream、ifstream对象
//链接无
#if 0
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename;

    cout << "Enter name for new file: ";
    cin >> filename;

    //写法一：
    ofstream fout;
    fout.open(filename.c_str());

    //写法二：(使用构造函数)
    // create output stream object for new file and call it fout
    //ofstream fout(filename.c_str());//使用c_str()方法，转化成C风格字符串

    fout << "For your eyes only!\n";        // write to file 将内容写入文件
    cout << "Enter your secret number: ";   // write to screen 将内容写入屏幕

    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;//将内容写入文件

    fout.close();           // close file 关闭到文件的连接

    // create input stream object for new file and call it fin
    ifstream fin(filename.c_str());

    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))     // read character from file and  (遇到文件尾就结束循环)
        cout << ch;         // write it to screen

    cout << "Done\n";

    fin.close();                //关闭到文件的连接

    return 0;
}
#endif


//程序清单17.17 使用命令行参数
//要依次处理一批文件，可以打开一个流，并将它依次关联到各个文件
//链接无
#if 0
#include <fstream>
//#include <cstdlib>          // or stdlib.h

int main(int argc, char* argv[])
{
    using namespace std;

    if (argc == 1)          // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;              // open stream
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);  // connect stream to argv[file]

        if (!fin.is_open())
        {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }

        count = 0;
        while (fin.get(ch))
            count++;

        cout << count << " characters in " << argv[file] << endl;

        total += count;

        fin.clear();           // needed for some implementations
        fin.close();           // disconnect file
    }

    cout << total << " characters in all files\n";

    return 0;
}
#endif


//程序清单17.18 使用ios::out | ios::app (或 ios_base::out | ios_base::app)
//实现在文件尾追加数据
//链接无
#if 0
#include <fstream>
#include <string>
#include <cstdlib>      // (or stdlib.h) for exit()

const char* file = "guests.txt";

int main()
{
    using namespace std;
    char ch;

    // show initial contents
    ifstream fin;
    fin.open(file);

    //若文件存在，则输出文件原来的内容
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file:\n";

        while (fin.get(ch))
            cout << ch;

        fin.close();
    }

    // add new names
    //显式地提供第二个参数的文件模式常量
    ofstream fout(file, ios_base::out | ios_base::app);

    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter guest names (enter a blank line to quit):\n";
    string name;
    while (getline(cin, name) && name.size() > 0)
    {
        fout << name << endl;
    }
    fout.close();

    // show revised file
    //fin.clear();    // not necessary for some compilers
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
            << file << " file:\n";
        while (fin.get(ch))
            cout << ch;

        fin.close();
    }
    cout << "Done.\n";
    // cin.get();
    return 0;
}
#endif


//程序清单17.19 使用二进制模式创建和读取二进制文件
//链接无
#if 0
#include <fstream>
#include <iomanip>
#include <cstdlib>  // (or stdlib.h) for exit()

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

struct planet
{
    char name[20];      // name of planet
    double population;  // its population
    double g;           // its acceleration of gravity
};

const char* file = "planets.dat";

int main()
{
    using namespace std;

    planet pl;
    //使用定点计数法，右对齐
    cout << fixed << right;

    // show initial contents
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary);  // binary file
    //NOTE: some systems don't accept the ios_base::binary mode
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file:\n";

        while (fin.read((char*)&pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }

        fin.close();
    }

    // add new data 在文件尾追加数据(若文件不存在则创建文件)
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    //NOTE: some systems don't accept the ios::binary mode
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0')
    {
        eatline();
        cout << "Enter planetary population: ";
        cin >> pl.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> pl.g;
        eatline();

        fout.write((char*)&pl, sizeof pl);


        cout << "Enter planet name (enter a blank line "
            "to quit):\n";
        cin.get(pl.name, 20);
    }
    fout.close();

    // show revised file
    //fin.clear();    // not required for some implementations, but won't hurt
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
            << file << " file:\n";
        while (fin.read((char*)&pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "Done.\n";
    // keeping output window open
        // cin.clear();
        // eatline();
        // cin.get();
    return 0;
}
//***注***
//不能用string对象代替C风格字符串的name
//因为string对象包含一个指向其中存储了字符串的内存单元的指针
//而拷贝结构体时，复制的也是字符串的存储地址
//当再次运行程序时，地址无意义
#endif


//创建fstream对象后，将有两个缓冲区，一个用于输入，一个用于输出
//使用tellg()、tellp()查看输入缓冲区的输入指针和
//输出缓冲区的输出指针的位置 
//链接无
#if 0
#include <fstream>

using namespace std;

int main()
{
    fstream finout;

    finout.open("ceshi.txt", ios_base::out);

    int loc1 = finout.tellg();
    int loc2 = finout.tellp();

    cout << loc1 << " " << loc2 << endl;

    int num = 123456;
    finout << num;
    loc1 = finout.tellg();
    loc2 = finout.tellp();

    cout << loc1 << " " << loc2 << endl;
    //结论：fstream对象的tellg()、tellp()返回的值相同
    return 0;
}
#endif


//程序清单17.20 仅使用fstream对象来修改文件内容
//链接无
#if 0
#include <fstream>
#include <iomanip>
#include <cstdlib>      // (or stdlib.h) for exit()

const int LIM = 20;

struct planet
{
    char name[LIM];      // name of planet
    double population;  // its population
    double g;           // its acceleration of gravity
};

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

const char* file = "planets.dat";  // ASSUMED TO EXIST (binary.cpp example)

int main()
{
    using namespace std;
    //使用定点计数法
    cout << fixed;

    // show initial contents
    fstream finout;     // read and write streams
    finout.open(file,
        ios_base::in | ios_base::out | ios_base::binary);

    //***注***
    //若无planets.dat文件，则会导致打开文件失败
    //若是finout.open(file,ios_base::out | ios_base::binary);
    //则打开成功，
    //可以理解为有ios_base::in但文件不存在时，会导致打开文件失败

    int ct = 0;
    planet pl;

    if (finout.is_open())
    {
        //finout.seekg(0);    // go to beginning (此句可不写)
        cout << "Here are the current contents of the "
            << file << " file:\n";
        while (finout.read((char*)&pl, sizeof pl))
        {
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }

        //若已经读到文件尾
        if (finout.eof())
            finout.clear(); // clear eof flag 若无此语句，
        else                     //则显示Error on attempted seek
        {
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }

    }
    else
    {
        cerr << file << " could not be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }

    // change a record
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();              // get rid of newline

    if (rec < 0 || rec >= ct)
    {
        cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }

    streampos place = rec * sizeof pl;  // convert to streampos type
    finout.seekg(place);    // random access

    if (finout.fail())
    {
        cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char*)&pl, sizeof pl);
    cout << "Your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;

    //以下语句可以不写
    //if (finout.eof())
    //    finout.clear();     // clear eof flag

    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;

    finout.seekp(place);    // go back
    finout.write((char*)&pl, sizeof pl)    /* << flush*/;

    if (finout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

    // show revised file
    ct = 0;
    finout.seekg(0);            // go to beginning of file
    //***注***写成finout.seekp(0);效果相同      
    cout << "Here are the new contents of the " << file
        << " file:\n";
    while (finout.read((char*)&pl, sizeof pl))
    {
        cout << ct++ << ": " << setw(LIM) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
    }

    finout.close();
    cout << "Done.\n";

    // keeping output window open
    // cin.clear();
    // eatline();
    // cin.get();
    return 0;
}
#endif
//***注***
//Windows环境下，读取文本文档遇见换行会变成 "\r\n"
//但是若以二进制的方式读取就仅有"\n"
//要使用seekg()、seekp()方法来随机移动指针的话要特别注意
//https://blog.csdn.net/Iwanaabigdrumstick/article/details/64476805


//使用临时文件
//链接无
#if 0
#include <cstdio>

using namespace std;

int main()
{
    cout << "此系统能生成最多" << TMP_MAX << "个不重复的文件名，";
    cout << "每个文件名包含最多" << L_tmpnam << "个字符" << endl;

    char Name[L_tmpnam] = { '\0' };

    for (int i = 0; i < 10; i++)
    {
        tmpnam(Name);
        cout << Name << endl;
    }

    return 0;
}
#endif


//程序清单17.21 内核格式化——写入数据到ostringstream对象
//读取string对象中的格式化信息或将格式化信息写入string对象被称为内核格式化(incore formatting)
//简而言之，istringstream 和 ostringstream 类使得能够使用
//istream 和 ostream 类的方法来管理存储在字符串中的字符数据。
//链接无
#if 0
#include <sstream> //ostringstream类
#include <string>

int main()
{
    using namespace std;
    ostringstream outstr;   // manages a string stream

    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;

    //向string对象写入信息
    // write formatted information to string stream
    outstr << "The hard disk " << hdisk << " has a capacity of "
        << cap << " gigabytes.\n";

    string result = outstr.str();   // save result
    cout << result;                 // show contents

    outstr << "测试继续写入\n";
    cout << outstr.str();

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单17.22 内核格式化——从istringstream对象读出数据
//链接无
#if 0
#include <sstream>
#include <string>

int main()
{
    using namespace std;

    string lit = "It was a dark and stormy day, and "
        " the full moon glowed brilliantly. ";

    //istringstream对象使用string对象进行初始化
    istringstream instr(lit);   // use buf for input

    string word;
    while (instr >> word)       // read a word a time
        cout << word << endl;
    // cin.get();
    return 0;
}
#endif


//chapter 17
//code2.cpp
//17.7 复习题
//6.
//链接无
#if 0
#include <iomanip>

using namespace std;

int main()
{
    cout << "请输入一个整数：";
    int num;
    cin >> num;

    cout << left;
    cout << setw(10) << "十进制：" << num << endl;
    cout << setw(10) << "八进制：" << oct << num << endl;
    cout << setw(10) << "十六进制：" << hex << num << endl;

    cout << showbase;
    cout << setw(15) << dec << num
        << setw(15) << oct << num
        << setw(15) << hex << num;

    return 0;
}
#endif


//7.
//链接无
#if 0
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout << "Enter your name : ";
    string st1;
    getline(cin, st1);

    cout << "Enter your hourly wages : ";
    double wages;
    while (!(cin >> wages))
    {
        cout << "error, please try again : ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }

    cout << "Enter number of hours worked : ";
    double work;
    while (!(cin >> work))
    {
        cout << "error, please try again : ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }

    cout << "First format : " << endl;
    cout << right << setw(30) << st1 << " : " << left <<
        setw(5) << "$"
        << fixed << setprecision(2) << wages << " : " << setw(5)
        << setprecision(1) << work << endl;
    cout << "Second format : " << endl;
    cout << left << setw(30) << st1 << " : " << "$" << setw(9)
        << fixed << setprecision(2) << wages << " : "
        << setprecision(1) << work;

    return 0;
}
//可以修改的点：
//将"：$"作为一个整体来输出到屏幕
#endif


//8.
//链接无
#if 0
int main()
{
    using namespace std;
    char ch;
    int ct1 = 0;

    cin >> ch;
    while (ch != 'q')
    {
        ct1++;
        cin >> ch;
    }

    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q')
    {
        ct2++;
        cin.get(ch);
    }

    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return 0;
}
#endif


//9.
//链接无
//***注***
//ignore()方法功能测试
#if 0
using namespace std;

int main()
{
    char ch1;
    cin >> ch1;

#if 0
    cin.ignore(5, '\n');
    char ch2;
    cin >> ch2;

    cout << ch1 << "\t" << ch2;
    //输入1234567
    //则输出1和7
#endif

#if 1
    cin.ignore(10, '\n');
    char ch2;
    cin.get(ch2);

    cout << ch1 << "\t" << ch2;
    //输入1234567(按下Enter键后)，再输入\n
    //则输出1和\n

    //结论：
    //ignore()方法先检测到\n，则读取并丢弃\n字符和\n之前的内容
#endif

    return 0;
}
#endif


//chapter 17
//code3.cpp
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
    cin.getline(data, 50, '$');
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++)
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

int main(int argc, char** argv)
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
    fout.open(*(argv + 1));

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

int main(int argc, char** argv)
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

    char temp1[80] = { '\0' };
    char temp2[80] = { '\0' };

    fin1.getline(temp1, 80);
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
            char* p = find(temp1, temp1 + 80, '\0');

            //将此段末尾的\0替换成' '
            *p = ' ';
            //结尾再添加空字符
            *(p + 1) = '\0';

            //拼接字符串
            strncat(temp1, temp2, 79);
            temp1[79] = '\0';

            fout << temp1 << endl;
        }
        else if (fin1)//***注1***       
        {
            fout << temp1 << endl;

            cout << "fin1：" << endl;
            cout << fin1.eof() << "\t" << fin1.fail()
                << endl;

            cout << "fin2：" << endl;
            cout << fin2.eof() << "\t" << fin2.fail()
                << endl;
        }
        else
            fout << temp2 << endl;

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
    cout << endl << fin1.bad() << " " << fin2.bad() << endl;

    return 0;
}
//***注***
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\Project3
//下添加文件后可以直接编译运行，不用命令行环境

//注1：
//理解：(可以对比程序清单6.16 读取文件内容)
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
//当fin.getline()读入一行后，
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

using namespace std;

int main()
{
    //**********************对于cin**********************

    char ch1;
    cin >> ch1;//此处输入^Z模拟EOF

    cout << cin.eof() << " " << cin.fail() << endl;

    if (cin)
        cout << "good" << endl;

    cout << ch1 << endl;

    cin.clear();

    //**********************对于cin.get()**********************

    char ch2[10] = "123456789";
    cin.get(ch2, 10);//此处输入^Z或输入正常的内容
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
    //若直接输入^Z则ch3[0]为空字符，
    //若输入正常的内容，则ch3中原来的内容会被输入的
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
            fout << str << ' ';

        if (getline(fin2, str) && str.size() > 0)
            fout << str << ' ';

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

    set<char[LIMIT]>data_Pat;

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

    cin.getline(temp, LIMIT);
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
    fout.open("17.8.5.txt", ios_base::binary);

    fout.write((char*)&data_Mat, sizeof data_Mat);

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
        strcpy(p, temp);					 //不会销毁p指向的内容
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
        fout << (*p) << '\n';
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
        fout << (*p).c_str() << '\n';
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
    enum classkind { Employee, Manager, Fink, Highfink };

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
    cout << left << setw(15) << "a) employee"
        << setw(8) << "b) manager" << endl
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

        strcpy(s.temp, st.c_str());

        m_fout.write((char*)&len, sizeof(std::size_t));
        m_fout.write(s.data(), len);
    }

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
    Store(std::ofstream& fout) :m_fout(&fout)
    {}

    void operator()(const std::string& st)
    {
        //***注***
        //记录要存储的字符串需要占用的空间
        int len = st.length() + 1;

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
        fin.read(p, len);
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
    char data[2] = { 'a','b' };
    string str;

    str = data;
    cout << str << endl;

    //结论：
    //可以赋值，但由于无空字符，会导致后的字符是乱码

    return 0;
}
#endif


//string的c_str()方法和data()方法的比较
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


//chapter 18
//code1.cpp
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

//***注***
// 此函数可以没有
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


//chapter 18
//code2.cpp
//18.11 复习题
//1.
//链接无
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
    Z200 zip{ 200, 'Z', 0.675 };
    std::vector<int> ai{ 3,9,4,7,1 };
}
#endif


//6.
//链接无
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

//用lambda函数代替函数对象
auto f1 = [](double x) {	return 1.8 * x + 32;	};

int main()
{
    show2(18.0, f1);

    return 0;
}

//***注***下述写法错误
//int main()
//{
//	show2(18.0, [](double x) {	return 1.8 * x + 32; });
//
//	return 0;
//}
#endif


//7.
//链接无
#if 1
//修改前：
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
    Adder ad(total);//ad对象的tot数据成员值为0

    std::array<double, Size>temp_c = { 32.1,34.3,37.8,35.2,34.7 };

    sum(temp_c, ad);
    total = ad.tot_v();

    std::cout << "total:" << ad.tot_v() << '\n';
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
//修改后：
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
//***注***
//一个典型的程序在内存中有不同的区域，这被称为程序的内存布局。
//这些区域包括：
//代码段（Text Segment）： 存储程序的机器指令，也就是可执行代码。
//                                            这部分是只读的，通常是不可修改的。
//数据段（Data Segment）：
//			全局变量区域： 包含全局变量和静态变量。
//			常量区域： 存储常量数据，例如字符串常量。
//堆（Heap）： 动态分配的内存区域。程序员可以在运行时通过new（C++）
//                       或malloc（C）等方式在堆上分配内存。
//                       注意，程序员需要负责手动管理堆上的内存，释放不再需要的部分。
//栈（Stack）： 存储函数调用和局部变量。每个函数调用时，
//                       相关的局部变量和返回地址等信息都被压入栈中，
//                       当函数返回时，这些信息会被弹出。栈是一个有限的区域，
//                       而且其内存管理是自动的。
//内存映射区域： 包括共享库、动态链接库、内核空间等。


//chapter 18
//code3.cpp
//18.12 编程练习
//1.
//链接无
#if 0
#include <initializer_list>

using namespace std;

#if 0
template <typename T>						//***注***无法写成decltype(T)
auto average_list(const initializer_list<T>& li) ->decltype(*li.begin())
{
    T sum = 0;

    for (auto p = li.begin(); p != li.end(); p++)
    {
        sum += *p;
    }

    return sum / li.size();
}
#endif

//***注***
//若要返回值的类型和模板的类型参数一致，即也为T，
//则应写为：
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
    //得数应该为28.1666666666666666
    //现在用整数类型进行截断
    cout << average_list({ 20,30,19,17,45,38 }) << endl;

    // forced list of double
    auto ad = average_list<double>({ 'A',70,65.33 });
    cout << ad << endl;

    return 0;
}
#endif


//2.
//链接无
#if 0
#include "18.12.2.h"

using namespace std;

int main()
{
    {
        cout << "创建cv1对象" << endl;
        Cpmv cv1;

        cout << endl << "创建cv2对象" << endl;
        Cpmv cv2("abc", "123");

        cout << endl << "创建cv3对象" << endl;
        Cpmv cv3(cv1);

        cout << endl << "创建cv4对象" << endl;
        Cpmv cv4(cv1 + cv2);

        cout << endl << "创建cv5对象" << endl;
        Cpmv cv5;
        cv5 = cv4;

        cout << endl << "创建cv6对象" << endl;
        Cpmv cv6;
        cv6 = cv5 + cv2;

        cout << endl;
    }

    return 0;
}
#endif


//3.
//链接无
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
{                           //使用引用以提高传输效率
    static T sum = 0;

    sum += value;

    sum_value(args...);//当只剩下一个参数时，会调用上面那个函数模板
                            //但是参数无法传递给上面那个函数模板

}

int main()
{
    auto res1 = sum_value(1, 2, 3, 4, 5);

    auto res2 = sum_value(1.5, 2.5, 3.5);

    return 0;
}
#endif
//3.改正
//链接无
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
{                           //使用引用以提高传输效率
    return value + sum_value(args...);
}

int main()
{
    auto res1 = sum_value(1, 2, 3, 4, 5);
    auto res2 = sum_value(1.5, 2.5, 3.5);
    auto res3 = sum_value('A', 1, 2);

    std::cout << res1 << std::endl
        << res2 << std::endl
        << res3 << std::endl;

    return 0;
}
#endif


//4.
//链接无
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

#include <functional>

//函数对象(函数符)
//重载了()运算符的类对象，则可以像使用函数那样使用类对象
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
    //使用匿名的lambda表达式
    yadayada.remove_if([](int n) { return n > 100; });

    //写法一：

    etcetera.remove_if([](int n) { return n > 200; });

    //写法二：
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

/****************************************************End*****************************************/
