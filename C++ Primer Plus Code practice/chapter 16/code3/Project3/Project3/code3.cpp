#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//16.10 �����ϰ
//1.
//������
#if 0
#include <string>
bool huiwen(std::string & st);

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
	int local=0;				   //����4������ֻҪ0��1������6������ֻҪ0��1��2������8������ֻҪ0��1��2��3

	//����Ҫ����ż
	//if(length%2)//������
		for (int i = 0; i < int(length/2); i++)
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
//count()��foreach() 
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

    reverse(temp.begin(),temp.end());

  /*  if (temp == st)
        return true;
    else
        return false;*/

    return (temp==st);
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
	cout << st<<endl;

	string st1;
	//transform(st.begin(), st.end(),st1.begin(),ToLower); //��������������ʹ�ò��������
	transform(st.begin(), st.end(),std::back_insert_iterator<string>(st1), ToLower);

	cout << st1<<endl;

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
    std::string::iterator phead,ptail;

    phead = st.begin();
    ptail = st.end()-1;//***ע***�˴�Ҫ��һ����������ú�����

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
    int NUM=0;

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

int reduce(long ar[],int n);

int main()
{
    long ar[] = {1,3,4,3,3,5,7,8,9,8,8,1,2,5,4};
    int len = sizeof ar / sizeof(long);

    int num=reduce(ar,len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//nֵΪ15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar+index));
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
    transform(l1.begin(),l1.end(),result,mycopy);

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
int reduce(T * ar,int n);

int main()
{
    long ar[15] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int num = reduce(ar,15);
    std::cout << num<<std::endl;

    std::string s1 [4] = {"abc","ghj","cdf","bef"};
    num = reduce(s1,4);
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

    copy(l1.begin(),l1.end(),result);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index]<<' ';
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
            if (line.size()==qs)
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
            temp=line.front();     //�ŵ�һ���Ĺ˿��ڶ����б��ų����俪ʼ���н���
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
vector<int> lotto(int num_of_dot,int num_of_choose);

int main()
{
    vector<int> winners;
    winners = lotto(51,6);

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
        data[i-1] = i;
    }

    cout << "���֣�";
    vector<int>::iterator p;
    for (p = data.begin(); p < data.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    srand(time(0));//***ע***�˴������������ܹ�random_shuffle����ʹ��
    random_shuffle(data.begin(),data.end());

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
        insert_iterator<set<string> > (data_M_and_P, data_M_and_P.begin()));
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
    bool status=1;

    string temp;

    getline(cin,temp);
    while (cin&&temp!="")
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
    for_each(vi0.begin(),vi0.end(),show);
    cout << endl;
#endif

    vector<int>vi(vi0);
    list<int>li(vi0.size());
    copy(vi0.begin(),vi0.end(),li.begin());

    cout << "STL��sort()�������õ�ʱ�䣺\n";
    //����������������������ʱ��
    clock_t start = clock();//(�Ժ���Ϊ��λ)
    sort(vi.begin(),vi.end());
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;

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
    cout << num<<" ";
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
    auto p_temp=new Review;
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
                cout << "�����������������룡"<<endl;
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
        shared_ptr<Review> p  (new Review (temp));

        //д������
        //shared_ptr<Review> p (new Review);
        //*p = temp;

        books.push_back(p);//��������ָ���ĸ�ֵ�������ǳ�ʼ��
    }
#endif

    if (books.size() > 0)
    {
        cout << "Thank you. You entered "
            << books.size()<<" books !\n";

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