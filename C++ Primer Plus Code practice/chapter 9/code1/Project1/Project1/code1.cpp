#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//�����嵥9.1 ʹ��ͷ�ļ�
#if 0
#include "CXQD9.1.h" // structure templates, function prototypes
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


//�����嵥9.4 �Զ�����ֻ�ڰ������ǵĺ����������пɼ�
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


//�����嵥9.5 �ⲿ���ӵľ�̬����
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


//�����嵥9.6 �ڲ����ӵľ�̬������������(����)�ⲿ���ӵľ�̬����
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


//�����嵥9.9 ʹ�������ӵľ�̬����
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
        cin.get(next);          //��ȡ���з��������ݳ��ȹ���ʱ��ȡ���µĵ�һ���ַ�
        while (next != '\n')    //���������ַ�
            cin.get(next);      

        strcount(input);

        cout << "Enter next line (empty line to quit):\n";//***ע***��get()��ȡ���к�����ʧЧλ
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

    static int total = 0;        // static local variable ֻ���ڵ�һ�ε��ú���ʱ���г�ʼ��

    cout << "\"" << str << "\" contains ";

    int count = 0;               // automatic local variable
    while (*str++)               // go to end of string
        count++;

    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}
#endif


//�����嵥9.10 new������ı��塪����λnew�����
#if 0
#include <new> // for placement new ��λnew�������ԭ��

const int LSIZE = 512;
char buffer[LSIZE];      // chunk of memory �洢��һ�����ڴ洢��̬�������ڴ���

const int SIZE = 5;

int main()
{
    using namespace std;

    double* pd1, * pd2;
    int i;

    cout << "Calling new and placement new:\n";
    pd1 = new double[SIZE];                // use heap 
                                                              //�Ӷ��з��䵽����Ҫ����ڴ��
    pd2 = new (buffer) double[SIZE];  // use buffer array 
                                                              //��buffer�����з���ռ��
                                                              //һ������SIZE��Ԫ�ص�double����
    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;

    cout << "Memory addresses:\n"
        << "(pd1)heap: " << pd1 << endl
        << "   buffer: " << (void*)buffer <<endl//ǿ������ת����ʹcout��ʾ��ַ�������ַ���
        <<"      pd2: "<<pd2
        << endl;

    cout << "Memory contents:\n";
    cout << "pd1ָ�������               pd2ָ������飺\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double* pd3, * pd4;
    pd3 = new double[SIZE];                // find new address
                                                              //�Ӷ��з��䵽����Ҫ����µ��ڴ��
    pd4 = new (buffer) double[SIZE];  // overwrite old data
                                                              //�ٴδ�buffer�����з���ռ��
                                                              //һ������SIZE��Ԫ�ص�double����
    for (i = 0; i < SIZE; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;

    cout << "Memory contents:\n";
    cout << "pd3ָ�������             pd4ָ������飺\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;                                    //�ͷ�pd1ָ����ڴ�飬������ɾ��pd1ָ�뱾��
    pd1 = new double[SIZE];                //�Ӷ��з��䵽����Ҫ����µ��ڴ��
    pd2 = new (buffer + SIZE * sizeof(double)) double[SIZE];
                                                             //�ٴδ�buffer�����з���ռ��
                                                             //һ������SIZE��Ԫ�ص�double����
                                                             //***ע***
                                                             //��λ����buffer��ͷλ������ƫ����ΪSIZE * sizeof(double)��λ��
                                                             //SIZE * sizeof(double)����40�ֽڣ���ʮ�����Ʊ�ʾ��0x28
    
    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;

    cout << "Memory contents:\n";
    cout << "pd1ָ�������             pd2ָ������飺\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete[] pd1;
    delete[] pd3;

    //***ע***
    //���ܼ���delete[] pd2; ��  delete[] pd4;
   //������������Ϊbuffer�ڴ洢��̬�������ڴ��У���������new����Ķ���

    return 0;
}
#endif


//�����嵥9.13 ���ƿռ������
#if 0
#include <iostream>
#include "cxqd9.13.h"

void other(void);
void another(void);

int main(void)
{
    using debts::Debt;
    using debts::showDebt;//Ҫʹ�����ƿռ��еĺ�����Ҳֻ���������
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
    using namespace debts;//using����ָ����пɴ����ԣ�
                                             //���Դ����ɵ������ƿռ�debts�����ƿռ�pers

    Person dg = { "Doodles", "Glister" };
    showPerson(dg);
    cout << endl;

    Debt zippy[3];//����һ���ṹ����
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
    using pers::Person;//ʹ��using����

    Person collector = { "Milo", "Rightshift" };

    pers::showPerson(collector);//ʹ����������������::
    std::cout << std::endl;
}
#endif