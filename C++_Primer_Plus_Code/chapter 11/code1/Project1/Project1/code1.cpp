#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//�����嵥11.3 ��ʹ����������أ�ʵ�ּ���ʱ��ĳ���
//����cxqd11.2.cpp
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


//�����嵥11.6 ʹ����������أ�ʵ�ּ���ʱ��ĳ���
//����cxqd11.5.cpp
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

    // operator notation ��һ��ʹ���������ʾ��
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    // function notation ������ʹ��operator+()����
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    // std::cin.get();
    return 0;
}
#endif


//�����嵥11.9 ʹ���������������(+-*)��ʵ�ּ���ʱ��ĳ���
//����cxqd11.8.cpp
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


//�����嵥11.12 ʹ����Ԫ����(���ڴ����һ���������������������)
//����cxqd11.11.cpp
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

    //ʹ���������������operator+()
    temp = aida + tosca;     
    cout << "Aida + Tosca: " << temp << endl;
    //ʹ���������������operator*()
    temp = aida * 1.17;  
    cout << "Aida * 1.17: " << temp << endl;

    //ʹ��ostream���operator<<()�������������
    cout << "10.0 * Tosca: " 
    //ʹ��Time���operator*()��Ԫ������
    //Ȼ��ʹ��Time���operator<<()��Ԫ����
        << 10.0 * tosca 
    //ʹ��ostream���operator<<()�������������
        << endl;

    return 0;
}
#endif


//�����嵥11.15 ʹ��Vector��ģ�������������
//����cxqd11.14.cpp
#if 0
#include "cxqd11.13.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//ʹ��VECTOR���ƿռ��Vector��

    //��¼ÿһ����ʸ������
    Vector step;
    //��¼�ۼƵ�ʸ������
    Vector result(0.0, 0.0,Vector::Mode(0));//***ע***����д��Vector result(0.0, 0.0,0); int���Ͳ����Զ�ת��Ϊö������

    /* ��ʼ������ */
    srand(time(0));     // seed random-number generator 
    //�����������
    double direction;
    //������������
    unsigned long steps = 0;

    cout << "��������Ŀ��ľ��� (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "������ÿһ���Ĳ���: ";
        if (!(cin >> step_size))
            break;

        while (result.magval() < target_distance)
        {
            //����������Ƕȵķ�������
            direction = rand() % 360;

            //ע��ֻдPOL���������ᱨ��
            //��д��VECTOR::Vector::POL, ��д��Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***ע***������������غ��������˹��캯����
                                                 //�����캯���Ĳ���form��Ĭ��ֵΪRECT
            steps++;                      //������ʱ���󸳸�result�����result����ΪRECTģʽ
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


//�����嵥11.18 ʹ��ת����������ֻ����һ�������Ĺ��캯��
//ʵ������Զ�ת����ǿ������ת��(�������͵������͵�ת��)
//ʵ�ּ��ط���ת������
//����cxqd11.17.cpp
#if 0
#include "cxqd11.16.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{    
    //��ʼ��д��һ��
    //��ʽ���ù��캯����Ҳ����ʽǿ������ת��
    //Stonewt p1 = Stonewt (275); // uses constructor to initialize

    //��ʼ��д������
    //��ʽ���ù��캯�� 
    //Stonewt p1(275);

    //��ʼ��д������
    //�Զ�����ת����Ҳ����ʽ����ת��
    //ʹ�ù��캯����Ϊת�����������Ƚ�275ת��Ϊ275.0��
    //Ȼ��ʹ��Stonewt(double pds)���캯������ʼ������p1
    //��int���͵�ֵת��ΪStonewt����
    Stonewt p1= 275; // uses constructor to initialize

    //��ֵд����
    //Stonewt p1;
    //p1 = 275;

    Stonewt p2(285.7);    // same as Stonewt wolfe = 285.7;

    //�˴���⣺C++�Զ������ݵ�ֵת��Ϊԭ����ָ�������ͣ�
    //���������߶�����������(���ó���)
    //8���Զ�ת����8.0���ٴ��빹�캯��
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
    //***ע***
    //422ת��Ϊ422.0��Ȼ��ʹ��Stonewt(double pds)���캯��
    //����һ����ʱStonewt���󣬴���display()
    display(422, 2);

    //cout << "No stone left unearned\n";//û��ʲô�ǲ��Ͷ����
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


//�����嵥11.21 ʹ��ת���������������C++���������
//ʵ�������͵��������͵�ת��
//����cxqd11.20.cpp
#if 0
#include "cxqd11.19.h"

int main()
{
    using std::cout;

    Stonewt poppins(9, 2.8);     // 9 stone, 2.8 pounds

    //��ʽ����ת��
    double p_wt = poppins;      // implicit conversion

    //��ʽǿ������ת��
    //double p_wt = double(poppins); 

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";
    // std::cin.get();
    return 0;
}
#endif