#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//(void *)���ڴ�ӡ��ַ����ֵ��ʾ
//������
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


//�����嵥17.1 ʹ��write()�����ʾ�ַ�
//������
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

    //write()�����������������ַ�ʱֹͣ��ӡ�ַ�
    //���Ǵ�ӡָ����Ŀ���ַ�
    // exceed string length
    cout << "Exceeding string length:\n";
    cout.write(state2, len2 + 5) << endl;//��ʾ��Kansas

    //write()Ҳ��������ֵ����
    long val = 560031841;//long����ռ4���ֽ�
    //��4���ֽڽ�һ���ֽ�һ���ֽڵؽ��д���
    //���������ÿ���ֽڵ�ASCII��Ľ���
    cout.write( (char*)&val, sizeof(long));
    // std::cin.get();
    return 0;
}
#endif


//ǿ��ˢ�»�����:endl��flush
//������
#if 0
using namespace std;

int main()
{
    cout << "123" << endl;
    cout << "456" << flush;

    return 0;
}
#endif


//�����嵥17.2 Ĭ�ϵ�cout�����ʽ
//������������λ�������ʾ6λ��С�����ֽ�β��0����ʾ��
//����λ��ѡ�񶨵���������ѧ������(E������)(����ֻ��ʾ6λ�ĸ�����)
//������
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


//�����嵥17.3 ʹ�ÿ��Ʒ��޸���������ϵͳ
//������
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
    dec(cout);//(д����)
    cout << n << "     " << n * n << " (decimal)\n";

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥17.4 ʹ��width()�����޸��ֶο��
//������
#if 0
int main()
{
    using std::cout;

    //***ע***
    //width()����ֻӰ���������ʾ��һ����Ŀ

    int w = cout.width(30);//����֮ǰ���ֶο��
    cout << "default field width = " << w << ":\n";

    cout.width(5);
    cout << cout.width()<<std::endl;//���ص�ǰ�ֶο��
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


//�����嵥17.5 ʹ��fill()�����޸��ֶ��������ַ�
//������
#if 0
int main()
{
    using std::cout;

    //***ע***
    //fill()����������Ч

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


//�����嵥17.6 ʹ��precise()�����޸ĸ���������ʾ����
//***ע***
//�˴����õ���Ĭ��ģʽ�µľ��ȣ�����λ�����Ϊ6λ
//������
#if 0
int main()
{
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    float f = 100000.1;
    cout << f << std:: endl;//ֻ��ʾ100000

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";

    //***ע***
    //precise()����������Ч

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";
    // std::cin.get();
    return 0;
}
#endif


//�����嵥17.7 ʹ��ios_base���setf()��������showpoint��ʽ����
//ʹcout��ʾĩβС���㣬���Ⱥ���ʱ������ʾС�����ֽ�β��0
//�˴�����ָ����Ĭ��ģʽ�µľ��ȣ�����λ��
//������
#if 0
int main()
{
    using std::cout;
    using std::ios_base;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    //showpoint��ios_base�������ж�����༶��̬����
    //����Ҫ����ʱҪ����������������

    //***ע***
    //��ʽ�����Ա�ǵ��޸ĳ�����Ч

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


//�����嵥17.8 ʹ�����ƿռ�std�е�ios_base���е�
//һЩ���ڳ���(��ʽ����)���setf()�����Ƹ�ʽ��
//������
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

    cout.setf(std::ios_base::boolalpha);//���Ƹ�ʽΪboolֵ����true��false
    cout << true << "!\n";
    // std::cin.get();
    return 0;
}
#endif


//�����ʾ��(������)�Ϳ�ѧ��ʾ��(������)��Ĭ�ϵı�ʾ��������
//������
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

    //С��������Ϊ6λ��
    //��ʾĩβ��0
    
    return 0;
}
#endif


//�����嵥17.9 ʹ�ý�������������setf()
//������
#if 0
#include <cmath>

int main()
{
    using namespace std;
    // use left justification, show the plus sign, show trailing
    // zeros, with a precision of 3
    cout.setf(ios_base::showpos);//��ʾ����ǰ��+
    cout.setf(ios_base::showpoint);//��ʾĩβ��С����
    cout.precision(3);//������Ϊ3����λ��Ϊ3

    //�����
    cout.setf(ios_base::left, ios_base::adjustfield);
    //����ԭ���ĸ�ʽ
    //use e-notation and save old format setting
    ios_base::fmtflags old = 
    //E��������ָ������������ô���ȵ���˼��С������λ��Ϊ3
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

    //���Ż����ǰ׺����룬ֵ�Ҷ���
    // change to internal justification
    cout.setf(ios_base::internal, ios_base::adjustfield);

    //ʹ��Ĭ�ϼ�����
    // restore default floating-point display style    
    //***ע***    
    //�Ա������������
#if 1
    cout.setf(old, ios_base::floatfield);
    //����floatfield��ص�λ����Ϊԭʼ��ʽ����Ĭ�ϼ�����
#endif    

#if 0
    cout.setf(old);
    //***ע***
    //old��ĸ�ʽ��
    //��ʾ����ǰ�� +
    //��ʾĩβ��С����
    //����Ϊ3
    //�����
    //Ĭ�ϼ�����
    
    //����ʱ�������cout.setf(ios_base::internal, ios_base::adjustfield);
    //Ҫע�͵������������ͷ��Ż�����ֵ�Ҷ���������λ��������
    //���յ���ʾЧ�������Ҷ���
    //��Ϊʲô��ʾ�Ļ��ǿ�ѧ������������
    //��Ϊ��ѧ��������Ӧ��λ��û����0

#endif    

    cout << "Internal Justification:\n";
    for (n = 1; n <= 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    //�Ҷ��룬
    cout.setf(ios_base::right, ios_base::adjustfield);
    //ʹ�ö��������
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


//����cout.setf()�ķ���ֵ��ϸ��
//������
#if 0
using namespace std;

int main()
{
    ios_base::fmtflags initial;

    cout << 10 << ' ' << 15.0 << '\n';
    initial = cout.setf(ios_base::fixed);
    cout << 10 << ' ' << 15.0 << '\n';
    //***ע***
    //����initial�����ԭ����Ĭ�ϼ�����
    //���� initial = cout.setf(ios_base::fixed); ����ʽ����Ϊ
    //�����������cout.setf(initial);�����Ὣ�����������Ӧ��λ��0
    //�������Ч�����Ƕ��������
    cout.setf(initial);
    cout << 10 << ' ' << 15.0 << '\n';

    return 0;
}
#endif


//�����嵥17.10 �����������ʽ�����
//һ��ʹ�ñ�׼���Ʒ��򻯽�������������setf()����
//����ʹ��ͷ�ļ�iomanip���ṩ�Ŀ��Ʒ�
//��ʹ��precise()��width()��fill()����
//��Ϊʹ��setprecise()��setfill()��setw()���ܲ����Ŀ��Ʒ�
//������
#if 0
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;

    //ʹ�ñ�׼���Ʒ����cout.setf(... , ...);
    // use new standard manipulators
    cout << fixed << right;

    //ʹ��ͷ�ļ�iomanip���ṩ�Ŀ��Ʒ�
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


//�����嵥17.11 cin>>��μ������
//������
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

    //�Ա�C���Ե�scanf("%d",&num)
#if 0
    int num;
    scanf("%d",&num);

    cout << num;//����123z����numΪ123
#endif
    return 0;
}
#endif


//�����嵥17.12 I/O���쳣
//������
#if 0
#include <exception>

int main()
{
    using namespace std;

    //��״̬��3��ios_baseԪ�����
    
    //rdstate()��Ա������exceptions()��Ա����
    cout << cin.rdstate() << endl;
    cout << cin.exceptions() << endl;

    //exceptions()��Ա����
    //����һ��λ���룬ָ����Щ��ǿ��Ե����쳣������
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
    //***ע***
    //cin >> input�������ܻ��޸�����
    //�޸����漰����clear(...)
    //clear()��������ǰ��״̬��exceptions()���ص�λ�ֶ�
    //(������λ״̬)���бȽ�
    //ǰ���cin.exceptions(ios_base::failbit);
    //��ʾfailbitλ�쳣�ܱ���Ӧ�����ص�λ�ֶε�failbitλ�ѱ�����
    //��clear()�����ṩ�ĵ�ǰ��״̬��failbitҲ�����ã���
    //clear()������ios_base::failure�쳣
    //ios_base::failure�Ǹ��࣬��std::expection������������
    //��what()����
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


//�����嵥17.13 ʹ��ignore()����
//������
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

    //ignore(... , ...)����
    //��ȡ�������������еĽ�������255���ַ������ȡ���������ݵ���β(����\n)
    if (ch != '\n')
        cin.ignore(Limit, '\n');    // discard rest of line

    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2\n";

    cin.get(ch);
    cout << "The next input character is " << ch << endl;

    //���ۣ�getline()�ᶪ���ֽ��#����get()����

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


//�����嵥17.14 ʹ��putback()��peek()����ʵ��ͬһ�ִ�����
//������
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
        {                                  //������#����#�Żص������ַ�����
            cin.putback(ch);    // reinsert character
            break;
        }
    }

    if (!cin.eof())//���Ƕ����ֽ��#���˳�ѭ��
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else//���Ƕ����ļ�β���˳�ѭ��
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#')    // look ahead
    {
        cin.get(ch);
        cout << ch;
    }

    if (!cin.eof())//���Ƕ����ֽ��#���˳�ѭ��
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else//���Ƕ����ļ�β���˳�ѭ��
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


//�����嵥17.15 ʹ��peek()��ȷ���Ƿ��ȡ������
//������
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


//�����嵥17.16 ʹ��ofstream��ifstream����
//������
#if 0
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename;

    cout << "Enter name for new file: ";
    cin >> filename;

    //д��һ��
    ofstream fout;
    fout.open(filename.c_str());

    //д������(ʹ�ù��캯��)
    // create output stream object for new file and call it fout
    //ofstream fout(filename.c_str());//ʹ��c_str()������ת����C����ַ���

    fout << "For your eyes only!\n";        // write to file ������д���ļ�
    cout << "Enter your secret number: ";   // write to screen ������д����Ļ

    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;//������д���ļ�

    fout.close();           // close file �رյ��ļ�������

    // create input stream object for new file and call it fin
    ifstream fin(filename.c_str());
    
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))     // read character from file and  (�����ļ�β�ͽ���ѭ��)
        cout << ch;         // write it to screen

    cout << "Done\n";
    
    fin.close();                //�رյ��ļ�������

    return 0;
}
#endif


//�����嵥17.17 ʹ�������в���
//Ҫ���δ���һ���ļ������Դ�һ���������������ι����������ļ�
//������
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


//�����嵥17.18 ʹ��ios::out | ios::app (�� ios_base::out | ios_base::app)
//ʵ�����ļ�β׷������
//������
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

    //���ļ����ڣ�������ļ�ԭ��������
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file:\n";

        while (fin.get(ch))
            cout << ch;
        
        fin.close();
    }

    // add new names
    //��ʽ���ṩ�ڶ����������ļ�ģʽ����
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


//�����嵥17.19 ʹ�ö�����ģʽ�����Ͷ�ȡ�������ļ�
//������
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
    //ʹ�ö�����������Ҷ���
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

    // add new data ���ļ�β׷������(���ļ��������򴴽��ļ�)
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
//***ע***
//������string�������C����ַ�����name
//��Ϊstring�������һ��ָ�����д洢���ַ������ڴ浥Ԫ��ָ��
//�������ṹ��ʱ�����Ƶ�Ҳ���ַ����Ĵ洢��ַ
//���ٴ����г���ʱ����ַ������
#endif


//����fstream����󣬽���������������һ���������룬һ���������
//ʹ��tellg()��tellp()�鿴���뻺����������ָ���
//��������������ָ���λ�� 
//������
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
    //���ۣ�fstream�����tellg()��tellp()���ص�ֵ��ͬ
    return 0;
}
#endif


//�����嵥17.20 ��ʹ��fstream�������޸��ļ�����
//������
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
    //ʹ�ö��������
    cout << fixed;

    // show initial contents
    fstream finout;     // read and write streams
    finout.open(file,
         ios_base::in | ios_base::out | ios_base::binary);

    //***ע***
    //����planets.dat�ļ�����ᵼ�´��ļ�ʧ��
    //����finout.open(file,ios_base::out | ios_base::binary);
    //��򿪳ɹ���
    //�������Ϊ��ios_base::in���ļ�������ʱ���ᵼ�´��ļ�ʧ��

    int ct = 0;
    planet pl;

    if (finout.is_open())
    {
        //finout.seekg(0);    // go to beginning (�˾�ɲ�д)
        cout << "Here are the current contents of the "
            << file << " file:\n";
        while (finout.read((char*)&pl, sizeof pl))
        {
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }

        //���Ѿ������ļ�β
        if (finout.eof())
            finout.clear(); // clear eof flag ���޴���䣬
        else                     //����ʾError on attempted seek
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

    //���������Բ�д
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
    //***ע***д��finout.seekp(0);Ч����ͬ      
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
//***ע***
//Windows�����£���ȡ�ı��ĵ��������л��� "\r\n"
//�������Զ����Ƶķ�ʽ��ȡ�ͽ���"\n"
//Ҫʹ��seekg()��seekp()����������ƶ�ָ��Ļ�Ҫ�ر�ע��
//https://blog.csdn.net/Iwanaabigdrumstick/article/details/64476805


//ʹ����ʱ�ļ�
//������
#if 0
#include <cstdio>

using namespace std;

int main()
{
    cout << "��ϵͳ���������" <<TMP_MAX<<"�����ظ����ļ�����";
    cout <<"ÿ���ļ����������"<< L_tmpnam << "���ַ�"<<endl;

    char Name[L_tmpnam] = {'\0'};

    for (int i = 0; i < 10; i++)
    {
        tmpnam(Name);
        cout << Name << endl;
    }

    return 0;
}
#endif


//�����嵥17.21 �ں˸�ʽ������д�����ݵ�ostringstream����
//��ȡstring�����еĸ�ʽ����Ϣ�򽫸�ʽ����Ϣд��string���󱻳�Ϊ�ں˸�ʽ��(incore formatting)
//�����֮��istringstream �� ostringstream ��ʹ���ܹ�ʹ��
//istream �� ostream ��ķ���������洢���ַ����е��ַ����ݡ�
//������
#if 0
#include <sstream> //ostringstream��
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

    //��string����д����Ϣ
    // write formatted information to string stream
    outstr << "The hard disk " << hdisk << " has a capacity of "
        << cap << " gigabytes.\n";

    string result = outstr.str();   // save result
    cout << result;                 // show contents

    outstr << "���Լ���д��\n";
    cout << outstr.str();

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥17.22 �ں˸�ʽ��������istringstream�����������
//������
#if 0
#include <sstream>
#include <string>

int main()
{
    using namespace std;

    string lit = "It was a dark and stormy day, and "
        " the full moon glowed brilliantly. ";

    //istringstream����ʹ��string������г�ʼ��
    istringstream instr(lit);   // use buf for input
    
    string word;
    while (instr >> word)       // read a word a time
        cout << word << endl;
    // cin.get();
    return 0;
}
#endif