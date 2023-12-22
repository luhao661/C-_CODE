#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//�����嵥15.3 ʹ����Ԫ��
//����cxqd15.2.cpp
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


//�����嵥15.4 �����ض������Ա��Ϊ��һ�������Ԫ
//����cxqd15.4.cpp
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


//�����嵥15.6 ��ģ������ʹ��Ƕ����
//������
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


//�����嵥15.7 ʹ��abort()
//������
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


//�����嵥15.8 ���ش�����
//������
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


//�����嵥15.9 ʹ���쳣�������������
//������
#if 0
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {                       //����Ҫע����Щ��������������쳣
            z = hmean(x, y);
        }                       
        catch (const char* s)  //ʹ���쳣�������������ƥ����쳣����
        {//�˴�����ʾҪ��ȡ�Ĵ�ʩ
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
        //throw��ʾ�����쳣
        throw "bad hmean() arguments: a = -b not allowed";
    return 2.0 * a * b / (a + b);
}
#endif


//�����嵥15.11 �����������쳣����
//������
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
                << hg.v2 << endl;//v1��v2�����ڹ������ݳ�Ա�����Զ�����Է���
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


//�����嵥15.12 ջ����
//������
#if 1
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
    double am, hm, gm;//����ƽ����������ƽ����������ƽ����
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
        throw;             // rethrows the exception �൱��throw bad_hmean(a,b)
    }                           //���������쳣�������ϰ��쳣���͸�main()
                                //��main()��û��try-catch�飬������쳣��ֹ
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


//�����嵥15.12.1 ʹ��exception��
//������
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
            cout<<bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
        //***ע***
        //Ҳ����ѡ����ͬһ�����ദ������в�������
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
        throw bad_hmean();//����bad_hmean���Ĭ�Ϲ��캯���Դ�������
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
#endif


//�����嵥15.13 new����bad_alloc�쳣
//������
#if 0
#include <new> //����bad_alloc������
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
        pb = new Big[10000]; // 1,600,000,000 bytes �����ṹ����
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


//�����嵥15.13.1 �ر�new������bad_alloc�쳣����newʧ��ʱ���ؿ�ָ��
//������
#if 0
#include <new> //����bad_alloc������
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
        pb = new (std::nothrow)Big[10000]; // 1,600,000,000 bytes �����ṹ����
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
        cout << "��������ڴ�ʧ�ܣ�\n";
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


//�����嵥15.16 �࣬�쳣���̳� (��Ƕ������м̳�)
//����cxqd15.15.cpp
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

            cout << sales2[i] << ' ';//��iΪ12ʱ������ֵ���磬�����쳣
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    catch (LabeledSales::nbad_index& bad)//***ע***����catch���˳���ܵߵ���P511
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
        sales1[20] = 23345;//***ע***�˴�����ֵ���磬operator[]()�����쳣
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


//�����嵥15.17 ʹ��RTTI(���н׶�����ʶ��)����dynamic_cast()
//���ϸ������ת�����������dynamic_cast()
//������
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
        if (ps = dynamic_cast<Superb*>(pg))//�����н׶��ж��Ƿ���԰�ȫ��
            ps->Say();                                          //������ĵ�ַ�����ض����͵�ָ��
    }                           //***ע***�麯���Ĺ��ܱ���                            
    // std::cin.get();
    return 0;
}

Grand* GetOne(void)    // generate one of three kinds of objects randomly
{
    Grand* p;
    p = (Grand*)0;//***ע***����д��Grand* p��(Grand*)0;

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


//�����嵥15.18 ʹ��RTTI(���н׶�����ʶ��)����typeid()
//������
#if 0
#include "cxqd15.17.h"
#include <cstdlib>//srand()
#include <ctime>//time()
#include <typeinfo>//type_info��

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
        if (typeid(Magnificent) == typeid(*pg))//typeid���ض�type_info���������
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


//�����嵥15.19 ���ϸ������ת�����������const_cast
//������
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
    change(&pop2, -103);//***ע***const_cast�����޸�ָ��һ��ֵ��ָ��
                                         //����������������Ϊconst��ֵ
                                         //��ʹ�ã�������ȷ��
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


//�����嵥15.9.1 ���ϸ������ת�����������static_cast��reinterpret_cast
//������
#if 0
int main()
{
    enum meiju {a,b,c};

    meiju y;
    int x = 1;
    y = static_cast<meiju>(x);

    std::cout << y<<std::endl;

    struct data
    {
        short a;
        short b;
    };

    long value = 0xA224B118;
    data* pd = reinterpret_cast<data*>(&value);

    std::cout << pd->a<<std::endl;

    return 0;
}
#endif