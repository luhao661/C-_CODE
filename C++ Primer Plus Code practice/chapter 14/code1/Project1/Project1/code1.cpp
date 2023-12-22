#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

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

template <class T1, class T2=int>//����Ϊ���Ͳ����ṩĬ��ֵ
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

    cout << " beta<double> guy(3.5, 3);"<<endl;
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
U beta<T>:: blab(U u, T t)
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