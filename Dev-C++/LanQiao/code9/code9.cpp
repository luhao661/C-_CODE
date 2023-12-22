//#include<bits/stdc++.h>包含了目前c++所包含的所有头文件，是个万能库
//包含
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
//******************不要随便修改之前的行对应的行号，笔记本记录的知识点要用来索引的***************************** 

//2022年第十三届蓝桥杯大赛软件类省赛C/C++研究生组真题
//质因数个数
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

#define MAX 10000

int main()
{
	long *zhishu=new long[MAX];
	
	fill(zhishu,zhishu+MAX,0);
	
	zhishu[0]={2};
	
	long index=1;
	bool flag=0;
	for(long i=3;i<MAX;++i)
	{
		for(long j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}			
		}
		
		if(flag)
		zhishu[index++]=i;
	}
	
//	for(int i=0;i<100;i++)
//	cout<<zhishu[i]<<" ";

	long long num;
	cin>>num;
	
	long count=0;
	for(long i=0;i<MAX&&zhishu[i]!=0;i++)
	{
		if(!(num%zhishu[i]))	
		{
//			cout<<zhishu[i]<<" ";
			count++;
		}
	}
	
	cout<<count;
	
	delete [] zhishu;
	
	return 0;
} 
#endif 


//********************“蓝桥杯”真题分类解析********************
//1.显示不同进制 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num=10;
	
	cout<<showbase;
	cout<<dec<<num<<" "<<oct
	<<num<<" "<<hex<<" "<<num;

	return 0;
}
#endif


//2.存储二进制的数字 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num=4;
	
	int index=7;
	char erjinzhi[8];
	
	fill(erjinzhi,erjinzhi+8,'0'); 

	while(num)
	{
		erjinzhi[index]=num%2+'0';
		num/=2;
		
		index--;
	}
	
	for(char x :erjinzhi)
	cout<<x;

	return 0;
}
#endif


//3.在C++中是否和C的数组的初始化的方法效果一致
//即部分初始化情况下，未初始化的元素是否都会被设置为0 
#if 0
#include <iostream>

using namespace std;
const int MAX=20;

int main()
{
	//一维 
	int yiwei[10]={1};
	//二维 
	int erwei[10][10]={1};
	
	for(int x:yiwei)
		cout<<x;
	
	cout<<endl<<endl;;
	
	for(int i=0;i<10;i++)
	{	for(int j=0;j<10;j++)
			cout<<erwei[i][j]<<" "; 
		cout<<endl;
	}	

	cout<<endl;
			
	long **p=new long* [MAX]; //有MAX个元素，每个元素都是指向long的指针  
	for(long i=0;i<MAX;i++)
	{
		//一维数组的指针*(p+i)指向一个有MAX个元素的数组，每个元素都是long类型的值 
		*(p+i)=new long [MAX];
 	} 
 	
 	p[0][0]=1;
 	
 	for(long i=0;i<MAX;i++)
 	{
		for(long j=0;j<MAX;j++)
		{
			cout<<p[i][j]<<" ";
		} 
		cout<<endl;
	}
		
	cout<<endl;
	
	long (*p1) [MAX]=new long [MAX][MAX];
	
	p1[0][0]=1;		
	
 	for(long i=0;i<MAX;i++)
 	{
		for(long j=0;j<MAX;j++)
		{
			cout<<p1[i][j]<<" ";
		} 
		cout<<endl;
	}
		
	cout<<endl;
	
	//结论：
	//C++中，不支持C中的指定初始化器而且 
	//以一般方法创建的数组，未初始化的元素会自动被设置为0
	//但以new创建的话，初始化一个元素后，未初始化的元素不会自动被设置为0		

	return 0;
} 
#endif 


//4.明码 
#if 1
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int input[10][32];
	
//	freopen("1.4.txt","r",stdin);
	ifstream fin("1.4.txt");
	
	for(int i=0;i<10;i++)
		for(int j=0;j<32;j++)
			fin>>input[i][j];
			
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<32;j++)		
			cout<<input[i][j]<<' ';
		cout<<endl;
	}
	
	fin.close();
	
	int getdata[16][16];
	fill(&getdata[0][0],&getdata[0][0]+16*16,0);
	
//	for(int i=0;i<16;i++)
//	{
//		for(int j=0;j<16;j++)
//		{
//			cout<<getdata[i][j];
//		}
//		cout<<endl;
//	}
	
	int m,n;
	m=0;
	
	//第i+1行的数据给到16*16的数组中 
	int i=0;
	
	for(int j=0;j<32;j++)//第i+1行第j+1列 
	{
		n=7;
		
		if(input[i][j]<0)
		input[i][j]=256+input[i][j];
		
		while(input[i][j])//把某个数字用8位二进制来表示 
		{
			getdata[m][n--]=input[i][j]%2;
			input[i][j]/=2;
		} 
		
		j++;
		
		n=15;
		
		if(input[i][j]<0)
		input[i][j]=256+input[i][j];
		
		while(input[i][j])//把某个数字用8位二进制来表示 
		{
			getdata[m][n--]=input[i][j]%2;
			input[i][j]/=2;
		}
		
		m++;
	} 
	
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<getdata[i][j];
		}
		cout<<endl;
	}
	
	return 0;
} 
#endif


//5.年号字符串 
#if 0
#include <iostream>
#include <algorithm>
 
using namespace std;

int main()
{
	int input=2019;
	
	int data[5];
	fill(data,data+5,-1);
	
	//倒着存26进制的数 
	int index=4;
	
	//将输入的值减1，则输入26，实际为25，26进制的数为25，用Z
	//表示，这样与题目的要求匹配 
	input-=1; 
	
	while(input)
	{
		data[index--]=input%26;
		input/=26;
	}//26进制，一个位上数值为0~25 
	
//	char x;
//	for(int i=0;i<5;i++)
//	{
//		if(data[i]==-1)
//		continue;
//		
//		x=data[i]+'A';//瑕疵：输入27，得到BA 
//		cout<<x;		
//	}

	char x;
	for(int i=0;i<5;i++)
	{
		if(data[i]==-1)
		continue;
		
		if(i!=4)//若非末位，则要处理成-1 
		{
			x=data[i]+'A'-1;
			cout<<x;	
		}
		else
		{
			x=data[i]+'A';
			cout<<x;
		}
	}
	
	return 0;
}
#endif


//6. 时间显示 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;

int main()
{
	LL num;
	cin>>num;//输入的是个1970年1月1日00:00:00到当前时刻的毫秒数 
	
	num%=24*60*60*1000;//输入的毫秒数保留最多24小时的毫秒数
	
	num/=1000;//num为秒数
	int sec=num%60;
	num/=60;//num为分钟数
	int minutes=num%60;
	num/=60;//num为小时数
	
	cout<<setw(2)<<setfill('0');
	cout<<num<<':'<<setw(2)<<minutes<<':'<<setw(2)<<sec; 

	return 0;
}
//1618708103123
#endif 


//7.分解质因数 
#if 0
#include <iostream>
//#include <set>
#include <algorithm>
using namespace std;

const int LIM=50;
int zhishu[LIM];

void getzhishu(int *);

int main()
{
	int a,b;
	cin>>a>>b;
	
	getzhishu(zhishu);
	
	long count=0;
	//处理数字i 
	for(int i=a;i<=b;i++)
	{
//错误写法： 
//若数字i是质数 
//		for(int index=0;index<LIM;index++)
//		{
//			
//			if(i==zhishu[index])
//			{
//				count+=1;
//				break;      //***注***此处的break只退出当前循环 
//			}					//不回到for，而是仍执行下面的语句 
//		} 

		//若数字i是质数 
		#if 1 
		auto p=find(zhishu,zhishu+LIM,i);
		if(p!=zhishu+LIM)
		{
			count++;
			continue;
		} 
		#endif//经过测试，此语句块不写也可以，但时间复杂度提高了 
		
		//若数字i不是质数 		
		int temp=i;
		for(int index=0;index<LIM;index++)
		{
			//***注***是用while 
			while(temp%zhishu[index]==0)
			{
				count++;
				temp/=zhishu[index];
			}
		} 		 
	}

	cout<<count; 
	
	return 0;
}
void getzhishu(int *p)
{
	*p=2;//zhishu[0]=2
	
	bool flag;
	int index=1;
	
	for(int num=3;num<500&&index<LIM;num++)
	{
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				flag=0;
				break;
			}
			else
				flag=1;
		}
		
		if(flag)
		p[index++]=num;
	}
	
//	for(int x:zhishu)
//		cout<<x<<" ";
}
#endif
//7.修改 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>zhishu;

void getzhishu(vector<int>& v,int max);

int main()
{
	int a,b;
	cin>>a>>b;
	
	getzhishu(zhishu,b);
	
	long count=0;
	//处理数字i 
	for(int i=a;i<=b;i++)
	{
		//若数字i是质数 
		#if 1 
		auto p=find(zhishu.begin(),zhishu.end(),i);
		if(p!=zhishu.end())
		{
			count++;
			continue;
		} 
		#endif//经过测试，此语句块不写也可以，但时间复杂度提高了 
		
		//若数字i不是质数 		
		int temp=i;
		for(int index=0;index<zhishu.size();index++)
		{
			//***注***是用while 
			while(temp%zhishu[index]==0)
			{
				count++;
				temp/=zhishu[index];
			}
		} 		 
	}

	cout<<count; 
	
	return 0;
}
void getzhishu(vector<int>& v,int max)
{
	v.push_back(2);//zhishu[0]=2
		
	bool flag;
		
	for(int num=3;num<=max;num++)
	{
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				flag=0;
				break;
			}
			else
				flag=1;
		}
		
		if(flag)
		v.push_back(num);
	}
	
	for(int x:zhishu)
		cout<<x<<" ";
}
#endif


//8.测试find()函数的返回值 
#if 0 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int shuzu[3]={1,2,3};
	
	int* p=find(shuzu,shuzu+3,4);
	
	if(p==shuzu+3)
		cout<<"未找到！";
	else
		cout<<"已找到！"; 

	return 0;
}
#endif


//9.十进制转十六进制 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long num;
	cin>>num;
	
	cout<<hex<<uppercase<<num;

	return 0;
}
#endif


//10.回文数 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	
	int M;
	cin>>M;
	
	char shuzi[99999];
	fill(shuzi,shuzi+99999,'\0');
	
	long num=0;
	
	if(N>=2&&N<=10)
	{
		sprintf(shuzi,"%d",M);  //没解决根据N代表的进制，来输入数字 
		num=atoi(shuzi);
	}
//	else
//	{
//		int len=M2.size();
//		int index=0;
//		while(len!=index)
//		{
//			num+=pow(16,len-index-1)*M2[index++]; //没解决A~F的十六进制输入 
//		}
//	}
	
	cout<<num;

	return 0;
}
#endif
//10.改正 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	string M;
	cin>>M;
	
	
	long num=0;
		
	if(N!=16)
	{	
		int len=M.size();	
	
		int index=0;
		while(len!=index)
		{
			long a=pow(N,len-index-1);
			
	//		cout<<a<<" ";
	//		cout<<M[index]<<" "<<a*M[index]<<" ";
			num+=a*(M[index]-'0');//***注***一定要这样写 
			
			index++ ;
		}
	}
	else
	{
		int len=M.size();	
	
		int index=0;
		while(len!=index)
		{
			long a=pow(N,len-index-1);
			
	//		cout<<a<<" ";
	//		cout<<M[index]<<" "<<a*M[index]<<" ";
			if(M[index]!='A'&&M[index]!='B'&&
			M[index]!='C'&&M[index]!='D'&&
			M[index]!='E'&&M[index]!='F')
			{
				num+=a*(M[index]-'0');//***注***一定要这样写 
			}else if(M[index]!='A')
			{
				num+=a*(M[index]-'A'+10);
			}else if(M[index]!='B')
			{
				num+=a*(M[index]-'B'+11);
			}else if(M[index]!='C')
			{
				num+=a*(M[index]-'C'+12);
			}else if(M[index]!='D')
			{
				num+=a*(M[index]-'D'+13);
			}else if(M[index]!='E')
			{
				num+=a*(M[index]-'E'+14);
			}else if(M[index]!='F')
			{
				num+=a*(M[index]-'F'+15);
			}
			index++ ;
		}
	}		
	
//	cout<<num;

	char cnum[20];
	fill(cnum,cnum+20,'\0');
	
	sprintf(cnum,"%d",num);
	
//	cout<<cnum;
	
	string snum(cnum);//原数字 
	string stemp(cnum);
	
	reverse(stemp.begin(),stemp.end());//颠倒后的数字 
	
	int count=0; 
	
	while(stemp!=snum)
	{
		long num1=atol(stemp.c_str());
		long num2=atol(snum.c_str());

		sprintf(cnum,"%d",num1+num2);//变成C风格字符串 
		snum=cnum;//变成string对象 
		stemp=snum;
		reverse(stemp.begin(),stemp.end());
		
		count++;		
	}
	
	if(count<=30) 
		cout<<count;
	else
		cout<<-1; 

	return 0;
}
#endif


//11.日期问题 
#if 0
#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int year,month,day;
	char a;
	cin>>year>>a
	>>month>>a
	>>day;
	
		
	set<      pair<  pair<int ,int> ,int >     > riqi;
	
	for(int y=1960;y<=2059;y++)
	{
		if(y%4==0&&y%100!=0||y%400==0)
		{
			days[2]=29;
		}
		
		
		for(int m=1;m<=12;m++)
		{
			for(int d=1;d<=days[m];d++)
			{
				
				int temp;
				
				temp=year;
				
				if(temp>=60&&temp<=99)
				temp+=1900;
				else
				temp+=2000;
				
				if(temp==y&&month==m&&day==d)
				{
					pair<int,int> a (y,m);//使用pair类的构造函数 
					pair<  pair<int ,int> ,int > b;

					b.first=a;
					b.second=d;
					
					riqi.insert(b); 
				}
				
				
				temp=day;
				
				if(temp>=60&&temp<=99)
				temp+=1900;
				else
				temp+=2000;
								
				if(temp==y&&year==m&&month==d)
				{
					pair<int,int> a (y,m);
					pair<  pair<int ,int> ,int > b;

					b.first=a;
					b.second=d;
					
					riqi.insert(b); 
				}				
		
				
				if(temp==y&&month==m&&year==d)
				{
					pair<int,int> a (y,m);
					pair<  pair<int ,int> ,int > b;

					b.first=a;
					b.second=d;
					
					riqi.insert(b); 
				}								
			}
		}
	}
	
	for(auto it=riqi.begin();it!=riqi.end();it++)
	{
		cout<<setfill('0');
		
		cout<<(*it).first.first<<"-"
		<<setw(2)<<(*it).first.second<<"-"
		<<setw(2)<<(*it).second<<endl;
	}

	return 0;
}
#endif


//12.整除序列 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

int main()
{
	ULL num;
	cin>>num;
	
	cout<<num<<" ";
	while(num)
	{
		num/=2;
		
		if(num<=0)
			break;
			
		cout<<num<<" ";	
	}	

	return 0;
}
#endif


//13.整数拼接 
#if 0
#include <iostream>
#include <cmath>
using namespace std;

char temp[1000000000];

long get_weishu(long );

int main()
{
	long n,k;
	cin>>n>>k;
	
	long* get_shuzu=new long[n];
		
	for(int i=0;i<n;i++)	
	{
		cin>>get_shuzu[i];
	}
	
	long* chuli_shuzu=new long[(1+n-1)*(n-1)];
	
	int i=0;
	int index=0;
	while(i!=n-1)
	{
		long weishu1=get_weishu(get_shuzu[i]);
		
		for(int j=i+1;j<n;j++)
		{
			long weishu2=get_weishu(get_shuzu[j]);
			
			
			long shuzi1=get_shuzu[j]*pow(10,weishu1)+get_shuzu[i];
			
			chuli_shuzu[index++]=shuzi1;
			
			long shuzi2=get_shuzu[i]*pow(10,weishu2)+get_shuzu[j];
			
			chuli_shuzu[index++]=shuzi2;			
		}
		
		i++;
	}
	
//	for(int i=0;i<(1+n-1)*(n-1);i++)
//		cout<<chuli_shuzu[i]<<" ";
	
	long count=0;
	for(int i=0;i<(1+n-1)*(n-1);i++)
	{
		if(chuli_shuzu[i]%k==0)
		count++;
	}
	cout<<count;

	delete []get_shuzu;
	delete []chuli_shuzu;

	return 0;
}

long get_weishu(long num)
{
	long weishu=0;

	fill(temp,temp+1000000000,'\0');
	
	sprintf(temp,"%ld",num);
	
	int index=0;
	while(temp[index++]!='\0')
	weishu++;
	
	return weishu;	
}
#endif


//14.卡片 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int kapian[10];//0到9的卡片数字 
	fill(kapian,kapian+10,2021);


#if 0 //任意有一种数字的卡片为0,就输出 
	int* p=find(kapian,kapian+10,0);
	long num; 
	for(num=1;p==kapian+10;num++)
	{
		if(num<10)
		kapian[num]--;
		else
		{
			char temp[30];
			sprintf(temp,"%ld",num);
//			cout<<temp<<" ";
			
			for(int i=0;temp[i]!='\0';i++)
			{
				kapian[temp[i]-'0']--;//***注***要这样写： -'0' 
				
				p=find(kapian,kapian+10,0);
				if(p!=kapian+10)
				goto END;
			}
		}
		
		for(int i=0;i<10;i++)
		cout<<kapian[i]<<" ";
		cout<<endl;
		
		p=find(kapian,kapian+10,0);
	}

END:	cout<<num-1;
#endif

	long num=1;
	bool biaoji=1;
	while(1)
	{
		if(num<10)
		kapian[num]--;
		else
		{
			char temp[30];
			sprintf(temp,"%ld",num);
//			cout<<temp<<" ";
			
			for(int i=0;temp[i]!='\0';i++)
			{
				kapian[temp[i]-'0']--;//***注***要这样写： -'0' 
			}
		}
		
		for(int i=0;i<10;i++)
		{
			if(kapian[i]<0)
			{
				biaoji=0;
				break; 
			} 
		}
		
		if(!biaoji)
			break;
		
		num++;
	}
	
	cout<<num-1;

	return 0;
}
#endif


//15.杨辉三角 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

//const long MAX=10000;

int main()
{
	long N;
	cin>>N;
	long count=0;	
	
	long MAX=1000;
	
	//用new创建二维数组(此方法，行列值均可以是变量)
	//p指向n*n的二维数组的第一行，存第一行的地址 
	long **p=new long* [MAX]; //有MAX个元素，每个元素都是指向long的指针  
	for(long i=0;i<MAX;i++)
	{
		//一维数组的指针*(p+i)指向一个有MAX个元素的数组，每个元素都是long类型的值 
		*(p+i)=new long [MAX];
 	} 
 	
//用fill()有错误数据产生 
//	fill(&p[0][0],&p[0][0]+100*100,0L);
//***原因***用new创建的二维数组，而且是如上方式创建的二维数组，
//数组元素不在一片连续的内存区域
//而LanQiao_code第5050行的new创建的二维数组在一片连续的内存区域 
 	
 	for(long i=0;i<MAX;i++)
 	{
		for(long j=0;j<MAX;j++)
		{
			p[i][j]=0;
		} 
	}
 	
 	for(long i=1;i<MAX;i++)
 	{
		for(long j=1;j<=i;j++)
		{
			if(j==1||j==i)
			{
				p[i][j]=1;
			}
			else
			{
				p[i][j]=p[i-1][j-1]+p[i-1][j];
			}
			
			//在生成杨辉三角的同时，进行数字的个数的计数 
			count++;
			if(p[i][j]==N)
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

END:	cout<<count;

	return 0;
}
#endif


//16.等差素数数列 
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

	int gongcha=1;
	int changdu=1;
//	while(changdu!=10)
//	{

	//从第i个数字开始试 
	for(int i=0;i<1000;i++)
	{
		//第i个数从公差为1开始试，到公差为999结束 
		for(; gongcha<1000;gongcha++)
		{
			long temp=sushu[i]+gongcha;
			long* loc=find(sushu,sushu+1000,temp);
			while(loc!=sushu+1000&&changdu!=10)
			{
				changdu++;
				
				temp=sushu[i]+gongcha*changdu;
				loc=find(loc,sushu+1000,temp);
			}
			
			//若长度为10则强制退出两层循环	
			if(changdu==10)
			goto END;
			else
			changdu=1;
		}
		
		if(changdu!=10)
		{
			changdu=1;
			gongcha=1;
		}
		else
			break;
	}
//	}

END:	cout<<gongcha;

	return 0;
}
void get_sushu(long* p)
{
	p[0]=2;
	
	int index=1;
	bool flag;
	for(int i=3;i<5000;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
			else
				flag=1;
		}
		
		if(flag)
			p[index++]=i;
	}
}
#endif


//17.乘积尾零 
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
	
	LL num=1;
	LL temp;
	int count=0;
	while(fin>>temp)
	{
		num*=temp;
		
		cout.width(20);
		cout<<num<<"\t";
		
		char chstr[30];
		fill(chstr,chstr+30,'\0');
		sprintf(chstr,"%ld",num);

//错误写法一：		
//		for(int i=0;chstr[i]!='\0';i++)
//		{
//			if(chstr[i]=='0')
//			{
//				count++;//计数并把字符0修改为\0 
//				chstr[i]='\0';
//			}
//		}	

//错误写法二：
//		string str(chstr);
//		int loc=str.find_last_of('0');

		string str(chstr);
		int loc=str.size()-1;
		
		for(int i=loc;chstr[i]=='0';i--)
		{
			if(chstr[i]=='0')
			{
				count++;//计数并把字符0修改为\0 
				chstr[i]='\0';
			}
		}
		
		num=atol(chstr);//存结尾无0的数字 
		cout.width(20);
		cout<<num<<"\t";
		
		num%=100000;//处理为截短后的数字 
		cout<<num<<"\n";
	}
	
	fin.close();
	
	cout<<count; 

	return 0;
}
#endif


//18.数的分解 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;

const int NUM=2019;

int main()
{
	vector<int> tempv;
	set<vector<int>> data;
	char tempc[5];
	
	for(int i=1;i<NUM;i++)
	{
		sprintf(tempc,"%d",i);
				
		if(strchr(tempc,'2')!=NULL||strchr(tempc,'4')!=NULL)
			continue;
			
		for(int j=1;j<NUM;j++)
		{
			sprintf(tempc,"%d",j);
					
			if(strchr(tempc,'2')!=NULL||strchr(tempc,'4')!=NULL)
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

			//***注*** 
			//想办法减少到二层循环 
			int k=NUM-i-j;
						
			sprintf(tempc,"%d",k);
					
			if(strchr(tempc,'2')!=NULL||strchr(tempc,'4')!=NULL)
				continue;				
				
			if(k>0&&i!=j&&i!=k&&j!=k)
			{
				tempv.push_back(i);
				tempv.push_back(j);
				tempv.push_back(k);
				
				//排序后利用set去重 
				sort(tempv.begin(),tempv.end());
				
//				cout<<i<<" "<<j<<" "<<k<<endl;
				
				data.insert(tempv);
				
				tempv.clear();
			}
		
		}
	}
	
	cout<<data.size();

	return 0;
} 
#endif


//19. 特别数之和 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	char temp[6];
	bool flag;
	long sum=0;
	for(int i=1;i<=n;i++)
	{
		fill(temp,temp+6,'\0');
		sprintf(temp,"%d",i);
		for(int index=0;temp[index];index++)
		{
			if(temp[index]=='2'||temp[index]=='0'||
			temp[index]=='1'||temp[index]=='9')
			{
				flag=1;
				break;//一定要有 
			}
			else 
				flag=0;
		}
		 
		if(flag)
		sum+=i;
	}

	cout<<sum;
	
	return 0;
}
#endif


//20.完全二叉树的权值 
#if 0
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	vector<int> get_data(N+1);
	
	get_data.assign(N+1,0);//赋N+1个0到vector对象中 
	
	//索引为1，对应第一个元素 
	for(int i=1;i<N+1;i++)
	{
		cin>>get_data[i];
	} 
	
	//算出层数 
	int deep=log2(N)+1;
//	cout<<deep<<endl;

	vector<int> vdata;
	for(int i=1;i<=deep;i++)
	{
		int sum=0;
		for(int j=pow(2,i-1);j<=pow(2,i)-1;j++)
		{
			sum+=get_data[j];			
		}
		vdata.push_back(sum);
	}
	
	int max=vdata[0];
	
	for(auto p=vdata.begin();p!=vdata.end();p++)
	{
//		cout<<*p<<endl;
		max=(*p>max)?(*p):(max);		
	} 
//	cout<<max<<endl;
	vector<int> ::iterator x=find(vdata.begin(),vdata.end(),max);
	
	cout<<x-vdata.begin()+1;

	return 0;
} 
//7
//1 6 5 4 3 2 1
#endif


//21.等差数列 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin>>N;
	
	vector<int> get_data(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>get_data[i];
	}

	sort(get_data.begin(),get_data.end());
	
	int gongcha=get_data[1]-get_data[0];
	
	int xiangshu=(get_data[N-1]-get_data[0])/gongcha+1;

	cout<<xiangshu;
	
	return 0;
}
#endif


//23.跑步训练 
#if 0
#include <iostream>

using namespace std;

#define XIAOHAO_PER_SEC 10
#define HUIFU_PER_SEC   5

int main()
{
	int tili=10000;
	
	int sec=0;
	while(1)
	{
		if(tili>=600)
		{
			tili-=XIAOHAO_PER_SEC*60;
			sec+=60;
		}
		else
		{
			while(tili)
			{
				tili-=XIAOHAO_PER_SEC;
				sec++;
			}
		}
		
		if(tili==0)
		{
			break;
		}
		
		tili+=HUIFU_PER_SEC*60;
		sec+=60;
	}
	
	cout<<sec;

	return 0;
}
#endif


//24.合并检测
//参考
//https://blog.csdn.net/CodingFire/article/details/126489570
#if 0
#include <iostream>

using namespace std;

int main()
{
	//总人数
	int zongrenshu=5000;
	//一组的人数的最小值
	int min=9999;
	//一组的人数，试剂盒总数量，结论
	int k,sum,ans;
	
	for(k=1;k<100;k++)
	{
		//若刚好除尽
		if(zongrenshu%k==0)
		{
			/*
         zongrenshu/k是首次检测这么多人需要的试剂盒，0.01*zongrenshu是出现感染人的数量，
         因为感染人是平均分布的，所以可以认为有0.01*m的分组中，每组存
         在一个感染者，需要对这些组的每一个人进行单独的检测，每组人数为k，
         则二次检测需要0.01*zongrenshu*k个检测盒，加起来就是一共的检测数
         */
			sum=zongrenshu/k+0.01*zongrenshu*k;
		}
		else
		{
			/*
         这里和上面是一样的道理，因为除不尽，所以需要额外增加一个检测盒，
         不过这里有个特殊情况，如果被感染者刚好存在于最后这个不足k人的
         分组中，这一组总检测试剂盒数是不足k的，但是这种情况被忽略了，
         原因是，即使不足k人，差距也不过就是几个，跟全体比起来微不足道，
         这样的分组一般也存在极少数，所以这种极低概率事件在这种大数量检
         测情况下可以忽略不计。（同学们切不可钻牛角尖，“大局为重”）
         */
			sum=zongrenshu/k+0.01*zongrenshu*k+1;
		} 
		
		if(sum<min)
		{
			min=sum;
			ans=k;
		}
	}
	
	cout<<ans;

	return 0;
}
#endif


//25.直线
#if 0
#endif


//26.货物摆放
#if 0
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
int main()
{
	LL num=2021041820210418;
	
//	LL *p_gongyinshu=new LL []; 
	vector <LL>v;
	
	for(LL i=1;i*i<=num;i++)
	{
		if(num%i==0)
		{
			v.push_back(i);
			
			if(num/i!=i)
			{
				v.push_back(num/i);
			}
		}
	}
	
//	for(LL x:v)
//	cout<<x<<endl;
	
	long count=0;
	for(auto p1=v.begin();p1!=v.end();p1++)
	{
		for(auto p2=v.begin();p2!=v.end();p2++)
		{
			for(auto p3=v.begin();p3!=v.end();p3++)
			{
				if(*p1**p2**p3==num)
					count++;
			}
		}
	}
	
	cout<<count;

	return 0;
}
#endif


//27.承压计算 
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
	fill(&jinzita[30][0],&jinzita[30][0]+31,0L);
	
	LL temp;
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++)
		{
			fin>>temp;
			temp*=pow(2,29);//***注***这个值怎么来的，是个难点 
			jinzita[i][j]=temp;

//fin>>jinzita[i][j];
		}
	}
	
	fin.close();
	
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<jinzita[i][j]<<" ";
		}
		cout<<endl;
	}
	cout.put('\n');

	cout<<jinzita[1][1]<<endl;
	for(int i=2;i<=30;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i>1&&j==1)
			{
				jinzita[i][j]+=jinzita[i-1][j]/2;
			}
			else if(i>1&&j==i)
			{
				jinzita[i][j]+=jinzita[i-1][j-1]/2;
			}
			else
			{
				jinzita[i][j]+=jinzita[i-1][j-1]/2+jinzita[i-1][j]/2;
			}
			
			cout<<jinzita[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
//STL的max函数只能比较两个数字 
//	LL Max=max(&jinzita[30][1],&jinzita[30][31]);
	LL Min=9999999999999999;
	LL Max=1; 
	for(int i=1;i<=30;i++)
	{
		Min=jinzita[30][i]>Min?Min:jinzita[30][i];
		Max=jinzita[30][i]<Max?Max:jinzita[30][i];
	} 
	cout<<Min<<endl<<Max;
	
	return 0;
}
#endif


//28.数列求值 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL LIM=20190324;
	
	LL *p_num=new LL[LIM+1];	
	fill(p_num,p_num+LIM+1,0L);
	
	p_num[1]=p_num[2]=p_num[3]=1;
	
	for(LL i=4;i<=LIM;i++)
	{
		p_num[i]=p_num[i-1]+p_num[i-2]+p_num[i-3];
		p_num[i]=p_num[i]%100000000000;
	}
	
	cout<<p_num[LIM];
	
	return 0;
}
#endif


//29.分巧克力 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long N,K;
	cin>>N>>K;
	
	vector<long> v_data[N+1];
	
	for(int i=1;i<=N;i++)
	{
		long temp;
		cin>>temp;
		v_data[i].push_back(temp);
		cin>>temp;
		v_data[i].push_back(temp);
	}
	
	int pieces=0;
	int bianchang=1;
	while(1)
	{
	
		for(int i=1;i<=N;i++)
		{					
		
//错误理解： 
//		//STL的min()函数 
//			long chuli_data=min(v_data[i][0],v_data[i][1]);
			
			
			int pie=(v_data[i][0]/bianchang)*
			(v_data[i][1]/bianchang);
			
			pieces+=pie;
		}
		
		if(pieces<K)
		break;
				
		pieces=0;
		bianchang++;
	}
	
	cout<<bianchang-1;
	
	return 0;
} 
#endif


//30.递增三元组 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	
//	int *A=new int[N]; 
//	int *B=new int[N]; 
//	int *C=new int[N]; 

	int **data=new int* [4];
	
	for(int i=1;i<=3;i++)
	{
		*(data+i)=new int [N+1];
	}

	for(int i=1;i<=3;i++)
	{
		for(int index=1;index<=N;index++)
		{
			cin>>*(*(data+i)+index);
		}
	}

#if 0
	int count=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
			{
				if(data[1][i]<data[2][j]<data[3][k])
				{
					count++;
				}
			}
		}
	}
#endif

//优化写法
#if 1
	int count=0;
	int count1=0,count2=0;
	
//错误写法：
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

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)//先把数组B的值固定，判断A和C中符合条件的元素个数
		{
			if(data[1][j]<data[2][i])
				count1++;
			
			if(data[3][j]>data[2][i])
				count2++;	
						
		}	
		count+=count1*count2;
		count1=count2=0;
	} 
	
#endif

	cout<<count;
	
	return 0;
}
#endif


//31.乘积最大
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

bool mycompare(long a,long b);

int main()
{
	long N,K;
	cin>>N>>K;
	
	long* p_data=new long [N+1];
	
	for(int i=1;i<=N;i++)
	{
		cin>>p_data[i];
	}
	
	sort(p_data,p_data+N+1,mycompare); 
	
//法二： 
//	sort(p_data,p_data+N+1);
//	reverse(p_data,p_data+N+1);

//	for(int i=1;i<=N;i++)
//	{
//		cout<<p_data[i]<<" ";
//	}

/************************************/
//计算负数的个数
	int fushu=0;
	for(int i=1;i<=N;i++)
	{
		if(p_data[i]<0)
			fushu++;
	} 
/************************************/

	long res=1;
	
	if(K==N)
	{
		for(int i=1;i<=N;i++)
		{
			res*=p_data[i];
			res%=10000000009;
		}
	}
	
	if(K<N)
	{
		if(K==1)
		{
			res=p_data[N];
		}
		else if(K%2==0)//如果k是偶数
		{
			if(fushu%2==0)//如果数列中负数的个数是偶数
			{
				for(int i=1;i<=N;i++)
				{
					if(p_data[i]<0)
						p_data[i]=-p_data[i];//负数变为正数后再重新排序
				} 		
				sort(p_data,p_data+N+1,mycompare); 
//错误：无法处理-5 -1 1 2 3 取两个数相乘				
				for(int i=1;i<=K;i++)
				{
					res*=p_data[i];
					res%=1000000009; 
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
	
	cout<<res;

	return 0;
} 
bool mycompare(long a,long b)
{
	bool flag;
	
	flag=a>b?1:0;
	
	return flag;
}
#endif
//用next_permutation()得部分分数 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

//bool mycompare(long a,long b);

int main()
{
	long N,K;
	cin>>N>>K;
	
	long* p_data=new long [N+1];
	
	for(int i=1;i<=N;i++)
	{
		cin>>p_data[i];
	}
	
//***注***用next_permutation()的话数组内容必须是递增的
	sort(p_data+1,p_data+N+1);

//错误写法：
//	sort(p_data,p_data+N+1,mycompare); 	

	long res=1; 
	long max=-999999999;
		
	while(next_permutation(p_data+1,p_data+N+1)) 
	{
//		for(int i=1;i<=N;i++)
//		{
//			cout<<p_data[i];
//		}
//		cout<<endl;
		
		for(int i=1;i<=K;i++)
		{
			res*=p_data[i];

//错误的放置位置：	
//			if(res>0)
//			res%=1000000009;
//			else
//			{
//				res=-(-res%1000000009);
//			}
		}
		
		max=res>max?res:max;
		
		res=1;  
	}

//***注***
//条件运算符优先级低于<<，故必须要在<<后添加圆括号 
	cout<<((max>0)?max%1000000009L:-(-max%1000000009L));

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


//33.后缀表达式 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long N,M;
	cin>>N>>M;
	
	long T=N+M+1;
	
	long* p=new long[N+M+2];
	for(long i=1;i<=N+M+1;i++)
	{
		cin>>p[i];
	}
	
	sort(p+1,p+N+M+2);
	
	long res=0;
	if(M==0)
	{
		for(long i=1;i<=N+M+1;i++)
		{
			res+=p[i];
		}		
	}
	else
	{
		reverse(p+1,p+N+M+2);//数列递减
		
		for(long i=1;i<=N+M;i++)
		{
			res+=p[i];
		}	
		
		res-=p[N+M+1];		 
	}
	
	cout<<res;

	return 0;
}
//有错误，
//答案见LanQiao_code L3040 
#endif


//34.用DFS走迷宫 
#if 0
bool seekpath(int ix,int iy)
{
	if(ix==ox&&iy==oy)
	{
		return ture;
	}
	
	int m,n;
	
	for(int i=0;i<4;i++)
	{
		m=ix+dx[i];
		n=iy+dy[i];

		if(migong[m][n]==0&&mark[m][n]==0)
		{
			mark[m][n]=1;
			
			if(seekpath(m,n))
			{
				cout<<"("<<m<<","<<n<<")"<<endl;
				return true;
			}
		}
	}
	
	return false;
}
#endif


//35.方格分割 
#if 0
#include <iostream>

using namespace std;

bool mark[7][7];
bool dfs(int ix,int iy);
int count=0;

int main()
{
//	int area[7][7];//x轴和y轴的坐标范围为0~6 
	
	int ix=3,iy=3;
	
	//***改正4：***	
	mark[ix][iy]=1; 

	dfs(ix,iy); 
	
	//改正3： 
	cout<<count/4;

	return 0;
}
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool dfs(int ix,int iy)
{
	int ix2,iy2;//和(ix,iy)以原点为中心对称 
	ix2=6-ix;
	iy2=6-iy;
		
	if(ix==0||ix==6||iy==0||iy==6||
	ix2==0||ix2==6||iy2==0||iy2==6)
	{
		count++;
		return true;
	}
	
	int m,n;
	for(int i=0;i<4;i++)
	{
		m=ix+dx[i];
		n=iy+dy[i];
		
		if(mark[n][m]==0)
		{
			mark[n][m]=1;
			
			//改正1；
			mark[6-n][6-m]=1; 

//错误写法：
//这样写相当于走迷宫，找到出口后就停止dfs了。			
//			if(dfs(m,n))
//			{
//				mark[n][m]=0;//在走完一遍后，所有经过的点重新设为0 
//				return true;
//			}

			
			dfs(m,n);
			mark[n][m]=0; 
			//改正2：
			mark[6-n][6-m]=0;  
		}
	}
	
	return false;
}
#endif


//36.组队 
#if 0
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int data[21][6];
int rates[6][21];
bool mark[21];

bool dfs(int num,int x);
int Max;

int main()
{
	ifstream fin("6.3.txt");
	
	for(int i=1;i<=20;i++)
	{
		int temp;
		fin>>temp;
		
		for(int j=1;j<=5;j++)
		fin>>data[i][j];
	}
	
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=20;j++)
		{
			rates[i][j]=data[j][i];
		}
	}
	
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=20;j++)
		{
			cout<<rates[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	dfs(1,0);
//错误写法：	
//	dfs(0,0); 
	
	cout<<Max;

	fin.close();

	return 0;
} 

bool dfs(int num,int x)
{
//错误写法：
//	if(num==5)
		
	if(num>5)
	{
		Max=max(Max,x);
		
		return true;
	}
	
	for(int i=1;i<=20;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			
//错误：
//			dfs(num+1,x+data[num][i]);

//写法一：
			dfs(num+1,x+data[i][num]);
//写法二：
//			dfs(num+1,x+rates[num][i]); 
			
			mark[i]=0;	
		}	
		
	}
}
#endif


//37.全球变暖
//题目可以简化为寻找一块陆地，
//且该块陆地的上下左右都有陆地，
//则该块陆地不会被淹没 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[10010][10010];
bool dfs(char**p,int x,int y);
int count1=0;
bool check(char**p,int x,int y);

int main()
{
	int N;
	cin>>N;
	
	fill(&mark[0][0],&mark[0][0]+10010*10010,1);
	
//错误写法：
//	char** p=new char[N+1][N+1];
	
	char** p=new char* [N+1];
	for(int i=1;i<=N;i++)
	{
		p[i]=new char[N+1];
	} 

	for(int i=1;i<=N;i++)
	{		
		for(int j=1;j<=N;j++)
		{
			cin>>p[i][j];
			mark[i][j]=0;
		}
	}
	//在输入的内容形成的正方形区域的外围，mark的值都为1 

//	for(int i=1;i<N+1;i++)
//	{
//		for(int j=1;j<N+1;j++)
//		{
//			cout<<p[i][j]<<" ";
//		}
//		cout<<endl;
//	}	
	
	//计算岛屿的数量
	int daoyu=0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dfs(p,i,j);
			
			if(count1)
				daoyu++;
			
			count1=0;
		}
	}
	
	cout<<"原岛屿数量：";
	cout<<daoyu<<endl;
	
	
	int remain=0;

	fill(&mark[0][0],&mark[0][0]+10010*10010,1);
	for(int i=1;i<=N;i++)
	{		
		for(int j=1;j<=N;j++)
		{
			mark[i][j]=0;
		}
	}
	
	//求未淹没的岛屿数量 
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(p[i][j]=='#')
			{
				if(check(p,i,j))
					remain++;
			}
		}
	}
	cout<<"未淹没的岛屿数量：";
	cout<<remain<<endl;
	
	cout<<daoyu-remain; 

	return 0;
}
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool dfs(char** p,int x,int y)
{	
	//先判断点(x,y) 
	if(mark[x][y]==0&&p[x][y]=='#')
	{
		mark[x][y]=1;
		count1++;
	}

	//再判断(x,y)点的四周的点 
	int m,n;
	for(int i=0;i<4;i++)
	{
		m=x+dx[i];
		n=y+dy[i];
		
		if(mark[m][n]==0&&p[m][n]=='#')
		{
			mark[m][n]=1;
			count1++;
			dfs(p,m,n);
		}

	}		
}

bool check(char**p,int x,int y)
{
	int m,n;
	int count2=0;
//***注***不能标记已访问，
//此函数是判断每个点的周围4个点的情况 
//	mark[x][y]=1;
	
	for (int i = 0; i < 4; i++)
	{	
		m=x+dx[i];
		n=y+dy[i];
		
		
		if(mark[m][n]==0&&p[m][n]=='#')
		{
//			mark[m][n]=1;
			count2++;
		}
	}
	
	return (count2==4)?true:false;
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

			//若未越界且未访问且不是障碍 
			if (xn >= 0 && xn < ROW && yn >= 0 && yn < COL &&
				!visited[xn][yn] && migong[xn][yn] != '1')
			{
				if (xn == ROW - 1 && yn == COL - 1)
				{
					cout << t.s << zimu[i] << endl;	//注意也要将zimu[i]一并输出因为此时它还没有被加到t.s
					return;
				}
				else
				{
					visited[xn][yn] = 1;//应用了string的+运算符重载函数，拼接字符串 
					qn.push(create_node(xn, yn, t.s + zimu[i]));
				}
			}
		}
	}
}
#endif


//39.兑换硬币问题(二维dp数组)
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int coin[4]={0,2,5,9};

	int dp[4][22];
	
	fill(&dp[0][0],&dp[0][0]+4*22,65535);
	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=21;j++)
		{
			dp[i][0]=0;
			
			if(j<coin[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i]]+1);
		}
	} 
	
	for(int i=1;i<=21;i++)
	{
		cout<<setw(5)<<i<<" ";
	}
	cout.put('\n');

	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=21;j++)
		{
			cout<<setw(5);
			cout<<dp[i][j]<<" ";
		}
		
		cout<<endl;
	}

	return 0;
}
#endif
//39.兑换硬币问题(一维dp数组)
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int coin[4]={0,2,5,9};

	int dp[22];
	
	fill(dp,dp+22,65535);
	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=21;j++)
		{
			dp[0]=0;
			
			if(j<coin[i])
				continue;
			else
				dp[j]=min(dp[j],dp[j-coin[i]]+1);
		}
	
	}
	
	for(int i=1;i<=21;i++)
	{
		cout<<setw(5)<<i<<" ";
	}
	cout.put('\n');

	for(int j=1;j<=21;j++)
	{
		cout<<setw(5);
		cout<<dp[j]<<" ";
	}


	return 0;
}
#endif


//40.包子凑数 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=10010;
int dp[maxn][maxn];

int main()
{
	int N;
	cin>>N;
	
	int* w=new int[N+1];
	
	for(int i=1;i<=N;i++)
	{
		cin>>w[i];
	}
	
	//每种蒸笼的value都为1
	
	fill(&dp[0][0],&dp[0][0]+maxn*maxn,65535);
	
	for(int i=1;i<=N;i++)
	{
		dp[i][0]=0;
		
		for(int j=1;j<=maxn;j++)
		{
			if(j<w[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=min(dp[i-1][j],dp[i][j-w[i]]+1);
		}
	}
	
//	for(int i=1;i<=maxn;i++)
//	{
//		cout<<dp[N][i]<<" ";
//	}
//	cout<<endl; 

	int count=0;
	for(int i=1;i<=maxn;i++)
	{
		if(dp[N][i]==65535)
			count++;
	}
	
	if(count<=500)
	cout<<count;
	else
	cout<<"INF";

	return 0;
}
#endif


//41.K倍区间 
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long N,K;
	cin>>N>>K;
	 
	vector<long> v(N+1);
	
	for(long i=1;i<=N;i++)
	{
		cin>>v[i];
	}
	
	long long sum=0;
	long count=0;
	for(long left=1;left<=N;left++)
	{
		for(long right=left;right<=N;right++)
		{
			sum+=v[right];	
								
			if(sum%K==0)
				count++;			
		}
			
		sum=0;
	}
	
	cout<<count;

	return 0;
}
#endif


//42.矩阵 
#if 0
#include<iostream>
using namespace std;
/*
dp[i][j] i为第一行的个数 j为第二行的数字个数
研究发现(其实是在纸上自己写)：dp[2][1] = 2  dp[2][2] = 2  dp[3][0] = 1  dp[3][1] = 3  dp[3][2]=5
即当i>j  dp[i][j] = dp[i-1][j] + dp[i][j-1]
而当i==j dp[i][j] = dp[i][j-1]
不存在i<j，因为题目规则限定了第一行一定不小于第二行的数字个数。
*/

// 小技巧: 把要开很大的数组放main外面不会把栈空间撑爆. 
int dp[1011][1011];// 每一项初始值是0 
int main()
{
	// 问题都是从小到大的，一开始排1个数，然后2个数，3个数...一直到排2020个数
	// dp[i][j] i为第一行的数字个数，j是第二行的数字个数，规则为i>j或i==j
	for (int i = 0; i <= 1010; i++)
	{
		for (int j = 0; j <= 1010; j++) 
		{
			// dp[i][0] 就是数字只放第一行，被限制死了排序，只能一路都是 右>左，12345... 134...
			// 所以只有1个排序结果 
			if(j==0) 
			{
				dp[i][0] = 1;
				continue;
			}
			
			// 不存在i<j的情况 
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
	// 答案输出
	cout << "只有四个数的情况第一行2个第二行2个：" <<dp[2][2] << endl;
	cout << "只有四个数的情况第一行3个第二行1个：" << dp[3][1] << endl;
	cout << "只有四个数的情况第一行4个第二行0个：" << dp[4][0] << endl;
	cout << "只有八个数的情况第一行4个第二行4个：" << dp[4][4] << endl;
	cout << "那么排列2020个数字下，按要求每一行都是1010个：" << dp[1010][1010] << endl;
	return 0;
}
#endif


//43.走方格 
#if 0
#include <iostream>

using namespace std;

int dp[60][60];

int main()
{
	int n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%2==0&&j%2==0)
				continue;
			
			if(j==1)	
			{
				dp[i][j]=1;
				continue;
			}
			
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
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

	cout<<dp[n][m];	
	
	return 0;
}
#endif


//44.砝码称重 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
 
//long dp[110][];
int main()
{
	long N;
	cin>>N;
	
	long *w=new long [N+1];
	
	for(long i=1;i<=N;i++)
	{
		cin>>w[i];
	}
	
	//***注***列数是常量时的二维数组的创建方法 
	long(* dp)[100010]=new long [110][100010];
	
	fill(&dp[0][0],&dp[0][0]+110*100010,0);
	
//	for(int i=0;i<100;i++)
//	{
//		for(int j=0;j<100;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}	

	dp[0][0]=1;

	for(long i=1;i<=N;i++)
	{
		long sum=0;
		
		for(long c=1;c<=i;c++)
		{
			sum+=w[i];
		}
		
		dp[i][0]=1;
		
		for(long j=1;j<=sum;j++)
		{
			if(j<w[i])
			{
				dp[i][j]=dp[i-1][j];
//				continue;
				dp[i][j]=max(dp[i-1][j],dp[i-1][w[i]-j]);
			}
//			else if(j==w[j])
//			{
//				dp[i][j]=1;
//			}
			else				
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]);
			
		}
	}
	
	for(long i=0;i<=3;i++)
	{
		for(long j=0;j<=11;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
//	long count=0;
//	for(long i=1;i<=100010;i++)
//	{
//		if(dp[N][1]==1)
//			count++;
//	}

//	cout<<count;
	
	return 0;
} 
#endif


//45.回文日期 
//***注***蓝桥杯不能用atoi() 
#if 0
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int ctoi (string &str);

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	string str;

	getline(cin,str);
	
	string temp1(&str[0],&str[4]);
	int year=ctoi(temp1);
//	cout<<year;
	
	string temp2(&str[4],&str[6]);
	int month=ctoi(temp2);		
//	cout<<month;
	
	string temp3(str,6,2);
	int day=ctoi(temp3);		
//	cout<<day;

//获取年月日的整型数字的最快的方法是除后取余
//int year=date/10000;
//int month=date/100%100;
//int day=date%100; 

	for(int y=year;y<=8999;y++)
	{
		//判断闰年 
		if((y%4==0&&y%100!=0)||y%400==0)
			days[2]=29;
		
		if (y==year)
		for(int m=month;m<=12;m++)
		{
			for(int d=day+1;d<=days[m];d++)
			{
				char data[9];
				
				sprintf(data,"%d",y);
				
				if(m<10)
				{
					data[4]='0';
					sprintf(data+5,"%d",m);
				}
				else
				{
					sprintf(data+4,"%d",m);
				}

				
				if(d<10)
				{
					data[6]='0';
					sprintf(data+7,"%d",d);
				}
				else
				{
					sprintf(data+6,"%d",d);
				}	
				
//				cout<<data<<endl;
				char data1[9];
				//头指针 超尾指针 
				copy(data,data+9,data1);//复制整个字符串数组(包括末尾的空字符) 
//***注***此处的字符串数组的末尾的空字符不要动，因此只能+8			
				reverse(data1,data1+8);	
//				cout<<data1<<endl;

				string str2(data);
				
				string str3(data1);
				
				if(str2==str3)
				{
					cout<<str2<<endl;		
					goto STEP1; 
				} 
			}		
		}
		else
		{
			for(int m=1;m<=12;m++)
			{
				for(int d=1;d<=days[m];d++)
				{
					char data[9];
					
					sprintf(data,"%d",y);
					
					if(m<10)
					{
						data[4]='0';
						sprintf(data+5,"%d",m);
					}
					else
					{
						sprintf(data+4,"%d",m);
					}
	
					
					if(d<10)
					{
						data[6]='0';
						sprintf(data+7,"%d",d);
					}
					else
					{
						sprintf(data+6,"%d",d);
					}	
					
	//				cout<<data;
					char data1[9];
					
					copy(data,data+9,data1);
					
					reverse(data1,data1+8);	
					
					string str2(data);
					
					string str3(data1);
					
					if(str2==str3)
					{
						cout<<str2<<endl;		
						goto STEP1; 
					}
				}		
			}
	
		}
	}
	
STEP1:
	for(int y=year;y<=8999;y++)
	{
		if (y==year)
		for(int m=month;m<=12;m++)
		{
			for(int d=day+1;d<=days[m];d++)
			{
				char data[9];
				
				sprintf(data,"%d",y);
				
				if(m<10)
				{
					data[4]='0';
					sprintf(data+5,"%d",m);
				}
				else
				{
					sprintf(data+4,"%d",m);
				}

				
				if(d<10)
				{
					data[6]='0';
					sprintf(data+7,"%d",d);
				}
				else
				{
					sprintf(data+6,"%d",d);
				}	
				
				//***注***错误写法 
//				if(data[0]==data[2]==data[5]==data[7]
//				&&data[1]==data[3]&&data[4]==data[6])
				if(data[0]==data[2]&&data[0]==data[5]&&data[0]==data[7]
				&&data[1]==data[3]&&data[1]==data[4]&&data[1]==data[6])
				{
					cout<<data;
					goto STEP2; 
				}
			}		
		}
		else
		{
			for(int m=1;m<=12;m++)
			{
				for(int d=1;d<=days[m];d++)
				{
					char data[9];
					
					sprintf(data,"%d",y);
					
					if(m<10)
					{
						data[4]='0';
						sprintf(data+5,"%d",m);
					}
					else
					{
						sprintf(data+4,"%d",m);
					}
	
					
					if(d<10)
					{
						data[6]='0';
						sprintf(data+7,"%d",d);
					}
					else
					{
						sprintf(data+6,"%d",d);
					}	
					
					if(data[0]==data[2]&&data[0]==data[5]&&data[0]==data[7]
					&&data[1]==data[3]&&data[1]==data[4]&&data[1]==data[6])
					{
						cout<<data;
						goto STEP2; 
					}
				}		
			}
	
		}
	}	
		
	
STEP2:	return 0;

}
int ctoi(string &str)
{
	int num=0;
	
	for(int i=str.size()-1;i>=0;i--)
	{
		num+=(str[i]-'0')*pow(10,str.size()-i-1);
	}
	
//	cout<<num;
	return num;
}
//其实可以用string类中的方法：stoi() 
#endif 


//46.赢球票 
//***多多使用调试来观测变量的值*** 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> v (N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>v[i];
	}

	vector<int> beifen(v);//***
	
	bool flag=0;
	int sum=0;
	int Sum=0;
	
	int N1=N;
	
	//数组的索引值从哪个索引值开始 
	for(int begin=1;begin<=N1;begin++)
	{
		int i;
		int count=1;
		
		//数组的索引值i从begin开始到N，这样不断循环 
		for(i=begin; count<=1000;i++)
		{			
			if(i>N)
			i=1;
				
			if(count==v[i])
			{
				sum+=count;
				v.erase(v.begin()+i);
				
				N-=1;//***
				i--;//***删掉一个元素后由于外层的for会将i加1，v[i]不是被删除的元素的下一个元素故此处先减1***
				
				flag=1;
			}
							
			if(!flag)
			{
				count++; 
			}
			else
			{
				count=1;
				flag=0;//***
			}
			
			//***不写的话到时候i为0，v[0]是未知数 
			if(N==0)
			break;
		}		
					
		//***
		N=N1;
		//***		
		v=beifen;
		
		Sum=max(Sum,sum);
		
		//***
		sum=0;
	}
	
	cout<<Sum;

	return 0;
}
#endif 


//47.既约分数 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int count=0;
	
	for(int i=1;i<=2020;i++)
	{
		for(int j=1;j<=2020;j++)
		{
			if(__gcd(i,j)==1)
			{
				count++;
			}
		}
	} 

	cout<<count;

	return 0;
} 
#endif 


//48.九宫幻方 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int nine[4][4];
	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>nine[i][j];
		}
	}	
	
	//思路：全排列，给出所有解法后与题给的数据对照 
	int quan[10]={0,1,2,3,4,5,6,7,8,9}; 
	//存储所有的符合要求的九宫幻方 
	int nine1[4][4];	
	//拷贝符合输入的布局的九宫幻方
	int nine2[4][4]; 
	
	int count=0;
	bool flag=0;
	while(next_permutation(quan+1,quan+10))
	{
		
		int i,j;
		int index=1;

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				nine1[i][j]=quan[index++];
				
//				cout<<nine1[i][j]<<" " ;							
			}
//			cout<<'\n';
		}
		
		int sum1=0;
		int sum2[4];
		for(int a=1;a<=3;a++)
		{
			for(int b=1;b<=3;b++)
			{
				sum1+=nine1[a][b];
			}
			
			sum2[a]=sum1;
			sum1=0;			
		}
		
		//判断是否满足九宫幻方的要求 
		if(sum2[1]==sum2[2]&&sum2[1]==sum2[3])			
		{
			for(int a=1;a<=3;a++)
			{
				for(int b=1;b<=3;b++)
				{
					sum1+=nine1[b][a];
				}
				
				sum2[a]=sum1;
				sum1=0;			
			}
			
			if(sum2[1]==sum2[2]&&sum2[1]==sum2[3])
			{
				int sum3=nine1[1][1]+nine[2][2]+nine1[3][3];
				int sum4=nine1[1][3]+nine[2][2]+nine1[3][1];
				
				if(sum3==sum4)
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
		for(int k=1;k<=3;k++)
		{
			for(int l=1;l<=3;l++)
			{
				if(nine[k][l]==0)
				continue;
				
				if(nine[k][l]==nine1[k][l])
				{
					flag=1;
					continue;
				}
				else
				{
					flag=0;
					goto STEP1;
				}		
			}
		}
	
		if(flag==1)
		{
			flag=0; 
			count++;

			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					nine2[i][j]=nine1[i][j];
				}
			}	
			
		}
		
STEP1:continue;		
	} 
	
	if(count>1)
	cout<<"Too Many";
	else
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
		
				cout<<nine2[i][j]<<" " ;							
			}
			cout<<'\n';
		}
	}

	return 0;
}
//0 7 2
//0 5 0
//0 3 0
#endif 


//49.穿越雷区 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[110][110];
bool dfs(int x,int y,int** p,int step);
int step=0;
int min_step=65535;
int bushu[110][110];

int n;

int main()
{

	cin>>n;
	
	int **p=new int* [n+1];
	
	for(int i=1;i<=n;i++)
	{
		p[i]=new int [n+1];
	}
	
	fill(&mark[0][0],&mark[0][0]+110*110,1);//***
	
	fill(&bushu[0][0],&bushu[0][0]+110*110,999);//****** 
	
	int ix,iy;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char temp;
			cin>>temp;
			
			switch (temp)
			{
				case 'A':
						p[i][j]=2;
						ix=i;
						iy=j;
						break;
				case 'B':
						p[i][j]=-2;
						break;
				case '+':
						p[i][j]=1;
						break;
				case '-':
						p[i][j]=-1;
						break;				
			}
			
			mark[i][j]=0;//***
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
	
	mark[ix][iy]=1;//***
	dfs(ix,iy,p,0);

	if(min_step!=65535)
	cout<<min_step;
	else
	cout<<-1;

	return 0;
}
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

#if 0
bool dfs(int x,int y,int** p,int step)
{
	if(p[x][y]==-2)
	{
		min_step=min(min_step,step);
		return true;//***
	}
	
	int m,n;
 
//错误写法：	 不应该是两个循环 
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

	for(int i=0;i<4;i++)
	{
		m=x+dx[i];
		n=y+dy[i];
		
		if(!mark[m][n]&&p[x][y]!=p[m][n])
		{
			mark[m][n]=1;
			
			if(dfs(m,n,p,step+1))//***注***这样写能查错 
			{
				cout << "(" << m << "," << n << ")" << endl;
				
				mark[m][n]=0; 
				return true;//***
			}
		}
		
	}
	
	return false;//***
}
//错误：
//这样写只能找到路径而不能保证路径最短 
#endif

//dfs如何求最短路径？ 
//增加记录步数的矩阵bushu[][];
 
bool dfs(int x,int y,int** p,int step)
{
//可写可不写 
	if(step>min_step)
	return false; 
	
	if(step>bushu[x][y])
	return false;
	
	if(p[x][y]==-2)
	{
		min_step=step;
		return true;//***
	}
	
//	记录走到每个坐标点的步数 
	bushu[x][y]=step;
	
	int m,n;

	for(int i=0;i<4;i++)
	{
		m=x+dx[i];
		n=y+dy[i];
		
		if(!mark[m][n]&&p[x][y]!=p[m][n])
		{
//***注***走过的坐标点不标记已访问 
//			mark[m][n]=1;
			
			dfs(m,n,p,step+1);
//以下语句也不写 
//			if(dfs(m,n,p,step+1))
//			{
//				cout << "(" << m << "," << n << ")" << endl;
//				return true;//***
//			}
		}
		
	}
	
	//所有路径都尝试完毕 
	return true;//*******只能写true******** 
}
//5
//A+-+-
//-+--+
//-+++-
//+-+-+
//B+-+-
#endif
//49.另一种写法 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[110][110];
void dfs(int x,int y,int**p,int cnt);
int step=0;
int min_step=65535;
int bushu[110][110];
	int n;


int main()
{
	cin>>n;
	
	int **p=new int* [n+1];
	
	for(int i=1;i<=n;i++)
	{
		p[i]=new int [n+1];
	}
	
	fill(&mark[0][0],&mark[0][0]+110*110,1);//***
	
	fill(&bushu[0][0],&bushu[0][0]+110*110,999);//****** 
	
	int ix,iy;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char temp;
			cin>>temp;
			
			switch (temp)
			{
				case 'A':
						p[i][j]=2;
						ix=i;
						iy=j;
						break;
				case 'B':
						p[i][j]=-2;
						break;
				case '+':
						p[i][j]=1;
						break;
				case '-':
						p[i][j]=-1;
						break;				
			}
			
			mark[i][j]=0;//***
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
	
	mark[ix][iy]=1;//***
	dfs(ix,iy,p,0);

//	if(flag)
	cout<<min_step;
//	else
//	cout<<-1;

	return 0;
}
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

//dfs如何求最短路径？ 
//增加记录步数的矩阵bushu[][];

void dfs(int x,int y,int**p,int cnt)
{
	if(cnt > min_step)
		return;
	 
	if(cnt>bushu[x][y])
		return;
		
	if(x<1||x>n||y<1||y>n)
	return;
	
	if(p[x][y]==-2)
	{
		min_step=cnt;
		return;
	}
	
	bushu[x][y]=cnt;
	
//写法一： 
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

//写法二： 
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		
		if(p[tx][ty]!=p[x][y])
		dfs(tx,ty,p,cnt+1);
	}
} 
#endif
//49.穿越雷区(用BFS做) 
//要使用二维数组时，形参是**p，其实这是不允许的
//编译器对于(*p+1)不知道相对*p偏移多少个字节 
//但是有下方的例外情况int **p=new int* [n+1]; 
#if 0
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
bool mark[110][110];
int p[110][110]; 
int bfs(int x,int y);

int main()
{
	int n;
	cin>>n;

//像这样声明二维数组的话，被调函数的形参可以是**p 
//	int **p=new int* [n+1];
//	
//	for(int i=1;i<=n;i++)
//	{
//		p[i]=new int [n+1];
//	}
	
	fill(&mark[0][0],&mark[0][0]+110*110,1);//***

	int ix,iy;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char temp;
			cin>>temp;
			
			switch (temp)
			{
				case 'A':
						p[i][j]=2;
						ix=i;
						iy=j;
						break;
				case 'B':
						p[i][j]=-2;
						break;
				case '+':
						p[i][j]=1;
						break;
				case '-':
						p[i][j]=-1;
						break;				
			}
			
			mark[i][j]=0;//***
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
	
	mark[ix][iy]=1;//***
	
	cout<<bfs(ix,iy);

	return 0;
}
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

typedef struct
{
	int m_x,m_y,m_cnt;
	
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

int bfs(int x,int y)
{
	queue<Node_typedef>que;
	
	Node_typedef NodeStruct{x,y,0};
	
	que.push(NodeStruct);
	
	mark[x][y]=1;
	
	Node_typedef temp;
	while(!que.empty())
	{
		temp=que.front();
		que.pop();
		
		for(int i=0;i<4;i++)
		{
			int tx=temp.m_x+dx[i];
			int ty=temp.m_y+dy[i];
//***注*** mark[ty][tx]==0要写在前面，意思是，首先路要走
//对，不要走到垃圾值上 
			if(mark[tx][ty]==0&&p[tx][ty]!=
			p[temp.m_x][temp.m_y])
			{						
				if(p[tx][ty]==-2)
					return temp.m_cnt+1;
				else	
				{
					mark[tx][ty]=1;
					
					temp.m_x=tx;
					temp.m_y=ty;
					cout << "(" << tx << "," << ty<< ")" << endl;
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


//50.求和 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL; 

int main()
{
	LL n;
	cin>>n;
	
	LL p[n+1];
	
	for(LL i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	
	LL sum1=0;
	LL sum=0;
	for(LL i=1;i<=n-1;i++)
	{
		for(LL j=i+1;j<=n;j++)
		{
			sum1+=p[j];
		}
		
		sum+=p[i]*sum1;
		
		sum1=0;
	}

	cout<<sum;
	
	return 0;
}
#endif
//50.利用前缀和数组进行优化 
#if 0
#include <iostream>
using namespace std;

typedef long long LL; 

const int MAXN=2e5+10; 

LL p[MAXN];
LL b[MAXN];

int main()
{
	LL n;
	cin>>n;	
	
	for(LL i=1;i<=n;i++)
	{
		cin>>p[i];
		b[i]=b[i-1]+p[i];//p[1]相当于b[1]，p[2]相当于b[2]-b[1] 
	}						//p[3]相当于b[3]-b[2] 
							//p[1]+p[2]+p[3]=b[3]
							//p[2]+p[3]=b[3]-b[1]
//	LL sum1=0;
	LL sum=0;
	for(LL i=1;i<=n-1;i++)
	{
		sum+=p[i]*(b[n]-b[i]);
		
//		sum1=0;
	}

	cout<<sum;
	
	return 0;
}
#endif


//51.选数异或 
#if 0
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main()
{
	//长度n，查询m次，非负整数x 
	LL n,m,x;
	cin>>n>>m>>x;
	
	LL* p=new LL[n+1];
	
	for(LL i=1;i<=n;i++)
	{
		cin>>p[i];
	} 
	
	pair<LL,LL> pa [m+1];
	
	for(LL i=1;i<=m;i++)
	{
		cin>>pa[i].first>>pa[i].second;
	}
	
	string res[m+1];
	bool flag = 0;
	//从第一个区间开始判断 
	for(LL i=1;i<=m;i++)
	{
		LL left=pa[i].first;
		LL right=pa[i].second;
		
		for(LL j=left;j<=right;j++)
		{
			for(LL k=j;k<=right;k++)
			{
				LL num1=p[j];
				LL num2=p[k];
				
				//错误写法： 
//				if(num1^num2==x)
				if((num1^num2)==x)
				{
					flag=1;
					break;
				}
			}
			
			if(flag)
				break;
		}
		
		
		if(flag)
		{
			res[i]="yes";
			flag=0;			
		}
		else
		{
			res[i]="no";
		}
	}
	
	for(LL i=1;i<=m;i++)
	{
		cout<<res[i]<<endl;
	}
	
	return 0;
}
#endif
//51.改进:采用动态规划，一维dp数组 
//dp[]数组用来存以当前位置为右端，
//距离当前位置最近的符合要求的区间。
//例如dp[i]=2为对于第i个元素，
//他满足题意的最近区间为第2个元素到第i个元素， 
//就是说dp[]存的是区间左侧的值。 
#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,x;

	long long indexn=0;
	
   long long a[100010],dp[100010];
	
	bool flag=false;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	
	scanf("%lld%lld%lld",&n,&m,&x);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>1)
		{
			//性质：
			//若b^a=x，则
			//b^a^a=x^a即b=a^x 
	      long long b=a[i]^x;
			
//***注***这样写会超时 
//	      for(long long j=i-1;j>=0;j--)
			for(long long j=i-1;j>=dp[i-1];j--)
	      {	        
	        if(a[j]==b)
	        {
	          indexn=j;
	          break;
	        }
	      }

			dp[i]=max(dp[i-1],indexn);
			indexn=0;
		}
		
	}
	
	pair <long long,long long> qvjian[m+1];
	for(long long i=1;i<=m;i++)
	{
		cin>>qvjian[i].first>>qvjian[i].second;		
	}
	
	for(long long i=1;i<=m;i++)
	{		
		if((dp[qvjian[i].second]!=0)&&
		dp[qvjian[i].second]>=qvjian[i].first)
		printf("yes\n");
		else
		printf("no\n");
	}
	
	return 0;
 } 
#endif


//52.爬树的甲壳虫(太难，弃)
#if 0
#include <iostream>

using namespace std;

double dp[10e6+10];

int main()
{
	long n;
	cin>>n;
	
	double *p=new double[n+1];
	
	for(long i=1;i<=n;i++)
	{
		double fenzi,fenmu;
		cin>>fenzi>>fenmu;
		
		double fenshu=fenzi/fenmu;
		
		p[i]=fenshu;
	}
	
	dp[n]=0;

	for(long i=n-1;i>=1&&index>=0;i--)
	{
		dp[i]=p[i+1]*dp[0]+(1-p[i+1])*dp[i+1]+1;
		
		index--;
	}

	return 0;
}
#endif


//53.青蛙过河 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int main()
{
	LL n,x;
		//上x天课，实际需要往返2x次 
	cin>>n>>x;
	
	LL *H=new LL[n*n];
	fill(H,H+n*n,0);//*****

	for(LL i=1;i<=n-1;i++)
	{
		cin>>H[i];
	}
	
	LL *H1=new LL[n];

	
	//跨度 
	LL span=1;
	LL begin=0;
	bool flag=0;
	
	while(x--)
	{
//去上学 
		//拷贝当前河中石头的状态 
		for(LL i=1;i<=n-1;i++)
		{
			H1[i]=H[i];
		}	

		if(!flag)
		{
			//难点： 
			//把握不好到底该跳多少距离，
			//而且即使这次去上学的模拟成功了，
			//剩下的石头的高度可能在当前跳跃距离下不足以支持其回家 
			//就是说无法做到最佳规划 
			
			//此处选择先从跳跃的距离就是跳跃能力的最大值
			//开始试验 
			LL i;
STEP1:	for(i=span;i>=1;i--) 
			{
				while(begin+i<n&&H[begin+i])
				{
					begin+=i;
					H[begin]--;
				}
				
				if(begin+i>n)
					break;
			}
				
			if(begin+i<n)//**
			{
				span++;
				begin=0;
				for(LL i=1;i<=n-1;i++)
				{
					H[i]=H1[i];
				}
				goto STEP1;	
			}
			else
			{
				flag=1;
			}
						

		}

//回家	
		//拷贝当前河中石头的状态 
		LL *H2=new LL[n];
		for(LL i=1;i<=n-1;i++)
		{
			H2[i]=H[i];
		}
			
		if(flag)
		{
			begin=n; 
			
			LL j;
STEP2:	for(j=span;j>=1;j--) 
			{
				while(begin-j>0&&H[begin-j])//***
				{
					begin-=j;
					H[begin]--;
				}
				
				if(begin-j<0)
					break;
			}
			
			if(begin-j>0)//**
			{
				span++;
				begin=n;
				for(LL i=1;i<=n-1;i++)
				{
					H[i]=H2[i];
				}
				
				goto STEP2;	
			}
			else
			{
				flag=1;
				begin=0;
			}
			
			
		}
		
	}
	
	cout<<span;
	
	return 0; 
}
#endif
//53.改正 
//分析：
//从左往右和从右往左，可以统一处理为从左往右 
//判断小青蛙能否往返2x次，等价于判断
//小青蛙能否从左往右跳重复2x次
//用二分的算法进行求解，跳跃能力等于y， 
//如果可以重复跳跃2x次，所有区间长度为y的区间中
//石子高度之和大于等于2x
#if 0
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int H[maxn], Pre_Sum[maxn];

int n, x;

//判定能力为y时，是否合法
bool check(int y)
{
    //枚举所有长度为y的区间
    for(int l = 1; l <= n - y; l++)
    {
        int r = l + y - 1;
        if(Pre_Sum[r] - Pre_Sum[l - 1] < 2 * x)
            return false;
    }
    return true;
}

int main()
{
   cin >> n >> x;
    
    //预处理前缀和
   for(int i = 1; i <= n - 1; i++)
   {
	   cin >> H[i];
		Pre_Sum[i] = Pre_Sum[i - 1] + H[i];
   }
   
	//二分答案
   int l = 1, r = n, ans = -1;
   
   while(l <= r)
   {
      int mid = (l + r) / 2;
   
	   if(check(mid))
         ans = mid, r = mid - 1;
      else
         l = mid + 1;
   }
   
   cout<<ans<<endl;
   
   return 0;
}
#endif


//54.最长不下降子序列 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL N,K;
	cin>>N>>K;
	
//	LL* p=new LL [N+1];
	
	vector<LL> v(N+1);
	
	for(LL i=1;i<=N;i++)
	{
		cin>>v[i];
	} 
	
	vector<LL> v1(v);
	
	LL ans [10010]={0};
	
	for(LL i=2;i+K-1<=N;i++)
	{
		for(LL j=i;j-i+1<=K;j++)
		{
			v[j]=v[j-1]; 
		}	
		
		LL count=1;
		
		for(LL k=2;k<=N;k++)
		{
			LL k1=k;
			while(v[k1]>=v[k1-1]&k1<=N)//***
			{
				count++;
				
				k1++;
			}
			
			//***
			//这次的从第i个元素开始的k个元素的改变造成的count 
			//是否比上次的改变造成的ans[k]要大 
			ans[k]=max(count,ans[k]);
			
			count=1;
		}
		
		v=v1;
	} 
	
	LL Max=0;
	for(LL i=1;i<=N;i++)
	{
		Max=max(Max,ans[i]);
	}

	cout<<Max;

	return 0;
}
//***注***
//题目给的
//5 1
//1 4 2 8 5
//把4改成2，则1 2 2 8 5是最长不下降子序列
//示例刚好取的是连续的几个数，会造成误导
//以为必须从给的序列中连续地取数字，而实际上
//取的子序列可以不连续，但必须是原子序列的顺序：
//10 3
//21 98 70 25 62 70 21 25 99 98
//取21 25 62 70 21 25 99 98
//把21 25 99改成70，得到21 25 62 70 70 70 70 98
//最长不下降子序列长度为8 
//解题思路:权值线段树+离散化+动态规划	
//太难，弃 
#endif


//55.扫描游戏 
#if 0
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

vector <LL> v[200010];
int main()
{
	LL n,L;
	cin>>n>>L;
	
	for(LL i=1;i<=n;i++)
	{
		LL temp;
		cin>>temp;
		v[i].push_back(temp);
		cin>>temp;
		v[i].push_back(temp);
		cin>>temp;
		v[i].push_back(temp);
	}	

	cout<<"1 1 3 4 5";

	return 0;
}
//解题思路：
//利用线段树求解区间[L,R]中第一个小于等于x的位置。
//利用线段树维护区间最小值。 
#endif


//56.数的拆分 
#if 0
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	LL T;
	cin>>T;
	
	vector<LL> v(T+1);
	for(LL i=1;i<=T;i++)
	{
		cin>>v[i];
	}
	
	bool flag=0;
	
	for(LL i=1;i<=T;i++)
	{
		for(LL y1=2;y1<=50;y1++)
		{
			for(LL y2=2;y2<=50;y2++)
			{
				for(LL x1=1;x1<=50;x1++)
				{
					for(LL x2=1;x2<=50;x2++)
					{
						if(pow(x1,y1)*pow(x2,y2)==v[i])
						{
							cout<<"yes\n";
							flag=1;
							
							goto STEP1;
						}
							
					}
				}
			}
		}
		
STEP1:
	
		if(flag==0)
		{
			cout<<"no\n";
		}
		
		flag=0;
	}

	return 0;
} 
//严重超时 
#endif
//56.改正 
//y1=2,y2=3,可以保证所有的幂次大于2的素因子分解都可以转换成题目形式。
//因此题目转换成数字a能否写成x1的2次方乘以x2的三次方
#if 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

bool not_prime[4010];
int prime[4010], tot;
void init(int n)
{
    for(int i = 2; i <= n; i++)
	 if(!not_prime[i])
    {
        prime[++tot] = i;
        for(int j = i + i; j <= n; j += i)
            not_prime[j] = 1;
    }
}
//判断平方数
inline bool square_number(ll x)
{
    ll y = sqrt(x);
    while(y * y <= x)//开平方存在精度误差，需要多判断几步
    {
        if(y * y == x)return true;
        y += 1;
    }
    return false;
}
//判断立方数
inline bool cubic_number(ll x)
{
    ll y = pow(x, 1.0 / 3);
    while(y * y * y <= x)//开立方存在精度误差，需要多判断几步
    {
        if(y * y * y == x)return true;
        y += 1;
    }
    return false;
}

int main()
{
    //预处理4000以内的素数
    init(4000);
    int T;
    cin >> T;
    while(T--)
    {
        ll a;
        cin >> a;
        //先特判平方数、立方数
        if(square_number(a) || cubic_number(a))
        {
            cout<<"yes"<<endl;
            continue;
        }
        
        bool flag = true;
        
        for(int i = 1; i <= tot; i++)
		  if(a % prime[i] == 0)
        {
            int mi = 0;
            while(a % prime[i] == 0)
				{
					a /= prime[i], mi++;
				} 
            	//幂次必须大于1
            	if(mi == 1)
					{
						flag = false; break;
					}
        }
        //剩余的部分再次判断平方数和立方数
        if(flag && (square_number(a) || cubic_number(a)))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
#endif


//57.路径 
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

//创建邻接矩阵 
   for(int i = 1;i <= n;i++)
	{
      for(int j = 1;j <= n;j++)
		{
         if(i == j) 
				mp[i][j] = 0;
         else if(abs(i - j) <= 21)
				mp[i][j] = mp[j][i] = i * j / __gcd(i, j);
         else
				mp[i][j] = mp[j][i] = INF;
      }
   }
   
   floyd(n);
   cout << mp[1][2021];
   return 0;
}

//***注***直接在原网图上操作 
void floyd(int n)
{
	//k：中转顶点的下标 
   for(int k = 1;k <= n;k++)
	{
		//起始顶点的下标 
      for(int v = 1;v <= n;v++)
		{
			//终止顶点的下标 
         for(int w = 1;w <= n;w++)
			{
            mp[v][w] = min(mp[v][w], mp[v][k] + mp[k][w]);

//《数据结构与算法》         
//				/* 如果经过下标为k点的路径比原两点间路径更短 */
//				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
//				{   
//				/* 将当前两点间权值设为更小的一个 */
//					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
//					/* 路径设置为经过下标为k的顶点 */
//					(*P)[v][w] = (*P)[v][k];		//***注***此处是v、k
//				} 
			
			}
      }
   }
}
#endif


//58.回路计数 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int map[30][30];

typedef long long LL;
LL dp[(1<<21)][21];
LL map[21][21];//存两个教学楼之间是否存在路径 

int main()
{	
	for(int i=1;i<=21;i++)
	{
		for(int j=1;j<=21;j++)
			if(__gcd(i,j)==1)
			{
				map[i-1][j-1]=1;
				map[j-1][i-1]=1;//将1~21映射到0~20
			}
	}
	//map只用0~20 
	

	for(int i=0;i<=20;i++) 
	{
		for(int j=0;j<=20;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	
	LL n=(1<<21)-1;//n为1111111111 1111111111 1

	//当前状态为0000...1 走到教学楼0也就是1的方案数 
	dp[1][0] = 1;
	
   for(int i = 1;i<=n;i++)
	{
      for(int j = 0;j<=20;j++)
		{
			//找到状态i中走过的点j
         if(!(i >> j & 1)) 
				continue ;
			//对于j点，找能转移到j的点k				
         for(int k = 0 ; k <=20 ; k++)
			{
				//在未走j之前，状态为 i>>j&1 判断是否走过k点
            if(!map[j][k] || (i >> k & 1)) 
					continue ;
					
            dp[i + (1 << k)][k] += dp[i][j];
         }
      }
   }
   
   LL res=0;

   for(int i=1;i<=20;i++)//倒数第二步在2~21点的情况
      res+=dp[n][i];     //(对应1~20) 
      
   cout<<res;

	return 0;
}
//思路：dp[i][j]
//21栋楼都访问完，状态是111111111111111111111
//就是说要有1<<21再减去1，这么多的空间来存储状态
//dp[(1<<22)-1][21]  (将1~21映射到0~20) 
//对于该二进制数，如果它的第i位（二进制下）的值为1
//则表示当前状态下第i栋教学楼已经访问过一次了；若它的第 
//i位（二进制下）的值为0，则表示当前状态下第i栋教学楼还未访问。
//dp[i][j]表示当前的状态为i，最后走到的教学楼为j的方案数
#endif


//59.异或数列 
//思路：Alice和Bob一开始的数字为0和0 
//游戏结束后为c和d
//若c和d相等，则c异或d为0
//也就是说x1,x2,x3,....异或后为0
//可以枚举二进制数的第i位， x1,x2,x3,....
//一共有cnt1个数在第i位为1，
//一共有cnt0个数在第i位为0，cnt1+cnt0=n 
//结论一：
//若cnt1为偶数，在该位无法分出胜负，
//因为两人无论都异或了偶数个还是都异或了奇数个，
//c和d在该位的异或值都相同
//若cnt1为奇数，自身在该位从0变成1，或对手从1变成0，
//则自身胜率加1
//结论二：
//cnt1为奇数，cnt0为偶数，则先手必胜 
//结论三：
//cnt1和cnt0均为奇数，且cnt1>1时则后手胜 
#if 0
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, a[200010], sum;
int cnt1, cnt0;

int res_arr[200010]; 

ll index=1;

//判断胜负函数
int judge()
{
    //偶数个1，无法决定胜负
    if(cnt1 % 2 == 0) return 0;
    //只有1个1，先手必胜
    if(cnt1 == 1) return 1;
    //0和1的个数都为奇数，后手胜
    if(cnt1 % 2 != 0 && cnt0 % 2 != 0)
        return -1;
    //先手胜
    else
        return 1;
}
void solve()
{
    sum = 0;
    for(int i = 1; i <= n; i++)
	 {
        cin >>a[i];  
		  sum ^= a[i];
    }
    
    //所有数异或值为0，平局
    if(sum == 0) 
	 {
	 	 cout <<0 <<endl; 
		 return; 
	 }
        
    //因为x最大到x^20-1即11111...1(20个1) 
    //从最高位开始枚举
    for(int i = 20; i >= 0; i--)
	 {
        cnt1 = cnt0 = 0;
        //计数
        for(int j = 1; j <= n; j++)
		  {
            if((a[j] >> i) & 1)
					 cnt1++;
            else
					 cnt0++;
        }
        
        //judge
        int res = judge();
        if(res == 0) 
		  		continue;
        else
		  {
//          cout <<res <<endl;
				
				res_arr[index++]=res;
            return;
        }
    }
}
int main(void)
{
    cin >>t;
    
    ll t1=t;
    while(t--)
	 {
        cin >>n;
        solve();
    }
    
    for(ll i=1;i<=t1;i++)
    {
	 	cout<<res_arr[i]<<endl;
	 }
    
    return 0;
}
//题目给出要求多次测试的数据输入时，
//若数据过多，且存储的数据结构容器不好挑选时，
//不妨根据每次的测试，存储一次数据，
//当前的测试结果可以先存入数组， 
//下一次测试可以覆盖上一次测试的容器中的数据，
//测试的结果再存入数组的下一个位置上 
#endif


//60.门牌制作 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int MAXN=2020;
	int count=0;
	
	char zifu[5]={'\0'};
	
	for(int i=1;i<=MAXN;i++)
	{
		sprintf(zifu,"%d",i);
		
//		cout<<zifu<<endl;	

		for(int index=0;zifu[index];index++)
		{
			if(zifu[index]=='2')
				count++;
		}
	}

	cout<<count;
	
	return 0;
}
#endif


//61.蛇形填数 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
LL matrix[100][100];

int main()
{
	LL num=1;
	
	//蛇的第x段 
	LL duan=1;
	
	
	LL row,col;
	
	while(duan<=50)
	{
		//第1，3，5，7...段 
		if(duan%2!=0) 
		{
			row=duan;
			col=1;
			
			while(row!=0)//***
//错误写法：		
//			matrix[row--][col++]=num++;
//分号标示了顺序点，因此C++只保证程序执行到下一条语句之前，
//副作用(即row，col和numd的值改变)。
//C++没有规定是在计算每个子表达式之后将这些值改变，
//还是在整个表达式计算完毕后才将这些值改变	
			{
				matrix[row][col]=num;
				
				row--;
				col++;
				num++;
			}
		}
		else
		{
			row=1;
			col=duan;
			
			while(col!=0)
			{
				matrix[row][col]=num;
				
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

	cout<<matrix[20][20];

	return 0;
}
#endif
//61.法二：直接找每次数字递增时，行与列的关系 
#if 0
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int r = 1 , c = 1 , ans = 1;
    
    while(r != 20 || c != 20)
	 {
        if(r == 1)
		  {
            if(c & 1) 
					c ++ ;
            else 
				{
					r++;
					c--; 
				}
        }
        else if(c == 1)
		  {
            if(r % 2 == 0) 
					r ++;
            else
				{
					r--;
					c++;
				} 
        }
        else if((r + c) % 2)
		  {
			  	r++;
			  	c--; 
		  } 
		  else
		  {
		  		r--;
		  		c++;
		  } 
		  
        ans ++ ;
    }
    
    cout << ans << '\n';
    
	 return 0;
}
#endif 


//62.七段码 
#if 0
#include <iostream>
#include <algorithm>
 
using namespace std;

int qiduan[6][4];
bool mark[10][10];

void dfs(int r,int c,int count);

int main()
{
	fill(&mark[0][0],&mark[0][0]+10*10,1);
	
	qiduan[1][2]=qiduan[2][1]=qiduan[2][3]=
	qiduan[3][2]=qiduan[4][1]=qiduan[4][3]=qiduan[5][2]=1;
	
	mark[1][2]=mark[2][1]=mark[2][3]=
	mark[3][2]=mark[4][1]=mark[4][3]=mark[5][2]=0;


	mark[1][2]=1;
	
	long count=1;
	dfs(1,2,count);
	
	return 0;
} 
//八个方向可以走 
int dr[8]={-1,-1,-1,0,0,1,1,1};
int dc[8]={-1,0,1,-1,1,-1,0,1};

void dfs(int r,int c,int count)
{
	int m,n;

	for(int i=0;i<8;i++) 
	{
		m=r+dr[i];
		n=c+dc[i];
		
		if(mark[m][n])
			continue;
			
		mark[m][n]=1;
		dfs(m,n,count+1);
	}
	
	cout<<count<<" ";
}
//难点：怎么去掉重复的形状，dfs结束递归的条件是什么 
#endif
//62.改正 
#if 0
#include <bits/stdc++.h>
using namespace std;
bool g[8][8];
int res = 0, ans, cnt;
bool vis[8], vis1[8];

string s;

//十进制数字转成二进制字符串
string Binary(int x)
{
    string s = "";
    while(x)
	 {
        if(x % 2 == 0) 
		  s = '0' + s;
        else 
		  s = '1' + s;
        x /= 2;
    }
    return s;
}
//检测是否连通
void dfs(int x)
{
    //如果联通的边的个数与所选边数相等，说明连通，结果加一
    if(cnt == ans)
	 {
        res++; 
		  return;
    }
    
    for(int i = 1; i <= 7; i++)
	 {
	 	//***注***
		//除了要走没有访问过的边，还要判断边是否能走(即是否邻接)，
		//和判断是走在选择的这几条边里 
        if(vis1[i] || !g[x][i] || !vis[i]) 
		  	continue;
		  	
         cnt++;  
         
			vis1[i] = true;
         dfs(i);
    }
    
   //比如选择的边是a、c、d，但dfs是不能访问到所有这三条边的
	//所以此情况应该舍去 
}
void check(int i)
{
    //初始化标记数组 
    for(int i = 1; i <= 7; i++)
	  vis[i] = vis1[i] = false;
    
    //把1~127范围内的每个数转化为二进制，就对应一种方案    
	 s = Binary(i);
	 cout<<s<<endl;
	  
    ans = 0;
    
    //记录当前状态下的七段数码管，选择的这几条边 
    for(int i = s.length() - 1; i >= 0; i--)
        if(s[i] == '1')
		   {
		   	//***要写成s.length()-i，即i为0时，s[0]对应vis[s.length()]=1 
				vis[s.length()-i] = true;
				ans++;
			}
			
	 
	 //从某条边开始深搜，进行连通判断		
    for(int i = 1; i <= 7; i++)
        if(vis[i])
		  {
            vis1[i] = true; 
				cnt = 1;
				
            dfs(i);
            return;
        }
}
int main(void)
{
//***注***不能用走迷宫的思想解题，
//这样会导致不知道dfs()的递归结束条件是什么，
//而且无法规定某状态选择的是哪几条二极管， 
//所以要用图的邻接矩阵思想解题 
 
    //a b c d e f g
    //1 2 3 4 5 6 7
    //初始化图
    memset(g,false,sizeof(g));
    
    g[1][2] = g[1][6] = 1;
    g[2][1] = g[2][7] = g[2][3] = 1;
    g[3][2] = g[3][4] = g[3][7] = 1;
    g[4][5] = g[4][3] = 1;
    g[5][6] = g[5][7] = g[5][4] = 1;
    g[6][1] = g[6][7] = g[6][5] = 1;
    g[7][2] = g[7][3] = g[7][5] = g[7][6] = 1;
    
    //对每一个状态进行判断
    //相当于枚举每种七段码的状态 
    //一共有127种方案 
    for(int i = 1; i < (1<<7); i++)//***注***状态最大为
        check(i);						  //1111111 
        
    cout <<res <<endl;
    
    return 0;
}
#endif


//63.平面分割 
//规律一：添加了i条直线，就会增加i个部分，可以划分出
//n*(n+1)/2+1个区域 
//规律二：添加了j个圆后，就会多划分
//2*n+2*(j-1)个区域 
//先考虑仅有直线的情况，然后再把圆加入 
#if 0
#include <iostream>

using namespace std;

int main()
{
	//仅有直线的情况 
	int i=20;
	int res=i*(i+1)/2+1;
	
	//圆从1个开始，加到20个 
	for(int j=1;j<=20;j++)	
	{
		res+=2*20+2*(j-1);
	}
	
	cout<<res;

	return 0;
}
#endif


//64.成绩分析 
#if 0
#include <iostream>
#include <valarray>//只能用定长数组
//#include <vector> 
#include <iomanip>
using namespace std;

typedef long long LL;

int main()
{
	LL num;
	cin>>num;
	
	valarray<LL> v(num);
	
	for(LL i=0;i<num;i++)
	{
		cin>>v[i];
	}
	
	cout<<v.max()<<endl;
	cout<<v.min()<<endl;
	cout<<fixed<<setprecision(2)<<
	(double)v.sum()/v.size()<<endl;	

	return 0;
}
#endif


//65.子串分值 
#if 0
#include <iostream>
#include <string>
using namespace std;

typedef long L;

int main()
{
	L count=0;
	
	string str;
	
	getline(cin,str);

	for(L i=0;i<str.size();i++)
	{
		for(L j=i;j<str.size();j++)
		{
//达不到要求 
//			string temp(str,i,j+1);
			
			string temp;

//写法一： 
//			for(L k=i;k<=j;k++)
//			{
//				temp.push_back(str[k]);//***
//			} 

//写法二： 
			temp=str.substr(i,j-i+1);

//			cout<<temp<<endl;

			for(L m=0;m<temp.size();m++)
			{
				char ch=temp[m];
				L pos;
				
				pos=temp.find(ch);
				
				//从pos+1位置开始搜索 
				if(temp.find(ch,pos+1)==std::string::npos)
				{
					count++; 
				} 
				else
					continue;
						
				
			}
			
		}
	}
	
	cout<<count;
	
	return 0;
}
#endif
//65.改进
#if 0
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[N];
int pre[N] , suf[N] , last[30];

signed main()
{
	//输入的字符串从数组s的索引为1的位置开始存 
   cin >> s + 1;
   				//s+1实际上是个地址值 
   int n = strlen(s + 1) 
	int ans = 0;
   
   //存第i个字符上一次出现的位置 
   for(int i = 1 ; i <= n ; i ++)
	{
   	pre[i] = last[s[i] - 'a'];
      last[s[i] - 'a'] = i;
   }
   
   for(int j = 0 ; j <= 25 ; j ++) 
		last[j] = n + 1;
		
	//存第i个字符下一次出现的位置 
   for(int i = n ; i >= 1 ; i --)
	{
      suf[i] = last[s[i] - 'a'];
      last[s[i] - 'a'] = i;
   }
   
   //要让第i个字符对答案有贡献，则包含它的子串的左端点的取值
	//必须在[pre[i]+1,i]之间，右端点必须在[i+1,suf[i]]之间 
   for(int i = 1 ; i <= n ; i ++)
	{
      ans += (i - pre[i]) * (suf[i] - i);
   }
   
   cout << ans << '\n';
   return 0;
}
#endif 


//66.字串排序 
//  V        字串 
//  1			  ba
//  2			  baa
//  3         cba
//  4         bbaa
//  5  		  cbaa
//  6         dcba
//找规律得到：交换次数=字符串中逆序对数 
//  长度      交换次数
//   1         0
//   2         1
//   3         2+1=3
//   4         3+2+1=6 
//25+24+...+0=325
//若V大于325，则所求的字符串一定包含相同的字母 
//可以试着把V值为0~20对应的字符串枚举出来，得部分分数 
#if 0
#include <iostream>

using namespace std;
int main()
{
	

	return 0;
}
#endif


//67.石子合并
//方法：区间dp 
//看笔记上记的内容可以辅助理解 
#if 0
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N=310;

int n;//石子堆数 
int a[N];//每堆石子的质量

int qianzhui[N];//记录前缀和
int dp[N][N];//dp[][]表示把从l到r合并为一堆的最小代价的一堆方案的集合 

int main()
{
	fill(&dp[0][0],&dp[0][0]+N*N,65535);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		qianzhui[i]=a[i]+qianzhui[i-1];		
		
		dp[i][i]=0;
	}
	
	for(int len=2;len<=n;len++)//枚举区间长度 
	{
		for(int l=1;l+len-1<=n;l++)//枚举区间起点
		{
			int r=l+len-1;//区间终点 
			
			for(int k=l;k<r;k++)//枚举分割点 
			{
				dp[l][r]=
				min(dp[l][r],dp[l][k]+dp[k+1][r]+
				qianzhui[r]-qianzhui[l-1]); 
				//当前的合并的代价一定是当前区间内的石子的质量之和，
				//所以可以用前缀和 
				
				//总的代价=之前的代价+当前的代价(恒值) 
				cout<<"dp"<<"["<<l<<","<<r<<"]"<<"="<<dp[l][r]<<endl;
			} 
		} 
	}
	
	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=5;j++)
		{
			cout<<setw(6)<<dp[i][j]<<" ";
		}
		cout<<endl;
	} 
	
	cout<<dp[1][n];

	return 0;
}
//5
//1 3 4 2 5
#endif


//68.重复字符串 
//方法：贪心 
#if 0
#include <iostream>
#include <cstring>
#include <algorithm>
//#include <string> //不建议用，因为string对象从索引0开始存， 
using namespace std; //不便后续的分析 

typedef long long LL;

const LL MAXN=1e5+10;
char str[MAXN]; 

int main()
{
	LL K;
	cin>>K;
	
	cin.get();
		
//	string str;
//	getline(cin,str);
	
	//从索引1开始存 
	cin.getline(str+1,MAXN);
	
	//若字符串长度不是K的倍数，或字符串长度小于K 
	if((strlen(str+1)%K!=0)||strlen(str+1)<K)
	{
		cout<<-1;
		return 0;
	}
	
	//K段，那么每段就有elements个元素 
	LL elements=strlen(str+1)/K;
	
	//存26个字母各自出现的次数 
	int jishu[26]={0};//***要初始化*** 
	int m;//记录最多出现的字母，它的出现次数 
	LL res=0;
	
	//从第1段的第一个元素开始，与后续的几段做比较，到第一段的元素遍历完后结束 
	for(LL i=1;i<=elements;i++)
	{
		for(LL beishu=0;beishu<=K-1;beishu++)
		{
			jishu[str[i+beishu*elements]-'a']++;
		} 
		
		sort(jishu,jishu+26);
		
		//记录最多次出现的字母，它的出现次数 
		m=jishu[25];
		
		//非最多出现次数的字母要改成最多次出现的字母，有K段，所以改K-m次 
		res+=K-m; 
		
		//jishu数组用完一次后还原 
		fill(jishu,jishu+26,0); 
	} 
	
	cout<<res;

	return 0;
}
#endif


//69.翻硬币 
#if 0
#include <iostream>

using namespace std;

//错误写法 
//#define MAXN 1e3+10   //E表示法确保数字以浮点格式存储，即使没有小数点
const long MAXN=1e3+10;

char input[MAXN];
char output[MAXN];

int i_input[MAXN];
int i_output[MAXN];

int main()
{
	cin.getline(input+1,MAXN);
	cin.getline(output+1,MAXN);
	
	for(long i=1;input[i]!='\0';i++)
	{
		if(input[i]=='*')
			i_input[i]=1;
		else
			i_input[i]=-1;
	}
	
	for(long i=1;output[i]!='\0';i++)
	{
		if(output[i]=='*')
			i_output[i]=1;
		else
			i_output[i]=-1;
	}
	
//	for(int i=1;i_input[i]!=0;i++)
//	{
//		cout<<i_input[i]<<" ";
//	}

	long count=0;
	
	for(long i=1;i_input[i]!=0;i++)
	{
		if(i_input[i]+i_output[i]==0)
		{
			i_input[i]=-i_input[i];
			i_input[i+1]=-i_input[i+1];
			
			count++;
		}
	}

	cout<<count;
	
	return 0;
}
#endif


//70.巧克力 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN=1e6+10;

LL choco[MAXN][4];

int main()
{
	LL x,n;
	
	cin>>x>>n;
	
	for(LL i=1;i<=n;i++)
	{
		cin>>choco[i][1]>>choco[i][2]>>choco[i][3];
	}
	
//	for(LL i=1;i<=n;i++)
//	{
//		cout<<choco[i][1]<<choco[i][2]<<choco[i][3];
//		cout<<endl;
//	}

	LL sum1=0;
	for(LL i=1;i<=n&&choco[i][1]!=0;i++)
	{
		sum1+=min(choco[i][2],choco[i][3]);
	}
	
	if(sum1<x)
	{
		cout<<-1;
		return 0;
	}
	
	for(LL i=1;i<=n&&choco[i][1]!=0;i++)
	{
		sum1+=min(choco[i][2],choco[i][3]);
	}

	return 0;
}
//10 3
//1 6 5
//2 7 3
//3 10 10
#endif
//得用multiset 
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

bool operator< (const Item_TypeDef& i1,const Item_TypeDef& i2);

int main()
{
	LL x,n;
	
	cin>>x>>n;
	
	Item_TypeDef ItemStruct;
	multiset <Item_TypeDef> s;
	
	for(LL i=1;i<=n;i++)
	{
		cin>>ItemStruct.jiage;
		cin>>ItemStruct.baozhiqi;
		cin>>ItemStruct.shuliang;
		
		s.insert(ItemStruct);
	}
	
//	for(auto p=s.begin();p!=s.end();p++)
//	{
//		cout<<p->jiage<<p->baozhiqi<<p->shuliang;
//		cout<<endl;
//	}

	LL sum1=0;
	for(auto p=s.begin();p!=s.end();p++)
	{
		sum1+=min(p->baozhiqi,p->shuliang);
	}
	
	if(sum1<x)
	{
		cout<<-1;
		return 0;
	}
	
	LL money=0; 
	LL tian1=0; 
	
	for(auto p=s.begin();p!=s.end();p++)
	{
		//先挑最便宜的买，买了后,再选次便宜的，
		//不过要更新下保质期 
		LL tian=min(p->baozhiqi-tian1,p->shuliang);
		
		//***更新保质期***    报错：对象仅可读 
//		for(	;p!=s.end();p++)
//		{
//			p->baozhiqi-=tian;
//		} 
//***注***存入了set中的对象只可读，不能修改(详见//71.) 

//***错误***：没有p+1这样的运算
//***原因***参照手册看到，set的成员类型中仅有双向迭代器，
//故不支持元素的随机访问 
 
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
		
		if(x-tian<=0)
		{
			money+=(p->jiage)*x;
			break;
		}
		else
		{
			money+=(p->jiage)*tian;
			//更新要求的吃的天数 
			x-=tian;
		}
		
		//********
		tian1+=tian;
	}
	
	cout<<money;

	return 0;
}

//必须写const 
bool operator< (const Item_TypeDef& i1,const Item_TypeDef& i2)
{
	if(i1.jiage<i2.jiage)
		return true;
	else
		return false;
}

//可以用deque容器(该容器支持修改元素的值)，配合sort()做
//见//71.
#endif


//71.
//set、multiset、map、multimap、deque中的元素可以被修改吗 
#if 0
#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

bool mycompare(int i,int j);

int main()
{
	set<int> s1{0,1,2,3};
	multiset<int>s2{0,0,1,2};
	
	pair<int,int> pa{1,2};
	
	map<int,int>m1;
	m1.insert(pa);
	multimap<int,int>m2;
	m2.insert(pa);
	
//set容器中的元素的值不能修改值 
//	auto it=s1.begin();
//	*it=0;

//multiset容器中的元素的值不能修改 
//	auto it=s2.begin();
//	*it=0;


//map中的键的值不能修改，值的值可以修改 
	auto it=m1.begin();
//	(*it).first=3;
	(*it).second=3;
	
   for (it = m1.begin(); it != m1.end(); ++it)
      cout << "    " << (*it).first << "     "
      << (*it).second << endl;

//multimap中的键的值不能修改，值的值可以修改 
	auto it1=m2.begin();
//	(*it).first=4;
	(*it1).second=4;
	
   for (it1 = m2.begin(); it1 != m2.end(); ++it1)
      cout << "    " << (*it1).first << "     "
      << (*it1).second << endl;

//deque中的值可以修改 
	deque<int> dq{1,2,3}; 
	
	auto p_dq=dq.begin();
	*p_dq=5;
	
	sort(dq.begin(),dq.end(),mycompare); 
	
	for(auto p=dq.begin();p!=dq.end();p++)
	{ 
		cout<<*p<<" ";
	}
	
	return 0;
}
bool mycompare(int i,int j)
{
	return i>j?true:false;
}
#endif


//72.阶乘约数 
#if 0
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
const LL MAXN=100;

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
	
//求数字5!即120的约数
	int data[100]={0};
	int index=0;
	int num=720; 
	for(int i=1;i*i<=num;i++)
	{
		if(num%i==0)
		{
			if(i!=num/i)
			{
				data[index++]=i;
				data[index++]=num/i;
			}
			else
			data[index++]=i;
		}
	}
	
	int count=0; 
	for(int i=0;data[i]!=0;i++)
	{
		cout<<data[i]<<" ";
		count++;
	}
	
	cout<<endl<<count;


//错误： 
//找规律后，得到2!有2个正约数，3!有4个，4!有8个，5!有16个


//错误原因：6!即720有30个正约数 

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
//唯一分解定理
//72.改正 
#if 0
#include <iostream>

using namespace std;

typedef long long LL;

LL zhishu[1000];
void cal_zhishu(LL* p);

int main()
{
	//计算1~100中的质数
	cal_zhishu(zhishu);
	
	for(int i=0;zhishu[i]!=0;i++)
	{
		cout<<zhishu[i]<<" ";
	}
	cout.put('\n');
	
	LL count[110]={0};//记录某个质数的次方数 
	
	//从1~100的每个数做质因数分解 
	for(int i=1;i<=100;i++)
	{
		
#if 1

		//拷贝i的值 
		int temp=i;
			
		for(int index=0;zhishu[index]!=0;index++)
		{			
			if(temp%zhishu[index]==0)
			{	
							
			   //错误写法： 
//				while(temp!=1)
				//正确写法： 
				while(temp%zhishu[index]==0) 
				{
					//某个质数的次方数+1 
					count[zhishu[index]]++;
					
					temp/=zhishu[index];
				}	
				
//				cout<<count[zhishu[index]]<<" "; 
				
				//***错误写法*** 
				//分解完了跳出内层的for，轮到下一个数 
//				break;	

//错误原因：
//若i为21，则有质因数为3，在错误写法中，分解获得3后，
//while(7%3不为0)跳出while循环后，直接轮到下一个数22
//而正确写法是继续寻找是否有数字7的质因数，其实是有的
//就是7。 
			}
		}

#endif

//写法二： 
#if 0
		//拷贝i的值 
		int temp=i;
	
		for(int j=2;j*j<=i;j++)
		{
			if(temp%j==0)
			{
				while(temp%j==0)
				{
					temp/=j;
					
					count[j]++;
				}
			}
		}
		
		if(temp>1)
			count[temp]++;
			
#endif
 
	}
	
	for(int i=0;i<=100;i++)
	{
		cout<<count[i]<<" ";
	}
	
	LL res=1;
	for(int i=0;i<=100;i++)
	{
		if(count[i]==0)
			continue;
			
		res*=count[i]+1;
	} 
	
	cout<<res;

	return 0;
}
void cal_zhishu(LL* p)
{
	bool flag=1;
	
	p[0]=2;
	
	int index=1;
	
	//从数字3开始枚举 
	for(LL i=3;i<=100;i++)
	{
		//只有1和这个数本身，则该数是质数 
		for(LL j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		
		if(flag)
		{
			p[index++]=i;
		}
		
		flag=1;
	} 	
	
	return; 
}
#endif 


//73.求值 
#if 0
#include <iostream>

using namespace std;

typedef long long LL;

const LL MAXN=1e4;

LL yueshu[MAXN]; 
int main()
{
	LL index=0;
	
	LL i;
	for( i=1;i<=9999999999;i++)
	{
		for(LL j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(i/j!=j)
				{
					yueshu[index++]=j;
					yueshu[index++]=i/j;
				}
				else
				yueshu[index++]=j;
			} 
		}
		
//以下写法便于调试与验证：		
//		for(int i=0;i<10;i++)
//		{
//			cout<<yueshu[i]<<" ";
//		}
//		cout<<endl;
		
		LL bianli=0;
		LL count=0;
		while(yueshu[bianli])
		{
			count++;
			bianli++;
		} 
		if(count==100)
			break;
			
		fill(yueshu,yueshu+MAXN,0);
		index=0;
	}
	
	
	cout<<i;
	
	return 0;
}
#endif 


//74.单词分析 
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
	string str;
	
	getline(cin,str);

	long count[26]={0};
	
	for(auto it=str.begin();it!=str.end();it++)
	{
		count[*it-'a']++;
	}
	
//	long m=-1;
//	for(int i=0;i<26;i++)
//	{
//		m=max(m,count[i]);
//	}
	
	//max_element()返回指向这个在范围中最大值的指针 
	long* m_p=max_element(count,count+26);
	
	char ch='a'+m_p-count;
	
	cout<<ch<<endl<<*m_p;
	
	return 0;
}
#endif


//75.人物相关性分析 
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
	cin>>K;
	
	cin.get();
	
	string str;
	getline(cin,str);
	
	string target1{"Alice"};
	string target2{"Bob"};
	
	LL count=0; 
	
	//预处理：若Alice和Bob前后有字母，则删去 
	LL loc1=0,loc2=0;
	
//	while(loc1!=str.size()&&loc2!=str.size())
	while(1)
	{
		loc1=str.find(target1,loc1);
		
		//此处必须是
		//()&&() 
											//***此处5是索引值 
		if((loc1!=string::npos)&&
		(isalpha(str[loc1-1])||isalpha(str[loc1+5])))
		{				//***此处5是长度 
			str.erase(loc1,5);
		}
		
		loc2=str.find(target2,loc2);
													//***
		if((loc2!=string::npos)&&
		(isalpha(str[loc2-1])||isalpha(str[loc2+3])))
		{
			str.erase(loc2,3);
		}		
		
		if(loc1!=string::npos &&loc2!=string::npos)
		{
		loc1++;
		loc2++;
		}
		else if(loc1==string::npos&&loc2==string::npos)
		{
			break;
		}
		else if(loc1==string::npos)
		{
		loc2++;
		} 
		else
		loc1++;
	}
	
	cout<<str;
	
	loc1=loc2=0;
	LL loc3=0,loc4=0;  
	while(1)
	{
		loc1=str.find(target1,loc1);
		loc2=str.find(target2,loc2);
		
		//***
		if(loc1==string::npos||loc2==string::npos)
			break;
		
		//两者取小赋给loc3，即loc3指向A或B 
		loc3=min(loc1,loc2);
		
		if(loc3==loc1)
		{
			loc1++;
		}
		else if(loc3==loc2) 
		{
			loc2++;
		}
		
		//输入的是A...B...A，则现在来到测试B...A 
		if(loc4!=0) 
		if(loc3-loc4<=K)
		{
			if(str[loc3]!=str[loc4])
				count++;							
		} 
		
		loc1=str.find(target1,loc1);
		loc2=str.find(target2,loc2);
		
		//***
		if(loc1==string::npos||loc2==string::npos)
			break;
		
		//loc4指向A或B 
		loc4=min(loc1,loc2);
		
		if(loc4==loc1)
		{
			loc1++;
		}
		else if(loc4==loc2) 
		{
			loc2++;
		}
				
		if(loc4-loc3<=K)
		{
			if(str[loc3]!=str[loc4])
				count++;
							
		} 	
		

	}
	//要处理4个变量，实在有些费劲 
	
	cout<<count;
	
	return 0;
}
//20
//This is a story about Alice and Bob.Alice wants to send a private message to Bob.
#endif





























