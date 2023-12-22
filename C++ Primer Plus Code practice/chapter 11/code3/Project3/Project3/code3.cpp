#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//11.9 �����ϰ
//1.
//����11.9.1.cpp
#if 0
#include "11.9.1.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//ʹ��VECTOR���ƿռ��Vector��

    /*
    //��Ҫ���ļ�д�����ݣ������ѡ��ذѺ����out��Ϊfout
    ofstream fout;
    fout.open("randwalk.txt");
    */

    //��¼ÿһ����ʸ������
    Vector step;
    //��¼�ۼƵ�ʸ������
    Vector result(0.0, 0.0, Vector::Mode(0));//***ע***����д��Vector result(0.0, 0.0,0); int���Ͳ����Զ�ת��Ϊö������

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

        cout << "Target Distance : " << target_distance
            << ", Step Size : " << step_size << endl;

        while (result.magval() < target_distance)
        {
            if (steps == 0)
                cout << "0 : (x,y) = (0,0)" << endl;

            steps++;
            //����������Ƕȵķ�������
            direction = rand() % 360;

            //ע��ֻдPOL���������ᱨ��
            //��д��VECTOR::Vector::POL, ��д��Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***ע***������������غ��������˹��캯����
                                                 //�����캯���Ĳ���form��Ĭ��ֵΪRECT
                                                 //������ʱ���󸳸�result�����result����ΪRECTģʽ
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
//����11.9.2.cpp
#if 0
#include "11.9.2.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//ʹ��VECTOR���ƿռ��Vector��

    //��¼ÿһ����ʸ������
    Vector step;
    //��¼�ۼƵ�ʸ������
    Vector result(0.0, 0.0, Vector::Mode(0));//***ע***����д��Vector result(0.0, 0.0,0); int���Ͳ����Զ�ת��Ϊö������

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


//3.
//����11.9.3.cpp
#if 0
#include "11.9.3.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

void show_average(double *,int );

int main()
{
    using namespace std;
    using VECTOR::Vector;//ʹ��VECTOR���ƿռ��Vector��

    //��¼ÿһ����ʸ������
    Vector step;
    //��¼�ۼƵ�ʸ������
    Vector result(0.0, 0.0, Vector::Mode(0));//***ע***����д��Vector result(0.0, 0.0,0); int���Ͳ����Զ�ת��Ϊö������

    /* ��ʼ������ */
    srand(time(0));     // seed random-number generator 
    //�����������
    double direction;
    //������������
    unsigned long steps = 0;

    cout << "��������Ŀ��ľ��� (q to quit) :  ";
    double target_distance;
    double step_size;
    int num;
    double* p_data=(double *)0;//***ע***�˴������ȶ�ָ���ʼ��
                                                    //��ָ������Ϊ��ַ0    (��P335)
    while (cin >> target_distance)
    {
        cout << "������ÿһ���Ĳ���: ";
        if (!(cin >> step_size))
            break;

        cout << "��������Դ�����";
        cin >> num;
        p_data = new double[num];//��̬�����ڴ�

        for (int i = 0; i < num; i++)
        {
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

            /*cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
            cout << result << endl;

            result.polar_mode();
            cout << " or\n" << result << endl;*/

            *(p_data + i) = result.magval() / steps;
            cout << "Average outward distance per step = "
                << result.magval() / steps << endl<<endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }

        show_average(p_data,num);
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

void show_average(double*p, int n)
{
    using std::cout;
    using std::endl;

    double min , max,sum=0.0;
    min = max = *p;

    for (int i = 0; i < n; i++)
    {
        *(p + i) > max ? max = *(p + i) : 1;
        *(p + i) < min ? min = *(p + i) : 1;
        sum += *(p+i);
    }

    cout.put('\n');
    cout << n << "�β����У�\n���ƽ��������" << max
        << "\n���ƽ��������"<<min<<endl
        << n << "�β��Ե�ƽ��������"<<sum/n<<endl<<endl;
}
#endif


//4.
//����11.9.4.cpp
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


//5.
//����11.9.5.cpp
#if 0
#include "11.9.5.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
    //ʹ��Ĭ�Ϲ��캯��
    Stonewt p0;
    cout << "The p0 weighed ";
    cout << p0;

    //ʹ�ù��캯��������ת�����ܣ�formΪFLOAT_POUNDS
    Stonewt p1 = 100.1; 
    cout << "The p1 weighed ";
    cout << p1;

    //ʹ�ù��캯��������ת�����ܣ�formΪINTEGER_POUNDS
    Stonewt p2(200.6,Stonewt::INTEGER_POUNDS);//ʹ��������Ϊ�����ʾ����
    cout << "The p2 weighed ";
    cout << p2;

    //ʹ�ù��캯���ڶ����汾��formΪSTONE
    //�˴���⣺C++�Զ������ݵ�ֵת��Ϊԭ����ָ�������ͣ�
    //���������߶�����������(���ó���)
    //8���Զ�ת����8.0���ٴ��빹�캯��
    Stonewt p3(21, 8);
    cout << "The p3 weighed ";
    cout << p3;

    //ʹ�ù��캯��������ת���͸�ֵ����
    p1 = 150.8;          // uses constructor for conversion
    cout << "After the change the p1 weighed ";
    cout << p1;

    Stonewt temp;
    temp = p1 + p2;
    cout << "p1+p2=" << temp;

    temp = p2 - p1;
    cout << "p2-p1=" << temp;

    temp = - p1;
    cout << "-p1=" << temp;

    temp = p1 * 2;
    cout << "p1*2=" << temp;

    temp = 2 * p1;
    cout << "2*p1="<<temp;

    cout << "The wrestler weighed even more.\n";
    //***ע***
    //422ת��Ϊ422.0��Ȼ��ʹ��Stonewt(double pds,Mode form= FLOAT_POUNDS)���캯��
    //����һ����ʱStonewt���󣬴���display()
    display(422, 2);

    //�������ģʽ����ȷ
    Stonewt p4(1.5,Stonewt::STONE);
    cout << p4;
    Stonewt p5(1,5,Stonewt::FLOAT_POUNDS);
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
//����11.9.6.cpp
#if 0
#include "11.9.6.h"

void show_report(const Stonewt *p,int num);

int main()
{
    //����һ��Stonewt���͵����飬����ʼ��ǰ��������
    Stonewt array[6]
    {
    1.1,(2.2),Stonewt(3.3)
    };

    std::cout << "�������4~6�������pounds��ֵ��";
    for (int index = 3; index < 6; index++)
    {
        while (!(std::cin >> array[index]))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "������������ݣ�\n";
        }
    }

    show_report(array,6);

    return 0;
}

void show_report(const Stonewt* p, int num)
{
    using std::cout;
    using std::endl;

    Stonewt stone11(11,0);//��154pounds
    int count = 0;

    Stonewt min, max;
    min = max = *p;

    for (int i = 0; i < num; i++)
    {
        if (*(p + i) > max)
            max = *(p+i);
        if (*(p + i) < min)
            min = *(p+i);
        if (*(p + i) >= stone11)
            count++;
    }

    cout << "\n��С������" << min << endl
        <<"���������"<<max<<endl
        <<"���ڻ����11Ӣʯ��������"<<count<<endl;
}
#endif


//7.
//����11.9.7.cpp
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