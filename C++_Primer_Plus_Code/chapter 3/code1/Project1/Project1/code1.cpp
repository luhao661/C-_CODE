#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//ʹ�����»��߿�ͷ�ı������ı����ᷢ��ʲô
#if 0
int main(void)
{
	using namespace std;
	int _ceshi=1;

	cout << _ceshi<<endl;           //�ڱ�ϵͳ���������쳣

	return 0;
}
#endif


//�����嵥3.1 �鿴���͵ĳ���
#if 1
#include <climits>              // use limits.h for older systems
int main()
{
    using namespace std;
    int n_int = INT_MAX;        // initialize n_int to max int value
    short n_short = SHRT_MAX;   // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    // cin.get();
    return 0;
}
#endif


//C++11������ʼ�������ķ�ʽ����{}��ʽ����һ��ͨ�ó�ʼ����ʽ
#if 0
int main(void)
{
    using namespace std;

    int num1 = {};
    int num2{10};
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}
#endif


//�����嵥3.2 ������Խ���͵ķ�Χ����(�������������)ʱ�����ĺ��
#if 0
#define ZERO 0        // makes ZERO symbol for 0 value
#include <climits>  // defines INT_MAX as largest int value
int main()
{
    using namespace std;
    short sam_money = SHRT_MAX;    // initialize a variable to max value
    unsigned short sue_money = sam_money;// okay if variable sam_money already defined

    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl
        << "Add $1 to each account." << endl << "Now ";
    sam_money = sam_money + 1;
    sue_money = sue_money + 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited.\nPoor Sam!" << endl;
    sam_money = ZERO;
    sue_money = ZERO;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";
    sam_money = sam_money - 1;
    sue_money = sue_money - 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥3.3 ������������ֵ
#if 0
int main()
{
    using namespace std;
    int chest = 42;     // decimal integer literal
    int waist = 0x42;   // hexadecimal integer literal
    int inseam = 042;   // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥3.4 ʹ�ÿ��Ʒ�dec��hex��oct�޸�cout��Ĭ�ϸ�ʽ(��ʮ����)
#if 0
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;      // manipulator for changing number base
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;      // manipulator for changing number base
    cout << "inseam = " << inseam << " (octal for 42)" << endl<<endl;

    inseam = 042;//�԰˽�����ʽ�洢
    cout << "inseam = " << inseam << " (octal for 042)" << endl;
    cout << dec;
    cout << "inseam = " << inseam << " (decimal for 042)" << endl;//��ʮ������ʽ��ʾ

    // cin.get();
    return 0;
}
#endif


//***ע***ʹ��using����ָ��ʱ��cout��������������������ʹ��std::coutʱ��cout����������������
#if 0
int main(void)
{
    std::cout << "����" << std::endl;
    int cout = 1;
    std::cout << cout << std::endl;

    return 0;
}
#endif


//�����嵥3.5 ʹ��char�ͱ���
#if 0
int main()
{
    using namespace std;
    char ch;        // declare a char variable

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥3.6 ʹ��cout.put()��ʾ�����ַ�
#if 0
int main()
{
    using namespace std;
    char ch = 'M';   // assign ASCII code for M to ch
    int i = ch;          // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;          // change character code in ch
    i = ch;               // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);                                                                                                //�����������滻cout<<ch
    cout << endl<<ch;
    // using cout.put() to display a char constant
    cout.put('!');
    putchar('\n');

    char ch1;
    cin >> ch1;
    int cunchudezhi_ch1=ch1;

    cout << ch1 << "ASCII��ֵ��"<<cunchudezhi_ch1<<endl;

    //��ӡ�ַ�����
    cout << 'a';
    cout.put('a');

    // cin.get();
    return 0;
}
#endif


//�����嵥3.7 ʹ��ת������
#if 0
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//ʹ��wchar_t(���ַ�����)��ʾ��չ�ַ�����ʹ��������char16_t��char32_t
#if 0
int main(void)
{
    using namespace std;
    wchar_t zifu = L'P';//P��һ�����ַ�����
    wcout << L"kuanzifuchuan" << endl;

    char16_t ch1 = u'q';
    char32_t ch2 = U'\U0000222B';
   
    return 0;
}
#endif


//�����嵥3.8 float��double��ʾ����ʱ����Чλ������Ĳ���
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-pointʹ�ö��������

    float tub = 10.0 / 3.0;     // good to about 6 places   ����6λ��Чλ
    double mint = 10.0 / 3.0;   // good to about 15 places   ����15λ��Чλ
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;                     //֤��float�����ڸ�ϵͳ���ܱ�ʾ����Чλ��ǰ7λ

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥3.9 float����������ʱ���ܲ������ȵ��½�
#if 0
int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;                                             //float�����ڸ�ϵͳ���ܱ�ʾ����Чλ��ǰ7λ������޸ĵ�23λ�����ֵû���κ�Ӱ��

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥3.10 ʹ�����������
#if 0
int main()
{
    using namespace std;
    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;

    cout << 10 / 3<<endl;                                                           //***ע***��������������������������Ϊ�̵��������֣�С�����ֱ�����
    hats = 10 / 3;//��3����ת����float�ͣ���3�������С�����0
    cout << hats<<endl;

    hats = 10.0 / 3;//��3.333333
    cout << hats << endl;

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥3.11 ��������
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9 / 5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1.e7 / 9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f / 9.0f << endl;

    cout << 1.e7 / 9.0f << endl;//�漰�������͵����㣬����ֵ�ᱻ�ֱ�ת�����������͵ĸ��߼���

    // cin.get();
    return 0;
}
#endif


//�����嵥3.12 ��ģ�����
#if 0
int main()
{
    using namespace std;
    const int Lbs_per_stn = 14;//1Ӣʯ����14��
    int lbs;

    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;      // whole stone
    int pounds = lbs % Lbs_per_stn;     // remainder in pounds
    cout << lbs << " pounds are " << stone
        << " stone, " << pounds << " pound(s).\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥3.13 ����ת��
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int converted to float                            ���Ϳ���ת���ɸ�����
    int guess = 3.9832; // float converted to int
    int debt = 7.2E12;  // ***ע***result not defined in C++   ���1��С�����ֶ�ʧ�����2��ԭ����ֵ���ܳ���Ŀ�����͵�ȡֵ��Χ������������£�������ǲ�ȷ����

    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    // cin.get();
    return 0;
}
#endif


//��{}��ʽ��ʼ������ʱ������ת��
#if 0
int main(void)
{
    using namespace std;
    //int a = {1.23};               //��������խ
    //char a={128};               //��������խ
     
    //int x = 66;
    //char a = {x};                 //������������x�Ǹ���������ֵ���ܴܺ󣬱������ж�Ϊ��intת����char����������խ   (����Ϊchar x=66�������)

    const int x = 66;          //***ע***
    char a = {x};                 //�������������������Ϊֻ������x��ֵ��66���������Ϊ#define x 66������char�ķ�Χ�ڣ��ɶ�a��ʼ��      

    cout << a << endl;

    /*int x = 128;
    char a = x;
    cout << a << endl;*/              //����ʹ��{}��ʽ��ʼ����������������խ

    return 0;
}
#endif


//�����嵥3.14 ǿ������ת��
#if 0
int main()
{
    using namespace std;
    int auks, bats, coots;// ��ȸ������ˮ��

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;                  //19.99+11.99=31.98��auks=31

    // these statements add values as int
    bats = (int)19.99 + (int)11.99;   // old C syntax               C�﷨
    coots = int(19.99) + int(11.99);  // new C++ syntax       C++���﷨
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // print as char
    cout << int(ch) << endl;                               // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;        // using static_cast

   // cin.get();
    return 0;
}
#endif