#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//�����嵥7.2 ����ԭ�ͣ��������ã���������
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
    //C++���Զ������ݵ�ֵת��Ϊԭ����ָ��������
    //2ת��Ϊ2.0��cube��������8.0��8.0ת��Ϊ8������cheers����
    
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


//�����嵥7.3 һ����ԣ����������ж����ݵĲ�������Ӱ�����������е����ݵ�ֵ
//��Ϊ��������������һ���µı���(�β�)�������ʼ��Ϊʵ�ε�ֵ���൱����ʵ�ε�ֵ�ĸ���
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


//�����嵥7.4 �������������ĺ�����Ӧ��
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

    for (n = numbers, p = picks;            p > 0;         n--, p--)
        result = result * n / p;

    return result;
}
#endif


//�����嵥7.5 ʹ��ָ�������ָ����Ϊ�������β�
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


//�����嵥7.6 ��������������ĵ�һ��Ԫ�صĵ�ַ
//***ע***
//&����������������ĵ�ַ�������ǵ���Ԫ�صĵ�ַ������P176
#if 0
const int ArSize = 8;

int sum_arr(int arr[], int n);

// use std:: instead of using directive
int main()
{
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

    std::cout<< "array address = " << cookies;
    //  some systems require a type cast: unsigned (cookies)

    std::cout << ", sizeof cookies = " << sizeof cookies<<std::endl;
                                              //sizeof cookies��ָ��������ĳ���(���ֽ�Ϊ��λ)
    int sum = sum_arr(cookies, ArSize);

    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, 3);        // a lie
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);    // another lie
    //��дΪ
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

    std::cout << ", sizeof arr = " << sizeof arr<<std::endl;
                                    //***ע***sizeof arr��ָ������ĳ��ȣ������������е�Ԫ�صĳ���
 
    for (int i = 0; i < n; i++)
        total = total + arr[i];

    return total;
}
#endif


//�����嵥7.7 ������顢��������ʾ���顢�޸�����ĺ���
//��������ʼ����ָ����Ϊһ�������������鳤����Ϊ�ڶ�������
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


//�����嵥7.8 ��һ�ָ������ṩ������Ϣ�ķ���
//һ��ָ���ʶ����Ŀ�ͷ��һ��ָ���ʶ�����β�����һ��λ��
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


//�����嵥7.9 �ú��������ַ���
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

//���ؽ��ַ���������Ϊ�������ݸ�����
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


//�����嵥7.10 ����C����ַ����ĺ���
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

    return pstr;//***ע***�˺�������ʱ��ָ��pstr��ռ���ڴ潫���ͷţ�
}                      //��new����Ķ�̬������ڴ�ռ䲻�ᱻ�ͷ�,
                       //���ں���������ָ��pstr�ϴ�ĵ�ַ�����main()�Կ�����ps�����ʴ������ַ���
#endif  


//�����嵥7.11 ���ݲ����ؽṹ
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


//�����嵥7.12 ���ݲ����ؽṹ  ʵ��Ӧ��
#if 0
#include <cmath>//sqrt()��atan2()

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


//�����嵥7.13 ���ݽṹ�ĵ�ַ
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


//�����嵥7.14 ��string������������ά����
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
    display(list, SIZE);//list==&list[0]��string��������е�����string����ĵ�ַ
    // cin.get();

    return 0;
}

void display(const string sa[], int n)//�βΣ�ָ��string�����ָ��
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << sa[i] << endl;
    //д������    
    //cout << i + 1 << ": " << *(sa+i) << endl;
}
#endif


//�����嵥7.15 arrayģ����Դ洢����󣬲���Ϊһ��array����Ҳ���Դ����ά����
//��������array����ķ�ʽ(д��)��Щ��ͬ
#if 0
#include <array>//array��
#include <string>//string��

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//����һ��const array���󣬸ö������4��string����

//******************ע***********************
/*����
//const char *Snames[Seasons] =
//{ "Spring", "Summer", "Fall", "Winter" };
*/
/*����
const char Snames[Seasons][20] =
{ "Spring", "Summer", "Fall", "Winter" };
*/

void fill(std::array<double, Seasons>* pa);//�βΣ�ָ��array�����ָ��
void show(std::array<double, Seasons> da);//�βΣ�array����

int main()
{
    std::array<double, Seasons> expenses;//����һ��array���󣬰���4��double���͵�ֵ

                               //***ע***
    fill(&expenses);//ʵ�Σ�array��������ĵ�ַ��������&array[0]
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons>* pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> (*pa)[i];//�˴�д��Ψһ
        //std::cin >> *(pa + i);//***ע***����ÿ��+1������1��array������ռ���ֽ���
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


//�����嵥7.16 �ݹ�
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

    cout << "Counting down ... " << n << " (n at "<<&n<<")" << endl;
    if (n > 0)
        countdown(n - 1);     // function calls itself
    cout << n << ": Kaboom!" << " (n at " << &n << ")"<<endl;
}
#endif


//�����嵥7.17 ��������ݹ���õĵݹ�
#if 0
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main()
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';//��2��Ԫ������Len-2��Ԫ�ض�Ϊ�ո�

    ruler[Len - 1] = '\0';//��Len��(���һ��)Ԫ��Ϊ���ַ�

    int max = Len - 2;
    int min = 0;                            //min��max��Ϊ����ֵ
    ruler[min] = ruler[max] = '|';//��1��Ԫ�غ͵�Len-1��Ԫ��Ϊ'|'

    std::cout << ruler << std::endl;//��ӡ��һ��

    for (i = 1; i <= Divs; i++)//����� i +1 ��
    {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;

        //���������е�'|'�ַ�(���Բ�д)
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
    subdivide(ar, low, mid, level - 1);//���
    subdivide(ar, mid, high, level - 1);//�Ҳ�
}
#endif


//�����嵥7.18 ʹ�ú���ָ��
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


//�����嵥7.19 ����̽�ֺ���ָ��
#if 0
// 1.various notations, same signatures ��ͬ�ĺ�����������ͬ�ĺ�������ֵ�Ͳ����б�
const double* f1(const double ar[], int n);//�βΣ�ָ��const double ����ֵ��ָ�룻�����Ԫ�ظ���
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
    using namespace std;

    double av[3] = { 1112.3, 1542.6, 2227.9 };

//************************************************************************************************************************************************************************
    // 2.��������������ָ���ͬʱ���г�ʼ��
    const double* (*p1)(const double*, int) = f1;//������һ������ָ��p1
                                                                              //*p1����p1�Ǻ���ָ�룬��������ֵ�� const double*(const double����ֵ�ĵ�ַ)�������βΣ�(const double*, int)

    auto p2 = f2;  // 3.����һ������ָ��p2���������ʼ�����Ե�ֵ��ʼ������auto�Զ������ƶ������г�ʼ��
    //д������
    // const double *(*p2)(const double *, int) = f2;

    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    //��ʾconst double ֵ�ĵ�ַ����ʾconst double ֵ
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
 //************************************************************************************************************************************************************************
    
    const double* (*pa[3])(const double*, int) = { f1,f2,f3 };//������һ������pa������3��Ԫ�أ�ÿ��Ԫ�ض��Ǻ���ָ�룬paָ����ָ���������Ԫ�أ�pa�溯��ָ���������Ԫ�صĵ�ַ
    // pb a pointer to first element of pa
    auto pb = pa;//������һ��ָ����ָ���������Ԫ�ص�ָ��pb���������ʼ����
                           // 4.***ע***auto�����������ƶ��б��ʼ����Ӧ�������������˴���auto������pb��pb�溯��ָ���������Ԫ�صĵ�ַ
    //д������
    // const double *(**pb)(const double *, int) = pa;

    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
//************************************************************************************************************************************************************************

    //��***ע***������⣺
    //����һ��ָ����ָ���������Ԫ�ص�ָ��pa��ָ��pc��pc�溯��ָ���������Ԫ�ص�ָ��pa�ĵ�ַ
    //***��ȷ���***��
    //����һ��ָ����������ָ�������ָ��pc��pc����������ָ������ĵ�ַ
    auto pc = &pa;
    //д������
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
//��չ��
//��������typedef���������������׶�
#if 0
typedef const double* (*p_fun)(const double*, int);//��ָ����ֺ�������ֵ�ͺ��������ĺ����ĺ���ָ������Ϊp_fun

// 1.various notations, same signatures ��ͬ�ĺ�����������ͬ�ĺ�������ֵ�Ͳ����б�
const double* f1(const double ar[], int n);//�βΣ�ָ��const double ����ֵ��ָ�룻�����Ԫ�ظ���
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
    using namespace std;

    double av[3] = { 1112.3, 1542.6, 2227.9 };

//************************************************************************************************************************************************************************

    p_fun p1= f1;//������һ������ָ��p1

    auto p2 = f2;  //����һ������ָ��p2���������ʼ�����Ե�ֵ��ʼ������auto�Զ������ƶ������г�ʼ��
    //д������
    //p_fun p2= f2;

    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    //��ʾconst double ֵ�ĵ�ַ����ʾconst double ֵ
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
//************************************************************************************************************************************************************************

    p_fun pa[3]= { f1,f2,f3 };//������һ������pa������3��Ԫ�أ�ÿ��Ԫ�ض��Ǻ���ָ�룬paָ����ָ���������Ԫ�أ�pa�溯��ָ���������Ԫ�صĵ�ַ

    auto pb = pa;//������һ��ָ����ָ���������Ԫ�ص�ָ��pb���������ʼ����
                           //***ע***auto�����������ƶ��б��ʼ����Ӧ�������������˴���auto������pb��pb�溯��ָ���������Ԫ�صĵ�ַ
    //д������
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

    //��***ע***������⣺
    //����һ��ָ����ָ���������Ԫ�ص�ָ��pa��ָ��pc��pc�溯��ָ���������Ԫ�ص�ָ��pa�ĵ�ַ
    //***��ȷ���***��
    //����һ��ָ����������ָ�������ָ��pc��pc����������ָ������ĵ�ַ
    auto pc = &pa;
    //д������
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