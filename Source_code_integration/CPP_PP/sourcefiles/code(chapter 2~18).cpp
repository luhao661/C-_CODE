#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//chapter
//code


//chapter 2
//code1.cpp
#if 1
//�����嵥2.1 ����C++����
//��һ��ʹ��std::ǰ׺
#if 0
#include <iostream>
int main()
{
	std::cout << "����һ��C++����";
	std::cout << std::endl;
	std::cout << "�㲻���ڵģ�" << std::endl;

	return 0;
}
#endif
//������ʹ��using����ָ��
#if 0
#include <iostream>
int main()
{
	using namespace std;//���ƿռ����ָ��		����std���ƿռ��е��������ƶ�����
	cout << "����һ��C++����";
	cout << endl;
	cout << "�㲻���ڵģ�" << endl;

	return 0;
}
#endif
//����(�Ľ�)��ʹ��using����
#if 0
#include <iostream>//C++����ͷ�ļ����������ƿռ�std��������cout,endl
int main()
{
	using std::cout;//using����ֻʹ��������ƿ���		ʹ�����ƿռ�std�е�Ԥ�������cout��cout��ʾ���������Ϊ "c out"����׼���
	using std::endl;//ʹ�����ƿռ�std�еĿ��Ʒ�endl

	cout << "����һ��C++����";
	cout << endl;
	cout << "�㲻���ڵģ�" << endl;

	return 0;
}
#endif


//�����嵥2.2 ������ʹ�ñ�����ʹ��cout��ӡ������ֵ
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	carrots = 25;

	cout << "I have ";
	cout << carrots;
	cout << " carrots\n";

	carrots -= 1;
	cout << "����1���������һ���" << carrots << "�����ܲ�(carrots)" << endl;

	return 0;
}
#endif


//�����嵥2.3 ʹ��cin
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	cout << "���ж��ٸ����ܲ��� ";
	cin >> carrots;
	//д��1��
	//cout << "����1���������һ���" << carrots-1 << "�����ܲ�(carrots)" << endl;
	//д��2��(�����ڳ�������)
	cout << "����1���������һ���"
		<< carrots - 1
		<< "�����ܲ�(carrots)"
		<< endl;

	return 0;
}
#endif


//�����嵥2.4 ����C���еĺ���
#if 0
#include <iostream>
#include <cmath>

int main(void)
{
	using namespace std;

	double area;
	cout << "������һ������0��С����";
	cin >> area;

	double side;
	side = sqrt(area);
	cout << "����������ƽ������";
	cout << side << endl;

	return 0;
}
#endif


//�����嵥2.5 �����û��Զ���ĺ���(1)
#if 0
#include <iostream>
void function(int);
//��дΪ��
//using namespace std;//����д�Ļ��������������ܷ������ƿռ�std

int main(void)
{
	using namespace std;

	function(3);

	cout << "���������֣�";
	int n;										//***ע***���������ܺͺ�������ͬ�������������֪��Ӧ���ñ������Ǹõ��ú���
	cin >> n;									//������ͬһ��������ͬʱ��cout�����������ͱ����������������Ҳ���Ϳ
	function(n);
	//�ؼ���(��int return��)����������
	return 0;
}
void function(int n)
{
	using namespace std;

	cout << "��ʾ��";
	cout << n << endl;
}
#endif


//�����嵥2.6 �����û��Զ���ĺ���(2)
#if 0
#include <iostream>
int function(int);

int main(void)
{
	using namespace std;

	cout << "���������֣�";
	int n;
	cin >> n;
	n = function(n);
	cout << "����2���󣬵õ�" << n << endl;

	return 0;
}
int function(int n)
{
	n *= 2;

	return n;//��return n*=2;
}
#endif
#endif


//chapter 2
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//2.7�����ϰ
//1.
#if 0
int main(void)
{
	using std::cout;
	cout << "����";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "������һ����longΪ��λ�ľ��룺";
	int distance;
	cin >> distance;
	cout << "���������൱��" << distance * 220 << "��";

	return 0;
}
#endif


//3.
#if 0
using namespace std;
void function1(void);
void function2(void);

int main(void)
{
	function1();
	function1();
	function2();
	function2();

	return 0;
}
void function1(void)
{
	cout << "Three blind mice" << endl;
}
void function2(void)
{
	cout << "See how they run\n";
}
#endif


//4.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter your age: ";
	int age;
	cin >> age;
	cout << "�����������" << age * 12 << "����";

	return 0;
}
#endif



//5.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "�����������¶�ֵ��";
	double temperature;
	cin >> temperature;
	cout << temperature << "���൱��" << function(temperature) << "���϶�";

	return 0;
}
double function(double num)
{
	return num * 1.8 + 32.0;
}
#endif


//6.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "���������ֵ��";
	double light_years;
	cin >> light_years;
	cout << light_years << "����=" << function(light_years) << "���ĵ�λ";

	return 0;
}
double function(double num)
{
	return num * 63240;
}
#endif


//7.
#if 0
using namespace std;
void function(int a, int b);

int main(void)
{
	int a, b;
	cout << "Enter the number of hours: ";
	cin >> a;
	cout << "Enter the number of minutes: ";
	cin >> b;
	function(a, b);

	return 0;
}
void function(int a, int b)
{
	cout << "Time : " << a << ":" << b;				//***ע***�޷���ֵ�ĺ������Բ�ʹ��return��䣬�������������е����һ�䣬Ȼ���Զ�����
	//return;
}
#endif
#endif


//chapter 3
//code1.cpp
#if 1
#include <iostream>
//
#if 1
#endif


//ʹ�����»��߿�ͷ�ı������ı����ᷢ��ʲô
#if 0
int main(void)
{
    using namespace std;
    int _ceshi = 1;

    cout << _ceshi << endl;           //�ڱ�ϵͳ���������쳣

    return 0;
}
#endif


//�����嵥3.1 �鿴���͵ĳ���
#if 0
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
    int num2{ 10 };
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
    cout << "inseam = " << inseam << " (octal for 42)" << endl << endl;

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
    cout << endl << ch;
    // using cout.put() to display a char constant
    cout.put('!');
    putchar('\n');

    char ch1;
    cin >> ch1;
    int cunchudezhi_ch1 = ch1;

    cout << ch1 << "ASCII��ֵ��" << cunchudezhi_ch1 << endl;

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

    cout << 10 / 3 << endl;                                                           //***ע***��������������������������Ϊ�̵��������֣�С�����ֱ�����
    hats = 10 / 3;//��3����ת����float�ͣ���3�������С�����0
    cout << hats << endl;

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
    char a = { x };                 //�������������������Ϊֻ������x��ֵ��66���������Ϊ#define x 66������char�ķ�Χ�ڣ��ɶ�a��ʼ��      

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
#endif


//chapter 3
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//3.6��ϰ��
//5.
#if 0
int main(void)
{
    using namespace std;

    char grade1 = 65;
    char grade2 = 'A';

    cout << grade1 << endl;
    cout << grade2 << endl;			//˵�������������ͨ��

    return 0;
}
#endif


//6.
#if 0
int main(void)
{
    using namespace std;
    cout.put(88);//��һ						��дΪ��cout.put((char)88);
    putchar('\n');
    cout << (char)88;//����
    putchar('\n');
    char ch = 88;
    cout << ch;//����

    return 0;
}
#endif


//7.
#if 0
#include <climits>
//�к궨�壺
//#define LONG_MAX      2147483647L										��10λ��Чλ��double���͵ı������Ա�ʾ����û���������
//#define LLONG_MAX     9223372036854775807i64				��19λ��Чλ������double���͵ı��������������

int main(void)
{
    long int a = 123456789;
    //float b = a;//����	C4244	����ʼ���� : �ӡ�long��ת������float�������ܶ�ʧ����	

    //double b = a;//�޾���
    double b = 123456789123456789LL;//����	C4305	����ʼ���� : �ӡ�__int64������double���ض�

    return 0;
}
#endif


//9.
#if 0
int main(void)
{
    double x1 = 1.6;
    double x2 = 2.5;

    int a;
    a = (int)x1 + (int)x2;

    int b;
    b = x1 + x2;				//��b=(int)(x1+x2);

    std::cout << a;
    putchar('\n');
    std::cout << b;

    return 0;
}
#endif
#endif


//chapter 3
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//�����ϰ
//4.
#if 0
int main(void)
{
    using namespace std;

    long seconds;
    cout << "������������";
    cin >> seconds;
    int days, hours, minutes, temp;

    temp = seconds;

    const int day_to_seconds = 86400;
    const int hour_to_seconds = 3600;
    const int minute_to_seconds = 60;

    days = seconds / day_to_seconds;
    seconds = seconds % day_to_seconds;
    hours = seconds / hour_to_seconds;
    seconds = seconds % hour_to_seconds;
    minutes = seconds / minute_to_seconds;
    seconds %= minute_to_seconds;

    cout << temp << "seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

    return 0;
}
#endif


//7.
#if 1
int main(void)
{
    using namespace std;

    cout << "������ÿ�ٹ������ĵ�������(��)��";
    double E_consume;
    cin >> E_consume;										//��λ��(��/100����)

    const double Seng_to_Jialun = 1.0 / 3.785;
    const double Gongli_to_Yinli = 0.6214;

    auto temp = E_consume * Seng_to_Jialun; //��λ��(����/100����)
    temp /= 100;//ÿһ�������(����)				   ��λ��(����/����)
    temp = 1 / temp;											//��λ��(����/����)

    auto A_consume = temp * Gongli_to_Yinli;//��λ��(Ӣ��/����)

    //������
    //double A_consume = 62.14 / (E_consume/3.785);

    cout << "�൱��" << A_consume << "mpg";

    return 0;
}
#endif
#endif


//chapter 4
//code1.cpp
#if 1
#include <iostream>
//
#if 1
#endif


//�����嵥4.1 ʹ������
#if 0
int main()
{
    using namespace std;
    int yams[3];    // creates array with three elements
    yams[0] = 7;   // assign value to first element                                             //����ĸ�ֵ
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = { 20, 30, 5 }; // create, initialize array                            //����ĳ�ʼ��                                                                                                                                                                    
// NOTE: If your C++ compiler or translator can't initialize
// this array, use static int yamcosts[3] instead of int yamcosts[3]

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n";

    char petkind[2][2] = { '\0' };
    petkind[1][0] = 'a';
    printf("%s", petkind[1]);                                                                //֤��petkind�����ʼ����Ԫ�ض�Ϊ'\0'
                                                                                                           //ԭ�򣺲��ֳ�ʼ����������������δ��ʽ�س�ʼ����Ԫ�ؾ���Ϊ0
    // cin.get();                                                                                    //��ASCII��0����Ӧ�������ǿ��ַ���
    return 0;
}
#endif


//�����嵥4.2 ʹ���ַ�������
#if 0
#include <cstring>  // for the strlen() function
int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];                             // empty array(���������ֵ)
    char name2[Size] = "C++owboy";  // initialized array
    // NOTE: some implementations may require the static keyword
    // to initialize the array name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';                // set to null character
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥4.3 ��cin��ȡ�ַ����������ʱֻ���ȡһ������
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥4.4 ��cin.getline()��ȡһ���ַ�����
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);  // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥4.5 ��cin.get()��ȡһ���ַ�����
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.get(name, ArSize);    // read string, newline
    cin.get();                                                                  //д��һ

    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, ArSize).get();                                 //д����

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥4.6 ��϶����ַ�������
#if 0
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();//��cin.get(ch);                  
                  //���������Ա����ƴ��д��(cin>>year).get()                 Ŀ�������ĵ����뻺�����Ļ��з�

    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}
#endif


//�����嵥4.7 ʹ��string���͵ı������洢�ַ���(ÿ�ζ���һ������)��string�������ַ�����֮����ͬ
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;

    char char_arr1[20];                    // create an empty array
    char char_arr2[20] = "ceshi1"; // create an initialized array
    string str1;                                 // create an empty string object ����һ��string���͵ı���str1          (����һ��string��Ķ���str1)
    string str2 = "ceshi2";              // create an initialized string ��������ʼ��һ��string���͵ı���str2

    cout << "Enter a kind of feline: ";
    cin >> char_arr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;                                // use cin for input    ***ע***ʹ�������str1�ĺô��ǣ�str1�ĳ��ȿɸ��������Զ�����
    cout << "Here are some felines:\n";
    cout << char_arr1 << " " << char_arr2 << " "
        << str1 << " " << str2         // use cout for output
        << endl;
    cout << "The third letter in " << char_arr2 << " is "
        << char_arr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
        << str2[2] << endl;              // use array notation ����Ԫ�صķ���Ҳ��������ֵ

    return 0;
}
#endif


//�����嵥4.8 string�����������(���������)
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;
    string s1{ "penguin" };//�����string��������ʹ���б��ʼ��
    string s2, s3;

    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;//ͨ��ʹ��string����󣬿���ֱ����=�ſ����ַ���
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";//string�����֧��C���ĳ�ʼ����ʽ
    cout << "s2: " << s2 << endl;

    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;//ͨ��ʹ��string����󣬿���ֱ����+��ƴ���ַ���
    cout << "s3: " << s3 << endl;
    cout << "You can append strings.\n";
    s1 += s2;//ͨ��ʹ��string����󣬿���ֱ����+=�Ű�s2�ַ������ӵ�s1�ַ���
    cout << "s1 += s2 yields s1 = " << s1 << endl;
    s2 += " for a day";//S2�ַ���������Ϊ������һ���ַ���������
    cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

    //cin.get();
    return 0;
}
#endif


//�����嵥4.9 �Ա������ַ�����ļ���������string����ļ���
#if 0
#include <string>               // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // assignment for string objects and character arrays  (assignment����ֵ�������Ϊ����)
    str1 = str2;                        // copy str2 to str1
    strcpy(charr1, charr2);     // copy charr2 to charr1

    // appending for string objects and character arrays
    str1 += " paste";             // add paste to end of str1
    strcat(charr1, " juice");   // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();         // obtain length of str1                            //��ʽ��   �������.�෽��
    int len2 = strlen(charr1);  // obtain length of charr1

    cout << "The string " << str1 << " contains "
        << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains "
        << len2 << " characters.\n";
    // cin.get();

    return 0;
}
#endif


//�����嵥4.10 ʹ��string���͵ı������洢�ַ���(ÿ�ζ���һ��)
#if 0                                       //�Աȳ����嵥4.7 ʹ��string���͵ı������洢�ַ���(ÿ�ζ���һ������)
#include <string>                // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
        << strlen(charr) << endl;//***ע***δ��ʼ���������������δ�����(����ֵ)��strlen()�����ַ������Կ��ַ����ֵ�λ���������
    cout << "Length of string in str before input: "
        << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length     //�ɲο������嵥4.4 ��cin.getline()��ȡһ���ַ�����
    cout << "You entered: " << charr << endl;                //***ע***cin.getline()�Ǵ����ַ�������ĺ���

    cout << "Enter another line of text:\n";
    getline(cin, str);          // cin now an argument; no length specifier   //getline()�����෽��
    cout << "You entered: " << str << endl;                    //***ע***getline(cin,str)�Ǵ���string�����ĺ���

    cout << "Length of string in charr after input: "
        << strlen(charr) << endl;
    cout << "Length of string in str after input: "
        << str.size() << endl;
    // cin.get();

    return 0;
}
#endif


//ʹ��C++�������ͣ�ԭʼ�ַ���
#if 0
int main(void)
{
    using namespace std;

    cout << R"(��ʹ��ת���������""     \n   "\n")" << endl << '\n';

    cout << "ʹ��ת���������" << "\"\"   \\n  \"\\n\"\n\n";

    return 0;
}
#endif


//�����嵥4.11 ʹ�ýṹ
#if 0
#include <string>
struct inflatable   // structure declaration ����һ�����Ϊinflatable�Ľṹ����(�ṹģ��)
{
    char name[20];
    float volume;
    double price;
};

struct ceshi
{
    std::string name;//string�����Ҳ������Ϊ�ṹ��Ա   ǰ�����������#include <string>�������ṩһ��using����ָ�������std::string��������
    float volumn;
};

int main()
{
    using namespace std;
    inflatable guest =                              //��������ʼ��һ����inflatable�ṹ���ֵĽṹ����
    {
        "Glorious Gloria",  // name value
        1.88,               // volume value
        29.99               // price value
    };  // guest is a structure variable of type inflatable
        // It's initialized to the indicated values
    inflatable pal                                     //C++11֧�ֽ��б��ʼ�����ڽṹ����=�ſɲ�д
    {
        "Audacious Arthur",
        3.12,
        32.99
    };  // pal is a second variable of type inflatable



    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    // pal.name is the name member of the pal variable
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥4.12 �����ṹ
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable bouquet =
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;

    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;  // assign one structure to another �����ṹ
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥4.13 ʹ�ýṹ����
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2] =          // initializing an array of structs
    {
        {"Bambi", 0.5, 21.99},      // first structure in array
        {"Godzilla", 2000, 565.99}  // next structure in array
    };

    cout << "The guests " << guests[0].name << " and " << guests[1].name
        << "\nhave a combined volume of "
        << guests[0].volume + guests[1].volume << " cubic feet.\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥4.14 ʹ��&�����
#if 0
int main()
{
    using namespace std;
    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cups)
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥4.15 ʹ��ָ��
#if 0
int main()
{
    using namespace std;
    int updates = 6;        // declare a variable
    int* p_updates;        // declare pointer to an int

    p_updates = &updates;   // assign address of int to pointer ��ָ�������ֵ

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥4.16 ��ʼ��ָ��
#if 0
int main()
{
    using namespace std;
    int higgens = 5;
    int* pt = &higgens;

    cout << "Value of higgens = " << higgens
        << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
        << "; Value of pt = " << pt << endl;
    // cin.get();
    return 0;
}
#endif


//C++����ָ�븳ֵ���������ϸ�
#if 0
int main(void)
{
    int* pt;
    //pt = 0x00b8;     //C������C++������  �������ܽ���������ָ��int���͵�ָ��
    pt = (int*)0x00b8;//C++������Ϊ��ֵ������߶��������ĵ�ַ
                                  //***ע***ָ��pt��������Ͳ�һ����int
    return 0;
}
#endif


//�����嵥4.17 ʹ��C++��new��delete�����
#if 0
int main()
{
    using namespace std;

    int nights = 1001;
    int* pt = new int;         // allocate space for an int
    *pt = 1001;                 // store a value there

    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double* pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    delete(pt);
    delete(pd);

    // cin.get();
    return 0;
}
#endif


//�����嵥4.18 ʹ�ö�̬���鲢���������е�Ԫ��
#if 0
int main()
{
    using namespace std;

    double* p3 = new double[3]; // space for 3 doubles
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";                          //��д����*(p3+1)

    p3 = p3 + 1;                  // increment the pointer

    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 - 1;                  // point back to beginning

    delete[] p3;                 // free the memory
    // cin.get();
    return 0;
}
#endif


//�����嵥4.19 ָ������
#if 0
int main()
{
    using namespace std;

    double wages[3] = { 10000.0, 20000.0, 30000.0 };
    short stacks[3] = { 3, 2, 1 };

    // Here are two ways to get the address of an array
    double* pw = wages;     // name of an array = address
    short* ps = &stacks[0]; // or use address operator with array element

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";//ʹ�����������ֵ��������Ԫ��
    cout << "stacks[0] = " << stacks[0]
        << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";//ʹ��ָ���ʾ����������Ԫ��
    cout << "*stacks = " << *stacks
        << ", *(stacks + 1) =  " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    // cin.get();
    return 0;
}
#endif


//�����嵥4.20 ������̬�ַ�������
#if 0
#include <cstring>              // declare strlen(), strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";   // animal holds bear
    const char* bird = "wren"; // bird holds address of string
    char* ps;                  // uninitialized

    cout << animal << " and ";  // display bear
    cout << bird << "\n";       // display wren
    // cout << ps << "\n";      //may display garbage, may cause a crash

    //�����ַ���
    cout << "Enter a kind of animal: ";
    cin >> animal;              // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps doesn't point to allocated space

    ps = animal;                // set ps to point to string
    cout << ps << "!\n";       // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;//ǿ������ת����Ŀ������ʾ�ַ����ĵ�ַ
    cout << ps << " at " << (int*)ps << endl;

    //����ַ����ĸ���
    ps = new char[strlen(animal) + 1];  // get new storage
    strcpy(ps, animal);         // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;                   //������ʹ��C����ַ������Աȳ����嵥4.8��4.9��
                                                                                             //C++string���͸�Ϊ��
    delete[] ps;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥4.21 ��new������̬�ṹ
#if 0
struct inflatable   // structure definition
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;

    inflatable* ps = new inflatable; // allot memory for structure
    //��
    //struct inflatable* ps = new inflatable;

    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);            // method 1 for member access

    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;               // method 2 for member access

    cout << "Enter price: $";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;                        // method 2
    cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
    cout << "Price: $" << ps->price << endl;                        // method 1
    delete ps;                        // free memory used by structure
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥4.22 ʹ��new��delete���洢ͨ������������ַ���(ʹ�ö�̬������ڴ��Ӧ��)
#if 0
#include <cstring>      // or string.h

using namespace std;
char* getname(void);   // function prototype

int main()
{
    char* name;        // create pointer but no storage

    name = getname();   // assign address of string to name

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed

    name = getname();   // reuse freed memory

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed again
    // cin.get();
    // cin.get();
    return 0;
}

//***ע***��̬�����ڴ��Ը�Ч��ʹ���ڴ�
char* getname()        // return pointer to new string
{
    char temp[80];      // temporary storage �������������ӣ��Զ��洢��

    cout << "Enter last name: ";
    cin >> temp;        //temp�����ݴ����������

    char* pn = new char[strlen(temp) + 1];//����������ַ���������̬����һ���ڴ�ռ�

    strcpy(pn, temp); // copy string into smaller space 
                                 //***ע***strcpy()��⵽temp�е�'\0'���'\0'Ҳ������pnָ����ڴ�ռ����Ӧλ�ã�Ȼ��ֹͣ����
    return pn;          // temp lost when function ends
}
#endif


//�����嵥4.23 ʹ�����顢�ṹ��ָ��
#if 0
struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc. */
};

int main()
{
    //------------------------------------------------------------------------------
    antarctica_years_end jiegou_shuzu[3]; //����һ�����飬�ں������ṹ

    jiegou_shuzu[0].year = 2003;

    std::cout << jiegou_shuzu->year << std::endl;
    //------------------------------------------------------------------------------

    antarctica_years_end jiegou01, jiegou02, jiegou03;//���������ṹ

    jiegou01.year = 1998;

    antarctica_years_end* p = &jiegou02;//��������ʼ��һ��ָ��ṹ��ָ��
    p->year = 1999;


    const antarctica_years_end* zhizhen_shuzu[3] = \
    { &jiegou01, & jiegou02, & jiegou03 };//����һ�����飬�ں�����ָ��

    std::cout << zhizhen_shuzu[1]->year << std::endl;
    //------------------------------------------------------------------------------

    const antarctica_years_end** p_zhizhen_shuzu_1 \
        = zhizhen_shuzu;//��������ʼ��һ��ָ��ָ���ָ��

    auto p_zhizhen_shuzu_2 = zhizhen_shuzu; //***ע***C++11��auto����Ϊ����һ�������ṩ����
                                                                           //������֪��zhizhen_shuzu�����ͣ������ܹ��ƶϳ�p_zhizhen_shuzu_2������
    //Ҳ��������Ϊ const antarctica_years_end ** p_zhizhen_shuzu_2 = zhizhen_shuzu; 

    std::cout << (*p_zhizhen_shuzu_1)->year << std::endl;
    std::cout << (*(p_zhizhen_shuzu_2 + 1))->year << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//�����嵥4.25 �Ƚ����顢vector����array����
#if 0
#include <vector>   // STL(Standard Template Library��STL) C++98
#include <array>    // C++0x
int main()
{
    using namespace std;
    //------------------------------------------------------------------------------

    // C, original C++
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    //------------------------------------------------------------------------------

    // C++98 STL
    vector<double> a2(4);   // create vector with 4 elements
    //vector<double> a2(4) = { 1.0 / 3.0 , 1.0 / 5.0 , 1.0 / 7.0 , 1.0 / 9.0 }; 
                                                //���ܽ��б��ʼ������vector����(C++11����������)
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    //vector<double> a5(4);
    //a5 = a2;                              //���Խ�һ��vector���󸳸���һ��vector����
    //------------------------------------------------------------------------------

    // C++11-- create and initialize array object
    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };//�ܽ��б��ʼ������array����
    array<double, 4> a4;
    a4 = a3;                                //���Խ�һ��array���󸳸���һ��array����
    //------------------------------------------------------------------------------

    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    //  cin.get();
    return 0;
}
#endif
#endif


//chapter 4
//code2.cpp
#if 0
#include <iostream>
#include <vector>//STL vector��
#include <array>//STL array��
#include <string>//string��
//
#if 1
#endif


//4.12��ϰ��
//1.
#if 0
int main(void)
{
    char actor[30];
    short betsie[100];
    float chuck[13];
    long double dipsea[64];

    return 0;
}
#endif


//2.
#if 0
int main(void)
{
    using namespace std;

    array<char, 30>actor;
    array<short, 100>betsie;
    array<float, 13>chuck;
    array<long double, 64>dipsea;

    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    int shuju[5] = { 1,3,5,7,9 };

    return 0;
}
#endif


//4.
#if 0
int main(void)
{
    int shuju[5] = { 1,3,5,7,9 };
    int even;
    even = shuju[0] + shuju[4];
    //��even = *(shuju)+ *(shuju+4);

    return 0;
}
#endif


//5.~7.
#if 0
int main(void)
{
    float ideas[10]{ 1,2 };
    std::cout << ideas[1];

    char shuju[20] = "cheeseburger";//��char shuju[]="cheeseburger";
    std::string str = "Waldorf Salad";

    return 0;
}
#endif


//8.~9.
#if 0
struct fish
{
    char pinzhong[20];
    int weight;
    double length;
};

int main(void)
{
    struct fish fish_canshu = { "����",1,2.2 };

    return 0;
}
#endif


//10.
#if 0
enum Response { No, Yes, Maybe };
#endif


//11.
#if 0
int main(void)
{
    double ted = 1.1;
    double* p = &ted;

    std::cout << *p;

    return 0;
}
#endif


//12.
#if 0
int main(void)
{
    float treacle[10] = { 1.0,2.0,3.0 };
    treacle[9] = 10.0;

    float* p = treacle;

    std::cout << *(p) << std::endl;
    std::cout << *(p + 9) << std::endl;

    return 0;
}
#endif


//13.
#if 0
int main(void)
{
    using namespace std;
    cout << "������Ҫд�������������";
    int num;
    cin >> num;

    int* p = new int[num];
    //��
    //vector<int>p(num);

    delete[]p;

    return 0;
}
#endif


//15.
#if 0
struct fish
{
    char pinzhong[20];
    int weight;
    double length;
};

int main(void)
{
    using namespace std;

    //struct fish fish_canshu = { "����",1,2.2 };
    //struct fish* p1 = &fish_canshu;

    struct fish* p = new fish;
    //��fish* p = new fish;
    cin >> p->pinzhong;
    cin >> p->weight;
    cin >> p->length;

    cout << p->pinzhong << endl;
    cout << p->weight << endl;
    cout << p->length << endl;

    return 0;
}
#endif


//17.
#if 0
int main(void)
{
    const int num = 10;//����	#define		num		 (10)
    std::vector<std::string>a_array(num);
    std::array<std::string, num>b_array;

    return 0;
}
#endif
#endif


//chapter 4
//code3.cpp
#if 0
#include <iostream>
#include <vector>//STL vector��
#include <array>//STL array��
#include <string>//string��
#include <cstring>//strcat()
//
#if 1
#endif


//4.13�����ϰ
//1.
#if 0
int main(void)
{
    using namespace std;
    const int SIZE = 20;

    cout << "What is your first name ? ";
    char f_name[SIZE];
    cin.getline(f_name, SIZE);

    cout << "What is your last name ? ";
    char l_name[SIZE];
    cin.getline(l_name, SIZE);

    cout << "What letter grade do you deserve ? ";
    char grade;
    cin >> grade;

    cout << "What is your age ? ";
    int age;
    cin >> age;

    cout << "Name :" << l_name << ", " << f_name << endl;
    cout << "Grade :" << char(grade + 1) << endl;//***ע***grade+1��ʹ������ֵ�����������int��Ҫ��ǿ������ת�������char
    cout << "Age :" << age << endl;						//cout���ܴ�ӡ�ַ�

    return 0;
}
#endif


//2.
#if 0
int main()
{
    using namespace std;

    const int ArSize = 20;
    string name;
    string dessert;

    cout << "Enter your name:\n";
    getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter your first name : ";
    char f_name[20];
    cin.getline(f_name, 20);
    cout << "Enter your last name : ";
    char l_name[60];
    cin.getline(l_name, 20);

    char temp[3] = ", ";
    strcat(l_name, temp);
    strcat(l_name, f_name);

    cout << "Here's the information in a single string : ";
    cout << l_name;

    return 0;
}
#endif


//4.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter your first name : ";
    string f_name;
    getline(cin, f_name);
    cout << "Enter your last name : ";
    string l_name;
    getline(cin, l_name);

    string temp = ", ";
    l_name += temp;
    l_name += f_name;

    cout << "Here's the information in a single string : ";
    cout << l_name;

    return 0;
}
#endif


//5.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;
    CandyBar snack{ "Mocha Munch",2.3,350 };

    cout << snack.brand << endl;
    cout << snack.weight << endl;
    cout << snack.calorie << endl;

    return 0;
}
#endif


//6.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;
    CandyBar snack[3]{
    {"Mocha Munch", 2.3, 350} ,
     {"Aaa Bbb", 2.3, 350} ,
     {"Ccc Ddd", 2.3, 350} };

    for (int i = 0; i < 3; i++)
    {
        cout << snack[i].brand << endl;
        cout << snack[i].weight << endl;
        cout << (snack + i)->calorie << endl;
    }

    return 0;
}
#endif


//7.
#if 0
const int SIZE = 20;

struct pizza
{
    char company[SIZE];
    double diameter;
    double weight;
};

int main(void)
{
    using namespace std;

    struct pizza xinxi;

    cout << "��������������˾�����ƣ�";
    cin.getline(xinxi.company, SIZE);
    cout << "��������������ֱ����";
    cin >> xinxi.diameter;
    cout << "��������������������";
    cin >> xinxi.weight;

    cout << xinxi.company << endl;
    cout << xinxi.diameter << endl;
    cout << xinxi.weight << endl;

    return 0;
}
#endif


//8.
#if 0
const int SIZE = 20;

struct pizza
{
    char company[SIZE];
    double diameter;
    double weight;
};

int main(void)
{
    using namespace std;

    struct pizza* p = new pizza;

    cout << "��������������ֱ����";
    cin >> p->diameter;
    cin.get();

    cout << "��������������˾�����ƣ�";
    cin.getline(p->company, SIZE);

    cout << "��������������������";
    cin >> p->weight;

    cout << p->company << endl;
    cout << p->diameter << endl;
    cout << p->weight << endl;

    delete p;

    return 0;
}
#endif


//9.
#if 0
struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

int main(void)
{
    using namespace std;

    CandyBar* p = new CandyBar[3];
    *p = { "Mocha Munch", 2.3, 350 };
    *(p + 1) = { "Aaa Bbb", 2.3, 350 };
    *(p + 2) = { "Ccc Ddd", 2.3, 350 };

    for (int i = 0; i < 3; i++)
    {
        cout << p[i].brand << endl;
        cout << p[i].weight << endl;
        cout << (p + i)->calorie << endl;
        //��
        //cout << (* (p + i)).calorie << endl;
    }
    delete[]p;

    return 0;
}
#endif


//10.
#if 0
int main(void)
{
    using namespace std;
    const int cishu = 3;

    array<double, cishu>chengji;

    cout << "������3��40���ܵĳɼ���";
    cin >> chengji[0];
    cin >> chengji[1];
    cin >> chengji[2];//ÿ����һ���ɼ��ͻ��У���ÿ����һ���ɼ����ÿո�ֿ���������������

    cout << cishu << "���ܲ���ƽ���ɼ��ǣ�" << (chengji[0] + chengji[1] + chengji[2]) / 3;

    return 0;
}
#endif
#endif


//chapter 5
//code1.cpp
#if 0
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
    for (i = 0, j = word.size() - 1; i < j; ++i, --j)
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

    for (char ch = 'a'; word != "mate"; ch++)
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
    double prices[5] = { 4.99,10.99,6.87,7.99,8.49 };
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

    ch = cin.get();

    while (ch != EOF)
    {
        cout.put(ch);

        if (ch != '\n')
            ++count;

        ch = cin.get();
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
#endif


//chapter 5
//code2.cpp
#if 0
#include <iostream>
//5.8��ϰ��
//6.
#if 1
int main(void)
{
    for (int i = 1; i <= 64; i *= 2)
        std::cout << i << '\t';

    return 0;
}
#endif
#endif


//chapter 5
//code3.cpp
#if 0
#include <iostream>
#include <array>
#include <string>
#include <cstring>//strcmp()
//
#if 1
#endif


//5.9�����ϰ
//1.
#if 0
int main(void)
{
    using namespace std;
    cout << "����������������";

    int start, end;
    cin >> start;
    cin >> end;

    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += i;

    cout << start << "~" << end << "֮�����������ĺ�Ϊ" << sum;

    return 0;
}
#endif


//2.
#if 0
const int ArSize = 100;      // example of external declaration

int main()
{
    std::array<long double, ArSize>factorials;

    factorials[1] = factorials[0] = 1.0L;//0!=1��1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//3.
#if 0
int main(void)
{
    using namespace std;

    cout << "���������֣�";
    int num, sum = 0;

    while (1)
    {
        cin >> num;
        sum += num;

        if (num != 0)
        {
            cout << "����������ۼƺ�Ϊ" << sum << endl;
            cout << "���������֣�";
        }
        else
            break;
    }
    //������
    /*do
    {
        cin >> num;
        sum += sum;
    } while (num!=0);
    cout << "����������ۼƺ�Ϊ" << sum << endl;*/
    return 0;
}
#endif


//4.
#if 0
//#define JUST_CHECKING
int main(void)
{
    using namespace std;

    double benjin_dap = 100.0, benjin_cle = 100.0;
    const double lilv_dap = 0.1;
    const double lilv_cle = 0.05;

    double lixi_dap, lixi_cle;

    double money_dap = benjin_dap;
    double money_cle = benjin_cle;
    int years = 0;

    do
    {
        years++;

        lixi_dap = lilv_dap * benjin_dap;
        money_dap += lixi_dap;

#ifdef JUST_CHECKING//��������
        cout << "��" << years << "�꣺" << "Daphne " << money_dap << "\t";
#endif

        lixi_cle = lilv_cle * money_cle;
        money_cle += lixi_cle;
#ifdef JUST_CHECKING
        cout << "��" << years << "�꣺" << "Cleo " << money_cle << endl;
#endif

    } while (money_cle <= money_dap);

    cout << "��" << years << "�꣺" << "Daphne " << money_dap << "\t";
    cout << "Cleo " << money_cle << endl;

    return 0;
}
#endif


//5.
#if 0
int main(void)
{
    using namespace std;

    int xiaoshouliang[12];
    //���󣺡�const char *�� ���͵�ֵ�������ڳ�ʼ�� ��char *�� ���͵�ʵ��
    //char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
    //***ע***��ȷд����
    const char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
    //д������
    //const string yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };

    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << "������" << yuefen[i] << "����������";
        cin >> xiaoshouliang[i];
        sum += xiaoshouliang[i];
    }

    cout << "��һ��������Ϊ" << sum << "��" << endl;

    return 0;
}
#endif


//6.
#if 0
int main(void)
{
    using namespace std;

    int xiaoshouliang[3][12];
    //���󣺡�const char *�� ���͵�ֵ�������ڳ�ʼ�� ��char *�� ���͵�ʵ��
    //char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
    //***ע***��ȷд����
    const char* nianfen[3] = { "1999��","2000��","2001��" };
    const char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
    //д������
    //const string yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };

    int sum[3 + 1] = {};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        cout << nianfen[i] << "��" << endl;

        for (j = 0; j < 12; j++)
        {
            cout << "������" << yuefen[j] << "����������";
            cin >> xiaoshouliang[i][j];
            sum[i] += xiaoshouliang[i][j];
        }
    }

    cout.put('\n');
    for (int i = 0; i < 3; i++)
    {
        cout << nianfen[i] << "������Ϊ" << sum[i] << "��" << endl;
        sum[3] += sum[i];
    }
    cout << "��������Ϊ" << sum[3] << "��" << endl;

    return 0;
}
#endif


//7.
#if 0
struct car
{
    std::string manufacturer;
    int year;
};

int main(void)
{
    using namespace std;

    cout << "How many cars do you wish to catalog ?";
    int num;
    cin >> num;
    cin.get();//���ĵ����з�

    struct car* p_car = new car[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << "��" << endl;
        cout << "Please enter the make :";
        getline(cin, (p_car + i)->manufacturer);
        cout << "Please enter the year made :";
        cin >> (p_car + i)->year;
        cin.get();
    }

    if (num != 0)
    {
        cout << "Here is your collection :" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << (p_car + i)->year << " ";
            cout << (p_car + i)->manufacturer << endl;
        }
    }
    else
        cout << "No data entered !";

    delete[]p_car;

    return 0;
}
#endif


//8.
#if 0
int main(void)
{
    using namespace std;
    cout << "Enter words (to stop, type the word done) :" << endl;
    char shuju[20];
    int count = 0;

    /*do
    {
        cin >> shuju;
        ++count;
    } while (strcmp(shuju, "done"));
    count -= 1;*/

    /*shuju[0] =0;
    for (; strcmp(shuju, "done"); ++count)
    {
        cin >> shuju;
    }
    count -= 1;*/

    while (1)
    {
        cin >> shuju;
        if (strcmp(shuju, "done"))
            ++count;
        else
            break;
    }

    cout << "You entered a total of " << count << " words";

    return 0;
}
#endif


//9.
#if 0
int main(void)
{
    using namespace std;
    cout << "Enter words (to stop, type the word done) :" << endl;
    string shuju;
    int count = 0;

    while (1)
    {
        cin >> shuju;
        if (shuju != "done")
            ++count;
        else
            break;
    }

    cout << "You entered a total of " << count << " words";

    return 0;
}
#endif


//10.
#if 0
int main(void)
{
    using namespace std;

    cout << "Enter number of rows : ";
    int num;
    cin >> num;//***ע***�����뻺�����л���'\n'

    int i, j, k;
    for (i = 1; i <= num; i++)//�к�
    {
        for (j = 1; j <= num - i; j++)
            cout << ". ";
        for (k = 1; k <= i; k++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}
#endif
#endif


//chapter 6
//code1.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//�����嵥6.1 ѭ�����֧������ʹ��
#if 0
int main()
{
    using std::cin;     // using declarations
    using std::cout;

    char ch;
    int spaces = 0;
    int total = 0;

    cin.get(ch);
    while (ch != '.')   // quit at end of sentence
    {
        if (ch == ' ')  // check if ch is a space
            ++spaces;

        ++total;        // done every time
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.2 ��֧��䣺if...else...���
#if 0
int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";

    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;        // done if newline
        else
            std::cout << ++ch;   // done otherwise

        std::cin.get(ch);
    }
    // try ch + 1 instead of ++ch for interesting effect
    //***ϸ�ڱȽ�***
    //++ch��ch������Ϊchar
    //ch+1��ch��������Ϊint

    std::cout << "\nPlease excuse the slight confusion.\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}
#endif


//�����嵥6.3 if...else...if...else�ṹ
#if 0
const int Fave = 27;

int main()
{
    using namespace std;
    int n;

    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: ";

    do
    {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again: ";
        else if (n > Fave)
            cout << "Too high -- guess again: ";
        else
            cout << Fave << " is right!\n";

    } while (n != Fave);
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.4 cinֻ��ȡһ���ַ������� if...else...if...else�ṹ��||�߼������
#if 0
int main()
{
    using namespace std;
    cout << "This program may reformat your hard disk\n"
        "and destroy all your data.\n"
        "Do you wish to continue? <y/n> ";//�����ַ�����ƴ������

    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')             // y or Y
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')        // n or N
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
        "can't follow\ninstructions, so "
        "I'll trash your disk anyway.\a\a\a\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.5 ѭ����&&�߼����������֧�������Ӧ��
#if 0
const int ArSize = 6;
int main()
{
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients) "
        << "of\nyour neighbors. Program terminates "
        << "when you make\n" << ArSize << " entries "
        << "or enter a negative value.\n";

    int i = 0;
    float temp;

    cout << "First value: ";
    cin >> temp;

    while (i < ArSize && temp >= 0) // 2 quitting criteria
    {
        naaq[i] = temp;
        ++i;// i����ָʾ�����˶��ٸ�ֵ

        if (i < ArSize)             // room left in the array,
        {
            cout << "Next value: ";
            cin >> temp;            // so get next value
        }
    }

    if (i == 0)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";

        float you;
        cin >> you;

        int count = 0;

        for (int j = 0; j < i; j++)
            if (naaq[j] > you)
                ++count;

        cout << count;
        cout << " of your neighbors have greater awareness of\n"
            << "the New Age than you do.\n";
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.6 ʹ��һϵ�� if...else...if...else�ṹ
#if 0
const char* qualify[4] =       // an array of pointers*/
{                               // to strings
    "10,000-meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festival.\n"
};

int main()
{
    using namespace std;

    int age;
    cout << "Enter your age in years: ";
    cin >> age;

    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "You qualify for the " << qualify[index];
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.7 !�߼������
#if 0
#include <climits>

bool is_int(double);

int main()
{
    using namespace std;
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))    // continue while num is not int-able
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }

    int val = int(num);    // type cast
    cout << "You've entered the integer " << val << "\nBye\n";
    // cin.get();
    // cin.get();
    return 0;
}

bool is_int(double x)//double �������Դ洢���͵�intֵ��Ȼ��������ֵ�����߼��ж�
{
    if (x <= INT_MAX && x >= INT_MIN)   // use climits values
        return true;
    else
        return false;
}
#endif


//�����嵥6.8 ʹ��ͷ�ļ�cctype���ṩ�ĺ���
#if 0
#include <cctype>              // prototypes for character functions

int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
        " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);                // get first character
    while (ch != '@')            // test for sentinel
    {
        if (isalpha(ch))         // is it an alphabetic character?
            chars++;
        else if (isspace(ch))    // is it a whitespace character?
            whitespace++;
        else if (isdigit(ch))    // is it a digit?
            digits++;
        else if (ispunct(ch))    // is it punctuation?
            punct++;
        else
            others++;
        cin.get(ch);            // get next character
    }

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.9 ���������:?
#if 0
int main()
{
    using namespace std;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "The larger of " << a << " and " << b;

    int c = a > b ? a : b;   // c = a if a > b, else c = b

    cout << " is " << c << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.10 switch���
#if 0
using namespace std;

void showmenu();   // function prototypes
void report();
void comfort();

int main()
{
    showmenu();

    int choice;
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:   cout << "\a\n";
            break;
        case 2:   report();
            break;
        case 3:   cout << "The boss was in all day.\n";
            break;
        case 4:   comfort();
            break;
        default:   cout << "That's not a choice.\n";
        }

        showmenu();
        cin >> choice;
    }
    //***ע***
    //��������ĸ�����һֱִ��default��ǩ��Ӧ�Ĺ��ܡ�

    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
        "1) alarm           2) report\n"
        "3) alibi           4) comfort\n"
        "5) quit\n";
}
void report()
{
    cout << "It's been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think\n"
        "you are the finest CEO in the industry.\n";
}
#endif


//�����嵥6.11 ��ö����������ǩ
#if 0
// create named constants for 0 - 6
enum { red, orange, yellow, green, blue, violet, indigo };
//ֻʹ�÷��ų�����Ӧ��ö����������ʹ��ö�����͵ı����������ʡ��ö�����͵�����

int main()
{
    using namespace std;

    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;

    while (code >= red && code <= indigo)
    {
        switch (code)
        {
        case red: cout << "Her lips were red.\n"; break;
        case orange: cout << "Her hair was orange.\n"; break;
        case yellow: cout << "Her shoes were yellow.\n"; break;
        case green: cout << "Her nails were green.\n"; break;
        case blue: cout << "Her sweatsuit was blue.\n"; break;
        case violet: cout << "Her eyes were violet.\n"; break;
        case indigo: cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.12 continue��䣬break���
#if 0
const int ArSize = 80;

int main()
{
    using namespace std;

    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);

    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";

    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];    // display character

        if (line[i] == '.') // quit if it's a period
            break;
        if (line[i] != ' ') // skip rest of loop
            continue;

        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.13 ��ȡ���ֵ�ѭ��(�������˷ǹ涨������ʱ����ѭ��)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
        << " fish <q to terminate>.\n";
    cout << "fish #1: ";

    int i = 0;                                                      // i �����������ֵ
    while (i < Max && cin >> fish[i]) {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
    //�˳�ѭ���� i ��ֵ�൱�������Ԫ������
// calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];

    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
        << i << " fish\n";

    cout << "Done.\n";
    // code to keep VC execution window open if q is entered
    //	if (!cin)  // input terminated by non-numeric response
    //	{
    //	    cin.clear();  // reset input
    //	    cin.get();    // read q
    //	}
    //	cin.get();    // read end of line after last input
    //	cin.get();    // wait for user to press <Enter>
    return 0;
}
#endif


//�����嵥6.14 ��ȡ���ֵ�ѭ��(�������˷ǹ涨������ʱ������ȡ����)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";

    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i + 1 << ": ";

        while (!(cin >> golf[i]))//����ǹ涨������ʱcin����false
        {
            cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

            while (cin.get() != '\n')
                continue;    //���ĵ����������

            cout << "Please enter a number: ";//��ʾ�û�������
        }

    }

    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    // report results
    cout << total / Max << " = average score "
        << Max << " rounds\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.15 ���ļ���������
#if 0
#include <fstream>                  // for file I/O        
                                                    //1.����ͷ�ļ�fstream(���ж�����ofstream��)
int main()
{
    using namespace std;

    ofstream outFile;                    // create object for output
                                                     //2.����һ��ofstream����                                                   
    outFile.open("carinfo.txt");    // associate with a file
                                                     //3.���ö�����һ���ļ���������
    cout << "Enter the make and model of automobile: ";
    char automobile[50];
    cin.getline(automobile, 50);

    cout << "Enter the model year: ";
    int year;
    cin >> year;

    cout << "Enter the original asking price: ";
    double a_price;
    cin >> a_price;
    double d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using outFile instead of cout
    //4.��ʹ��cout����ʹ�ø�ofstream����
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    //5.ʹ�����ļ�����close()����ر�
    outFile.close();                // done with file

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥6.16 ��ȡ�ļ�����
#if 0
#include <fstream>                  // file I/O support
                                                    //1.����ͷ�ļ�fstream(���ж�����ifstream��)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main()
{
    using namespace std;

    ifstream inFile;                       // object for handling file input
                                                    //2.����һ��ifstream����                                                   
    cout << "Enter name of data file: ";
    char filename[SIZE];
    cin.getline(filename, SIZE);

    inFile.open(filename);           // associate inFile with a file
                                                    //3.���ö�����һ���ļ���������

    //����ļ��Ƿ񱻳ɹ���
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;                         // number of items read

    inFile >> value;                     // get first value
                                                   //4.��ʹ��cin����ʹ�ø�ifstream����

    while (inFile.good())   // while input good and not at EOF
    {
        ++count;                // one more item read
        sum += value;       // calculate running total
        inFile >> value;     // get next value
    }

    //��дΪ��
    /*while (inFile >> value)   //inFile >> value����inFile��ִ��boolת����Ϊtrue��false
    {
        ++count;
        sum += value;
    }*/

    //ȷ��ѭ����ֹ��ԭ��
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else//inFile.bad()Ϊtrue
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    //5.ʹ�����ļ�����close()����ر�
    inFile.close();         // finished with the file
    // cin.get();
    return 0;
}
//***ע***
//��ʹ�������л���Ҳ��˳����ȡ�ļ�
//scores.txt
#endif
#endif


//chapter 6
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//6.10��ϰ��
//3.
#if 0
using namespace std;
int main()
{
    char ch;
    int ct1, ct2;

    ct1 = ct2 = 0;
    while ((ch = cin.get()) != '$')
    {
        cout << ch;
        ct1++;
        if (ch = '$')
            ct2++;
        cout << ch;
    }
    cout << "ct1= " << ct1 << ", ct2=" << ct2 << endl;

    return 0;
}
/*���룺
Hi!
Send $10 or $20 now!
*/
#endif


//4.
#if 0
weight >= 115 && weight < 125
    ch == 'q' || ch == 'Q'
    x % 2 == 0 && x != 26
    x % 2 == 0 && x % 26 != 0
    (donation >= 1000 && donation <= 2000) || guest == 1
    (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
#endif


    //6.
#if 0
    x>0 ? x : -x
#endif


    //7.
#if 0
    switch (ch)
    {
    case 'A':
        a_grade++;
        break;
    case 'B':
        b_grade++;
        break;
    case 'C':
        c_grade++;
        break;
    case 'D':
        d_grade++;
        break;
    default:
        f_grade++;
    }
#endif


//9.
#if 0
int main(void)
{
    using namespace std;

    int line = 0;
    char ch;
    while (cin.get(ch) && ch != 'Q')
    {
        if (ch == '\n')
            line++;

        //cout << ch;
    }
}
#endif
#endif


//chapter 6
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//6.11�����ϰ
//1.
#if 0
#include <cctype>

int main(void)
{
    using namespace std;

    char ch;
    while (cin.get(ch) && ch != '@')
    {
        if (isdigit(ch))
            continue;

        if (islower(ch))
            cout.put(toupper(ch));//***ע***��дΪcout<<toupper(ch);���ӡ�����ַ���Ӧ��ASCIIֵ
        else if (isupper(ch))
            cout.put(tolower(ch));
        else
            cout << ch;
    }
    cout << "�ټ���";

    return 0;
}
#endif


//2.
#if 0
int main(void)
{
    using namespace std;
    cout << "���������10��ֵ" << endl;

    double donation[10];
    int index = 0;
    double sum = 0.0;

    while (index<10 && cin >> donation[index])//���������ʱcin����false
    {
        ++index;
        sum += donation[index - 1];
    }
    //index�˳�ѭ���󣬴���Ԫ�ظ���

    double average = sum / index;
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        if (donation[i] > average)
            count++;
    }

    cout << "������" << index << "������" << endl;
    cout << "ƽ��ֵ��" << average << endl;
    cout << "��������" << count << "�����ִ���ƽ��ֵ" << endl;

    return 0;
}
#endif


//3.
#if 0
#include <cstring>
void showmenu(void);
char get_choice(void);
using namespace std;

int main(void)
{
    showmenu();
    char choice = get_choice();

    switch (choice)
    {
    case 'c':
        cout << "ccccc\n";
        break;
    case 'p':
        cout << "ppppp\n";
        break;
    case 't':
        cout << "A maple is a tree.\n";
        break;
    case 'g':
        cout << "ggggg\n";
        break;
    defalut:
        cout << "Error !\n";
    }

    return 0;
}
void showmenu(void)
{
    cout << "Please enter one of the following choices :" << endl;
    cout << "c) carnivore p) pianist" << endl;
    cout << "t) tree g)game" << endl;
}
char get_choice(void)
{
    char ch;

    /*�Ϸ�����
    while(ch!='c'&&ch!='p'&&ch!='t'&&ch!='g')
    {
            cin.get();
            cout << "������c��p��t��g : " ;
            cin.get(ch);
    }
    */

    while (cin.get(ch))
    {
        while (cin.get() != '\n')
            continue;
        ch = tolower(ch);

        if (strchr("cptg", ch) == NULL)
            cout << "������c��p��t��g : ";
        else
            break;
    }

    return ch;
}
#endif


//4.
#if 0
#include <cstring>
#include <cctype>

const int strsize = 30;
void showmenu(void);
char get_choice(void);
void display_by_name(struct bop* p_BopStructure);
void display_by_title(struct bop* p_BopStructure);
void display_by_bopname(struct bop* p_BopStructure);
void display_by_preference(struct bop* p_BopStructure);

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

using namespace std;
int main(void)
{
    //***ע***C99��C11Ϊ�ṹ�ṩ��ָ����ʼ������designated initializer��1�����﷨�������ָ����ʼ�������ơ�
    //���ǣ��ṹ��ָ����ʼ����ʹ�õ�������ͳ�Ա���������Ƿ����ź��±꣩��ʶ�ض���Ԫ�ء�
    //���ǣ�C++��֧�֡�
    struct bop BopStructure[5] = {
        {"Wimp Macho","Programmer","MIPS",0},
        {"Raki Rhodes", "Junior Programmer","\0",1},
        {"Celia Laiter","\0","MIPS",2},
        {"Hoppy Hipman","Analyst Trainee","\0",1 },
        {"Pat Hand","\0","LOOPY",2}

    };

    showmenu();
    char choice;

    while ((choice = get_choice()) && choice != 'q')
    {
        switch (choice)
        {
        case 'a':
            display_by_name(BopStructure);
            break;
        case 'b':
            display_by_title(BopStructure);
            break;
        case 'c':
            display_by_bopname(BopStructure);
            break;
        case 'd':
            display_by_preference(BopStructure);
            break;
        default:
            cout << "Error !";
            return 1;
        }
        cout << "Next choice : ";
    }

    cout << "Bye !";
    return 0;
}
void showmenu(void)
{
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name         b. display by title" << endl;
    cout << "c. display by bopname  d. display by preference" << endl;
    cout << "q. quit" << endl;
    cout << "Enter your choice : ";
}
char get_choice(void)
{
    char ch;

    while (cin.get(ch))
    {
        while (cin.get() != '\n')
            continue;
        ch = tolower(ch);

        if (strchr("abcdq", ch) == NULL)
            cout << "������a��b��c��d��q : ";
        else
            break;
    }

    return ch;
}
void display_by_name(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
    {
        //�����Ƶ�д����
        /*if (strlen((p_BopStructure + i)->fullname) == 0)
            continue;
        else*/
        cout << (p_BopStructure + i)->fullname << endl;
    }
}
void display_by_title(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
        cout << (p_BopStructure + i)->title << endl;
}
void display_by_bopname(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
        cout << (p_BopStructure + i)->bopname << endl;
}
void display_by_preference(struct bop* p_BopStructure)
{
    for (int i = 0; i < 5; i++)
        switch ((p_BopStructure + i)->preference)
        {
        case 0:
            cout << (p_BopStructure + i)->fullname << endl;
            break;
        case 1:
            cout << (p_BopStructure + i)->title << endl;
            break;
        case 2:
            cout << (p_BopStructure + i)->bopname << endl;
            break;
        }
}
//������
//��main�����������ṹ���飬�������ʼ��
//�����Ļ����������������βζ�������void
#endif


//5.
#if 0
int main(void)
{
    using namespace std;

    cout << "�������������룺";
    long income;
    double tax = 0;

    while (cin >> income && income >= 0)
    {
        if (income <= 5000)
            tax = 0;
        else if (income > 5000 && income <= 15000)
            tax = 0 + (income - 5000) * 0.1;
        else if (income > 15000 && income <= 35000)
            tax = (15000 - 5000) * 0.1 + (income - 15000) * 0.15;
        else
            tax = (15000 - 5000) * 0.1 + (35000 - 15000) * 0.15 + (income - 35000) * 0.2;

        cout << "��Ӧ����˰�" << tax << endl;
    }

    return 0;
}
#endif


//6.
#if 0
#include <string>//getline()

typedef struct
{
    std::string name;
    double donation;
}PeopleTypedef;

int main(void)
{
    using namespace std;
    cout << "�����������������";
    long num = 0;
    while (!(cin >> num))//����ǹ涨������ʱcin����false
    {
        cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

        while (cin.get() != '\n')
            continue;    //���ĵ����������

        cout << "Please enter a number: ";//��ʾ�û�������
    }
    cin.get();

    PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

    for (int i = 0; i < num; i++)
    {
        cout << "������������";
        getline(cin, (p_PeopleTypedef + i)->name);

        cout << "��������";
        while (!(cin >> (p_PeopleTypedef + i)->donation))//����ǹ涨������ʱcin����false
        {
            cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

            while (cin.get() != '\n')
                continue;    //���ĵ����������

            cout << "Please enter a number: ";//��ʾ�û�������
        }

        cin.get();
    }

    int biaoji1, biaoji2;
    biaoji1 = biaoji2 = 0;

    cout << "\nGrand Patrons : \n";
    for (int i = 0; i < num; i++)
    {
        if ((p_PeopleTypedef + i)->donation > 10000)
        {
            cout << (p_PeopleTypedef + i)->name << "\t";
            cout << (p_PeopleTypedef + i)->donation << endl;
            biaoji1 = 1;
        }
    }
    if (!biaoji1)
        cout << "none\n";

    cout << "\nPatrons : \n";
    for (int i = 0; i < num; i++)
    {
        if ((p_PeopleTypedef + i)->donation <= 10000)
        {
            cout << (p_PeopleTypedef + i)->name << "\t";
            cout << (p_PeopleTypedef + i)->donation << endl;
            biaoji2 = 1;
        }
    }
    if (!biaoji2)
        cout << "none\n";

    return 0;
}
#endif


//7.
#if 0
#include <cstring>//strcmp()
#include<cctype>//isupper()

void string_tolower(char* p);
void delete_punctuation(char* p);

int main(void)
{
    using namespace std;
    cout << "Enter words (q to quit) : " << endl;
    char words[30];
    int length = 0;
    int index, jishu = 0;
    int vowels = 0, consonants = 0, others = 0;

    while (cin >> words && strcmp(words, "q"))//ÿ�ζ������˻�һ��Ϊ�հ׵��ַ�
    {
        //�����˻�һ��Ϊ�հ׵��ַ������Ǵ�д��ĸ����ת��ΪСд
        string_tolower(words);
        //�����˻�һ��Ϊ�հ׵��ַ�,���еı�������'\0'�滻
        delete_punctuation(words);

        //�ж����˻�һ��Ϊ�հ׵��ַ��Ƿ��ǵ���
        length = strlen(words);
        for (index = 0; index < length; index++)
        {
            if (isalpha(words[index]))
                ++jishu;
        }

        //���ǵ���
        if (jishu == length)
        {
            switch (words[0])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
                /*default:
                    consonants++;*/			//����if�������д��
            }

            if (strchr("bcdfghjklmnpqrstvwxyz", words[0]))
                consonants++;
        }
        else//�����ǵ���
            others++;

        jishu = 0;
    }

    cout << "\n" << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;

    return 0;
}
void string_tolower(char* p)
{
    int length = strlen(p);
    for (int index = 0; index < length; index++)
    {
        if (isupper(*(p + index)))
            *(p + index) = tolower(*(p + index));
    }

    return;
}
void delete_punctuation(char* p)
{
    int length = strlen(p);
    for (int index = 0; index < length; index++)
    {
        if (ispunct(*(p + index)))
            *(p + index) = '\0';
    }

    return;
}
/*�������ݣ�
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
*/
#endif


//8.
#if 0
#include <fstream>                  // file I/O support
                                                    //1.����ͷ�ļ�fstream(���ж�����ifstream��)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main(void)
{
    using namespace std;

    ifstream inFile;                       // object for handling file input
                                                    //2.����һ��ifstream����                                                   

// ifstreamĬ�������뷽ʽ���ļ������ڶ��ļ�
//	ofstreamĬ���������ʽ���ļ�������д�ļ�

    cout << "Enter name of data file: ";
    char filename[SIZE];
    cin.getline(filename, SIZE);

    inFile.open(filename);           // associate inFile with a file
                                                    //3.���ö�����һ���ļ���������

    //����ļ��Ƿ񱻳ɹ���
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    char ch;
    int count = 0;

    inFile >> ch;                     // get first value
                                                   //4.��ʹ��cin����ʹ�ø�ifstream����

    while (inFile.good())   // while input good and not at EOF
    {
        ++count;
        inFile >> ch;
    }

    //ȷ��ѭ����ֹ��ԭ��
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else//inFile.bad()Ϊtrue
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "���ļ����� " << count << "���ַ�" << endl;
    }

    //5.ʹ�����ļ�����close()����ر�
    inFile.close();         // finished with the file

    return 0;
}
//6.11.8.txt
#endif


//9.
#if 0
#include <string>//getline()
#include <fstream>
#include <cstdlib> 

typedef struct
{
    std::string name;
    double donation;
}PeopleTypedef;

int main(void)
{
    using namespace std;

    ifstream inFile;

    inFile.open("6.11.9.txt");

    //cout << "�����������������";

    //����ļ��Ƿ񱻳ɹ���
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << "6.11.9.txt" << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    long num = 0;
    while (!(inFile >> num))//����ǹ涨������ʱcin����false
    {
        cin.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

        while (cin.get() != '\n')
            continue;    //���ĵ����������

        cout << "Please enter a number: ";//��ʾ�û�������
    }
    inFile.get();

    PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

    for (int i = 0; i < num; i++)
    {
        //cout << "������������";
        getline(inFile, (p_PeopleTypedef + i)->name);

        //cout << "��������";
        while (!(inFile >> (p_PeopleTypedef + i)->donation))//����ǹ涨������ʱinFile����false
        {
            inFile.clear();     //��clear()�������ô��������ǣ�������ܼ�����ȡ����

            while (inFile.get() != '\n')
                continue;    //���ĵ����������

            cout << "Please enter a number: ";//��ʾ�û�������
        }

        inFile.get();
    }

    int biaoji1, biaoji2;
    biaoji1 = biaoji2 = 0;

    cout << "\nGrand Patrons : \n";
    for (int i = 0; i < num; i++)
    {
        if ((p_PeopleTypedef + i)->donation > 10000)
        {
            cout << (p_PeopleTypedef + i)->name << "\t";
            cout << (p_PeopleTypedef + i)->donation << endl;
            biaoji1 = 1;
        }
    }
    if (!biaoji1)
        cout << "none\n";

    cout << "\nPatrons : \n";
    for (int i = 0; i < num; i++)
    {
        if ((p_PeopleTypedef + i)->donation <= 10000)
        {
            cout << (p_PeopleTypedef + i)->name << "\t";
            cout << (p_PeopleTypedef + i)->donation << endl;
            biaoji2 = 1;
        }
    }
    if (!biaoji2)
        cout << "none\n";

    inFile.close();

    return 0;
}
#endif
#endif


//chapter 7
//code1.cpp
#if 0
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

    for (n = numbers, p = picks; p > 0; n--, p--)
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

    std::cout << "array address = " << cookies;
    //  some systems require a type cast: unsigned (cookies)

    std::cout << ", sizeof cookies = " << sizeof cookies << std::endl;
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

    std::cout << ", sizeof arr = " << sizeof arr << std::endl;
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
    show(expenses);//ʵ�Σ�����array����
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

    cout << "Counting down ... " << n << " (n at " << &n << ")" << endl;
    if (n > 0)
        countdown(n - 1);     // function calls itself
    cout << n << ": Kaboom!" << " (n at " << &n << ")" << endl;
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
    // const double *   (**pb)    (const double *, int) = pa;

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

    p_fun p1 = f1;//������һ������ָ��p1

    auto p2 = f2;  //����һ������ָ��p2���������ʼ�����Ե�ֵ��ʼ������auto�Զ������ƶ������г�ʼ��
    //д������
    //p_fun p2= f2;

    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    //��ʾconst double ֵ�ĵ�ַ����ʾconst double ֵ
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    //************************************************************************************************************************************************************************

    p_fun pa[3] = { f1,f2,f3 };//������һ������pa������3��Ԫ�أ�ÿ��Ԫ�ض��Ǻ���ָ�룬paָ����ָ���������Ԫ�أ�pa�溯��ָ���������Ԫ�صĵ�ַ

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
#endif


//chapter 7
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//7.12��ϰ��
//2.
#if 0
void igor(void);
float tofu(int);
double mpg(double, double);
long summation(long* p, int num);
double doctor(const char* string);
void ofcourse(struct boss bos);
char* plot(struct map* p_structure);
#endif


//3.
#if 0
void Array_Init(int* p_data, int num, int data);

void Array_Init(int* p_data, int num, int data)
{
    for (int i = 0; i < num; i++)
        *(p_data + i) = data;

    return;
}
#endif


//4.
#if 0
void fill_array(int* begin, int* end, int num)
{
    int* temp;
    for (temp = begin; temp != end; temp++)
        *temp = num;

    //������
    /*while (begin!=end)
    {
        *begin = num;
        begin++;
    }*/
}
#endif


//5.
#if 0
double FindMax(const double* p, int num)
{
    double max = *p;
    for (int i = 0; i < num - 1; i++)
        (*(p + i) >= *(p + i + 1)) ? (max = *(p + i)) : (max = *(p + i + 1));

    //������
    /*for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = *(p+i);*/

    return max;
}
#endif


//8.
#if 0
int replace(char* str, char c1, char c2)
{
    int count = 0;

    while (str)
    {
        if (*str == c1)
        {
            *str = c2;
            count++;
        }
        str++;
    }

    return count;
}
#endif


//11.
#if 0
int judge(int (*p_fun) (const char* string));
#endif


//12.
#if 0
struct applicant
{
    char name[30];
    int credit_ratings[3];
};

struct applicant applicant_structure;

void show(struct applicant applicant_structure)
{
    std::cout << applicant_structure.name << "\n";
    for (int i = 0; i < 3; i++)
        std::cout << applicant_structure.credit_ratings[i] << std::endl;
}

void show(const struct applicant* p_applicant_structure)
{
    std::cout << p_applicant_structure->name << "\n";
    for (int i = 0; i < 3; i++)
        std::cout << p_applicant_structure->credit_ratings[i] << std::endl;
}
#endif


//13.
#if 0
struct applicant
{
    char name[30];
    int credit_ratings[3];
};

void f1(applicant* a);
const char* f2(const applicant* a1, const applicant* a2);

typedef void (*p_fun1)(applicant*);
typedef const char* (*p_fun2)(const applicant*, const applicant*);

int main(void)
{
    p_fun1 p1 = f1;
    p_fun2 p2 = f2;

    p_fun1 ap[5] = { f1,f1,f1,f1,f1 };

    p_fun2 f2_array[10] = { f2,f2 ,f2 ,f2 ,f2  ,f2  ,f2  ,f2  ,f2  ,f2 };
    p_fun2(*pa)[10] = &f2_array;

    std::cout << "Done !";
    return 0;
}
void f1(applicant* a)
{}
const char* f2(const applicant* a1, const applicant* a2)
{
    return 0x00;
}
#endif
#endif


//chapter 7
//code3.cpp
#if 0
#include <iostream>
//
#if 0
int main(void)
{
    using namespace std;

    return 0;
}
#endif


//7.13 �����ϰ
//1.
#if 0
double harmonic_average_fun(double a, double b);

int main(void)
{
    using namespace std;

    cout << "�������������֣�";

    double a, b;
    double harmonic_average;
    while (cin >> a >> b && a != 0 && b != 0)
    {
        harmonic_average = harmonic_average_fun(a, b);
        cout << "����" << a << "��" << b << "�ĵ���ƽ�����ǣ�" << harmonic_average << endl;
        cout << "�������������֣�";
    }

    return 0;
}
double harmonic_average_fun(double a, double b)
{
    double result = 2.0 * a * b / (a + b);

    return result;
}
#endif


//2.
#if 0
int fill_array(double* p_num);
void show(const double* p_num, int);
double average(const double* p_num, int);

using namespace std;


int main(void)
{
    cout << "���������10���߶���ɼ�(����0�Խ�������)��";
    double scores[10];
    int count = fill_array(scores);

    show(scores, count);

    double averagenum = average(scores, count);
    cout << "ƽ���ɼ���" << averagenum << endl;

    return 0;
}
int fill_array(double* p_num)
{
    int count = 0;
    double temp;

    for (int i = 0; i < 10; i++)
    {
        while (!(cin >> temp))
        {
            cin.clear();

            while (cin.get() != '\n')
                continue;    //���ĵ����������

            cout << "���������֣�" << endl;
        }

        if (temp != 0)
        {
            p_num[i] = temp;
            count++;
        }
        else
            break;
    }

    return count;
}
void show(const double* p_num, int num)
{
    cout.put('\n') << "����ĳɼ�Ϊ��";
    for (int i = 0; i < num; i++)
        cout << *(p_num + i) << "  ";
    cout << endl;
}
double average(const double* p_num, int num)
{
    double sum = 0.0;
    for (int i = 0; i < num; i++)
        sum += *(p_num + i);

    return (double)(sum / num);
}
#endif


//4.
#if 0
long double probability(unsigned numbers, unsigned picks,
    unsigned numbers1, unsigned picks1);

int main()
{
    using namespace std;
    double total, choices;
    double total1, choices1;
    cout << "��������ͨ���ֵ�����(1~X)������ѡ��ĺ������\n";

    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "��������ѡ���ֵ�����(1~X)������ѡ��ĺ������\n";
        cin >> total1 >> choices1;

        cout << "You have one chance in ";
        cout << probability(total, choices, total1, choices1);      // compute the odds
        cout << " of winning.\n";
        cout << "��������ͨ���ֵ�����(1~X)������ѡ��ĺ������\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks,
    unsigned numbers1, unsigned picks1)
{
    long double result = 1.0, result1 = 1.0; // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    for (n = numbers1, p = picks1; p > 0; n--, p--)
        result1 = result1 * n / p;

    return result * result1;
}
#endif


//5.
#if 0
long long temp = 1;
long long jiecheng(long long num);

int main(void)
{
    using namespace std;

    cout << "������Ҫ�׳˵�������";
    long long num, result;
    while (cin >> num)
    {
        result = jiecheng(num);
        cout << num << "! = " << result << endl;
        temp = 1;
        cout << "������Ҫ�׳˵�������";
    }

    return 0;
}

//��һ���ݹ�ķ���ֵ��ʹ��
#if 0
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        temp *= num;
        jiecheng(--num);
    }

    return temp;
}
#endif

/*
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        temp = num * jiecheng(num--);//�������������޵��ú���jiecheng()
        return temp;
    }
}
*/

//������
long long jiecheng(long long num)
{
    if (num == 0 || num == 1)
        return 1;
    if (num > 1)
    {
        temp = num * jiecheng(num - 1);
        //***ע***
        //��д��--num�����������ǰ�num�ݼ���Ȼ���*�������num�ݼ����ֵ���棬�ٽ�����õĺ��������Ե�2!=1
        //��д��num--�����������ǰ�*�������num��ֵ���棬Ȼ���num�ݼ����ٽ�����õĺ����������ڵڶ��ν��뺯��ʱ(�ü������鿴numֵ��֪)num�ֱ����ԭֵ�����³�������ѭ��
        // ��⣺��P112��
        //�����ĩβ�Ǹ�˳��㣬C++ֻ�ܱ�֤�������棬num��ֵ�����1��������֤�ڴ������е�ĳ��ʱ�̣�ʹnumֵ��1
        return temp;
    }
}
#endif


//6.�Աȳ����嵥5.9 ��ת�������һ�ַ���
#if 0
void reverse_array(double* ar, int size)
{
    double temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = ar[i];
        arr[i] = ar[size - i - i];
        arr[size - i - 1] = temp;
    }
}
#endif


//7.
#if 0
const int Max = 5;

// function prototypes
double* fill_array(double ar[], double*);
void show_array(const double ar[], double*);  // don't change data
void revalue(double r, double ar[], double*);

int main()
{
    using namespace std;
    double properties[Max];

    double* end = fill_array(properties, properties + Max);

    show_array(properties, end);

    if (end - properties > 0)
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

        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

double* fill_array(double ar[], double* end)
{
    using namespace std;
    double temp;
    int i = 0;
    double* the_end;

    for (; ar != end; ar++)
    {
        cout << "Enter value #" << (++i) << ": ";
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

        *ar = temp;
    }
    the_end = ar;

    return the_end;
}

//the following function can use, but not alter,
//the array whose address is ar
void show_array(const double ar[], double* end)
{
    using namespace std;
    for (int i = 0; i < end - ar; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

//������
#if 0
void show_array(const double ar[], double* end)
{
    using namespace std;

    int* p_num = new int[end - ar];
    int index;
    for (index = end - ar - 1; index >= 0; index--)
        *(p_num + index) = index;

    index = 0;
    for (; ar != end; ar++, index++)
    {
        cout << "Property #" << *(p_num + index) + 1 << ": $";
        cout << *ar << endl;
    }

    delete[]p_num;
}
#endif

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double* end)
{
    for (; ar < end; ar++)
        *ar *= r;
}
#endif


//8.a.
#if 0
const int Seasons = 4;

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double* p_num, int NumToFill);
void show(const double* p_num, int NumToShow);

int main()
{
    double expenses[Seasons];

    fill(expenses, Seasons);
    show(expenses, Seasons);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(double* p_num, int NumToFill)
{
    for (int i = 0; i < NumToFill; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> *(p_num + i);
    }
}

void show(const double* p_num, int NumToShow)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < NumToShow; i++)
    {
        std::cout << Snames[i] << ": $" << *(p_num + i) << '\n';
        total += *(p_num + i);
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//8.b.
#if 0
const int Seasons = 4;

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

typedef struct
{
    double expenses[Seasons];
}Expenses_Typedef;

void fill(Expenses_Typedef* p_structure, int NumToFill);
void show(const Expenses_Typedef* p_structure, int NumToShow);

int main()
{
    Expenses_Typedef Expenses_structure;

    fill(&Expenses_structure, Seasons);
    show(&Expenses_structure, Seasons);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(Expenses_Typedef* p_structure, int NumToFill)
{
    for (int i = 0; i < NumToFill; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> p_structure->expenses[i];
    }
}

void show(const Expenses_Typedef* p_structure, int NumToShow)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < NumToShow; i++)
    {
        std::cout << Snames[i] << ": $" << *(p_structure->expenses + i) << '\n';
        total += *(p_structure->expenses + i);
    }
    //***ע***
    /*
    p_structure->expenses[0] = 0;
    */
    //����䲻��������Ϊ��Expenses_Typedef���ֵĽṹ��������Ϊ��const
    //���ṹ�����е�ֵ�������Ըı�
    std::cout << "Total: $" << total << '\n';
}
#endif


//9.
#if 0
#include <cstring>//strlen()��memcpy()
using namespace std;

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(struct student* p_structure, int num);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main(void)
{
    cout << "Enter class size : ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student* ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);
    cout << "\nѧ����Ϣ����\n";
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete[]ptr_stu;
    cout << "Done !\n";

    return 0;
}
int getinfo(struct student* p_structure, int num)
{
    int count = 0;
    char temp[SLEN];

    for (int i = 0; i < num; i++)
    {
        cout << "������" << i + 1 << "���ṹ����" << endl;
        cout << "������ѧ��ȫ��(��Enter�Խ�������)��";
        cin.getline(temp, SLEN);
        if (temp[0] == '\0')
            break;
        else
            memcpy((p_structure + i)->fullname, temp, strlen(temp) * sizeof(char) + 1);
        //***ע***
        //���������дΪstrlen(temp)*sizeof(char) ���޷��������ַ�����ɺ�����ӡ������������ݵĺ���������
        cout << "�������ѧ������Ȥ���ã�";
        cin.getline((p_structure + i)->hobby, SLEN);
        cout << "�������ѧ������������̵������ȼ���";
        while (!(cin >> (p_structure + i)->ooplevel))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "�������������֣�" << endl;
        }
        cin.get();

        count++;
    }

    return count;
}
void display1(student st)
{
    cout << "ѧ��������" << st.fullname << endl;
    cout << "ѧ���İ��ã�" << st.hobby << endl;
    cout << "ѧ������������̵������ȼ���" << st.ooplevel << endl << endl;
}
void display2(const student* ps)
{
    cout << "ѧ��������" << ps->fullname << endl;
    cout << "ѧ���İ��ã�" << ps->hobby << endl;
    cout << "ѧ������������̵������ȼ���" << ps->ooplevel << endl << endl;
}
void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ѧ��������" << (pa + i)->fullname << endl;
        cout << "ѧ���İ��ã�" << (pa + i)->hobby << endl;
        cout << "ѧ������������̵������ȼ���" << (pa + i)->ooplevel << endl << endl;
    }
}
#endif


//10.
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x, double y);
int main(void)
{
    using namespace std;

    double result;

    cout << "�������������֣�";
    double a, b;
    while (cin >> a >> b)
    {
        result = calculate(a, b, add);
        cout << a << "+" << b << "���Ϊ" << result << endl;

        result = calculate(a, b, sub);
        cout << a << "-" << b << "���Ϊ" << result << endl;

        cout << "��������������(������������˳�����)��";
    }

    return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
    double result;

    result = p_fun(x, y);

    return result;
}

double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
#endif


//10.ʹ�ú���ָ������
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x, double y);
double mul(double, double);

int main(void)
{
    using namespace std;

    double (*pf[3])(double, double) = { add,sub,mul };//��������ʼ��һ������ָ������
    const char* p_string[3] = { "+","-","*" };

    double result;

    cout << "�������������֣�";
    double a, b;
    while (cin >> a >> b)
    {
        for (int i = 0; i < 3; i++)
        {
            result = calculate(a, b, pf[i]);
            cout << a << p_string[i] << b << "���Ϊ" << result << endl;
        }
        cout << "��������������(������������˳�����)��";
    }

    return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
    double result;

    result = p_fun(x, y);

    return result;
}

double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
double mul(double x, double y)
{
    return x * y;
}
#endif
#endif


//chapter 8
//code1.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//�����嵥8.1 C++ͨ����������������C���Ե��ຯ����
#if 0
// an inline function definition
inline double square(double x) { return x * x; }//��������һ��Ѻ���ԭ��ʡ�ԣ��������������ͷ�ļ���

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);   // can pass expressions

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    //***ע***
    //�����ĩβ�Ǹ�˳��㣬C++ֻ�ܱ�֤�������棬c��ֵ������1
   //����square()���ǵ���ǰ��c��ֵ
    //�겻�ܰ�ֵ���ݣ�����ͨ���ı��滻ʵ�ֹ���
    //���������ܰ�ֵ����
    cout << "Now c = " << c << "\n";

    // cin.get();
    return 0;
}
#endif


//�����嵥8.2 �������ñ���
#if 0
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   // rodents is a reference
                                        //����ָ��rats�����ñ���rodents
                                        //rodents��Ϊrats�����ı��������߶�ָ��ͬһ��ֵ���ڴ浥Ԫ
                                        //int &   :ָ��int���ͱ���������
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;//�����Ĳ��ǵ�ֵַ������rats��ֵ
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    // some implementations require type casting the following
    // addresses to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥8.3 ����һ��������ʱ����ʼ���󣬾�һֱ���˸ñ���
#if 0
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   //��������ʼ�����ã�rodents����rats

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;       // can we change the reference?
                                           //���Ըı�rodents���õı�����
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;//rodents�ĵ�ַ����rats�ĵ�ַ��ͬ
    // cin.get();
    return 0;
}
#endif


//�����嵥8.4 �Ƚϴ��ݺ������������ַ���
//1.��ֵ���ݣ�2.��ָ�봫�ݣ�3.�����ô���
#if 0
void swapv(int a, int b);       // a, b are new variables
void swapp(int* p, int* q);   // p, q are addresses of ints
void swapr(int& a, int& b);   // a, b are aliases for ints

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);   // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);   // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    // cin.get();
    return 0;
}

void swapv(int a, int b)        // try using values
{
    int temp;

    temp = a;      // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int* p, int* q)    // use pointers
{
    int temp;

    temp = *p;      // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

void swapr(int& a, int& b)    // use references
{
    int temp;

    temp = a;       // use a, b for values of variables
    a = b;
    b = temp;
}
#endif


//�����嵥8.5 ����ʱ���ò���const�ʹ�const������ʵ��������ʱ�Ĳ�ͬ��Ӧ
#if 0
double cube(double a);
double refcube(double& ra);
double refcude_1(const double& ra);

int main()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;

    cout << refcube(x);
    //***ע***��д��refcude(3)����ᱨ���ǳ������õĳ�ʼֵ��������ֵ
    //��Ϊ������3�����ڷ���ֵ���������ñ���û����Ϊconst������C++���ᴴ����ʱ����������ֱ�ӱ���
    cout << " = cube of " << x << endl;

    int a = 3;
    cout << refcude_1(a);
    cout << " = cube of " << a << endl;
    //***ע***����������ʱ�����ò���const����ᱨ���޷���int���͵�ֵ��ʼ��double&���͵�����(�ǳ����޶�)

    // cin.get();
    return 0;
}

double cube(double a)           // x=3.0���룬����ֵ27.0����
{
    a *= a * a;
    return a;
}

double refcube(double& ra)  // ra��x�ı����������޸���x��x��ֵ��Ϊ27.0
{
    ra *= ra * ra;
    return ra;
}                                               //***ע***����ʹ�����ã���������Щ��Ϣ�޸ģ���Ӧ��ʹ�ó�������
                                                //double refcube(const double& ra)

double refcude_1(const double& ra)
{
    return ra * ra * ra;
}                                               //***ע***����ʵ�δ�����3������C++�ᴴ��һ��������ʱ����
#endif                        


//�����嵥8.6 ���������ڽṹ
//�������úͰ�ֵ���صĲ�֮ͬ��
#if 0
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
//����ֵ��ָ��ṹ������
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
    free_throws one = { "Ifelsa Branch", 13, 14 };
    free_throws two = { "Andor Knott", 10, 16 };
    free_throws three = { "Minnie Max", 7, 9 };
    free_throws four = { "Whily Looper", 5, 9 };
    free_throws five = { "Long Long", 6, 14 };
    free_throws team = { "Throwgoods", 0, 0 };
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // use return value as argument ʹ�÷���ֵ��Ϊ����
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    //***ע***
    //�����ķ���ֵ���������ã��������ǰ�ֵ���أ�������ĳ����޷����ʷ��ص�ֵ������䲻��ͨ������
    //���Ұ�ֵ���ص�ֵ(����ʱֵ)������Ϊ��ֵ���ʽ������ֵ��ֻ����Ϊ��ֵ
    display(team);

    // use return value in assignment ʹ�÷���ֵ��Ϊ��ֵ���ʽ����ֵ
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);

    set_pc(four);
    // ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
    // std::cin.get();
    return 0;
}

void set_pc(free_throws& ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

void display(const free_throws& ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}
#endif


//�����嵥8.7���������������
#if 0
#include <string>
using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);  // has side effect
const string& version3(string& s1, const string& s2);  // bad design

int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);

    copy = input;

    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    // cin.get();
    // cin.get();
    return 0;
}

string version1(const string& s1, const string& s2)//***ע***��Ȼʵ����string��const *char��������const���õ����ԣ����򽫴���һ����ȷ���͵���ʱ������s2��ָ�����ʱ����������
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
    //***ע***
    //���ܷ���ָ��temp�����ã���Ϊtemp�Ǹ��Զ��������ú���ִ����Ϻ��������ٴ���
}   //�˴�temp�����Ƶ�һ����ʱλ�ã�����������result���Է��������ʱλ��

const string& version2(string& s1, const string& s2)   // has side effect
{
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}

const string& version3(string& s1, const string& s2)   // bad design
{
    string temp;

    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
    //***ע***
    //���ܷ���ָ��temp�����ã���Ϊtemp�Ǹ��Զ��������ú���ִ����Ϻ��������ٴ���
}   //�Ա�version1()����
#endif


//�����嵥8.8 �������ÿ���ָ��������������󣬶��������ǿ������ת��
#if 0
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);//�βΣ�ָ��ostream���������
const int LIMIT = 5;

int main()
{
    ofstream fout;//�������ʽ���ļ�������д�ļ�
    const char* filename = "ep-data.txt";

    fout.open(filename);

    if (!fout.is_open())
    {
        cout << "Can't open " << filename << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
        "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
        << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);//���ļ�д������
    file_it(cout, objective, eps, LIMIT);//����ʾ������ʾ����
    cout << "Done\n";
    // cin.get();
    // cin.get();
    return 0;
}

//�βΣ�ָ��ostream��������ã��ﾵ����fo��ָ��Ŀ������������Ԫ�ص�ָ�룬���鳤��
//***ע***
//os����ָ��ostream����Ҳ����ָ��ofstream����
void file_it(ostream& os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    //fmtflags����ʽ״̬��־λ���Ǵ洢��ʽ����Ϣ����������
    //����һ��fmtflags���͵ı���initial
    initial = os.setf(ios_base::fixed, ios_base::floatfield);
    //initial������������ĸ�ʽ��״̬

    std::streamsize sz = os.precision(0);

    os << "Focal length of objective: " << fo << " mm\n";
    os.precision(1);
    os.width(12);//�����ý�����ʾ��һ��ֵʱ��Ч
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }

    os.setf(initial);
    // restore initial formatting state �����еĸ�ʽ�����ûָ���ԭ����ֵ
    //����setf()���ص�����֮ǰ��Ч�����и�ʽ������(���洢��initial��)
    os.precision(sz);
}
#endif


//�����嵥8.9 ʹ��Ĭ�ϲ���
#if 0
const int ArSize = 80;

char* left(const char* str, int n = 1);//n��Ĭ��ֵ��1

int main()
{
    using namespace std;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char* ps = left(sample, 4);
    cout << ps << endl;
    delete[] ps;       // free old string

    ps = left(sample);
    cout << ps << endl;
    delete[] ps;       // free new string
    // cin.get();
    // cin.get();
    return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;
    char* p = new char[n + 1];//���ö�̬�ڴ���䣬ʹ�����������ڱ�����������ʱ�Դ���

    //������
    /*
    int len = strlen(str);
    n = (n < len) ? n:len;

    char* p = new char[n + 1];
    */
    //������
    /*
    int m=0;
    while(m<n&&str[m])
    m++;

    char* p = new char[n + 1];
    */

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;//ָ��p�����Զ��������ڷ��ظ���������������ĵ�ֵַ��p�����ٴ���
}
#endif


//�����嵥8.10 ʹ�ú�������
#if 0
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main()
{
    using namespace std;
    unsigned long n = 12345678; // test value
    const char* trip = "Hawaii!!";   // test value

    char* temp;

    for (int i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;

        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; // point to temporary storage
    }
    // cin.get();
    return 0;
}

// This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;       // return 0 if no digits

    while (n /= 10)
        digits++;   //��������num�м�λ

    if (digits > ct)//��λ������Ҫ������λ��(�Ӹ�λ����λ����)
    {
        ct = digits - ct;//����Ҫɾ����λ(�ӵ�λ���λɾ��)

        while (ct--)
            num /= 10;
        return num;         // return left ct digits
    }
    else //��λ��С�ڻ����Ҫ������λ��(�Ӹ�λ����λ����)
        return num;     // return the whole number
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;

    char* p = new char[n + 1];

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;
}
#endif


//�����嵥8.11 ʹ�ú���ģ��
#if 0
// function template prototype ����һ������ģ��
template <typename T>  // or class T ��ʹ�ùؼ���class   ����������ΪT
void Swap(T& a, T& b);

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y);  // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y << ".\n";
    // cin.get();
    return 0;
}

// function template definition ���庯��ģ��
template <typename T>  // or class T
void Swap(T& a, T& b)
{
    T temp;   // temp a variable of type T ����һ��T���͵ı���temp
    temp = a;
    a = b;
    b = temp;
}
#endif


//�����嵥8.12 ʹ�����ص�ģ��
#if 0
template <typename T>     // original template
void Swap(T& a, T& b);

template <typename T>     // new template
void Swap(T* a, T* b, int n);

const int Lim = 8;
void Show(int a[]);

int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);              // matches original template
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = { 0,7,0,4,1,7,7,6 };
    int d2[Lim] = { 0,7,2,0,1,9,6,9 };
    cout << "Original arrays:\n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);        // matches new template
    cout << "Swapped arrays:\n";
    Show(d1);
    Show(d2);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];
    cout << endl;
}
#endif


//�����嵥8.13 ʹ����ʽ���廯
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//����һ������ģ�壬����������ΪT
void Swap(T& a, T& b);

// explicit specialization 
template <> void Swap<job>(job& j1, job& j2);
//��ʽ���廯
//��ʹ��Swap()ģ�������ɺ������壬��ʹ��ר��Ϊjob������ʽ�ض���ĺ�������
//��д�ɣ�
//template <> void Swap<>(job& j1, job& j2);
//template <> void Swap(job& j1, job& j2);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);    //��ʽʵ���������� void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = { "Susan Yaffee", 73000.60, 7 };
    job sidney = { "Sidney Taffee", 78060.72, 9 };
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);

    cout << "After job swapping:\n";
    Swap(sue, sidney); // uses void Swap(job &, job &)
    Show(sue);
    Show(sidney);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template <> void Swap<job>(job& j1, job& j2)  // specialization
//д������
//template <> void Swap<>(job& j1, job& j2)  // specialization
//д������
//template <> void Swap(job& j1, job& j2)  // specialization
{
    double t1;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    int t2;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif
//�����嵥8.13 �ģ�
//���ú���ʱ��������ʽʵ������Ҫע��ĵ�
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//����һ������ģ�壬����������ΪT
void Swap(T& a, T& b);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10;
    double j = 20.2;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap<double>(i, j);    //��ʽʵ����������ģ�壬���� void Swap(double &, double &)
    //***ע***
    //��Ȼ���뺯���Ķ���double���͵�ֵ���������������е� i ����int���ͣ����Բ��ܲ���ָ��int���͵� i ������
    cout << "Now i, j = " << i << ", " << j << ".\n";

    // cin.get();
    return 0;
}

template <typename T>
void Swap(const T& a, const T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;

    return;
}

void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif



//ʹ����ʽʵ����
//��һ������ʱ������ʽʵ����
#if 0
template <typename T>
T add(T a, T b);

template double add<double>(double, double);//ʹ��add()ģ������һ��ʹ��double���͵�ʵ��(��������)

int main(void)
{
    using namespace std;

    double m = 6;
    double n = 10.2;

    cout << add(m, n) << endl;

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif
//���������ú���ʱ��������ʽʵ����
#if 0
template <typename T>
T add(T a, T b);

int main(void)
{
    using namespace std;

    int m = 6;
    double n = 10.2;

    cout << add<double>(m, n) << endl;//��ʾʵ������ʹ��add()ģ������һ��ʹ��double���͵�ʵ��

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif


//�����嵥8.14 ���ؽ�������ʾ�����������
#if 0
template <typename T>            // template A ����ʵ�����������ƣ���ָ��������Ԫ�ص�ָ��
void ShowArray(T arr[], int n);

template <typename T>            // template B ����ʵ����ָ��һ��ָ��������Ԫ�ص�ָ��
//void ShowArray(T* arr[], int n);
//д������
void ShowArray(T** arr, int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    //************************************************************************
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);  // uses template A
//************************************************************************

    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double* pd[3];//����һ��ָ������
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;//��ָ�������ÿ��Ԫ��(��ÿ��ָ��)��ֵ�������ǽṹ�ĳ�Աamount�ĵ�ַ

    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
//************************************************************************

    // cin.get();
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;

    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << endl;
}

template <typename T>
void ShowArray(T** arr, int n)
{
    using namespace std;

    cout << "template B\n";
    for (int i = 0; i < n; i++)
        /*cout << *arr[i] << ' ';*/cout << **(arr + i) << ' ';
    cout << endl;
}
#endif


//�����嵥8.15 ��д���ʵĺ������ã�ָʾ������ʹ���û���ϣ���ĺ�����ģ�庯��
#if 0
template<class T>
T lesser(T a, T b)         // #1
{
    return a < b ? a : b;
}

int lesser(int a, int b)  // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;

    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;       // use #2
    cout << lesser(x, y) << endl;       // use #1 with double
    cout << lesser<>(m, n) << endl;     // use #1 with int
    cout << lesser<int>(x, y) << endl; // use #1 with int

    // cin.get();
    return 0;
}
#endif


//C++11�Ĺؼ���decltype ����ȷ���βν��������õ���ֵ�����ͣ��Լ�ȷ�������ķ���ֵ������
#if 0
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y);// ->decltype(x+y) ˵������������x+y������ֵ������

int main(void)
{
    using namespace std;

    int a = 1;
    double b = 2.2;
    cout << add(a, b) << endl;

    return 0;
}
/*
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    decltype(x + y) sum = x + y;

    return sum;
}
*/
//Ҳ����ʹ��typedef������������һ������ʹ�õı�ǩ(ȡ������)
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    typedef decltype(x + y)  LeiXin;
    LeiXin sum = x + y;

    return sum;
}
#endif
#endif


//chapter 8
//code2.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//8.7��ϰ��
//2.
#if 0
void song(const char* name = "O.My Papa", int times = 1);
#endif


//3.
#if 0
void iquote(int num)
{
    cout << "\"" << num << "\"" << endl;
}
void iquote(double num)
{
    cout << "\"" << num << "\"" << endl;
}
void iquote(std::string str)
{
    cout << "\"" << str << "\"" << endl;
}
#endif


//4.
#if 0
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void show(box& r_box)
{
    using namespace std;
    cout << r_box.maker << endl;
    cout << r_box.height << endl;
    cout << r_box.width << endl;
    cout << r_box.length << endl;
    cout << r_box.volume << endl;
}
void fill_volume(box& r_box)
{
    r_box.volume = r_box.length * r_box.width * r_box.height;
}
#endif


//5.
#if 0
#include <array>//array��
#include <string>//string��

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//����һ��const array���󣬸ö������4��string����

void fill(std::array<double, Seasons>&);//�βΣ�ָ��array���������
void show(const std::array<double, Seasons>&);//�βΣ�ָ��array���������

int main()
{
    std::array<double, Seasons> expenses;//����һ��array���󣬰���4��double���͵�ֵ

    fill(expenses);//***ע***ʵ�β���������Ԫ�صĵ�ַ��������������
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons>& r_a)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> r_a[i];
    }
}

void show(const std::array<double, Seasons>& r_a)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << r_a[i] << '\n';
        total += r_a[i];
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//6.
#if 0
//a.
//ʹ��Ĭ��ֵ��
double mass(double density, double volume = 1.0);
//ʹ�ú������ط�
double mass(double density, double volume);
double mass(double density);

//b.
//void repeat(int num=5, const char*);//����Ĭ��ʵ�β����β��б�Ľ�β
//ʹ�ú������ط�
void repeat(int num, const char*);
void repeat(const char*);

//c.
int average(int, int);
double average(double, double);

//d.
/*
char mangle(char* );
const char* mangle(char*);  //***ע***������������ͬ���޷�ʵ�ֺ�������
*/
#endif


//7.
#if 0
template <typename T1, typename T2>
auto bigger(T1 t1, T2 t2)->decltype(t1 > t2 ? t1 : t2)
{
    return (t1 > t2 ? t1 : t2);
}
#endif


//8.
#if 0
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

template <typename T>
T& bigger(T&, T&);

template <>box& bigger(box& b1, box& b2);


template <typename T>
T& bigger(T& x, T& y)
{
    return x > y ? x : y;
}

template <>box& bigger(box& b1, box& b2)
{
    if (b1.volume > b2.volume)
        return b1;
    else
        return b2;
}
#endif
#endif


//chapter 8
//code3.cpp
#if 0
#include <iostream>
//
#if 1
#endif


//8.8�����ϰ
//1.
#if 0
void print(const char*, int num = 0);

int main(void)
{
    const char* p = "ABCdefg";

    for (int i = 0; i < 5; i++)
        print(p, i);

    return 0;
}
void print(const char* p, int num)
{
    using namespace std;
    if (num == 0)
        cout << p << endl << endl;
    else
        cout << p << "\t";				//����δ����ɵ��ڶ���������Ϊ0ʱ����ӡ�Ĵ���Ϊ�������õĴ���
}
#endif
//1.����
#if 0
void print(const char*, int num = 0);

int main(void)
{
    const char* p = "ABCdefg";

    print(p);
    print(p);
    print(p, 1);


    return 0;
}
void print(const char* p, int num)
{
    using namespace std;

    static int count = 0;						//��������ľ�̬����count���ڴ洢���ú����Ĵ���

    count++;
    if (num == 0)
    {
        cout << "�ڶ�������Ϊ0\t" << p << endl;
    }
    else
        for (int i = 0; i < count; i++)
            cout << "�ڶ���������Ϊ0\t" << p << endl;
}
#endif


//2.
#if 0
#include <cstring>

struct CandyBar
{
    char brand[30];
    double weight;
    int calories;
};

void fill_struct(CandyBar&, const char* string = "Millennium Munch",
    double weight = 2.85, int calories = 350);
void show(const CandyBar&);

int main(void)
{
    CandyBar CandyBarStructure;

    fill_struct(CandyBarStructure);
    show(CandyBarStructure);

    return 0;
}
void fill_struct(CandyBar& CB, const char* string,
    const double weight, const int calories)
{
    //strcpy(CB.brand,string);
    //Ҳ����memcpy������ȱ���й�����ĳ��ȵ���Ϣ������strlen()���
    memcpy(CB.brand, string, strlen(string) * sizeof(char) + 1);
    CB.weight = weight;
    CB.calories = calories;
}
void show(const CandyBar& CB)
{
    using namespace std;

    cout << CB.brand << endl;
    cout << CB.weight << endl;
    cout << CB.calories << endl;
}
#endif


//3.
#if 0
#include <string>
#include <cstring>
#include <cctype>

void convert(std::string&);

int main()
{
    using namespace std;

    string str;
    cout << "Enter a string (q to quit)��";
    while (getline(cin, str) && str != "q")
    {
        convert(str);
        cout << str << endl;
        cout << "Next string (q to quit)��";
    }
    cout << "Bye.";

    return 0;
}
void convert(std::string& shuju)
{
    for (int i = 0; shuju[i]; i++)
    {
        if (islower(shuju[i]))
            shuju[i] = toupper(shuju[i]);
    }
}
//������
#if 0
void convert(std::string& shuju)
{
    for (int i = 0; i < shuju.size(); i++)
    {
        if (islower(shuju[i]))
            shuju[i] = toupper(shuju[i]);
    }
}
#endif
#endif


//4.
#if 0
using namespace std;

#include <cstring> // for strlen(),strcpy()

struct stringy {
    char* str; // points to a string
    int ct; // length of string (not counting'\0')
};

// prototypes for set(),show(),and show()go here
void set(stringy&, const char*);
void show(const stringy&, int num = 1);
void show(const char*, int num = 1);
//��дΪ��
//void show(const string& st,int num=1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);// first argument is a reference,
    // allocates space to hold copy of testing,
    // sets str member of beany to point to the
    // new block,copies testing to new block,
    // and sets ct member of beany
    show(beany); // prints member string once
    show(beany, 2); // prints member string twice

    cout << endl << endl;

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing); // prints testing string once
    show(testing, 3);// prints testing string thrice
    show("Done!");

    return 0;
}
void set(stringy& r_stringy, const char* p)
{
    r_stringy.str = new char[strlen(p) + 1];
    strcpy(r_stringy.str, p);

    r_stringy.ct = strlen(p);
}
void show(const stringy& r_stringy, int num)
{
    if (num < 0)
        num = 1;

    while (num--)
        cout << r_stringy.str;
}
void show(const char* p, int num)
{
    if (num < 0)
        num = 1;

    while (num--)
        cout << p;
}
#endif


//5.
#if 0
template <typename T>
T max5(const T* p);

int main(void)
{
    using namespace std;

    int shuju1[5] = { 1,2,3,4,5 };
    double shuju2[5] = { 1.1,2.2,3.3,4.4,5.5 };

    cout << max5(shuju1) << endl;//��ʽʵ����
    cout << max5(shuju2) << endl;

    return 0;
}
template <typename T>
T max5(const T* p)
{
    T max = *p;

    for (int i = 0; i < 5; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
#endif


//6.
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

//template <>const char* maxn(const char** p, int num);//��ʽ���廯
//����
//û����ָ������ƥ��ĺ���ģ��maxnʵ��

//***ע1***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע2***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    const char* shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;

    return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
    T max = *p;

    for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
/*
template <>const char* maxn(const char** p, int num)
{
    const char* max = *p;

    for (int i = 0; i < num; i++)
        if (strlen(*(p + i)) >strlen(max))
            max = p[i];

    return max;
}
*/
#endif
//6.�Ľ��汾1
//***�޸İ취***����ƶ���maxn(shuzu, 5)��maxn�������������Զ��ƶϳ� T Ӧ����Ϊʲô����
//�ɴ˿��Դ�����ʽ���廯
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

template <>const char* maxn<const char*>(const char* const* p, int num);

//***ע1***
// T ������Ϊconst char*
//const char* const* p
//ʵ�����Ƕ�����һ��ָ���ַ����Ķ���ָ�룬�ڶ���const����һ��ָ��ָ������ݲ����޸ģ���һ����const���ƶ���ָ��ָ������ݲ����޸ġ�
//https://blog.csdn.net/xc889078/article/details/8909498

//***ע2***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע3***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    const char* shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;

    return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
    T max = *p;

    for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
template <>const char* maxn<const char*>(const char* const* p, int num)
{
    const char* max = *p;

    for (int i = 0; i < num; i++)
        if (strlen(*(p + i)) > strlen(max))
            max = p[i];

    return max;
}
#endif
//6.�Ľ��汾2
#if 0
#include <cstring>
template <typename T>
const T maxn(const T* p, int num);

template <> const char* const maxn<const char*>(const char* const* p, int num);//��ʽ���廯

//***ע1***
// T ������Ϊconst char*
//const char* const* p
//ʵ�����Ƕ�����һ��ָ���ַ����Ķ���ָ�룬�ڶ���const����һ��ָ��ָ������ݲ����޸ģ���һ����const���ƶ���ָ��ָ������ݲ����޸ġ�
//https://blog.csdn.net/xc889078/article/details/8909498

//***ע2***
//���е���ʽ���廯��
//template <>char maxn(const char* p,int num);
//�������ʽ���廯��
//template <>char* maxn(const char**p, int num);
//����ԭ��T������Ϊchar*�����Ǻ����ĵ�һ������Ϊconst char* *p���޷�ͨ�����룬��Ϊconst char* * ���Ǹ�������

//***ע3***
//const char* maxn(const char** p, int num);�˺��������Ԥ��Ŀ�꣬���ⲻ��ģ�庯��

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    const char* shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;

    return 0;
}
template <typename T>
const T maxn(const T* p, int num)
{
    T max = *p;

    for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
template <> const char* const maxn(const char* const* p, int num)
{
    const char* max = *p;

    for (int i = 0; i < num; i++)
        if (strlen(*(p + i)) > strlen(max))
            max = p[i];

    return max;
}
#endif
//6.�Ľ��汾3 ʹ��string����
#if 0
#include <cstring>
template <typename T>
T maxn(const T* p, int num);

template <>  std::string maxn<std::string>(const std::string* p, int num);//��ʽ���廯

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    string shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;//ʵ�Σ���һ������string����ĵ�ַ

    return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
    T max = *p;

    for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
std::string maxn<std::string>(const std::string* p, int num)
{
    std::string max = *p;

    for (int i = 0; i < num; i++)
        if ((*(p + i)).size() > max.size())
            max = p[i];

    return max;
}
#endif
//6.�汾4  ʹ��string���󣬵����ô���C����ַ������ַ���������
//���޷�ͨ������
#if 0
#include <cstring>
template <typename T>
T maxn(T* p, int num);

template <>  char* maxn(char**, int num);//��ʽ���廯

int main(void)
{
    using namespace std;

    int shuju1[6] = { 1,2,3,4,5,6 };
    double shuju2[4] = { 1.1,2.2,3.3,4.4 };

    cout << maxn(shuju1, 6) << endl;
    cout << maxn(shuju2, 4) << endl << endl;

    string shuzu[5] = { "a","bc","defgh","ij","klm" };
    cout << maxn(shuzu, 5) << endl;//ʵ�Σ���һ������string����ĵ�ַ

    return 0;
}
template <typename T>
T maxn(const T* p, int num)
{
    T max = *p;

    for (int i = 0; i < num; i++)
        if (*(p + i) > max)
            max = p[i];

    return max;
}
template <>  char* maxn(char** p, int num)
{
    char* max = *p;

    for (int i = 0; i < num; i++)
        if (strlen(*(p + i)) > strlen(max))
            max = p[i];

    return max;
}
#endif


//7.
#if 0
template <typename T>            // template A ����ʵ�����������ƣ���ָ��������Ԫ�ص�ָ��
void ShowArray(T arr[], int n);

template <typename T>            // template B ����ʵ����ָ��һ��ָ��������Ԫ�ص�ָ��
void ShowArray(T** arr, int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T** arr, int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    //************************************************************************
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);  // uses template A
    cout << SumArray(things, 6) << endl;
    //************************************************************************

    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double* pd[3];//����һ��ָ������
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;//��ָ�������ÿ��Ԫ��(��ÿ��ָ��)��ֵ�������ǽṹ�ĳ�Աamount�ĵ�ַ

    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
    cout << SumArray(pd, 3) << endl;
    //************************************************************************

        // cin.get();
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;

    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << endl;
}

template <typename T>
void ShowArray(T** arr, int n)
{
    using namespace std;

    cout << "template B\n";
    for (int i = 0; i < n; i++)
        /*cout << *arr[i] << ' ';*/cout << **(arr + i) << ' ';
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

template <typename T>
T SumArray(T** arr, int n)
{
    T sum = 0;

    for (int i = 0; i < n; i++)
        sum += *arr[i];

    return sum;
}
#endif
#endif


/********************************************************************************�����Ǻ����ļ��ĳ���*****************************************************************************************************************************************************************************************/
//chapter 9
//code1.cpp
//�����嵥9.1 ʹ��ͷ�ļ�
//����cxqd9.1.cpp
#if 1
#include "cxqd9.1.h" // structure templates, function prototypes
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
//����cxqd9.5.cpp
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
//����cxqd9.6.cpp
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
        << "   buffer: " << (void*)buffer << endl//ǿ������ת����ʹcout��ʾ��ַ�������ַ���
        << "      pd2: " << pd2
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
//����cxqd9.12.cpp
#if 0
#include <iostream>
//#include "D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 9\code1\Project1\Project1\cxqd9.13.h"
//��дΪ
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


//chapter 9
//code2.cpp
//9.5��ϰ��
//3.
#if 0
int main()
{
    double x;
    std::cout << "Enter value:  ";
    while (!(std::cin >> x))
    {
        std::cout << "Bad input. Please enter a number:  ";
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << "Value = " << x << std::endl;

    return 0;
}
#endif


//4.
#if 0
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x;
    cout << "Enter value:  ";
    while (!(cin >> x))
    {
        cout << "Bad input. Please enter a number:  ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    cout << "Value = " << x << endl;

    return 0;
}
#endif


//chapter 9
//code3.cpp
//9.6�����ϰ
//1.
//����9.6.1.cpp
#if 0
#include "9.6.1.h"
#include <new>
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "������Ҫ���Ľṹ������";
    int count;
    while (!(cin >> count))
    {
        cout << "Bad input. Please enter a number:  ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    cin.get();
    //struct golf golf_structure[count];//����count�����Ǳ���
    //�����1��
    /*const int c_count = count;
    struct golf golf_structure[c_count];*/  //�˷������У�c_count������Ϊ����

    //��ȷ������
    struct golf* p_golfstructure = new golf[count];

    int biaoji = 1;
    int i;
    for (i = 0; i < count; i++)
    {
        cout << "�������" << i + 1 << "���ṹ������" << endl;
        biaoji = setgolf(*(p_golfstructure + i));

        if (!biaoji)
            break;
    }
    //***����count��ֵ�����Դ���ṹ������ֵ***
    count = i;

    cout << "Ҫ�޸Ľṹ�����е�handicap��Ա��ֵ��(����y��n)";
    char answer;
    while (cin.get(answer))
    {
        while (cin.get() != '\n')
            continue;
        answer = tolower(answer);

        if (strchr("yn", answer) == NULL)
            cout << "������y��n : ";
        else
            break;
    }

    if (answer == 'y')
    {
        cout << "������Ҫ�޸ĵ����������ֵ��";
        int num;
        while (!(cin >> num))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cout << "������Ҫ�޸ĵ������handicap��ֵ��";
        int handicap_num;
        while (!(cin >> handicap_num))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cin.get();

        handicap(*(p_golfstructure + num), handicap_num);
        cout << "��" << num + 1 << "���ṹ�޸���ɣ�" << endl;
    }

    cout << "\n�������£�" << endl;
    for (int i = 0; i < count; i++)
    {
        showgolf(*(p_golfstructure + i));
    }

    return 0;
}
#endif


//2.
#if 0
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string str);

int main()
{
    using namespace std;

    string input;
    cout << "Enter a line:\n";
    getline(cin, input);

    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";//***ע***��get()��ȡ���к�����ʧЧλ
        getline(cin, input);
    }
    cout << "Bye\n";

    return 0;
}

void strcount(const std::string str)
{
    using namespace std;

    static int total = 0;        // static local variable ֻ���ڵ�һ�ε��ú���ʱ���г�ʼ��

    cout << "\"" << str << "\" contains ";

    int count = 0;               // automatic local variable
    //while (str[count])               // go to end of string
    //	count++;

    //������
    count = str.size();/*  count=str.length();  */

    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}
#endif


//3.
#if 0
#include <new>
#define SIZE 50
struct chaff
{
    char dross[20];
    int slag;
};

char buffer[SIZE];

int main()
{
    using std::cout;

    struct chaff* p = new (buffer)struct chaff[2];

    const char* data = "abcdefg";
    strcpy(p->dross, data);
    p->slag = 1;
    strcpy((p + 1)->dross, data);
    (p + 1)->slag = 2;

    for (int i = 0; i < 2; i++)
    {
        cout << (p + i)->dross << "\t";
        cout << (p + i)->slag << std::endl;
    }

    delete[]p;

    return 0;
}
#endif


//4.
//����9.6.4.cpp
#if 0
#include "9.6.4.h"

int main()
{
    using SALES::Sales;
    using SALES::setSales;

    Sales Sales_Structure[2];

    setSales(Sales_Structure[0]);

    double data[2]{ 1.1,2.2 };
    setSales(Sales_Structure[1], data, 2);

    SALES::showSales(Sales_Structure[0]);
    showSales(Sales_Structure[1]);

    return 0;
}
#endif


//chapter 10
//code1.cpp
//�����嵥10.3 ����һ�������ʹ���෽��
//����cxqd10.2.cpp
#if 0
#include "cxqd10.1.h"

int main()
{
    Stock   fluffy_the_cat;

    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    // std::cin.get();
    return 0;
}
#endif


//�����嵥10.6 ���캯�������������Լ�C++11���б��ʼ��������
//����cxqd10.5.cpp
#if 0
#include "cxqd10.4.h"

int main()
{
    {//�˶Դ������ṩ��һ������飬ʹ��stock1,stock2,stock3����Щ�Զ�����
     //���ڳ����������������ʱ��ʧ��ִ�������������Ա��۲쵽
     //������main()�����ʱ(�������ʱ)�����������������ڴ��ڻ������޷�ֱ�۹۲쵽
        using std::cout;
        cout << "Using constructors to create new objects\n";
        //��ʽ���ù��캯��
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();

        //��ʽ���ù��캯��
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();

        //���Խ�һ����������ݸ�����һ��
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        //ʹ�ù��캯�����ö��������(��ʽ���ù��캯��)
        //���캯������������ʼ������Ҳ��������������ֵ
        cout << "Using a constructor to reset an object\n";
        //***ע***
        //���캯������һ����ʱ���󣬽��丳ֵ��stock1�������������ɾ����ʱ����
        stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
        cout << "Revised stock1:\n";
        stock1.show();

        //��ʽ����Ĭ�Ϲ��캯��
        Stock stock3;
        stock3.show();

        //C++11���б��ʼ��������
        Stock stock4 = { "abc def",20,20.0 };//��ʽ���ù��캯��
        stock4.show();
        Stock stock5 = {};//��ʽ���ù��캯��
        stock5.show();

        cout << "Done\n";
    }

    return 0;
}
#endif


//�����嵥10.9 �������飬thisָ��
//����cxqd10.8
#if 0
#include "cxqd10.7.h"

const int STKS = 4;
int main()
{
    {
        // create an array of initialized objects
        Stock stocks[STKS] =
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
        };

        std::cout << "Stock holdings:\n";
        int i;
        for (i = 0; i < STKS; i++)
            stocks[i].show();

        // set pointer to first element ��������ʼ��һ��ָ��Stock������ָ��top
        const Stock* top = &stocks[0];
        for (i = 1; i < STKS; i++)
            top = &(top->topval(stocks[i]));//ָ��Ҳ������->�����ʶ���ķ�����Ա

        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        top->show();

        putchar('\n');
        int shares = stocks[0].fanhui_shares();
        //***ע***����Ϊconst��ֵ���ܸ�����const���ݣ�
        //������const��������Ϊ����ֵ���صģ������ȱ���������ʱ�洢��Ԫ����ʱ�洢��Ԫ������
        //�ڱ�������shares�����У����Գ�ȥ�������õ�����⣬��ͳ����ֵ����const���˴���
        std::cout << shares << std::endl;
    }

    // std::cin.get();
    return 0;
}
#endif


//�����嵥10.12 ʹ��ADT����ջ
//����cxqd10.11.cpp
#if 0
#include <cctype>  // or ctype.h
#include "cxqd10.10.h"

int main()
{
    using namespace std;

    Stack st; // create an empty stack (��ʽ����Ĭ�Ϲ��캯��������ʽ��ʼ��)

    unsigned long data;
    cout << "Please enter A to add a purchase order,"
        << "P to delete, or Q to quit.\n";
    char ch;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a number to add: ";
            while (!(cin >> data))
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "���������֣�";
            }
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(data);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(data);//����ջ��ֵ�ḳ��data
                cout << "ջ����Ա ��" << data << " popped\n";
            }
            break;
        }
        cout << "Please enter A to add a purchase order,"
            << "P to delete, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
#endif


//chapter 10
//code2.cpp
//10.9 ��ϰ��
//��5.��7.��9.��
#if 1
#endif


//chapter 10
//code3.cpp
//10.10 �����ϰ
//1.
//����10.10.1.cpp
#if 0
#include "10.10.1.h"
int main()
{
    using namespace std;

    cout << "��������ʼ��account1(��ʽ����Ĭ�Ϲ��캯��)\n";
    Account account1;
    account1.show();

    cout << "��������ʼ��account2(��ʽ���ù��캯��)\n";
    Account account2("Xiao Min", "123456789876");
    account2.show();

    cout << "С������10��Ǯ��\n";
    account2.deposit(10);
    account2.show();

    cout << "С��ȡ��5��Ǯ��\n";
    account2.draw(5);
    account2.show();

    cout << "Done !\n";

    return 0;
}
#endif


//2.
//����10.10.2.cpp
#if 0
#include "10.10.2.h"

int main()
{
    using namespace std;

    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

    one.Show();
    cout << endl;
    one.FormalShow();
    cout << endl;

    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;

    three.Show();
    cout << endl;
    three.FormalShow();
    cout << endl;

    return 0;
}
#endif


//3.
//����10.10.3.cpp
#if 0
#include "10.10.3.h"
int main()
{
    Golf golf1("Xiao min", 1);
    golf1.showgolf();
    golf1.handicap(0);
    golf1.showgolf();

    Golf golf2;
    golf2.showgolf();

    return 0;
}
#endif


//4.
//����10.10.4.cpp
#if 0
#include "10.10.4.h"
int main()
{
    using namespace SALES;

    double data[1] = { 1.1 };
    Sales sales1(data, 1);
    sales1.ShowSales();

    Sales sales2;
    sales2.ShowSales();

    return 0;
}
#endif


//5.
//����10.10.5.cpp
#if 0
#include "10.10.5.h"
#include <cctype>
using namespace std;

void show_order(void);
char get_choice(void);
void fill_stack(Stack& st);
void delete_item(Stack& st);

int main()
{
    Stack stack;

    show_order();
    char ch = get_choice();

    while (ch != 'c')
    {
        switch (ch)
        {
        case 'a':
            fill_stack(stack);
            break;
        case 'b':
            delete_item(stack);
            break;
        }
        show_order();
        ch = get_choice();
    }

    return 0;
}
void show_order(void)
{
    cout << "���������ܶ�Ӧ����ĸ��";
    cout << "\na) ��ӹ˿�" << '\t' << "b) ɾ���˿�\n";
    cout << "c) �˳�\n";
}
char get_choice(void)
{
    char answer;
    while (cin.get(answer))
    {
        while (cin.get() != '\n')
            continue;
        answer = tolower(answer);

        if (strchr("abc", answer) == NULL)
            cout << "\a����a��b��c : ";
        else
            break;
    }
    return answer;
}
void fill_stack(Stack& st)
{
    if (st.isfull())
    {
        cout << "ջ������";
        return;
    }

    Item item;
    cout << "������˿͵����֣�";
    char temp[35];
    double money = 0.0;
    while (cin.get(temp, 34))//get()��ȡ���к������ʧЧλ   ***ע***����д��	while (cin.get(temp, 34).get())
    {
        cout << "������˿͸���";
        while (!(cin >> money))
        {
            cout << "Bad input. Please enter a number:  ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        cin.get();

        strcpy(item.fullname, temp);
        item.payment = money;
        st.push(item);
        cout << "������˿͵����֣�(ֻ����Enter��ֹͣ)";
    }

    cin.clear();//***ע***�˾��д
    cin.get();//���ĵ����з�(����ջ�����������)
}
void delete_item(Stack& st)
{
    if (st.isempty())
    {
        cout << "ջΪ�գ�";
        return;
    }

    Item item;
    st.pop(item);

    cout << "ջ����Ա ��" << item.fullname << '\t'
        << item.payment << " popped\n";

    static double sum = 0.0;
    sum += item.payment;

    cout << "����" << sum << "Ԫ\n\n";
}
#endif


//6.
//����10.10.6.cpp
#if 0
#include "10.10.6.h"

int main()
{
    Move move;
    move.showmove();

    Move temp(1, 1);
    move = move.add(temp);//�������ֵ
    move.showmove();

    move.rest();
    move.showmove();

    return 0;
}
#endif


//7.
//����10.10.7.cpp
#if 0
#include "10.10.7.h"

int main()
{
    BetelPlorg b1;
    b1.show();

    BetelPlorg b2("Xiao min", 20);
    b2.show();

    b2.modification(80);
    b2.show();

    return 0;
}
#endif


//8.(���ͣ�����ʵ����ʽ����ʽ�ṹ)
//����10.10.8.cpp
#if 0
#include "10.10.8.h"
void showmovies(Item& item);

char* s_gets(char* string, int num);

int main(void)
{
    List movies;//����һ�������movies(��ʽ����Ĭ�Ϲ��캯��������ʽ��ʼ��)

    Item temp;//����һ��film�ṹ���ֵĽṹtemp

//��ʼ�������ͷָ��
//InitializeList(&movies);
    if (movies.ListIsFull())
    {
        fprintf(stderr, "�������������Ѵﵽ���ֵ��");
        exit(1);
    }

    //��ȡ�û����벢�洢
    puts("�������Ӱ�ı��⣺");
    while (s_gets(temp.title, LENGTH) != NULL && temp.title[0] != '\0')
    {
        puts("��������������(0-10)��");
        scanf("%d", &temp.rating);

        while (getchar() != '\n')
            continue;

        if (movies.AddItem(temp) == false)
        {
            fprintf(stderr, "���󣬷����ڴ�ʧ�ܣ�");
            break;
        }
        if (movies.ListIsFull())
        {
            puts("���������Ѵﵽ���ֵ��");
            break;
        }

        puts("��������һ����Ӱ�ı���(����^Z��������˳�)��");
    }

    //��ʾ
    if (movies.ListIsEmpty())
        printf("û���������룡\n");
    else
    {
        printf("�����ǵ�ӰĿ¼\n");
        movies.Visit(showmovies);
    }
    printf("��������%d����Ӱ\n", movies.ListItemCount());

    //����
    movies.EmptyTheList();
    printf("�ټ���\n");

    return 0;
}
void showmovies(Item& item)
{
    printf("��Ӱ��:%-20s��Ӱ����:%d\n", item.title, item.rating);
}
char* s_gets(char* string, int num)
{
    char* fanhui;
    char* find;

    fanhui = fgets(string, num, stdin);

    if (fanhui)
    {
        if (find = strchr(string, '\n'))
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return fanhui;
}
#endif


//8.����(���ͣ�ջ��ʵ����ʽ������)
//ͷ�ļ���ջ����


//chapter 11
//code1.cpp
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
    Stonewt p1 = 275; // uses constructor to initialize

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


//chapter 11
//code2.cpp
//11.8 ��ϰ��
//1.
//����11.8.1.cpp
#if 0
#include "11.8.1.h"
int main()
{
    using std::cout;
    using std::endl;

    Stonewt w1(10, 8);

    Stonewt w2 = 2 * w1;

    cout << double(w2) << "�����൱��";//ʹ����ʽǿ������ת��

    w2.show_stn();

    return 0;
}
#endif


//7.
//����11.8.7.cpp
#if 0
#include "11.8.7.h"
int main()
{
    using namespace VECTOR;
    using namespace std;

    Vector v1(1, 1);

    double length = double(v1);

    cout << length << endl;

    return 0;
}
#endif


//chapter 11
//code3.cpp
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

void show_average(double*, int);

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
    double* p_data = (double*)0;//***ע***�˴������ȶ�ָ���ʼ��
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
                << result.magval() / steps << endl << endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }

        show_average(p_data, num);
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

void show_average(double* p, int n)
{
    using std::cout;
    using std::endl;

    double min, max, sum = 0.0;
    min = max = *p;

    for (int i = 0; i < n; i++)
    {
        *(p + i) > max ? max = *(p + i) : 1;
        *(p + i) < min ? min = *(p + i) : 1;
        sum += *(p + i);
    }

    cout.put('\n');
    cout << n << "�β����У�\n���ƽ��������" << max
        << "\n���ƽ��������" << min << endl
        << n << "�β��Ե�ƽ��������" << sum / n << endl << endl;
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
    Stonewt p2(200.6, Stonewt::INTEGER_POUNDS);//ʹ��������Ϊ�����ʾ����
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

    temp = -p1;
    cout << "-p1=" << temp;

    temp = p1 * 2;
    cout << "p1*2=" << temp;

    temp = 2 * p1;
    cout << "2*p1=" << temp;

    cout << "The wrestler weighed even more.\n";
    //***ע***
    //422ת��Ϊ422.0��Ȼ��ʹ��Stonewt(double pds,Mode form= FLOAT_POUNDS)���캯��
    //����һ����ʱStonewt���󣬴���display()
    display(422, 2);

    //�������ģʽ����ȷ
    Stonewt p4(1.5, Stonewt::STONE);
    cout << p4;
    Stonewt p5(1, 5, Stonewt::FLOAT_POUNDS);
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

void show_report(const Stonewt* p, int num);

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

    show_report(array, 6);

    return 0;
}

void show_report(const Stonewt* p, int num)
{
    using std::cout;
    using std::endl;

    Stonewt stone11(11, 0);//��154pounds
    int count = 0;

    Stonewt min, max;
    min = max = *p;

    for (int i = 0; i < num; i++)
    {
        if (*(p + i) > max)
            max = *(p + i);
        if (*(p + i) < min)
            min = *(p + i);
        if (*(p + i) >= stone11)
            count++;
    }

    cout << "\n��С������" << min << endl
        << "���������" << max << endl
        << "���ڻ����11Ӣʯ��������" << count << endl;
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


//chapter 12
//code1.cpp
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
            if (shortest->length() > sayings[i].length())
                shortest = &sayings[i];
            if (*first > sayings[i])        // compare values
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


//chapter 12
//code2.cpp
#if 0
int main()
{
    //const char a[]; ��Ч�������������ں�����������ָ��ʱ��[]
    //a = "abc";
}
#endif


//chapter 12
//code3.cpp
//12.10 �����ϰ
//1.
//����12.10.1.cpp
#if 0
#include "12.10.1.h"

int main()
{
    using namespace std;

    Cow cow1;
    cow1.ShowCow();

    Cow cow2("abc", "programming", 70);//���ù��캯��
    cow2.ShowCow();

    Cow cow3("def", "relaxing", 60);
    cow3.ShowCow();

    cow1 = cow2 = cow3;//���ø�ֵ��������غ���
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    Cow cow4(cow3);//���ø��ƹ��캯��
    cow4.ShowCow();

    Cow cow5[2] = { {"ghj","aaa",50} };
    cow5[0].ShowCow();
    cow5[1].ShowCow();

    return 0;
}
#endif


//2.
//����12.10.2.cpp
#if 0
using namespace std;
#include "12.10.2.h"

int main()
{
    String s2 = "Please enter your name: ";
    String s3;

    cout << s2; // overloaded << operator
    cin >> s3; // overloaded >> operator

    s2 = "My name is " + s3; // overloaded =,+ operators
    cout << s2 << ".\n";

    String s1(" and I am a C++ student.");
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase

    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";

    s1 = " red";  // String (const char *),
    String rgb[3] = { String(s1),String("green"),String("blue") };

    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again !\n";
    }
    cout << "Bye\n";
    return 0;
}
#endif


//3.
//����12.10.3.cpp
#if 0
#include "12.10.3.h"

const int STKS = 4;
int main()
{
    {
        // create an array of initialized objects
        Stock stocks[STKS] =
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
        };

        std::cout << "Stock holdings:\n";
        int i;
        for (i = 0; i < STKS; i++)
            std::cout << stocks[i];

        // set pointer to first element ��������ʼ��һ��ָ��Stock������ָ��top
        const Stock* top = &stocks[0];
        for (i = 1; i < STKS; i++)
            top = &(top->topval(stocks[i]));//ָ��Ҳ������->�����ʶ���ķ�����Ա

        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        std::cout << *top;
    }

    // std::cin.get();
    return 0;
}
#endif


//4.
//����12.10.4.cpp
#if 0
#include <cctype>  // or ctype.h
#include "12.10.4.h"

bool fill_data(Stack& s, Item& data);
void showdata(Item& item);

int main()
{
    using namespace std;

    Stack st(3);

    Item data;
    cout << "Please enter A to add a purchase order,"
        << "P to delete, S to show, or Q to quit.\n";
    char ch;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            if (!fill_data(st, data))
                cout << "stack already full\n";
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(data);//����ջ��ֵ�ḳ��data
                cout << "ջ����Ա ��" << data << " popped\n";
            }
            break;
        case 'S':
        case 's':
            st.traverse(showdata);
            break;
        }
        cout << "Please enter A to add a purchase order,"
            << "P to delete, S to show, or Q to quit.\n";
    }

    cout << "ʹ�ø��ƹ��캯����" << endl;
    Stack st1(st);
    cout << "st1�������ǣ�";
    st1.traverse(showdata);

    cout << "ʹ�ø�ֵ��������غ�����" << endl;
    Stack st2;
    st2 = st;
    cout << "st2�������ǣ�";
    st2.traverse(showdata);

    cout << "Bye\n";
    return 0;
}

bool fill_data(Stack& s, Item& data)
{
    if (s.isfull())
        return false;

    using std::cout;
    using std::cin;

    cout << "Enter a number to add: ";
    while (!(cin >> data))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "���������֣�";
    }
    s.push(data);
    return true;
}
void showdata(Item& item)
{
    using std::cout;
    using std::endl;

    cout << item << "     ";
}
#endif


//5.
//����12.10.5.cpp
#if 0
#include "12.10.5.h"
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

    cout << "The number of simulation hours : 100Сʱ\n";
    int hours = 100;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Calculating the average number of customers per hour: \n......\n";
    double perhour = 10;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//��ÿλ�ͻ�������ƽ��ʱ��

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line

    do {
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        //***ע***ÿ��ģ����ɺ�Ҫ�Ը�������0
        turnaways = customers = served = sum_line\
            = wait_time = line_wait = 0;

        //***ע***
        //�����´�����ʱ���еĽڵ�û�����
        //������
        while (!line.isempty())
            line.dequeue(temp);

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

    } while (((double)line_wait / served) <= 1.0/*|| ((double)line_wait / served) >= 1.1*/);

    // reporting results
    if (customers > 0)
    {
        cout << "ÿСʱ����Ŀͻ�����" << perhour << endl;
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


//6.
//����12.10.6.cpp
#if 0
#include "12.10.6.h"
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
    cout << "Maximum size of queue: 10\n";
    //int qs;
    //cin >> qs;
    //Queue line(qs);                 //���������ù��캯����ʼ��
    //										  // line queue holds up to qs people
    Queue line[2];

    //***ע***���ڰѸ�ֵ��������غ���������private�����Բ���ʵ�ֶ���丳ֵ
    //line[0] = Queue(qs);

    cout << "The number of simulation hours : 100 Сʱ\n";
    int hours = 100;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Calculating the average number of customers per hour: \n......\n";
    double perhour = 10;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//��ÿλ�ͻ�������ƽ��ʱ��


    Item temp;              //***ע***�ͻ���һ�������ܷŵ��ṹ����

    typedef struct			//�洢�������е��Ŷ����
    {
        long turnaways;     //  turned away by full queue
        long customers;     //  joined the queue
        long served;        //  served during the simulation
        long sum_line;      //  cumulative line length
        int wait_time;      //  time until autoteller is free
        long line_wait;     //  cumulative time in line
    }x;

    x x_struct[2];//***ע***�޷�ʹ��C�ĳ�ʼ����

    double temp1, temp2, result;

    do
    {
        perhour++;
        min_per_cust = MIN_PER_HR / perhour;
        //***ע***ÿ��ģ����ɺ�Ҫ�Ը�������0
        for (int i = 0; i < 2; i++)
        {
            x_struct[i].customers = x_struct[i].line_wait = x_struct[i].served
                = x_struct[i].sum_line = x_struct[i].turnaways
                = x_struct[i].wait_time = 0;
        }

        //***ע***
        //�����´�����ʱ���еĽڵ�û�����
        //������
        while (!line[0].isempty())
            line[0].dequeue(temp);

        while (!line[1].isempty())
            line[1].dequeue(temp);

        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line[0].isfull())
                    x_struct[0].turnaways++;

                if (line[1].isfull())
                    x_struct[1].turnaways++;

                if (!line[0].isfull() || !line[1].isfull())
                {
                    if (line[0].queuecount() <= line[1].queuecount())
                    {
                        x_struct[0].customers++;
                        temp.set(cycle);    // cycle = time of arrival
                        line[0].enqueue(temp); // add newcomer to line
                    }
                    else
                    {
                        x_struct[1].customers++;
                        temp.set(cycle);    // cycle = time of arrival
                        line[1].enqueue(temp); // add newcomer to line
                    }
                }
            }

            if (x_struct[0].wait_time <= 0 && (!line[0].isempty()))//�����п������нڵ�ʱ
            {
                line[0].dequeue(temp);     //�ŵ�һ���Ĺ˿��ڶ����б��ų����俪ʼ���н���
                x_struct[0].wait_time = temp.ptime(); //wait_time�����н���������ʱ��
                x_struct[0].line_wait += cycle - temp.when();
                x_struct[0].served++;
            }

            if (x_struct[1].wait_time <= 0 && (!line[1].isempty()))//�����п������нڵ�ʱ
            {
                line[1].dequeue(temp);     //�ŵ�һ���Ĺ˿��ڶ����б��ų����俪ʼ���н���
                x_struct[1].wait_time = temp.ptime(); //wait_time�����н���������ʱ��
                x_struct[1].line_wait += cycle - temp.when();
                x_struct[1].served++;
            }

            if (x_struct[0].wait_time > 0)
                x_struct[0].wait_time--;

            if (x_struct[1].wait_time > 0)
                x_struct[1].wait_time--;

            x_struct[0].sum_line += line[0].queuecount();
            x_struct[1].sum_line += line[1].queuecount();
        }

        temp1 = (double)x_struct[0].line_wait / x_struct[0].served;
        temp2 = (double)x_struct[1].line_wait / x_struct[1].served;

        result = (temp1 + temp2) / 2;

    } while (result <= 1.0);
    //(((double)x_struct[0].line_wait / x_struct[0].served) <= 1.0
    //	|| ((double)x_struct[0].line_wait / x_struct[0].served) >= 1.1)
    //	|| (((double)x_struct[1].line_wait / x_struct[1].served) <= 1.0
    //		|| ((double)x_struct[1].line_wait / x_struct[1].served) >= 1.1)

    // reporting results
    cout << "ÿСʱ����Ŀͻ�����" << perhour << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "customers accepted: " << x_struct[i].customers << endl;//������е�����
        cout << "  customers served: " << x_struct[i].served << endl;//�ѷ����������
        cout << "         turnaways: " << x_struct[i].turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)x_struct[i].sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)x_struct[i].line_wait / x_struct[i].served << " minutes\n";
    }

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


//chapter 13
//code1.cpp
//�����嵥13.3 ʹ��һ���򵥵Ļ���
//����cxqd13.2.cpp
#if 0
#include "cxqd13.1.h"

int main(void)
{
    using std::cout;

    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    // std::cin.get();
    return 0;
}
#endif


//�����嵥13.6 ʹ�������࣬��ʾ������ͻ���Ĺ�ϵ
//����cxqd13.5.cpp 
#if 0
#include "cxqd13.4.h"

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    player1.Name();           // �������ʹ�û���ķ���
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";

    //��������ʼ�����������
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();          // ���������ʹ�û���ķ���
    //д������
    //rplayer1.TableTennisPlayer::Name();

    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    //ʹ�û�������ʼ�����������
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    RatedPlayer rplayer3(333, "Aaa", "Bbb", true);
    TableTennisPlayer player3(rplayer3);//ʹ������������ʼ���������
    player3.Name();
    cout.put('\n');

    RatedPlayer rplayer4(444, "Ccc", "Ddd", true);
    TableTennisPlayer player4;//ʹ�����������ֵ���������
    player4 = rplayer4;
    player4.Name();
    cout.put('\n');

    // std::cin.get();
    return 0;
}
#endif


//�����嵥13.9 ���Ժ��麯���Ļ����������(����ʹ���鷽��������)
//����cxqd13.8.cpp
#if 0
#include "cxqd13.7.h"

void fv(BrassPlus b)
{
    b.ViewAcct();
}

void fv_1(Brass* pb)
{
    pb->ViewAcct();
}

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl << endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);//ʹ��Brass���Withdraw��������֧��͸֧
    cout << "Pigg account balance: $" << Piggy.Balance() << endl << endl;

    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);//ʹ��BrassPlus���Withdraw������֧��͸֧
    Hoggy.ViewAcct();
    // std::cin.get();
    cout.put('\n');
    fv(Piggy);//Brass���󴫵ݸ�BrassPlus���͵��βεĺ��������ȵ��������๹�캯����������ת������ʹ��fv()����
    cout.put('\n');
    fv_1(&Hoggy);

    return 0;
}
#endif


//�����嵥13.10 ��Ķ�̬(ͬһ��������������ͻ����е���Ϊ��ͬ)�����麯��
//����cxqd13.8.cpp
#if 0
#include "cxqd13.7.h"
#include <string>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass* p_clients[CLIENTS];//����һ�����飬ÿ��Ԫ�ض���ָ��Brass���ָ��
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";

        while (!(cin >> kind) || (kind != '1' && kind != '2'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                tmax, trate);
        }
        while (cin.get() != '\n')//���ĵ����з�������getline()����ȡ�����ڶ��μ�֮�������
            continue;
    }

    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}
#endif


//�����嵥13.13 �ؼ���protected�����麯�����������ABC
//����cxqd13.12.cpp
#if 0
#include <string>
#include "cxqd13.11.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC* p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                tmax, trate);
        }

        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    // cin.get();
    return 0;
}

#endif


//�����嵥13.16 ������ʹ�ö�̬�ڴ�������������η��ʻ������Ԫ����
//����cxqd13.15.cpp
#if 0
#include "cxqd13.14.h"

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;

    lacksDMA balloon("red", "Blimpo", 4);
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;

    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;

    lacksDMA balloon2(balloon);//ʹ��Ĭ�ϵĸ��ƹ��캯��
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;//ʹ����ʽ�ĸ�ֵ��������غ���
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    // std::cin.get();
    return 0;
}
#endif


//chapter 13
//code2.cpp
//13.10 ��ϰ��
//14.
//������
#if 0
int main()
{


    return 0;
}
#endif


//chapter 13
//code3.cpp
//13.11 �����ϰ
//1.
//����13.11.1.cpp
#if 0
#include "13.11.1.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Using object directly:\n";
    c1.Report();// use Cd method
    c2.Report(); ;// use Classic method
    cout << endl;

    cout << "Using type cd * pointer to objects:\n";
    Cd* pcd = &c1;
    pcd->Report();// use Cd method for cd object
    pcd = &c2;
    pcd->Report();// use Classic method for classic object
    cout << endl;

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy.Report();
    copy = c2;
    copy.Report();

    return 0;
}
void Bravo(const Cd& disk)//���Խ��ж�̬����(����ʹ�ö�����������ķ���)
{												//���virtual�麯��
    disk.Report();
}
#endif


//2.
//����13.11.2.cpp
#if 0
#include "13.11.2.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Using object directly:\n";
    c1.Report();// use Cd method
    c2.Report(); ;// use Classic method
    cout << endl;

    cout << "Using type cd * pointer to objects:\n";
    Cd* pcd = &c1;
    pcd->Report();// use Cd method for cd object
    pcd = &c2;
    pcd->Report();// use Classic method for classic object
    cout << endl;

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy.Report();
    copy = c2;
    copy.Report();

    return 0;
}
void Bravo(const Cd& disk)//���Խ��ж�̬����(����ʹ�ö�����������ķ���)
{												//���virtual�麯��
    disk.Report();
}
#endif


//3.
//����13.11.3.cpp
#if 0
#include "13.11.3.h"

const int SIZE = 3;
char* getlabel(void);        //���ַ�����ռ���ڴ���ж�̬����

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DmaABC* p_dma[SIZE];//����һ�����飬ÿ��Ԫ�ض���ָ���������ָ��
    char* p_label_data;
    int rating;
    char kind;
    char color_data[40];
    char style[40];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the label name: ";
        p_label_data = getlabel();
        cout << "Enter the number of rating: ";
        cin >> rating;

        cout << "Enter 1 for baseDMA or "
            << "2 for lacksDMA or " << "3 for hasDMA:";

        while (!(cin >> kind) || (kind != '1' && kind != '2' && kind != '3'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 or 3 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        cin.get();//���ĵ����з�

        if (kind == '1')
            p_dma[i] = new baseDMA(p_label_data, rating);
        else if (kind == '2')
        {
            cout << "Enter the color: ";
            cin.getline(color_data, 40);
            p_dma[i] = new lacksDMA(color_data, p_label_data, rating);
        }
        else
        {
            cout << "Enter the style: ";
            cin.getline(style, 40);
            p_dma[i] = new hasDMA(style, p_label_data, rating);
        }

        delete p_label_data;
        //while (cin.get() != '\n')//���ĵ����з�������getline()����ȡ�����ڶ��μ�֮�������
        //    continue;//����Ҫ����Ϊgetline��ѻ��з��滻��'\0'
    }

    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete p_dma[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}

char* getlabel(void)        // return pointer to new string
{
    using std::cout;
    using std::cin;

    char temp[80];      // temporary storage �������������ӣ��Զ��洢��

    cin >> temp;        //temp�����ݴ����������

    char* pn = new char[strlen(temp) + 1];//����������ַ���������̬����һ���ڴ�ռ�

    strcpy(pn, temp); // copy string into smaller space 
                                 //***ע***strcpy()��⵽temp�е�'\0'���'\0'Ҳ������pnָ����ڴ�ռ����Ӧλ�ã�Ȼ��ֹͣ����
    return pn;          // temp lost when function ends
}//��������ʱ��pn�����٣�����ָ����ڴ�����(��)��������

#endif


//4.
//����13.11.4.cpp
#if 0
int main()
{


    return 0;
}
#endif


//chapter 14
//code1.cpp
//�����嵥14.3 has-a��ϵ��ʹ�ð�������(������һ������������������)
//ʹ�ø�����
//����cxqd14.2.cpp
#if 0
#include "cxqd14.1.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };
    //ʹ���˹��캯��������ת������(��ʽ����ת��)

    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//�����嵥14.6 has-a��ϵ��ʹ��˽�м̳м���
//����cxqd14.5.cpp
#if 0
#include "cxqd14.4.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };

    int i;
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//�����嵥14.9 ʹ�ù��е��ؼ̳�
//����cxqd14.8.cpp
#if 0
#include "cxqd14.7.h"
const int LIM = 4;

int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

    int i;
    for (i = 2; i < LIM; i++)
        pw[i]->Set();

    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.12 ʹ�ù��ж��ؼ̳�(����MI)
//����cxqd14.11.cpp
#if 0
#include <cstring>
#include "cxqd14.10.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";

        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':   lolas[ct] = new Waiter;
            break;
        case 's':   lolas[ct] = new Singer;
            break;
        case 't':   lolas[ct] = new SingingWaiter;
            break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥14.14 ʹ����ģ�壬ʹ��ģ������stringջ
//������
#if 0
#include "cxqd14.13.h"
#include <string>
#include <cctype>

using std::cin;
using std::cout;

int main()
{                                          //ģ�����ʽʵ����
    Stack<std::string> st;   // create an empty stack ��������Ĭ�Ϲ��캯����ʼ��һ����ջ
                                           //***ע***������ʽ���ṩ���������
    std::string po;

    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    char ch;
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
            }
        }

        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥14.16 ʹ����ģ�壬ʹ��ģ���ö�̬�ڴ��������ָ��ջ
//������
#if 0
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()
#include "cxqd14.15.h"

const int Num = 10;

int main()
{
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    // create an empty stack with stacksize slots
    Stack<const char*> st(stacksize);//����һ����̬�ڴ�����ָ��ջ

    // in basket                                                   //����ָ������
    const char* in[Num] = {
            " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
            " 3: Betty Rocker", " 4: Ian Flagranti",
            " 5: Wolfgang Kibble", " 6: Portia Koop",
            " 7: Joy Almondo", " 8: Xaverie Paprika",
            " 9: Juan Moore", "10: Misha Mache"
    };
    // out basket
    const char* out[Num];

    std::srand(std::time(0)); // randomize rand()
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num)   // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }

    for (int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;

    std::cout << "Bye\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.18 ʹ����ģ�壬ʹ�÷�ģ�����Ͳ������ṩ��������Ĵ�С
//��ʵ�ֵݹ����ģ�壬���ɶ�ά����
//������
#if 0
#include "cxqd14.17.h"

int main(void)
{
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums;//����int sums[10]
    ArrayTP<double, 10> aves;//����double aves[10]
    ArrayTP< ArrayTP<int, 5>, 10> twodee;//����int twodee[10][5]


    int i, j;

    for (i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double)sums[i] / 5;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }

    cout << "Done.\n";
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.19 ʹ����ģ�壬ʹ�ö�����Ͳ���
//������
#if 0
#include <string>

template <class T1, class T2 = int>//����Ϊ���Ͳ����ṩĬ��ֵ
class Pair
{
private:
    T1 a;
    T2 b;

public:
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval)
    { }
    Pair()
    {}
    T1& first();//�����޸�a
    T2& second();
    T1 first() const//����ֻ��ȡa
    {
        return a;
    }
    T2 second() const
    {
        return b;
    }
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    Pair<string, int> ratings[4] =
    {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);

    cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
        << ratings[i].first() << endl;

    cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t "
        << ratings[3].first() << endl;
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.20 ʹ�ó�Աģ��
//һ��ģ���ཫ��һ��ģ�����ģ�庯����Ϊ���Ա(��ģ���ڶ���)
//������
#if 0
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:                                    //Ƕ��ģ�����Ա
    template <typename V>  // nested template class member
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    };

    hold<T> q;             // template object ��������T���͵�hold����
    hold<int> n;           // template object

public:
    beta(T t, int i) : q(t), n(i) {}

    template<typename U>   // template method
    U blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }

    void Show() const
    {
        q.show(); n.show();
    }
};

int main()
{
    beta<double> guy(3.5, 3);

    cout << " beta<double> guy(3.5, 3);" << endl;
    cout << "T was set to double\n\n";

    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n\n";

    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n\n";

    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n\n";
    cout << "Done\n";
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.20 ʹ�ó�Աģ��
//һ��ģ���ཫ��һ��ģ�����ģ�庯����Ϊ���Ա(��ģ���ⶨ�壬�˱�������֧��)
//������
#if 0
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:                                    //Ƕ��ģ�����Ա����
    template <typename V>
    class hold;
    /* {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    }; */

    hold<T> q;             // template object ��������T���͵�hold����
    hold<int> n;           // template object

public:
    beta(T t, int i) : q(t), n(i) {}

    template<typename U>   // template method
    U blab(U u, T t);
    /*{
        return (n.Value() + q.Value()) * u / t;
    }*/

    void Show() const
    {
        q.show(); n.show();
    }
};

int main()
{
    beta<double> guy(3.5, 3);

    cout << " beta<double> guy(3.5, 3);" << endl;
    cout << "T was set to double\n\n";

    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n\n";

    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n\n";

    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n\n";
    cout << "Done\n";
    // std::cin.get();
    return 0;
}

template <typename T>
template<typename V>
class beta<T>::hold//дȫ��������������������
{
private:
    V val;
public:
    hold(V v = 0) : val(v)
    {}
    void show() const
    {
        cout << val << endl;
    }
    V Value() const
    {
        return val;
    }
};

template <typename T>
template <typename U>
U beta<T>::blab(U u, T t)
{
    return (n.Value() + q.Value()) * u / t;
}
#endif


//�����嵥14.21 ʹ����ģ�壬ʹ��ģ����Ϊ���Ͳ���
//������
#if 0
#include "cxqd14.21.h"

template <template <typename T> class Thing>//***ע***
class Crab                                                  //�˴���Thing��ͨ������˵����
{                                                                  //�˴���������һ��ģ����
private:
    Thing<int> s1;
    Thing<double> s2;

public:
    Crab() {};

    // assumes the thing class has push() and pop() members
    bool push(int a, double x)
    {
        return s1.push(a) && s2.push(x);
    }
    bool pop(int& a, double& x)
    {
        return s1.pop(a) && s2.pop(x);
    }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Crab<Stack> nebula;
    // Stack must match template <typename T> class thing   
    //Stack �滻�� Thing

    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;

    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥14.22 ģ����ķ�ģ����Ԫ����
//������
#if 0
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;

public:
    HasFriend(const T& i) : item(i)
    {
        ct++;
    }
    ~HasFriend()
    {
        ct--;
    }
    friend void counts();//��Ϊģ������ʵ��������Ԫ
    friend void reports(HasFriend<T>&); // template parameter
    //***ע***
    //����д��friend void report (HasFriend& );
    //��Ҫ�ṩģ�������������ָ�����廯
};

//ÿ�����廯�����Լ��ľ�̬��Ա
// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
void reports(HasFriend<int>& hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double>& hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();

    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.23 ģ�����Լ��ģ����Ԫ����
//������
#if 0
using std::cout;
using std::endl;

//��һ������������ǰ����ÿ��ģ�庯��
// template prototypes
template <typename T> void counts();
template <typename T> void report(T&);

// template class
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT& i) : item(i) { ct++; }
    ~HasFriendT() { ct--; }

    //�ڶ����������������ٴν�����ģ������Ϊ��Ԫ
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT>&);//ģ����廯
};

template <typename T>
int HasFriendT<T>::ct = 0;

//��������Ϊ��Ԫдģ�庯���Ķ���
// template friend functions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T& hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();

    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    report(hfi1);  // generate report(HasFriendT<int> &)
    report(hfi2);  // generate report(HasFriendT<int> &)
    report(hfdb);  // generate report(HasFriendT<double> &)

    cout << "counts<int>() output:\n";//ÿ��T���Ͷ����Լ�����Ԫ����count()
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
    // std::cin.get();
    return 0;
}
#endif


//�����嵥14.24 ģ����ķ�Լ��ģ����Ԫ����
//������
#if 0
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
    T item;

public:
    ManyFriend(const T& i) : item(i)
    {}
    template <typename C, typename D> friend void show2(C&, D&);
};

template <typename C, typename D> void show2(C& c, D& d)
{
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);
    // std::cin.get();
    return 0;
}
#endif


//chapter 14
//code2.cpp
//14.6 ��ϰ��
//4.
#if 0
//��Ŀ�����ɵ�������
//��������
class Stack  <Worker*>
{
private:
    enum { MAX = 10 };  // constant specific to class ��ʾ����
    Worker* items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Worker*& item); // add item to stack
    bool pop(Worker*& item);        // pop top into item
};
#endif


//5.
//������
#if 0
#include <string>
#include <valarray>
#include "14.6.5.h"

int main()
{
    std::valarray<std::string>s_shuzu;

    //�����������ɵ���ָ��ջ
    /*double a[20] = {};
    Stack<double *>s1;*/
    //������
    //cxqd14.17.h����ArrayTP��ģ��
    //Stack< ArrayTP<double,100> >  stack;

    //Worker* p_w = Worker w1;//�������������������Ķ���
    Worker* p_w;//��ʱδ����Worker�����P473
    Stack<Worker*>s2[20];

    //��
    //ArrayTP<Stack<Worker*>, 100>arr_stk;

    return 0;
}
#endif


//chapter 14
//code3.cpp
//14.7 �����ϰ
//1.
//����14.7.1.cpp
#if 0
#include "14.7.1.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "Enter number of years:";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);// store label,years,give arrays yrs elements
    holding.GetBottles();// solicit input for year,bottle count
    holding.Show(); // display object contents

    const int YRS = 3;
    int y[YRS] = { 1993,1995,1998 };
    int b[YRS] = { 48,60,72 };

    // create new object,initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for" << more.Label()// use Label()method
        << ": " << more.sum() << endl; // use sum () method
    cout << "Bye\n";
    return 0;
}
#endif


//2.
//����14.7.2.cpp
#if 0
#include "14.7.2.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "Enter number of years:";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);// store label,years,give arrays yrs elements
    holding.GetBottles();// solicit input for year,bottle count
    holding.Show(); // display object contents

    const int YRS = 3;
    int y[YRS] = { 1993,1995,1998 };
    int b[YRS] = { 48,60,72 };

    // create new object,initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for" << more.Label()// use Label()method
        << ": " << more.sum() << endl; // use sum () method
    cout << "Bye\n";
    return 0;
}
#endif


//3.
//����14.7.3.cpp
#if 0
#include <cstring>
#include "14.7.3.h"
const int SIZE = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    //***ע***ԭ���ķ�������ָ�������ָ��Worker��ָ�룬
    //���ڽ�������һ��ָ�룬����ָ���������
    Worker* lolas = (Worker*)0x00;
    QueueTp<Worker*>lolas_stack;//ģ����ʽʵ����P464

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {

        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";

        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':  lolas = new Waiter;//***ע***��Ȼlolas�ĵ�ַ���䣬����ÿ��ѭ���д�ĵ�ַ����ı�
            break;
        case 's':   lolas = new Singer;
            break;
        case 't':   lolas = new SingingWaiter;
            break;
        }

        cin.get();
        lolas->Set();
        lolas_stack.enqueue(lolas);
    }


    Worker* lolas_1 = (Worker*)0x01;
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas_stack.dequeue((lolas_1));
        lolas_1->Show();
    }

    //for (i = 0; i < ct; i++)
    //	delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//4.
//����14.7.4.cpp
#if 0
#include <cstring>
#include "14.7.4.h"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "g: Gunslinger  p: PokerPlayer  "
            << "b: BadDude q: quit\n";

        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'g':   lolas[ct] = new Gunslinger;
            break;
        case 'p':   lolas[ct] = new PokerPlayer;
            break;
        case 'b':   lolas[ct] = new BadDude;
            break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//5.
//����14.7.5.cpp
#if 0
using namespace std;
#include "14.7.5.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;//***ע***����������û���ض���<<��������غ��������Ĭ��ʹ�û����<<��������غ���
    em.ShowAll();
    cout.put('\n');

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    cout.put('\n');

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    cout.put('\n');

    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout.put('\n');

    cout << "Press a key for next phase:\n";
    cin.get();

    highfink hf2;
    hf2.SetAll();
    cout.put('\n');

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp* tri[4] = { &em,&fi,&hf,&hf2 };

    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    /*abstr_emp tri[4] = {em,fi,hf,hf2};
    for (int i = 0; i < 4; i++)
        tri[i].ShowAll();*/

    return 0;
}
#endif


//chapter 15
//code1.cpp
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
#if 0
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
            cout << bg.what();
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
//���� High��Low�������࣬�� ph �� pl�����ͷֱ�ΪHigh* ��Low* ��
//�����Low �� High �Ŀɷ��ʻ��ֱࣨ�ӻ��ӣ�ʱ��
//��������Ž�һ��Low* ָ�븳��pl��
//pl = dynamic_cast<Low*> ph;
//���򣬸���佫��ָ�븳��pl��
//�����������;�ǣ�ʹ���ܹ������νṹ�н��С�����ת����
//������ is-a ��ϵ������������ת���ǰ�ȫ�ģ���������������ת��
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
    enum meiju { a, b, c };

    meiju y;
    int x = 1;
    y = static_cast<meiju>(x);//֧�֡�����ת����������ת����

    std::cout << y << std::endl;

    struct data
    {
        short a;
        short b;
    };

    long value = 0xA224B118;
    data* pd = reinterpret_cast<data*>(&value);

    std::cout << pd->a << std::endl;

    return 0;
}
#endif


//chapter 15
//code2.cpp
//15.7 ��ϰ��
//6.
//����15.7.6.cpp
#if 0
#endif


//chapter 15
//code3.cpp
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
            cout << bg.what();
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
        if (typeid(bad) == typeid(LabeledSales::nbad_index))
        {
            //LabeledSales::nbad_index bad1("chushihua",1);
            //bad1 = dynamic_cast<LabeledSales::nbad_index &>(bad);//ֻ������ʽ����ǿ��ת�����൱��ֻ����nbad_index��nbad_index

            //������dynamic_cast����ָ��
            LabeledSales::nbad_index* bad1 = dynamic_cast<LabeledSales::nbad_index*>(&bad);
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


//chapter 16
//code1.cpp
//�����嵥16.1 ʹ��string���7�����캯��
//������
#if 0
#include <string>
// using string constructors

int main()
{
    using namespace std;

    string one("Lottery Winner!");     // ctor #1
    cout << one << endl;               // overloaded <<

    string two(20, '$');               // ctor #2
    cout << two << endl;

    string three(one);                 // ctor #3
    cout << three << endl;

    one += " Oops!";                   // overloaded +=
    cout << one << endl;

    two = "Sorry! That was ";
    three[0] = 'P';
    string four;                       // ctor #4
    four = two + three;                // overloaded +, =
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 50);              // ctor #5 
    cout << five << "!\n";//***ע***��������C����ַ����ĳ��ȣ����Խ�����������Ŀ���ַ�
                                        //����C����ַ�����β����\0�������ᱻ���Ƶ�five
    string six(alls + 6, alls + 10);     // ctor #6  ��Ҫ�������������ֵַ
    cout << six << ", ";
    string seven(&five[6], &five[10]); // ctor #6 again
    cout << seven << "...\n";

    string eight(four, 7, 16);         // ctor #7
    cout << eight << " in motion!" << endl;
    // std::cin.get();
    return 0;
}
#endif


//�����嵥16.2 ʹ��string���뺯�����ļ��ж�ȡ���룬ʹ��ָ���ֽ����getline()����
//������
#if 0
#include <fstream>
#include <string>//getline()
#include <cstdlib>//EXIT_FAILURE

int main()
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;

    getline(fin, item, ':');
    while (fin)  // while input is good
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }

    cout << "Done\n";
    fin.close();
    // std::cin.get();
    // std::cin.get();
    return 0;
}
//***ע***
//�������л������еķ�����
//1.�ҵ��ÿ�ִ�г������ڵ��ļ�·��(�籾������ΪProject1.exe��������·��Ϊ)
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\x64\Debug
//2.��VS�Դ��Ĺ����е������й���
//����cd�Ϳո��·�������Ըı�·��
//����Project1.exe tobuy.txt

//��������ʹ�������л�����
//�ڸ�·����D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\Project1
//����tobuy.txt������Ҳ����������
//fin.open("tobuy.txt");���Ըĳ�
//fin.open("D:\\CODE\\CPP_CODE\\C++ Primer Plus Code practice\\chapter 16\\code1\\Project1\\Project1\\tobuy.txt");
//����\\��ת�����У��൱��\

#endif


//�����嵥16.3 ʹ��find()����ʵ��ƴ����Ϸ
//������
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()

const int NUM = 26;
using std::string;
const string wordlist[NUM] = { "apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy" };

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];

        int length = target.length();//��дΪtarget.size();

        string attempt(length, '-');

        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        string badchars;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos//����������ͬ����ĸ
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);//���ظ��ַ��״γ��ֵ�λ�õ�����ֵ
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //***ע***��������һ����ȷ���ַ��󣬼������target���飬����
                //�Ѻ��е����и��ַ���������attempt�������Ӧλ��
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }

        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
#endif


//�����嵥16.4 size()��capacity()��reserve()����
//C++ʵ��ͨ�������һ����ʵ���ַ�������ڴ��
//������
#if 0
#include <string>

int main()
{
    using namespace std;

    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";

    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "//������С����Ϊ50���ڴ�ռ�
        << empty.capacity() << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥16.5 ʹ������ָ��
//���ܣ���ָ�����ʱ������ָ����ڴ��ܹ��Զ��ͷ�
//������
#if 0
#include <string>
#include <memory>//����ָ��ģ����
#include "cxqd16.5.h"

int main()
{
    {   //double* p_to_d ��1.5 ���Ը�д�ɣ�

        //��ȷд����
            //double�滻��ģ��ķ�����(���Ͳ���)��new double���ص�ֵ
                                                                             //��Ϊ���캯����ʵ��
        std::auto_ptr<double>p_to_d(new double);
        *p_to_d = 1.5;
        std::cout << *p_to_d << std::endl;

        //����д����
        /*double num = 1.5;
        std::auto_ptr<double>p(&num);*/
        //ԭ��delete�������ڷǶ��ڴ�
    }
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();   // use -> to invoke a member function
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    // std::cin.get();  
    return 0;
}
#endif


//�����嵥16.6 ���ʺ�ʹ��auto_ptr�����
//�Ƚ�auto_ptr��shared_ptr��unique_ptr
//������
#if 0
#include <string>
#include <memory>

#define use_auto_ptr     0
#define use_shared_ptr  1

int main()
{
    using namespace std;
#if use_auto_ptr==1
    auto_ptr<string> films[5] =
    {
        auto_ptr<string>(new string("Fowl Balls")),
        auto_ptr<string>(new string("Duck Walks")),
        auto_ptr<string>(new string("Chicken Runs")),
        auto_ptr<string>(new string("Turkey Errors")),
        auto_ptr<string>(new string("Goose Eggs"))
    };

    //***ע***��ʹ��auto_ptr������ڳ������н׶α���
    auto_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#elif use_shared_ptr==1

    shared_ptr<string> films[5] =
    {
        shared_ptr<string>(new string("Fowl Balls")),
        shared_ptr<string>(new string("Duck Walks")),
        shared_ptr<string>(new string("Chicken Runs")),
        shared_ptr<string>(new string("Turkey Errors")),
        shared_ptr<string>(new string("Goose Eggs"))
    };

    //***ע***shared_ptr֧�ֹ�������Ȩ��������ָ���ĸ�ֵ
    shared_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    //***ע***��ʹ��unique_ptr������ڱ���׶α���
    /*unique_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership   */
    //��unique_ptr����unique_ptr���͵���ʱ��ֵ����unique_ptrָ��
    //��ʹ��move()��һ��unique_ptr������һ��(����ָ���ĸ�ֵ)

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#endif

    //���²������У�
    //�൱��shared_ptr֮��ĸ�ֵ
    /*
    shared_ptr<double> pd;
    double* p_reg = new double;
    *p_reg = 1.1;
    pd = (shared_ptr<double>)p_reg;  //����ʹ����ʽǿ������ת��

    std::cout << *pd << endl;
    */

    // cin.get();
    return 0;
}
#endif
//ʹ��move()����һ��unique_ptr������һ��
#if 0
#include <memory>
#include <string>
using std::string;
using std::unique_ptr;

unique_ptr <string> demo(const char* s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main()
{
    unique_ptr<string> ps1, ps2;
    ps1 = demo("123abc");
    ps2 = move(ps1);
    ps1 = demo("456def");
    std::cout << *ps2 << *ps1 << std::endl;

    return 0;
}
#endif


//�����嵥16.7 ���ͱ�̣�ʹ��vectorģ���࣬����vectorģ�����
//������
#if 0
#include <vector>
#include <string>

const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<string> titles(NUM);
    vector<int> ratings(NUM);

    cout << "You will do exactly as told. You will enter\n"
        << NUM << " book titles and your ratings (0-10).\n";

    int i;
    for (i = 0; i < NUM; i++)
    {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Thank you. You entered the following:\n"
        << "Rating\tBook\n";

    for (i = 0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    // cin.get();

    return 0;
}
#endif


//�����嵥16.8 ʹ�õ�����iterator 
//ʹ��STL�����ķ�����size()��begin()��end()��swap()
//����STL�������еķ�����push_back()��erase()��insert()
//����cxqd16.8.cpp
#if 0
#include <string>
#include <vector>
#include "cxqd16.8.h"

int main()
{
    using std::cout;
    using std::vector;

    vector<Review> books;//����һ��vector�����Ԫ������Ϊ
                                             //Review�ṹ����
    Review temp;//����һ��Review�ṹģ��Ľṹtemp

    while (FillReview(temp))
        books.push_back(temp);//��Ԫ����ӵ�ʸ������ĩβ

    int num = books.size();

    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
            << "Rating\tBook\n";

        //����Ԫ�ط���һ��
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);

        cout << "Reprising:\n"
            << "Rating\tBook\n";

        //ʹ���������������������������ʵ�����iterator
        //Ϊvector��Review��������һ��������pr
        vector<Review>::iterator pr;

        //����Ԫ�ط�������
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        //����Ԫ�ط�����ʹ��for_each();

        //����Ԫ�ط��ģ�ʹ�û��ڷ�Χ��forѭ��(��֧���޸�����������)

        //����������������������ܽ�

        vector <Review> oldlist(books);// copy constructor used

        if (num > 3)
        {
            // remove 2 items
            //***ע***
            //ɾ������ֵ1������ֵ2λ���ϵ�Ԫ�أ���
            //ɾ���ڶ����͵�����Ԫ��
            books.erase(books.begin() + 1, books.begin() + 3);

            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);

            // insert 1 item
            //�ڵ�һ��Ԫ��ǰ�����oldlist�ĵڶ���Ԫ��
            books.insert(books.begin(), oldlist.begin() + 1,
                oldlist.begin() + 2);

            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }

        //books��Ԫ����oldlist��Ԫ�ؽ��н���
        //***ע***ʹ�õ���vector��Ա����������STL�ṩ�ķǳ�Ա����swap()
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";

        cout << "books���������:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        cout << "oldlist���������:\n";
        for (pr = oldlist.begin(); pr != oldlist.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    // std::cin.get();
    return 0;
}
#endif


//�����嵥16.9 ʹ��STL����(�ǳ�Ա����) for_each()��sort()��random_shuffle()
//����cxqd16.9.cpp
#if 0
#include "cxqd16.9.h"
#include <vector>
#include <algorithm>//for_each()��sort()��random_shuffle()��swap()

int main()
{
    using namespace std;

    vector<Review> books;

    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        //�������滻�����嵥16.8�е�forѭ��
        for_each(books.begin(), books.end(), ShowReview);

        //��sort()�����õ�<operator()��vector�����Ԫ�ؽ�������
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //��sort()���Զ���ĺ�����vector�����Ԫ�ؽ�������
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //��random_shuffle()����������򣬼����������Ԫ��
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//ʹ�û��ڷ�Χ��forѭ�����������������ܽ�
//������
#if 0
#include <vector>
#include <algorithm>//for_each()

void show(double);
void alter(double&);

int main()
{
    using std::vector;
    using std::cout;
    using std::endl;
    //using std::iterator;  ����Ӧʹ���������ж���ĵ�����
    using std::for_each;

    vector<double> data = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    //����Ԫ�ط���һ��(ʹ������)
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << '\t';
    }
    cout.put('\n');

    //����Ԫ�ط�������(ʹ�õ�����)
    //д��һ��
    /*vector<double>::iterator p;
    for (p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }*/
    //д������
    for (auto p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }
    cout.put('\n');

    //����Ԫ�ط�������(ʹ��STL����)
    for_each(data.begin(), data.end(), show);
    cout.put('\n');

    //����Ԫ�ط����ģ�(���ڷ�Χ��forѭ��)
    //д��һ��
    /*for (double x : data)
        show(x);*/
        //д������
    for (auto x : data)
        show(x);
    cout.put('\n');

    //ʹ�ñ���Ԫ�ط������޸�Ԫ�ص�ֵ��
    for (auto& x : data)
        alter(x);
    for (auto x : data)
        show(x);
    cout.put('\n');

    //����Ԫ�ط����壺(�����ݸ��Ƶ������(ʹ��������������))
#include <iterator>
    copy(data.begin(), data.end(),
        std::ostream_iterator<double, char>(cout, "\t"));

    return 0;
}
void show(double a)
{
    std::cout << a << '\t';
}
void alter(double& num)
{
    num++;
}
#endif


//�����嵥16.10 ʹ��copy()������������������������sort()
//������
#if 0
#include <vector>
#include <iterator>//ostream_iteratorģ�壬�Ǹ������������Խ�
                                  //һЩ�����ӿ�ת��ΪSTLʹ�õĽӿ�
#include <algorithm>//sort()

int main()
{
    using namespace std;

    int casts[10] = { 6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5 };
    vector<int> dice(10);

    // create an ostream iterator
    //Ҫ����Ϣ���Ƶ���ʾ���ϣ���Ҫ��һ�����������
    //������ostream_iteratorģ�崴�����ֵ�����
    //����������ӿ�coutת��ΪSTLʹ�õĽӿ�(�����������)
    //���������ʹ�õ������ӿ�
    ostream_iterator<int, char> out_iter(cout, " ");

    //��15����ָ��ָ���λ�ã�Ȼ��ָ���1
    *(out_iter++) = 15;
    cout.put('\n');

    // copy from array to vector
                                        //***ע***���һ������ӦΪ���������
    cout << "��casts�����ݸ��Ƶ�dice\n";
    copy(casts, casts + 10, dice.begin());
    cout << "��ɣ�\n";

    // copy from vector to output
    //��dice�������������临�Ƶ�������У�����ʾ����������
    //д��һ��
    //copy(dice.begin(), dice.end(), out_iter);
    //д�����������������ĵ���������ֱ�ӹ���һ������������
    cout << "����ʾ������ʾdice������\n";
    copy(dice.begin(), dice.end(),
        ostream_iterator<int, char>(cout, " "));
    cout << endl;

    cout << "Implicit use of reverse iterator.\n";
    //ʵ��һ��ָ��β�ķ����������ʵ�ζ���ָ���һ��Ԫ�صķ��������
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    // vector<int>::reverse_iterator ri;  // use if auto doesn't work
    for (auto ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

    //ʹ��STL����sort
    sort(dice.begin(), dice.end());
    copy(dice.begin(), dice.end(),
        std::ostream_iterator<int, char>(cout, " "));

    cout << endl;
    // cin.get();
    return 0;
}
#endif


//�����嵥16.11 ʹ�����ֲ��������
//������
#if 0
#include <string>
#include <iterator>//back_insert_iterator��insert_iterator
#include <vector>
#include <algorithm>//copy()

void output(const std::string& s)
{
    std::cout << s << " ";
}

int main()
{
    using namespace std;

    string s1[4] = { "fine", "fish", "fashion", "fate" };
    string s2[2] = { "busy", "bats" };
    string s3[2] = { "silly", "singers" };

    //����һ��vector���飬�京4��Ԫ�أ�ÿ��Ԫ�����;�Ϊstring
    vector<string> words(4);

    //***ע***s1 + 4�ǳ�β����������ʶ��β��λ��
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous back_insert_iterator object
    //����������back_insert_iterator������
    copy(s2, s2 + 2,
        back_insert_iterator<vector<string> >(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous insert_iterator object
    //����������insert_iterator������
    copy(s3, s3 + 2,
        insert_iterator<vector<string> >(words, words.begin()));
    copy(words.begin(), words.end(),
        std::ostream_iterator<string, char>(cout, " "));//ʹ�õ��������
    cout << endl;           //***ע***
                                      //���͸���������������ͣ�string
    // cin.get();               //�����ʹ�õ��ַ����ͣ�char
    return 0;
}
#endif


//�����嵥16.12 ʹ��list��insert()��remove()��splice()��
//unique()��sort()��merge()����
//������
#if 0
#include <iterator>
#include <list>//��Ա����insert()��
#include <algorithm>//STL����(�ǳ�Ա����)��for_each()

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using namespace std;

    //����һ����5��int���͵�ֵ2��ɵ�����
    list<int> one(5, 2); // list of 5 2s

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //����һ��������
    list<int> two;

    //������stuff��������ݲ��뵽two����Ԫ��ǰ
    int stuff[5] = { 1,2,4,8, 6 };
    //��һ��(ʹ��insert()��Ա����)
    two.insert(two.begin(), stuff, stuff + 5);
    //������(ʹ��insert_iterator���������)
    /*copy(stuff,stuff+5,
        insert_iterator<list<int>>(two,two.end()));*/

    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);

    //���ø��ƹ��캯���������͸���
    list<int> three(two);

    int more[6] = { 6, 4, 2, 4, 6, 5 };
    three.insert(three.end(), more, more + 6);

    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);

    //��˫��������ɾ��ֵΪ2������ʵ��
    three.remove(2);
    cout << endl << "List three (ɾ����ֵΪ2��ʵ��): ";
    for_each(three.begin(), three.end(), outint);

    //������one�����ݲ��뵽threeͷ����ǰ��
    //***ע***one�����
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //����������ͬԪ��ѹ��Ϊ����Ԫ��
    three.unique();
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    //����(Ĭ�ϵ���)
    three.sort();
    //***ע***
    //����ʹ��STL����sort()��
    //��Ϊ�ǳ�Ա����sort()��Ҫ������ʵ�������
    //��list��֧���������
    //sort(three.begin(),three.end());

    //�ϲ�ͬ����
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    //����(Ĭ�ϵ���)
    two.sort();
    //����������ϲ�
    //***ע***ǰ�᣺������������Ѿ�����
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);

    cout << endl;
    // cin.get();

    return 0;
}
#endif


//�����嵥16.13 ʹ�ù�������set
//ʹ��insert()��set_union()��set_intersection()��set_difference()��
//lower_bound()��upper_bound()
//������
#if 0
#include <string>
#include <set>//��������set
#include <algorithm>//set_union()��set_intersection()��set_difference()
#include <iterator>

int main()
{
    using namespace std;

    const int N = 6;
    string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
    string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    //���������ʹ�õ������ӿ�
    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";

    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
        insert_iterator<set<string> >(C, C.begin()));//ʹ�ò��������

    //***ע***����д����
    //set_union(A.begin(), A.end(), B.begin(), B.end(), C.begin());
    //���һ����������д��C.begin()��
    //��Ϊ���ڹ������ϣ�
    //��������������C.begin()���ص��ǵ������ǳ���������
    //���������������
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
    // cin.get();
    return 0;
}
//lower_bound() �����������������д��ڵ��ڣ� >= ��ָ��Ԫ�صĵ�һ��Ԫ�ء�
//upper_bound()�����������������д��ڣ� > ��ָ��Ԫ�صĵ�һ��Ԫ�ء�
#endif


//�����嵥16.14 ʹ�ù�������multimap
//ʹ�÷���insert()��count()��equal_range()
//������
#if 0
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
//��������          �洢��ֵ����
typedef std::pair<const KeyType, std::string> Pair;
//multimap��ֵ������Ͳ�ͬ��һ������������ֵ�����
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;

    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Brooklyn"));
    //codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: "
        << codes.count(415) << endl;
    cout << "Number of cities with area code 718: "
        << codes.count(718) << endl;
    cout << "Number of cities with area code 510: "
        << codes.count(510) << endl;

    cout << "Area Code   City\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "    " << (*it).first << "     "
        << (*it).second << endl;

    //pair<MapCode::iterator, MapCode::iterator>
    auto range
        = codes.equal_range(718);

    cout << "Cities with area code 718:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;

    // cin.get();
    return 0;
}
#endif
//map�У�ֵ�������һ����ͬ��
#if 0
#include <map>

using namespace std;

int main()
{
    multimap<int, int > m;

    m.insert(pair<int, int>(2, 5));
    m.insert(pair<int,int>(1,2));
    m.insert(pair<int, int>(1, 3));

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout.put('\n');

    auto range = m.equal_range(1);

    //ʹ�������Ƶ�lambda����
    auto print = [](const char* string,
        const pair<multimap<int, int>::iterator,
        multimap<int, int>::iterator >& pa)
    {
        cout << string << endl;

        for (auto r1 = pa.first; r1 != pa.second; r1++)
            cout << r1->first << " " << r1->second << endl;
    };

    print("��ӡ��Ϊ1��Ӧ��ֵ",range);

    return 0;
}
//˵��map�У�ֵ��������Ϳ�����ͬ
#endif


//�����嵥16.15 ʹ�ú�������ʹ�÷���remove_if()
//������
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

#include <functional>

//��������(������)
//������()�������������������ʹ�ú�������ʹ�������
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T& t) : cutoff(t)
    {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::cout;
    using std::endl;

    using std::list;
    using std::for_each;
    using std::remove_if;

    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(vals, vals + 10);

    //  C++0x can use the following instead
    //  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    //  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    //remove_if()��Ա��ν��(������boolֵ��һԪ����)��Ϊ����
    //�������ж�����()��������غ��������Կ��԰Ѵ������
    //���ɺ�����(��ָ������ָ��)����
    TooBig<int> f100(100); // limit = 100
    yadayada.remove_if(f100);               // use a named function object

    //д��һ��
                                //���������������
    //etcetera.remove_if(TooBig<int>(200));   // construct a function object

    //д������
    etcetera.remove_if(std::bind2nd(std::greater<int>(), 200));

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    // std::cin.get();
    return 0;
}
#endif


//�����嵥16.16 ʹ�ú���������
//������
#if 0
#include <vector>
#include <iterator>
#include <algorithm> //for_each()��transform()
#include <functional> //bind1st()

void Show(double);
const int LIM = 6;

int main()
{
    using namespace std;

    double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
    double arr2[LIM] = { 63, 65, 69, 75, 80, 99 };

    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);

    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;

    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);

    //plus<double>()����һ����������ͬʱ�����Ϊ��������
    //�Ǹ���Ԫ������������������
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(),
        plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);

    //multiplies<double>()����һ����������ͬʱ�����Ϊ��������
    //�Ǹ���Ԫ������������������
    //ͨ��ʹ�ú���������bind1st()��
    //�Ѷ�Ԫ�������������Ϊһ��һԪ��������
    //������������һ������������һ�������̶�
    transform(gr8.begin(), gr8.end(), prod.begin(),
        bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);

    cout << endl;
    // cin.get();
    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}
#endif


//�����嵥16.17 string��ʹ��STL�ӿ�
//������
#if 0
#include <string>
#include <algorithm> //sort()��next_permutation()

int main()
{
    using namespace std;
    string letters;

    cout << "Enter the letter grouping (quit to quit): ";

    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;

        //next_permutation()�����������ת��Ϊ��һ������ʽ
        //***ע***�����ȶ����ݽ�������
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;

        cout << "Enter next sequence (quit to quit): ";
    }

    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//�����嵥16.18 �Ա�STL����(��Ա����)��STL����(�ǳ�Ա����)��remove()
//������
#if 0
#include <list>
#include <algorithm>

void Show(int);
const int LIM = 10;

int main()
{
    using namespace std;

    int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };

    list<int> la(ar, ar + LIM);
    list<int> lb(la);

    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    la.remove(4);
    cout << "After using the remove() method:\n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;

    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);

    cout << endl;
    // cin.get();    
    return 0;
}

void Show(int v)
{
    std::cout << v << ' ';
}
#endif


//�����嵥16.19 ʹ��STLʵ��ͳ�Ƶ��ʳ��ִ����ĳ���
//������
#if 0
#include <vector>
#include <string>
#include <set>//��������set
#include <map>//��������map
#include <iterator>
#include <algorithm> //transform
#include <cctype> //tolower()

using namespace std;

char toLower(char ch)
{
    return tolower(ch);
}

string& ToLower(string& st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string& s);

int main()
{
    //������ĵ�����ӵ�ʸ����
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);

    //������˳����ʾ����
    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    //����ĸ˳����ʾ����
    //��������set�Զ������ݽ�������
    // place words in set, converting to lowercase
    set<string> wordset;
    //����ToLower()��stringԪ�ض�����ΪСд�ַ���
    //Ȼ��transform()��ÿ��stringԪ�ؽ���ToLower()����
    //���뵽set�л��Զ�����
    transform(words.begin(), words.end(),
        insert_iterator<set<string> >(wordset, wordset.begin()),
        ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    //��¼ÿ�����ʱ�����Ĵ���
    // place word and frequency in map
    //map��ֵ������Ͳ�ͬ����Ψһ��ÿ������Ӧһ��ֵ
    map<string, int> wordmap;
    set<string>::iterator si;//Ϊset��string��������һ��������si

    for (si = wordset.begin(); si != wordset.end(); si++)
        //д��һ��  
 /*       wordmap.insert(
            pair<string, int>
            (
                *si, count(words.begin(), words.end(), *si)
             )
                                  );                                              
 */
    //д������(�����������ʾ��(������������ֵ)���洢����ֵ)
    wordmap[*si] = count(words.begin(), words.end(), *si);

   // display map contents
    cout << "\nWord frequency:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        //�����������ʾ��(������������ֵ)�����ʴ洢��ֵ
        cout << *si << ": " << wordmap[*si] << endl;

    // cin.get();
    // cin.get();
    return 0;
}

void display(const string& s)
{
    cout << s << " ";
}
#endif


//�����嵥16.20 �Ƚ�vector��valarray���Ե�����
//������
#if 0
#include <vector>//vector֧�����������Ĳ���
#include <valarray>//valarray������ֵ����
#include <algorithm>

int main()
{
    using namespace std;

    vector<double> data;
    double temp;

    cout << "Enter numbers (<=0 to quit):\n";
    while (cin >> temp && temp > 0)
        data.push_back(temp);

    sort(data.begin(), data.end());
    int size = data.size();

    valarray<double> numbers(size);
    int i;
    //д��һ��
    //for (i = 0; i < size; i++)
    //    numbers[i] = data[i];
    //д���������������������²����У������ǳ���&numbers[size]ʱ
    //copy(data.begin(),data.end(),&numbers[0]);
    //д������C++11�ṩ��begin()��������������STL�ӿ�����
    copy(data.begin(), data.end(), begin(numbers));

    //valarray����������ѧ����������һ��valarray����������һ��valarray����
    //Ҳ����ʹ��apply()��������֧�ַ����غ�����Ϊ����
    valarray<double> sq_rts(size);
    //д��һ��
    //sq_rts = sqrt(numbers);
    //д������
    sq_rts = numbers.apply(sqrt);

    //valarray���������������������
    valarray<double> results(size);
    results = numbers + 2.0 * sq_rts;

    cout.setf(ios_base::fixed);
    cout.precision(4);

    for (i = 0; i < size; i++)
    {
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.width(8);
        cout << results[i] << endl;
    }
    cout << "done\n";
    // cin.get();
    // cin.get();

    return 0;
}
#endif


//�����嵥16.21 valarray����������
//��һά�����ʾ��ά�������������
//������
#if 0
#include <valarray>
#include <cstdlib>

typedef std::valarray<int> vint;     // simplify declarations
const int SIZE = 12;
void show(const vint& v, int cols);

int main()
{
    using std::slice;                // from <valarray>
    using std::cout;
    vint valint(SIZE);               // think of as 4 rows of 3

    int i;
    for (i = 0; i < SIZE; ++i)
        valint[i] = std::rand() % 10;

    cout << "Original array:\n";
    show(valint, 3);                 // show in 3 columns

    //��vcol����valint����1��4��7��10��Ӧ������
    vint vcol(valint[slice(1, 4, 3)]); // extract 2nd column
    cout << "Second column:\n";
    show(vcol, 1);                   // show in 1 column

    //��vrow����valint����3��4��5��Ӧ������
    vint vrow(valint[slice(3, 3, 1)]); // extract 2nd row
    cout << "Second row:\n";
    show(vrow, 3);

    //valint������2��5��8��11��Ӧ�����ݸ�Ϊ10
    valint[slice(2, 4, 3)] = 10;      // assign to 2nd column
    cout << "Set last column to 10:\n";
    show(valint, 3);

    cout << "Set first column to sum of next two:\n";
    // + not defined for slices, so convert to valarray<int>
    //valarray�����+��������غ���
    valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)])
        + vint(valint[slice(2, 4, 3)]);
    show(valint, 3);

    // std::cin.get();
    return 0;
}

void show(const vint& v, int cols)
{
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];

        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }
    if (lim % cols != 0)
        cout << endl;
}
#endif


//�����嵥16.22 ʹ��ģ��initializer_list
//������
#if 0
#include <initializer_list>

//��ֵ����initializer_list����
double sum(std::initializer_list<double> il);
//�����ô���initializer_list����
double average(const std::initializer_list<double>& ril);

int main()
{
    using std::cout;

    cout << "List 1: sum = " << sum({ 2,3,4 })
        << ", ave = " << average({ 2,3,4 }) << '\n';

    std::initializer_list<double> dl = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "List 2: sum = " << sum(dl)
        << ", ave = " << average(dl) << '\n';

    dl = { 16.0, 25.0, 36.0, 40.0, 64.0 };
    cout << "List 3: sum = " << sum(dl)
        << ", ave = " << average(dl) << '\n';
    // std::cin.get();
    return 0;
}

double sum(std::initializer_list<double> il)
{
    double tot = 0;

    std::initializer_list<double>::iterator p;
    for (p = il.begin(); p != il.end(); p++)
        tot += *p;
    return tot;
}

double average(const std::initializer_list<double>& ril)
{
    double tot = 0;
    int n = ril.size();
    double ave = 0.0;

    if (n > 0)
    {
        for (auto p = ril.begin(); p != ril.end(); p++)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}
//�ṩ initializer_list��ĳ���ּ��
//�����ܹ���һϵ��ֵ���ݸ����캯��������������
//����˵��vector����н���initializer_list��Ϊ�����Ĺ��캯��
//��˲ſ�����ôд��vector<int> v {1,2,3};
#endif


//chapter 16
//code2.cpp
//16.9 ��ϰ��
//1.
//������
#if 0
#include "16.9.1.h"

int main()
{
    RQ1 st1;
    st1.show();

    RQ1 st2("abc");
    st2.show();

    RQ1 st3(st2);
    st3.show();

    RQ1 st4;
    st4 = st3;
    st4.show();

    return 0;
}
#endif


//3.
//������
#if 0
#include <string>
#include <cctype>
void alter(std::string&);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string st;

    cin >> st;
    alter(st);

    cout << st;

    return 0;
}
void alter(std::string& s)
{
    for (auto p = s.begin(); p != s.end(); p++)
    {
        if (islower(*p))
            *p = toupper(*p);
    }
}
#endif


//10.
//����16.9.10.cpp
#if 0
#include "16.9.10.h"
#include <list>
#include <algorithm>//for_each()��sort()��random_shuffle()��swap()

int main()
{
    using namespace std;

    list<Review> books;

    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        //�������滻�����嵥16.8�е�forѭ��
        for_each(books.begin(), books.end(), ShowReview);

        //***ע***
        //����ʹ��STL�ķǳ�Աsort()
        //�޸�һ��
        books.sort();
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //�޸Ķ���
        books.sort(worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //��random_shuffle()����������򣬼����������Ԫ��
        //random_shuffle(books.begin(), books.end());

        //cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";

    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//11.
//������
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

//��������(������)
//������()�������������������ʹ�ú�������ʹ�������
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T& t) : cutoff(t)
    {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::cout;
    using std::endl;

    using std::list;
    using std::for_each;
    using std::remove_if;

    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(vals, vals + 10);

    //  C++0x can use the following instead
    //  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    //  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    //remove_if()��Ա��ν��(������boolֵ��һԪ����)��Ϊ����
    //�������ж�����()��������غ��������Կ��԰Ѵ������
    //���ɺ�����(��ָ������ָ��)����
    TooBig<int> f100(100); // limit = 100
    yadayada.remove_if(f100);               // use a named function object

                                //���������������
    etcetera.remove_if(TooBig<int>(200));   // construct a function object

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    bool bo = TooBig<int>(10)(9);
    cout << bo << endl;
    // std::cin.get();
    return 0;
}
#endif


//chapter 16
//code3.cpp
//16.10 �����ϰ
//1.
//������
#if 0
#include <string>
bool huiwen(std::string& st);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;

    cout << "�������ַ�����";
    string st;
    cin >> st;
    bool bo = huiwen(st);

    if (bo)
        cout << "�ǻ���\n";
    else
        cout << "���ǻ���\n";

    return 0;
}
bool huiwen(std::string& st)
{
    int length = st.size();//����3��������0��1��2  ����ֻҪ0������5������ֻҪ0��1������7������ֻҪ0��1��2
    int local = 0;				   //����4������ֻҪ0��1������6������ֻҪ0��1��2������8������ֻҪ0��1��2��3

    //����Ҫ����ż
    //if(length%2)//������
    for (int i = 0; i < int(length / 2); i++)
    {
        int j = length - i - 1;
        if (st[i] == st[j])
            continue;
        else
            return false;
    }
    //else//ż����
    //	for (int i = 0; i < int(length / 2); i++)
    //	{
    //		int j = length - i - 1;

    //	}

    return true;
}
#endif
//***ע***
//algorithmͷ�ļ���ʵ�õĺ�����
//min()��max()��abs()
//find()��upper_bound()��lower_bound()
//count()��for_each() 
//__gcd()
//fill()��copy()��transform()
//swap()��reverse()��sort() 
//set_intersection()��set_union()��set_difference() 
//next_permutation()

//������ʹ��algorithm�е�reverse()
//������
#if 0
#include <algorithm>
#include <string>
bool huiwen(std::string& st);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;

    cout << "�������ַ�����";
    string st;
    cin >> st;
    bool bo = huiwen(st);

    if (bo)
        cout << "�ǻ���\n";
    else
        cout << "���ǻ���\n";

    return 0;
}
bool huiwen(std::string& st)
{
    std::string temp(st);

    reverse(temp.begin(), temp.end());

    /*  if (temp == st)
          return true;
      else
          return false;*/

    return (temp == st);
}
#endif


//2.
//������
#if 0
#include <cctype>
#include <algorithm>
#include <iterator>

bool huiwen(std::string& st);

char ToLower(char a)
{
    return tolower(a);
}

using std::string;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    //����erase()�Ĺ���
    /*
    string st = "abcdefghijklmn";
    string::iterator si=st.begin();
    //st.erase(3,1);
    //��д�ɣ�
    st.erase(si+3, si+4);
    */

    string st;
    cin >> st;

    //����Ϊ����ĸ����
    for (int index = 0; index < st.size(); index++)
    {
        if (!isalpha(st[index]))
        {
            st.erase(index, 1);
            --index;//***ע***��ûд����䣬�����������ķ���ĸ���ַ�ʱ������һ��δɾȥ��������,,,�������,
        }
    }
    cout << st << endl;

    string st1;
    //transform(st.begin(), st.end(),st1.begin(),ToLower); //��������������ʹ�ò��������
    transform(st.begin(), st.end(), std::back_insert_iterator<string>(st1), ToLower);

    cout << st1 << endl;

    bool bo = huiwen(st1);

    if (bo)
        cout << "�ǻ���\n";
    else
        cout << "���ǻ���\n";

    return 0;
}
#if 0
bool huiwen(std::string& st)
{
    int length = st.size();//����3��������0��1��2  ����ֻҪ0������5������ֻҪ0��1������7������ֻҪ0��1��2
    int local = 0;				   //����4������ֻҪ0��1������6������ֻҪ0��1��2������8������ֻҪ0��1��2��3

    for (int i = 0; i < int(length / 2); i++)
    {
        int j = length - i - 1;
        if (st[i] == st[j])
            continue;
        else
            return false;
    }

    return true;
}
#endif
//���������Է���ĸ�����ݣ�����ͷβָ�룬
//ͷβָ�����м�ƽ�
#if 1
bool huiwen(std::string& st)
{
    std::string::iterator phead, ptail;

    phead = st.begin();
    ptail = st.end() - 1;//***ע***�˴�Ҫ��һ����������ú�����

    while (phead < ptail)
    {
        if (!isalpha(*phead))
        {
            phead++;
            continue;
        }

        if (!isalpha(*ptail))
        {
            ptail--;
            continue;
        }

        if (tolower(*phead) == tolower(*ptail))
        {
            phead++;
            ptail--;
        }
        else
            return false;
    }

    return true;
}
#endif

#endif


//3.
//������
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()
#include <vector>
#include <fstream>

//const string wordlist[NUM] = { "apiary", "beetle", "cereal",
//    "danger", "ensign", "florid", "garage", "health", "insult",
//    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
//    "plaid", "quilt", "remote", "stolid", "train", "useful",
//    "valid", "whence", "xenon", "yearn", "zippy" };

using namespace std;

int main()
{
    vector<string>source;

    ifstream fin;
    fin.open("abc.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    //����ʹ��getline
    //getline(fin, target);
    //while (fin)  // while input is good
    //{
    //    cout << target <<'\t';
    //    getline(fin, target);
    //}

    string temp;
    int NUM = 0;

    fin >> temp;
    while (fin)
    {
        source.push_back(temp);
        NUM++;

        fin >> temp;
    }

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = source[std::rand() % NUM];

        int length = target.length();//��дΪtarget.size();

        string attempt(length, '-');

        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        string badchars;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos//����������ͬ����ĸ
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);//���ظ��ַ��״γ��ֵ�λ�õ�����ֵ
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //***ע***��������һ����ȷ���ַ��󣬼������target���飬����
                //�Ѻ��е����и��ַ���������attempt�������Ӧλ��
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }

        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
#endif


//4.
//������
#if 0
#include <list>

int reduce(long ar[], int n);

int main()
{
    long ar[] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int len = sizeof ar / sizeof(long);

    int num = reduce(ar, len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//nֵΪ15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    for (int index = 0; index < num; index++)
    {
        result[index] = l1.front();
        l1.pop_front();
    }


    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
#endif
//����������
//������
#if 0
#include <list>
#include <algorithm>

int reduce(long ar[], int n);
long mycopy(long a);

int main()
{
    long ar[] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int len = sizeof ar / sizeof(long);

    int num = reduce(ar, len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//nֵΪ15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    /*for (int index = 0; index < num; index++)
    {
        result[index] = l1.front();
        l1.pop_front();
    }*/

    //������
    //copy(l1.begin(),l1.end(),result);
    //������
    transform(l1.begin(), l1.end(), result, mycopy);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
long mycopy(long a)
{
    long result = a;
    return result;
}
#endif


//5.
//������
#if 0
#include <list>
#include <algorithm>
//#include <vector>

template <class T>
int reduce(T* ar, int n);

int main()
{
    long ar[15] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int num = reduce(ar, 15);
    std::cout << num << std::endl;

    std::string s1[4] = { "abc","ghj","cdf","bef" };
    num = reduce(s1, 4);
    std::cout << num;

    return 0;
}
template <class T>
int reduce(T* ar, int n)
{
    std::list<T> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    T* result = new T[num];

    copy(l1.begin(), l1.end(), result);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index] << ' ';
    }
    std::cout.put('\n');

    return num;
}
#endif


//6.
//����16.10.6.cpp
#if 0
#include "16.10.6.h"
#include <queue>
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
    using std::queue;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item>line;                 //���������ù��캯����ʼ��
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
            if (line.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.push(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.empty())//�����п������нڵ�ʱ
        {
            temp = line.front();     //�ŵ�һ���Ĺ˿��ڶ����б��ų����俪ʼ���н���
            line.pop();
            wait_time = temp.ptime(); //wait_time�����н���������ʱ��

            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
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


//7.
//������
#if 0
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<int> lotto(int num_of_dot, int num_of_choose);

int main()
{
    vector<int> winners;
    winners = lotto(51, 6);

    cout << "\n��Ʊ�н����֣�\n";
    for (auto p = winners.begin(); p < winners.end(); p++)
    {
        cout << *p << '\t';
    }

    return 0;
}
vector<int> lotto(int num_of_dot, int num_of_choose)
{
    vector<int> data(num_of_dot);
    for (int i = 1; i <= num_of_dot; i++)
    {
        data[i - 1] = i;
    }

    cout << "���֣�";
    vector<int>::iterator p;
    for (p = data.begin(); p < data.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    srand(time(0));//***ע***�˴������������ܹ�random_shuffle����ʹ��
    random_shuffle(data.begin(), data.end());

    vector<int> win(num_of_choose);
    for (int index = 0; index < num_of_choose; index++)
    {
        win[index] = data[index];
    }

    return win;
}
#endif
//�����ʵ�ȡ����
//for (int i = 0; i < sdot; i++)
//{
//
//    for (int j = 0; j < dot; j++)
//        temp.push_back(rand()%dot);
//
//    random_shuffle(temp.begin(),temp.end());
//
//    result.push_back(*temp.begin());
//}


//8.
//������
#if 0
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool FillData(set<string>&);
int main()
{
    set<string>data_Mat;

    cout << "������������\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_Pat;

    cout << "������������\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_M_and_P;
    //��һ��ʹ����Լ��ϲ����ĺ���
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

    //������
    //***ע***���������������λ��
    copy(data_Mat.begin(), data_Mat.end(),
        insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));
    copy(data_Pat.begin(), data_Pat.end(),
        insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

    //������
    //data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
    //data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

    //����д����(ԭ����P569)
    //copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

    //����д��������ʹ��back_insert_iterator
    /*copy(data_Mat.begin(), data_Mat.end(),
        back_insert_iterator<set<string> >(data_M_and_P));*/

    cout << "���˵������У�\n";
    for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    return 0;
}
bool FillData(set<string>& data)
{
    bool status = 1;

    string temp;

    getline(cin, temp);
    while (cin && temp != "")
    {
        data.insert(temp);
        getline(cin, temp);
    }

    if (cin)
        cin.clear();

    if (data.size() == 0)
        status = 0;

    return status;
}
//***ע***
//�˴�string�������ʱ��ָ���ַ�����ָ���
//�ַ������ݾ��ᱻ����
//�� set<string>data_Mat
//data.insert(temp);
//data_Mat��set�����е�string�����Ѿ���
//temp���ݿ�����
#endif


//9.
//������
#if 0
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void show(int);
int main()
{
    vector<int>vi0;

    srand((int)time(0));
    for (int i = 0; i < 100000; i++)
        vi0.push_back(rand());

#if 0
    for_each(vi0.begin(), vi0.end(), show);
    cout << endl;
#endif

    vector<int>vi(vi0);
    list<int>li(vi0.size());
    copy(vi0.begin(), vi0.end(), li.begin());

    cout << "STL��sort()�������õ�ʱ�䣺\n";
    //����������������������ʱ��
    clock_t start = clock();//(�Ժ���Ϊ��λ)
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    cout << "list��sort()�������õ�ʱ�䣺\n";
    //����������������������ʱ��
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    cout << "�������ݸ��Ƶ����飬�ٶ�vi���������ٽ�������Ƶ�li\
�����ʱ�䣺\n";
    copy(vi0.begin(), vi0.end(), li.begin());

    //�����������ݸ��Ƶ����飬��vi���������ٽ�������Ƶ�li�����ʱ��
    /*
    start = clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    */

    start = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end());
    li.assign(vi.begin(), vi.end());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    //***ע***ʹ��assign()������������copy���������
    return 0;
}
void show(int num)
{
    cout << num << " ";
}
#endif


//10.
//����16.10.10.cpp
#if 0
#include "16.10.10.h"
#include <vector>
#include <algorithm>//for_each()��sort()��random_shuffle()��swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;

    //����һ��vector���飬ÿ��Ԫ�ض�������ָ�룬ָ��Review���͵�ֵ
    auto p_temp = new Review;
    vector<shared_ptr<Review>> books;
    /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//ָ����һ�������ڴ洢Review���ڴ�����
    }

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
                //����	C2664	��void(const Review*)�� :
                //�޷������� 1 �ӡ�std::shared_ptr<Review>��ת��Ϊ��const Review * ��
                //��������ָ�����Ͳ����Զ�ת������ָͨ������
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case '2':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(*books_kaobei.begin(), *books_kaobei.end());

            }
            default:
                cout << "�����������������룡" << endl;
                break;
            }//�������滻�����嵥16.8�е�forѭ��

            ////��sort()�����õ�<operator()��vector�����Ԫ�ؽ�������
            //sort(books.begin(), books.end());
            //cout << "Sorted by title:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////��sort()���Զ���ĺ�����vector�����Ԫ�ؽ�������
            //sort(books.begin(), books.end(), worseThan);
            //cout << "Sorted by rating:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////��random_shuffle()����������򣬼����������Ԫ��
            //random_shuffle(books.begin(), books.end());
            //cout << "After shuffling:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//10.����
//����16.10.10.1cpp
#if 0
#include "16.10.10.1.h"
#include <vector>
#include <algorithm>//for_each()��sort()��random_shuffle()��swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;

    //���Ľ��ķ�����
    //��ֻ֧�����10������
    //��������ѡ�������'7'�󣬳�������
    //Expression: _CrtisvalidHeapPointer(block) ��������
#if 0
    //����һ��vectoir���飬ÿ��Ԫ�ض�������ָ�룬ָ��Review���͵�ֵ
    auto p_temp = new Review[10];
    vector<shared_ptr<Review>> books;
    /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {                                   //ʹ��ǿ������ת��
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//ָ����һ�������ڴ洢Review���ڴ�����
    }
#endif

    //�Ľ���ķ�����
#if 0
    //����һ��vectoir���飬ÿ��Ԫ�ض�������ָ�룬ָ��Review���͵�ֵ
    vector<shared_ptr<Review>> books;

    auto p_temp = new Review;
    while (FillReview(*p_temp))
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp = new Review;
    }
#endif

    //�Ľ���ķ���(����)��
#if 1
    vector<shared_ptr<Review>> books;
    Review temp;

    while (FillReview(temp))
    {                    //***ע***�˴�ʹ���˳�ʼ����̬����ı���(��P263)
        shared_ptr<Review> p(new Review(temp));

        //д������
        //shared_ptr<Review> p (new Review);
        //*p = temp;

        books.push_back(p);//��������ָ���ĸ�ֵ�������ǳ�ʼ��
    }
#endif

    if (books.size() > 0)
    {
        cout << "Thank you. You entered "
            << books.size() << " books !\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '2':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end());
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '3':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anpinjishengxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '4':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anpinjijiangxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '5':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anjiageshengxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            case '6':
            {//***ע***���������ţ��򱨴�switch���ƴ���������ʵ����
                vector<shared_ptr<Review>> books_kaobei(books);
                sort(books_kaobei.begin(), books_kaobei.end(),
                    anjiagejiangxu);
                for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
            }
            break;

            default:
                cout << "�����������������룡" << endl;
                break;
            }

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";

    return 0;
}
#endif


//chapter 17
//code1.cpp
//(void *)���ڴ�ӡ��ַ����ֵ��ʾ
//������
#if 0
using namespace std;

int main()
{
    int eggs = 12;
    const char* amount = "abc";

    cout << &eggs << endl;

    cout << amount << endl;
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
    cout.write((char*)&val, sizeof(long));
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
    cout << cout.width() << std::endl;//���ص�ǰ�ֶο��
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
    cout << f << std::endl;//ֻ��ʾ100000

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

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << num << endl;

    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << num << endl;

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
        cout.setf(ios_base::scientific, ios_base::floatfield);

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
    scanf("%d", &num);

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

    finout.open("ceshi.txt", ios_base::out);

    int loc1 = finout.tellg();
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
    finout.write((char*)&pl, sizeof pl)    /* << flush*/;

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
    cout << "��ϵͳ���������" << TMP_MAX << "�����ظ����ļ�����";
    cout << "ÿ���ļ����������" << L_tmpnam << "���ַ�" << endl;

    char Name[L_tmpnam] = { '\0' };

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


//chapter 17
//code2.cpp
//17.7 ��ϰ��
//6.
//������
#if 0
#include <iomanip>

using namespace std;

int main()
{
    cout << "������һ��������";
    int num;
    cin >> num;

    cout << left;
    cout << setw(10) << "ʮ���ƣ�" << num << endl;
    cout << setw(10) << "�˽��ƣ�" << oct << num << endl;
    cout << setw(10) << "ʮ�����ƣ�" << hex << num << endl;

    cout << showbase;
    cout << setw(15) << dec << num
        << setw(15) << oct << num
        << setw(15) << hex << num;

    return 0;
}
#endif


//7.
//������
#if 0
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout << "Enter your name : ";
    string st1;
    getline(cin, st1);

    cout << "Enter your hourly wages : ";
    double wages;
    while (!(cin >> wages))
    {
        cout << "error, please try again : ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }

    cout << "Enter number of hours worked : ";
    double work;
    while (!(cin >> work))
    {
        cout << "error, please try again : ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }

    cout << "First format : " << endl;
    cout << right << setw(30) << st1 << " : " << left <<
        setw(5) << "$"
        << fixed << setprecision(2) << wages << " : " << setw(5)
        << setprecision(1) << work << endl;
    cout << "Second format : " << endl;
    cout << left << setw(30) << st1 << " : " << "$" << setw(9)
        << fixed << setprecision(2) << wages << " : "
        << setprecision(1) << work;

    return 0;
}
//�����޸ĵĵ㣺
//��"��$"��Ϊһ���������������Ļ
#endif


//8.
//������
#if 0
int main()
{
    using namespace std;
    char ch;
    int ct1 = 0;

    cin >> ch;
    while (ch != 'q')
    {
        ct1++;
        cin >> ch;
    }

    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q')
    {
        ct2++;
        cin.get(ch);
    }

    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return 0;
}
#endif


//9.
//������
//***ע***
//ignore()�������ܲ���
#if 0
using namespace std;

int main()
{
    char ch1;
    cin >> ch1;

#if 0
    cin.ignore(5, '\n');
    char ch2;
    cin >> ch2;

    cout << ch1 << "\t" << ch2;
    //����1234567
    //�����1��7
#endif

#if 1
    cin.ignore(10, '\n');
    char ch2;
    cin.get(ch2);

    cout << ch1 << "\t" << ch2;
    //����1234567(����Enter����)��������\n
    //�����1��\n

    //���ۣ�
    //ignore()�����ȼ�⵽\n�����ȡ������\n�ַ���\n֮ǰ������
#endif

    return 0;
}
#endif


//chapter 17
//code3.cpp
//17.8 �����ϰ
//1.
//������
#if 0
using namespace std;

int main()
{
    //��һ��
    //***�ַ�������***

#if 0
    char data[50];
    cin.getline(data, 50, '$');
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        count++;
    }
    cout << count << endl;
    char ch;
    ch = cin.get();
    cout << "�������е�һ���ַ��ǣ�" << ch << endl;
    //***ע***getline()�������ֽ��$
#endif

#if 0
    char data[50];
    cin.get(data, 50, '$');
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        count++;
    }
    cout << count << endl;
    char ch;
    ch = cin.get();
    cout << "�������е�һ���ַ��ǣ�" << ch << endl;
    //***ע***get()���ֽ��$�Ա�������������
#endif

//������
//***�ַ�����***

    char data[50];
    int index = 0;
    int count = 0;
    char ch;
    cin.get(ch);
    while (ch != '\n')
    {
        data[index++] = ch;
        count++;

        if (cin.peek() == '$')
            break;

        cin.get(ch);
    }

    //д������
    /*
    while (cin.peek() != '$')
    {
        cin.get(ch);
        count++;
    }
    */

    cout << count << endl;
    char ch1;
    ch1 = cin.get();
    cout << "�������е�һ���ַ��ǣ�" << ch1 << endl;

    return 0;
}
#endif


//2.
//������
#if 0
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ofstream fout;

    if (argc > 2)
    {
        exit(EXIT_FAILURE);
    }

    //***ע***
    //����д����
    //fout.open(*argv);
    //fout.open(*argv,ios_base::out);
    //��ȷд����
    fout.open(*(argv + 1));

    if (fout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

    char ch;
    cin.get(ch);
    while (cin)
    {
        fout << ch;

        cin.get(ch);
    }

    return 0;
}
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\x64\Debug
#endif


//3.
//������
#if 0
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;

    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cerr << "error 1\n";
        exit(EXIT_FAILURE);
    }

    fout.open(argv[2]);
    if (!fout.is_open())
    {
        cerr << "error 2\n";
        exit(EXIT_FAILURE);
    }

    char ch;
    fin.get(ch);
    while (fin)
    {
        fout << ch;

        fin.get(ch);
    }

    fin.close();
    fout.close();

    cout << "Done !\n";

    return 0;
}
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\x64\Debug
//Project3.exe 17.8.3.1.txt 17.8.3.2.txt
#endif


//4.
//������
#if 0
#include <fstream>
#include <algorithm>

using namespace std;

const char* file1 = "17.8.4.1.txt";
const char* file2 = "17.8.4.2.txt";
const char* file3 = "17.8.4.3.txt";

int duan = 1;

int main()
{
    ifstream fin1, fin2;
    ofstream fout;

    fin1.open(file1);
    if (!fin1.is_open())
    {
        cerr << "error 1\n";
        exit(EXIT_FAILURE);
    }

    fin2.open(file2);
    if (!fin2.is_open())
    {
        cerr << "error 2\n";
        exit(EXIT_FAILURE);
    }

    fout.open(file3);
    if (!fout.is_open())
    {
        cerr << "error 3\n";
        exit(EXIT_FAILURE);
    }

    char temp1[80] = { '\0' };
    char temp2[80] = { '\0' };

    fin1.getline(temp1, 80);
    fin2.getline(temp2, 80);

    cout << "��" << duan++ << "��" << endl;
    cout << "fin1��" << endl;
    cout << fin1.eof() << "\t" << fin1.fail()
        << endl;

    cout << "fin2��" << endl;
    cout << fin2.eof() << "\t" << fin2.fail()
        << endl;

    while (fin1 || fin2)
    {
        if (fin1 && fin2)
        {
            //Ѱ�Ҵ˶�ĩβ��\0
            char* p = find(temp1, temp1 + 80, '\0');

            //���˶�ĩβ��\0�滻��' '
            *p = ' ';
            //��β����ӿ��ַ�
            *(p + 1) = '\0';

            //ƴ���ַ���
            strncat(temp1, temp2, 79);
            temp1[79] = '\0';

            fout << temp1 << endl;
        }
        else if (fin1)//***ע1***       
        {
            fout << temp1 << endl;

            cout << "fin1��" << endl;
            cout << fin1.eof() << "\t" << fin1.fail()
                << endl;

            cout << "fin2��" << endl;
            cout << fin2.eof() << "\t" << fin2.fail()
                << endl;
        }
        else
            fout << temp2 << endl;

        fin1.getline(temp1, 80);
        fin2.getline(temp2, 80);

        cout << "��" << duan++ << "��" << endl;
        cout << "fin1��" << endl;
        cout << fin1.eof() << "\t" << fin1.fail()
            << endl;

        cout << "fin2��" << endl;
        cout << fin2.eof() << "\t" << fin2.fail()
            << endl;
    }

    cout << "���գ�" << endl;
    cout << endl << fin1.fail() << " " << fin2.fail() << endl;
    cout << endl << fin1.bad() << " " << fin2.bad() << endl;

    return 0;
}
//***ע***
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 17\code3\Project3\Project3
//������ļ������ֱ�ӱ������У����������л���

//ע1��
//��⣺(���ԶԱȳ����嵥6.16 ��ȡ�ļ�����)
//�˴�����д��fin1.good()����Ϊ����
//���һ�к�eofbit�ͱ���1����ô�����鲻�ᱻִ��
//��fin1���൱��!fin1.fail()��

//***ע***
//�Ӽ�������ʱ����⵽ EOF ��
//cin����λ��eofbit�� failbit��������Ϊ1��
//�����ļ�����ʱ����⵽EOF��
//fin����eof()����Ϊ1

//***ϸ��***
//�ļ���Ϊ���������£�
//��fin.getline()����һ�к�
//����һ�о���EOF
//��fin.eof()Ϊ1��fin.fail()Ϊ0
//�������У�����finû�ܶ�����Ҫ�����ݣ�
//��fin.eof()��fin.fail()��Ϊ1
//����õ���getline���������ֲ�һ����
//Ҫ����EOFʱeof()��Ϊ1��fail()ҲΪ1
//(��D:\CODE\CPP_CODE\Dev-C++\LanQiao\code10 - ����)
//(���԰��ռ����������������)
#endif
//�Ӽ�������ʱ��cin����EOFʱ����״̬
#if 0
#include <fstream>

using namespace std;

int main()
{
    //**********************����cin**********************

    char ch1;
    cin >> ch1;//�˴�����^Zģ��EOF

    cout << cin.eof() << " " << cin.fail() << endl;

    if (cin)
        cout << "good" << endl;

    cout << ch1 << endl;

    cin.clear();

    //**********************����cin.get()**********************

    char ch2[10] = "123456789";
    cin.get(ch2, 10);//�˴�����^Z����������������
    //��ֱ������^Z��ch2[0]Ϊ���ַ���
    //���������������ݣ���ch2��ԭ�������ݻᱻ�����
    //���ݺͿ��ַ�������
    cout << cin.eof() << " " << cin.fail() << endl;

    //���ڷ�Χ��forѭ����������������飬����˵�������
    //��ֹ�����������⵽���ַ���ֹͣ
    //for (auto x : ch2)
    //{
    //	cout << x;
    //}
    for (int index = 0; ch2[index]; index++)
    {
        cout << ch2[index];
    }
    cout.put('\n');

    cin.clear();

    //**********************����cin.getline()**********************

    char ch3[10] = "123456789";
    cin.getline(ch3, 10);//�˴�����^Z����������������
    //��ֱ������^Z��ch3[0]Ϊ���ַ���
    //���������������ݣ���ch3��ԭ�������ݻᱻ�����
    //���ݺͿ��ַ�������
    cout << cin.eof() << " " << cin.fail() << endl;

    for (int index = 0; ch3[index]; index++)
    {
        cout << ch3[index];
    }
    cout.put('\n');

    cin.clear();

    return 0;
}
#endif
#if 0
//�޸ģ�
//ʹ��string���������ļ�����Ķ��䲻����ƴ�������
//������������if���ֱ�����
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const char* file1 = "17.8.4.1.txt";
const char* file2 = "17.8.4.2.txt";
const char* file3 = "17.8.4.3.txt";

int main()
{
    ifstream fin1, fin2;
    ofstream fout;

    fin1.open(file1);
    if (!fin1.is_open())
    {
        cerr << "error 1\n";
        exit(EXIT_FAILURE);
    }

    fin2.open(file2);
    if (!fin2.is_open())
    {
        cerr << "error 2\n";
        exit(EXIT_FAILURE);
    }

    fout.open(file3);
    if (!fout.is_open())
    {
        cerr << "error 3\n";
        exit(EXIT_FAILURE);
    }

    //char temp1[80] = { '\0' };
    //char temp2[80] = { '\0' };

    //fin1.getline(temp1, 80);
    //fin2.getline(temp2, 80);

    string str;

    while (!fin1.eof() || !fin2.eof())
    {
        if (getline(fin1, str) && str.size() > 0)
            fout << str << ' ';

        if (getline(fin2, str) && str.size() > 0)
            fout << str << ' ';

        fout << endl;
    }

    //д������
    /*
    while (fin1 || fin2)
    {
        if (getline(fin1, str))
            fout << str << ' ';

        if (getline(fin2, str))
            fout << str << ' ';

        fout << endl;
    }
    */

    return 0;
}
#endif


//5.
//������
#if 0
//*****************************ע************************************
//���뱨��
//�޷�ʹ�ô�Բ���ŵĳ�ʼֵ�趨���ʼ������
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

const int LIMIT = 20;

bool FillData(set<char[LIMIT]>&);

int main()
{
    set<char[LIMIT]>data_Mat;

    cout << "������������\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<char[LIMIT]>data_Pat;

    cout << "������������\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<char[LIMIT]>data_M_and_P;
    //��һ��ʹ����Լ��ϲ����ĺ���
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

    //������
    //***ע***���������������λ��
    //copy(data_Mat.begin(), data_Mat.end(),
    //	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
    //copy(data_Pat.begin(), data_Pat.end(),
    //	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

    //������
    data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
    data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

    //����д����(ԭ����P569)
    //copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

    //����д��������ʹ��back_insert_iterator
    /*copy(data_Mat.begin(), data_Mat.end(),
        back_insert_iterator<set<string> >(data_M_and_P));*/

    cout << "���˵������У�\n";
    for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    return 0;
}
bool FillData(set<char[LIMIT]>& data)
{
    bool status = 1;

    char temp[LIMIT];

    cin.getline(temp, LIMIT);
    while (cin && temp[0] != '\0')
    {
        data.insert(temp);
        cin.getline(temp, LIMIT);
    }

    if (cin)
        cin.clear();

    if (data.size() == 0)
        status = 0;

    return status;
}
#endif
#if 0
//***ע***
//���뱨��
//�޷�ʹ�ô�Բ���ŵĳ�ʼֵ�趨���ʼ������
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

const int LIMIT = 20;

bool FillData(set<char*>&);

int main()
{
    set<char*>data_Mat;

    cout << "������������\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<char*>data_Pat;

    cout << "������������\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<char*>data_M_and_P;
    //��һ��ʹ����Լ��ϲ����ĺ���
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

    //������
    //***ע***���������������λ��
    //copy(data_Mat.begin(), data_Mat.end(),
    //	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));
    //copy(data_Pat.begin(), data_Pat.end(),
    //	insert_iterator<set<char[LIMIT]> >(data_M_and_P, data_M_and_P.begin()));

    //������
    data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
    data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

    //����д����(ԭ����P569)
    //copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

    //����д��������ʹ��back_insert_iterator
    /*copy(data_Mat.begin(), data_Mat.end(),
        back_insert_iterator<set<string> >(data_M_and_P));*/

    cout << "���˵������У�\n";
    for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    ofstream fout;
    ifstream fin;
    fout.open("17.8.5.txt", ios_base::binary);

    fout.write((char*)&data_Mat, sizeof data_Mat);

    set<char*>data;
    fin.read((char*)&data, sizeof data_Mat);
    for (auto p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\n';
    }
    //***ע***
    //�������ԣ�set<char*>data����ʵ��ɾ����ͬ���ַ�������Ϊ
    //�����ַ����ĵ�ַ��ͬ������Ϊ��ͬ
    //���Ҳ��ܽ����ݴ����ļ�����Ϊ�����Ĳ����ַ������ݣ�
    //�����ַ����Ĵ洢��ַ

    return 0;
}
bool FillData(set<char*>& data)
{
    bool status = 1;

    char temp[LIMIT];

    cin.getline(temp, LIMIT);
    while (cin && temp[0] != '\0')
    {
        char* p = new char[LIMIT];//������������ʱ��ֻ������p��
        strcpy(p, temp);					 //��������pָ�������
                                                     //���ڴ�й©�ķ���
        data.insert(p);
        cin.getline(temp, LIMIT);
    }

    if (cin)
        cin.clear();

    if (data.size() == 0)
        status = 0;

    return status;
}
#endif
//˼·�����Ȼ���ʹ��string������ַ���
//��set�����������ظ����ݺ��ٽ����ݴ���ΪC����ַ�����
//�����������ı�ģʽ��д�����ݣ����Կ���ʹ��string����
//���ļ�д������
#if 0
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

bool FillData(set<string>&);
int main()
{

    //����û��Mat���Ѻ�Pat���ѵ��ļ������ȼ���˶�
#if 0

    ofstream fout;
    ifstream fin;

    set<string>data_Mat;

    cout << "������������\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    fout.open("17.8.5.1.txt");
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        fout << (*p) << '\n';
    }
    fout.close();

    set<string>data_Pat;

    cout << "������������\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    fout.open("17.8.5.2.txt");
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        fout << (*p).c_str() << '\n';
    }
    fout.close();
#endif

#if 1

    ofstream fout("17.8.5.3.txt");
    ifstream fin;

    fin.open("17.8.5.1.txt");
    string temp;
    set<string>data_Mat;
    while (getline(fin, temp))
    {
        data_Mat.insert(temp);
    }
    fin.close();

    fin.open("17.8.5.2.txt");
    set<string>data_Pat;
    while (getline(fin, temp))
    {
        data_Pat.insert(temp);
    }
    fin.close();

    set<string>data_M_and_P;
    //��һ��ʹ����Լ��ϲ����ĺ���
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//ʹ�ò��������

    //������
    //***ע***���������������λ��
    //copy(data_Mat.begin(), data_Mat.end(),
    //	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));
    //copy(data_Pat.begin(), data_Pat.end(),
    //	insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

    //������
    data_M_and_P.insert(data_Mat.begin(), data_Mat.end());
    data_M_and_P.insert(data_Pat.begin(), data_Pat.end());

    //����д����(ԭ����P569)
    //copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());

    //����д��������ʹ��back_insert_iterator
    /*copy(data_Mat.begin(), data_Mat.end(),
        back_insert_iterator<set<string> >(data_M_and_P));*/

    fout << "���˵������У�\n";
    for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
    {
        fout << *p << '\n';
    }

    std::cout << "Done !\n";

#endif

    return 0;
}
bool FillData(set<string>& data)
{
    bool status = 1;

    string temp;

    getline(cin, temp);
    while (cin && temp != "")
    {
        data.insert(temp);
        getline(cin, temp);
    }

    if (cin)
        cin.clear();

    if (data.size() == 0)
        status = 0;

    return status;
}
//***ע***
//�˴�string�������ʱ��ָ���ַ�����ָ���
//�ַ������ݾ��ᱻ����
//�� set<string>data_Mat
//data.insert(temp);
//data_Mat��set�����е�string�����Ѿ���
//temp���ݿ�������
#endif


//6.
//����17.8.6.cpp
#if 0
#include "17.8.6.h"
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 10;
abstr_emp* pc[MAX];

void menu(void);
char get_choice(void);

int main(void)
{
    /*
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;//***ע***����������û���ض���<<��������غ�����
    em.ShowAll();				//���Ĭ��ʹ�û����<<��������غ���
    cout.put('\n');

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    cout.put('\n');

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    cout.put('\n');

    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout.put('\n');

    cout << "Press a key for next phase:\n";
    cin.get();

    highfink hf2;
    hf2.SetAll();
    cout.put('\n');

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp* tri[4] = { &em,&fi,&hf,&hf2 };

    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    */

    //***ע***
    //�ڶ�������д���ļ�ʱ��������ǰ���Ѿ�����һ��ָʾ�������͵�����
    enum classkind { Employee, Manager, Fink, Highfink };

    ifstream fin("17.8.6.txt");
    int index = 0;
    //���ļ����ڣ�������ļ�ԭ��������
    if (fin.is_open())
    {
        std::cout << "Here are the current contents of the "
            << "17.8.6.txt" << " file:\n";

        int classtype;

        while (fin >> classtype)
        {
            fin.get();

            //***ע***
            //д��
            //while ((fin >> classtype).get())
            //{
            //�������в�����

            switch (classtype)
            {
            case Employee:
                pc[index] = new employee;
                pc[index]->getall(fin);
                break;
            case Manager:
                pc[index] = new manager;
                pc[index]->getall(fin);
                break;
            case Fink:
                pc[index] = new fink;
                pc[index]->getall(fin);
                break;
            case Highfink:
                pc[index] = new highfink;
                pc[index]->getall(fin);
                break;
            }

            index++;
        }

        fin.close();
    }

    //����д����
    //fin.seekg(0,ios_base::beg);
    //for (int i = 0; i < index; i++)
    //	pc[i]->getall(fin);

    for (int i = 0; i < index; i++)
        pc[i]->ShowAll();

    //д�����ݣ�

    index = 0;
    while (index < 10)
    {
        menu();
        char choice = get_choice();

        if (choice == 'q')
            break;

        switch (choice)
        {
        case 'a':
            pc[index] = new employee;
            break;
        case 'b':
            pc[index] = new manager;
            break;
        case 'c':
            pc[index] = new fink;
            break;
        case 'd':
            pc[index] = new highfink;
            break;
        }

        pc[index]->SetAll();

        index++;
    }

    //***ע***

    //������⣺
    //����д����ÿ��д���������ݺ󣬴���writeall(...)
    //��fout�����ָ��ָ���λ�û����ļ���ͷ

    //��ȷ��⣺
    //foutֻ�Ǹ�ofstream���������һ�����ָ��
    //fout��ģʽ����׷������ģʽ��fout�������ָ����Ƶ��ļ�ĩβ
    ofstream fout;
    for (int i = 0; i < index; i++)
        pc[i]->writeall(fout);

    cout << "д����ɣ�";

    return 0;
}

void menu(void)
{
    cout << "������Ҫ�����Ķ���ǰ��Ӧ����ĸ��\n";
    cout << left << setw(15) << "a) employee"
        << setw(8) << "b) manager" << endl
        << setw(15) << "c) fink"
        << setw(8) << "d) highfink" << endl;
}
char get_choice(void)
{
    char ch;
    while (cin.get(ch))
    {
        while (cin.get() != '\n')
            continue;
        ch = tolower(ch);

        if (strchr("abcdq", ch) == NULL)
            cout << "������a��b��c��d��q : ";
        else
            break;
    }

    return ch;
}
#endif


//7.
//������
#if 0
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

void ShowStr(const std::string&);

class Store
{
private:
    std::ofstream m_fout;

    struct
    {
        char temp[50];

        char* data(void)
        {
            return temp;
        }
    }s;

public:
    Store()
    {}
    Store(std::ofstream& fout)
    {
        //m_fout = fout;  ����
        //�����m_foutҲ��"strings.dat"������ģʽ��foutһ��������
    }

    void operator()(const std::string& st)
    {
        int len = st.length();

        strcpy(s.temp, st.c_str());

        m_fout.write((char*)&len, sizeof(std::size_t));
        m_fout.write(s.data(), len);
    }

    ~Store()
    {}
};

void GetStrs(std::ifstream&, std::vector<std::string>&);

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings(empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr�Ǻ�������

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    //***ע***
    //Store(fout)���õ��ǹ��캯��������һ�������ĺ�������
    //���ú�������Ӧ��operator()����

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const std::string& st)
{
    std::cout << st << std::endl;
}
#endif
//������
//7.
//������
#if 0
#include <vector>
#include <string>
//#include <sstream>
#include <fstream>
#include <algorithm>

void ShowStr(const std::string&);

class Store
{
private:
    std::ofstream* m_fout;//����һ��ָ��ofstream�����ָ��

public:
    //Store()
    //{}

    //***ע***��һ��&��ʾ���ã��ڶ���&��ʾȡ��ַ
    Store(std::ofstream& fout) :m_fout(&fout)
    {}

    void operator()(const std::string& st)
    {
        //***ע***
        //��¼Ҫ�洢���ַ�����Ҫռ�õĿռ�
        int len = st.length() + 1;

        if (m_fout->is_open())
        {
            m_fout->write((char*)&len, sizeof len);
            m_fout->write(st.data(), len);//***ע***string����data()����
            //�䷵��һ��ָ�룬ָ��洢���ַ���������
        }
    }

    //***ע***
    //����д�������У�ԭ����P633
    //m_fout->write((char*)&st, len);
    //����д�������У�
    //m_fout->write(st.data(), len);
    //m_fout->write(st.c_str(), len);

    ~Store()
    {}
};

void GetStrs(std::ifstream&, std::vector<std::string>&);

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings(empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);//ShowStr�Ǻ�������

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    //***ע***
    //Store(fout)���õ��ǹ��캯��������һ�������ĺ�������
    //���ú�������Ӧ��operator()����

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const std::string& st)
{
    std::cout << st << std::endl;
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& v)
{
    int len;
    char* p;

    while (fin.read((char*)&len, sizeof len))
    {
        p = new char[len];
        fin.read(p, len);
        v.push_back(p);//��C����ַ�����յ�string����ֵ
    }
}
#endif


//�����ַ�������string����ֵ��
//������
#if 0
#include <string>

using namespace std;

int main()
{
    char data[2] = { 'a','b' };
    string str;

    str = data;
    cout << str << endl;

    //���ۣ�
    //���Ը�ֵ���������޿��ַ����ᵼ�º���ַ�������

    return 0;
}
#endif


//string��c_str()������data()�����ıȽ�
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
    {
        string s = "12345";
        char test[10];
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            test[i] = 'z';
        }

        strncpy(test, s.c_str(), 6);
        for (i = 0; i < 10; i++)
        {
            printf("%c ", test[i]);
        }

        cout << endl;
    }

    {
        string s = "12345";
        char test[10];
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            test[i] = 'z';
        }

        strncpy(test, s.data(), 6);
        for (i = 0; i < 10; i++)
        {
            printf("%c ", test[i]);
        }

        cout << endl;
    }

    return 0;
}
//https://blog.csdn.net/stpeace/article/details/50640317
//���ۣ�������ͬ��Ч����������C����ַ���
#endif


//chapter 18
//code1.cpp
//C++11�¹���
//1.������
//2.ͳһ�ĳ�ʼ��
//3.������
//4.����ָ��
//5.�쳣
//6.��������ö��
//7.������޸�  explicit
//8.ģ���STL������޸�
//9.��ֵ����


//�����嵥 18.1 ��ֵ����
//������
#if 0
#include <iostream>

inline double f(double tf)
{
    return 5.0 * (tf - 32.0) / 9.0;
}

int main()
{
    using namespace std;

    double tc = 21.5;

    double&& rd1 = 7.07;
    double&& rd2 = 1.8 * tc + 32.0;
    double&& rd3 = f(rd2);

    cout << " tc value and address: " << tc << ", " << &tc << endl;
    cout << "rd1 value and address: " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 value and address: " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 value and address: " << rd3 << ", " << &rd3 << endl;

    // cin.get();
    return 0;
}
#endif


//�����嵥18.2 �ƶ����캯��
//����cxqd18.2.cpp
#if 0
#include "cxqd18.2.h"

using namespace std;

// application
int main()
{
    {
        Useless one(10, 'x');
        //���ø��ƹ��캯��
        Useless two = one; // calls copy constructor

        //***ע***��д��
        //Useless two;
        //two = one;
        //�ͻᷢ����ֵ�����ǳ���ƣ�������������
        //���ͷ�ͬһƬ�ڴ����Σ����³����쳣��ֹ

        Useless three(20, 'o');
        cout.put('\n');

        //����+��������غ���
        //�����ƶ����캯��
        Useless four(one + three);  // calls operator+(), move constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
    // cin.get();
}
#endif


//�����嵥18.2.1 ʹ��ǿ���ƶ�move()
//����cxqd18.2.1.cpp
#if 0
#include "cxqd18.2.1.h"
#include <utility>

using namespace std;

int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;          // calls copy constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        Useless three = move(one);
        cout << "object three: ";
        three.ShowData();
    }

    //cin.get();
}
#endif


//�����嵥18.3 �ƶ��������ڹ��캯���͸�ֵ��������غ���
//����cxqd18.3.cpp
#if 0
#include <utility>
#include "cxqd18.3.h"

// application
int main()
{
    using std::cout;
    {
        Useless one(10, 'x');

        //����+��������غ���
        //���ƶ����캯��
        Useless two = one + one;   // calls move constructor

        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();

        Useless three, four;

        cout << "three = one\n";
        //���ø�ֵ��������غ���
        three = one;              // automatic copy assignment
        cout << "now object three = ";
        three.ShowData();
        cout << "and object one = ";
        one.ShowData();

        cout << "four = one + two\n";
        //***ע***
        //����+��������غ���
        //���ƶ����캯��(���صĶ������ڶ���ʱ�����ʼ����
        //Ȼ���������������ͷŷ��صĶ���ռ�õ��ڴ�)
        //���ƶ���ֵ��������غ���(���ڽ���ʱ���������
        //ֱ���޸�Ϊfour�����ݣ�����ٴε�����������
        //�ͷ���ʱ����ռ�õ��ڴ�)
        four = one + two;         // automatic move assignment
        cout << "now object four = ";
        four.ShowData();

        cout << "four = move(one)\n";
        //�ƶ���ֵ��������غ���
        four = std::move(one);    // forced move assignment
        cout << "now object four = ";
        four.ShowData();
        cout << "and object one = ";
        one.ShowData();
    }
    //std::cin.get();
}
#endif


//�����嵥18.4 ʹ��lambda����
//������
#if 0
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main()
{
    using std::cout;

    std::vector<int> numbers(Size1);

    std::srand(std::time(0));
    //generate()�����������Ǹ��������κβ����ĺ�������(������)
    std::generate(numbers.begin(), numbers.end(), std::rand);

    cout << "Sample size = " << Size1 << '\n';

    //ʹ�ú���ָ��(��������)
    // using function pointers
    //count_if()�����������Ǹ�����ֵΪtrue��false�ĺ�������
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    //ʹ�ú�������
    // using a functor
    class f_mod
    {
    private:
        int dv;
    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) { return x % dv == 0; }
    };

    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers again
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';

    //ʹ��lambda����
    // using lambdas
    count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    // std::cin.get();
    return 0;
}
//����lambda��������Ϊ�˽������ں����ı��ʽ���ڽ��ܺ���ָ��
//�������ĺ����Ĳ���

//ʹ��lambda�����ĺô���
//�����ʹ����һ�����鿴���޸���༭����
//���ȸ�
//������ֹ������Ч�ʸ�
#endif


//�����嵥18.5 lambda�����Ķ��⹦��
//������
#if 0
#include <vector>
#include <algorithm>
//#include <cmath>
#include <ctime>
#include <cstdlib>
const long Size = 390000L;

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

    cout << "Sample size = " << Size << '\n';

    //ʹ������������lambda��������ʹ��lambda�����Ķ��⹦��
    // using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&count13](int x) {count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    //ʹ��һ��lambda�������������Ķ��⹦�ܣ��ɷ�����������
    //���κζ�̬�������ɽ������Ʒ�����������
    // using a single lambda
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    // std::cin.get();
    return 0;
}
#endif


//�����嵥18.7 ģ��ĵ�Ч��
//������
#if 0
#include <cmath>
#include "cxqd18.6.h"

using namespace std;

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << "  " << use_f(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
    cout << "  " << use_f(y, sqrt1) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f(y, [](double u) {return u * u; }) << endl;
    cout << "Lambda expresson 2:\n";
    cout << "  " << use_f(y, [](double u) {return u + u / 2.0; }) << endl;

    //cin.get();
    return 0;
}
//���Կ�����
//ģ��use_f()��5����ͬ��ʵ����
#endif


//�����嵥18.8 ʹ�ð�װ��function
//��ģ��function������һ�����󣬿����ڰ�װ������������ͬ��
//����ָ�롢���������lambda���ʽ��
//ʹģ�������һ��ʵ����
//������
#if 0
#include "cxqd18.6.h"
#include <math.h>
#include <functional>

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    using std::cout;
    using std::endl;
    using std::function;

    double y = 1.21;

    //д��һ��
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = sqrt1;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 = [](double u) {return u * u; };
    function<double(double)> ef6 = [](double u) {return u + u / 2.0; };

    //д������
    cout << use_f(y, function<double(double)>(dub)) << endl;
    //��д����
    typedef function<double(double)> fdd;
    cout << use_f(y, fdd(sqrt1)) << endl;

    //(д��һ������)
    cout << use_f(y, ef3) << endl;
    cout << use_f(y, ef4) << endl;
    cout << use_f(y, ef5) << endl;
    cout << use_f(y, ef6) << endl;

    //std::cin.get();
    return 0;
}
#endif
//д������Ҫ�޸�ģ���ģ�����Ͳ���
//����Ҫ�ڵ��ú���ʱ������ʽʵ����
#if 0
#include <math.h>
#include <functional>
using namespace std;

template <typename T>
T use_f(T v, std::function<T(T)> f)
{
    static int count = 0;
    count++;
    cout << "  use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp
{
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator()(double p) { return z_ * p; }
};
class Fq
{
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return z_ + q; }
};

double dub(double x) { return 2.0 * x; }
double sqrt1(double x) { return sqrt(x); }

int main()
{
    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << "  " << use_f<double>(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
    cout << "  " << use_f<double>(y, sqrt1) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f<double>(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f<double>(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f<double>(y, [](double u) {return u * u; }) << endl;
    cout << "Lambda expression 2:\n";
    cout << "  " << use_f<double>(y, [](double u) {return u + u / 2.0; }) << endl;

    //cin.get();
    return 0;
}
#endif


//�����嵥18.9 �ɱ����ģ��
//������
#if 0
#include <string>

// definition for 0 parameters -- terminating call
void show_list3() {}
//***ע***�˺���������
//��Ϊ���������б�ݹ��ÿ�μ���һ��
//�������0�����Ҫ�к����ܴ���0�����������

// definition for 1 or more parameters
//ģ�������Args
//����������args
template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);//�˴�...��ʾ������������չ��
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list3(n, x);

    std::cout.put('\n');

    show_list3(x * x, '!', 7, mr);

    return 0;
}
#endif


//�����嵥18.10 �ɱ����ģ�壬ʹ���ϵĸĽ�
//������
#if 0
#include <string>

// definition for 0 parameters
//void show_list() {}

//***ע***
// �˺�������û��
//��Ϊ�ݹ���õ�����ֻʣ1��ʱ��������
//template<typename T>
//void show_list(const T& value)
//����û���ٵ���show_list()���ʽ���ֹ�ݹ�

// definition for 1 parameter
template<typename T>
void show_list(const T& value)
{
    std::cout << value << '\n';
}

// definition for 2 or more parameters
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
    std::cout << value << ", ";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);
    return 0;
}
#endif


//�����嵥18.11 ʹ��Boost���е�Conversion�⣬
//������ֵ���ַ���֮��ļ�ת��
//(Boost��δ���أ������޷�ͨ������)
//������
#if 0
#include <string>
#include "boost/lexical_cast.hpp"
int main()
{
    using namespace std;
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " to ";  // string operator+()
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;
    return 0;
}
#endif


//chapter 18
//code2.cpp
//18.11 ��ϰ��
//1.
//������
#if 0
#include <string>
#include <vector>
//#include <initializer_list>

class Z200
{
private:
    int j;
    char ch;
    double z;
public:
    Z200(int jv, char chv, double zv) : j(jv), ch(chv), z(zv) {}
};

int main()
{
    double x{ 8.8 };
    std::string s{ "What a bracing effect!" };
    int k{ 99 };
    Z200 zip{ 200, 'Z', 0.675 };
    std::vector<int> ai{ 3,9,4,7,1 };
}
#endif


//6.
//������
#if 0
template <typename T >
void show2(double x, T& fp)
{
    std::cout << x << " -> " << fp(x) << '\n';
}

//double f1(double x)
//{
//	return 1.8 * x + 32;
//}

//��lambda�������溯������
auto f1 = [](double x) {	return 1.8 * x + 32;	};

int main()
{
    show2(18.0, f1);

    return 0;
}

//***ע***����д������
//int main()
//{
//	show2(18.0, [](double x) {	return 1.8 * x + 32; });
//
//	return 0;
//}
#endif


//7.
//������
#if 1
//�޸�ǰ��
#if 0
#include <array>

const int Size = 5;

template<typename T>
void sum(std::array<double, Size> a, T& fp);

class Adder
{
    double tot;
public:
    Adder(double q = 0) :tot(q) {}
    void operator() (double w) { tot += w; }
    double tot_v() const { return tot; };
};

int main()
{
    double total = 0.0;
    Adder ad(total);//ad�����tot���ݳ�ԱֵΪ0

    std::array<double, Size>temp_c = { 32.1,34.3,37.8,35.2,34.7 };

    sum(temp_c, ad);
    total = ad.tot_v();

    std::cout << "total:" << ad.tot_v() << '\n';
    return 0;
}

template<typename T>
void sum(std::array<double, Size> a, T& fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(*pt);
    }
}
#endif
//�޸ĺ�
#if 0
#include <array>

const int Size = 5;

template<typename T>
void sum(std::array<double, Size> a, T& fp);

int main()
{
    double total = 0.0;

    std::array<double, Size>temp_c = { 32.1,34.3,37.8,35.2,34.7 };

    auto ad = [&total](double w) {	total += w;	};

    sum(temp_c, ad);

    std::cout << "total:" << total << '\n';
    return 0;
}

template<typename T>
void sum(std::array<double, Size> a, T& fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(*pt);
    }
}
#endif
#endif
//***ע***
//һ�����͵ĳ������ڴ����в�ͬ�������ⱻ��Ϊ������ڴ沼�֡�
//��Щ���������
//����Σ�Text Segment���� �洢����Ļ���ָ�Ҳ���ǿ�ִ�д��롣
//                                            �ⲿ����ֻ���ģ�ͨ���ǲ����޸ĵġ�
//���ݶΣ�Data Segment����
//			ȫ�ֱ������� ����ȫ�ֱ����;�̬������
//			�������� �洢�������ݣ������ַ���������
//�ѣ�Heap���� ��̬������ڴ����򡣳���Ա����������ʱͨ��new��C++��
//                       ��malloc��C���ȷ�ʽ�ڶ��Ϸ����ڴ档
//                       ע�⣬����Ա��Ҫ�����ֶ�������ϵ��ڴ棬�ͷŲ�����Ҫ�Ĳ��֡�
//ջ��Stack���� �洢�������ú;ֲ�������ÿ����������ʱ��
//                       ��صľֲ������ͷ��ص�ַ����Ϣ����ѹ��ջ�У�
//                       ����������ʱ����Щ��Ϣ�ᱻ������ջ��һ�����޵�����
//                       �������ڴ�������Զ��ġ�
//�ڴ�ӳ������ ��������⡢��̬���ӿ⡢�ں˿ռ�ȡ�


//chapter 18
//code3.cpp
//18.12 �����ϰ
//1.
//������
#if 0
#include <initializer_list>

using namespace std;

#if 0
template <typename T>						//***ע***�޷�д��decltype(T)
auto average_list(const initializer_list<T>& li) ->decltype(*li.begin())
{
    T sum = 0;

    for (auto p = li.begin(); p != li.end(); p++)
    {
        sum += *p;
    }

    return sum / li.size();
}
#endif

//***ע***
//��Ҫ����ֵ�����ͺ�ģ������Ͳ���һ�£���ҲΪT��
//��ӦдΪ��
template <typename T>
T average_list(const initializer_list<T>& li)
{
    T sum = 0;

    for (auto p = li.begin(); p != li.end(); p++)
    {
        sum += *p;
    }

    return sum / li.size();
}

int main()
{
    using namespace std;

    // list of double deduced from list contents
    auto q = average_list({ 15.4,10.7,9.0 });
    cout << q << endl;

    // list of int deduced from list contents
    //����Ӧ��Ϊ28.1666666666666666
    //�������������ͽ��нض�
    cout << average_list({ 20,30,19,17,45,38 }) << endl;

    // forced list of double
    auto ad = average_list<double>({ 'A',70,65.33 });
    cout << ad << endl;

    return 0;
}
#endif


//2.
//������
#if 0
#include "18.12.2.h"

using namespace std;

int main()
{
    {
        cout << "����cv1����" << endl;
        Cpmv cv1;

        cout << endl << "����cv2����" << endl;
        Cpmv cv2("abc", "123");

        cout << endl << "����cv3����" << endl;
        Cpmv cv3(cv1);

        cout << endl << "����cv4����" << endl;
        Cpmv cv4(cv1 + cv2);

        cout << endl << "����cv5����" << endl;
        Cpmv cv5;
        cv5 = cv4;

        cout << endl << "����cv6����" << endl;
        Cpmv cv6;
        cv6 = cv5 + cv2;

        cout << endl;
    }

    return 0;
}
#endif


//3.
//������
#if 0
#include <iomanip>

// definition for 1 parameter
template<typename T>
long double  sum_value(const T& value)
{
    sum += value;

    return sum;
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_value(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
    static T sum = 0;

    sum += value;

    sum_value(args...);//��ֻʣ��һ������ʱ������������Ǹ�����ģ��
                            //���ǲ����޷����ݸ������Ǹ�����ģ��

}

int main()
{
    auto res1 = sum_value(1, 2, 3, 4, 5);

    auto res2 = sum_value(1.5, 2.5, 3.5);

    return 0;
}
#endif
//3.����
//������
#if 0
#include <iomanip>

// definition for 1 parameter
template<typename T>
long double  sum_value(const T& value)
{
    return value;
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_value(const T& value, const Args&... args)
{                           //ʹ����������ߴ���Ч��
    return value + sum_value(args...);
}

int main()
{
    auto res1 = sum_value(1, 2, 3, 4, 5);
    auto res2 = sum_value(1.5, 2.5, 3.5);
    auto res3 = sum_value('A', 1, 2);

    std::cout << res1 << std::endl
        << res2 << std::endl
        << res3 << std::endl;

    return 0;
}
#endif


//4.
//������
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

#include <functional>

//��������(������)
//������()�������������������ʹ�ú�������ʹ�������
//template<class T>  // functor class defines operator()()
//class TooBig
//{
//private:
//	T cutoff;
//
//public:
//	TooBig(const T& t) : cutoff(t)
//	{}
//	bool operator()(const T& v)
//	{
//		return v > cutoff;
//	}
//};

//void outint(int n)
//{
//	std::cout << n << " ";
//}

int main()
{
    using std::cout;
    using std::endl;

    using std::list;
    using std::for_each;
    using std::remove_if;

    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(vals, vals + 10);

    //  C++0x can use the following instead
    //  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    //  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    auto outint = [](int n) { cout << n << " ";  };

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    //ʹ��������lambda���ʽ
    yadayada.remove_if([](int n) { return n > 100; });

    //д��һ��

    etcetera.remove_if([](int n) { return n > 200; });

    //д������
    //etcetera.remove_if(std::bind2nd(std::greater<int>(), 200));

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    // std::cin.get();
    return 0;
}
#endif

/****************************************************End*****************************************/
