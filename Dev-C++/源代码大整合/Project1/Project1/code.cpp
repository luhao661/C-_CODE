#define _CRT_SECURE_NO_WARNINGS 1

//code1.cpp
//1.2 ���ﵥ
#if 0
#include <iostream>
#include <valarray>
//#include <algorithm> 
using namespace std;

int main()
{
	freopen("cost.txt", "r", stdin);

	//***ע***����д���� 
	//	valarray<double> jiage[100];
	//	valarray<int> zhekou[100];
	//��ȷд����
	valarray<double> jiage(100);  //Ĭ��ȫΪ0 
	valarray<int> zhekou(100);

	//	double jiage[100]={0.0};
	//	int zhekou[100]={};

	double a;
	int b;
	int index = 0;
	while (cin >> a >> b)
	{
		//���� valarray���󳤶Ȳ�֧�ֶ�̬�ı� 
		//		jiage.push_back(a);
		//		zhekou.push_back(b);
		jiage[index] = a;
		zhekou[index] = b;
		index++;
	}

	int count = 0;//������Ʒ���� 
	for (int i = 0; i < 100; i++)
	{
		if (jiage[i])
			count++;
	}

	//	for(int i=0;i<count;i++)
	//	{
	//	cout<<jiage[i];
	//	}

	valarray<double> result(100);
	for (int i = 0; i < count; i++)
	{
		if (zhekou[i] > 0 && zhekou[i] < 10)//��9�� 
			result[i] = jiage[i] * 0.1 * zhekou[i];
		else//��88�� 
			result[i] = jiage[i] * 0.01 * zhekou[i];
	}

	double sum = result.sum();
	cout << sum;

	return 0;
}
#endif


//1.3 �ڼ���(�ж����꣬�������Ƿ�Ϊ29��)
#if 0
#include <iostream>

using namespace std;
bool runnian(int year);

int main()
{
	int year;

	cin >> year;

	if (runnian(year))
		cout << "������" << endl;

	return 0;
}
bool runnian(int year)
{
	return(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
#endif


//1.4 ���� 
#if 0
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in;
	in.open("1.4.txt");

	vector<int>data[10];//������ά���� 

	int i, temp;
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			in >> temp;
			data[i].push_back(temp);
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (auto p = data[i].begin(); p != data[i].end(); p++)
			cout << *p << " ";

		cout << endl;
	}
	cout << endl;


	//���ڴ�����ǵڼ����� 
	int dijigezi = 1;

	vector<int> data2[16];//����һ��16*2�Ķ�ά����
	int j = 0;
	for (i = 0; i < 32; i++)
	{
		data2[j].push_back(data[dijigezi - 1][i]);
		data2[j].push_back(data[dijigezi - 1][++i]);
		j++; //���� 
	}

	//��ʾʮ���Ʊ�ʾ��������Ϣ 
	int huanhang = 0;
	for (i = 0; i < 16; i++)
		for (auto p = data2[i].begin(); p != data2[i].end(); p++)
		{
			cout << *p << " ";
			huanhang++;

			if (huanhang % 2 == 0)
				cout << endl;
		}

	//***ע*** 
	//������⣺����ȫΪ0 (��C������ȷʵ������)
	char shuzu[16][16] = { {'0'},{'0'} };

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			shuzu[i][j] = '0';
	}

	int num;

	for (int i = 0; i < 16; i++)		//***ע***�˴�-1����д 
		for (auto p = data2[i].begin(); p != data2[i].end() - 1; )
		{
			num = *p;

			//��Ϊ���� 
			if (num < 0)
				num = 256 + num;

			int index = 7;//����ȡ�൹�����ɴ�洢ʱ���Ŵ棬��ʱ˳�Ŷ� 
			while (num != 0 && index != 0)
			{
				shuzu[i][index--] = num % 2 + '0';
				num /= 2;
			}

			p++;
			num = *p;


			if (num < 0)
				num = 256 + num;

			index = 15;
			while (num != 0 && index != 8)
			{
				shuzu[i][index--] = num % 2 + '0';
				num /= 2;
			}
			//***�������ת���ɶ����ƣ��� 
			//��������bitsetģ���� 
		}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
			cout << shuzu[i][j];
		cout << endl;
	}

	return 0;
}
#endif


//1.5 ����ַ��� 
//����ĸ�������ʾ���� 
//***˼·***
//�൱��������26��������ʾ ����0��25�� 
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;//***ע***����1Ӧ��ʾA��A������Ϊ0 

	while (cin >> num)
	{
		num -= 1; //�������ֵ 

		//ʹ��vector�����ĺô��ǿ��Զ�̬�������ȣ�����
		//ʹ�������޷�����û��Ԫ�������λ�õı�ʾ 
		vector<int> data;

		//***ע***Ҫʹ�ó�������ѭ������������1ʱ��data���������� 
		do
		{
			data.push_back(num % 26);

			num /= 26;
		} while (num != 0);


		//***ע***д��
//		for(auto i=data.end()-1;i>=data.begin();i--)//Ҳ���� 
		for (auto i = data.rbegin(); i != data.rend(); i++)
			cout << *i;

		//�����Ѿ�ת���ɶ�ʮ�����Ʊ�ʾ 


		//***ע***
		//��λ������λ���ȵ��������λ֮���λ��Ӧ����
		//ԭ������-1����Ϊ�Ͷ�λ����˵��һ���������10��ʼ��
		//������Ҫ����00��ʼ�� 
		cout.put('\n');

		//����ָ��ͨ���ȵݼ����ٽ��д����
		for (auto i = data.rbegin(); i != data.rend(); i++)
		{
			if (data.size() == 1)
				cout << (char)(*(i)+'A');
			else
			{
				if (i == data.rend() - 1)//���λ ***ע***�˴�-1��Ҫ��� 
					cout << (char)(*(i)+'A');//rend()ָ��ת���еĳ�β������-1��ָ��ת���е����һ��Ԫ�� 
				else//��λ 
					cout << (char)(*(i)+'A' - 1);
			}
		}

		cout << endl;
	}

	return 0;
}
#endif


//1.6 ������ 
//��������ʱ��Ĳ�ֵ 
#if 0
#include <iostream>
using namespace std;

bool runnian(int year);
int main()
{
	long minutes = 0;

	//����1922�굽2019��ķ����� 
	for (int year = 1922; year <= 2019; year++)
	{
		if (runnian(year))
		{
			cout << year << endl;
			minutes += 366 * 24 * 60;
		}
		else
			minutes += 365 * 24 * 60;
	}

	//1921��7��23������12ʱ��12��31�յ�ʱ�� 
	minutes += 9 * 24 * 60 - 12 * 60 + (31 + 30 + 31 + 30 + 31) * 24 * 60;
	//2020��1��1�յ�7��1������12ʱ��ʱ��
	minutes += (31 + 29 + 31 + 30 + 31 + 30) * 24 * 60 + 12 * 60;

	cout << minutes;

	return 0;
}
bool runnian(int year)
{
	bool status = 0;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		status = 1;

	return status;
}
#endif


//1.7 �ռ� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	//	//256MBת��ΪbitsΪ��λ   MB->KB->B->bits
	//	long cunchukongjian=256*1024*1024*8;
	//	
	//	long zhengshu=32;
	//	//***ע***[Warning] integer overflow in expression [-Woverflow]
	//�����������
	//	cout<<cunchukongjian/zhengshu;

		//***ע***Ҫʹ��ǿ������ת�� 
		//256MBת��ΪbitsΪ��λ   MB->KB->B->bits
	long long cunchukongjian = (long long)256 * (long)1024 * (long)1024 * 8;

	int zhengshu = 32;
	//[Warning] integer overflow in expression [-Woverflow]
	cout << cunchukongjian / zhengshu;
	return 0;
}
#endif


//1.8 ʱ����ʾ 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long haomiaoshu;
	cin >> haomiaoshu;

	long long miaoshu = haomiaoshu / 10;//***����1��Ӧ�õ���1000���� 

	int hour = (miaoshu / 60 / 60) % 24;

	//	miaoshu-=hour*3600;

	int minutes = (miaoshu / 60) % 60;

	//	miaoshu-=minutes*60;

	int second = miaoshu % 60;

	//***ע***coutʵ��ʱ���벻����λʱǰ����0���鷳�� 
	//������printf()��ת��˵�����η�ʵ��ǰ����0 
	cout << hour << ":" << minutes << ":" << second << endl;

	return 0;
}
#endif
//������ 
#if 0
#include <iostream>
#include <stdio.h> 

using namespace std;

int main()
{
	long long haomiaoshu;
	cin >> haomiaoshu;

	//ȥ���������� 
	haomiaoshu %= (24 * 60 * 60 * 1000);

	//ȥ�����룬����� 
	long long miaoshu = haomiaoshu / 1000;

	int hour = (miaoshu / 60 / 60) % 24;

	//�ɲ�д 
	//	miaoshu-=hour*3600;

	int minutes = (miaoshu / 60) % 60;

	//	miaoshu-=minutes*60;

	int second = miaoshu % 60;

	//������
	/*
	second=miaoshu%60;
	miaoshu/=60;
	minutes=miaoshu%60;
	miaoshu/=60;
	hour=miaoshu;
	*/

	//***ע***coutʵ��ʱ���벻����λʱǰ����0���鷳 
	//������printf()��ת��˵�����η�ʵ��ǰ����0 
	printf("%02d:%02d:%02d", hour, minutes, second);

	return 0;
}
#endif


//code2.cpp
//2.1 ģ�ⷨ 
//���ջ����������ֵ�ķ��� 
#if 0
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int>v1;

	int a, b;
	int c;
	while (cin >> a >> b)
	{
		c = a + b;
		v1.push_back(c);
	}

	int day = 0;
	int day1 = 0;
	int max = v1[0];
	vector<int>::iterator p;
	for (p = v1.begin(); p != v1.end(); p++)
	{
		day++;
		if (*p > max)
		{
			max = *p;
			day1 = day;
		}
	}

	if (max <= 8)
		cout << "����";
	else
		cout << "��" << day1 << "�������";

	return 0;
}
#endif


//2.2 �������� 
#if 0
#include <iostream>
#include <stdio.h> 
using namespace std;

int main()
{
	int diyibufen, dierbufen, disanbufen;

	char temp;
	cin >> diyibufen;
	cin >> temp;
	cin >> dierbufen;
	cin >> temp;
	cin >> disanbufen;

	//	cout<<diyibufen<<" "<<dierbufen<<" "<<disanbufen<<endl;

	printf("%d-%02d-%02d\n", 2000 + diyibufen, dierbufen, disanbufen);
	printf("%d-%02d-%02d\n", 2000 + disanbufen, diyibufen, dierbufen);
	printf("%d-%02d-%02d\n", 2000 + disanbufen, dierbufen, diyibufen);

	//***����***
	//û�г�����ú���Ŀ����
	//������������1960��1��1����2059��12��31�� 
	//Ҫ�󣺶�����ڰ����絽��˳������

	return 0;
}
#endif
//����
#if 0
#include <iostream>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct da
{
	int x, y, z, flag = 0;
}date[5];

int main()
{
	int y, m, d;
	char c;

	cin >> y >> c >> m >> c >> d;
	int num = 0;

	//��������ѭ�����������������ı��浽�ṹ�������У�
	//***ע***˳��������ĿҪ��Ĵ����ڴ�С�����˳��

	for (int nian = 1960; nian <= 2059; nian++)
	{

		if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
			mon[2] = 29;
		else mon[2] = 28;

		for (int yue = 1; yue <= 12; yue++)
		{
			for (int ri = 1; ri <= mon[yue]; ri++)
			{
				//������ѭ������ʱ�õ�������ƥ��������յ�����ʱ

				//�������������
				if (nian % 100 == y && m == yue && d == ri)
				{
					date[++num].x = nian;
					date[num].y = m;
					date[num].z = d;
				}

				//���������(y)��(m)��(d)
				if (nian % 100 == d && y == yue && m == ri)
				{
					date[++num].x = nian;
					date[num].y = y;
					date[num].z = m;
				}

				//���������(y)��(m)��(d)
				if (nian % 100 == d && m == yue && y == ri)
				{
					date[++num].x = nian;
					date[num].y = m;
					date[num].z = y;
				}

			}
		}

	}

	//ȥ�أ����ظ������ڱ��һ��
	for (int i = 1; i <= num; i++)
	{
		for (int j = i + 1; j <= num; j++)
		{
			if (date[i].x == date[j].x &&
				date[i].y == date[j].y &&
				date[i].z == date[j].z)

				date[j].flag = 1;
		}
	}

	//�������
	for (int i = 1; i <= num; i++)
		if (!date[i].flag)
			printf("%d-%02d-%02d\n", date[i].x, date[i].y, date[i].z);
	return 0;
}
#endif 
//ʹ��set�������� 
#if 0
#include <iostream>
#include <set>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

typedef struct a  //***ע***a���ܲ�д����Ϊ�ᵼ�±���
{
	int x, y, z;
}RiQiTypeDef;

//������Ԫ��operator��:��type*����������������Ԥ����������ɽ������͵�ת��
//ԭ��ʹ���Զ���ļ�ʱ��Ҫ����<�����
//***const����д***
bool operator<(const RiQiTypeDef&, const RiQiTypeDef&);

int main()
{
	int y, m, d;
	char c;

	cin >> y >> c >> m >> c >> d;
	int num = 0;

	//��������ѭ�����������������ı��浽�ṹ�������У�
	//***ע***˳��������ĿҪ��Ĵ����ڴ�С�����˳��

	RiQiTypeDef RiQiStruct;
	set<RiQiTypeDef>RiQiSet;

	for (int nian = 1960; nian <= 2059; nian++)
	{

		if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
			mon[2] = 29;
		else mon[2] = 28;

		for (int yue = 1; yue <= 12; yue++)
		{
			for (int ri = 1; ri <= mon[yue]; ri++)
			{
				//������ѭ������ʱ�õ�������ƥ��������յ�����ʱ

				//�������������
				if (nian % 100 == y && m == yue && d == ri)
				{
					RiQiStruct.x = nian;
					RiQiStruct.y = m;
					RiQiStruct.z = d;
					RiQiSet.insert(RiQiStruct);
				}

				//���������(y)��(m)��(d)
				if (nian % 100 == d && y == yue && m == ri)
				{
					RiQiStruct.x = nian;
					RiQiStruct.y = y;
					RiQiStruct.z = m;
					RiQiSet.insert(RiQiStruct);
				}

				//���������(y)��(m)��(d)
				if (nian % 100 == d && m == yue && y == ri)
				{
					RiQiStruct.x = nian;
					RiQiStruct.y = m;
					RiQiStruct.z = y;
					RiQiSet.insert(RiQiStruct);
				}

			}
		}

	}

	//ȥ�أ����ظ������ڱ��һ��
//    for (int i = 1; i <= num; i++)
//    {
//        for (int j = i + 1; j <= num; j++)
//        {
//            if (date[i].x == date[j].x && 
//                date[i].y == date[j].y && 
//                date[i].z == date[j].z)
//
//                date[j].flag = 1;
//        }
//    }

	//�������
	for (auto p = RiQiSet.begin(); p != RiQiSet.end(); p++)
	{
		printf("%d-%02d-%02d\n", p->x, p->y, p->z);
	}
	return 0;
}

bool operator<(const RiQiTypeDef& RiQiStruct1, const RiQiTypeDef& RiQiStruct2)
{
	bool status = 0;

	if (RiQiStruct1.x < RiQiStruct2.x)
		status = 1;
	else if (RiQiStruct1.x == RiQiStruct2.x &&
		RiQiStruct1.y < RiQiStruct2.y)
		status = 1;
	else if (RiQiStruct1.x == RiQiStruct2.x &&
		RiQiStruct1.y == RiQiStruct2.y &&
		RiQiStruct1.z < RiQiStruct2.z)
		status = 1;

	return status;
}
#endif 


//2.3 REPEAT���� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	//	cin>>num;

	for (int i = 0; i < 2; i++)
	{
		num += 4;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 6; k++)
				num += 5;
			num += 7;
		}
		num += 8;
	}
	num += 9;

	cout << num;
	//***����***
	//prog.txt�ļ����г����ĳ���ƪ�����޷�ͨ�������ĳ�����⡣ 

	return 0;
}
#endif
//������ 
//ʹ��ջ���� 
#if 0
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	int space;
	int zongxunhuanshu = 1;
	int result = 0;

	freopen("2.3.txt", "r", stdin);

	stack<int> xunhuancishu_stack;
	stack<int> kongbaizifushu_stack;

	xunhuancishu_stack.push(1);//����Ϊ0������ѭ����Ϊ1 
	kongbaizifushu_stack.push(-1);//ѡһ��������ֵ0��ҪС�������˴�ѡ-1 

	string st;
	getline(cin, st);//��ȡ��������

	while (getline(cin, st))
	{
		//����ո����� 
		space = 0;
		while (st[space] == ' ')
			space++;

		//���ݴ洢�հ��ַ�����ջ�ж��Ƿ�Ҫ����ѭ��
		//***ע***Ҫ��while��� 
		while (space <= kongbaizifushu_stack.top())
		{
			zongxunhuanshu /= xunhuancishu_stack.top();
			xunhuancishu_stack.pop();
			kongbaizifushu_stack.pop();
		}

		//�ж��Ƿ���REPEAT��� 
		if (st[st.size() - 1] == ':')
		{
			int xunhuanshu = st[st.size() - 2] - '0';
			zongxunhuanshu *= xunhuanshu;

			xunhuancishu_stack.push(xunhuanshu);
			kongbaizifushu_stack.push(space);
		}
		else//������REPEAT��� 
		{	//Ҫ���ϵ��� 
			int jiashu = st[st.size() - 1] - '0';
			result += jiashu * zongxunhuanshu;
		}

	}

	cout << result;

	return 0;
}
#endif


//2.4 �������� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num = 0;

	cin >> num;

	if (num % 2 != 0)
		return 0;

	while (num >= 1)
	{
		cout << num << " ";
		num /= 2;
	}
	//�����������������<<��ÿ�γ��Զ��൱������һλ�����λ���Ƿ���������0��1 
	return 0;
}
#endif


//2.5 ���� 
#if 0
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin >> str;

	char data[500][2];

	for (int i = 0; i < 100; i++)
	{
		data[i][0] = '\0';
		data[i][1] = '\0';
	}

	int i = 0;
	int j = 0;
	for (int index = 0; index < str.size(); index++)
	{
		if (isdigit(str[index]))
			continue;

		data[i][0] = str[index];

		if (isdigit(str[index + 1]))
			data[i][1] = str[index + 1];
		else
			data[i][1] = '1';

		i++;
	}

	//��ʾ���������		
	//	for(int i=0;i<100;i++)
	//	{
	//		cout<<data[i][0]<<" ";
	//		cout<<data[i][1]<<endl;
	//	}

	i = 0;
	while (1)
	{				//***ע***char��ת��Ϊint�� 
		for (int cishu = data[i][1] - '0'; cishu > 0; cishu--)
			cout << data[i][0];

		i++;

		if (data[i][0] == '\0')
			break;
	}

	return 0;
}
#endif


//2.6 ����ƴ�� 
#if 0
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int CheckNumber(int num);

int main()
{
	int n;
	cin >> n;
	int* shuzu1 = new int[n];//��������� 
	int* shuzu2 = new int[(n - 1 + 1) * (n - 1)];//ƴ�Ӻú������ 

	int k;
	cin >> k;

	int index = 0;
	int n1 = n;
	do
	{
		cin >> shuzu1[index++];
		n1--;
	} while (n1);


	int temp = 0;
	int m = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = shuzu1[i] * pow(10, CheckNumber(shuzu1[j])) + shuzu1[j];
			shuzu2[m++] = temp;
			temp = shuzu1[j] * pow(10, CheckNumber(shuzu1[i])) + shuzu1[i];
			shuzu2[m++] = temp;
		}
	}

	//��ʾ���������		
	//	for(int i=0;i<(n-1+1)*(n-1);i++)
	//	cout<<shuzu2[i]<<" ";

		//���� 
		//***ע*** 
		//ʹ��set��������ȥ���ظ���ֵ 
	set<int>shuzi_set;
	for (int i = 0; i < (n - 1 + 1) * (n - 1); i++)
		shuzi_set.insert(shuzu2[i]);

	int geshu = 0;
	for (auto p = shuzi_set.begin(); p != shuzi_set.end(); p++)
		(*p % k == 0) ? geshu++ : geshu;

	cout << geshu;

	return 0;
}

int CheckNumber(int num)
{
	int weishu = 0;
	for (int num1 = num; num1; )
	{
		//��numΪһλʱ ѭ������һ�� ��numΪ��λʱ ���� ,��λʱ ����
		num1 = num1 / 10;
		weishu++;								//ѭ������һ��,λ����һ
	}
	//	cout<< weishu;
	return weishu;
}
//��������
//4 2
//1 2 3 4 
//5 2
//1 12 123 1234 12345
#endif


//2.7 ��Ƭ 
#if 0
#include <iostream>
#include <vector>
#include <stdio.h>//sprintf() 
using namespace std;

void meiweideshuzi(vector<int>&, int num);
int main()
{
	vector<int> data[10];

	for (int i = 0; i < 10; i++)
	{
		data[i].push_back(i);
		data[i].push_back(2021);
	}

	//��ʾ�������� 
	//	for(int i=0;i<10;i++)
	//	{
	//		cout<<data[i][0]<<" "<<data[i][1];
	//		cout<<endl;
	//	}

	vector<int> shuzi;

	//Ҫƴ������ 
	int pindezhengshu = 1;
	int result;

	while (1)
	{
		meiweideshuzi(shuzi, pindezhengshu);

		for (auto p = shuzi.begin(); p != shuzi.end(); p++)
			for (int i = 0; i < 10; i++)
				if (*p == data[i][0])
				{
					if (data[i][1])
						data[i][1]--;
					else
					{
						result = pindezhengshu - 1;
						goto step1;
					}
				}

		pindezhengshu++;
	}

step1:cout << result;

	return 0;
}

//����ÿλ�ϵ����� 
void meiweideshuzi(vector<int>& data, int num)
{
	//	int num1=num;
	//	int weishu=0;
	//	do
	//	{
	//		num1/=10;
	//		weishu++;
	//	}while(num1);

	//***ע***���������ַ���	
	//��һ��ѭ����ȡ�� 
	// data.clear();
	//	while(num)
	//	{					//***ע***Ҫ���뵽ͷ�� 
	//		data.insert(data.begin(),num%10);
	//		num/=10;	
	//	}
	//	for(auto p=data.begin();p!=data.end();p++)
	//		cout<<*p<<" ";
	//������ʹ��sprintf()ֱ�ӽ�����ת��Ϊ�ַ�����
	//Ȼ�����ѡ�����ַ�����ʽ�����Ҳ����ѡ����int�������ÿλ������ 
	char str[100] = { '\0' };
	sprintf(str, "%d", num);

	int index = 0;
	int weishu = 0;
	while (str[index++])
	{
		weishu++;
	}

	//������ 
	//***ע***��ÿ�ε��ô˺���ʱ��vector���鶼Ҫ�Ȼָ���ʼ״̬ 
	data.clear();
	for (index = 0; index < weishu; index++)
		data.push_back(str[index] - '0');

	//	for(auto p=data.begin();p!=data.end();p++)
	//		cout<<*p<<" ";
}
#endif


//2.8 ������� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long yanghui[100][100];

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			yanghui[i][j] = 0;

	yanghui[0][0] = 1;
	yanghui[1][0] = yanghui[1][1] = 1;
	for (int i = 2; i < 100; i++)//�ӵ����㿪ʼ 
	{
		yanghui[i][0] = yanghui[i][i] = 1;
		for (int j = 1; j <= i - 1; j++)
			yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
	}

	//	for(int i=0;i<100;i++)
	//	{
	//		for(int j=0;j<100;j++)
	//			if(yanghui[i][j]!=0)
	//				cout<<yanghui[i][j]<<" ";
	//		cout<<endl;
	//	}

	int jishu = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (yanghui[i][j] == 0)
				continue;

			++jishu;
			if (yanghui[i][j] == N)
				goto step;
		}
	}

step:cout << jishu;

	return 0;
}
#endif


//code3.cpp
//3.1 ö�ٷ� 
//��ʵ��Ӧ����Ҫ�������ٱ����ĸ����Լ������Ŀռ䣬
//�����㷨��ʱ�临�Ӷ� 
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//4x+7y=1000000
	int x;
	//	int y[5000]={0};  ����� 
	vector<int>y;
	int temp;
	int index = 0;
	for (x = 250000; x; x--)
	{
		temp = (1000000 - 4 * x) / 7.0;//***ע***.0Ҫд���漰����֪ʶ���ǲ�ͬ���͵�ֵ������������ʱ������е�ת�� 
		if ((1000000 - 4 * x) / 7.0 > temp)//��temp�Ǹ�С�� 
			continue;

		y.push_back(temp);
	}

	for (auto p = y.begin(); p != y.end(); p++)
		cout << *p << ' ';

	return 0;
}
#endif


//3.2 �Ȳ��������� 
#if 0
#include <iostream>
#include <vector>
using namespace std;

bool sushu(long num);
int main()
{
	vector<long> num_vector;

	for (long num = 2; num < 50000; num++)
		if (sushu(num))
			num_vector.push_back(num);

	//	for(auto p=num_vector.begin();p!=num_vector.end();p++)
	//	cout<<*p<<" ";

	int gongcha = 1;
	int k = 1;
	int shuliechangdu;

	//�ӵ�һ�ʼ�� 
	for (auto p = num_vector.begin(); p != num_vector.end(); p++)
	{
		//�����������Ϊ1 
		shuliechangdu = 1;
		k = 1;
		gongcha = 1;

		//***�޸Ľ���***
		//�ѹ��������ѭ������ѭ��������� 
		while (gongcha < 1000)
		{
			//�����������Ϊ1 
			shuliechangdu = 1;
			k = 1;

			//�������pָ���Ԫ�ؿ�ʼ�� 
			for (auto q = p; q != num_vector.end(); q++)
				if ((*p) + gongcha * k == *q)//�����1��ʼ�� 
				{
					shuliechangdu++;

					if (shuliechangdu == 10)
						goto conclusion;

					k++;
					continue;
				}

			//������1 
			gongcha++;
		}
	}

conclusion:cout << gongcha;

	return 0;
}

bool sushu(long num)
{
	bool status = 1;

	for (long i = 2; i < num; i++)
	{
		if (num % i == 0)
			status = 0;
	}

	return status;
}
#endif
//������ 
//�ð���ɸѡ������Ȳ����и����ֵ�Ĺ�ʽ 
#if 0
#include <iostream>
using namespace std;

void shengchengsushu(void);
bool ok(int n, int gongcha);

bool flag[10000];
int main()
{
	shengchengsushu();

	for (int gongcha = 2; ; gongcha++)
	{
		for (int qishizhi = 2; qishizhi < 10000; qishizhi++)
		{
			if (flag[qishizhi] && ok(qishizhi, gongcha))
			{
				cout << gongcha;
				return 0;//***ע***��������д���滻��goto��� 
			}
		}
	}

	return 0;
}

void shengchengsushu(void)
{
	//flag�����ʼ�� 
	for (int i = 0; i < 10000; i++)
		flag[i] = 1;

	//���������ֵ�������������е�Ԫ�أ��������д�2��ʼ 
	for (int i = 2; i < 10000; i++)
	{
		if (flag[i])
			for (int j = i + i; j < 10000; j += i)
				flag[j] = 0;
	}
}

//�ж��Ƿ����㳤��Ϊ10�ĵȲ���������
//���е���ʼֵn�����еĹ���gongcha
bool ok(int n, int gongcha)
{
	for (int i = 0; i < 10; i++)
		if (!flag[n + i * gongcha])
			return 0;

	return 1;//***ע***����ֱ�ӷ���0��1�����������ı����� 
}
#endif


//3.3 �˻�β�� 
#if 0
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("3.3.txt", "r", stdin);

	int count = 0;

	long temp;
	long long result = 1;

	char shuzu[100] = { '\0' };
	char shuzu2[100] = { '\0' };
	int index2 = 0;
	int weishu;

	for (int i = 0; i < 100; i++)
	{
		cin >> temp;
		result *= temp;

		//***ע*** 
		//����ת�����ַ���
		//��һ��		
		//		sprintf(shuzu,"%d",result);
		//������
		//itoa ������һ����׼��C����������Windows���еģ����Ҫд��ƽ̨�ĳ�������sprintf 
		//���⣬����atoi()��atof()��ʵ�õ�ת������
		itoa(result, shuzu, 10);

		//��resultΪ8800 
		//����Ҫ������λ�� 	
		weishu = 1;	//***ע***�����������for��int index=0����for���е�weishu����Ӱ��for�����weishu ��P108
		for (int index = 0; shuzu[index]; index++)
		{
			if (shuzu[index] == '0')
				weishu++;
		}

		//����result���ֵĳ��� 
		int changdu = 0;
		for (int index = 0; shuzu[index]; index++)
		{
			if (shuzu[index] != '\0')
				changdu++;
		}

		//weishuΪ3��������������λ��
		//***ע***shuzu2Ҫ����������� 
		for (int i = 0; i < 100; i++)
		{
			shuzu2[i] = '\0';
		}

		for (int index = 0; index != weishu; index++)
		{
			shuzu2[index] = shuzu[changdu - weishu + index];
		}

		//result����Ϊ800 
		result = atoi(shuzu2);

		if (result / 10 == result / 10.0)
		{
			count++;
			result /= 10;
		}
	}

	cout << count;

	//***����***
	//1.����ÿ���������֮���ֵ��0�ص�����ôֵ����
	//���ǻᳬ��long long�ܱ�ʾ�����Χ 
	//2.��������������������������������������λ����ô���
	//���ǲ���ȷ

	return 0;
}
#endif
//���� 
//��ÿ���������֮���ֵ��0�ص������Ұ�ֵʼ�ձ�����8λ�� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long temp, result = 1;
	int zero = 0;

	freopen("3.3.txt", "r", stdin);

	for (int i = 0; i < 100; i++)
	{
		cin >> temp;
		result *= temp;

		while (result % 10 == 0)
		{
			result /= 10;
			zero++;
		}

		result %= 100000000;//resultʼ�ձ�����8λ�� 
	}
	cout << zero;

	return 0;
}
#endif


//3.4 ���ķֽ� 
#if 0
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>//STL��sort() 
using namespace std;

typedef struct s
{
	int x;
	int y;
	int z;
}fenjieTypeDef;

bool operator<(const fenjieTypeDef&, const fenjieTypeDef&);

//set�������϶�Ԫ�ؽ����Զ�����ʱ�����õ�==����� 
//bool operator==(const fenjieTypeDef&,const fenjieTypeDef&);

int main()
{
	int i, j, k;

	fenjieTypeDef fenjieStruct;
	set<fenjieTypeDef> num_set;
	vector<int> v1;

	//����1��
	//�ж�һ�������Ƿ�2��4 
	char erhuosi[10] = { '\0' };

	const int NUM = 2019;
	for (i = 1; i < NUM; i++)
		for (j = 1; j < NUM; j++)
			for (k = 1; k < NUM; k++)
				if (i + j + k == NUM && i != j && i != k && j != k)//����2��������ͬ�������� 
				{
					//������⣺ 
					//					if(i==2||j==2||k==2||i==4||j==4||k==4)
					//						continue;

										//ÿ���������Ƿ�����2��4�ı��					
					int biaoji = 0;

					itoa(i, erhuosi, 10);
					for (int i = 0; erhuosi[i]; i++)
						if (erhuosi[i] == '2' || erhuosi[i] == '4')
							biaoji = 1;

					itoa(j, erhuosi, 10);
					for (int i = 0; erhuosi[i]; i++)
						if (erhuosi[i] == '2' || erhuosi[i] == '4')
							biaoji = 1;

					itoa(k, erhuosi, 10);
					for (int i = 0; erhuosi[i]; i++)
						if (erhuosi[i] == '2' || erhuosi[i] == '4')
							biaoji = 1;

					if (biaoji)
						continue;

					//ÿ�ν���ʱv1��Ҫ������� 
					v1.clear();

					v1.push_back(i);
					v1.push_back(j);
					v1.push_back(k);

					//����(��vector����ʹ��sort()) 
					sort(v1.begin(), v1.end());

					//�����򸳸�x,y,z 
					fenjieStruct.x = v1[0];
					fenjieStruct.y = v1[1];
					fenjieStruct.z = v1[2];

					//�Զ�ɾ���ظ���(����set��������) 
					num_set.insert(fenjieStruct);
				}

	//	int count=0;			
	//	for(auto p=num_set.begin();p!=num_set.end();p++)
	//	{	
	//		cout<<p->x<<" "<<p->y<<" "<<p->z<<endl;
	// 		count++;
	//	 }

	cout << endl << num_set.size() << endl;

	return 0;
}
bool operator<(const fenjieTypeDef& f1, const fenjieTypeDef& f2)
{
	bool b = 0;

	if (f1.x < f2.x)
		b = 1;
	else if (f1.x == f2.x && f1.y < f2.y)
		b = 1;
	else if (f1.x == f2.x && f1.y == f2.y && f1.z < f2.z)
		b = 1;

	return b;
}
//bool operator==(const fenjieTypeDef& f1,const fenjieTypeDef& f2)
//{
//	set<int> s1;
//	set<int> s2;
//	
//	s1.insert(f1.x);
//	s1.insert(f1.y);
//	s1.insert(f1.z);
//
//	s2.insert(f2.x);
//	s2.insert(f2.y);
//	s2.insert(f2.z);
//	
//	if(s1==s2)
//	return 1;
//	else
//	return 0;
//}
#endif
//������ 
#if 0
#include <iostream>

using namespace std;

bool judge(int);
int main()
{
	int count = 0;

	//ͨ���������������ѭ������ʼֵ�ͺ���ֵֹ��������������ظ�
	//i,j,2019-i-j���������������ʽ����

	//	for(int i=1;i<2019/3+1;i++)
	//		if(judge(i))				
	//			for(int j=i+1;j<2019-i-j;j++)
	//				if(judge(j))
	//					if(judge(2019-i-j))
	//						count++;

		//Ҳ����д��				
	for (int i = 1; i < 2019; i++)
		if (judge(i))
			for (int j = i + 1; j < 2019 - i - j; j++)
				if (judge(j))
					if (judge(2019 - i - j))
						count++;

	cout << count;

	return 0;
}
bool judge(int num)
{
	while (num)
	{
		if (num % 10 == 2 || num % 10 == 4)//��num�����λ��ʼ�ж��Ƿ�������2��4 
			return 0;

		num /= 10;
	}

	return 1;
}
#endif


//3.5 �ر���֮�� 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long num;
	cin >> num;

	bool flag = 0;
	long long result = 0;
	for (int i = 1; i <= num; i++)
	{
		long long temp = i;
		flag = 0;
		while (temp)
		{
			if (temp % 10 == 2 || temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 9)
				flag = 1;

			temp /= 10;
		}

		if (flag)
			result += i;
	}

	cout << result << endl;

	return 0;
}
#endif
//������ 
#if 0
#include <iostream>
#include <vector>  
#include <algorithm>//STL��find()���� 

using namespace std;

bool judge(long);
int main()
{
	long long num;
	cin >> num;

	long long result = 0;
	for (int i = 1; i <= num; i++)
	{
		if (judge(i))
			result += i;
	}

	cout << result << endl;

	return 0;
}
bool judge(long num)
{
	char shuzi[10] = { '\0' };
	itoa(num, shuzi, 10);

	vector<char> shuzi2;
	for (int index = 0; shuzi[index]; index++)
		shuzi2.push_back(shuzi[index]);

	//д��һ��		
	//	for(auto p=shuzi2.begin();p!=shuzi2.end();p++)
	//		if(*p=='2'||*p=='0'||*p=='1'||*p=='9')
	//			return 1;

	//д������ 
	char ch[4] = { '2','0','1','9' };
	for (int index = 0; index < 4; index++)
		if (find(shuzi2.begin(), shuzi2.end(), ch[index]) != shuzi2.end())
			return 1;

	return 0;
}
#endif


//3.6 ��ȫ��������Ȩֵ 
#if 0
#include <iostream>
#include <cmath>
//#include <valarray>
using namespace std;

typedef int SqBiTree[100];//SqBiTree��˳��洢�ṹ�Ķ��������� 

bool InitBiTree(SqBiTree T);
bool CreateBiTree(SqBiTree T);

int num;

int main()
{
	SqBiTree T;
	InitBiTree(T);

	CreateBiTree(T);

	int deep;
	deep = log2(num) + 1;//***ע***n���ڵ�����ȹ�ʽ 

	//����һ�����飬���ڴ�ÿ���Ԫ��֮�� 
	int* p = new int[deep];

	//�����ʼ��Ϊ0 
	for (int i = 0; i < deep; i++)
		p[i] = 0;

	int d = deep;

	for (int i = 1; i <= d; i++)//�ڼ��� 
		for (int j = pow(2, i - 1) - 1; j <= pow(2, i - 1) - 1 + pow(2, i - 1) - 1; j++)
			*(p + i - 1) += T[j];

	//����Ѱ�������е����ֵ��Ӧ������ֵ������ֵ+1���ǲ��(���)		
	int max = p[0];
	int result = 1;
	for (int i = 0; i < deep; i++)
		if (p[i] > max)
		{
			max = p[i];
			result = i + 1;
		}

	cout << result;

	return 0;
}

bool InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < 100; i++)
		T[i] = 0; /* ��ֵΪ�� */

	return 1;
}
bool CreateBiTree(SqBiTree T)
{
	cin >> num;

	for (int index = 0; index < num; index++)
		cin >> T[index];
}
//���ԣ�
//7
//1 6 5 4 3 2 1 
#endif


//3.7 �Ȳ����� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int size;
	cin >> size;

	vector<long long> shuzu(size);
	long long temp;
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		shuzu[i] = temp;
	}

	sort(shuzu.begin(), shuzu.end());

	//	for(int i=0;i<size;i++)
	//		cout<<shuzu[i];

	long long gongcha = shuzu[1] - shuzu[0];

	long long min = shuzu[0];
	long long max = shuzu[0];
	for (int i = 0; i < size; i++)
	{
		if (shuzu[i] > max)
			max = shuzu[i];
		if (shuzu[i] < min)
			min = shuzu[i];
	}

	cout << (max - min) / gongcha + 1;

	return 0;
}
#endif


//3.8 �ܲ�ѵ�� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	int energy = 10000;

	int seconds = 0;
	while (1)
	{
		energy -= 10;
		seconds++;

		if (energy <= 0)
			break;

		energy += 5;
		seconds++;
	}
	//***�������Ϊ����һ������Ϣһ���� 
	cout << seconds;

	return 0;
}
#endif
//���� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	int energy = 10000;

	int seconds = 0;
	while (1)
	{
		if (energy >= 600)
		{
			energy -= 600;
			seconds += 60;
		}
		else//������С��600ʱ 
		{
			seconds += energy / 10;//(����ÿ���½�10��)
			break;
		}

		energy += 300;
		seconds += 60;
	}

	cout << seconds;

	return 0;
}
#endif


//3.9 �ϲ���� 
#if 0
#include <iostream>
#include <valarray>
//#include <algorithm>

using namespace std;
int main()
{
	long zongrenshu = 10000;
	int ganranrenshu = 10000 * 0.01;
	int k = 2;//2�˻�� 
	int k1 = 0;

	valarray<long> data(998);
	int index = 0;

	char ch[10] = { '\0' };

	for (; k <= 1000; k++, k1 = 0)
	{
		int temp = zongrenshu / k;//��һ��ɸ��ʱ���˼����Լ��� 
		k1 += temp;

		int temp2;
		//����д��1�� itoa��int to a��ֻ֧������ת�����ַ��� 
		//		itoa(temp*0.01,ch,10);

		//����д��2�� 
		//		sprintf(ch,"%f",temp*0.01);//��ʹ��������Ҳ�������ֺ��㣬��50.000000 
		//		cout<<ch;
		//		if(find(ch,ch+10,'.')!=ch+10)//�ж��Ƿ���С�� 
		//			temp2=temp*0.01+1;//��һ�����������Լ�����		
		//		else
		//			temp2=temp*0.01;

		if (temp * 0.01 > int(temp * 0.01))
			temp2 = temp * 0.01 + 1;//��һ�����������Լ�����		
		else
			temp2 = temp * 0.01;

		k1 += temp2 * k;//k1�ټ��ϵڶ���ɸ��ʱҪ�õ��Լ����� 

		data[index++] = k1;
	}

	for (int index = 0; index < 998; index++)
		cout << data[index] << " ";

	cout << endl << data.min() << endl;

	int result;
	for (int index = 0; index < 998; index++)
		if (data[index] == data.min())
			result = index;

	cout << "����ֵ��" << result;//�õ���           10000���ˣ�110���˻�����ʡ�Լ��У�Ϊ200�� 

//***����***
//�����Ĳ�ͬ����Ӱ�����ģ��õ����Լ�����Сֵ 
//***���� 
//û�п�������10000����3�˻�ܵ����Ҫȥ�� 

	return 0;
}
#endif
//���� 
#if 0
#include <iostream>
#include <valarray>
#include <map> 
//#include <iterator>
using namespace std;
int main()
{
	long zongrenshu = 100;
	int k = 2;//2�˻�� 
	int k1 = 0;

	map<long, long> data_map;

	for (; k <= 100; k++, k1 = 0)
	{
		int temp = zongrenshu / k;//��һ��ɸ��ʱ���˼����Լ��� 

		//����Ƿ����� 
		if (zongrenshu / (double)k > temp)
			continue;

		k1 += temp;

		int temp2;
		//�ټ���Ƿ����� 
		if (temp * 0.01 > int(temp * 0.01))
			temp2 = temp * 0.01 + 1;//��һ�����������Լ�����		
		else
			temp2 = temp * 0.01;

		k1 += temp2 * k;//k1�ټ��ϵڶ���ɸ��ʱҪ�õ��Լ����� 

		//��map�д����ݷ���һ�� 
		//***�����ʾ��***
		data_map[k] = k1;
		//�������� 
//		data_map.insert(pair<long,long>(k,k1));
	}

	//***map���������ı�������***
	for (auto p = data_map.begin(); p != data_map.end(); p++)
	{
		cout << p->first << ' ' << p->second << endl;
	}

	//Ѱ���Լ��������ٵ�����
	map<long, long>::iterator di;
	di = data_map.begin();
	long min = di->second;
	for (auto p = data_map.begin(); p != data_map.end(); p++)
	{
		if (p->second < min)
		{
			min = p->second;
			di = p;//�ݴ�p��ֵ 
		}
	}

	cout << endl << di->first << " " << min;

	//***����***ֻ��ͨ������Ѱ��Ԫ�أ�������ͨ��Ԫ����Ѱ�Ҽ�	
	//	auto search = data_map.find(min);
	//   if (search != data_map.end()) 
	//	{
	//      cout << "Found " << search->first << " " << search->second << '\n';
	//   }

	return 0;
}
#endif


//3.10 ֱ�� 
//***˼·***
//����Ax+By+C=0�ܱ�ʾ����ֱ��(������ֱ��x���ֱ��)
//��������ֱ�ߵ�����ʽ�Ƴ�A��B��C��Ӧ�ı��ʽ 
#if 0
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

//�����Լ��(A��B��C������ͬʱ����һ����0�ı�����
//���Ǳ�ʾͬһ��ֱ�ߣ����������set�޷�ȥ��)
int measure(int, int);

using namespace std;
int main()
{
	int x, y;//����ķ�Χ 
	cin >> x >> y;

	pair<int, int> pa;
	vector<pair<int, int>>v;//�������ΪԪ�أ�����vector���� 
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			pa.first = i;
			pa.second = j;
			v.push_back(pa);
		}

	pair<pair<int, int>, int> pa2;
	set<pair<pair<int, int>, int>>s;//�ô����������¶���<��������غ��� 
	//������һ���ṹ���֣���3������ 
	//set<jiegou_TypeDef>s;

	for (int i = 0; i < v.size(); i++)//ȡһ���� 
		for (int j = i + 1; j < v.size(); j++)//ȡ��һ���� 
		{
			int x1 = v[i].first;
			int y1 = v[i].second;
			int x2 = v[j].first;
			int y2 = v[j].second;

			int A = y2 - y1;
			int B = x1 - x2;
			int C = x2 * y1 - x1 * y2;

			int gongyueshu = measure(measure(A, B), C);

			pa.first = A / gongyueshu;
			pa.second = B / gongyueshu;
			pa2.first = pa;
			pa2.second = C / gongyueshu;

			s.insert(pa2);
		}

	cout << s.size();

	return 0;
}

int measure(int a, int b)
{
	//	if (b==0)
	//		return a;
	//	else 
	//	   return measure(b,a%b); 

		//������algorithmͷ�ļ��а�����__gcd() 
	return __gcd(a, b);

	//���䣺��С������=�����˻�/���Լ��
}
/* շת�������������ԭ��
   �������������Լ���������н�С��������������������������Լ��
	��y��x%y�������Ϊ0����y���������Լ��
   ���䣺����������С����������  x*y/measure(x,y);
*/
#endif


//3.11 ����ڷ� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num = 2021041820210418;

	long long count = 0;
	//	for(int i=1;i<=num;i++)
	//		for(int j=1;j<=num;j++)
	//			for(int k=1;k<=num;k++)
	//			{
	//				if(i*j*k==2021041820210418)
	//				count++;
	//			}

	for (long long i = 1; i <= num; i++)
		for (long long j = 1; j <= num; j++)
		{
			long long k = num / i / j;

			if (k > num || k<1 || ((double)num / i / j)>k)
				continue;
			else
			{
				cout << i << ' ' << j << ' ' << k << ' ' << endl;
				count++;
			}

		}
	//***����***
	//���س�ʱ 

	cout << count;

	return 0;
}
#endif
//���� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num = 2021041820210418;

	long long count = 0;

	//���num�����ӣ����������� 
	long long a[1000] = { 0 };

	//***����֪ʶ***
	//��num�����ӵļ���ΪA��
	//��a*b*c=num��a��b��c�����Լ���A 

	int index = 0;
	for (long long i = 1; i * i <= num; i++)
	{
		if (num % i == 0)//��i������ 
		{
			a[index++] = i;

			//***ע***����������д 
			if (num / i != i)
				a[index++] = num / i;//����num/i�����ӵĽϴ��� 
		}
	}

	cout << "index=" << index << endl;

	for (int i = 0; i < index; i++)
		for (int j = 0; j < index; j++)
			for (int k = 0; k < index; k++)
			{
				if (a[i] * a[j] * a[k] == num)
					count++;
			}

	cout << count;

	return 0;
}
#endif
//������ʹ��set�������� 
#if 0
#include <iostream>
#include <set>

using namespace std;
int main()
{
	long long num = 2021041820210418;

	long long count = 0;

	//���num�����ӣ����������� 
	set<long long>a;

	//***����֪ʶ***
	//��num�����ӵļ���ΪA��
	//��a*b*c=num��a��b��c�����Լ���A 

	int index = 0;
	for (long long i = 1; i * i <= num; i++)
	{
		if (num % i == 0)//��i������ 
		{
			a.insert(i);//���㵽900000009���������ʱ��ǳ��� 
//							//���Բ���Ҫi*i<num��һ�ж����� 
			a.insert(num / i);
		}
	}

	for (auto p = a.begin(); p != a.end(); p++)
		cout << *p << endl;

	for (auto i = a.begin(); i != a.end(); i++)
		for (auto j = a.begin(); j != a.end(); j++)
			for (auto k = a.begin(); k != a.end(); k++)
			{
				if ((*i) * (*j) * (*k) == num)
					count++;
			}

	cout << count;

	return 0;
}
#endif


//code4.cpp
//4.1 ���ƺ͵ݹ� 
#if 0
#include <iostream>

using namespace std;
int ditui(int n);
int digui(int n);
int main()
{
	int n;
	cin >> n;

	int result1 = ditui(n);
	int result2 = digui(n);

	cout << result1 << endl << result2 << endl;

	return 0;
}
int ditui(int n)
{
	int arr[100] = { 0 };

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	return arr[n];
}
int digui(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	return digui(n - 1) + digui(n - 2);
}
#endif


//4.2 ��ѹ���� 
#if 0
#include <iostream>
#include <valarray>
#include <cmath>
#include <stdio.h>

using namespace std;
int main()
{
	freopen("4.2.txt", "r", stdin);

	double data_jinzita[30][30];

	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			data_jinzita[i][j] = 0.0;

	int temp;
	for (int i = 0; i < 29; i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;
			data_jinzita[i][j] = temp;
		}

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
			cout << data_jinzita[i][j] << " ";
		cout << endl;
	}

	//***����***
	//ֱ����double�������ʹ洢����2֮���ֵ�����������
	//��һ������ֵ���ײ��൱��Ҫ����2��29�η���double�ﲻ���˾��� 

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j <= i; j++)
			data_jinzita[i][j] *= pow(2, 29);//����	
	}

	data_jinzita[1][0] += data_jinzita[0][0] / 2.0;
	data_jinzita[1][1] += data_jinzita[0][0] / 2.0;

	//	�ӵ����㿪ʼ���ֿ�����������������ֺͽ������ڵ����� 
	for (int i = 2; i < 30; i++)
	{
		//������������������ 
		data_jinzita[i][0] += data_jinzita[i - 1][0] / 2.0;
		data_jinzita[i][i] += data_jinzita[i - 1][i - 1] / 2.0;
		for (int j = 1; j <= i - 1; j++)
		{
			//***����λ�ô���*** 
			//			data_jinzita[i][0]+=data_jinzita[i-1][0]/2.0;
			//			data_jinzita[i][i]+=data_jinzita[i-1][i-1]/2.0; 				

						//����������ڵ�����			
			data_jinzita[i][j] += data_jinzita[i - 1][j - 1] / 2.0 + data_jinzita[i - 1][j] / 2.0;

		}
	}

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
			cout << data_jinzita[i][j] << " ";
		cout << endl;
	}

	valarray<double> a(30);
	for (int i = 0; i < 30; i++)
		a[i] = data_jinzita[29][i];

	cout << endl << a.min() << endl << a.max() << endl;

	printf("%.2f", a.max());
	return 0;
}
#endif


//4.3 ȡ��λ 
#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

int len(int x)
{
	if (x < 10)
		return 1;

	return len(x / 10) + 1;
}
//ȡx�ĵ�kλ���� 
int f(int x, int k)
{
	if (len(x) - k == 0)
		return x % 10;

	return f(x / 10, k);
}

int main()
{
	int x = 23574;
	printf("%d\n", f(x, 3));

	return 0;
}
#endif


//4.4 ���е�ֵ 
#if 0
#include <iostream>

using namespace std;
int main()
{
	const long num = 20190324;

	//***ע*** 
	//�ᵼ�³��������쳣��ֹ�ľ��棺 
	//����ʹ�� ��ջ��constant_1 �ֽڣ����� /analyze��stacksize constant_2��
	//���ǽ����������Ƶ���	
	//	long long shuzu[num]={0};

	long long* shuzu = new long long[num];

	shuzu[0] = shuzu[1] = shuzu[2] = 1;

	//�ӵ����ʼ 
	for (long i = 3; i < num; i++)
	{
		shuzu[i] = shuzu[i - 1] + shuzu[i - 2] + shuzu[i - 3];
		shuzu[i] %= 100000000;//����8λ���Կ�����long long�ı�ʾ��Χ�� 
	}
	cout << shuzu[num - 1];

	delete[] shuzu;

	return 0;
}
#endif


//4.5 �������� 
#if 0
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop
���⣺��������
���´�����Դ�����a[]���ҳ���kС��Ԫ�ء�
��ʹ�������ƿ��������еķ����㷨������ʱ�临�Ӷ���O(N)�ġ�
����ϸ�Ķ�����Դ�룬��д���߲���ȱʧ�����ݡ�
*/
int quick_select(int a[], int l, int r, int k)
{
	//����һ�����������ֵ����Ϊ������ 
	int p = rand() % (r - l + 1) + l;

	//x�������ѡ�������� 
	int x = a[p];

	{
		int t = a[p];//t�������ѡ�������� 
		a[p] = a[r];//��������������ָ��ָ���Ԫ�� 
		a[r] = t;
	}

	int i = l, j = r;
	while (i < j)
	{
		//����������飬���ҵ�һ�����ڻ�������������ݵ�
		//��������ֵ 
		while (i < j && a[i] < x) i++;

		//��������ֵ������ĩ�����ݵ�����ֵ 
		if (i < j)
		{
			//�������ݸ��Ƶ���ĩλ                    
			a[j] = a[i];
			j--;
		}

		//����������飬���ҵ�һ��С�ڻ�������������ݵ�
		//��������ֵ 
		while (i < j && a[j] > x) j--;

		if (i < j)
		{
			//�������ݸ��Ƶ���һ�����ڻ�������������ݵ�
			//����λ�� 
			a[i] = a[j];
			i++;
		}
	}

	//ѭ������ʱi��ߵ������������ᴦ����С��
	//i�ұߵ������������ᴦ������ 

	//��ԭ�����ᴦ�����ָ��Ƶ�i��λ�� 
	a[i] = x;
	p = i;

	if (i - l + 1 == k)//��i-l==k-1 ����ֵ�Ƿ����Ҫ��� 
		return a[i];	//��kС�������ڵ�λ��(��k-1)
							//���ж�����������
							//��˵�������ᴦ�����־��ǵ�kС������ 

	//��С��k����˵��k��Ӧ�������������ұߣ�
	//��һ��ֻ���������ұ�ȥ��				
	//***ע***
	//k-i+l-1��k-(i-l+1),��ȥ����i��벿�ֺ�i�Ұ벿�ִ�0��ʼ������ֵ		
	if (i - l + 1 < k)
		return quick_select(a, i + 1, r, k - i + l - 1); //��� 
	else
		return quick_select(a, l, i - 1, k);
}
int main()
{
	int a[] = { 1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12 };
	printf("%d\n", quick_select(a, 0, 14, 2));
	return 0;
}
#endif


//code5.cpp
//5.1 ̰���㷨 
//���������ʱ�����������ڵ�ǰ��������õ�ѡ��
//�������Ǿֲ����Ž� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	float W = 15;
	float weight_data[7] = { 4.5,1,2,3.3,2.8,6.2,8.4 };

	int count = 0;
	sort(weight_data, weight_data + 7);

	for (int i = 0; i < 7; i++)
		cout << weight_data[i] << " ";

	float temp = 0.0;
	for (int i = 0; i < 7; i++)
	{
		temp += weight_data[i];
		if (temp <= W)
		{
			count++;
		}
		else
			break;
	}

	cout << endl << count << endl;

	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
	float jiage;
	float danjia;
	float weight;
}FoodTypeDef;

bool mycompare(const FoodTypeDef&, const FoodTypeDef&);
int main()
{
	float W = 15;
	FoodTypeDef food_structure[7] =
	{
		{18,18.0 / 4.5,4.5},
		{3,3.0 / 1,1},
		{7.8,7.8 / 2,2},
		{15.8,15.8 / 3.3,3.3},
		{8,8 / 2.5,2.5},
		{99.2,99.2 / 6.2,6.2},
		{20.2,20.2 / 8.4,8.4}
	};

	int count = 0;
	sort(food_structure, food_structure + 7, mycompare);

	for (int i = 0; i < 7; i++)
		cout << food_structure[i].danjia << " ";

	float temp = 0.0;
	float money = 0;
	for (int i = 0; i < 7; i++)
	{
		temp += food_structure[i].weight;
		if (temp <= W)
		{
			count++;
			money += food_structure[i].jiage;
		}
		else
			temp -= food_structure[i].weight;
	}

	cout << endl << count << endl << money;

	return 0;
}
bool mycompare(const FoodTypeDef& F1, const FoodTypeDef& F2)
{
	if (F1.danjia >= F2.danjia)
		return 1;
	else
		return 0;
}
#endif


//5.2 ���ɿ��� 
#if 0
#include <iostream>

using namespace std;

typedef struct
{
	int H;
	int W;
}AttributeTypeDef;

int main()
{
	int N, K;
	cin >> N >> K;

	AttributeTypeDef AttributeStruct[N];//***C++֧�����鳤���Ǳ��� 

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		AttributeStruct[i].H = temp;
		cin >> temp;
		AttributeStruct[i].W = temp;
	}

	int k = 0;
	int bianchang;
	for (bianchang = 1; ; bianchang++)
	{
		k = 0;

		for (int i = 0; i < N; i++)
		{
			int m = AttributeStruct[i].H / bianchang;
			int n = AttributeStruct[i].W / bianchang;
			k += m * n;
		}

		if (k >= K)
			continue;
		else
			break;
	}

	cout << bianchang - 1;

	return 0;
}
//2 10
//6 5
//5 6
#endif


//5.3 ������Ԫ�� 
#if 0
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		B[i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		C[i] = temp;
	}

	int count = 0;
	//ʱ�临�Ӷȣ�O(n^3) 
//	for(int i=0;i<N;i++)
//		for(int j=0;j<N;j++)
//			for(int k=0;k<N;k++)
//			{
//				if(A[i]<B[j]&&B[j]<C[k])
//					count++;
//			}

//�޸ķ�һ��(ʱ�临�Ӷȣ�O(n^2)) 
//��A[j]<B[i]��B[i]<C[j]�ֿ�ͳ����Ŀ����ͳ�ƵĽ����� 
	int m = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[j] < B[i])
				m++;
			if (B[i] < C[j])
				n++;
		}
		count += m * n;
		m = n = 0;
	}

	cout << count;

	return 0;
}
#endif
//�޸ķ����� 
//˼·��
//��������������Ȼ���ҳ�A��С��B[i]������һ������
//����ֵ���ҳ�C�д���B[i]����С��һ����������ֵ 
//�ٰ���������ֵ���д����õ�A��С��B[i]�ĸ�����
//C�д���B[i]�ĸ�������˺�õ���� 
//ת��Ϊһ���������� 
//***ע***���������������Ӧ������ͼ�Ը������ͱ�� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int small(const vector<int>&, int);
int big(const vector<int>&, int);

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		B[i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		C[i] = temp;
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	int count = 0;

	int m = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		int key = B[i];
		int m = small(A, key);
		int n = big(C, key);

		if (A[m]<key && C[n]>key)
			count += (m + 1) * (N - n);
	}

	cout << count;

	return 0;
}
int small(const vector<int>& v, int key)
{
	//�ö��ַ�����
	int left = 0, right = v.size() - 1;

	while (left < right)
	{
		int mid = (left + right + 1) / 2;//��ֹ������ѭ�� 
		if (v[mid] < key)
			left = mid;
		else
			right = mid - 1;
	}

	return left;
}
int big(const vector<int>& v, int key)
{
	//�ö��ַ�����
	int left = 0, right = v.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;//��ֹ������ѭ�� 
		if (v[mid] > key)
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}
#endif


//5.4 �˻���� 
#if 0
#include <iostream>
#include <vector>
#include <valarray>
#include <map>
#include <cmath>
#include <algorithm>//copy()
#include <iterator> 
using namespace std;
typedef long long LL;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<LL> data(N);
	for (int i = 0; i < N; i++)
	{
		LL temp;
		cin >> temp;
		data[i] = temp;
	}

	valarray<LL>shuzu(N);//N����Ҫд 
	copy(data.begin(), data.end(), begin(shuzu));

	//���³���ʧ�� 
//	valarray<LL>shuzu; 
//	copy(data.begin(),data.end(),
//	back_insert_iterator<valarray<LL>>(shuzu));


//������map����Ϊ���ܴ���ֵͬ�ļ�	
//	map<LL,LL>data_map;
//	for(auto p=begin(shuzu);p!=end(shuzu);p++)
//	{
//		data_map[*p]=abs(*p);
//	}
	int* judge = new int[N];//p�����ĳ�����Ƿ�Ϊ��ֵ

	for (int i = 0; i < N; i++)
		judge[i] = 0;

	valarray<LL>shuzu_jueduizhi(N);
	for (int index = 0; index < N; index++)
	{
		LL temp;
		if (shuzu[index] < 0)
		{
			temp = abs(shuzu[index]);
			judge[index] = 1;
			shuzu_jueduizhi[index] = temp;
		}
		else
			shuzu_jueduizhi[index] = shuzu[index];
	}


	LL* qvshuzi = new LL[K];

	int fushu_count = 0;
	for (int i = 0; i < K; i++)
	{
		qvshuzi[i] = shuzu_jueduizhi.max();
		auto p = find(begin(shuzu_jueduizhi),
			end(shuzu_jueduizhi), shuzu_jueduizhi.max());

		//���ֵ��������Сֵ����
		//***����***
		//���ֵѡ���󣬲�����ѡ�����ǰ����ֵ����Ϊ
		//���������bug�����ܱ�֤֮��һ������ѡ��������������� 
		*p = shuzu_jueduizhi.min();

		if (judge[p - begin(shuzu_jueduizhi)])
			fushu_count++;
	}

	LL result = 1;
	for (int i = 0; i < K; i++)
	{
		result *= qvshuzi[i];
		result %= 1000000009;
	}

	if (fushu_count % 2 != 0)//����������
		result = 0 - result;

	cout << result << endl;

	delete[]judge;
	delete[]qvshuzi;
	return 0;
}
#endif
#if 0
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

//typedef struct
//{
//	LL num;
//	bool flag;
//}NumTypeDef;

//1.�����õ�pair���ʹ���ṹ�壬����д<��������غ���
//2.��deque������֧�������ʾ���������Ԫ�أ� 
//֧��Ԫ�ص���ɾ
//3.֧�ֶ�deque����ʹ��sort()���� 

int main()
{
	int N, K;
	cin >> N >> K;

	pair<LL, bool> p1;
	deque<pair<LL, bool>> Num_deque;
	for (int i = 0; i < N; i++)
	{
		LL temp;
		cin >> temp;

		bool f;
		if (temp < 0)
		{
			f = 1;
			temp = -temp;
		}
		else
			f = 0;

		p1.first = temp;
		p1.second = f;
		Num_deque.insert(Num_deque.begin(), p1);
	}

	sort(Num_deque.begin(), Num_deque.end());

	for (auto p = Num_deque.begin(); p != Num_deque.end(); p++)
		cout << (*p).first << " ";
	cout << endl;

	LL result = 1;
	int fushu_count = 0;
	for (int i = 0; i < K; i++)
	{
		//***����д��*** 
		//		result*=(*Num_deque.end()).first;
		result *= (*(Num_deque.end() - 1)).first;
		result %= 1000000009;

		if ((*(Num_deque.end() - 1)).second)
			fushu_count++;

		Num_deque.pop_back();
	}

	if (fushu_count % 2 != 0)//����������
		result = 0 - result;

	cout << result << endl;

	return 0;
}
//5 3
//-100000
//-100000
//-2
//-100000
//-100000
#endif 


//5.5 ��׺���ʽ
//˼·������������ӣ�����С������� 
#if 0
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;

	//	long long * shuzu=new long long[N+M+1];
	//	
	//	for(int i=0;i<N+M+1;i++)
	//	{
	//		long long temp;
	//		cin>>temp;
	//		shuzu[i]=temp;				
	//	}

	deque<long long>shuzu(N + M + 1);
	for (int i = 0; i < N + M + 1; i++)
	{
		long long temp;
		cin >> temp;
		shuzu[i] = temp;
	}

	sort(shuzu.begin(), shuzu.end());

	long long result;
	//���������һ���Ӻ� 
	if (N)
	{
		result = *(shuzu.end() - 1);//ȡ������ 
		shuzu.pop_back();
	}
	else//���û�мӺ� 
	{
		result = *(shuzu.begin());//ȡ��С���� 
		shuzu.pop_front();
	}

	for (int i = 1; i <= N; i++)
	{
		//����������������� 
		result += *(shuzu.end() - 1);
		shuzu.pop_back();
	}

	for (int i = 1; i <= M; i++)
	{
		//����С����������� 
		result -= *(shuzu.begin());
		shuzu.pop_front();
	}


	cout << result << endl;
	//***����***
	//����Ŀ�����˱����ȼӺ���� 
	//��Ŀ����˼��ʵ�ǣ�����ʹ�����ű��ʽ�ģ�
	//��ˣ������������ţ�����С������ȥ
	//������׺���ʽ���Ա�ʾΪ
	//max______-(min______)
	//��һ�������ܽ�Ϊ
	//max-min+���µ��������ľ���ֵ	
	return 0;
}
#endif
//���� 
#if 0
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;

	deque<long long>shuzu(N + M + 1);
	for (int i = 0; i < N + M + 1; i++)
	{
		long long temp;
		cin >> temp;
		shuzu[i] = temp;
	}

	sort(shuzu.begin(), shuzu.end());

	long long result = 0;
	//���ȫ�ǼӺ� 
	if (M == 0)
	{
		for (int i = 0; i < N + M + 1; i++)
			result += shuzu[i];
	}
	else//����м��м� 
	{
		result = shuzu[N + M] - *(shuzu.begin());//��������ȥ��С���� 

		for (int i = 1; i <= N + M - 1; i++)
		{
			result += abs(shuzu[i]);//����ʣ�����ֵľ���ֵ
		}
	}

	cout << result << endl;

	return 0;
}
#endif


//code6.cpp
//6.1 �����㷨 
//������ȱ���(DFS)��������ȱ���(BFS) 
//       ջ						���� 


//���Թ�
#if 0
#include <iostream>

using namespace std;

const int ROW = 14, COL = 17;
int migong[ROW][COL];
int mark[ROW][COL];
int ox, oy;
bool seek_path(int ix, int iy);
int main()
{
	freopen("6.1.txt", "r", stdin);

	//	int XLEN,YLEN;
	//	cin>>XLEN>>YLEN;

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			cin >> migong[i][j];
			mark[i][j] = 0;
		}

	cout << "������꣺";
	int ix, iy;
	//	cin>>ix>>iy;
	ix = 1;
	iy = 0;

	//��ڱ��Ϊ�ѷ���
	mark[1][0] = 1;

	cout << "�������꣺";

	//	cin>>ox>>oy;
	ox = 12;
	oy = 16;

	if (seek_path(ix, iy))
		cout << "(" << ix << "," << iy << ")" << endl;//�������������
	else
		cout << "ERROR";

	return 0;
}

//�������� 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool seek_path(int ix, int iy)
{
	if (ix == ox && iy == oy)
		return true;

	int m, n;

	for (int i = 0; i < 4; i++)
	{
		m = ix + dx[i];
		n = iy + dy[i];

		//���ͨ����δ�����ʹ� 
		if (migong[m][n] == 0 && mark[m][n] == 0)
		{
			//���Ϊ�ѷ��ʹ�
			mark[m][n] = 1;

			//�ݹ���̽
			if (seek_path(m, n))
			{
				//�������·������
				cout << "(" << m << "," << n << ")" << endl;
				return true;
			}
		}
		//���ݣ���һ����������̽ͨ����ڵ�·�� 
	}

	return false;
}
#endif


//6.2����ָ� 
//***˼·***
//�۲�õ�ÿ���ָ�������ݵ�(3,3)�Գ�
//��(3,3)Ϊ������DFS 
#if 0
#include <iostream>

using namespace std;
const int N = 6;

bool mark[N + 1][N + 1]; //���δ��ʼ���ⲿ���������ǻᱻ�Զ���ʼ��Ϊ 0����һԭ��Ҳ�������ⲿ���������Ԫ�ء�
void dfs(int x, int y);
int count1;

int main()
{
	//�����ĵ���Ϊ�ѷ��� 
	mark[3][3] = true;
	dfs(3, 3);
	cout << count1 / 4;//��ת�Գ�����ͬһ�ַָ�����Ҫ����������� 

	return 0;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y)
{
	//����һ���ѵ���߽� 
	if (x == 0 || x == N || y == 0 || y == N)
	{
		count1++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int m = x + dx[i];
		int n = y + dy[i];

		if (mark[m][n] == 0)
		{
			mark[m][n] = true;

			//�õ����(3,3)�Գƴ��ĵ�Ҳ���Ϊ�ѷ���
			mark[N - m][N - n] = true;

			dfs(m, n);

			//����·���ϵĵ�����Ϊδ���� 
			mark[m][n] = false;
			mark[N - m][N - n] = false;
		}
		//ѡ��һ�������ٴν���·������ 
	}

}
#endif 


//6.3 ��� 
#if 0
#include <iostream>
#include <vector>

using namespace std;
bool mark[20];

//1��λ��5��λ�ĸ�����Ա�����ִ���vector 

//***����д��*** 
//vector<int> rates(20) [5];
vector<int> rates[5];

int max_sum;

int max(int a, int b);
void dfs(int num, int sum);
int main()
{
	freopen("6.3.txt", "r", stdin);

	int shuzu[20][6];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 6; j++)
			cin >> shuzu[i][j];

	//	for(int i=0;i<20;i++)
	//	{	for(int j=0;j<6;j++)	
	//			cout<<shuzu[i][j]<<' ';
	//		cout<<endl;		
	//	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
			rates[i].push_back(shuzu[j][i + 1]);
	}

	//	for(int i=0;i<20;i++)
	//	cout<<rates[0][i]<<' ';

	dfs(0, 0);
	cout << max_sum << endl;

	return 0;
}

//int count=0; 
//int sum;
//void dfs(int num)
//{
//	//���⣺����ҵ�����λ��������ֵ���Ա����Ա���ظ���
//	//������õݹ������㣿 
//	 
//	if(count>5)
//		cout<<sum<<endl; 
//	
//	//x��λ 
//	for(int i=0;i<5;i++)
//	{
//		//����Ա���� 
//		for(int j=0;j<20;j++)
//		{
//			if(mark[j]!=1)
//			{
//				mark[j]=1;
//				count++;
//				sum+=rates[i][j];
//			}
//			else
//				continue; 
//		}
//	}
//	
//	
//}

//������
//�������Թ��ĳ���
//�ݹ����������������ڳ�������
//�ݹ���µ���������ǰ����
//ѭ�������������x�᷶Χ��y�᷶Χ

//***�β�ѡ���x��λ����ʱ�����ֺ� 
void dfs(int num, int sum)
{
	if (num > 4)//num��0��4����5��λ 
	{
		//		cout<<sum<<endl;
		max_sum = max(max_sum, sum);
		return;
	}

	for (int i = 0; i < 20; i++)
	{
		if (!mark[i])
		{
			mark[i] = 1;
			//***ע***
			//�ر�ע��Ҫ�ݹ�ʱ���˴�Ӧ�ðѵݹ���µ�����
			//num+1, sum + rates[num][i]
			//д�ڱ��������������ڣ��������ں����⴦��ú�
			//��д�ڱ��������������� 
			//			sum+=rates[num][i];
			//       dfs(num+1,sum);
			//��Ϊ��1��λ��5��λ�ֱ�ѡ����1��5����Ա��
			//��һ�λ�ѡ����1��2��3��4��6����Ա��
			//����sum��ֵ����1��6����Ա�ķ���ֵ����ɼ������
			dfs(num + 1, sum + rates[num][i]);

			mark[i] = 0;
		}
		else
			continue;
	}
	return;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
//������
//int maxSum = 0;
//            for (int i = 0; i < 20; i++)
//                for (int j = 0; j < 20; j++)
//                    for (int k = 0; k < 20; k++)
//                        for (int h = 0; h < 20; h++)
//                            for (int g = 0; g < 20; g++)
//                                if ((i != j && i != k && i != h && i != g) && (j != k && j != h && j != g)
//                                        && (k != h && k != g) && h != g) {
//                                    int max = team[i][0] + team[j][1] + team[k][2] + team[h][3] + team[g][4];
//                                    if (max > maxSum)
//                                        maxSum = max;
//                                }

//�𰸣�490
#endif


//6.4 ȫ���ů 
#if 0
#include <iostream>

using namespace std;

bool mark[1000][1000];
char picture[1000][1000];
int N;

void dfs(int a, int b);
int main()
{
	cin >> N;

	char data[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> data[i][j];
		}

	//��data���ݷŵ�picture[1][1]��ʼ��λ�� 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			picture[i + 1][j + 1] = data[i][j];
		}

	//��μ��㵺��������

	mark[1][1] = 1;
	dfs(1, 1);

	int count = 0;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
		{
			if (picture[i][j] == '#')
				count++;
		}

	cout << count;

	return 0;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y)
{
	if (x == 7 && y == 7)						//------>x�� 
	{															//|
		cout << "Done! " << endl;			//|
		return;												//�� y�� 
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (picture[nx][ny] == '.' && mark[nx][ny] == 0)
		{
			mark[nx][ny] = 1;

			cout << "(" << nx << "," << ny << ")" << " ";
			//1�ź�ˮ��û4�������½�أ�����û���Ϊ* 
			if (picture[nx][ny + 1] == '#')
				picture[nx][ny + 1] = '*';

			if (picture[nx][ny - 1] == '#')
				picture[nx][ny - 1] = '*';

			if (picture[nx - 1][ny] == '#')
				picture[nx - 1][ny] = '*';

			if (picture[nx + 1][ny] == '#')
				picture[nx + 1][ny] = '*';

			dfs(nx, ny);
		}
		//	cout<<"ok\n";
	}
}
//7
//. . . . . . .
//. # # . . . .
//. # # . . . .
//. . . . # # .
//. . # # # # .
//. . . # # # .
//. . . . . . .
#endif
//������
//***˼·***
//û��Ҫ������������������û��û�ĵ��������������
//������Ϊ#�ͱ�ʾһ�����죬 
//��#�����������ҵ���������dfs����(��������������)��
//������Χ�Ƿ���½�أ� 
//���У���flag��1����ʾ��Ƭ���첻��ȫ����û��
//��֮����û�ĵ�������һ 
#if 0
#include<iostream>
#include<string>

using namespace std;

const int maxn = 1005;
int mark[maxn][maxn];

string island[maxn];
int n, flag, sum;

void dfs(int x, int y);

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> island[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (island[i][j] == '#' && mark[i][j] == 0)
			{
				flag = 0;
				dfs(i, j);
				if (!flag)//���flag=0,��ʾ�����������û���ҵ����ʵģ����ջ���ʧ,sum�ۼ�û���ҵ��ġ� 
					++sum;	//���flag=1,��ʾ������������ҵ��˺��ʵģ����ǽ�flag��Ϊ1�� 
			}
		}
	}
	cout << sum;
	return 0;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y)
{
	//����߹���½�� 
	if (island[x][y] == '#' && !mark[x][y])
		mark[x][y] = 1;
	else
		return;

	//�ж��Ƿ�������� 
	if (island[x][y + 1] == '#' && island[x][y - 1] == '#'
		&& island[x + 1][y] == '#' && island[x - 1][y] == '#')
		flag = 1;

	//������������  
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
#endif


//6.5 �Թ� 
//***˼·***
//BFSģ�� 
//queue<type> q;
//q.push(��ʼ״̬);
//while (!q.empty())
//{
//  type t = q.front() ;
//  q.pop();
//  ���� t �ĸ���Next״̬  next
//  { 
//    if (next is legal)
//      q.push(next��״̬); ������ά����; 
//  } 
//}

#if 0
#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int ROW = 30, COL = 50;
char migong[ROW][COL + 1];
bool mark[ROW][COL];

//�ṹ��node��¼xy������ߵ�˳��
struct node
{
	int x;
	int y;
	string s;
};

struct node create_node(int x, int y, string s)
{
	struct node temp;
	temp.x = x;
	temp.y = y;
	temp.s = s;

	return temp;
}
//���� ����  ����  ���� 
int dir[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
char zimu[4] = { 'D','L','R','U' };
bool visited[100][100];

void bfs(int x, int y);
int main()
{
	freopen("6.5.txt", "r", stdin);

	for (int i = 0; i < ROW; i++)
		cin.getline(migong[i], COL + 1);//***ÿ�ж�COL���ַ�*** 

	bfs(0, 0);

	return 0;
}
void bfs(int x, int y)
{
	queue<node> qn;

	qn.push(create_node(0, 0, ""));
	visited[x][y] = 1;

	while (!qn.empty())
	{
		node t = qn.front();
		qn.pop();

		for (int i = 0; i < 4; i++)
		{
			int xn = t.x + dir[i][0];
			int yn = t.y + dir[i][1];

			//��δԽ����δ�����Ҳ����ϰ� 
			if (xn >= 0 && xn < ROW && yn >= 0 && yn < COL &&
				!visited[xn][yn] && migong[xn][yn] != '1')
			{
				if (xn == ROW - 1 && yn == COL - 1)
				{
					cout << t.s << zimu[i] << endl;	//ע��ҲҪ��zimu[i]һ�������Ϊ��ʱ����û�б��ӵ�t.s
					return;
				}
				else
				{
					visited[xn][yn] = 1;//Ӧ����string��+��������غ�����ƴ���ַ��� 
					qn.push(create_node(xn, yn, t.s + zimu[i]));
				}
			}
		}
	}
}
#endif


//code7.cpp
//7.1 ��̬�滮
//������������ֽ�����������⣬��˳����������� 
//ǰһ��������Ľ�Ϊ��һ�������������ṩ�����õ���Ϣ
//***�ȳ���дdp����ٳ��Խ���״̬ת�Ʒ���***
//���ǳ�ʼ�����ͱ߽����

//������̰���㷨
//̰���㷨���ܱ�֤��õ����������Ž⣬
//̰���㷨ʹ�õ�ǰ���Ǿֲ����Ž��ܲ���ȫ�����Ž� 


//�һ�Ӳ������ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 65535;
int main()
{
	int n = 21;
	int a[3] = { 2,5,9 };

	int cc[21];//0~21ΪҪ�õ���Ӳ������ֵ 

	cc[0] = 0;
	for (int i = 1; i <= n; i++)//Ӳ�ҵ�����ֵ 
	{
		cc[i] = MAX;//��Ĭ�ϴղ��� 
		for (int j = 0; j <= 2; j++)
		{
			//����ֵ���ڵ������е�Ӳ�ҵ���ֵ��
			//����ֵ��ȥ������ֵ���ܹ���֮ǰ������յ� 
			if (i >= a[j] && cc[i - a[j]] != MAX)
				cc[i] = min(cc[i - a[j]] + 1, cc[i]);//algorithmͷ�ļ��е�min() 
		}
	}

	cout << cc[21] << endl;

	return 0;
}
#endif 
//***ע***
//algorithmͷ�ļ���ʵ�õĺ�����
//min()��max()��abs()
//swap()��reverse()��sort() 
//find()��upper_bound()��lower_bound()
//fill()��count()��for_each()��copy()
//__gcd()
//set_intersection()��set_union()��set_difference() 
//next_permutation()


//01�������� 
//��N����Ʒ��һ������ܴ�����ΪW�ı�����
//��i����Ʒ��������weight[i]���õ��ļ�ֵ��value[i]
//***ÿ����Ʒֻ����һ��***��
//��⽫��Щ��Ʒװ�뱳������Ʒ��ֵ�ܺ���� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items, num_weight;

	int value[100][100];
	int w[100], v[100];//�����������ֵ

	cin >> num_items >> num_weight;

	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for (int i = 1; i <= num_items; i++)
		cin >> w[i] >> v[i];

	//�����һ�У� 
	//��ά����ĵ�һ��ȫΪ0����ʾ��0����Ʒ��������Ϊ
	//0~num_weight�ı�������ֵΪ0	
	fill(value[0], &value[0][num_weight], 0);

	//	for(int i=0;i<=num_weight;i++)
	//		cout<<value[0][i]<<" ";

		//��x����Ʒ�Ƿ���뱳��
	for (int i = 1; i <= num_items; i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[i][0] = 0;

		//��x����Ʒ��������Ϊ1~num_weight�ı��� 
		for (int j = 1; j <= num_weight; j++)
		{
			//��������ǰ����(����)С�ڵ�x����Ʒ��������
			//�򱳰���ǰ�����������Ʒ��ֵ��Ϊ�ϼ���Ʒ�����
			//�ļ�ֵ 
			if (j < w[i])
				value[i][j] = value[i - 1][j];//***ע***��û�д˾䣬�����ֲ���Ԫ����0�Ĳ��������

				//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			else
				value[i][j] =
				max(value[i - 1][j],
					value[i - 1][j - w[i]] + v[i]);
			//����װ��i����Ʒ����
			//��ֵ��װ��i-1����Ʒ������Ϊj��
			//����ʱ�ļ�ֵ��
			//��װ��i����Ʒ����
			//��ֵ��װ��i-1����Ʒ������Ϊj-w[i]��
			//����ʱ�ļ�ֵ���ϵ�i����Ʒ�ļ�ֵ 

			//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
			//����ѡ���µļ�ֵ��ȡ���ֵ	
		}
	}

	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout << value[num_items][num_weight] << endl;

	//����dp�� 
	for (int i = 0; i <= num_items; i++)
	{
		for (int j = 0; j <= num_weight; j++)
		{
			printf("%4d", value[i][j]);
		}
		cout << endl;
	}

	//��ʾnum_items����Ʒ����num_weight������
	//��������ֵ���ʱ��������ļ�����Ʒ 
	while (value[num_items][num_weight] != 0)
	{
		if (value[num_items][num_weight] >
			value[num_items - 1][num_weight])
		{
			cout << num_items << " ";
			num_weight -= w[num_items];
		}

		num_items--;
	}
	cout << num_items;

	return 0;
}
//5 10
//5 10
//3 5
//4 8
//4 9
//2 6
#endif
//dp��ά����ĸĽ���(�Ż��ռ临�Ӷ�)
//����ά����ѹ����һά���飬
//ÿ��ѭ�����Ƕ�һά������Ԫ�ص�ֵ�ġ�ˢ�¡� 
//value[i][j]=
//			max(value[i-1][j],
//			value[i-1][j-w[i]]+v[i]); 

//value[j]=
//			max(value[j],
//			value[j-w[i]]+v[i]);
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items, num_weight;

	int value[100];
	int w[100], v[100];//�����������ֵ

	cin >> num_items >> num_weight;

	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for (int i = 1; i <= num_items; i++)
		cin >> w[i] >> v[i];

	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value, value + 100, 0);

	//��x����Ʒ�Ƿ���뱳��
	for (int i = 1; i <= num_items; i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0] = 0;

		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***
		//ѭ���������Ϊ���� 
		//����ʱҪ�Ӻ���ǰ����
		//��Ϊ����Ԫ��ֵʱҪ�õ�����ǰ�����(������) 
		for (int j = num_weight; j >= 1; j--)
		{
			//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			if (j >= w[i])
				value[j] =
				max(value[j],
					value[j - w[i]] + v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		} 							  //����ѡ���µļ�ֵ��ȡ���ֵ				

		//��ʾÿ��״̬���º��dp�� 
		for (int k = 0; k <= num_weight; k++)
			printf("%4d", value[k]);
		cout << endl;
	}

	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout << value[num_weight] << endl;

	//��ʾ����״̬��dp�� 
	for (int j = 0; j <= num_weight; j++)
	{
		printf("%4d", value[j]);
	}

	return 0;
}
#endif


//��ȫ�������� 
//��N����Ʒ��һ������ܴ�����ΪW�ı�����
//��i����Ʒ��������weight[i]���õ��ļ�ֵ��value[i]
//***ÿ����Ʒ��������ʹ��***��
//��⽫��Щ��Ʒװ�뱳������Ʒ��ֵ�ܺ����
//˼���� 
//������ʵ�����ޣ�����Ϊ��ǰ��������
//���Ը���Ʒ����������˵õ�
//������ȫ�����㷨 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items, num_weight;

	int value[100];
	int w[100], v[100];//�����������ֵ

	cin >> num_items >> num_weight;

	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for (int i = 1; i <= num_items; i++)
		cin >> w[i] >> v[i];

	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value, value + 100, 0);

	//��x����Ʒ�Ƿ���뱳��
	for (int i = 1; i <= num_items; i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0] = 0;

		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***(С����) 
		//����ʱҪ�Ӻ���ǰ����
		//��Ϊ����Ԫ��ֵʱҪ�õ�����ǰ����� 
		for (int j = num_weight; j >= 1; j--)
		{
			//��i����Ʒ��1����ʼ�ã�
			//�õ�j/w[i]��Ϊֹ 
			for (int k = 1; k <= j / w[i]; k++)
			{
				//��������ǰ�������ڵ���k����x����Ʒ������ 
				if (j >= k * w[i])
					value[j] =
					max(value[j],
						value[j - k * w[i]] + k * v[i]);
			}
		}

		//��ʾÿ��״̬���º��dp�� 
		for (int k = 0; k <= num_weight; k++)
			printf("%4d", value[k]);
		cout << endl;
	}

	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout << value[num_weight] << endl;

	//��ʾ����״̬��dp�� 
	for (int j = 0; j <= num_weight; j++)
	{
		printf("%4d", value[j]);
	}

	return 0;
}
//4 10
//2 1
//3 3
//4 5
//7 9
#endif
//������ȫ�����㷨�Ľ���
//дdp���Ƶ�״̬ת�Ʒ���
//***ע***
//����01������״̬ת�Ʒ�������ȫ������һ��(����P121) 
//����άdp�����Ż���һά���� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items, num_weight;

	int value[100];
	int w[100], v[100];//�����������ֵ

	cin >> num_items >> num_weight;

	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for (int i = 1; i <= num_items; i++)
		cin >> w[i] >> v[i];

	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value, value + 100, 0);

	//��x����Ʒ�Ƿ���뱳��
	for (int i = 1; i <= num_items; i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0] = 0;

		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***
		//ѭ���������Ϊ˳�� 
		//����ʱҪ��ǰ���󸲸�
		//��Ϊ����Ԫ��ֵʱҪ�õ��µ�����
#if 0 
		for (int j = 1; j <= num_weight; j++)
		{
			//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			if (j >= w[i])
				value[j] =
				max(value[j],
					value[j - w[i]] + v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		} 							  //����ѡ���µļ�ֵ��ȡ���ֵ				
#endif

//�ٴ��Ż��� 
		for (int j = w[i]; j <= num_weight; j++)
		{
			value[j] =
				max(value[j],
					value[j - w[i]] + v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		}

		//��ʾÿ��״̬���º��dp�� 
		for (int k = 0; k <= num_weight; k++)
			printf("%4d", value[k]);
		cout << endl;
	}

	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout << value[num_weight] << endl;

	//��ʾ����״̬��dp�� 
	for (int j = 0; j <= num_weight; j++)
	{
		printf("%4d", value[j]);
	}

	return 0;
}
#endif 


//7.2 ���Ӵ���
//***˼·***
//��Ŀ˵����ÿ�����ӵĸ���������ÿ������������
//�����޵ģ��ɴ��뵽��ȫ�������⡣���Ҫ�ճ�
//����������Ҫ����a1x1+a2x2+a3x3+��+anxn=c��
//���಻�����̡�
//���ۣ�����nά��ʽ�ӣ����£�
//a1x1+a2x2+a3x3+��+anxn=c�����a1,a2,a3��an
//���ʣ���x1,x2,x3��xnһ���н����������� 
//����x1,x2,...xn>=0�Ҷ�Ϊ����ʱ,���·��̽�ĸ������ޣ�
//���޽⡣ 
//���a1,a2,a3��an������,��ô����������cʹ��
//�����޽⡣
//�����Լ����Ϊ1���������޸��ղ���
//�����Լ��Ϊ1�����迼������ȫ����˼�����
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	//��ͬ���������� 
	int N;
	cin >> N;

	//��ͬ�������İ��Ӹ��� 
	int zhenglong[N] = { 0 };

	//��x���������İ��Ӹ��� 
	for (int i = 1; i <= N; i++)
		cin >> zhenglong[i];

	int gongyinshu;
	for (int i = 1; i < N; i++)
	{
		gongyinshu = __gcd(zhenglong[i], zhenglong[i + 1]);
	}

	if (gongyinshu != 1)
	{
		cout << "INF";
		return 0;
	}

	int dp[20000];
	fill(dp, dp + 20000, 0);

	//***ע***
	//��ȫ��������ı����ļ�ֵ����Ӧ
	//����dp[x]��0��1��
	//���õ�Ҫ��İ���������1�����ܾ���0 

	//Ҫ0�����ӿ϶��ܴճ� 
	dp[0] = 1;

	//��x�� 
	for (int i = 1; i <= N; i++)
	{
		//��ǰҪ�İ����� 
		for (int j = 1; j <= 20000; j++)
		{
			//����ǰҪ�İ��������ڵ��ڵ�x�����İ����� 
			if (j >= zhenglong[i])
				dp[j] = max(dp[j], dp[j - zhenglong[i]]);//��ȫ����������Ż�д�� 
		}
	}

	int count = 0;
	for (int i = 0; i < 20000; i++)
	{
		if (!dp[i])
			count++;
	}
	cout << count;

	return 0;
}
#endif
//������
//for(int i=1;i<N;i++)
//	for(int j=0;j<20000;j++) 
//	{
//		if(dp[j])
//			dp[j+zhenglong[i]]=1;
//	}


//7.3 K������ 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;

	vector<int>shulie(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> shulie[i];

	int count = 0;
	//�ӵ�1��������N���� 
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)//��i��������i��������N���� 
		{
			int sum = 0;

			//��ֻȡһ���� 
			if (i == j)
			{
				if (shulie[i] % K == 0)
					count++;
			}
			else//��ȡ2��j-i+1���� 
			{
				int temp = i;

				do
					sum += shulie[temp];
				while (temp++ != j);

				if (sum % K == 0)
					count++;
			}
		}

	cout << count;

	return 0;
}
//5 2
//1
//2
//3
//4
//5
#endif


//7.4 ���Դ��� 
//***˼·***
//Ҫ������������Ѳ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000;

int main()
{
	//����һ���ֻ��������ֻ��������ֻ�
	//�ӵ�һ�㵽��N����Ե�dp���� 
	int dp[4][N + 1];

	//***ע***
	//��fill()�Զ�ά���鸳ֵ 
	//����Ĳ���� 
	//	fill(&dp[0][0],&dp[4][N+1],0);
	//��ȷ��� 
	//	fill(&dp[0][0],&(dp[0][0])+4*(N+1),0);

		//�����ֻ��Ĵ�����ֵΪ¥����(����ֻ��һ���ֻ������) 
	for (int i = 1; i <= 3; i++)
		for (int j = 0; j <= N; j++)
			dp[i][j] = j;

	//��i���ֻ� 
	for (int i = 2; i <= 3; i++)
	{
		//Ҫ���j�� 
		for (int j = 1; j <= N; j++)
		{
			//�ڲ��k��¥ʱ 
			for (int k = 1; k <= j; k++)
				dp[i][j] =
				//�����������ѡ���ŵľ���(ѡ���ٵĲ��Դ���) 
				min(dp[i][j],
					//ȡ�������   +1:��ʾ�Ѿ�����һ�β��� 
					1 + max
					//�ֻ�ˤ��������1~k-1�� 
					(dp[i - 1][k - 1],
						//�ֻ�û��������k+1~j�㣬��j-(k+1)+1�� 
						dp[i][j - (k + 1) + 1]));
		}
	}

	cout << dp[3][N];

	return 0;
}
#endif


//7.5 ���� 
//***�����*** 
#if 0
#include <iostream> 

using namespace std;
int dp[2030][1020];

int main()
{
	int n = 2020;

	dp[1][1] = 1;

	//��ǰ����i������ 
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] += dp[i - 1][j - 1];

			if (i - j <= j)
				dp[i][j] += dp[i - 1][j];

			dp[i][j] %= n;
		}
	}

	printf("%d\n", dp[2020][1010]);
	return 0;
}
#endif


//7.6�߷��� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

long dp[10000][100];

int main()
{
	long n, m;
	cin >> n >> m;

	//��һ���߷�ֻ��һ�� 
	fill(&dp[1][1], &dp[1][1] + 99, 1);

	//�ӵڶ��п�ʼ 
	for (int i = 2; i <= n; i++)
	{
		//��i�е�һ���߷�ֻ��һ�� 
		dp[i][1] = 1;
		//�ӵ�i�еڶ��п�ʼ 
		for (int j = 2; j <= m; j++)
		{
			//��i��j��Ϊż�� 
			if (i % 2 == 0 && j % 2 == 0)
				dp[i][j] = 0;
			//��������Ԫ�ص�ǰ��һ��Ԫ��Ϊ0 
			else if (dp[i][j - 1] == 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			//��������Ԫ�ص�����һ��Ԫ��Ϊ0 
			else if (dp[i - 1][j] == 0)
			{
				dp[i][j] = dp[i][j - 1];
			}
			//��������Ԫ��ǰ��һ��Ԫ�غ�����һ��Ԫ�ؾ���Ϊ0
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//�������⹫ʽ���� 
			}
		}
	}

	//	for(int i=0;i<=n;i++)
	//	{
	//		for(int j=0;j<=m;j++)
	//			printf("%6d",dp[i][j]);
	//		cout<<endl;
	//	}

	cout << dp[n][m];

	return 0;
}
#endif


//7.7 ������� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[110][200010];

int main()
{
	int N;
	cin >> N;

	vector<int> fama(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> fama[i];

	//��i������ 
	for (int i = 1; i <= N; i++)
	{
		//��һ�е����ݿ�������ǰ�� 
		for (int j = 1; j <= 200010; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}

		//��¼1~i�������ܱ�ʾ��������� 
		int Max = 0;
		for (int index = 1; index <= i; index++)
			Max += fama[index];

		//Ҫ�յ����� 
		for (int j = 1; j <= Max; j++)
		{
			if (j == fama[i])
				dp[i][j] = 1;

			if (fama[i] - j >= 1 && dp[i - 1][fama[i] - j])//����01��������Ĺ�ʽ 
				dp[i][j] = 1;

			if (j - fama[i] >= 1 && dp[i - 1][j - fama[i]])
				dp[i][j] = 1;
		}
	}

	//	for(int i=0;i<=N;i++)
	//	{
	//		for(int j=0;j<=15;j++)
	//			printf("%6d",dp[i][j]);
	//		cout<<endl;
	//	}	

	int count = 0;
	for (int j = 0; j <= 200010; j++)
		if (dp[N][j])
			count++;

	cout << count;

	return 0;
}
#endif


//7.8 �������� 
//***�����*** 
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string::iterator p;
	int l_count = 0, r_count = 0;
	for (p = str.begin(); p != str.end(); p++)
	{
		if (*p == '(')
			l_count++;
		if (*p == ')')
			r_count++;
	}

	cout << l_count << " " << r_count;

	return 0;
}
#endif


//code8.cpp
//8.1 �����㷨
//���·���㷨�����Ͻ�˹�����㷨�����������㷨
//���鼯�㷨


//8.2 ��󹫹��Ӵ�
#if 0
#include <stdio.h>
#include <string.h>

#define N 256
int f(const char* s1, const char* s2)
{
	int a[N][N];
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i, j;

	memset(a, 0, sizeof(int) * N * N);

	int max = 0;
	for (i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				a[i][j] = a[i - 1][j - 1] + 1;
				if (a[i][j] > max)
					max = a[i][j];
			}
		}
	}

	return max;
}

int main()
{
	printf("%d\n", f("abcdkkk", "baabcdadabc"));
	printf("%d\n", f("aaakkkabababa", "baabababcdadabc"));
	printf("%d\n", f("abccbaacbcca", "ccccbbbbbaaaa"));
	printf("%d\n", f("abcd", "xyz"));
	printf("%d\n", f("ab", "ab"));
	return 0;
}
#endif 


//8.3 �������� 
//***˼·***
//�����n�����Σ������ʱ�ȼ��Ͼ��εĳ���
//��������ֵ��
//��������������֮��Ĺ�ϵ 
#if 0
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	LL X, Y;
	cin >> X >> Y;

	//����õ��ڵ�n����������
	LL n = max(abs(X), abs(Y));

	//����Ҫ�ȼ��ϵ�n-1�������εĳ���	
	LL dis = (0 + 8 * (n - 1)) * n / 2;

	//��y>=xʱ
	if (Y >= X)
		dis += 2 * n + X + Y;
	else//��y<xʱ
		dis += 6 * n - X - Y;

	cout << dis;

	return 0;
}
#endif


//8.4 ��־ͳ�� 
#if 0
#include <iostream>
#include <set>
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std;

long f1(vector<long> v, long d);

int main()
{
	//N����¼��D��ʱ�䳤�ȣ�K���� 
	long N, D, K;
	cin >> N >> D >> K;

	//***ע***
	//����ʹ��multiset����������
	//��Ϊ���ڴ�������˵��ֵ���Ǽ�����pair����
	//��ô��ѯҲֻ�ܲ�pair���� 

	//	multiset<pair<long,long>>record;

	//	for(int i=0;i<N;i++)
	//	{
	//		long ts,id;
	//		cin>>ts>>id;					 //������⣺ 
	//								          //�� ֵ 
	//		record.insert(pair<long,long>(id,ts));
	//	}
	//	
	//	for(auto p=record.begin();p!=record.end();p++)
	//	{
	//		auto range=record.equal_range((*p).first);//������� 
	//		
	//	}

	multimap<long, long> record;

	for (int i = 0; i < N; i++)
	{
		long ts, id;
		cin >> ts >> id;
		//�� ֵ 
		record.insert(pair<long, long>(id, ts));
	}

#if 0
	cout.put('\n');
	for (auto p = record.begin(); p != record.end(); p++)
	{
		cout << (*p).first << " " << (*p).second << endl;
	}
#endif

	set <long> id;
	vector<long> v1;
	for (auto p = record.begin(); p != record.end(); p++)
	{
		//�ҵ�����id�ļ�¼�ķ�Χ 
		auto range = record.equal_range((*p).first);

		//		for(auto it=range.first;it!=range.second;it++)
		//		cout<<(*it).first<<" "<<(*it).second<<endl;

		int count = 0;
		//***ע***range.second-1�޶��� 
		//no match for 'operator -'
//		for(auto it=range.first;it!=range.second;    )
//		{
//no match for 'operator +'
//			if(it+1<range.second&&*((it+1)).second-(*it).second<D)
//				count++; 

//			auto temp=it;
//			it++;
//			
//			if((*it).second-(*temp).second<D)
//				count++;
//		}
		//���ڲ��ܱ�֤ͬһ����Ӧ��ֵ���������еģ���ô��
		//��Щֵ����vector�У������������������ʱ���� 
		for (auto it = range.first; it != range.second; it++)
		{
			v1.push_back((*it).second);
		}
		count = f1(v1, D);
		v1.clear();//***��д*** 

		if (count >= K)
			id.insert((*p).first);
	}

	for (auto i = id.begin(); i != id.end(); i++)
		cout << *i << endl;

	return 0;
}

long f1(vector<long> v, long d)
{
	long count = 1;//***ע***��1����0 

	sort(v.begin(), v.end());

	for (auto it = v.begin(); it + 1 != v.end(); it++)
	{
		if (*(it + 1) - *it < d)//������ʱ��ļ��С��d   
		{
			count++;
		}
	}

	return count;
}
//7 10 2
//0 1
//0 10
//10 10
//10 1
//9 1
//100 3
//100 3
#endif
//�Ľ���
//��set��Ԫ��ֵ����multimap�ļ�¼���в��ң�
//���ٶ�multimap�ظ����ҵĴ��� 
#if 0
#include <iostream>
#include <set>
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std;

//�������ʱ�������޵����� 
long f1(vector<long> v, long d);

int main()
{
	//N����¼��D��ʱ�䳤�ȣ�K���� 
	long N, D, K;
	cin >> N >> D >> K;

	multimap<long, long> record;

	for (int i = 0; i < N; i++)
	{
		long ts, id;
		cin >> ts >> id;
		//�� ֵ 
		record.insert(pair<long, long>(id, ts));
	}

#if 0
	cout.put('\n');
	for (auto p = record.begin(); p != record.end(); p++)
	{
		cout << (*p).first << " " << (*p).second << endl;
	}
#endif

	//�����ڱ���multimap���ļ� 
	set<long> ID;
	for (auto p = record.begin(); p != record.end(); p++)
	{
		ID.insert((*p).first);
	}

	//�����������id�� 
	set <long> id;
	//��id�Ŷ�Ӧ�ĸ���ʱ�� 
	vector<long> v1;
	//��set�����Ԫ�ؽ��б��� 
	for (auto p = ID.begin(); p != ID.end(); p++)
	{
		//��multimap���ҵ�����ID�ļ�¼�ķ�Χ 
		auto range = record.equal_range((*p));

		int count = 0;

		for (auto it = range.first; it != range.second; it++)
		{
			v1.push_back((*it).second);
		}
		count = f1(v1, D);
		v1.clear();//***��д*** 

		if (count >= K)
			id.insert(*p);
	}

	for (auto i = id.begin(); i != id.end(); i++)
		//		cout<<*i<<endl;
		printf("%ld\n", *i);

	//***ע***
	//Ҫ�����������ʱcout��printf����Ϊ�˲�Ӱ�����������˴���printf() 
	return 0;
}

long f1(vector<long> v, long d)
{
	//***ע***
	//������⣺
	//ֻҪ�����޵�ʱ����С��d������������ 

//	//�޵����� 
//	long count=1;//***ע***��1����0 
//	
//	sort(v.begin(),v.end());
//	
//	for(auto it=v.begin();it+1!=v.end();it++)
//	{
//		if(*(it+1)-*it<d)//������ʱ��ļ��С��d   
//		{
//			count++;
//		}		
//	}

	//��ȷ��⣺ 
	//��¼��ĳһʱ�̿�ʼ��dʱ����ڵ��޵�������
	//����һ��ʱ�̿�ʼ��dʱ��μ�¼ʱ��Ҫ�ص�1 

	sort(v.begin(), v.end());

	long max_count = 1;
	long count = 1;
	for (auto it1 = v.begin(); it1 != v.end(); it1++)
	{
		for (auto it2 = it1 + 1; it2 != v.end(); it2++)
		{
			if (*it2 - *it1 < d)
			{
				count++;
				max_count = max_count > count ? max_count : count;
			}
		}

		count = 1;
	}

	return max_count;
}
#endif


//8.5 ���ܴ��� 
//***������Ѷ�*** 
#if 0
#include <iostream>
#include <algorithm>
#include <string.h>//memset()
#define ll long long

using namespace std;

const int N = 3e5 + 3;

ll a[N], s[N];
bool vis[N];
int n;

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		memset(vis, 0, sizeof(vis));

		scanf("%d", &n);

		s[0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &s[i]);
			s[i] += s[i - 1];
		}

		ll s0 = 0, sn = s[n];

		if (s0 > sn) swap(s0, sn);//ǰС���Ϊ����ȡ�����ɱ�������ȡ��ʱ�ظ�ȡ�����⡣ 
		sort(s, s + n + 1);

		int l = 0, r = n;
		for (int i = lower_bound(s, s + n + 1, s0) - s; i >= 0; i -= 2)
		{
			a[l++] = s[i], vis[i] = 1;
		}

		for (int i = lower_bound(s, s + n + 1, sn) - s; i <= n; i += 2)
		{
			a[r--] = s[i], vis[i] = 1;
		}

		for (int i = 0; i <= n; ++i)
		{
			if (!vis[i])
				a[l++] = s[i];
		}

		ll res = 0;

		for (int i = 1; i <= n; ++i)
			res = max(res, abs(a[i] - a[i - 1]));

		printf("%lld\n", res);
	}
	return 0;
}
#endif


//8.6 ˫������ 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(const long& a, const long& b);

int main()
{
	//���г��ȣ���������
	long n, m;
	cin >> n >> m;

	vector<long>v1;
	for (long i = 0; i <= n; i++)//0~n��Ϊ�������е��±��Ӧ��
		v1.push_back(i);	 //����0��Ԫ�ز�ʹ�� 

//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;

	//ʹ��new������ά����
	long(*caozuo)[3] = new long[m + 1][3];

	fill(&caozuo[0][0], &caozuo[0][0] + (m + 1) * 3, 0L);

	for (long i = 1; i <= m; i++)
	{
		cin >> caozuo[i][1] >> caozuo[i][2];
	}

	int i = 1;
	while (m--)
	{
		if (caozuo[i][1] == 0)//***ע***sort()�Ƕ�[ )�ķ�Χ������ 
			sort(&v1[1], &v1[caozuo[i][2]] + 1, mycompare);

		if (caozuo[i][1] == 1)
			sort(&v1[caozuo[i][2]], &v1[n] + 1);

		i++;

		for (auto x : v1)
			cout << x << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i++)
		cout << v1[i] << " ";

	delete[]caozuo;

	return 0;
}
bool mycompare(const long& a, const long& b)
{
	return a > b;
}
//3 3
//0 3
//1 2
//0 2
#endif
//�ظ��Ĳ�������̫�࣬����AC����
//���Ƕ��������ļ���ͬ���Ĳ�����ȡ��Χ�����Ǹ����� 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(const long& a, const long& b);

int main()
{
	//���г��ȣ���������
	long n, m;
	cin >> n >> m;

	vector<long>v1;
	for (long i = 0; i <= n; i++)//0~n��Ϊ�������е��±��Ӧ��
		v1.push_back(i);	 //����0��Ԫ�ز�ʹ�� 

//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;

	//ʹ��new������ά����
	long(*caozuo)[3] = new long[m + 2][3];

	fill(&caozuo[0][0], &caozuo[0][0] + (m + 1) * 3, 2L);

	int p, q, max_q = 0;
	int count_p_0 = 0, count_p_1 = 0;
	for (long i = 1; i <= m; i++)
	{
		//		cin>>caozuo[i][1]>>caozuo[i][2];
		cin >> p >> q;

		//��¼p=0��p=1�������� 
		if (!p)
		{
			count_p_0++;
			count_p_1 = 0;
		}
		else
		{
			count_p_1++;
			count_p_0 = 0;
		}

		//��p=0��p=1���ֵĵ�һ�ε�q����max_q 
		if (count_p_0 == 1 || count_p_1 == 1)
			max_q = q;

		//��p=0���������������ٶ��� 
		if (!p && count_p_0 >= 2)
		{
			max_q = max_q >= q ? max_q : q;
		}
		else if (p && count_p_1 >= 2)
		{
			max_q = max_q >= q ? max_q : q;
		}

		caozuo[i][1] = p;
		caozuo[i][2] = max_q;

		if (count_p_0 >= 2 || count_p_1 >= 2)
		{//�����ֵĵ�һ�ε�qҲ��max_q���ǵ� 
			caozuo[i - 1][2] = max_q;
		}
	}

	int i = 1;
	long m1 = m;
	while (m1--)
	{
		if (caozuo[i][1] == 0 && caozuo[i + 1][1] != 0)
			//***ע***sort()�Ƕ�[ )�ķ�Χ������ 
			sort(&v1[1], &v1[caozuo[i][2]] + 1, mycompare);

		if (caozuo[i][1] == 1 && caozuo[i + 1][1] != 1)
			sort(&v1[caozuo[i][2]], &v1[n] + 1);

		i++;

		for (auto x : v1)
			cout << x << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i++)
		cout << v1[i] << " ";

	delete[]caozuo;

	return 0;
}
bool mycompare(const long& a, const long& b)
{
	return a > b;
}
//3 3
//0 3
//1 2
//0 2
#endif
//�޸ģ�
//����ջ��ջԪ����pair<int,int>
//�������Ժܷ���ض�������pֵ��Ӧ�Ĳ�ͬ��qȡ����qֵ��
//���Ѿ����ݵ����������ݼ��� 


//8.7 ������� 
#if 0
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int net[10010][10010];

typedef struct caozuo
{
	int a;
	int b;
	int c;

}CaozuoTypeDef;

int n;

//�ѷ��ʱ�� 
bool visit[100010] = { 0 };
//��ĳ�η�������Ϣ���ļ����ڵ��洢��Ϣ 
set<int>s1;
//����������� 
void dfs(int n1);

int main()
{
	//�ڵ��������������� 
	int m;
	cin >> n >> m;

	//�����ڽӾ��� 
	//***ע***
	//������ά���� 
	//ʧ�ܣ� ����ά�������ֵ����Ϊ������ 
	//	int (*net)[n]=new int[n][n];
	//�ɹ��� 
	//	int (*net)[3]=new int[n][3];

	//	fill(&net[0][0],&net[0][0]+n*n,0);

	//	for(int i=0;i<n;i++)
	//	{
	//		for(int j=0;j<n;j++)
	//			cout<<net[i][j]<<" ";
	//		cout<<endl;
	//	}

		//�������ڵ�洢��Ϣ��С������ 
	long* message = new long[n + 1];

	fill(message, message + n + 1, 0);

	//����� 
	queue<CaozuoTypeDef>q1;

	for (int i = 0; i < m; i++)
	{
		CaozuoTypeDef CaozuoStruct;
		cin >> CaozuoStruct.a >>
			CaozuoStruct.b >> CaozuoStruct.c;

		q1.push(CaozuoStruct);
	}

	while (!q1.empty())
	{
		//�ж�ĳ�β�����1����2 
		if (q1.front().a == 1)
		{
			//�ڽӾ���Խ���Ԫ�ض���1����ʾ��ͨ 
			net[q1.front().b][q1.front().c] = 1;
			net[q1.front().c][q1.front().b] = 1;
		}
		else
		{
			//DFS�����ļ����ڵ��洢��Ϣ�����ڵ�Ŵ���set���� 
			dfs(q1.front().b);

			for (auto it = s1.begin(); it != s1.end(); it++)
			{
				message[*it] += q1.front().c;
			}

			//***ע***
			//�������䲻���٣���
			//ÿ��ִ�в���2ʱ��set�������ݾ�Ϊ��
			//�ҷ��ʱ��Ҳ��Ϊ0��Ϊ��dfs���������� 
			s1.clear();
			fill(visit, visit + 100010, 0);
		}

		q1.pop();
	}

	for (int i = 1; i <= n; i++)
		cout << message[i] << " ";

	delete[]message;

	return 0;
}

void dfs(int n1)
{
	if (!visit[n1])
	{
		visit[n1] = 1;
		s1.insert(n1);//ע��˾�ŵ�λ�� 

		for (int i1 = 1; i1 <= n; i1++)
		{
			if (net[n1][i1])//��n1����i1������ͨ 
				dfs(i1);
		}
	}
}
//4 8
//1 1 2
//2 1 10
//2 3 5
//1 4 1
//2 2 2
//1 1 2
//1 2 4
//2 2 1
#endif
//���鼯��
#if 0
#include <iostream>

using namespace std;

int fa[10010];
long long message[10010];

void merge(int a, int b);
int get(int x);

int main()
{
	//�ڵ��������������� 
	int n, m;
	cin >> n >> m;

	//1.��ʼ��
	//ÿ���ڵ����Ϊһ�����ϣ�
	//�Ҽ��ϵĸ��ڵ�Ϊ�Լ� 
	for (int i = 1; i <= n; i++)
		fa[i] = i;

	//���������ڵ�a���ڵ�b 
	int id, a, b;

	for (int i = 0; i < m; i++)
	{
		cin >> id >> a >> b;

		if (id == 1)
		{
			merge(a, b);
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				//ÿ��һ���ڵ���a���ڵļ����� 
				if (get(a) == get(j))
					message[j] += b;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%lld", message[i]);

		if (i < n)
			printf(" ");
	}

	return 0;
}

//2.��
//***�������*** 
//��a�ĸ��ڵ�����Ϊb 
//��ȷ��⣺
//��a���ڵļ��Ϻ�b���ڵļ��Ͻ��кϲ�
//���������ϲ�Ϊͬһ�����ϣ��� 
//��a���ڼ��ϵĸ��ڵ�����Ϊb���ڵĸ��ڵ� 
void merge(int a, int b)
{
	int aa = get(a);
	int bb = get(b);

	if (aa != bb)
		fa[aa] = bb;
}

//3.��
//���ҽڵ����ڼ��ϵĸ��ڵ㣬
//�˴���·��ѹ���Ĳ��ҷ��� 
int get(int x)
{
	if (fa[x] == x)
		return x;
	else
	{
		fa[x] = get(fa[x]);

		return fa[x];
	}
}
#endif 


//8.8 ·�� 
#if 0
#include <iostream>
#include <cmath>
#include <algorithm>
							//***ע***�������̫С 
#define GRAPH_INFINITY 999999999
#define MAXVEX 2021

using namespace std;

typedef struct
{
	int vertex[MAXVEX];
	long arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph* G);
void ShortestPath_Floyd(const MGraph* G,
	int(*P)[MAXVEX], long(*D)[MAXVEX]);

int measure(int a, int b)
{
	if (b == 0)
		return a;
	else
		return measure(b, a % b);

	//������algorithmͷ�ļ��а�����__gcd() 
	//return __gcd(a, b);

	//���䣺��С������=�����˻�/���Լ��
}

int main()
{
	MGraph* G = new MGraph;
	CreateMGraph(G);

	//����ʹ�öѵ��� "49021384" �ֽڡ��뿼�ǽ�һЩ�����ƶ����ѡ�
	//	//���·������ 
	//	long Path[MAXVEX][MAXVEX];
	//	//���·��Ȩֵ�;��� 
	//	int D[MAXVEX][MAXVEX]; /* ��ĳ�㵽�����������·�� */

	//���·������path
	int(*Path)[MAXVEX] = new int[MAXVEX][MAXVEX];
	//���·��Ȩֵ�;���distance
	long(*Dis)[MAXVEX] = new long[MAXVEX][MAXVEX];

	ShortestPath_Floyd(G, Path, Dis);

	cout << Dis[0][MAXVEX - 1];

	delete[]Path;
	delete[]Dis;

	return 0;
}
void CreateMGraph(MGraph* G)
{
	//������ 
	G->numVertexes = MAXVEX;

	/* ��ʼ������ */
//	for (int i = 0; i < G->numVertexes; i++)
//	{
//		G->vertex[i] = i+1;
//	}

	for (int i = 0; i < MAXVEX; i++)
	{
		for (int j = 0; j < MAXVEX; j++)
		{
			//***ע*** 
			//����д����	
#if 0 
	//���㵽����ı߲����� 
			if (i == j)
				G->arc[i][j] = 0;
			else//���㵽��������ı�Ĭ�����޳� 
				G->arc[i][j] = GRAPH_INFINITY;

			if (abs(i - j) > 21)
				continue;
			else				//***ע***����Ҫд+1 
				G->arc[i][j] = (i + 1) * (j + 1) / __gcd(i + 1, j + 1);
#endif

			//��ȷд���� 
				//���㵽����ı߲����� 
			if (i == j)
				G->arc[i][j] = 0;
			else//���㵽��������ı�Ĭ�����޳� 
			{
				G->arc[i][j] = GRAPH_INFINITY;

				if (abs(i - j) > 21)
					continue;
				else				//***ע***����Ҫд+1 
					G->arc[i][j] = (i + 1) * (j + 1) / __gcd(i + 1, j + 1);
			}
		}
	}

	//	for(int i=0;i<MAXVEX;i++)
	//	{
	//		for(int j=0;j<MAXVEX;j++)
	//			printf("%5d",G->arc[i][j]);
	//		cout<<endl;
	//	}
	//printf("%5d",G->arc[0][1]);

}

void ShortestPath_Floyd(const MGraph* G,
	int(*P)[MAXVEX], long(*D)[MAXVEX])
{
	//��ʼ��P��D
	for (int v = 0; v < G->numVertexes; v++)
	{
		for (int w = 0; w < G->numVertexes; w++)
		{
			P[v][w] = w;
			D[v][w] = G->arc[v][w];
		}
	}

	//��ת����
	for (int k = 0; k < G->numVertexes; k++)
	{
		for (int v = 0; v < G->numVertexes; v++)
		{
			for (int w = 0; w < G->numVertexes; w++)
			{
				if (D[v][w] > D[v][k] + D[k][w])
				{
					D[v][w] = D[v][k] + D[k][w];
					P[v][w] = P[v][k];
				}
			}
		}
	}

	return;
}
#endif


/******************************��ˢ*****************************************/


//#include<bits/stdc++.h>������Ŀǰc++������������ͷ�ļ����Ǹ����ܿ�
//����
//#include <iostream> 
//#include <cstdio> 
//#include <fstream> 
//#include <algorithm> 
//#include <cmath> 
//#include <deque> 
//#include <vector> 
//#include <queue> 
//#include <string> 
//#include <cstring> 
//#include <map> 
//#include <stack> 
//#include <set>  
//******************��Ҫ����޸�֮ǰ���ж�Ӧ���кţ��ʼǱ���¼��֪ʶ��Ҫ����������***************************** 

//2022���ʮ�������ű����������ʡ��C/C++�о���������
//����������
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

#define MAX 10000

int main()
{
	long* zhishu = new long[MAX];

	fill(zhishu, zhishu + MAX, 0);

	zhishu[0] = { 2 };

	long index = 1;
	bool flag = 0;
	for (long i = 3; i < MAX; ++i)
	{
		for (long j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}

		if (flag)
			zhishu[index++] = i;
	}

	//	for(int i=0;i<100;i++)
	//	cout<<zhishu[i]<<" ";

	long long num;
	cin >> num;

	long count = 0;
	for (long i = 0; i < MAX && zhishu[i] != 0; i++)
	{
		if (!(num % zhishu[i]))
		{
			//			cout<<zhishu[i]<<" ";
			count++;
		}
	}

	cout << count;

	delete[] zhishu;

	return 0;
}
#endif 


//********************�����ű�������������********************
//1.��ʾ��ͬ���� 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num = 10;

	cout << showbase;
	cout << dec << num << " " << oct
		<< num << " " << hex << " " << num;

	return 0;
}
#endif


//2.�洢�����Ƶ����� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num = 4;

	int index = 7;
	char erjinzhi[8];

	fill(erjinzhi, erjinzhi + 8, '0');

	while (num)
	{
		erjinzhi[index] = num % 2 + '0';
		num /= 2;

		index--;
	}

	for (char x : erjinzhi)
		cout << x;

	return 0;
}
#endif


//3.��C++���Ƿ��C������ĳ�ʼ���ķ���Ч��һ��
//�����ֳ�ʼ������£�δ��ʼ����Ԫ���Ƿ񶼻ᱻ����Ϊ0 
#if 0
#include <iostream>

using namespace std;
const int MAX = 20;

int main()
{
	//һά 
	int yiwei[10] = { 1 };
	//��ά 
	int erwei[10][10] = { 1 };

	for (int x : yiwei)
		cout << x;

	cout << endl << endl;;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << erwei[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	long** p = new long* [MAX]; //��MAX��Ԫ�أ�ÿ��Ԫ�ض���ָ��long��ָ��  
	for (long i = 0; i < MAX; i++)
	{
		//һά�����ָ��*(p+i)ָ��һ����MAX��Ԫ�ص����飬ÿ��Ԫ�ض���long���͵�ֵ 
		//��ÿ��һά�������Ԫ�ر���ʼ��Ϊ1   (C++11)
		*(p + i) = new long[MAX] {1};
	}

	//����д������������Ǹ�ֵ�������ǳ�ʼ��
	//p[0][0] = 1;

	for (long i = 0; i < MAX; i++)
	{
		for (long j = 0; j < MAX; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	//����ά�������Ԫ�س�ʼ��Ϊ1
	long(*p1)[MAX] = new long[MAX][MAX]{1};

	//����д������������Ǹ�ֵ�������ǳ�ʼ��
	//p1[0][0] = 1;

	for (long i = 0; i < MAX; i++)
	{
		for (long j = 0; j < MAX; j++)
		{
			cout << p1[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	//���ۣ�
	//C++�У���֧��C�е�ָ����ʼ�������� 
	//��һ�㷽�����������飬δ��ʼ����Ԫ�ػ��Զ�������Ϊ0
	//��new�����Ļ�����ʼ��һ��Ԫ�غ�δ��ʼ����Ԫ��Ҳ���Զ�������Ϊ0	(C++11)	

	return 0;
}
#endif 


//4.���� 
#if 0
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int input[10][32];

	//	freopen("1.4.txt","r",stdin);
	ifstream fin("1.4.txt");

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 32; j++)
			fin >> input[i][j];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 32; j++)
			cout << input[i][j] << ' ';
		cout << endl;
	}

	fin.close();

	int getdata[16][16];
	fill(&getdata[0][0], &getdata[0][0] + 16 * 16, 0);

	//	for(int i=0;i<16;i++)
	//	{
	//		for(int j=0;j<16;j++)
	//		{
	//			cout<<getdata[i][j];
	//		}
	//		cout<<endl;
	//	}

	int m, n;
	m = 0;

	//��i+1�е����ݸ���16*16�������� 
	int i = 0;

	for (int j = 0; j < 32; j++)//��i+1�е�j+1�� 
	{
		n = 7;

		if (input[i][j] < 0)
			input[i][j] = 256 + input[i][j];

		while (input[i][j])//��ĳ��������8λ����������ʾ 
		{
			getdata[m][n--] = input[i][j] % 2;
			input[i][j] /= 2;
		}

		j++;

		n = 15;

		if (input[i][j] < 0)
			input[i][j] = 256 + input[i][j];

		while (input[i][j])//��ĳ��������8λ����������ʾ 
		{
			getdata[m][n--] = input[i][j] % 2;
			input[i][j] /= 2;
		}

		m++;
	}


	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << getdata[i][j];
		}
		cout << endl;
	}

	return 0;
}
#endif


//5.����ַ��� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int input = 2019;

	int data[5];
	fill(data, data + 5, -1);

	//���Ŵ�26���Ƶ��� 
	int index = 4;

	//�������ֵ��1��������26��ʵ��Ϊ25��26���Ƶ���Ϊ25����Z
	//��ʾ����������Ŀ��Ҫ��ƥ�� 
	input -= 1;

	while (input)
	{
		data[index--] = input % 26;
		input /= 26;
	}//26���ƣ�һ��λ����ֵΪ0~25 

//	char x;
//	for(int i=0;i<5;i++)
//	{
//		if(data[i]==-1)
//		continue;
//		
//		x=data[i]+'A';//覴ã�����27���õ�BA 
//		cout<<x;		
//	}

	char x;
	for (int i = 0; i < 5; i++)
	{
		if (data[i] == -1)
			continue;

		if (i != 4)//����ĩλ����Ҫ�����-1 
		{
			x = data[i] + 'A' - 1;
			cout << x;
		}
		else
		{
			x = data[i] + 'A';
			cout << x;
		}
	}

	return 0;
}
#endif


//6. ʱ����ʾ 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;

int main()
{
	LL num;
	cin >> num;//������Ǹ�1970��1��1��00:00:00����ǰʱ�̵ĺ����� 

	num %= 24 * 60 * 60 * 1000;//����ĺ������������24Сʱ�ĺ�����

	num /= 1000;//numΪ����
	int sec = num % 60;
	num /= 60;//numΪ������
	int minutes = num % 60;
	num /= 60;//numΪСʱ

	cout << setw(2) << setfill('0');
	cout << num << ':' << setw(2) << minutes << ':' << setw(2) << sec;

	return 0;
}
//1618708103123
#endif 


//7.�ֽ������� 
#if 0
#include <iostream>
//#include <set>
#include <algorithm>
using namespace std;

const int LIM = 50;
int zhishu[LIM];

void getzhishu(int*);

int main()
{
	int a, b;
	cin >> a >> b;

	getzhishu(zhishu);

	long count = 0;
	//��������i 
	for (int i = a; i <= b; i++)
	{
		//����д���� 
		//������i������ 
		//		for(int index=0;index<LIM;index++)
		//		{
		//			
		//			if(i==zhishu[index])
		//			{
		//				count+=1;
		//				break;      //***ע***�˴���breakֻ�˳���ǰѭ�� 
		//			}					//���ص�for��������ִ���������� 
		//		} 

				//������i������ 
#if 1 
		auto p = find(zhishu, zhishu + LIM, i);
		if (p != zhishu + LIM)
		{
			count++;
			continue;
		}
#endif//�������ԣ������鲻дҲ���ԣ���ʱ�临�Ӷ������ 

		//������i�������� 		
		int temp = i;
		for (int index = 0; index < LIM; index++)
		{
			//***ע***����while 
			while (temp % zhishu[index] == 0)
			{
				count++;
				temp /= zhishu[index];
			}
		}
	}

	cout << count;

	return 0;
}
void getzhishu(int* p)
{
	*p = 2;//zhishu[0]=2

	bool flag;
	int index = 1;

	for (int num = 3; num < 500 && index < LIM; num++)
	{
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}

		if (flag)
			p[index++] = num;
	}

	//	for(int x:zhishu)
	//		cout<<x<<" ";
}
#endif
//7.�޸� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>zhishu;

void getzhishu(vector<int>& v, int max);

int main()
{
	int a, b;
	cin >> a >> b;

	getzhishu(zhishu, b);

	long count = 0;
	//��������i 
	for (int i = a; i <= b; i++)
	{
		//������i������ 
#if 1 
		auto p = find(zhishu.begin(), zhishu.end(), i);
		if (p != zhishu.end())
		{
			count++;
			continue;
		}
#endif//�������ԣ������鲻дҲ���ԣ���ʱ�临�Ӷ������ 

		//������i�������� 		
		int temp = i;
		for (int index = 0; index < zhishu.size(); index++)
		{
			//***ע***����while 
			while (temp % zhishu[index] == 0)
			{
				count++;
				temp /= zhishu[index];
			}
		}
	}

	cout << count;

	return 0;
}
void getzhishu(vector<int>& v, int max)
{
	v.push_back(2);//zhishu[0]=2

	bool flag;

	for (int num = 3; num <= max; num++)
	{
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}

		if (flag)
			v.push_back(num);
	}

	for (int x : zhishu)
		cout << x << " ";
}
#endif


//8.����find()�����ķ���ֵ 
#if 0 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int shuzu[3] = { 1,2,3 };

	int* p = find(shuzu, shuzu + 3, 4);

	if (p == shuzu + 3)
		cout << "δ�ҵ���";
	else
		cout << "���ҵ���";

	return 0;
}
#endif


//9.ʮ����תʮ������ 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long num;
	cin >> num;

	cout << hex << uppercase << num;

	return 0;
}
#endif


//10.������ 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;


	int M;
	cin >> M;

	char shuzi[99999];
	fill(shuzi, shuzi + 99999, '\0');

	long num = 0;

	if (N >= 2 && N <= 10)
	{
		sprintf(shuzi, "%d", M);  //û�������N����Ľ��ƣ����������� 
		num = atoi(shuzi);
	}
	//	else
	//	{
	//		int len=M2.size();
	//		int index=0;
	//		while(len!=index)
	//		{
	//			num+=pow(16,len-index-1)*M2[index++]; //û���A~F��ʮ���������� 
	//		}
	//	}

	cout << num;

	return 0;
}
#endif
//10.���� 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string M;
	cin >> M;


	long num = 0;

	if (N != 16)
	{
		int len = M.size();

		int index = 0;
		while (len != index)
		{
			long a = pow(N, len - index - 1);

			//		cout<<a<<" ";
			//		cout<<M[index]<<" "<<a*M[index]<<" ";
			num += a * (M[index] - '0');//***ע***һ��Ҫ����д 

			index++;
		}
	}
	else
	{
		int len = M.size();

		int index = 0;
		while (len != index)
		{
			long a = pow(N, len - index - 1);

			//		cout<<a<<" ";
			//		cout<<M[index]<<" "<<a*M[index]<<" ";
			if (M[index] != 'A' && M[index] != 'B' &&
				M[index] != 'C' && M[index] != 'D' &&
				M[index] != 'E' && M[index] != 'F')
			{
				num += a * (M[index] - '0');//***ע***һ��Ҫ����д 
			}
			else if (M[index] == 'A')
			{
				num += a * (M[index] - 'A' + 10);
			}
			else if (M[index] == 'B')
			{
				num += a * (M[index] - 'B' + 11);
			}
			else if (M[index] == 'C')
			{
				num += a * (M[index] - 'C' + 12);
			}
			else if (M[index] == 'D')
			{
				num += a * (M[index] - 'D' + 13);
			}
			else if (M[index] == 'E')
			{
				num += a * (M[index] - 'E' + 14);
			}
			else if (M[index] == 'F')
			{
				num += a * (M[index] - 'F' + 15);
			}
			index++;
		}
	}

		cout<<num;

	char cnum[20];
	fill(cnum, cnum + 20, '\0');

	sprintf(cnum, "%d", num);

	//	cout<<cnum;

	string snum(cnum);//ԭ���� 
	string stemp(cnum);

	reverse(stemp.begin(), stemp.end());//�ߵ�������� 

	int count = 0;

	while (stemp != snum)
	{
		long num1 = atol(stemp.c_str());
		long num2 = atol(snum.c_str());

		sprintf(cnum, "%d", num1 + num2);//���C����ַ��� 
		snum = cnum;//���string���� 
		stemp = snum;
		reverse(stemp.begin(), stemp.end());

		count++;
	}

	if (count <= 30)
		cout << count;
	else
		cout << -1;

	return 0;
}
#endif


//11.�������� 
#if 0
#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int year, month, day;
	char a;
	cin >> year >> a
		>> month >> a
		>> day;


	set<      pair<  pair<int, int>, int >     > riqi;

	for (int y = 1960; y <= 2059; y++)
	{
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		{
			days[2] = 29;
		}


		for (int m = 1; m <= 12; m++)
		{
			for (int d = 1; d <= days[m]; d++)
			{

				int temp;

				temp = year;

				if (temp >= 60 && temp <= 99)
					temp += 1900;
				else
					temp += 2000;

				if (temp == y && month == m && day == d)
				{
					pair<int, int> a(y, m);//ʹ��pair��Ĺ��캯�� 
					pair<  pair<int, int>, int > b;

					b.first = a;
					b.second = d;

					riqi.insert(b);
				}


				temp = day;

				if (temp >= 60 && temp <= 99)
					temp += 1900;
				else
					temp += 2000;

				if (temp == y && year == m && month == d)
				{
					pair<int, int> a(y, m);
					pair<  pair<int, int>, int > b;

					b.first = a;
					b.second = d;

					riqi.insert(b);
				}


				if (temp == y && month == m && year == d)
				{
					pair<int, int> a(y, m);
					pair<  pair<int, int>, int > b;

					b.first = a;
					b.second = d;

					riqi.insert(b);
				}
			}
		}
	}

	for (auto it = riqi.begin(); it != riqi.end(); it++)
	{
		cout << setfill('0');

		cout << (*it).first.first << "-"
			<< setw(2) << (*it).first.second << "-"
			<< setw(2) << (*it).second << endl;
	}

	return 0;
}
#endif


//12.�������� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

int main()
{
	ULL num;
	cin >> num;

	cout << num << " ";
	while (num)
	{
		num /= 2;

		if (num <= 0)
			break;

		cout << num << " ";
	}

	return 0;
}
#endif


//13.����ƴ�� 
#if 0
#include <iostream>
#include <cmath>
using namespace std;

char temp[1000000000];

long get_weishu(long);

int main()
{
	long n, k;
	cin >> n >> k;

	long* get_shuzu = new long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> get_shuzu[i];
	}

	long* chuli_shuzu = new long[(1 + n - 1) * (n - 1)];

	int i = 0;
	int index = 0;
	while (i != n - 1)
	{
		long weishu1 = get_weishu(get_shuzu[i]);

		for (int j = i + 1; j < n; j++)
		{
			long weishu2 = get_weishu(get_shuzu[j]);


			long shuzi1 = get_shuzu[j] * pow(10, weishu1) + get_shuzu[i];

			chuli_shuzu[index++] = shuzi1;

			long shuzi2 = get_shuzu[i] * pow(10, weishu2) + get_shuzu[j];

			chuli_shuzu[index++] = shuzi2;
		}

		i++;
	}

	//	for(int i=0;i<(1+n-1)*(n-1);i++)
	//		cout<<chuli_shuzu[i]<<" ";

	long count = 0;
	for (int i = 0; i < (1 + n - 1) * (n - 1); i++)
	{
		if (chuli_shuzu[i] % k == 0)
			count++;
	}
	cout << count;

	delete[]get_shuzu;
	delete[]chuli_shuzu;

	return 0;
}

long get_weishu(long num)
{
	long weishu = 0;

	fill(temp, temp + 1000000000, '\0');

	sprintf(temp, "%ld", num);

	int index = 0;
	while (temp[index++] != '\0')
		weishu++;

	return weishu;
}
#endif


//14.��Ƭ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int kapian[10];//0��9�Ŀ�Ƭ���� 
	fill(kapian, kapian + 10, 2021);


#if 0 //������һ�����ֵĿ�ƬΪ0,����� 
	int* p = find(kapian, kapian + 10, 0);
	long num;
	for (num = 1; p == kapian + 10; num++)
	{
		if (num < 10)
			kapian[num]--;
		else
		{
			char temp[30];
			sprintf(temp, "%ld", num);
			//			cout<<temp<<" ";

			for (int i = 0; temp[i] != '\0'; i++)
			{
				kapian[temp[i] - '0']--;//***ע***Ҫ����д�� -'0' 

				p = find(kapian, kapian + 10, 0);
				if (p != kapian + 10)
					goto END;
			}
		}

		for (int i = 0; i < 10; i++)
			cout << kapian[i] << " ";
		cout << endl;

		p = find(kapian, kapian + 10, 0);
	}

END:	cout << num - 1;
#endif

	long num = 1;
	bool biaoji = 1;
	while (1)
	{
		if (num < 10)
			kapian[num]--;
		else
		{
			char temp[30];
			sprintf(temp, "%ld", num);
			//			cout<<temp<<" ";

			for (int i = 0; temp[i] != '\0'; i++)
			{
				kapian[temp[i] - '0']--;//***ע***Ҫ����д�� -'0' 
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (kapian[i] < 0)
			{
				biaoji = 0;
				break;
			}
		}

		if (!biaoji)
			break;

		num++;
	}

	cout << num - 1;

	return 0;
}
#endif


//15.������� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

//const long MAX=10000;

int main()
{
	long N;
	cin >> N;
	long count = 0;

	long MAX = 1000;

	//��new������ά����(�˷���������ֵ�������Ǳ���)
	//pָ��n*n�Ķ�ά����ĵ�һ�У����һ�еĵ�ַ 
	long** p = new long* [MAX]; //��MAX��Ԫ�أ�ÿ��Ԫ�ض���ָ��long��ָ��  
	for (long i = 0; i < MAX; i++)
	{
		//һά�����ָ��*(p+i)ָ��һ����MAX��Ԫ�ص����飬ÿ��Ԫ�ض���long���͵�ֵ 
		*(p + i) = new long[MAX];
	}

	//��fill()�д������ݲ��� 
	//	fill(&p[0][0],&p[0][0]+100*100,0L);
	//***ԭ��***��new�����Ķ�ά���飬���������Ϸ�ʽ�����Ķ�ά���飬
	//����Ԫ�ز���һƬ�������ڴ�����
	//��LanQiao_code��5050�е�new�����Ķ�ά������һƬ�������ڴ����� 

	for (long i = 0; i < MAX; i++)
	{
		for (long j = 0; j < MAX; j++)
		{
			p[i][j] = 0;
		}
	}

	for (long i = 1; i < MAX; i++)
	{
		for (long j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				p[i][j] = 1;
			}
			else
			{
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
			}

			//������������ǵ�ͬʱ���������ֵĸ����ļ��� 
			count++;
			if (p[i][j] == N)
				goto END;
		}
	}

	//	for(long i=1;i<10;i++)
	//	{
	//		for(long j=1;j<=i;j++)
	//			cout<<p[i][j]<<" ";
	//			
	//		cout<<endl;
	//	}

END:	cout << count;

	return 0;
}
#endif


//16.�Ȳ��������� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

long sushu[1000];

void get_sushu(long* p);

int main()
{
	get_sushu(sushu);

	//	for(long x:sushu)
	//	{
	//		cout<<x<<" ";
	//	}

	int gongcha = 1;
	int changdu = 1;
	//	while(changdu!=10)
	//	{

		//�ӵ�i�����ֿ�ʼ�� 
	for (int i = 0; i < 1000; i++)
	{
		//��i�����ӹ���Ϊ1��ʼ�ԣ�������Ϊ999���� 
		for (; gongcha < 1000; gongcha++)
		{
			long temp = sushu[i] + gongcha;
			long* loc = find(sushu, sushu + 1000, temp);
			while (loc != sushu + 1000 && changdu != 10)
			{
				changdu++;

				temp = sushu[i] + gongcha * changdu;
				loc = find(loc, sushu + 1000, temp);
			}

			//������Ϊ10��ǿ���˳�����ѭ��	
			if (changdu == 10)
				goto END;
			else
				changdu = 1;
		}

		if (changdu != 10)
		{
			changdu = 1;
			gongcha = 1;
		}
		else
			break;
	}
	//	}

END:	cout << gongcha;

	return 0;
}
void get_sushu(long* p)
{
	p[0] = 2;

	int index = 1;
	bool flag;
	for (int i = 3; i < 5000; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}

		if (flag)
			p[index++] = i;
	}
}
#endif


//17.�˻�β�� 
#if 0
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long LL;

int main()
{
	ifstream fin;
	fin.open("3.3.txt");

	LL num = 1;
	LL temp;
	int count = 0;
	while (fin >> temp)
	{
		num *= temp;

		cout.width(20);
		cout << num << "\t";

		char chstr[30];
		fill(chstr, chstr + 30, '\0');
		sprintf(chstr, "%ld", num);

		//����д��һ��		
		//		for(int i=0;chstr[i]!='\0';i++)
		//		{
		//			if(chstr[i]=='0')
		//			{
		//				count++;//���������ַ�0�޸�Ϊ\0 
		//				chstr[i]='\0';
		//			}
		//		}	

		//����д������
		//		string str(chstr);
		//		int loc=str.find_last_of('0');

		string str(chstr);
		int loc = str.size() - 1;

		//�����ֵĵ�λ���λ���������
		for (int i = loc; chstr[i] == '0'; i--)
		{
			if (chstr[i] == '0')
			{
				count++;//���������ַ�0�޸�Ϊ\0 
				chstr[i] = '\0';
			}
		}

		num = atol(chstr);//���β��0������ 
		cout.width(20);
		cout << num << "\t";

		num %= 100000;//����Ϊ�ض̺������ 
		cout << num << "\n";
	}

	fin.close();

	cout << count;

	return 0;
}
#endif


//18.���ķֽ� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;

const int NUM = 2019;

int main()
{
	vector<int> tempv;
	set<vector<int>> data;
	char tempc[5];

	for (int i = 1; i < NUM; i++)
	{
		sprintf(tempc, "%d", i);

		if (strchr(tempc, '2') != NULL || strchr(tempc, '4') != NULL)
			continue;

		for (int j = 1; j < NUM; j++)
		{
			sprintf(tempc, "%d", j);

			if (strchr(tempc, '2') != NULL || strchr(tempc, '4') != NULL)
				continue;

			//			for(int k=1;k<NUM;k++)
			//			{				
			//				sprintf(tempc,"%d",k);
			//						
			//				if(strchr(tempc,'2')!=NULL||strchr(tempc,'4')!=NULL)
			//					continue;				
			//					
			//				if(i+j+k==NUM)
			//				{
			//					tempv.push_back(i);
			//					tempv.push_back(j);
			//					tempv.push_back(k);
			//					sort(tempv.begin(),tempv.end());
			//					
			//					cout<<i<<" "<<j<<" "<<k<<endl;
			//					
			//					data.insert(tempv);
			//					
			//					tempv.clear();
			//				}
			//			}

						//***ע*** 
						//��취���ٵ�����ѭ�� 
			int k = NUM - i - j;

			sprintf(tempc, "%d", k);

			if (strchr(tempc, '2') != NULL || strchr(tempc, '4') != NULL)
				continue;

			if (k > 0 && i != j && i != k && j != k)
			{
				tempv.push_back(i);
				tempv.push_back(j);
				tempv.push_back(k);

				//���������setȥ�� 
				sort(tempv.begin(), tempv.end());

				//				cout<<i<<" "<<j<<" "<<k<<endl;

				data.insert(tempv);

				tempv.clear();
			}

		}
	}

	cout << data.size();

	return 0;
}
#endif


//19. �ر���֮�� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	char temp[6];
	bool flag;
	long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(temp, temp + 6, '\0');
		sprintf(temp, "%d", i);
		for (int index = 0; temp[index]; index++)
		{
			if (temp[index] == '2' || temp[index] == '0' ||
				temp[index] == '1' || temp[index] == '9')
			{
				flag = 1;
				break;//һ��Ҫ�� 
			}
			else
				flag = 0;
		}

		if (flag)
			sum += i;
	}

	cout << sum;

	return 0;
}
#endif


//20.��ȫ��������Ȩֵ 
#if 0
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> get_data(N + 1);

	get_data.assign(N + 1, 0);//��N+1��0��vector������ 

	//����Ϊ1����Ӧ��һ��Ԫ�� 
	for (int i = 1; i < N + 1; i++)
	{
		cin >> get_data[i];
	}

	//������� 
	int deep = log2(N) + 1;
	//	cout<<deep<<endl;

	vector<int> vdata;
	for (int i = 1; i <= deep; i++)
	{
		int sum = 0;
		for (int j = pow(2, i - 1); j <= pow(2, i) - 1; j++)
		{
			sum += get_data[j];
		}
		vdata.push_back(sum);
	}

	int max = vdata[0];

	for (auto p = vdata.begin(); p != vdata.end(); p++)
	{
		//		cout<<*p<<endl;
		max = (*p > max) ? (*p) : (max);
	}
	//	cout<<max<<endl;
	vector<int> ::iterator x = find(vdata.begin(), vdata.end(), max);

	cout << x - vdata.begin() + 1;

	return 0;
}
//7
//1 6 5 4 3 2 1
#endif


//21.�Ȳ����� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> get_data(N);

	for (int i = 0; i < N; i++)
	{
		cin >> get_data[i];
	}

	sort(get_data.begin(), get_data.end());

	int gongcha = get_data[1] - get_data[0];

	int xiangshu = (get_data[N - 1] - get_data[0]) / gongcha + 1;

	cout << xiangshu;

	return 0;
}
#endif


//23.�ܲ�ѵ�� 
#if 0
#include <iostream>

using namespace std;

#define XIAOHAO_PER_SEC 10
#define HUIFU_PER_SEC   5

int main()
{
	int tili = 10000;

	int sec = 0;
	while (1)
	{
		if (tili >= 600)
		{
			tili -= XIAOHAO_PER_SEC * 60;
			sec += 60;
		}
		else
		{
			while (tili)
			{
				tili -= XIAOHAO_PER_SEC;
				sec++;
			}
		}

		if (tili == 0)
		{
			break;
		}

		tili += HUIFU_PER_SEC * 60;
		sec += 60;
	}

	cout << sec;

	return 0;
}
#endif


//24.�ϲ����
//�ο�
//https://blog.csdn.net/CodingFire/article/details/126489570
#if 0
#include <iostream>

using namespace std;

int main()
{
	//������
	int zongrenshu = 5000;
	//һ�����������Сֵ
	int min = 9999;
	//һ����������Լ���������������
	int k, sum, ans;

	for (k = 1; k < 100; k++)
	{
		//���պó���
		if (zongrenshu % k == 0)
		{
			/*
		 zongrenshu/k���״μ����ô������Ҫ���Լ��У�0.01*zongrenshu�ǳ��ָ�Ⱦ�˵�������
		 ��Ϊ��Ⱦ����ƽ���ֲ��ģ����Կ�����Ϊ��0.01*m�ķ����У�ÿ���
		 ��һ����Ⱦ�ߣ���Ҫ����Щ���ÿһ���˽��е����ļ�⣬ÿ������Ϊk��
		 ����μ����Ҫ0.01*zongrenshu*k�����У�����������һ���ļ����
		 */
			sum = zongrenshu / k + 0.01 * zongrenshu * k;
		}
		else
		{
			/*
		 �����������һ���ĵ�����Ϊ��������������Ҫ��������һ�����У�
		 ���������и�����������������Ⱦ�߸պô���������������k�˵�
		 �����У���һ���ܼ���Լ������ǲ���k�ģ�������������������ˣ�
		 ԭ���ǣ���ʹ����k�ˣ����Ҳ�������Ǽ�������ȫ�������΢�������
		 �����ķ���һ��Ҳ���ڼ��������������ּ��͸����¼������ִ�������
		 ������¿��Ժ��Բ��ơ���ͬѧ���в�����ţ�Ǽ⣬�����Ϊ�ء���
		 */
			sum = zongrenshu / k + 0.01 * zongrenshu * k + 1;
		}

		if (sum < min)
		{
			min = sum;
			ans = k;
		}
	}

	cout << ans;

	return 0;
}
#endif


//25.ֱ��
#if 0
#endif


//26.����ڷ�
#if 0
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
int main()
{
	LL num = 2021041820210418;

	//	LL *p_gongyinshu=new LL []; 
	vector <LL>v;

	for (LL i = 1; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			v.push_back(i);

			if (num / i != i)
			{
				v.push_back(num / i);
			}
		}
	}

	//	for(LL x:v)
	//	cout<<x<<endl;

	long count = 0;
	for (auto p1 = v.begin(); p1 != v.end(); p1++)
	{
		for (auto p2 = v.begin(); p2 != v.end(); p2++)
		{
			for (auto p3 = v.begin(); p3 != v.end(); p3++)
			{
				if (*p1 * *p2 * *p3 == num)
					count++;
			}
		}
	}

	cout << count;

	return 0;
}
#endif


//27.��ѹ���� 
#if 0
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	ifstream fin;
	fin.open("4.2.txt");

	LL jinzita[31][31];
	fill(&jinzita[30][0], &jinzita[30][0] + 31, 0L);

	LL temp;
	for (int i = 1; i <= 29; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			fin >> temp;
			temp *= pow(2, 29);//***ע***���ֵ��ô���ģ��Ǹ��ѵ� 
			jinzita[i][j] = temp;

			//fin>>jinzita[i][j];
		}
	}

	fin.close();

	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << jinzita[i][j] << " ";
		}
		cout << endl;
	}
	cout.put('\n');

	cout << jinzita[1][1] << endl;
	for (int i = 2; i <= 30; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i > 1 && j == 1)
			{
				jinzita[i][j] += jinzita[i - 1][j] / 2;
			}
			else if (i > 1 && j == i)
			{
				jinzita[i][j] += jinzita[i - 1][j - 1] / 2;
			}
			else
			{
				jinzita[i][j] += jinzita[i - 1][j - 1] / 2 + jinzita[i - 1][j] / 2;
			}

			cout << jinzita[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	//STL��max����ֻ�ܱȽ��������� 
	//	LL Max=max(&jinzita[30][1],&jinzita[30][31]);
	LL Min = 9999999999999999;
	LL Max = 1;
	for (int i = 1; i <= 30; i++)
	{
		Min = jinzita[30][i] > Min ? Min : jinzita[30][i];
		Max = jinzita[30][i] < Max ? Max : jinzita[30][i];
	}
	cout << Min << endl << Max;

	return 0;
}
#endif


//28.������ֵ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL LIM = 20190324;

	LL* p_num = new LL[LIM + 1];
	fill(p_num, p_num + LIM + 1, 0L);

	p_num[1] = p_num[2] = p_num[3] = 1;

	for (LL i = 4; i <= LIM; i++)
	{
		p_num[i] = p_num[i - 1] + p_num[i - 2] + p_num[i - 3];
		p_num[i] = p_num[i] % 100000000000;
	}

	cout << p_num[LIM];

	return 0;
}
#endif


//29.���ɿ��� 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long N, K;
	cin >> N >> K;

	vector<long> v_data[N + 1];

	for (int i = 1; i <= N; i++)
	{
		long temp;
		cin >> temp;
		v_data[i].push_back(temp);
		cin >> temp;
		v_data[i].push_back(temp);
	}

	int pieces = 0;
	int bianchang = 1;
	while (1)
	{

		for (int i = 1; i <= N; i++)
		{

			//������⣺ 
			//		//STL��min()���� 
			//			long chuli_data=min(v_data[i][0],v_data[i][1]);


			int pie = (v_data[i][0] / bianchang) *
				(v_data[i][1] / bianchang);

			pieces += pie;
		}

		if (pieces < K)
			break;

		pieces = 0;
		bianchang++;
	}

	cout << bianchang - 1;

	return 0;
}
#endif


//30.������Ԫ�� 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	//	int *A=new int[N]; 
	//	int *B=new int[N]; 
	//	int *C=new int[N]; 

	int** data = new int* [4];

	for (int i = 1; i <= 3; i++)
	{
		*(data + i) = new int[N + 1];
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int index = 1; index <= N; index++)
		{
			cin >> *(*(data + i) + index);
		}
	}

#if 0
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (data[1][i] < data[2][j] < data[3][k])
				{
					count++;
				}
			}
		}
	}
#endif

	//�Ż�д��
#if 1
	int count = 0;
	int count1 = 0, count2 = 0;

	//����д����
	//	for(int i=1;i<=N;i++)
	//	{
	//		for(int j=1;j<=N;j++)
	//		{
	//			for(int k=1;k<=N;k++)
	//			{
	//				if(data[1][i]<data[2][j])
	//				{
	//					count1++;
	//				}
	//				if(data[2][j]<data[3][k])
	//				{
	//					count2++;
	//				}			
	//				
	//				count+=count1*count2;
	//				count1=count2=0;
	//			}
	//		}
	//	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)//�Ȱ�����B��ֵ�̶����ж�A��C�з���������Ԫ�ظ���
		{
			if (data[1][j] < data[2][i])
				count1++;

			if (data[3][j] > data[2][i])
				count2++;

		}
		count += count1 * count2;
		count1 = count2 = 0;
	}

#endif

	cout << count;

	return 0;
}
#endif


//31.�˻����
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

bool mycompare(long a, long b);

int main()
{
	long N, K;
	cin >> N >> K;

	long* p_data = new long[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> p_data[i];
	}

	sort(p_data, p_data + N + 1, mycompare);

	//������ 
	//	sort(p_data,p_data+N+1);
	//	reverse(p_data,p_data+N+1);

	//	for(int i=1;i<=N;i++)
	//	{
	//		cout<<p_data[i]<<" ";
	//	}

	/************************************/
	//���㸺���ĸ���
	int fushu = 0;
	for (int i = 1; i <= N; i++)
	{
		if (p_data[i] < 0)
			fushu++;
	}
	/************************************/

	long res = 1;

	if (K == N)
	{
		for (int i = 1; i <= N; i++)
		{
			res *= p_data[i];
			res %= 10000000009;
		}
	}

	if (K < N)
	{
		if (K == 1)
		{
			res = p_data[N];
		}
		else if (K % 2 == 0)//���k��ż��
		{
			if (fushu % 2 == 0)//��������и����ĸ�����ż��
			{
				for (int i = 1; i <= N; i++)
				{
					if (p_data[i] < 0)
						p_data[i] = -p_data[i];//������Ϊ����������������
				}
				sort(p_data, p_data + N + 1, mycompare);
				//�����޷�����-5 -1 1 2 3 ȡ���������				
				for (int i = 1; i <= K; i++)
				{
					res *= p_data[i];
					res %= 1000000009;
				}
			}
			else
			{

			}

		}
		else
		{

		}
	}

	cout << res;

	return 0;
}
bool mycompare(long a, long b)
{
	bool flag;

	flag = a > b ? 1 : 0;

	return flag;
}
#endif
//��next_permutation()�ò��ַ��� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

//bool mycompare(long a,long b);

int main()
{
	long N, K;
	cin >> N >> K;

	long* p_data = new long[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> p_data[i];
	}

	//***ע***��next_permutation()�Ļ��������ݱ����ǵ�����
	sort(p_data + 1, p_data + N + 1);

	//����д����
	//	sort(p_data,p_data+N+1,mycompare); 	

	long res = 1;
	long max = -999999999;

	//����д����
#if 0
	while (next_permutation(p_data + 1, p_data + N + 1))
	{
		//		for(int i=1;i<=N;i++)
		//		{
		//			cout<<p_data[i];
		//		}
		//		cout<<endl;

		for (int i = 1; i <= K; i++)
		{
			res *= p_data[i];

			//����ķ���λ�ã�	
			//			if(res>0)
			//			res%=1000000009;
			//			else
			//			{
			//				res=-(-res%1000000009);
			//			}
		}
		......
	}

#endif

		do
		{
			//		for(int i=1;i<=N;i++)
			//		{
			//			cout<<p_data[i];
			//		}
			//		cout<<endl;

			for (int i = 1; i <= K; i++)
			{
				res *= p_data[i];

				//����ķ���λ�ã�	
				//			if(res>0)
				//			res%=1000000009;
				//			else
				//			{
				//				res=-(-res%1000000009);
				//			}
			}

			max = res > max ? res : max;

			res = 1;

		} while (next_permutation(p_data + 1, p_data + N + 1));
				

	//***ע***
	//������������ȼ�����<<���ʱ���Ҫ��<<�����Բ���� 
	cout << ((max > 0) ? max % 1000000009L : -(-max % 1000000009L));

	return 0;
}
//bool mycompare(long a,long b)
//{
//	bool flag;
//	
//	flag=a>b?1:0;
//	
//	return flag;
//}

//5 3
//-100000
//-10000
//2
//100000
//10000

//5 3
//-100000
//-100000
//-2
//-100000
//-100000
#endif


//33.��׺���ʽ 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long N, M;
	cin >> N >> M;

	long T = N + M + 1;

	long* p = new long[N + M + 2];
	for (long i = 1; i <= N + M + 1; i++)
	{
		cin >> p[i];
	}

	sort(p + 1, p + N + M + 2);

	long res = 0;
	if (M == 0)
	{
		for (long i = 1; i <= N + M + 1; i++)
		{
			res += p[i];
		}
	}
	else
	{
		reverse(p + 1, p + N + M + 2);//���еݼ�

		for (long i = 1; i <= N + M; i++)
		{
			res += p[i];
		}

		res -= p[N + M + 1];
	}

	cout << res;

	return 0;
}
//�д���
//�𰸼�LanQiao_code L3040 
#endif


//34.��DFS���Թ� 
#if 0
bool seekpath(int ix, int iy)
{
	if (ix == ox && iy == oy)
	{
		return ture;
	}

	int m, n;

	for (int i = 0; i < 4; i++)
	{
		m = ix + dx[i];
		n = iy + dy[i];

		if (migong[m][n] == 0 && mark[m][n] == 0)
		{
			mark[m][n] = 1;

			if (seekpath(m, n))
			{
				cout << "(" << m << "," << n << ")" << endl;
				return true;
			}
		}
	}

	return false;
}
#endif


//35.����ָ� 
#if 0
#include <iostream>

using namespace std;

bool mark[7][7];
bool dfs(int ix, int iy);
int count = 0;

int main()
{
	//	int area[7][7];//x���y������귶ΧΪ0~6 

	int ix = 3, iy = 3;

	//***����4��***	
	mark[ix][iy] = 1;

	dfs(ix, iy);

	//����3�� 
	cout << count / 4;

	return 0;
}
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool dfs(int ix, int iy)
{
	int ix2, iy2;//��(ix,iy)��ԭ��Ϊ���ĶԳ� 
	ix2 = 6 - ix;
	iy2 = 6 - iy;

	if (ix == 0 || ix == 6 || iy == 0 || iy == 6 ||
		ix2 == 0 || ix2 == 6 || iy2 == 0 || iy2 == 6)
	{
		count++;
		return true;
	}

	int m, n;
	for (int i = 0; i < 4; i++)
	{
		m = ix + dx[i];
		n = iy + dy[i];

		if (mark[n][m] == 0)
		{
			mark[n][m] = 1;

			//����1��
			mark[6 - n][6 - m] = 1;

			//����д����
			//����д�൱�����Թ����ҵ����ں��ֹͣdfs�ˡ�			
			//			if(dfs(m,n))
			//			{
			//				mark[n][m]=0;//������һ������о����ĵ�������Ϊ0 
			//				return true;
			//			}


			dfs(m, n);
			mark[n][m] = 0;
			//����2��
			mark[6 - n][6 - m] = 0;
		}
	}

	return false;
}
#endif


//36.��� 
#if 0
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int data[21][6];
int rates[6][21];
bool mark[21];

bool dfs(int num, int x);
int Max;

int main()
{
	ifstream fin("6.3.txt");

	for (int i = 1; i <= 20; i++)
	{
		int temp;
		fin >> temp;

		for (int j = 1; j <= 5; j++)
			fin >> data[i][j];
	}

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			rates[i][j] = data[j][i];
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			cout << rates[i][j] << " ";
		}
		cout << endl;
	}


	dfs(1, 0);
	//����д����	
	//	dfs(0,0); 

	cout << Max;

	fin.close();

	return 0;
}

bool dfs(int num, int x)
{
	//����д����
	//	if(num==5)

	if (num > 5)
	{
		Max = max(Max, x);

		return true;
	}

	for (int i = 1; i <= 20; i++)
	{
		if (!mark[i])
		{
			mark[i] = 1;

			//����
			//			dfs(num+1,x+data[num][i]);

			//д��һ��
			dfs(num + 1, x + data[i][num]);
			//д������
			//			dfs(num+1,x+rates[num][i]); 

			mark[i] = 0;
		}

	}
}
#endif


//37.ȫ���ů
//��Ŀ���Լ�ΪѰ��һ��½�أ�
//�Ҹÿ�½�ص��������Ҷ���½�أ�
//��ÿ�½�ز��ᱻ��û 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[10010][10010];
bool dfs(char** p, int x, int y);
int count1 = 0;
bool check(char** p, int x, int y);

int main()
{
	int N;
	cin >> N;

	fill(&mark[0][0], &mark[0][0] + 10010 * 10010, 1);

	//����д����
	//	char** p=new char[N+1][N+1];

	char** p = new char* [N + 1];
	for (int i = 1; i <= N; i++)
	{
		p[i] = new char[N + 1];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> p[i][j];
			mark[i][j] = 0;
		}
	}
	//������������γɵ��������������Χ��mark��ֵ��Ϊ1 

//	for(int i=1;i<N+1;i++)
//	{
//		for(int j=1;j<N+1;j++)
//		{
//			cout<<p[i][j]<<" ";
//		}
//		cout<<endl;
//	}	

	//���㵺�������
	int daoyu = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dfs(p, i, j);

			if (count1)
				daoyu++;

			count1 = 0;
		}
	}

	cout << "ԭ����������";
	cout << daoyu << endl;


	int remain = 0;

	fill(&mark[0][0], &mark[0][0] + 10010 * 10010, 1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			mark[i][j] = 0;
		}
	}

	//��δ��û�ĵ������� 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (p[i][j] == '#')
			{
				if (check(p, i, j))
					remain++;
			}
		}
	}
	cout << "δ��û�ĵ���������";
	cout << remain << endl;

	cout << daoyu - remain;

	return 0;
}
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool dfs(char** p, int x, int y)
{
	//���жϵ�(x,y) 
	if (mark[x][y] == 0 && p[x][y] == '#')
	{
		mark[x][y] = 1;
		count1++;
	}

	//���ж�(x,y)������ܵĵ� 
	int m, n;
	for (int i = 0; i < 4; i++)
	{
		m = x + dx[i];
		n = y + dy[i];

		if (mark[m][n] == 0 && p[m][n] == '#')
		{
			mark[m][n] = 1;
			count1++;
			dfs(p, m, n);
		}

	}
}

bool check(char** p, int x, int y)
{
	int m, n;
	int count2 = 0;
	//***ע***���ܱ���ѷ��ʣ�
	//�˺������ж�ÿ�������Χ4�������� 
	//	mark[x][y]=1;

	for (int i = 0; i < 4; i++)
	{
		m = x + dx[i];
		n = y + dy[i];


		if (mark[m][n] == 0 && p[m][n] == '#')
		{
			//			mark[m][n]=1;
			count2++;
		}
	}

	return (count2 == 4) ? true : false;
}
//7
//. . . . . . .
//. # # . . . .
//. # # . . . .
//. . . . # # .
//. . # # # # .
//. . . # # # .
//. . . . . . .
#endif


//38.BFS 
#if 0
void bfs(int x, int y)
{
	queue<node> qn;

	qn.push(create_node(0, 0, ""));
	visited[x][y] = 1;

	while (!qn.empty())
	{
		node t = qn.front();
		qn.pop();

		for (int i = 0; i < 4; i++)
		{
			int xn = t.x + dir[i][0];
			int yn = t.y + dir[i][1];

			//��δԽ����δ�����Ҳ����ϰ� 
			if (xn >= 0 && xn < ROW && yn >= 0 && yn < COL &&
				!visited[xn][yn] && migong[xn][yn] != '1')
			{
				if (xn == ROW - 1 && yn == COL - 1)
				{
					cout << t.s << zimu[i] << endl;	//ע��ҲҪ��zimu[i]һ�������Ϊ��ʱ����û�б��ӵ�t.s
					return;
				}
				else
				{
					visited[xn][yn] = 1;//Ӧ����string��+��������غ�����ƴ���ַ��� 
					qn.push(create_node(xn, yn, t.s + zimu[i]));
				}
			}
		}
	}
}
#endif


//39.�һ�Ӳ������(��άdp����)
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int coin[4] = { 0,2,5,9 };

	int dp[4][22];

	fill(&dp[0][0], &dp[0][0] + 4 * 22, 65535);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 21; j++)
		{
			dp[i][0] = 0;

			if (j < coin[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i]] + 1);
		}
	}

	for (int i = 1; i <= 21; i++)
	{
		cout << setw(5) << i << " ";
	}
	cout.put('\n');

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 21; j++)
		{
			cout << setw(5);
			cout << dp[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}
#endif
//39.�һ�Ӳ������(һάdp����)
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int coin[4] = { 0,2,5,9 };

	int dp[22];

	fill(dp, dp + 22, 65535);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 21; j++)
		{
			dp[0] = 0;

			if (j < coin[i])
				continue;
			else
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}

	}

	for (int i = 1; i <= 21; i++)
	{
		cout << setw(5) << i << " ";
	}
	cout.put('\n');

	for (int j = 1; j <= 21; j++)
	{
		cout << setw(5);
		cout << dp[j] << " ";
	}


	return 0;
}
#endif


//40.���Ӵ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int dp[maxn][maxn];

int main()
{
	int N;
	cin >> N;

	int* w = new int[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> w[i];
	}

	//ÿ��������value��Ϊ1

	fill(&dp[0][0], &dp[0][0] + maxn * maxn, 65535);

	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 0;

		for (int j = 1; j <= maxn; j++)
		{
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - w[i]] + 1);
		}
	}

	//	for(int i=1;i<=maxn;i++)
	//	{
	//		cout<<dp[N][i]<<" ";
	//	}
	//	cout<<endl; 

	int count = 0;
	for (int i = 1; i <= maxn; i++)
	{
		if (dp[N][i] == 65535)
			count++;
	}

	if (count <= 500)
		cout << count;
	else
		cout << "INF";

	return 0;
}
#endif


//41.K������ 
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long N, K;
	cin >> N >> K;

	vector<long> v(N + 1);

	for (long i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	long long sum = 0;
	long count = 0;
	for (long left = 1; left <= N; left++)
	{
		for (long right = left; right <= N; right++)
		{
			sum += v[right];

			if (sum % K == 0)
				count++;
		}

		sum = 0;
	}

	cout << count;

	return 0;
}
#endif


//42.���� 
#if 0
#include<iostream>
using namespace std;
/*
dp[i][j] iΪ��һ�еĸ��� jΪ�ڶ��е����ָ���
�о�����(��ʵ����ֽ���Լ�д)��dp[2][1] = 2  dp[2][2] = 2  dp[3][0] = 1  dp[3][1] = 3  dp[3][2]=5
����i>j  dp[i][j] = dp[i-1][j] + dp[i][j-1]
����i==j dp[i][j] = dp[i][j-1]
������i<j����Ϊ��Ŀ�����޶��˵�һ��һ����С�ڵڶ��е����ָ�����
*/

// С����: ��Ҫ���ܴ�������main���治���ջ�ռ�ű�. 
int dp[1011][1011];// ÿһ���ʼֵ��0 
int main()
{
	// ���ⶼ�Ǵ�С����ģ�һ��ʼ��1������Ȼ��2������3����...һֱ����2020����
	// dp[i][j] iΪ��һ�е����ָ�����j�ǵڶ��е����ָ���������Ϊi>j��i==j
	for (int i = 0; i <= 1010; i++)
	{
		for (int j = 0; j <= 1010; j++)
		{
			// dp[i][0] ��������ֻ�ŵ�һ�У���������������ֻ��һ·���� ��>��12345... 134...
			// ����ֻ��1�������� 
			if (j == 0)
			{
				dp[i][0] = 1;
				continue;
			}

			// ������i<j����� 
			if (i < j)
			{
				break;
			}

			if (i > j)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 2020;
			}
			else if (i == j)
			{
				dp[i][j] = dp[i][j - 1] % 2020;
			}

		}
	}
	// �����
	cout << "ֻ���ĸ����������һ��2���ڶ���2����" << dp[2][2] << endl;
	cout << "ֻ���ĸ����������һ��3���ڶ���1����" << dp[3][1] << endl;
	cout << "ֻ���ĸ����������һ��4���ڶ���0����" << dp[4][0] << endl;
	cout << "ֻ�а˸����������һ��4���ڶ���4����" << dp[4][4] << endl;
	cout << "��ô����2020�������£���Ҫ��ÿһ�ж���1010����" << dp[1010][1010] << endl;
	return 0;
}
#endif


//43.�߷��� 
#if 0
#include <iostream>

using namespace std;

int dp[60][60];

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
				continue;

			if (j == 1)
			{
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=m;j++)
	//		{
	//			cout<<dp[i][j]<<" ";
	//		}
	//		
	//		cout<<endl;
	//	}

	cout << dp[n][m];

	return 0;
}
#endif


//44.������� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

//long dp[110][];
int main()
{
	long N;
	cin >> N;

	long* w = new long[N + 1];

	for (long i = 1; i <= N; i++)
	{
		cin >> w[i];
	}

	sort(w+1,w+N+1);

	//***ע***�����ǳ���ʱ�Ķ�ά����Ĵ������� 
	long(*dp)[100010] = new long[110][100010];

	fill(&dp[0][0], &dp[0][0] + 110 * 100010, 0);

	//	for(int i=0;i<100;i++)
	//	{
	//		for(int j=0;j<100;j++)
	//			cout<<dp[i][j]<<" ";
	//		cout<<endl;
	//	}	

	dp[0][0] = 1;

	for (long i = 1; i <= N; i++)
	{
		long sum = 0;

		for (long c = 1; c <= i; c++)
		{
			sum += w[i];
		}

		dp[i][0] = 1;

		for (long j = 1; j <= sum; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];
				//				continue;
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][w[i] - j]);
			}
			//			else if(j==w[j])
			//			{
			//				dp[i][j]=1;
			//			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]]);

		}
	}

	//for (long i = 0; i <= 3; i++)
	//{
	//	for (long j = 0; j <= 11; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

		long count=0;
		for(long i=1;i<=100010;i++)
		{
			if(dp[N][i]==1)
				count++;
		}

		cout<<count;

	return 0;
}
#endif


//45.�������� 
//***ע***���ű�������atoi() 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int ctoi(string& str);

int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	string str;

	getline(cin, str);

	string temp1(&str[0], &str[4]);
	int year = ctoi(temp1);
	//	cout<<year;

	string temp2(&str[4], &str[6]);
	int month = ctoi(temp2);
	//	cout<<month;

	string temp3(str, 6, 2);
	int day = ctoi(temp3);
	//	cout<<day;

	//��ȡ�����յ��������ֵ����ķ����ǳ���ȡ��
	//int year=date/10000;
	//int month=date/100%100;
	//int day=date%100; 

	for (int y = year; y <= 8999; y++)
	{
		//�ж����� 
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			days[2] = 29;

		if (y == year)
			for (int m = month; m <= 12; m++)
			{
				for (int d = day + 1; d <= days[m]; d++)
				{
					char data[9];

					sprintf(data, "%d", y);

					if (m < 10)
					{
						data[4] = '0';
						sprintf(data + 5, "%d", m);
					}
					else
					{
						sprintf(data + 4, "%d", m);
					}


					if (d < 10)
					{
						data[6] = '0';
						sprintf(data + 7, "%d", d);
					}
					else
					{
						sprintf(data + 6, "%d", d);
					}

					//				cout<<data<<endl;
					char data1[9];
					//ͷָ�� ��βָ�� 
					copy(data, data + 9, data1);//���������ַ�������(����ĩβ�Ŀ��ַ�) 
					//***ע***�˴����ַ��������ĩβ�Ŀ��ַ���Ҫ�������ֻ��+8			
					reverse(data1, data1 + 8);
					//				cout<<data1<<endl;

					string str2(data);

					string str3(data1);

					if (str2 == str3)
					{
						cout << str2 << endl;
						goto STEP1;
					}
				}
			}
		else
		{
			for (int m = 1; m <= 12; m++)
			{
				for (int d = 1; d <= days[m]; d++)
				{
					char data[9];

					sprintf(data, "%d", y);

					if (m < 10)
					{
						data[4] = '0';
						sprintf(data + 5, "%d", m);
					}
					else
					{
						sprintf(data + 4, "%d", m);
					}


					if (d < 10)
					{
						data[6] = '0';
						sprintf(data + 7, "%d", d);
					}
					else
					{
						sprintf(data + 6, "%d", d);
					}

					//				cout<<data;
					char data1[9];

					copy(data, data + 9, data1);

					reverse(data1, data1 + 8);

					string str2(data);

					string str3(data1);

					if (str2 == str3)
					{
						cout << str2 << endl;
						goto STEP1;
					}
				}
			}

		}
	}

STEP1:
	for (int y = year; y <= 8999; y++)
	{
		if (y == year)
			for (int m = month; m <= 12; m++)
			{
				for (int d = day + 1; d <= days[m]; d++)
				{
					char data[9];

					sprintf(data, "%d", y);

					if (m < 10)
					{
						data[4] = '0';
						sprintf(data + 5, "%d", m);
					}
					else
					{
						sprintf(data + 4, "%d", m);
					}


					if (d < 10)
					{
						data[6] = '0';
						sprintf(data + 7, "%d", d);
					}
					else
					{
						sprintf(data + 6, "%d", d);
					}

					//***ע***����д�� 
	//				if(data[0]==data[2]==data[5]==data[7]
	//				&&data[1]==data[3]&&data[4]==data[6])
					if (data[0] == data[2] && data[0] == data[5] && data[0] == data[7]
						&& data[1] == data[3] && data[1] == data[4] && data[1] == data[6])
					{
						cout << data;
						goto STEP2;
					}
				}
			}
		else
		{
			for (int m = 1; m <= 12; m++)
			{
				for (int d = 1; d <= days[m]; d++)
				{
					char data[9];

					sprintf(data, "%d", y);

					if (m < 10)
					{
						data[4] = '0';
						sprintf(data + 5, "%d", m);
					}
					else
					{
						sprintf(data + 4, "%d", m);
					}


					if (d < 10)
					{
						data[6] = '0';
						sprintf(data + 7, "%d", d);
					}
					else
					{
						sprintf(data + 6, "%d", d);
					}

					if (data[0] == data[2] && data[0] == data[5] && data[0] == data[7]
						&& data[1] == data[3] && data[1] == data[4] && data[1] == data[6])
					{
						cout << data;
						goto STEP2;
					}
				}
			}

		}
	}


STEP2:	return 0;

}
int ctoi(string& str)
{
	int num = 0;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		num += (str[i] - '0') * pow(10, str.size() - i - 1);
	}

	//	cout<<num;
	return num;
}
//��ʵ������string���еķ�����stoi() 
#endif 


//46.Ӯ��Ʊ 
//***���ʹ�õ������۲������ֵ*** 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	vector<int> beifen(v);//***

	bool flag = 0;
	int sum = 0;
	int Sum = 0;

	int N1 = N;

	//���������ֵ���ĸ�����ֵ��ʼ 
	for (int begin = 1; begin <= N1; begin++)
	{
		int i;
		int count = 1;

		//���������ֵi��begin��ʼ��N����������ѭ�� 
		for (i = begin; count <= 1000; i++)
		{
			if (i > N)
				i = 1;

			if (count == v[i])
			{
				sum += count;
				v.erase(v.begin() + i);

				N -= 1;//***
				i--;//***ɾ��һ��Ԫ�غ���������for�Ὣi��1��v[i]���Ǳ�ɾ����Ԫ�ص���һ��Ԫ�عʴ˴��ȼ�1***

				flag = 1;
			}

			if (!flag)
			{
				count++;
			}
			else
			{
				count = 1;
				flag = 0;//***
			}

			//***��д�Ļ���ʱ��iΪ0��v[0]��δ֪�� 
			if (N == 0)
				break;
		}

		//***
		N = N1;
		//***		
		v = beifen;

		Sum = max(Sum, sum);

		//***
		sum = 0;
	}

	cout << Sum;

	return 0;
}
#endif 


//47.��Լ���� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int count = 0;

	for (int i = 1; i <= 2020; i++)
	{
		for (int j = 1; j <= 2020; j++)
		{
			if (__gcd(i, j) == 1)
			{
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
#endif 


//48.�Ź��÷� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int nine[4][4];

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> nine[i][j];
		}
	}

	//˼·��ȫ���У��������нⷨ������������ݶ��� 
	int quan[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//�洢���еķ���Ҫ��ľŹ��÷� 
	int nine1[4][4];
	//������������Ĳ��ֵľŹ��÷�
	int nine2[4][4];

	int count = 0;
	bool flag = 0;

	//ʹ��next_permutation()�Ļ������
	//do...while���

	while (next_permutation(quan + 1, quan + 10))
	{

		int i, j;
		int index = 1;

		for (i = 1; i <= 3; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				nine1[i][j] = quan[index++];

				//				cout<<nine1[i][j]<<" " ;							
			}
			//			cout<<'\n';
		}

		int sum1 = 0;
		int sum2[4];
		for (int a = 1; a <= 3; a++)
		{
			for (int b = 1; b <= 3; b++)
			{
				sum1 += nine1[a][b];
			}

			sum2[a] = sum1;
			sum1 = 0;
		}

		//�ж��Ƿ�����Ź��÷���Ҫ�� 
		if (sum2[1] == sum2[2] && sum2[1] == sum2[3])
		{
			for (int a = 1; a <= 3; a++)
			{
				for (int b = 1; b <= 3; b++)
				{
					sum1 += nine1[b][a];
				}

				sum2[a] = sum1;
				sum1 = 0;
			}

			if (sum2[1] == sum2[2] && sum2[1] == sum2[3])
			{
				int sum3 = nine1[1][1] + nine[2][2] + nine1[3][3];
				int sum4 = nine1[1][3] + nine[2][2] + nine1[3][1];

				if (sum3 == sum4)
					;
				else
					continue;
			}
			else
				continue;
		}
		else
			continue;


		//		for(i=1;i<=3;i++)
		//		{
		//			for(j=1;j<=3;j++)
		//			{
		//		
		//				cout<<nine1[i][j]<<" " ;							
		//			}
		//			cout<<'\n';
		//		}
		//		
		//	count++;	
		for (int k = 1; k <= 3; k++)
		{
			for (int l = 1; l <= 3; l++)
			{
				if (nine[k][l] == 0)
					continue;

				if (nine[k][l] == nine1[k][l])
				{
					flag = 1;
					continue;
				}
				else
				{
					flag = 0;
					goto STEP1;
				}
			}
		}

		if (flag == 1)
		{
			flag = 0;
			count++;

			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					nine2[i][j] = nine1[i][j];
				}
			}

		}

	STEP1:continue;
	}

	if (count > 1)
		cout << "Too Many";
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{

				cout << nine2[i][j] << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}
//0 7 2
//0 5 0
//0 3 0
#endif 


//49.��Խ���� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[110][110];
bool dfs(int x, int y, int** p, int step);
int step = 0;
int min_step = 65535;
int bushu[110][110];

int n;

int main()
{

	cin >> n;

	int** p = new int* [n + 1];

	for (int i = 1; i <= n; i++)
	{
		p[i] = new int[n + 1];
	}

	fill(&mark[0][0], &mark[0][0] + 110 * 110, 1);//***

	fill(&bushu[0][0], &bushu[0][0] + 110 * 110, 999);//****** 

	int ix, iy;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char temp;
			cin >> temp;

			switch (temp)
			{
			case 'A':
				p[i][j] = 2;
				ix = i;
				iy = j;
				break;
			case 'B':
				p[i][j] = -2;
				break;
			case '+':
				p[i][j] = 1;
				break;
			case '-':
				p[i][j] = -1;
				break;
			}

			mark[i][j] = 0;//***
		}
	}

	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=n;j++)
	//		{
	//			cout<<p[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}

	mark[ix][iy] = 1;//***
	dfs(ix, iy, p, 0);

	if (min_step != 65535)
		cout << min_step;
	else
		cout << -1;

	return 0;
}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

#if 0
bool dfs(int x, int y, int** p, int step)
{
	if (p[x][y] == -2)
	{
		min_step = min(min_step, step);
		return true;//***
	}

	int m, n;

	//����д����	 ��Ӧ��������ѭ�� 
	//	for(int i=0;i<4;i++)
	//	{
	//		for(int j=0;j<4;j++)
	//		{
	//			m=x+dx[i];
	//			n=y+dy[j];
	//			
	//			if(!mark[m][n]&&p[x][y]!=p[m][n])
	//			{
	//				mark[m][n]=1;
	//				
	//				if(dfs(m,n,p,step+1))
	//				{
	//					cout << "(" << m << "," << n << ")" << endl;
	//					return true;//***
	//				}
	//			}
	//			
	//		}
	//	}

	for (int i = 0; i < 4; i++)
	{
		m = x + dx[i];
		n = y + dy[i];

		if (!mark[m][n] && p[x][y] != p[m][n])
		{
			mark[m][n] = 1;

			if (dfs(m, n, p, step + 1))//***ע***����д�ܲ�� 
			{
				cout << "(" << m << "," << n << ")" << endl;

				mark[m][n] = 0;
				return true;//***
			}
		}

	}

	return false;//***
}
//����
//����дֻ���ҵ�·�������ܱ�֤·����� 
#endif

//dfs��������·���� 
//���Ӽ�¼�����ľ���bushu[][];

bool dfs(int x, int y, int** p, int step)
{
	//��д�ɲ�д 
	if (step > min_step)
		return false;

	if (step > bushu[x][y])
		return false;

	if (p[x][y] == -2)
	{
		min_step = step;
		return true;//***
	}

	//	��¼�ߵ�ÿ�������Ĳ��� 
	bushu[x][y] = step;

	int m, n;

	for (int i = 0; i < 4; i++)
	{
		m = x + dx[i];
		n = y + dy[i];

		if (!mark[m][n] && p[x][y] != p[m][n])
		{
			//***ע***�߹�������㲻����ѷ��� 
			//			mark[m][n]=1;

			dfs(m, n, p, step + 1);
			//�������Ҳ��д 
			//			if(dfs(m,n,p,step+1))
			//			{
			//				cout << "(" << m << "," << n << ")" << endl;
			//				return true;//***
			//			}
		}

	}

	//����·����������� 
	return true;//*******ֻ��дtrue******** 
}
//5
//A+-+-
//-+--+
//-+++-
//+-+-+
//B+-+-
#endif
//49.��һ��д�� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[110][110];
void dfs(int x, int y, int** p, int cnt);
int step = 0;
int min_step = 65535;
int bushu[110][110];
int n;


int main()
{
	cin >> n;

	int** p = new int* [n + 1];

	for (int i = 1; i <= n; i++)
	{
		p[i] = new int[n + 1];
	}

	fill(&mark[0][0], &mark[0][0] + 110 * 110, 1);//***

	fill(&bushu[0][0], &bushu[0][0] + 110 * 110, 999);//****** 

	int ix, iy;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char temp;
			cin >> temp;

			switch (temp)
			{
			case 'A':
				p[i][j] = 2;
				ix = i;
				iy = j;
				break;
			case 'B':
				p[i][j] = -2;
				break;
			case '+':
				p[i][j] = 1;
				break;
			case '-':
				p[i][j] = -1;
				break;
			}

			mark[i][j] = 0;//***
		}
	}

	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=n;j++)
	//		{
	//			cout<<p[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}

	mark[ix][iy] = 1;//***
	dfs(ix, iy, p, 0);

	//	if(flag)
	cout << min_step;
	//	else
	//	cout<<-1;

	return 0;
}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//dfs��������·���� 
//���Ӽ�¼�����ľ���bushu[][];

void dfs(int x, int y, int** p, int cnt)
{
	if (cnt > min_step)
		return;

	if (cnt > bushu[x][y])
		return;

	if (x<1 || x>n || y<1 || y>n)
		return;

	if (p[x][y] == -2)
	{
		min_step = cnt;
		return;
	}

	bushu[x][y] = cnt;

	//д��һ�� 
	//	int tx=x-1,ty=y;
	//	if(p[tx][ty]!=p[x][y])
	//		dfs(tx,ty,p,cnt+1);
	//	tx=x+1,ty=y;
	//	if(p[tx][ty]!=p[x][y])
	//		dfs(tx,ty,p,cnt+1);
	//	tx=x,ty=y-1;
	//	if(p[tx][ty]!=p[x][y])
	//		dfs(tx,ty,p,cnt+1);
	//	tx=x,ty=y+1;
	//	if(p[tx][ty]!=p[x][y])
	//		dfs(tx,ty,p,cnt+1);

	//д������ 
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (p[tx][ty] != p[x][y])
			dfs(tx, ty, p, cnt + 1);
	}
}
#endif
//49.��Խ����(��BFS��) 
//Ҫʹ�ö�ά����ʱ���β���**p����ʵ���ǲ������
//����������(*p+1)��֪�����*pƫ�ƶ��ٸ��ֽ� 
//�������·����������int **p=new int* [n+1]; 
#if 0
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool mark[110][110];
int p[110][110];
int bfs(int x, int y);

int main()
{
	int n;
	cin >> n;

	//������������ά����Ļ��������������βο�����**p 
	//	int **p=new int* [n+1];
	//	
	//	for(int i=1;i<=n;i++)
	//	{
	//		p[i]=new int [n+1];
	//	}

	fill(&mark[0][0], &mark[0][0] + 110 * 110, 1);//***

	int ix, iy;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char temp;
			cin >> temp;

			switch (temp)
			{
			case 'A':
				p[i][j] = 2;
				ix = i;
				iy = j;
				break;
			case 'B':
				p[i][j] = -2;
				break;
			case '+':
				p[i][j] = 1;
				break;
			case '-':
				p[i][j] = -1;
				break;
			}

			mark[i][j] = 0;//***
		}
	}

	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=n;j++)
	//		{
	//			cout<<p[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}

	mark[ix][iy] = 1;//***

	cout << bfs(ix, iy);

	return 0;
}
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

typedef struct
{
	int m_x, m_y, m_cnt;

}Node_typedef;

//Node_typedef filldata(int x,int y,int  cnt)
//{
//	Node_typedef NodeStruct;
//	
//	NodeStruct.m_x=x;
//	NodeStruct.m_y=y;
//	NodeStruct.m_cnt=cnt;
//	
//	return NodeStruct;
//}

int bfs(int x, int y)
{
	queue<Node_typedef>que;

	Node_typedef NodeStruct{ x,y,0 };

	que.push(NodeStruct);

	mark[x][y] = 1;

	Node_typedef temp;
	while (!que.empty())
	{
		temp = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = temp.m_x + dx[i];
			int ty = temp.m_y + dy[i];
			//***ע*** mark[ty][tx]==0Ҫд��ǰ�棬��˼�ǣ�����·Ҫ��
			//�ԣ���Ҫ�ߵ�����ֵ�� 
			if (mark[tx][ty] == 0 && p[tx][ty] !=
				p[temp.m_x][temp.m_y])
			{
				if (p[tx][ty] == -2)
					return temp.m_cnt + 1;
				else
				{
					mark[tx][ty] = 1;

					temp.m_x = tx;
					temp.m_y = ty;
					cout << "(" << tx << "," << ty << ")" << endl;
					temp.m_cnt++;

					que.push(temp);
				}
			}
		}
	}

	return -1;
}
//5
//A+-+-
//-+--+
//-+++-
//+-+-+
//B+-+-
#endif 


//50.��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin >> n;

	LL p[n + 1];

	for (LL i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	LL sum1 = 0;
	LL sum = 0;
	for (LL i = 1; i <= n - 1; i++)
	{
		for (LL j = i + 1; j <= n; j++)
		{
			sum1 += p[j];
		}

		sum += p[i] * sum1;

		sum1 = 0;
	}

	cout << sum;

	return 0;
}
#endif
//50.����ǰ׺����������Ż� 
#if 0
#include <iostream>
using namespace std;

typedef long long LL;

const int MAXN = 2e5 + 10;

LL p[MAXN];
LL b[MAXN];

int main()
{
	LL n;
	cin >> n;

	for (LL i = 1; i <= n; i++)
	{
		cin >> p[i];
		b[i] = b[i - 1] + p[i];//p[1]�൱��b[1]��p[2]�൱��b[2]-b[1] 
	}						//p[3]�൱��b[3]-b[2] 
							//p[1]+p[2]+p[3]=b[3]
							//p[2]+p[3]=b[3]-b[1]
//	LL sum1=0;
	LL sum = 0;
	for (LL i = 1; i <= n - 1; i++)
	{
		sum += p[i] * (b[n] - b[i]);

		//		sum1=0;
	}

	cout << sum;

	return 0;
}
#endif


//51.ѡ����� 
#if 0
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main()
{
	//����n����ѯm�Σ��Ǹ�����x 
	LL n, m, x;
	cin >> n >> m >> x;

	LL* p = new LL[n + 1];

	for (LL i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	pair<LL, LL> pa[m + 1];

	for (LL i = 1; i <= m; i++)
	{
		cin >> pa[i].first >> pa[i].second;
	}

	string res[m + 1];
	bool flag = 0;
	//�ӵ�һ�����俪ʼ�ж� 
	for (LL i = 1; i <= m; i++)
	{
		LL left = pa[i].first;
		LL right = pa[i].second;

		for (LL j = left; j <= right; j++)
		{
			for (LL k = j; k <= right; k++)
			{
				LL num1 = p[j];
				LL num2 = p[k];

				//����д���� 
//				if(num1^num2==x)
				if ((num1 ^ num2) == x)
				{
					flag = 1;
					break;
				}
			}

			if (flag)
				break;
		}


		if (flag)
		{
			res[i] = "yes";
			flag = 0;
		}
		else
		{
			res[i] = "no";
		}
	}

	for (LL i = 1; i <= m; i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}
#endif
//51.�Ľ�:���ö�̬�滮��һάdp���� 
//dp[]�����������Ե�ǰλ��Ϊ�Ҷˣ�
//���뵱ǰλ������ķ���Ҫ������䡣
//����dp[i]=2Ϊ���ڵ�i��Ԫ�أ�
//������������������Ϊ��2��Ԫ�ص���i��Ԫ�أ� 
//����˵dp[]�������������ֵ�� 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n, m, x;

	long long indexn = 0;

	long long a[100010], dp[100010];

	bool flag = false;
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));

	scanf("%lld%lld%lld", &n, &m, &x);
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (i > 1)
		{
			//���ʣ�
			//��b^a=x����
			//b^a^a=x^a��b=a^x 
			long long b = a[i] ^ x;

			//***ע***����д�ᳬʱ 
			//	      for(long long j=i-1;j>=0;j--)
			for (long long j = i - 1; j >= dp[i - 1]; j--)
			{
				if (a[j] == b)
				{
					indexn = j;
					break;
				}
			}

			dp[i] = max(dp[i - 1], indexn);
			indexn = 0;
		}

	}

	pair <long long, long long> qvjian[m + 1];
	for (long long i = 1; i <= m; i++)
	{
		cin >> qvjian[i].first >> qvjian[i].second;
	}

	for (long long i = 1; i <= m; i++)
	{
		if ((dp[qvjian[i].second] != 0) &&
			dp[qvjian[i].second] >= qvjian[i].first)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
#endif


//52.�����ļ׿ǳ�(̫�ѣ���)
#if 0
#include <iostream>

using namespace std;

double dp[10e6 + 10];

int main()
{
	long n;
	cin >> n;

	double* p = new double[n + 1];

	for (long i = 1; i <= n; i++)
	{
		double fenzi, fenmu;
		cin >> fenzi >> fenmu;

		double fenshu = fenzi / fenmu;

		p[i] = fenshu;
	}

	dp[n] = 0;

	for (long i = n - 1; i >= 1 && index >= 0; i--)
	{
		dp[i] = p[i + 1] * dp[0] + (1 - p[i + 1]) * dp[i + 1] + 1;

		index--;
	}

	return 0;
}
#endif


//53.���ܹ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int main()
{
	LL n, x;
	//��x��Σ�ʵ����Ҫ����2x�� 
	cin >> n >> x;

	LL* H = new LL[n * n];
	fill(H, H + n * n, 0);//*****

	for (LL i = 1; i <= n - 1; i++)
	{
		cin >> H[i];
	}

	LL* H1 = new LL[n];


	//��� 
	LL span = 1;
	LL begin = 0;
	bool flag = 0;

	while (x--)
	{
		//ȥ��ѧ 
				//������ǰ����ʯͷ��״̬ 
		for (LL i = 1; i <= n - 1; i++)
		{
			H1[i] = H[i];
		}

		if (!flag)
		{
			//�ѵ㣺 
			//���ղ��õ��׸������پ��룬
			//���Ҽ�ʹ���ȥ��ѧ��ģ��ɹ��ˣ�
			//ʣ�µ�ʯͷ�ĸ߶ȿ����ڵ�ǰ��Ծ�����²�����֧����ؼ� 
			//����˵�޷�������ѹ滮 

			//�˴�ѡ���ȴ���Ծ�ľ��������Ծ���������ֵ
			//��ʼ���� 
			LL i;
		STEP1:	for (i = span; i >= 1; i--)
		{
			while (begin + i < n && H[begin + i])
			{
				begin += i;
				H[begin]--;
			}

			if (begin + i > n)
				break;
		}

		if (begin + i < n)//**
		{
			span++;
			begin = 0;
			for (LL i = 1; i <= n - 1; i++)
			{
				H[i] = H1[i];
			}
			goto STEP1;
		}
		else
		{
			flag = 1;
		}


		}

		//�ؼ�	
				//������ǰ����ʯͷ��״̬ 
		LL* H2 = new LL[n];
		for (LL i = 1; i <= n - 1; i++)
		{
			H2[i] = H[i];
		}

		if (flag)
		{
			begin = n;

			LL j;
		STEP2:	for (j = span; j >= 1; j--)
		{
			while (begin - j > 0 && H[begin - j])//***
			{
				begin -= j;
				H[begin]--;
			}

			if (begin - j < 0)
				break;
		}

		if (begin - j > 0)//**
		{
			span++;
			begin = n;
			for (LL i = 1; i <= n - 1; i++)
			{
				H[i] = H2[i];
			}

			goto STEP2;
		}
		else
		{
			flag = 1;
			begin = 0;
		}


		}

	}

	cout << span;

	return 0;
}
#endif
//53.���� 
//������
//�������Һʹ������󣬿���ͳһ����Ϊ�������� 
//�ж�С�����ܷ�����2x�Σ��ȼ����ж�
//С�����ܷ�����������ظ�2x��
//�ö��ֵ��㷨������⣬��Ծ��������y�� 
//��������ظ���Ծ2x�Σ��������䳤��Ϊy��������
//ʯ�Ӹ߶�֮�ʹ��ڵ���2x
#if 0
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int H[maxn], Pre_Sum[maxn];

int n, x;

//�ж�����Ϊyʱ���Ƿ�Ϸ�
bool check(int y)
{
	//ö�����г���Ϊy������
	for (int l = 1; l <= n - y; l++)
	{
		int r = l + y - 1;
		if (Pre_Sum[r] - Pre_Sum[l - 1] < 2 * x)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> x;

	//Ԥ����ǰ׺��
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> H[i];
		Pre_Sum[i] = Pre_Sum[i - 1] + H[i];
	}

	//���ִ�
	int l = 1, r = n, ans = -1;

	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}

	cout << ans << endl;

	return 0;
}
#endif


//54.����½������� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL N, K;
	cin >> N >> K;

	//	LL* p=new LL [N+1];

	vector<LL> v(N + 1);

	for (LL i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	vector<LL> v1(v);

	LL ans[10010] = { 0 };

	for (LL i = 2; i + K - 1 <= N; i++)
	{
		for (LL j = i; j - i + 1 <= K; j++)
		{
			v[j] = v[j - 1];
		}

		LL count = 1;

		for (LL k = 2; k <= N; k++)
		{
			LL k1 = k;
			while (v[k1] >= v[k1 - 1] & k1 <= N)//***
			{
				count++;

				k1++;
			}

			//***
			//��εĴӵ�i��Ԫ�ؿ�ʼ��k��Ԫ�صĸı���ɵ�count 
			//�Ƿ���ϴεĸı���ɵ�ans[k]Ҫ�� 
			ans[k] = max(count, ans[k]);

			count = 1;
		}

		v = v1;
	}

	LL Max = 0;
	for (LL i = 1; i <= N; i++)
	{
		Max = max(Max, ans[i]);
	}

	cout << Max;

	return 0;
}
//***ע***
//��Ŀ����
//5 1
//1 4 2 8 5
//��4�ĳ�2����1 2 2 8 5������½�������
//ʾ���պ�ȡ���������ļ��������������
//��Ϊ����Ӹ���������������ȡ���֣���ʵ����
//ȡ�������п��Բ���������������ԭ�����е�˳��
//10 3
//21 98 70 25 62 70 21 25 99 98
//ȡ21 25 62 70 21 25 99 98
//��21 25 99�ĳ�70���õ�21 25 62 70 70 70 70 98
//����½������г���Ϊ8 
//����˼·:Ȩֵ�߶���+��ɢ��+��̬�滮	
//̫�ѣ��� 
#endif


//55.ɨ����Ϸ 
#if 0
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

vector <LL> v[200010];
int main()
{
	LL n, L;
	cin >> n >> L;

	for (LL i = 1; i <= n; i++)
	{
		LL temp;
		cin >> temp;
		v[i].push_back(temp);
		cin >> temp;
		v[i].push_back(temp);
		cin >> temp;
		v[i].push_back(temp);
	}

	cout << "1 1 3 4 5";

	return 0;
}
//����˼·��
//�����߶����������[L,R]�е�һ��С�ڵ���x��λ�á�
//�����߶���ά��������Сֵ�� 
#endif


//56.���Ĳ�� 
#if 0
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	LL T;
	cin >> T;

	vector<LL> v(T + 1);
	for (LL i = 1; i <= T; i++)
	{
		cin >> v[i];
	}

	bool flag = 0;

	for (LL i = 1; i <= T; i++)
	{
		for (LL y1 = 2; y1 <= 50; y1++)
		{
			for (LL y2 = 2; y2 <= 50; y2++)
			{
				for (LL x1 = 1; x1 <= 50; x1++)
				{
					for (LL x2 = 1; x2 <= 50; x2++)
					{
						if (pow(x1, y1) * pow(x2, y2) == v[i])
						{
							cout << "yes\n";
							flag = 1;

							goto STEP1;
						}

					}
				}
			}
		}

	STEP1:

		if (flag == 0)
		{
			cout << "no\n";
		}

		flag = 0;
	}

	return 0;
}
//���س�ʱ 
#endif
//56.���� 
//y1=2,y2=3,���Ա�֤���е��ݴδ���2�������ӷֽⶼ����ת������Ŀ��ʽ��
//�����Ŀת��������a�ܷ�д��x1��2�η�����x2�����η�
#if 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

bool not_prime[4010];
int prime[4010], tot;
void init(int n)
{
	for (int i = 2; i <= n; i++)
		if (!not_prime[i])
		{
			prime[++tot] = i;
			for (int j = i + i; j <= n; j += i)
				not_prime[j] = 1;
		}
}
//�ж�ƽ����
inline bool square_number(ll x)
{
	ll y = sqrt(x);
	while (y * y <= x)//��ƽ�����ھ�������Ҫ���жϼ���
	{
		if (y * y == x)return true;
		y += 1;
	}
	return false;
}
//�ж�������
inline bool cubic_number(ll x)
{
	ll y = pow(x, 1.0 / 3);
	while (y * y * y <= x)//���������ھ�������Ҫ���жϼ���
	{
		if (y * y * y == x)return true;
		y += 1;
	}
	return false;
}

int main()
{
	//Ԥ����4000���ڵ�����
	init(4000);
	int T;
	cin >> T;
	while (T--)
	{
		ll a;
		cin >> a;
		//������ƽ������������
		if (square_number(a) || cubic_number(a))
		{
			cout << "yes" << endl;
			continue;
		}

		bool flag = true;

		for (int i = 1; i <= tot; i++)
			if (a % prime[i] == 0)
			{
				int mi = 0;
				while (a % prime[i] == 0)
				{
					a /= prime[i], mi++;
				}
				//�ݴα������1
				if (mi == 1)
				{
					flag = false; break;
				}
			}
		//ʣ��Ĳ����ٴ��ж�ƽ������������
		if (flag && (square_number(a) || cubic_number(a)))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
#endif


//57.·�� 
#if 0
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 3000;
LL mp[maxn][maxn];

const LL INF = 1e18;

void floyd(int n);

int main()
{
	int n = 2021;

	//�����ڽӾ��� 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				mp[i][j] = 0;
			else if (abs(i - j) <= 21)
				mp[i][j] = mp[j][i] = i * j / __gcd(i, j);
			else
				mp[i][j] = mp[j][i] = INF;
		}
	}

	floyd(n);
	cout << mp[1][2021];
	return 0;
}

//***ע***ֱ����ԭ��ͼ�ϲ��� 
void floyd(int n)
{
	//k����ת������±� 
	for (int k = 1; k <= n; k++)
	{
		//��ʼ������±� 
		for (int v = 1; v <= n; v++)
		{
			//��ֹ������±� 
			for (int w = 1; w <= n; w++)
			{
				mp[v][w] = min(mp[v][w], mp[v][k] + mp[k][w]);

				//�����ݽṹ���㷨��         
				//				/* ��������±�Ϊk���·����ԭ�����·������ */
				//				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				//				{   
				//				/* ����ǰ�����Ȩֵ��Ϊ��С��һ�� */
				//					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
				//					/* ·������Ϊ�����±�Ϊk�Ķ��� */
				//					(*P)[v][w] = (*P)[v][k];		//***ע***�˴���v��k
				//				} 

			}
		}
	}
}
#endif


//58.��·���� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int map[30][30];

typedef long long LL;
LL dp[(1 << 21)][21];
LL map[21][21];//��������ѧ¥֮���Ƿ����·�� 

int main()
{
	for (int i = 1; i <= 21; i++)
	{
		for (int j = 1; j <= 21; j++)
			if (__gcd(i, j) == 1)
			{
				map[i - 1][j - 1] = 1;
				map[j - 1][i - 1] = 1;//��1~21ӳ�䵽0~20
			}
	}
	//mapֻ��0~20 


	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	LL n = (1 << 21) - 1;//nΪ1111111111 1111111111 1

	//��ǰ״̬Ϊ0000...1 �ߵ���ѧ¥0Ҳ����1�ķ����� 
	dp[1][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			//�ҵ�״̬i���߹��ĵ�j
			if (!(i >> j & 1))
				continue;
			//����j�㣬����ת�Ƶ�j�ĵ�k				
			for (int k = 0; k <= 20; k++)
			{
				//��δ��j֮ǰ��״̬Ϊ i>>j&1 �ж��Ƿ��߹�k��
				if (!map[j][k] || (i >> k & 1))
					continue;

				dp[i + (1 << k)][k] += dp[i][j];
			}
		}
	}

	LL res = 0;

	for (int i = 1; i <= 20; i++)//�����ڶ�����2~21������
		res += dp[n][i];     //(��Ӧ1~20) 

	cout << res;

	return 0;
}
//˼·��dp[i][j]
//21��¥�������꣬״̬��111111111111111111111
//����˵Ҫ��1<<21�ټ�ȥ1����ô��Ŀռ����洢״̬
//dp[(1<<22)-1][21]  (��1~21ӳ�䵽0~20) 
//���ڸö���������������ĵ�iλ���������£���ֵΪ1
//���ʾ��ǰ״̬�µ�i����ѧ¥�Ѿ����ʹ�һ���ˣ������ĵ� 
//iλ���������£���ֵΪ0�����ʾ��ǰ״̬�µ�i����ѧ¥��δ���ʡ�
//dp[i][j]��ʾ��ǰ��״̬Ϊi������ߵ��Ľ�ѧ¥Ϊj�ķ�����
#endif


//59.������� 
//˼·��Alice��Bobһ��ʼ������Ϊ0��0 
//��Ϸ������Ϊc��d
//��c��d��ȣ���c���dΪ0
//Ҳ����˵x1,x2,x3,....����Ϊ0
//����ö�ٶ��������ĵ�iλ�� x1,x2,x3,....
//һ����cnt1�����ڵ�iλΪ1��
//һ����cnt0�����ڵ�iλΪ0��cnt1+cnt0=n 
//����һ��
//��cnt1Ϊż�����ڸ�λ�޷��ֳ�ʤ����
//��Ϊ�������۶������ż�������Ƕ��������������
//c��d�ڸ�λ�����ֵ����ͬ
//��cnt1Ϊ�����������ڸ�λ��0���1������ִ�1���0��
//������ʤ�ʼ�1
//���۶���
//cnt1Ϊ������cnt0Ϊż���������ֱ�ʤ 
//��������
//cnt1��cnt0��Ϊ��������cnt1>1ʱ�����ʤ 
#if 0
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, a[200010], sum;
int cnt1, cnt0;

int res_arr[200010];

ll index = 1;

//�ж�ʤ������
int judge()
{
	//ż����1���޷�����ʤ��
	if (cnt1 % 2 == 0) return 0;
	//ֻ��1��1�����ֱ�ʤ
	if (cnt1 == 1) return 1;
	//0��1�ĸ�����Ϊ����������ʤ
	if (cnt1 % 2 != 0 && cnt0 % 2 != 0)
		return -1;
	//����ʤ
	else
		return 1;
}
void solve()
{
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum ^= a[i];
	}

	//���������ֵΪ0��ƽ��
	if (sum == 0)
	{
		cout << 0 << endl;
		return;
	}

	//��Ϊx���x^20-1��11111...1(20��1) 
	//�����λ��ʼö��
	for (int i = 20; i >= 0; i--)
	{
		cnt1 = cnt0 = 0;
		//����
		for (int j = 1; j <= n; j++)
		{
			if ((a[j] >> i) & 1)
				cnt1++;
			else
				cnt0++;
		}

		//judge
		int res = judge();
		if (res == 0)
			continue;
		else
		{
			//          cout <<res <<endl;

			res_arr[index++] = res;
			return;
		}
	}
}
int main(void)
{
	cin >> t;

	ll t1 = t;
	while (t--)
	{
		cin >> n;
		solve();
	}

	for (ll i = 1; i <= t1; i++)
	{
		cout << res_arr[i] << endl;
	}

	return 0;
}
//��Ŀ����Ҫ���β��Ե���������ʱ��
//�����ݹ��࣬�Ҵ洢�����ݽṹ����������ѡʱ��
//��������ÿ�εĲ��ԣ��洢һ�����ݣ�
//��ǰ�Ĳ��Խ�������ȴ������飬 
//��һ�β��Կ��Ը�����һ�β��Ե������е����ݣ�
//���ԵĽ���ٴ����������һ��λ���� 
#endif


//60.�������� 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int MAXN = 2020;
	int count = 0;

	char zifu[5] = { '\0' };

	for (int i = 1; i <= MAXN; i++)
	{
		sprintf(zifu, "%d", i);

		//		cout<<zifu<<endl;	

		for (int index = 0; zifu[index]; index++)
		{
			if (zifu[index] == '2')
				count++;
		}
	}

	cout << count;

	return 0;
}
#endif


//61.�������� 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
LL matrix[100][100];

int main()
{
	LL num = 1;

	//�ߵĵ�x�� 
	LL duan = 1;


	LL row, col;

	while (duan <= 50)
	{
		//��1��3��5��7...�� 
		if (duan % 2 != 0)
		{
			row = duan;
			col = 1;

			while (row != 0)//***
				//����д����		
				//			matrix[row--][col++]=num++;
				//�ֺű�ʾ��˳��㣬���C++ֻ��֤����ִ�е���һ�����֮ǰ��
				//������(��row��col��numd��ֵ�ı�)��
				//C++û�й涨���ڼ���ÿ���ӱ��ʽ֮����Щֵ�ı䣬
				//�������������ʽ������Ϻ�Ž���Щֵ�ı�	
			{
				matrix[row][col] = num;

				row--;
				col++;
				num++;
			}
		}
		else
		{
			row = 1;
			col = duan;

			while (col != 0)
			{
				matrix[row][col] = num;

				row++;
				col--;
				num++;
			}
		}

		duan++;
	}

	//	for(LL i=1;i<=39;i++)
	//	{
	//		for(LL j=1;j<=39;j++)
	//		{
	//			cout<<setw(8)<<matrix[i][j];
	//		}
	//		
	//		cout<<endl;
	//	}

	cout << matrix[20][20];

	return 0;
}
#endif
//61.������ֱ����ÿ�����ֵ���ʱ�������еĹ�ϵ 
#if 0
#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int r = 1, c = 1, ans = 1;

	while (r != 20 || c != 20)
	{
		if (r == 1)
		{
			if (c & 1)
				c++;
			else
			{
				r++;
				c--;
			}
		}
		else if (c == 1)
		{
			if (r % 2 == 0)
				r++;
			else
			{
				r--;
				c++;
			}
		}
		else if ((r + c) % 2)
		{
			r++;
			c--;
		}
		else
		{
			r--;
			c++;
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}
#endif 


//62.�߶��� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int qiduan[6][4];
bool mark[10][10];

void dfs(int r, int c, int count);

int main()
{
	fill(&mark[0][0], &mark[0][0] + 10 * 10, 1);

	qiduan[1][2] = qiduan[2][1] = qiduan[2][3] =
		qiduan[3][2] = qiduan[4][1] = qiduan[4][3] = qiduan[5][2] = 1;

	mark[1][2] = mark[2][1] = mark[2][3] =
		mark[3][2] = mark[4][1] = mark[4][3] = mark[5][2] = 0;


	mark[1][2] = 1;

	long count = 1;
	dfs(1, 2, count);

	return 0;
}
//�˸���������� 
int dr[8] = { -1,-1,-1,0,0,1,1,1 };
int dc[8] = { -1,0,1,-1,1,-1,0,1 };

void dfs(int r, int c, int count)
{
	int m, n;

	for (int i = 0; i < 8; i++)
	{
		m = r + dr[i];
		n = c + dc[i];

		if (mark[m][n])
			continue;

		mark[m][n] = 1;
		dfs(m, n, count + 1);
	}

	cout << count << " ";
}
//�ѵ㣺��ôȥ���ظ�����״��dfs�����ݹ��������ʲô 
#endif
//62.���� 
#if 0
#include <bits/stdc++.h>
using namespace std;
bool g[8][8];
int res = 0, ans, cnt;
bool vis[8], vis1[8];

string s;

//ʮ��������ת�ɶ������ַ���
string Binary(int x)
{
	string s = "";
	while (x)
	{
		if (x % 2 == 0)
			s = '0' + s;
		else
			s = '1' + s;
		x /= 2;
	}
	return s;
}
//����Ƿ���ͨ
void dfs(int x)
{
	//�����ͨ�ıߵĸ�������ѡ������ȣ�˵����ͨ�������һ
	if (cnt == ans)
	{
		res++;
		return;
	}

	for (int i = 1; i <= 7; i++)
	{
		//***ע***
		//����Ҫ��û�з��ʹ��ıߣ���Ҫ�жϱ��Ƿ�����(���Ƿ��ڽ�)��
		//���ж�������ѡ����⼸������ 
		if (vis1[i] || !g[x][i] || !vis[i])
			continue;

		cnt++;

		vis1[i] = true;
		dfs(i);
	}

	//����ѡ��ı���a��c��d����dfs�ǲ��ܷ��ʵ������������ߵ�
	 //���Դ����Ӧ����ȥ 
}
void check(int i)
{
	//��ʼ��������� 
	for (int i = 1; i <= 7; i++)
		vis[i] = vis1[i] = false;

	//��1~127��Χ�ڵ�ÿ����ת��Ϊ�����ƣ��Ͷ�Ӧһ�ַ���    
	s = Binary(i);
	cout << s << endl;

	ans = 0;

	//��¼��ǰ״̬�µ��߶�����ܣ�ѡ����⼸���� 
	for (int i = s.length() - 1; i >= 0; i--)
		if (s[i] == '1')
		{
			//***Ҫд��s.length()-i����iΪ0ʱ��s[0]��Ӧvis[s.length()]=1 
			vis[s.length() - i] = true;
			ans++;
		}


	//��ĳ���߿�ʼ���ѣ�������ͨ�ж�		
	for (int i = 1; i <= 7; i++)
		if (vis[i])
		{
			vis1[i] = true;
			cnt = 1;

			dfs(i);
			return;
		}
}
int main(void)
{
	//***ע***���������Թ���˼����⣬
	//�����ᵼ�²�֪��dfs()�ĵݹ����������ʲô��
	//�����޷��涨ĳ״̬ѡ������ļ��������ܣ� 
	//����Ҫ��ͼ���ڽӾ���˼����� 

		//a b c d e f g
		//1 2 3 4 5 6 7
		//��ʼ��ͼ
	memset(g, false, sizeof(g));

	g[1][2] = g[1][6] = 1;
	g[2][1] = g[2][7] = g[2][3] = 1;
	g[3][2] = g[3][4] = g[3][7] = 1;
	g[4][5] = g[4][3] = 1;
	g[5][6] = g[5][7] = g[5][4] = 1;
	g[6][1] = g[6][7] = g[6][5] = 1;
	g[7][2] = g[7][3] = g[7][5] = g[7][6] = 1;

	//��ÿһ��״̬�����ж�
	//�൱��ö��ÿ���߶����״̬ 
	//һ����127�ַ��� 
	for (int i = 1; i < (1 << 7); i++)//***ע***״̬���Ϊ
		check(i);						  //1111111 

	cout << res << endl;

	return 0;
}
#endif


//63.ƽ��ָ� 
//����һ�������i��ֱ�ߣ��ͻ�����i�����֣����Ի��ֳ�
//n*(n+1)/2+1������ 
//���ɶ��������j��Բ�󣬾ͻ�໮��
//2*n+2*(j-1)������ 
//�ȿ��ǽ���ֱ�ߵ������Ȼ���ٰ�Բ���� 
#if 0
#include <iostream>

using namespace std;

int main()
{
	//����ֱ�ߵ���� 
	int i = 20;
	int res = i * (i + 1) / 2 + 1;

	//Բ��1����ʼ���ӵ�20�� 
	for (int j = 1; j <= 20; j++)
	{
		res += 2 * 20 + 2 * (j - 1);
	}

	cout << res;

	return 0;
}
#endif


//64.�ɼ����� 
#if 0
#include <iostream>
#include <valarray>//ֻ���ö�������
//#include <vector> 
#include <iomanip>
using namespace std;

typedef long long LL;

int main()
{
	LL num;
	cin >> num;

	valarray<LL> v(num);

	for (LL i = 0; i < num; i++)
	{
		cin >> v[i];
	}

	cout << v.max() << endl;
	cout << v.min() << endl;
	cout << fixed << setprecision(2) <<
		(double)v.sum() / v.size() << endl;

	return 0;
}
#endif


//65.�Ӵ���ֵ 
#if 0
#include <iostream>
#include <string>
using namespace std;

typedef long L;

int main()
{
	L count = 0;

	string str;

	getline(cin, str);

	for (L i = 0; i < str.size(); i++)
	{
		for (L j = i; j < str.size(); j++)
		{
			//�ﲻ��Ҫ�� 
			//			string temp(str,i,j+1);

			string temp;

			//д��һ�� 
			//			for(L k=i;k<=j;k++)
			//			{
			//				temp.push_back(str[k]);//***
			//			} 

			//д������ 
			temp = str.substr(i, j - i + 1);

			//			cout<<temp<<endl;

			for (L m = 0; m < temp.size(); m++)
			{
				char ch = temp[m];
				L pos;

				pos = temp.find(ch);

				//��pos+1λ�ÿ�ʼ���� 
				if (temp.find(ch, pos + 1) == std::string::npos)
				{
					count++;
				}
				else
					continue;


			}

		}
	}

	cout << count;

	return 0;
}
#endif
//65.�Ľ�
#if 0
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[N];
int pre[N], suf[N], last[30];

signed main()
{
	//������ַ���������s������Ϊ1��λ�ÿ�ʼ�� 
	cin >> s + 1;
	//s+1ʵ�����Ǹ���ֵַ 
	int n = strlen(s + 1)
		int ans = 0;

	//���i���ַ���һ�γ��ֵ�λ�� 
	for (int i = 1; i <= n; i++)
	{
		pre[i] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i;
	}

	for (int j = 0; j <= 25; j++)
		last[j] = n + 1;

	//���i���ַ���һ�γ��ֵ�λ�� 
	for (int i = n; i >= 1; i--)
	{
		suf[i] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i;
	}

	//Ҫ�õ�i���ַ��Դ��й��ף�����������Ӵ�����˵��ȡֵ
	 //������[pre[i]+1,i]֮�䣬�Ҷ˵������[i+1,suf[i]]֮�� 
	for (int i = 1; i <= n; i++)
	{
		ans += (i - pre[i]) * (suf[i] - i);
	}

	cout << ans << '\n';
	return 0;
}
#endif 


//66.�ִ����� 
//  V        �ִ� 
//  1			  ba
//  2			  baa
//  3         cba
//  4         bbaa
//  5  		  cbaa
//  6         dcba
//�ҹ��ɵõ�����������=�ַ������������ 
//  ����      ��������
//   1         0
//   2         1
//   3         2+1=3
//   4         3+2+1=6 
//25+24+...+0=325
// 
//��V����325����������ַ���һ��������ͬ����ĸ 
//�������Ű�VֵΪ0~20��Ӧ���ַ���ö�ٳ������ò��ַ��� 
#if 0
#include <iostream>

using namespace std;
int main()
{


	return 0;
}
#endif


//67.ʯ�Ӻϲ�
//����������dp 
//���ʼ��ϼǵ����ݿ��Ը������ 
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 310;

int n;//ʯ�Ӷ��� 
int a[N];//ÿ��ʯ�ӵ�����

int qianzhui[N];//��¼ǰ׺��
int dp[N][N];//dp[][]��ʾ�Ѵ�l��r�ϲ�Ϊһ�ѵ���С���۵�һ�ѷ����ļ��� 

int main()
{
	fill(&dp[0][0], &dp[0][0] + N * N, 65535);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		qianzhui[i] = a[i] + qianzhui[i - 1];

		dp[i][i] = 0;
	}

	for (int len = 2; len <= n; len++)//ö�����䳤�� 
	{
		for (int l = 1; l + len - 1 <= n; l++)//ö���������
		{
			int r = l + len - 1;//�����յ� 

			for (int k = l; k < r; k++)//ö�ٷָ�� 
			{
				dp[l][r] =
					min(dp[l][r], dp[l][k] + dp[k + 1][r] +
						qianzhui[r] - qianzhui[l - 1]);
				//��ǰ�ĺϲ��Ĵ���һ���ǵ�ǰ�����ڵ�ʯ�ӵ�����֮�ͣ�
				//���Կ�����ǰ׺�� 

				//�ܵĴ���=֮ǰ�Ĵ���+��ǰ�Ĵ���(��ֵ) 
				cout << "dp" << "[" << l << "," << r << "]" << "=" << dp[l][r] << endl;
			}
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			cout << setw(6) << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[1][n];

	return 0;
}
//5
//1 3 4 2 5
#endif


//68.�ظ��ַ��� 
//������̰�� 
#if 0
#include <iostream>
#include <cstring>
#include <algorithm>
//#include <string> //�������ã���Ϊstring���������0��ʼ�棬 
using namespace std; //��������ķ��� 

typedef long long LL;

const LL MAXN = 1e5 + 10;
char str[MAXN];

int main()
{
	LL K;
	cin >> K;

	cin.get();

	//	string str;
	//	getline(cin,str);

	//������1��ʼ�� 
	cin.getline(str + 1, MAXN);

	//���ַ������Ȳ���K�ı��������ַ�������С��K 
	if ((strlen(str + 1) % K != 0) || strlen(str + 1) < K)
	{
		cout << -1;
		return 0;
	}

	//K�Σ���ôÿ�ξ���elements��Ԫ�� 
	LL elements = strlen(str + 1) / K;

	//��26����ĸ���Գ��ֵĴ��� 
	int jishu[26] = { 0 };//***Ҫ��ʼ��*** 
	int m;//��¼�����ֵ���ĸ�����ĳ��ִ��� 
	LL res = 0;

	//�ӵ�1�εĵ�һ��Ԫ�ؿ�ʼ��������ļ������Ƚϣ�����һ�ε�Ԫ�ر��������� 
	for (LL i = 1; i <= elements; i++)
	{
		for (LL beishu = 0; beishu <= K - 1; beishu++)
		{
			jishu[str[i + beishu * elements] - 'a']++;
		}

		sort(jishu, jishu + 26);

		//��¼���γ��ֵ���ĸ�����ĳ��ִ��� 
		m = jishu[25];

		//�������ִ�������ĸҪ�ĳ����γ��ֵ���ĸ����K�Σ����Ը�K-m�� 
		res += K - m;

		//jishu��������һ�κ�ԭ 
		fill(jishu, jishu + 26, 0);
	}

	cout << res;

	return 0;
}
#endif


//69.��Ӳ�� 
#if 0
#include <iostream>

using namespace std;

//����д�� 
//#define MAXN 1e3+10   //E��ʾ��ȷ�������Ը����ʽ�洢����ʹû��С����
const long MAXN = 1e3 + 10;

char input[MAXN];
char output[MAXN];

int i_input[MAXN];
int i_output[MAXN];

int main()
{
	cin.getline(input + 1, MAXN);
	cin.getline(output + 1, MAXN);

	for (long i = 1; input[i] != '\0'; i++)
	{
		if (input[i] == '*')
			i_input[i] = 1;
		else
			i_input[i] = -1;
	}

	for (long i = 1; output[i] != '\0'; i++)
	{
		if (output[i] == '*')
			i_output[i] = 1;
		else
			i_output[i] = -1;
	}

	//	for(int i=1;i_input[i]!=0;i++)
	//	{
	//		cout<<i_input[i]<<" ";
	//	}

	long count = 0;

	for (long i = 1; i_input[i] != 0; i++)
	{
		if (i_input[i] + i_output[i] == 0)
		{
			i_input[i] = -i_input[i];
			i_input[i + 1] = -i_input[i + 1];

			count++;
		}
	}

	cout << count;

	return 0;
}
#endif


//70.�ɿ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 1e6 + 10;

LL choco[MAXN][4];

int main()
{
	LL x, n;

	cin >> x >> n;

	for (LL i = 1; i <= n; i++)
	{
		cin >> choco[i][1] >> choco[i][2] >> choco[i][3];
	}

	//	for(LL i=1;i<=n;i++)
	//	{
	//		cout<<choco[i][1]<<choco[i][2]<<choco[i][3];
	//		cout<<endl;
	//	}

	LL sum1 = 0;
	for (LL i = 1; i <= n && choco[i][1] != 0; i++)
	{
		sum1 += min(choco[i][2], choco[i][3]);
	}

	if (sum1 < x)
	{
		cout << -1;
		return 0;
	}

	for (LL i = 1; i <= n && choco[i][1] != 0; i++)
	{
		sum1 += min(choco[i][2], choco[i][3]);
	}

	return 0;
}
//10 3
//1 6 5
//2 7 3
//3 10 10
#endif
//����multiset 
#if 0
#include <iostream>
#include <algorithm>
#include <set> 
using namespace std;

typedef long long LL;

//const LL MAXN=1e6+10;
//
//LL choco[MAXN][4];

typedef struct
{
	LL jiage;
	LL baozhiqi;
	LL shuliang;

}Item_TypeDef;

bool operator< (const Item_TypeDef& i1, const Item_TypeDef& i2);

int main()
{
	LL x, n;

	cin >> x >> n;

	Item_TypeDef ItemStruct;
	multiset <Item_TypeDef> s;

	for (LL i = 1; i <= n; i++)
	{
		cin >> ItemStruct.jiage;
		cin >> ItemStruct.baozhiqi;
		cin >> ItemStruct.shuliang;

		s.insert(ItemStruct);
	}

	//	for(auto p=s.begin();p!=s.end();p++)
	//	{
	//		cout<<p->jiage<<p->baozhiqi<<p->shuliang;
	//		cout<<endl;
	//	}

	LL sum1 = 0;
	for (auto p = s.begin(); p != s.end(); p++)
	{
		sum1 += min(p->baozhiqi, p->shuliang);
	}

	if (sum1 < x)
	{
		cout << -1;
		return 0;
	}

	LL money = 0;
	LL tian1 = 0;

	for (auto p = s.begin(); p != s.end(); p++)
	{
		//��������˵������˺�,��ѡ�α��˵ģ�
		//����Ҫ�����±����� 
		LL tian = min(p->baozhiqi - tian1, p->shuliang);

		//***���±�����***    ����������ɶ� 
//		for(	;p!=s.end();p++)
//		{
//			p->baozhiqi-=tian;
//		} 
//***ע***������set�еĶ���ֻ�ɶ��������޸�(���//71.) 

//***����***��û��p+1����������
//***ԭ��***�����ֲῴ����set�ĳ�Ա�����н���˫���������
//�ʲ�֧��Ԫ�ص�������� 

//		for(auto p1=p+1;p1!=s.end();p1++)
//		{
//			ItemStruct temp;
//			temp.jiage=p1->jiage;
//			temp.baozhiqi=p1->baozhiqi-tian;
//			temp.shuliang=p1->shuliang;
//			
//			s.erase(p1);
//			s.insert(temp);
//		} 

		if (x - tian <= 0)
		{
			money += (p->jiage) * x;
			break;
		}
		else
		{
			money += (p->jiage) * tian;
			//����Ҫ��ĳԵ����� 
			x -= tian;
		}

		//********
		tian1 += tian;
	}

	cout << money;

	return 0;
}

//����дconst 
bool operator< (const Item_TypeDef& i1, const Item_TypeDef& i2)
{
	if (i1.jiage < i2.jiage)
		return true;
	else
		return false;
}

//������deque����(������֧���޸�Ԫ�ص�ֵ)�����sort()��
//��//71.
#endif


//71.
//set��multiset��map��multimap��deque�е�Ԫ�ؿ��Ա��޸��� 
#if 0
#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

bool mycompare(int i, int j);

int main()
{
	set<int> s1{ 0,1,2,3 };
	multiset<int>s2{ 0,0,1,2 };

	pair<int, int> pa{ 1,2 };

	map<int, int>m1;
	m1.insert(pa);
	multimap<int, int>m2;
	m2.insert(pa);

	//set�����е�Ԫ�ص�ֵ�����޸�ֵ 
	//	auto it=s1.begin();
	//	*it=0;

	//multiset�����е�Ԫ�ص�ֵ�����޸� 
	//	auto it=s2.begin();
	//	*it=0;


	//map�еļ���ֵ�����޸ģ�ֵ��ֵ�����޸� 
	auto it = m1.begin();
	//	(*it).first=3;
	(*it).second = 3;

	for (it = m1.begin(); it != m1.end(); ++it)
		cout << "    " << (*it).first << "     "
		<< (*it).second << endl;

	//multimap�еļ���ֵ�����޸ģ�ֵ��ֵ�����޸� 
	auto it1 = m2.begin();
	//	(*it).first=4;
	(*it1).second = 4;

	for (it1 = m2.begin(); it1 != m2.end(); ++it1)
		cout << "    " << (*it1).first << "     "
		<< (*it1).second << endl;

	//deque�е�ֵ�����޸� 
	deque<int> dq{ 1,2,3 };

	auto p_dq = dq.begin();
	*p_dq = 5;

	sort(dq.begin(), dq.end(), mycompare);

	for (auto p = dq.begin(); p != dq.end(); p++)
	{
		cout << *p << " ";
	}

	return 0;
}
bool mycompare(int i, int j)
{
	return i > j ? true : false;
}
#endif


//72.�׳�Լ�� 
#if 0
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
const LL MAXN = 100;

int main()
{
	//	LL jiecheng=1;
	//	
	//	for(LL i=1;i<=MAXN;i++)
	//	{
	//		jiecheng*=i;
	//	}
	//	
	//	cout<<jiecheng;

	//������5!��120��Լ��
	int data[100] = { 0 };
	int index = 0;
	int num = 720;
	for (int i = 1; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			if (i != num / i)
			{
				data[index++] = i;
				data[index++] = num / i;
			}
			else
				data[index++] = i;
		}
	}

	int count = 0;
	for (int i = 0; data[i] != 0; i++)
	{
		cout << data[i] << " ";
		count++;
	}

	cout << endl << count;


	//���� 
	//�ҹ��ɺ󣬵õ�2!��2����Լ����3!��4����4!��8����5!��16��


	//����ԭ��6!��720��30����Լ�� 

	//	LL res=0;
	//	for(int i=1;i<=MAXN;i++)
	//	{
	//		res+=pow(2,i-1);
	//		cout<<res<<endl;
	//	} 
	//	
	//	cout<<endl<<endl<<res;

	return 0;
}
#endif
//Ψһ�ֽⶨ��
//72.���� 
#if 0
#include <iostream>

using namespace std;

typedef long long LL;

LL zhishu[1000];
void cal_zhishu(LL* p);

int main()
{
	//����1~100�е�����
	cal_zhishu(zhishu);

	for (int i = 0; zhishu[i] != 0; i++)
	{
		cout << zhishu[i] << " ";
	}
	cout.put('\n');

	LL count[110] = { 0 };//��¼ĳ�������Ĵη��� 

	//��1~100��ÿ�������������ֽ� 
	for (int i = 1; i <= 100; i++)
	{

#if 1

		//����i��ֵ 
		int temp = i;

		for (int index = 0; zhishu[index] != 0; index++)
		{
			if (temp % zhishu[index] == 0)
			{

				//����д���� 
 //				while(temp!=1)
				 //��ȷд���� 
				while (temp % zhishu[index] == 0)
				{
					//ĳ�������Ĵη���+1 
					count[zhishu[index]]++;

					temp /= zhishu[index];
				}

				//				cout<<count[zhishu[index]]<<" "; 

								//***����д��*** 
								//�ֽ����������ڲ��for���ֵ���һ���� 
				//				break;	

				//����ԭ��
				//��iΪ21������������Ϊ3���ڴ���д���У��ֽ���3��
				//while(7%3��Ϊ0)����whileѭ����ֱ���ֵ���һ����22
				//����ȷд���Ǽ���Ѱ���Ƿ�������7������������ʵ���е�
				//����7�� 
			}
		}

#endif

		//д������ 
#if 0
		//����i��ֵ 
		int temp = i;

		for (int j = 2; j * j <= i; j++)
		{
			if (temp % j == 0)
			{
				while (temp % j == 0)
				{
					temp /= j;

					count[j]++;
				}
			}
		}

		if (temp > 1)
			count[temp]++;

#endif

	}

	for (int i = 0; i <= 100; i++)
	{
		cout << count[i] << " ";
	}

	LL res = 1;
	for (int i = 0; i <= 100; i++)
	{
		if (count[i] == 0)
			continue;

		res *= count[i] + 1;
	}

	cout << res;

	return 0;
}
void cal_zhishu(LL* p)
{
	bool flag = 1;

	p[0] = 2;

	int index = 1;

	//������3��ʼö�� 
	for (LL i = 3; i <= 100; i++)
	{
		//ֻ��1���������������������� 
		for (LL j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			p[index++] = i;
		}

		flag = 1;
	}

	return;
}
#endif 


//73.��ֵ 
#if 0
#include <iostream>

using namespace std;

typedef long long LL;

const LL MAXN = 1e4;

LL yueshu[MAXN];
int main()
{
	LL index = 0;

	LL i;
	for (i = 1; i <= 9999999999; i++)
	{
		for (LL j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				if (i / j != j)
				{
					yueshu[index++] = j;
					yueshu[index++] = i / j;
				}
				else
					yueshu[index++] = j;
			}
		}

		//����д�����ڵ�������֤��		
		//		for(int i=0;i<10;i++)
		//		{
		//			cout<<yueshu[i]<<" ";
		//		}
		//		cout<<endl;

		LL bianli = 0;
		LL count = 0;
		while (yueshu[bianli])
		{
			count++;
			bianli++;
		}
		if (count == 100)
			break;

		fill(yueshu, yueshu + MAXN, 0);
		index = 0;
	}


	cout << i;

	return 0;
}
#endif 


//74.���ʷ��� 
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;

	getline(cin, str);

	long count[26] = { 0 };

	for (auto it = str.begin(); it != str.end(); it++)
	{
		count[*it - 'a']++;
	}

	//	long m=-1;
	//	for(int i=0;i<26;i++)
	//	{
	//		m=max(m,count[i]);
	//	}

		//max_element()����ָ������ڷ�Χ�����ֵ��ָ�� 
	long* m_p = max_element(count, count + 26);

	char ch = 'a' + m_p - count;

	cout << ch << endl << *m_p;

	return 0;
}
#endif


//75.��������Է��� 
#if 0
#include <iostream>
#include <string> 
#include <cctype>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL K;
	cin >> K;

	cin.get();

	string str;
	getline(cin, str);

	string target1{ "Alice" };
	string target2{ "Bob" };

	LL count = 0;

	//Ԥ������Alice��Bobǰ������ĸ����ɾȥ 
	LL loc1 = 0, loc2 = 0;

	//	while(loc1!=str.size()&&loc2!=str.size())
	while (1)
	{
		loc1 = str.find(target1, loc1);

		//�˴�������
		//()&&() 
											//***�˴�5������ֵ 
		if ((loc1 != string::npos) &&
			(isalpha(str[loc1 - 1]) || isalpha(str[loc1 + 5])))
		{				//***�˴�5�ǳ��� 
			str.erase(loc1, 5);
		}

		loc2 = str.find(target2, loc2);
		//***
		if ((loc2 != string::npos) &&
			(isalpha(str[loc2 - 1]) || isalpha(str[loc2 + 3])))
		{
			str.erase(loc2, 3);
		}

		if (loc1 != string::npos && loc2 != string::npos)
		{
			loc1++;
			loc2++;
		}
		else if (loc1 == string::npos && loc2 == string::npos)
		{
			break;
		}
		else if (loc1 == string::npos)
		{
			loc2++;
		}
		else
			loc1++;
	}

	cout << str;

	loc1 = loc2 = 0;
	LL loc3 = 0, loc4 = 0;
	while (1)
	{
		loc1 = str.find(target1, loc1);
		loc2 = str.find(target2, loc2);

		//***
		if (loc1 == string::npos || loc2 == string::npos)
			break;

		//����ȡС����loc3����loc3ָ��A��B 
		loc3 = min(loc1, loc2);

		if (loc3 == loc1)
		{
			loc1++;
		}
		else if (loc3 == loc2)
		{
			loc2++;
		}

		//�������A...B...A����������������B...A 
		if (loc4 != 0)
			if (loc3 - loc4 <= K)
			{
				if (str[loc3] != str[loc4])
					count++;
			}

		loc1 = str.find(target1, loc1);
		loc2 = str.find(target2, loc2);

		//***
		if (loc1 == string::npos || loc2 == string::npos)
			break;

		//loc4ָ��A��B 
		loc4 = min(loc1, loc2);

		if (loc4 == loc1)
		{
			loc1++;
		}
		else if (loc4 == loc2)
		{
			loc2++;
		}

		if (loc4 - loc3 <= K)
		{
			if (str[loc3] != str[loc4])
				count++;

		}


	}
	//Ҫ����4��������ʵ����Щ�Ѿ� 

	cout << count;

	return 0;
}
//20
//This is a story about Alice and Bob.Alice wants to send a private message to Bob.
#endif





























