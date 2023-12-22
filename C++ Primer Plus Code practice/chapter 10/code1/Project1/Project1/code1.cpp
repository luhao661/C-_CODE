#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


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
        Stock stock4 = {"abc def",20,20.0};//��ʽ���ù��캯��
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
                while(!(cin >> data))
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