#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//程序清单13.3 使用一个简单的基类
//链接cxqd13.2.cpp
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


//程序清单13.6 使用派生类，演示派生类和基类的关系
//链接cxqd13.5.cpp 
#if 0
#include "cxqd13.4.h"

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    player1.Name();           // 基类对象使用基类的方法
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";

    //声明并初始化派生类对象
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();          // 派生类对象使用基类的方法
    //写法二：
    //rplayer1.TableTennisPlayer::Name();

    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    //使用基类对象初始化派生类对象
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    RatedPlayer rplayer3(333, "Aaa", "Bbb", true);
    TableTennisPlayer player3 (rplayer3);//使用派生类对象初始化基类对象
    player3.Name();
    cout.put('\n');

    RatedPlayer rplayer4(444, "Ccc", "Ddd", true);
    TableTennisPlayer player4;//使用派生类对象赋值给基类对象
    player4 = rplayer4;
    player4.Name();
    cout.put('\n');

    // std::cin.get();
    return 0;
}
#endif


//程序清单13.9 测试含虚函数的基类和派生类(但不使用虚方法的特性)
//链接cxqd13.8.cpp
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
    cout << "New balance: $" << Hoggy.Balance() << endl<<endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);//使用Brass类的Withdraw方法，不支持透支
    cout << "Pigg account balance: $" << Piggy.Balance() << endl<<endl;

    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);//使用BrassPlus类的Withdraw方法，支持透支
    Hoggy.ViewAcct();
    // std::cin.get();
    cout.put('\n');
    fv(Piggy);//Brass对象传递给BrassPlus类型的形参的函数，会先调用派生类构造函数进行类型转换，再使用fv()函数
    cout.put('\n');
    fv_1(&Hoggy);

    return 0;
}
#endif


//程序清单13.10 类的多态(同一个方法在派生类和基类中的行为不同)——虚函数
//链接cxqd13.8.cpp
#if 0
#include "cxqd13.7.h"
#include <string>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass* p_clients[CLIENTS];//声明一个数组，每个元素都是指向Brass类的指针
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

        while (!(cin >> kind)||(kind!='1'&&kind!='2'))
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
        while (cin.get() != '\n')//消耗掉换行符，否则getline()将读取不到第二次及之后的输入
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


//程序清单13.13 关键字protected，纯虚函数，抽象基类ABC
//链接cxqd13.12.cpp
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


//程序清单13.16 派生类使用动态内存分配和派生类如何访问基类的友元函数
//链接cxqd13.15.cpp
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

    lacksDMA balloon2(balloon);//使用默认的复制构造函数
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;//使用显式的赋值运算符重载函数
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    // std::cin.get();
    return 0;
}
#endif