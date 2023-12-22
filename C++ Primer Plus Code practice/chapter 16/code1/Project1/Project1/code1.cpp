#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

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
        std::cout <<*p_to_d<< std::endl;

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

    vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    //����Ԫ�ط���һ��
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
    for_each(data.begin(),data.end(),show);
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
    for (auto &x : data)
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
    std::cout <<a<< '\t';
}
void alter(double &num)
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
    sort(dice.begin(),dice.end());
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
    codes.insert(Pair(718, "Staten Island"));
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
    etcetera.remove_if(std::bind2nd(std::greater<int>(),200));

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
        wordmap.insert(
            pair<string,int>(
                *si,          count(words.begin(),words.end(),*si)
                )
        );
     //д������(�����������ʾ��(������������ֵ)�����ʴ洢��ֵ)
     //wordmap[*si] = count(words.begin(), words.end(), *si);

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
    copy(data.begin(),data.end(),begin(numbers));

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

    cout << "List 1: sum = " << sum(  { 2,3,4 }  )
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
#endif

