#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//(void *)用于打印地址的数值表示
//链接无
#if 0
using namespace std;

int main()
{
	int eggs = 12;
	const char* amount = "abc";

	cout << &eggs<<endl;

	cout << amount<<endl;
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
    cout.write( (char*)&val, sizeof(long));
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
    cout << cout.width()<<std::endl;//返回当前字段宽度
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
    cout << f << std:: endl;//只显示100000

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

    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << num<<endl;

    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << num<<endl;

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
        cout.setf(ios_base::scientific,ios_base::floatfield);

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
    scanf("%d",&num);

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

    finout.open("ceshi.txt",ios_base::out);

    int loc1=finout.tellg();
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
    finout.write((char*)&pl, sizeof pl)    /* << flush*/   ;

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
    cout << "此系统能生成最多" <<TMP_MAX<<"个不重复的文件名，";
    cout <<"每个文件名包含最多"<< L_tmpnam << "个字符"<<endl;

    char Name[L_tmpnam] = {'\0'};

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