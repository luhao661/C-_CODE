#define _CRT_SECURE_NO_WARNINGS 1
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
double refcude_1(const double & ra);

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
free_throws &accumulate(free_throws& target, const free_throws& source);

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
    //fmtflags���洢��ʽ����Ϣ����������
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
    for (i = 0;         i < n && str[i];         i++)
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
void Swap( T& a,  T& b);

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
T add(T a,T b);

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

    cout <<add<double>(m,n)<<endl;//��ʾʵ������ʹ��add()ģ������һ��ʹ��double���͵�ʵ��

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
        /*cout << *arr[i] << ' ';*/cout<<**(arr+i)<<' ';
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
auto add(T1 x,T2 y)->decltype(x+y);// ->decltype(x+y) ˵������������x+y������ֵ������

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
