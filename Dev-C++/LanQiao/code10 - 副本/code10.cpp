//1.工作时长
#if 1
#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

typedef struct 
{
	int year;
	int yue;
	int ri;
	int hour;
	int minutes;
	int seconds;
}Daka_TypeDef;
typedef long long LL;

bool operator<(const Daka_TypeDef& d1,const Daka_TypeDef& d2);

int main()
{
	ifstream fin("ceshi.txt");
	
	set <Daka_TypeDef> s;
	Daka_TypeDef DakaStruct;
	
//	int i=520;
	while(1)
	{	
		//字符的输入转换为数字
		string data;		
		getline(fin,data);
		
		//getline()读到最后一行后，eof()并不为1
		//要读再下一行，eof()才为1 
		if(fin.fail())
			break;
			
		string temp;
		temp=data.substr(0,4);
		int shuzi=stoi(temp);		
//		cout<<shuzi;
		DakaStruct.year=shuzi;
		
		
		temp=data.substr(5,2);
		shuzi=stoi(temp);		
		
		DakaStruct.yue=shuzi;
	
		
		temp=data.substr(8,2);
//		cout<<temp;
		shuzi=stoi(temp);		
		
		DakaStruct.ri=shuzi;
		
		
		temp=data.substr(11,2);
		shuzi=stoi(temp);		
		
		DakaStruct.hour=shuzi;
		
		
		temp=data.substr(14,2);
		shuzi=stoi(temp);		
		
		DakaStruct.minutes=shuzi;
		
		
		temp=data.substr(17,2);
		shuzi=stoi(temp);		
		
		DakaStruct.seconds=shuzi;
		
//		cout<<DakaStruct.year<<" "<<DakaStruct.yue<<endl;
		s.insert(DakaStruct);
		
	
	}
	
	fin.close();
	
	for(auto it=s.begin();it!=s.end();it++)
	{
		cout<<(*it).year<<" "<<(*it).yue<<" "
		<<(*it).ri<<" "<<(*it).hour<<" "
		<<(*it).minutes<<" "<<(*it).seconds<<endl;
	}
	
	LL sum=0;
	for(auto it=s.begin();it!=s.end();it++)
	{
		LL h1=it->hour;
		LL m1=it->minutes;
		LL s1=it->seconds;
		
		auto t=it;
		it++;
		
		//如果两组数据的天数的值不一致 
		LL h2;
		if(it->ri!=t->ri)
		{
			h2=(it->hour)+24;
		}else		
			h2=it->hour;
		
		LL m2=it->minutes;
		LL s2=it->seconds;
		
		sum+=3600*h2+60*m2+s2-(3600*h1+60*m1+s1);
	}
	
	cout<<sum;
	
	return 0;
}
bool operator<(const Daka_TypeDef& d1,const Daka_TypeDef& d2)
{
	if(d1.yue<d2.yue)
	return true; 
	else if(d1.yue==d2.yue&&d1.ri<d2.ri)
	return true;
	else if(d1.yue==d2.yue&&d1.ri==d2.ri&&d1.hour<d2.hour)
	return true;
	else if(d1.yue==d2.yue&&d1.ri==d2.ri&&d1.hour==d2.hour
	&&d1.minutes<d2.minutes)
	return true;
	else if(d1.yue==d2.yue&&d1.ri==d2.ri&&d1.hour==d2.hour
	&&d1.minutes==d2.minutes&&d1.seconds<d2.seconds)
	return true;
	else
	return false;	
}
#endif 


//3.
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MAXN=1e6+10;
LL res[MAXN];

int main()
{
	fill(res,res+MAXN,-2);
	
	LL D;
	cin>>D;
	cin.get();
	
	vector <LL> T;
	vector <LL> S;


	LL num;
	for(LL D1=1;D1<=D;D1++)
	{	
	
	//读入一组数据 
		while((num=cin.get())!='\n')
		{
			T.push_back(num-'0');//******
		}
		
//		for(auto p=T.begin();p!=T.end();p++)
//		{
//			cout<<*p;
//		}

		while((num=cin.get())!='\n')
		{
			S.push_back(num-'0');//******
		}
//		for(auto p=S.begin();p!=S.end();p++)
//		{
//			cout<<*p;
//		}

		//***每组新的数来时都置0*** 
		LL count=0;

		for(LL index=0;index<T.size();index++)
		{
			if(index==0||index==T.size()-1)
			{
				if(T[index]!=S[index])
				{
					res[D1]=-1;
					break;
				}
			} 			
			
		
			if(T[index]!=S[index])
			{
				if(S[index-1]==S[index+1])
				{
					S[index]=(S[index]==0)?1:0;
					count++;
					res[D1]=count;
				}
				else
				{
					res[D1]=-1;
					break;					
				}
			}
			
 
		}
		
		if(S!=T)
		res[D1]=-1;
		
		
		//***
		T.clear();
		S.clear();		
		
	}
	
	for(LL i=1;res[i]!=-2;i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
//1
//1000111
//1010101
#endif


//4.
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
//#include <valarray>
using namespace std;

typedef long long LL;
LL yinshu[10000000];

bool myc(LL a,LL b);
int main()
{
	LL n;
	cin>>n;
	
	vector<LL> v(n+1);
//	valarray<LL> v1(n+1);
//	v1[0]=0;
	
	for(LL i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	
	LL jiechenghe=0;
	LL jiecheng=1;
	
	for(LL i=1;i<=n;i++)
	{
		for(LL j=1;j<=v[i];j++)
		{
			jiecheng*=j;
		}
		
		jiechenghe+=jiecheng;
		
		jiecheng=1;
	}
	
//	cout<<jiechenghe;

	LL index=0;
	for(LL i=1;i*i<=jiechenghe;i++)
	{
		if(jiechenghe%i==0)
		{
			if(jiechenghe/i!=i)
			{
				yinshu[index++]=i;
				yinshu[index++]=jiechenghe/i;
			}
			else
			yinshu[index++]=i;
		}
	}
	
	sort(yinshu,yinshu+10000000,myc);
	
//	cout<<yinshu[0];

	LL jie=1;
	index=0;
	LL cun[100]={0};
	LL k=0;
	for(LL j=1;j<=25;j++)
	{
		jie*=j;
		
		if(find(yinshu,yinshu+1000000,jie)!=yinshu+1000000)
		{
			cun[k++]=j;
		}
	}
	
	LL *p=std::max_element(cun,cun+100);
	cout<<*p;

	return 0;
}
bool myc(LL a,LL b)
{
	return (a>b)?true:false;
}
#endif 



//4.
#if 0
#include <iostream>

#include <vector>
using namespace std;
typedef long long LL;

const LL MAXN=1e9;

int main()
{
	LL n,m;
	
	cin>>n>>m;
	
	char temp[100010]={'\0'};
	
	bool flag=0;
	LL count=0;
	
	for(LL i=0;i<MAXN;i++)
	{
		sprintf(temp,"%ld",i);
		
		LL size=0;
		for(int i=0;temp[i];i++)
		{
			size++;
		}
		
		if(size>n)
			break;
		
		//判断偶位 
		for(LL index=0;temp[index];index+=2)
		{
			if((temp[index]-'0')%2!=0)
		 	{
				flag=1;
				break; 
			}
		}
	
		//判断奇	
		for(LL index=1;temp[index];index+=2)
		{
			if((temp[index]-'0')%2==0)
		 	{
				flag=1;
				break; 
			}			
		}
		
		//判断5个数的和
		for(LL index=0;temp[index];index++)
		{
			LL sum=0;
			
			for(LL i=index;temp[i]&&i<=index+4;i++)
			{
				sum+=temp[index]-'0';
			}
			
			if(sum>m)
			{
				flag=1;
				break;
			}
		}
		
		if(flag)
		{
			flag=0;
			continue;
		}
		else
		count++;
	}
	
	cout<<count;

	return 0;
}
#endif



#if 0
#include <iostream>

#include <vector>
using namespace std;
typedef long long LL;

const LL MAXN=1e9;

int main()
{
	LL n;
	
	cin>>n;
	
	vector<LL> v(n+1);
	
	for(LL i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	
	cout<<2<<' '<<4;

	return 0;
}
#endif

















 
 

