#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

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
    TableTennisPlayer player3 (rplayer3);//ʹ������������ʼ���������
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
    cout << "New balance: $" << Hoggy.Balance() << endl<<endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);//ʹ��Brass���Withdraw��������֧��͸֧
    cout << "Pigg account balance: $" << Piggy.Balance() << endl<<endl;

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