#define _CRT_SECURE_NO_WARNINGS 1
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
    printf("%s",petkind[1]);                                                                //֤��petkind�����ʼ����Ԫ�ض�Ϊ'\0'
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

    cout << R"(��ʹ��ת���������""     \n   "\n")"<<endl<<'\n';

    cout << "ʹ��ת���������"<<"\"\"   \\n  \"\\n\"\n\n";

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


    const antarctica_years_end* zhizhen_shuzu[3] =\
    { &jiegou01, &jiegou02, &jiegou03 };//����һ�����飬�ں�����ָ��
 
    std::cout << zhizhen_shuzu[1]->year << std::endl;
    //------------------------------------------------------------------------------

    const antarctica_years_end** p_zhizhen_shuzu_1 \
        = zhizhen_shuzu;//��������ʼ��һ��ָ��ָ���ָ��

    auto p_zhizhen_shuzu_2 = zhizhen_shuzu; //***ע***C++11��auto����Ϊ����һ�������ṩ����
                                                                           //������֪��zhizhen_shuzu�����ͣ������ܹ��ƶϳ�p_zhizhen_shuzu_2������
    //Ҳ��������Ϊ const antarctica_years_end ** p_zhizhen_shuzu_2 = zhizhen_shuzu; 

    std::cout << (*p_zhizhen_shuzu_1)->year << std::endl;
    std::cout << (  *(p_zhizhen_shuzu_2 + 1)  )->year << std::endl;
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