//1.2 ���ﵥ
#if 0
#include <iostream>
#include <valarray>
//#include <algorithm> 
using namespace std;

int main ()
{
	freopen("cost.txt","r",stdin);

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
	int index=0;
	while(cin>>a>>b)
	{
//���� valarray���󳤶Ȳ�֧�ֶ�̬�ı� 
//		jiage.push_back(a);
//		zhekou.push_back(b);
		jiage[index]=a;
		zhekou[index]=b;
		index++;
	}
	
	int count=0;//������Ʒ���� 
	for(int i=0;i<100;i++)
	{
		if(jiage[i])
		count++;
	}
	
//	for(int i=0;i<count;i++)
//	{
//	cout<<jiage[i];
//	}
	 
	valarray<double> result(100);
	for(int i=0;i<count;i++) 
	{
		if(zhekou[i]>0&&zhekou[i]<10)//��9�� 
		result[i]=jiage[i]*0.1*zhekou[i];
		else//��88�� 
		result[i]=jiage[i]*0.01*zhekou[i];
	}
	
	double sum=result.sum(); 
	cout<<sum;
	
	return 0;
}
#endif


//1.3 �ڼ���(�ж����꣬�������Ƿ�Ϊ29��)
#if 0
#include <iostream>

using namespace std;
bool runnian (int year);

int main()
{
	int year;
	
	cin>>year;
	
	if(runnian(year))
	cout<<"������"<<endl;
	
	return 0;
}
bool runnian (int year)
{
	return(year%4==0&&year%100!=0||year%400==0);
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
	
	int i,temp;
	for(i=0; i<10; i++)
	{
		for(int j=0;j<32;j++)
		{
			in>>temp;
			data[i].push_back(temp);
		}
	}
	
	for(i=0; i<10; i++)
	{
		for(auto p=data[i].begin();p!=data[i].end();p++)
		cout<<*p<<" ";
		
		cout<<endl;
	}
	cout<<endl;
		

	//���ڴ�����ǵڼ����� 
	int dijigezi=1;

	vector<int> data2[16];//����һ��2*16�Ķ�ά����
	int j=0;
	for(i=0;i<32;i++)
	{
		data2[j].push_back(data[dijigezi-1][i]);
		data2[j].push_back(data[dijigezi-1][++i]);
		j++; //���� 
	} 

	//��ʾʮ���Ʊ�ʾ��������Ϣ 
	int huanhang=0;	
	for(i=0;i<16;i++)
	for(auto p=data2[i].begin();p!=data2[i].end();p++)
	{
		cout<<*p<<" ";
		huanhang++;
		
		if(huanhang%2==0)
		cout<<endl;
	}

	//***ע*** 
	//������⣺����ȫΪ0 (��C������ȷʵ������)
	char shuzu[16][16]={{'0'},{'0'}};
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
			shuzu[i][j]='0';
	}
	
	int num;

	for(int i=0;i<16;i++)		//***ע***�˴�-1����д 
	for(auto p=data2[i].begin();p!=data2[i].end()-1;   )
	{
		num=*p;			
		
		//��Ϊ���� 
		if(num<0)
		num=256+num;
		 
		int index=7;//����ȡ�൹�����ɴ�洢ʱ���Ŵ棬��ʱ˳�Ŷ� 
		while(num!=0&&index!=0)
		{
			shuzu[i][index--]=num%2+'0';
			num/=2;
		}
		
		p++;
		num=*p;
		
				
		if(num<0)
		num=256+num;
		
		index=15;
		while(num!=0&&index!=8)
		{
			shuzu[i][index--]=num%2+'0';
			num/=2;
		}			
//***�������ת���ɶ����ƣ��� 
//��������bitsetģ���� 
	}
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		cout<<shuzu[i][j];
	cout<<endl;
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
	
	while(cin>>num)
	{
		num-=1; //�������ֵ 
		
		//ʹ��vector�����ĺô��ǿ��Զ�̬�������ȣ�����
		//ʹ�������޷�����û��Ԫ�������λ�õı�ʾ 
		vector<int> data;
		
		//***ע***Ҫʹ�ó�������ѭ������������1ʱ��data���������� 
		do
		{
			data.push_back(num%26);

			num/=26;
		}while(num!=0);
		
		
		//***ע***д��
//		for(auto i=data.end()-1;i>=data.begin();i--)//Ҳ���� 
		for(auto i=data.rbegin();i!=data.rend();i++)
		cout<<*i;
		
		//�����Ѿ�ת���ɶ�ʮ�����Ʊ�ʾ 
		
		
		//***ע***
		//��λ������λ���ȵ��������λ֮���λ��Ӧ����
		//ԭ������-1����Ϊ�Ͷ�λ����˵��һ���������10��ʼ��
		//������Ҫ����00��ʼ�� 
		cout.put('\n');
		
		//����ָ��ͨ���ȵݼ����ٽ��д����
		for(auto i=data.rbegin();i!=data.rend();i++)
		{
			if(data.size()==1) 
			cout<<(char)(*(i)+'A');
			else
			{
				if(i==data.rend()-1)//���λ ***ע***�˴�-1��Ҫ��� 
				cout<<(char)(*(i)+'A');//rend()ָ��ת���еĳ�β������-1��ָ��ת���е����һ��Ԫ�� 
				else//��λ 
				cout<<(char)(*(i)+'A'-1);
			}
		}
		 
		cout<<endl;
	}
	
	return 0;
}
#endif


//1.6 ������ 
//��������ʱ��Ĳ�ֵ 
#if 0
#include <iostream>
using namespace std;

bool runnian (int year);
int main()
{
	long minutes=0;
	
	//����1922�굽2019��ķ����� 
	for(int year=1922;year<=2019;year++)
	{
		if(runnian(year))
		{
			cout<<year<<endl;
			minutes+=366*24*60;
		}
		else
		minutes+=365*24*60;
	}
	
	//1921��7��23������12ʱ��12��31�յ�ʱ�� 
	minutes+=9*24*60-12*60+(31+30+31+30+31)*24*60;
	//2020��1��1�յ�7��1������12ʱ��ʱ��
	minutes+=(31+29+31+30+31+30)*24*60+12*60; 
	
	cout<<minutes; 

	return 0;
}
bool runnian (int year)
{
	bool status=0;
	
	if(year%4==0&&year%100!=0||year%400==0)
		status=1;
	
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
    long long cunchukongjian =(long long)256 *(long)1024 * (long)1024 * 8;
	
	int zhengshu=32;
	//[Warning] integer overflow in expression [-Woverflow]
	cout<<cunchukongjian/zhengshu;
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
	cin>>haomiaoshu;
	
	long long miaoshu=haomiaoshu/10;//***����1��Ӧ�õ���1000���� 
	
	int hour=(miaoshu/60/60)%24;
	
//	miaoshu-=hour*3600;
	
	int minutes=(miaoshu/60)%60;
	
//	miaoshu-=minutes*60;
	
	int second=miaoshu%60;
	
	//***ע***coutʵ��ʱ���벻����λʱǰ����0���鷳�� 
	//������printf()��ת��˵�����η�ʵ��ǰ����0 
	cout<<hour<<":"<<minutes<<":"<<second<<endl;

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
	cin>>haomiaoshu;
	
	//ȥ���������� 
	haomiaoshu%=(24*60*60*1000); 
	
	//ȥ�����룬����� 
	long long miaoshu=haomiaoshu/1000;
	
	int hour=(miaoshu/60/60)%24;
	
//�ɲ�д 
//	miaoshu-=hour*3600;
	
	int minutes=(miaoshu/60)%60;
	
//	miaoshu-=minutes*60;
	
	int second=miaoshu%60;
	
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
	printf("%02d:%02d:%02d",hour,minutes,second);
	
	return 0;
}
#endif



















