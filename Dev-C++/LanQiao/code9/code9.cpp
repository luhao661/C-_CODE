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


//********************�����ű�������������********************
//1.��ʾ��ͬ���� 
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


//2.�洢�����Ƶ����� 
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


//3.��C++���Ƿ��C������ĳ�ʼ���ķ���Ч��һ��
//�����ֳ�ʼ������£�δ��ʼ����Ԫ���Ƿ񶼻ᱻ����Ϊ0 
#if 0
#include <iostream>

using namespace std;
const int MAX=20;

int main()
{
	//һά 
	int yiwei[10]={1};
	//��ά 
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
			
	long **p=new long* [MAX]; //��MAX��Ԫ�أ�ÿ��Ԫ�ض���ָ��long��ָ��  
	for(long i=0;i<MAX;i++)
	{
		//һά�����ָ��*(p+i)ָ��һ����MAX��Ԫ�ص����飬ÿ��Ԫ�ض���long���͵�ֵ 
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
	
	//���ۣ�
	//C++�У���֧��C�е�ָ����ʼ�������� 
	//��һ�㷽�����������飬δ��ʼ����Ԫ�ػ��Զ�������Ϊ0
	//����new�����Ļ�����ʼ��һ��Ԫ�غ�δ��ʼ����Ԫ�ز����Զ�������Ϊ0		

	return 0;
} 
#endif 


//4.���� 
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
	
	//��i+1�е����ݸ���16*16�������� 
	int i=0;
	
	for(int j=0;j<32;j++)//��i+1�е�j+1�� 
	{
		n=7;
		
		if(input[i][j]<0)
		input[i][j]=256+input[i][j];
		
		while(input[i][j])//��ĳ��������8λ����������ʾ 
		{
			getdata[m][n--]=input[i][j]%2;
			input[i][j]/=2;
		} 
		
		j++;
		
		n=15;
		
		if(input[i][j]<0)
		input[i][j]=256+input[i][j];
		
		while(input[i][j])//��ĳ��������8λ����������ʾ 
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


//5.����ַ��� 
#if 0
#include <iostream>
#include <algorithm>
 
using namespace std;

int main()
{
	int input=2019;
	
	int data[5];
	fill(data,data+5,-1);
	
	//���Ŵ�26���Ƶ��� 
	int index=4;
	
	//�������ֵ��1��������26��ʵ��Ϊ25��26���Ƶ���Ϊ25����Z
	//��ʾ����������Ŀ��Ҫ��ƥ�� 
	input-=1; 
	
	while(input)
	{
		data[index--]=input%26;
		input/=26;
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
	for(int i=0;i<5;i++)
	{
		if(data[i]==-1)
		continue;
		
		if(i!=4)//����ĩλ����Ҫ�����-1 
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


//6. ʱ����ʾ 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;

int main()
{
	LL num;
	cin>>num;//������Ǹ�1970��1��1��00:00:00����ǰʱ�̵ĺ����� 
	
	num%=24*60*60*1000;//����ĺ������������24Сʱ�ĺ�����
	
	num/=1000;//numΪ����
	int sec=num%60;
	num/=60;//numΪ������
	int minutes=num%60;
	num/=60;//numΪСʱ��
	
	cout<<setw(2)<<setfill('0');
	cout<<num<<':'<<setw(2)<<minutes<<':'<<setw(2)<<sec; 

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

const int LIM=50;
int zhishu[LIM];

void getzhishu(int *);

int main()
{
	int a,b;
	cin>>a>>b;
	
	getzhishu(zhishu);
	
	long count=0;
	//��������i 
	for(int i=a;i<=b;i++)
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
		auto p=find(zhishu,zhishu+LIM,i);
		if(p!=zhishu+LIM)
		{
			count++;
			continue;
		} 
		#endif//�������ԣ������鲻дҲ���ԣ���ʱ�临�Ӷ������ 
		
		//������i�������� 		
		int temp=i;
		for(int index=0;index<LIM;index++)
		{
			//***ע***����while 
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
//7.�޸� 
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
	//��������i 
	for(int i=a;i<=b;i++)
	{
		//������i������ 
		#if 1 
		auto p=find(zhishu.begin(),zhishu.end(),i);
		if(p!=zhishu.end())
		{
			count++;
			continue;
		} 
		#endif//�������ԣ������鲻дҲ���ԣ���ʱ�临�Ӷ������ 
		
		//������i�������� 		
		int temp=i;
		for(int index=0;index<zhishu.size();index++)
		{
			//***ע***����while 
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


//8.����find()�����ķ���ֵ 
#if 0 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int shuzu[3]={1,2,3};
	
	int* p=find(shuzu,shuzu+3,4);
	
	if(p==shuzu+3)
		cout<<"δ�ҵ���";
	else
		cout<<"���ҵ���"; 

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
	cin>>num;
	
	cout<<hex<<uppercase<<num;

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
	cin>>N;
	
	
	int M;
	cin>>M;
	
	char shuzi[99999];
	fill(shuzi,shuzi+99999,'\0');
	
	long num=0;
	
	if(N>=2&&N<=10)
	{
		sprintf(shuzi,"%d",M);  //û�������N����Ľ��ƣ����������� 
		num=atoi(shuzi);
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
	
	cout<<num;

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
			num+=a*(M[index]-'0');//***ע***һ��Ҫ����д 
			
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
				num+=a*(M[index]-'0');//***ע***һ��Ҫ����д 
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
	
	string snum(cnum);//ԭ���� 
	string stemp(cnum);
	
	reverse(stemp.begin(),stemp.end());//�ߵ�������� 
	
	int count=0; 
	
	while(stemp!=snum)
	{
		long num1=atol(stemp.c_str());
		long num2=atol(snum.c_str());

		sprintf(cnum,"%d",num1+num2);//���C����ַ��� 
		snum=cnum;//���string���� 
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


//11.�������� 
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
					pair<int,int> a (y,m);//ʹ��pair��Ĺ��캯�� 
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


//12.�������� 
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


//13.����ƴ�� 
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


//14.��Ƭ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int kapian[10];//0��9�Ŀ�Ƭ���� 
	fill(kapian,kapian+10,2021);


#if 0 //������һ�����ֵĿ�ƬΪ0,����� 
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
				kapian[temp[i]-'0']--;//***ע***Ҫ����д�� -'0' 
				
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
				kapian[temp[i]-'0']--;//***ע***Ҫ����д�� -'0' 
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


//15.������� 
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
	
	//��new������ά����(�˷���������ֵ�������Ǳ���)
	//pָ��n*n�Ķ�ά����ĵ�һ�У����һ�еĵ�ַ 
	long **p=new long* [MAX]; //��MAX��Ԫ�أ�ÿ��Ԫ�ض���ָ��long��ָ��  
	for(long i=0;i<MAX;i++)
	{
		//һά�����ָ��*(p+i)ָ��һ����MAX��Ԫ�ص����飬ÿ��Ԫ�ض���long���͵�ֵ 
		*(p+i)=new long [MAX];
 	} 
 	
//��fill()�д������ݲ��� 
//	fill(&p[0][0],&p[0][0]+100*100,0L);
//***ԭ��***��new�����Ķ�ά���飬���������Ϸ�ʽ�����Ķ�ά���飬
//����Ԫ�ز���һƬ�������ڴ�����
//��LanQiao_code��5050�е�new�����Ķ�ά������һƬ�������ڴ����� 
 	
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
			
			//������������ǵ�ͬʱ���������ֵĸ����ļ��� 
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

	int gongcha=1;
	int changdu=1;
//	while(changdu!=10)
//	{

	//�ӵ�i�����ֿ�ʼ�� 
	for(int i=0;i<1000;i++)
	{
		//��i�����ӹ���Ϊ1��ʼ�ԣ�������Ϊ999���� 
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
			
			//������Ϊ10��ǿ���˳�����ѭ��	
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
		int loc=str.size()-1;
		
		for(int i=loc;chstr[i]=='0';i--)
		{
			if(chstr[i]=='0')
			{
				count++;//���������ַ�0�޸�Ϊ\0 
				chstr[i]='\0';
			}
		}
		
		num=atol(chstr);//���β��0������ 
		cout.width(20);
		cout<<num<<"\t";
		
		num%=100000;//����Ϊ�ض̺������ 
		cout<<num<<"\n";
	}
	
	fin.close();
	
	cout<<count; 

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

			//***ע*** 
			//��취���ٵ�����ѭ�� 
			int k=NUM-i-j;
						
			sprintf(tempc,"%d",k);
					
			if(strchr(tempc,'2')!=NULL||strchr(tempc,'4')!=NULL)
				continue;				
				
			if(k>0&&i!=j&&i!=k&&j!=k)
			{
				tempv.push_back(i);
				tempv.push_back(j);
				tempv.push_back(k);
				
				//���������setȥ�� 
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


//19. �ر���֮�� 
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
				break;//һ��Ҫ�� 
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
	cin>>N;
	
	vector<int> get_data(N+1);
	
	get_data.assign(N+1,0);//��N+1��0��vector������ 
	
	//����Ϊ1����Ӧ��һ��Ԫ�� 
	for(int i=1;i<N+1;i++)
	{
		cin>>get_data[i];
	} 
	
	//������� 
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


//21.�Ȳ����� 
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


//23.�ܲ�ѵ�� 
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


//24.�ϲ����
//�ο�
//https://blog.csdn.net/CodingFire/article/details/126489570
#if 0
#include <iostream>

using namespace std;

int main()
{
	//������
	int zongrenshu=5000;
	//һ�����������Сֵ
	int min=9999;
	//һ����������Լ���������������
	int k,sum,ans;
	
	for(k=1;k<100;k++)
	{
		//���պó���
		if(zongrenshu%k==0)
		{
			/*
         zongrenshu/k���״μ����ô������Ҫ���Լ��У�0.01*zongrenshu�ǳ��ָ�Ⱦ�˵�������
         ��Ϊ��Ⱦ����ƽ���ֲ��ģ����Կ�����Ϊ��0.01*m�ķ����У�ÿ���
         ��һ����Ⱦ�ߣ���Ҫ����Щ���ÿһ���˽��е����ļ�⣬ÿ������Ϊk��
         ����μ����Ҫ0.01*zongrenshu*k�����У�����������һ���ļ����
         */
			sum=zongrenshu/k+0.01*zongrenshu*k;
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
	fill(&jinzita[30][0],&jinzita[30][0]+31,0L);
	
	LL temp;
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++)
		{
			fin>>temp;
			temp*=pow(2,29);//***ע***���ֵ��ô���ģ��Ǹ��ѵ� 
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
//STL��max����ֻ�ܱȽ��������� 
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


//28.������ֵ 
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


//29.���ɿ��� 
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
		
//������⣺ 
//		//STL��min()���� 
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


//30.������Ԫ�� 
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

//�Ż�д��
#if 1
	int count=0;
	int count1=0,count2=0;
	
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

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)//�Ȱ�����B��ֵ�̶����ж�A��C�з���������Ԫ�ظ���
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


//31.�˻����
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
	
//������ 
//	sort(p_data,p_data+N+1);
//	reverse(p_data,p_data+N+1);

//	for(int i=1;i<=N;i++)
//	{
//		cout<<p_data[i]<<" ";
//	}

/************************************/
//���㸺���ĸ���
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
		else if(K%2==0)//���k��ż��
		{
			if(fushu%2==0)//��������и����ĸ�����ż��
			{
				for(int i=1;i<=N;i++)
				{
					if(p_data[i]<0)
						p_data[i]=-p_data[i];//������Ϊ����������������
				} 		
				sort(p_data,p_data+N+1,mycompare); 
//�����޷�����-5 -1 1 2 3 ȡ���������				
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
//��next_permutation()�ò��ַ��� 
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
	
//***ע***��next_permutation()�Ļ��������ݱ����ǵ�����
	sort(p_data+1,p_data+N+1);

//����д����
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

//����ķ���λ�ã�	
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

//***ע***
//������������ȼ�����<<���ʱ���Ҫ��<<�����Բ���� 
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


//33.��׺���ʽ 
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
		reverse(p+1,p+N+M+2);//���еݼ�
		
		for(long i=1;i<=N+M;i++)
		{
			res+=p[i];
		}	
		
		res-=p[N+M+1];		 
	}
	
	cout<<res;

	return 0;
}
//�д���
//�𰸼�LanQiao_code L3040 
#endif


//34.��DFS���Թ� 
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


//35.����ָ� 
#if 0
#include <iostream>

using namespace std;

bool mark[7][7];
bool dfs(int ix,int iy);
int count=0;

int main()
{
//	int area[7][7];//x���y������귶ΧΪ0~6 
	
	int ix=3,iy=3;
	
	//***����4��***	
	mark[ix][iy]=1; 

	dfs(ix,iy); 
	
	//����3�� 
	cout<<count/4;

	return 0;
}
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool dfs(int ix,int iy)
{
	int ix2,iy2;//��(ix,iy)��ԭ��Ϊ���ĶԳ� 
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
			
			//����1��
			mark[6-n][6-m]=1; 

//����д����
//����д�൱�����Թ����ҵ����ں��ֹͣdfs�ˡ�			
//			if(dfs(m,n))
//			{
//				mark[n][m]=0;//������һ������о����ĵ�������Ϊ0 
//				return true;
//			}

			
			dfs(m,n);
			mark[n][m]=0; 
			//����2��
			mark[6-n][6-m]=0;  
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
//����д����	
//	dfs(0,0); 
	
	cout<<Max;

	fin.close();

	return 0;
} 

bool dfs(int num,int x)
{
//����д����
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
			
//����
//			dfs(num+1,x+data[num][i]);

//д��һ��
			dfs(num+1,x+data[i][num]);
//д������
//			dfs(num+1,x+rates[num][i]); 
			
			mark[i]=0;	
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
bool dfs(char**p,int x,int y);
int count1=0;
bool check(char**p,int x,int y);

int main()
{
	int N;
	cin>>N;
	
	fill(&mark[0][0],&mark[0][0]+10010*10010,1);
	
//����д����
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
	
	cout<<"ԭ����������";
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
	
	//��δ��û�ĵ������� 
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
	cout<<"δ��û�ĵ���������";
	cout<<remain<<endl;
	
	cout<<daoyu-remain; 

	return 0;
}
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool dfs(char** p,int x,int y)
{	
	//���жϵ�(x,y) 
	if(mark[x][y]==0&&p[x][y]=='#')
	{
		mark[x][y]=1;
		count1++;
	}

	//���ж�(x,y)������ܵĵ� 
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
//***ע***���ܱ���ѷ��ʣ�
//�˺������ж�ÿ�������Χ4�������� 
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
//39.�һ�Ӳ������(һάdp����)
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


//40.���Ӵ��� 
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
	
	//ÿ��������value��Ϊ1
	
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


//41.K������ 
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
			if(j==0) 
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
	cout << "ֻ���ĸ����������һ��2���ڶ���2����" <<dp[2][2] << endl;
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


//44.������� 
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
	
	//***ע***�����ǳ���ʱ�Ķ�ά����Ĵ������� 
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


//45.�������� 
//***ע***���ű�������atoi() 
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

//��ȡ�����յ��������ֵ����ķ����ǳ���ȡ��
//int year=date/10000;
//int month=date/100%100;
//int day=date%100; 

	for(int y=year;y<=8999;y++)
	{
		//�ж����� 
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
				//ͷָ�� ��βָ�� 
				copy(data,data+9,data1);//���������ַ�������(����ĩβ�Ŀ��ַ�) 
//***ע***�˴����ַ��������ĩβ�Ŀ��ַ���Ҫ�������ֻ��+8			
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
				
				//***ע***����д�� 
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
	
	//���������ֵ���ĸ�����ֵ��ʼ 
	for(int begin=1;begin<=N1;begin++)
	{
		int i;
		int count=1;
		
		//���������ֵi��begin��ʼ��N����������ѭ�� 
		for(i=begin; count<=1000;i++)
		{			
			if(i>N)
			i=1;
				
			if(count==v[i])
			{
				sum+=count;
				v.erase(v.begin()+i);
				
				N-=1;//***
				i--;//***ɾ��һ��Ԫ�غ���������for�Ὣi��1��v[i]���Ǳ�ɾ����Ԫ�ص���һ��Ԫ�عʴ˴��ȼ�1***
				
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
			
			//***��д�Ļ���ʱ��iΪ0��v[0]��δ֪�� 
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


//47.��Լ���� 
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


//48.�Ź��÷� 
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
	
	//˼·��ȫ���У��������нⷨ������������ݶ��� 
	int quan[10]={0,1,2,3,4,5,6,7,8,9}; 
	//�洢���еķ���Ҫ��ľŹ��÷� 
	int nine1[4][4];	
	//������������Ĳ��ֵľŹ��÷�
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
		
		//�ж��Ƿ�����Ź��÷���Ҫ�� 
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


//49.��Խ���� 
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

	for(int i=0;i<4;i++)
	{
		m=x+dx[i];
		n=y+dy[i];
		
		if(!mark[m][n]&&p[x][y]!=p[m][n])
		{
			mark[m][n]=1;
			
			if(dfs(m,n,p,step+1))//***ע***����д�ܲ�� 
			{
				cout << "(" << m << "," << n << ")" << endl;
				
				mark[m][n]=0; 
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
 
bool dfs(int x,int y,int** p,int step)
{
//��д�ɲ�д 
	if(step>min_step)
	return false; 
	
	if(step>bushu[x][y])
	return false;
	
	if(p[x][y]==-2)
	{
		min_step=step;
		return true;//***
	}
	
//	��¼�ߵ�ÿ�������Ĳ��� 
	bushu[x][y]=step;
	
	int m,n;

	for(int i=0;i<4;i++)
	{
		m=x+dx[i];
		n=y+dy[i];
		
		if(!mark[m][n]&&p[x][y]!=p[m][n])
		{
//***ע***�߹�������㲻����ѷ��� 
//			mark[m][n]=1;
			
			dfs(m,n,p,step+1);
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

//dfs��������·���� 
//���Ӽ�¼�����ľ���bushu[][];

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
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		
		if(p[tx][ty]!=p[x][y])
		dfs(tx,ty,p,cnt+1);
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
int bfs(int x,int y);

int main()
{
	int n;
	cin>>n;

//������������ά����Ļ��������������βο�����**p 
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
//***ע*** mark[ty][tx]==0Ҫд��ǰ�棬��˼�ǣ�����·Ҫ��
//�ԣ���Ҫ�ߵ�����ֵ�� 
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


//50.��� 
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
//50.����ǰ׺����������Ż� 
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
		b[i]=b[i-1]+p[i];//p[1]�൱��b[1]��p[2]�൱��b[2]-b[1] 
	}						//p[3]�൱��b[3]-b[2] 
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


//51.ѡ����� 
#if 0
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main()
{
	//����n����ѯm�Σ��Ǹ�����x 
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
	//�ӵ�һ�����俪ʼ�ж� 
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
				
				//����д���� 
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
			//���ʣ�
			//��b^a=x����
			//b^a^a=x^a��b=a^x 
	      long long b=a[i]^x;
			
//***ע***����д�ᳬʱ 
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


//52.�����ļ׿ǳ�(̫�ѣ���)
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


//53.���ܹ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int main()
{
	LL n,x;
		//��x��Σ�ʵ����Ҫ����2x�� 
	cin>>n>>x;
	
	LL *H=new LL[n*n];
	fill(H,H+n*n,0);//*****

	for(LL i=1;i<=n-1;i++)
	{
		cin>>H[i];
	}
	
	LL *H1=new LL[n];

	
	//��� 
	LL span=1;
	LL begin=0;
	bool flag=0;
	
	while(x--)
	{
//ȥ��ѧ 
		//������ǰ����ʯͷ��״̬ 
		for(LL i=1;i<=n-1;i++)
		{
			H1[i]=H[i];
		}	

		if(!flag)
		{
			//�ѵ㣺 
			//���ղ��õ��׸������پ��룬
			//���Ҽ�ʹ���ȥ��ѧ��ģ��ɹ��ˣ�
			//ʣ�µ�ʯͷ�ĸ߶ȿ����ڵ�ǰ��Ծ�����²�����֧����ؼ� 
			//����˵�޷�������ѹ滮 
			
			//�˴�ѡ���ȴ���Ծ�ľ��������Ծ���������ֵ
			//��ʼ���� 
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

//�ؼ�	
		//������ǰ����ʯͷ��״̬ 
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
    
    //Ԥ����ǰ׺��
   for(int i = 1; i <= n - 1; i++)
   {
	   cin >> H[i];
		Pre_Sum[i] = Pre_Sum[i - 1] + H[i];
   }
   
	//���ִ�
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


//54.����½������� 
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
			//��εĴӵ�i��Ԫ�ؿ�ʼ��k��Ԫ�صĸı���ɵ�count 
			//�Ƿ���ϴεĸı���ɵ�ans[k]Ҫ�� 
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
    for(int i = 2; i <= n; i++)
	 if(!not_prime[i])
    {
        prime[++tot] = i;
        for(int j = i + i; j <= n; j += i)
            not_prime[j] = 1;
    }
}
//�ж�ƽ����
inline bool square_number(ll x)
{
    ll y = sqrt(x);
    while(y * y <= x)//��ƽ�����ھ�������Ҫ���жϼ���
    {
        if(y * y == x)return true;
        y += 1;
    }
    return false;
}
//�ж�������
inline bool cubic_number(ll x)
{
    ll y = pow(x, 1.0 / 3);
    while(y * y * y <= x)//���������ھ�������Ҫ���жϼ���
    {
        if(y * y * y == x)return true;
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
    while(T--)
    {
        ll a;
        cin >> a;
        //������ƽ������������
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
            	//�ݴα������1
            	if(mi == 1)
					{
						flag = false; break;
					}
        }
        //ʣ��Ĳ����ٴ��ж�ƽ������������
        if(flag && (square_number(a) || cubic_number(a)))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
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

//***ע***ֱ����ԭ��ͼ�ϲ��� 
void floyd(int n)
{
	//k����ת������±� 
   for(int k = 1;k <= n;k++)
	{
		//��ʼ������±� 
      for(int v = 1;v <= n;v++)
		{
			//��ֹ������±� 
         for(int w = 1;w <= n;w++)
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
LL dp[(1<<21)][21];
LL map[21][21];//��������ѧ¥֮���Ƿ����·�� 

int main()
{	
	for(int i=1;i<=21;i++)
	{
		for(int j=1;j<=21;j++)
			if(__gcd(i,j)==1)
			{
				map[i-1][j-1]=1;
				map[j-1][i-1]=1;//��1~21ӳ�䵽0~20
			}
	}
	//mapֻ��0~20 
	

	for(int i=0;i<=20;i++) 
	{
		for(int j=0;j<=20;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	
	LL n=(1<<21)-1;//nΪ1111111111 1111111111 1

	//��ǰ״̬Ϊ0000...1 �ߵ���ѧ¥0Ҳ����1�ķ����� 
	dp[1][0] = 1;
	
   for(int i = 1;i<=n;i++)
	{
      for(int j = 0;j<=20;j++)
		{
			//�ҵ�״̬i���߹��ĵ�j
         if(!(i >> j & 1)) 
				continue ;
			//����j�㣬����ת�Ƶ�j�ĵ�k				
         for(int k = 0 ; k <=20 ; k++)
			{
				//��δ��j֮ǰ��״̬Ϊ i>>j&1 �ж��Ƿ��߹�k��
            if(!map[j][k] || (i >> k & 1)) 
					continue ;
					
            dp[i + (1 << k)][k] += dp[i][j];
         }
      }
   }
   
   LL res=0;

   for(int i=1;i<=20;i++)//�����ڶ�����2~21������
      res+=dp[n][i];     //(��Ӧ1~20) 
      
   cout<<res;

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

ll index=1;

//�ж�ʤ������
int judge()
{
    //ż����1���޷�����ʤ��
    if(cnt1 % 2 == 0) return 0;
    //ֻ��1��1�����ֱ�ʤ
    if(cnt1 == 1) return 1;
    //0��1�ĸ�����Ϊ����������ʤ
    if(cnt1 % 2 != 0 && cnt0 % 2 != 0)
        return -1;
    //����ʤ
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
    
    //���������ֵΪ0��ƽ��
    if(sum == 0) 
	 {
	 	 cout <<0 <<endl; 
		 return; 
	 }
        
    //��Ϊx���x^20-1��11111...1(20��1) 
    //�����λ��ʼö��
    for(int i = 20; i >= 0; i--)
	 {
        cnt1 = cnt0 = 0;
        //����
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


//61.�������� 
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
LL matrix[100][100];

int main()
{
	LL num=1;
	
	//�ߵĵ�x�� 
	LL duan=1;
	
	
	LL row,col;
	
	while(duan<=50)
	{
		//��1��3��5��7...�� 
		if(duan%2!=0) 
		{
			row=duan;
			col=1;
			
			while(row!=0)//***
//����д����		
//			matrix[row--][col++]=num++;
//�ֺű�ʾ��˳��㣬���C++ֻ��֤����ִ�е���һ�����֮ǰ��
//������(��row��col��numd��ֵ�ı�)��
//C++û�й涨���ڼ���ÿ���ӱ��ʽ֮����Щֵ�ı䣬
//�������������ʽ������Ϻ�Ž���Щֵ�ı�	
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
//61.������ֱ����ÿ�����ֵ���ʱ�������еĹ�ϵ 
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


//62.�߶��� 
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
//�˸���������� 
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
//����Ƿ���ͨ
void dfs(int x)
{
    //�����ͨ�ıߵĸ�������ѡ������ȣ�˵����ͨ�������һ
    if(cnt == ans)
	 {
        res++; 
		  return;
    }
    
    for(int i = 1; i <= 7; i++)
	 {
	 	//***ע***
		//����Ҫ��û�з��ʹ��ıߣ���Ҫ�жϱ��Ƿ�����(���Ƿ��ڽ�)��
		//���ж�������ѡ����⼸������ 
        if(vis1[i] || !g[x][i] || !vis[i]) 
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
    for(int i = 1; i <= 7; i++)
	  vis[i] = vis1[i] = false;
    
    //��1~127��Χ�ڵ�ÿ����ת��Ϊ�����ƣ��Ͷ�Ӧһ�ַ���    
	 s = Binary(i);
	 cout<<s<<endl;
	  
    ans = 0;
    
    //��¼��ǰ״̬�µ��߶�����ܣ�ѡ����⼸���� 
    for(int i = s.length() - 1; i >= 0; i--)
        if(s[i] == '1')
		   {
		   	//***Ҫд��s.length()-i����iΪ0ʱ��s[0]��Ӧvis[s.length()]=1 
				vis[s.length()-i] = true;
				ans++;
			}
			
	 
	 //��ĳ���߿�ʼ���ѣ�������ͨ�ж�		
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
//***ע***���������Թ���˼����⣬
//�����ᵼ�²�֪��dfs()�ĵݹ����������ʲô��
//�����޷��涨ĳ״̬ѡ������ļ��������ܣ� 
//����Ҫ��ͼ���ڽӾ���˼����� 
 
    //a b c d e f g
    //1 2 3 4 5 6 7
    //��ʼ��ͼ
    memset(g,false,sizeof(g));
    
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
    for(int i = 1; i < (1<<7); i++)//***ע***״̬���Ϊ
        check(i);						  //1111111 
        
    cout <<res <<endl;
    
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
	int i=20;
	int res=i*(i+1)/2+1;
	
	//Բ��1����ʼ���ӵ�20�� 
	for(int j=1;j<=20;j++)	
	{
		res+=2*20+2*(j-1);
	}
	
	cout<<res;

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


//65.�Ӵ���ֵ 
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
//�ﲻ��Ҫ�� 
//			string temp(str,i,j+1);
			
			string temp;

//д��һ�� 
//			for(L k=i;k<=j;k++)
//			{
//				temp.push_back(str[k]);//***
//			} 

//д������ 
			temp=str.substr(i,j-i+1);

//			cout<<temp<<endl;

			for(L m=0;m<temp.size();m++)
			{
				char ch=temp[m];
				L pos;
				
				pos=temp.find(ch);
				
				//��pos+1λ�ÿ�ʼ���� 
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
//65.�Ľ�
#if 0
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[N];
int pre[N] , suf[N] , last[30];

signed main()
{
	//������ַ���������s������Ϊ1��λ�ÿ�ʼ�� 
   cin >> s + 1;
   				//s+1ʵ�����Ǹ���ֵַ 
   int n = strlen(s + 1) 
	int ans = 0;
   
   //���i���ַ���һ�γ��ֵ�λ�� 
   for(int i = 1 ; i <= n ; i ++)
	{
   	pre[i] = last[s[i] - 'a'];
      last[s[i] - 'a'] = i;
   }
   
   for(int j = 0 ; j <= 25 ; j ++) 
		last[j] = n + 1;
		
	//���i���ַ���һ�γ��ֵ�λ�� 
   for(int i = n ; i >= 1 ; i --)
	{
      suf[i] = last[s[i] - 'a'];
      last[s[i] - 'a'] = i;
   }
   
   //Ҫ�õ�i���ַ��Դ��й��ף�����������Ӵ�����˵��ȡֵ
	//������[pre[i]+1,i]֮�䣬�Ҷ˵������[i+1,suf[i]]֮�� 
   for(int i = 1 ; i <= n ; i ++)
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

const int N=310;

int n;//ʯ�Ӷ��� 
int a[N];//ÿ��ʯ�ӵ�����

int qianzhui[N];//��¼ǰ׺��
int dp[N][N];//dp[][]��ʾ�Ѵ�l��r�ϲ�Ϊһ�ѵ���С���۵�һ�ѷ����ļ��� 

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
	
	for(int len=2;len<=n;len++)//ö�����䳤�� 
	{
		for(int l=1;l+len-1<=n;l++)//ö���������
		{
			int r=l+len-1;//�����յ� 
			
			for(int k=l;k<r;k++)//ö�ٷָ�� 
			{
				dp[l][r]=
				min(dp[l][r],dp[l][k]+dp[k+1][r]+
				qianzhui[r]-qianzhui[l-1]); 
				//��ǰ�ĺϲ��Ĵ���һ���ǵ�ǰ�����ڵ�ʯ�ӵ�����֮�ͣ�
				//���Կ�����ǰ׺�� 
				
				//�ܵĴ���=֮ǰ�Ĵ���+��ǰ�Ĵ���(��ֵ) 
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


//68.�ظ��ַ��� 
//������̰�� 
#if 0
#include <iostream>
#include <cstring>
#include <algorithm>
//#include <string> //�������ã���Ϊstring���������0��ʼ�棬 
using namespace std; //��������ķ��� 

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
	
	//������1��ʼ�� 
	cin.getline(str+1,MAXN);
	
	//���ַ������Ȳ���K�ı��������ַ�������С��K 
	if((strlen(str+1)%K!=0)||strlen(str+1)<K)
	{
		cout<<-1;
		return 0;
	}
	
	//K�Σ���ôÿ�ξ���elements��Ԫ�� 
	LL elements=strlen(str+1)/K;
	
	//��26����ĸ���Գ��ֵĴ��� 
	int jishu[26]={0};//***Ҫ��ʼ��*** 
	int m;//��¼�����ֵ���ĸ�����ĳ��ִ��� 
	LL res=0;
	
	//�ӵ�1�εĵ�һ��Ԫ�ؿ�ʼ��������ļ������Ƚϣ�����һ�ε�Ԫ�ر��������� 
	for(LL i=1;i<=elements;i++)
	{
		for(LL beishu=0;beishu<=K-1;beishu++)
		{
			jishu[str[i+beishu*elements]-'a']++;
		} 
		
		sort(jishu,jishu+26);
		
		//��¼���γ��ֵ���ĸ�����ĳ��ִ��� 
		m=jishu[25];
		
		//�������ִ�������ĸҪ�ĳ����γ��ֵ���ĸ����K�Σ����Ը�K-m�� 
		res+=K-m; 
		
		//jishu��������һ�κ�ԭ 
		fill(jishu,jishu+26,0); 
	} 
	
	cout<<res;

	return 0;
}
#endif


//69.��Ӳ�� 
#if 0
#include <iostream>

using namespace std;

//����д�� 
//#define MAXN 1e3+10   //E��ʾ��ȷ�������Ը����ʽ�洢����ʹû��С����
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


//70.�ɿ��� 
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
		//��������˵������˺�,��ѡ�α��˵ģ�
		//����Ҫ�����±����� 
		LL tian=min(p->baozhiqi-tian1,p->shuliang);
		
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
		
		if(x-tian<=0)
		{
			money+=(p->jiage)*x;
			break;
		}
		else
		{
			money+=(p->jiage)*tian;
			//����Ҫ��ĳԵ����� 
			x-=tian;
		}
		
		//********
		tian1+=tian;
	}
	
	cout<<money;

	return 0;
}

//����дconst 
bool operator< (const Item_TypeDef& i1,const Item_TypeDef& i2)
{
	if(i1.jiage<i2.jiage)
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
	
//set�����е�Ԫ�ص�ֵ�����޸�ֵ 
//	auto it=s1.begin();
//	*it=0;

//multiset�����е�Ԫ�ص�ֵ�����޸� 
//	auto it=s2.begin();
//	*it=0;


//map�еļ���ֵ�����޸ģ�ֵ��ֵ�����޸� 
	auto it=m1.begin();
//	(*it).first=3;
	(*it).second=3;
	
   for (it = m1.begin(); it != m1.end(); ++it)
      cout << "    " << (*it).first << "     "
      << (*it).second << endl;

//multimap�еļ���ֵ�����޸ģ�ֵ��ֵ�����޸� 
	auto it1=m2.begin();
//	(*it).first=4;
	(*it1).second=4;
	
   for (it1 = m2.begin(); it1 != m2.end(); ++it1)
      cout << "    " << (*it1).first << "     "
      << (*it1).second << endl;

//deque�е�ֵ�����޸� 
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


//72.�׳�Լ�� 
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
	
//������5!��120��Լ��
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
	
	for(int i=0;zhishu[i]!=0;i++)
	{
		cout<<zhishu[i]<<" ";
	}
	cout.put('\n');
	
	LL count[110]={0};//��¼ĳ�������Ĵη��� 
	
	//��1~100��ÿ�������������ֽ� 
	for(int i=1;i<=100;i++)
	{
		
#if 1

		//����i��ֵ 
		int temp=i;
			
		for(int index=0;zhishu[index]!=0;index++)
		{			
			if(temp%zhishu[index]==0)
			{	
							
			   //����д���� 
//				while(temp!=1)
				//��ȷд���� 
				while(temp%zhishu[index]==0) 
				{
					//ĳ�������Ĵη���+1 
					count[zhishu[index]]++;
					
					temp/=zhishu[index];
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
	
	//������3��ʼö�� 
	for(LL i=3;i<=100;i++)
	{
		//ֻ��1���������������������� 
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


//73.��ֵ 
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
		
//����д�����ڵ�������֤��		
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


//74.���ʷ��� 
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
	
	//max_element()����ָ������ڷ�Χ�����ֵ��ָ�� 
	long* m_p=max_element(count,count+26);
	
	char ch='a'+m_p-count;
	
	cout<<ch<<endl<<*m_p;
	
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
	cin>>K;
	
	cin.get();
	
	string str;
	getline(cin,str);
	
	string target1{"Alice"};
	string target2{"Bob"};
	
	LL count=0; 
	
	//Ԥ������Alice��Bobǰ������ĸ����ɾȥ 
	LL loc1=0,loc2=0;
	
//	while(loc1!=str.size()&&loc2!=str.size())
	while(1)
	{
		loc1=str.find(target1,loc1);
		
		//�˴�������
		//()&&() 
											//***�˴�5������ֵ 
		if((loc1!=string::npos)&&
		(isalpha(str[loc1-1])||isalpha(str[loc1+5])))
		{				//***�˴�5�ǳ��� 
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
		
		//����ȡС����loc3����loc3ָ��A��B 
		loc3=min(loc1,loc2);
		
		if(loc3==loc1)
		{
			loc1++;
		}
		else if(loc3==loc2) 
		{
			loc2++;
		}
		
		//�������A...B...A����������������B...A 
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
		
		//loc4ָ��A��B 
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
	//Ҫ����4��������ʵ����Щ�Ѿ� 
	
	cout<<count;
	
	return 0;
}
//20
//This is a story about Alice and Bob.Alice wants to send a private message to Bob.
#endif





























