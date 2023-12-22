#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//15.8 �����ϰ
//1.
//����15.8.1.cpp
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
    
    cout << "\nң������ǰ��ģʽ��\n";
    grey.show_moshi();
    Tv v1(Tv::On);
    cout << "\n����v1\" settings:\n";
    v1.settings();
    cout << "�л�ң�����Ľ���ģʽ��\n";

    if (v1.switch_moshi(grey))
    {
        cout << "ң������ǰ��ģʽ��\n";
        grey.show_moshi();
    }
    else
        cout << "���ӻ�δ�򿪣�\n";

    return 0;
}
#endif


//2.
//������
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
//������
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
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return std::sqrt(a * b);
}
#endif
//3.����
//������
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
        {                                   //um��unexpected_mean����������

            //um.message();//***ע***��������ʵ��Ч����������ͬ
            //�������������Ĳ�֮ͬ���ڵ�4������(�����ڣ�����ָ������ò��ܵ��û�����û�еĵ��������еķ���)

            if (typeid(um) == typeid(bad_hmean))
            {
                bad_hmean* bh = dynamic_cast<bad_hmean*>(&um);//�˴�&um��bad_hmean�����ĵ�ַ
                bh->message();                                                  //��⣺�����unexpected_mean�������um��������bad_hmean�����
                break;
            }
            else if (typeid(um) == typeid(bad_gmean))
            {
                bad_gmean* bg = dynamic_cast<bad_gmean*>(&um);//�˴�&um��unexpected_mean�����ĵ�ַ
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
//������
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

            cout << sales2[i] << ' ';//��iΪ12ʱ������ֵ���磬�����쳣
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    /*catch (LabeledSales::nbad_index& bad)//***ע***����catch���˳���ܵߵ���P511
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }*/
    catch (Sales::bad_index& bad)
    {
        //�뷨һ���Ƿ����������+��������������������what()��ӡ�����ݣ�
        //�����ڲ�ͬ�����е��쳣��������+������������������ӡ��ͬ���ַ�������
        //cout << bad.bad_index::what();//***ע***ָ��ʹ��bad_index�๫�м̳е�logic_error���what()����
        //���Ϸ��������ã���Ϊnbad_index�̳���bad_index�࣬��
        //��LabeledSales���������쳣�󣬳�ʼ����nbad_index����
        //ͬʱҲ��ʼ����bad_index����󣬶�bad_index�̳е�logic_error���what()�������ַ�������ΪIndex error in LabeledSales object
        //��LabeledSales���������쳣������ķ�����ӡ����Index error in Sales object
        //�뷨һʧ��

        //�뷨����
        //ʹ��RTTI���ж�����ֵ��������Sales���л���LabeledSales����
        //����ֻҪ���ں���ʱ����label_val()
        //�൱��Ҫ���ݲ�ͬ���쳣������label_val()��bi_val() ��ֻ����bi_val()
        if(typeid(bad)==typeid(LabeledSales::nbad_index))
        {
            //LabeledSales::nbad_index bad1("chushihua",1);
            //bad1 = dynamic_cast<LabeledSales::nbad_index &>(bad);//ֻ������ʽ����ǿ��ת�����൱��ֻ����nbad_index��nbad_index

            //������dynamic_cast����ָ��
            LabeledSales::nbad_index *bad1= dynamic_cast<LabeledSales::nbad_index*>(&bad);
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
        sales1[20] = 23345;//***ע***�˴�����ֵ���磬operator[]()�����쳣
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
            bad1 = dynamic_cast<LabeledSales::nbad_index&>(bad);//ֻ������ʽ����ǿ��ת�����൱��ֻ����nbad_index��nbad_index

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