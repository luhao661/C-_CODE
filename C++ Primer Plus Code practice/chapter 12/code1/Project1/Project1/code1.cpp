#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//�����嵥12.3 �о�һ�������Ƶ���
//����12.2.cpp
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

        //����ֻ������Ĭ�ϵĸ��ƹ��캯����������ǳ����
        //���¾�̬��Ա����
        callme1(s1);
        cout << "s1: " << s1 << endl;
        callme2(s2);
        cout << "s2: " << s2 << endl;

        cout << "Initialize one object to another:\n";
        //����ֻ������Ĭ�ϵĸ��ƹ��캯����������ǳ����
        //���¾�̬��Ա���䣬ֻ�Ǹ�ֵ��ָ���ֵ(��ֱ�ӵ��º��������������ʱ������ͷ������ڴ棬�����ǲ�ȷ����)
        StringBad s4 = s1;
        cout << "s4: " << s4 << endl;

        cout << "Assign one object to another:\n";
        //����ֻ������Ĭ�ϵĸ�ֵ��������غ�����������ǳ����
        //���µĺ����������һ��
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


//�����嵥12.6 ʹ��һ���Ƚ����Ƶ�String�࣬ʵ���ַ����Ĵ洢�ͱȽ�
//����cxqd12.5.cpp
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

            while (cin && cin.get() != '\n')//���벻Ϊ������û��ȡ�����з�
                continue;

            if (!cin || temp[0] == '\0')    // empty line? ***ע***temp[0]=='\0'�����ھɰ�ʵ�֣��˴��ɲ�д
                break;              // i not incremented
            else
                sayings[i] = temp;  //ʹ�ø�ֵ��������غ��������أ������ַ���������ĸ�ֵ
        }
        int total = i;              // total # of lines read

        if (total > 0)
        {
            cout << "Here are your sayings:\n";
            for (i = 0; i < total; i++)
                cout << sayings[i][0] << ": " << sayings[i] << endl;

            int shortest = 0;//��������
            int first = 0;
            for (i = 1; i < total; i++)
            {
                if (sayings[shortest].length() > sayings[i].length())//�Ƚ��ַ�������
                    shortest = i;
                if (sayings[first] > sayings[i])//�Ƚ��ַ�������ĸ��˳��
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


//�����嵥12.7 ʹ��ָ������ָ��
//����cxqd12.5.cpp
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

        //��������ʼ��ָ������ָ��
        // use pointers to keep track of shortest, first strings
        String* shortest = &sayings[0]; // initialize to first object
        String* first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (shortest->length()>sayings[i].length())
                shortest = &sayings[i];
            if (*first>sayings[i])        // compare values
                first = &sayings[i];     // assign address
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total; // pick index at random
        //ʹ�ö�������ʼ���µ�String����
        // use new to create, initialize new String object
        String* favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;//***ע***�˴���delete����
                                 //��˵�һ�����ͷ�strָ���len��Ա�Ŀռ䣬
                                 //�����ͷ�strָ����ڴ棬
                                 //�ڶ����ŵ��������������ͷ�strָ����ڴ�
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


//�����嵥12.8 ʹ�ö�λnew����������ڶ���(��覴�)
//�����ӵ��ļ�
#if 0
#include "cxqd12.8.h"
#include <new> //��λnew������
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //ʹ��Ĭ�Ϲ��캯�������������� 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//ʹ�ù��캯����ʼ���´�������������
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" << 
        "pc1: "<<pc1<<endl<<
        "buffer: "<<(void *)buffer <<endl<<//***ע***����д(void *)�����ӡbuffer�ϴ�����ݣ�����buffer�ϴ���Ƕ����޷�ֱ�Ӵ�ӡ������˽�г�Ա�����ݣ��ʴ�ӡ��������
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);//pc3ָ��Ķ����pc1ָ��Ķ��󸲸���
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 ������������        
    delete pc4;                          // free Heap2 ������������
    delete[] buffer;                    // free buffer
    cout << "Done\n";             //***ע***
    // std::cin.get();                   //ִ��delete[] buffer;�󲻻�Ϊ��λnew�����Ķ��������������
    return 0;                              //��Ϊnew/deleteϵͳֻ֪���ѷ����512�ֽڿ�buffer������֪����λnew������ڴ����˺δ���
}
#endif


//�����嵥12.9 ʹ�ö�λnew����������ڶ���(���޸�����)
//������
#if 0
#include "cxqd12.8.h"
#include <new> //��λnew������
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //ʹ��Ĭ�Ϲ��캯�������������� 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//ʹ�ù��캯����ʼ���´�������������
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" <<
        "pc1: " << pc1 << endl <<
        "buffer: " << (void*)buffer << endl <<//***ע***����д(void *)�����ӡbuffer�ϴ�����ݣ�����buffer�ϴ���Ƕ����޷�ֱ�Ӵ�ӡ������˽�г�Ա�����ݣ��ʴ�ӡ��������
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer + sizeof(JustTesting))
        JustTesting("Better Idea", 6);//pc3ָ��Ķ����pc1ָ��Ķ��������ڴ������ص�
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 ������������        
    delete pc4;                          // free Heap2 ������������

    //��ʽ���������������봴��ʱ�෴��˳��ɾ������
    // explicitly destroy placement new objects
    pc3->~JustTesting();  // destroy object pointed to by pc3
    pc1->~JustTesting();  // destroy object pointed to by pc1

    //���ж��󶼱����ٺ󣬲����ͷ����ڴ洢��Щ����Ĵ洢��
    delete[] buffer;                    // free buffer

    return 0;                           
}
#endif


//�����嵥12.12 
//����cxqd12.11.cpp
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
    Queue line(qs);                 //���������ù��캯����ʼ��
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
    min_per_cust = MIN_PER_HR / perhour;//��ÿλ�ͻ�������ƽ��ʱ��

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
        if (wait_time <= 0 && !line.isempty())//�����п������нڵ�ʱ
        {
            line.dequeue(temp);     //�ŵ�һ���Ĺ˿��ڶ����б��ų����俪ʼ���н���
            wait_time = temp.ptime(); //wait_time�����н���������ʱ��

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
        cout << "customers accepted: " << customers << endl;//������е�����
        cout << "  customers served: " << served << endl;//�ѷ����������
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
    return (std::rand() * x / RAND_MAX < 1);//��ϸ��������C Primer Plus�������嵥17.9
}
#endif
