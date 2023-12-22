#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>//string ��
#include <cstring>// prototype for strcmp()
//
#if 1
#endif


//�����嵥5.3 ע����������ȼ�
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
}                                                           //�ھ���������λ��ϵ����λ�߼���ֵ
#endif


//�����嵥5.4 ��forѭ��ʵ�ֽ׳�(forѭ��������Эͬ����)
#if 0
const int ArSize = 16;      // example of external declaration
int main()
{
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;//0!=1��1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//�����嵥5.5 �޸Ĳ���
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


//�����嵥5.6 ��forѭ�������ַ���
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


//�����嵥5.9 ���������ַ�˳��ת
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // physically modify string object
    char temp;

    //��һ��
    //for (int i = 0, j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //������
    int i, j;
    for (       i = 0, j = word.size() - 1;                i < j;           ++i,--j       )
    {                       // start block
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }                       // end block

    //***ע***
    //for (int i = 0, int j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //����jδ������ԭ����P116

    cout << word << "\nDone\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥5.10 ע��=��==�����������
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


//�����嵥5.11 forѭ����strcmp()Эͬ����(ʹ�õ���C����ַ���)
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


//�����嵥5.12 forѭ����string���ַ���������Эͬ����(ʹ�õ���string���ַ���)
#if 0
int main()
{
    using namespace std;
    string word = "?ate";

    for (char ch = 'a'; word!= "mate"; ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥5.13 whileѭ��
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
//�����嵥5.13 whileѭ��(ʹ��string��)
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


//�����嵥5.14 ��д��ʱѭ����ʹ��wait��ʹ��clock()
#if 0
#include <ctime> // describes clock() function, clock_t type

int main()
{
    //����1��
    long wait = 0;
    while (wait < 1000000000)
        wait++;


    //����2��
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
                                                                           //CLOCKS_PER_SEC��ÿ���Ӱ�����ϵͳʱ�䵥λ��
    clock_t delay = secs * CLOCKS_PER_SEC;  // convert to clock ticks
                                                                          //����Ϊ��λ����ת��Ϊϵͳʱ�䵥λΪ��λ����
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


//�����嵥5.15 do...whileѭ��
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
    //��
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


//���ڷ�Χ��forѭ��(C++11)
#if 0
int main(void)
{
    //������ʾ�����Ԫ��
    double prices[5] = {4.99,10.99,6.87,7.99,8.49};
    for (double x : prices)
        std::cout << x << std::endl;

    putchar('\n');

    //�����޸������Ԫ�أ�����ʾ����
    for (double& x : prices)
        x = x * 0.8;
    for (double x : prices)
    std::cout << x << std::endl;

    return 0;
}
#endif


//�����嵥5.16 ��ȡ���Լ��̵��ı����룬�����ڱ��ַ�'#' (cin������հ��ַ�)
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


//�����嵥5.17 ��ȡ���Լ��̵��ı����룬�����ڱ��ַ�'#' (cin.get()�����ո��ַ�)
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


//�����嵥5.18 ��ȡ���Լ��̻��ļ����ı����룬ͨ��cin��fail()����ʾ��⵽EOF
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
//***ע***
//���Լ�������^Z��ģ��EOF�ó���ֹͣ���У�Ҳ����ֱ���������л�����<�ó������һ���ļ�
//�����л���������cd D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 5\code1\Project1\x64\Debug
//������Project1.exe<5.18.txt
#endif


//��ȡ���Լ��̻��ļ����ı����룬ͨ��C++��istream��ostream����
//����C���Ե�getchar()��putchar()���ܵĳ�Ա���������EOF
#if 0
int main()
{
    using namespace std;

    char ch;
    int count = 0;

   ch= cin.get();        

    while (ch!=EOF) 
    {
        cout.put(ch) ; 

        if(ch!='\n')
        ++count;

        ch=cin.get();
    }
    //��
    //while ((ch=cin.get()) != EOF)
    //{
    //    cout.put(ch);

    //    if (ch != '\n')
    //        ++count;
    //}

    cout << endl << count << " characters read\n";

    return 0;
}
//***ע***��ϵͳ��charĬ��Ϊ�з���char�����Կ��Դ�EOF�����-1����ch����Ϊcharû���⣬
// ����Ҫ����Ϊint ch���Ҹ�Ϊcout.put(char(ch))
#endif


//�����嵥5.20 ��������ʼ����ά���飬��ʾ��ά���������
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
    //�򷨶���
    //const char cities[Cities][25] =   // array of pointers
    //{                               // to 5 strings
    //    "Gribble City",
    //    "Gribbletown",
    //    "New Gribble",
    //    "San Gribble",
    //    "Gribble Vista"
    //};
    //������
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