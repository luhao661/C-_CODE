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
	int index=0;
	for(x=250000; x ;x--)
	{
		temp=(1000000-4*x)/7.0;//***ע***.0Ҫд���漰����֪ʶ���ǲ�ͬ���͵�ֵ������������ʱ������е�ת�� 
		if((1000000-4*x)/7.0>temp)//��temp�Ǹ�С�� 
			continue;
		
		y.push_back(temp);
	}

	for(auto p=y.begin();p!=y.end();p++)
		cout<<*p<<' ';
	
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
	
	for(long num=2;num<50000;num++)
		if(sushu(num))
			num_vector.push_back(num);
	
//	for(auto p=num_vector.begin();p!=num_vector.end();p++)
//	cout<<*p<<" ";
	
	int gongcha=1;
	int k=1;
	int shuliechangdu;
	
	//�ӵ�һ�ʼ�� 
	for(auto p=num_vector.begin();p!=num_vector.end();p++)
	{
		//�����������Ϊ1 
		shuliechangdu=1;
		k=1;
		gongcha=1;
		
		//***�޸Ľ���***
		//�ѹ��������ѭ������ѭ��������� 
		while(gongcha<1000)
		{
			//�����������Ϊ1 
			shuliechangdu=1;
			k=1;
			
			//�������pָ���Ԫ�ؿ�ʼ�� 
			for(auto q=p;q!=num_vector.end();q++)
				if((*p)+gongcha*k==*q)//�����1��ʼ�� 
				{
					shuliechangdu++;
					
					if(shuliechangdu==10)
						goto conclusion;
					
					k++; 
					continue;
				}
			
			//������1 
			gongcha++;
		}
	}
	
conclusion:cout<<gongcha;
	
	return 0;
}

bool sushu(long num)
{
	bool status=1;
	
	for(long i=2;i<num;i++)
	{
		if(num%i==0)
			status=0;
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
bool ok(int n,int gongcha);

bool flag[10000];
int main()
{
	shengchengsushu();
	
	for(int gongcha=2; ;gongcha++)
	{
		for(int qishizhi=2;qishizhi<10000;qishizhi++)
		{
			if(flag[qishizhi]&&ok(qishizhi,gongcha))
			{
				cout<<gongcha;
				return 0;//***ע***��������д���滻��goto��� 
			}
		}
	}

	return 0;
}

void shengchengsushu(void)
{
	//flag�����ʼ�� 
	for(int i=0;i<10000;i++)
		flag[i]=1;
	
	//���������ֵ�������������е�Ԫ�أ��������д�2��ʼ 
	for(int i=2;i<10000;i++)
	{
		if(flag[i])
			for(int j=i+i;j<10000;j+=i)
				flag[j]=0;	
	}
}

//�ж��Ƿ����㳤��Ϊ10�ĵȲ���������
//���е���ʼֵn�����еĹ���gongcha
bool ok(int n,int gongcha)
{
	for(int i=0;i<10;i++)
		if(!flag[n+i*gongcha]) 
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
	freopen("3.3.txt","r",stdin);
	
	int count=0;
	
	long temp;
	long long result=1;
	
	char shuzu[100]={'\0'};
	char shuzu2[100]={'\0'};
	int index2=0;
	int weishu;
	
	for(int i=0;i<100;i++)
	{
		cin>>temp;
		result*=temp;

//***ע*** 
//����ת�����ַ���
//��һ��		
//		sprintf(shuzu,"%d",result);
//������
//itoa ������һ����׼��C����������Windows���еģ����Ҫд��ƽ̨�ĳ�������sprintf 
		itoa(result,shuzu,10);
		
		//��resultΪ8800 
		//����Ҫ������λ�� 	
		weishu=1;	//***ע***�����������for��int index=0�󣬲��ᱻִ�� 
		for(int index=0;shuzu[index];index++)
		{
			if(shuzu[index]=='0')
				weishu++;			
		}
		
		//����result���ֵĳ��� 
		int changdu=0;
		for(int index=0;shuzu[index];index++)
		{
			if(shuzu[index]!='\0')
				changdu++;
		} 
		
		//weishuΪ3��������������λ��
		//***ע***shuzu2Ҫ����������� 
		for(int i=0;i<100;i++)
		{
			shuzu2[i]='\0';
		}
		
		for(int index=0;index!=weishu;index++)
		{
			shuzu2[index]=shuzu[changdu-weishu+index];
		}
		
		//result����Ϊ800 
		result=atoi(shuzu2);
		
		if(result/10==result/10.0)
		{
			count++;
			result/=10;
		}
	}
	
	cout<<count;

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
	long long temp,result=1;
	int zero=0;
	
	freopen("3.3.txt","r",stdin);
	
	for(int i=0;i<100;i++)
	{
		cin>>temp;
		result*=temp;
		
		while(result%10==0)
		{
			result/=10;
			zero++;
		}
		
		result%=100000000;//resultʼ�ձ�����8λ�� 
	}
	cout<<zero; 

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

bool operator<(const fenjieTypeDef&,const fenjieTypeDef&);

//set�������϶�Ԫ�ؽ����Զ�����ʱ�����õ�==����� 
//bool operator==(const fenjieTypeDef&,const fenjieTypeDef&);

int main()
{
	int i,j,k;
	
	fenjieTypeDef fenjieStruct;
	set<fenjieTypeDef> num_set;
	vector<int> v1;
	
	//����1��
	//�ж�һ�������Ƿ�2��4 
	char erhuosi[10]={'\0'};
	
	const int NUM=2019;
	for(i=1;i<NUM;i++)
		for(j=1;j<NUM;j++)
			for(k=1;k<NUM;k++)
				if(i+j+k==NUM&&i!=j&&i!=k&&j!=k)//����2��������ͬ�������� 
				{
//������⣺ 
//					if(i==2||j==2||k==2||i==4||j==4||k==4)
//						continue;
					
					//ÿ���������Ƿ�����2��4�ı��					
					int biaoji=0;
					
					itoa(i,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;

					itoa(j,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;
							
					itoa(k,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;
																				
					if(biaoji)
					continue;
					
					//ÿ�ν���ʱv1��Ҫ������� 
					v1.clear();
					
					v1.push_back(i);
					v1.push_back(j);
					v1.push_back(k);
					
					//����(��vector����ʹ��sort()) 
					sort(v1.begin(),v1.end());
					
					//�����򸳸�x,y,z 
					fenjieStruct.x=v1[0];
					fenjieStruct.y=v1[1];
					fenjieStruct.z=v1[2];		
					
					//�Զ�ɾ���ظ���(����set��������) 
					num_set.insert(fenjieStruct);
				}
	
//	int count=0;			
//	for(auto p=num_set.begin();p!=num_set.end();p++)
//	{	
//		cout<<p->x<<" "<<p->y<<" "<<p->z<<endl;
// 		count++;
//	 }
 	
 	cout<<endl<<num_set.size()<<endl;
 	
	return 0;
}
bool operator<(const fenjieTypeDef& f1,const fenjieTypeDef& f2)
{
	bool b=0;
	
	if(f1.x<f2.x)
		b=1;
	else if(f1.x==f2.x&&f1.y<f2.y) 
		b=1;
	else if(f1.x==f2.x&&f1.y==f2.y&&f1.z<f2.z) 
		b=1;
		
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
	int count=0;
	
//ͨ���������������ѭ������ʼֵ�ͺ���ֵֹ��������������ظ�
//i,j,2019-i-j���������������ʽ����
 
//	for(int i=1;i<2019/3+1;i++)
//		if(judge(i))				
//			for(int j=i+1;j<2019-i-j;j++)
//				if(judge(j))
//					if(judge(2019-i-j))
//						count++;
		
	//Ҳ����д��				
		for(int i=1;i<2019;i++)
			if(judge(i))
				for(int j=i+1;j<2019-i-j;j++)
					if(judge(j))
						if(judge(2019-i-j))
							count++;
						
	cout<<count;

	return 0;
}
bool judge(int num)
{
	while(num)
	{
		if(num%10==2||num%10==4)//��num�����λ��ʼ�ж��Ƿ�������2��4 
			return 0;
		
		num/=10;
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
	cin>>num;
	
	bool flag=0;
	long long result=0;
	for(int i=1;i<=num;i++)
	{
		long long temp=i;
		flag=0;
		while(temp)
		{
			if(temp%10==2||temp%10==0||temp%10==1||temp%10==9)
				flag=1;
				
			temp/=10;
		}
		
		if(flag)
		result+=i;
	}
	
	cout<<result<<endl;

	return 0;
} 
#endif
//������ 
#if 0
#include <iostream>
#include <vector>  
#include <algorithm>//STL��find()���� 

using namespace std;

bool judge(long );
int main()
{
	long long num;
	cin>>num;
	
	long long result=0;
	for(int i=1;i<=num;i++)
	{
		if(judge(i))
		result+=i;
	}
	
	cout<<result<<endl;

	return 0;
} 
bool judge (long num)
{
	char shuzi[10]={'\0'};
	itoa(num,shuzi,10);
	
	vector<char> shuzi2;
	for(int index=0;shuzi[index];index++)
		shuzi2.push_back(shuzi[index]);

//д��һ��		
//	for(auto p=shuzi2.begin();p!=shuzi2.end();p++)
//		if(*p=='2'||*p=='0'||*p=='1'||*p=='9')
//			return 1;
		
//д������ 
	char ch[4]={'2','0','1','9'};
	for(int index=0;index<4;index++)
		if(find(shuzi2.begin(),shuzi2.end(),ch[index])!=shuzi2.end())
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
	deep=log2(num)+1;//***ע***n���ڵ�����ȹ�ʽ 
	
	//����һ�����飬���ڴ�ÿ���Ԫ��֮�� 
	int* p=new int[deep];
	
	//�����ʼ��Ϊ0 
	for(int i=0;i<deep;i++)
		p[i]=0;
	
	int d=deep;
	
	for(int i=1;i<=d;i++)//�ڼ��� 
		for(int j=pow(2,i-1)-1;j<=pow(2,i-1)-1+pow(2,i-1)-1;j++)
			*(p+i-1)+=T[j];
	
	//����Ѱ�������е����ֵ��Ӧ������ֵ������ֵ+1���ǲ��(���)		
	int max=p[0];
	int result=1;
	for(int i=0;i<deep;i++)
		if(p[i]>max)
		{
			max=p[i]; 
			result=i+1; 
		} 
		
	cout<<result;
		
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
	cin>>num;
	
	for(int index=0;index<num;index++)
		cin>>T[index];	
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
	cin>>size;
	
	vector<long long> shuzu(size);
	long long temp;
	for(int i=0;i<size;i++)
	{	
		cin>>temp;
		shuzu[i]=temp;
	}
	
	sort(shuzu.begin(),shuzu.end());
	
//	for(int i=0;i<size;i++)
//		cout<<shuzu[i];

	long long gongcha=shuzu[1]-shuzu[0];

	long long min=shuzu[0];
	long long max=shuzu[0];
	for(int i=0;i<size;i++)
	{
		if(shuzu[i]>max)
			max=shuzu[i];
		if(shuzu[i]<min)
			min=shuzu[i];			
	}
	
	cout<<(max-min)/gongcha+1;
		
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
	
	int seconds=0;
	while(1)
	{
		energy-=10;
		seconds++;
		
		if(energy<=0)
			break;
			
		energy+=5;
		seconds++;
	}
	//***�������Ϊ����һ������Ϣһ���� 
	cout<<seconds;

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
	
	int seconds=0;
	while(1)
	{
		if(energy>=600)
		{	
			energy-=600;
			seconds+=60;
		}
		else//������С��600ʱ 
		{
			seconds+=energy/10;//(����ÿ���½�10��)
			break; 
		}
			
		energy+=300;
		seconds+=60;
	}

	cout<<seconds;

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
	long zongrenshu=10000;
	int ganranrenshu=10000*0.01;
	int k=2;//2�˻�� 
	int k1=0;
	
	valarray<long> data(998);
	int index=0;
	
	char ch[10]={'\0'};
	
	for(   ;   k<=1000;    k++,k1=0)
	{			
		int temp=zongrenshu/k;//��һ��ɸ��ʱ���˼����Լ��� 
		k1+=temp;		
		
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

		if(temp*0.01>int(temp*0.01))
			temp2=temp*0.01+1;//��һ�����������Լ�����		
		else
			temp2=temp*0.01;						
		
		k1+=temp2*k;//k1�ټ��ϵڶ���ɸ��ʱҪ�õ��Լ����� 
		
		data[index++]=k1;
	}
	
	for(int index=0;index<998;index++)
		cout<<data[index]<<" ";
		
	cout<<endl<<data.min()<<endl;
	
	int result;
	for(int index=0;index<998;index++)
		if(data[index]==data.min())
			result=index;

	cout<<"����ֵ��"<<result;//�õ���           10000���ˣ�110���˻�����ʡ�Լ��У�Ϊ200�� 
	
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
	long zongrenshu=100;
	int k=2;//2�˻�� 
	int k1=0;
	
	map<long,long> data_map;
	
	for(   ;   k<=100;    k++,k1=0)
	{			
		int temp=zongrenshu/k;//��һ��ɸ��ʱ���˼����Լ��� 
		
		//����Ƿ����� 
		if(zongrenshu/(double)k>temp)
			continue;
		
		k1+=temp;		
		
		int temp2;
		//�ټ���Ƿ����� 
		if(temp*0.01>int(temp*0.01))
			temp2=temp*0.01+1;//��һ�����������Լ�����		
		else
			temp2=temp*0.01;						
		
		k1+=temp2*k;//k1�ټ��ϵڶ���ɸ��ʱҪ�õ��Լ����� 
		
		//��map�д����ݷ���һ�� 
		//***�����ʾ��***
		data_map[k]=k1;
		//�������� 
//		data_map.insert(pair<long,long>(k,k1));
	}
	
	//***map���������ı�������***
	for(auto p=data_map.begin();p!=data_map.end();p++)
	{
		cout<<p->first<<' '<<p->second<<endl;
	}
	
	//Ѱ���Լ��������ٵ�����
	map<long,long>::iterator di;
	di=data_map.begin();
	long min=di->second;	
	for(auto p=data_map.begin();p!=data_map.end();p++)
	{
		if(p->second<min)
		{	
			min=p->second;
			di=p;//�ݴ�p��ֵ 
		} 
	}
	
	cout<<endl<<di->first<<" "<<min;

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
int measure(int ,int); 

using namespace std;
int main()
{
	int x,y;//����ķ�Χ 
	cin>>x>>y;
	
	pair<int,int> pa;
	vector<pair<int,int>>v;//�������ΪԪ�أ�����vector���� 
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) 
		{
			pa.first=i;
			pa.second=j;
			v.push_back(pa);
		}
		
	pair<pair<int,int>,int> pa2;
	set<pair<pair<int,int>,int>>s;//�ô����������¶���<��������غ��� 
	//������һ���ṹ���֣���3������ 
	//set<jiegou_TypeDef>s;
	 
	for(int i=0;i<v.size();i++)//ȡһ���� 
		for(int j=i+1;j<v.size();j++)//ȡ��һ���� 
		{
			int x1=v[i].first;
			int y1=v[i].second; 
			int x2=v[j].first;
			int y2=v[j].second;
			
			int A=y2-y1;
			int B=x1-x2;
			int C=x2*y1-x1*y2;
			
			int gongyueshu=measure(measure(A,B),C);
			
			pa.first=A/gongyueshu;
			pa.second=B/gongyueshu;
			pa2.first=pa;
			pa2.second=C/gongyueshu;
			
			s.insert(pa2); 
		} 
		
	cout<<s.size();

	return 0;
} 

int measure(int a,int b)
{
//	if (b==0)
//		return a;
//	else 
//	   return measure(b,a%b); 

	//������algorithmͷ�ļ��а�����__gcd() 
	return __gcd(a,b);
	
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
	long long num=2021041820210418;
	
	long long count=0;
//	for(int i=1;i<=num;i++)
//		for(int j=1;j<=num;j++)
//			for(int k=1;k<=num;k++)
//			{
//				if(i*j*k==2021041820210418)
//				count++;
//			}

	for(long long i=1;i<=num;i++)
		for(long long j=1;j<=num;j++)
		{
			long long k=num/i/j;
			
			if(k>num||k<1||((double)num/i/j)>k)
			continue; 
			else
			{ 
				cout<<i<<' '<<j<<' '<<k<<' '<<endl;
				count++;		
			}
		
		}
//***����***
//���س�ʱ 

	cout<<count;		
			
	return 0;
} 
#endif
//���� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num=2021041820210418;
	
	long long count=0;

	//���num�����ӣ����������� 
	long long a[1000]={0}; 
	
	//***����֪ʶ***
	//��num�����ӵļ���ΪA��
	//��a*b*c=num��a��b��c�����Լ���A 
	
	int index=0;
	for(long long i=1;i*i<=num;i++)
	{
		if(num%i==0)//��i������ 
		{
			a[index++]=i; 
			
			//***ע***����������д 
			if(num/i!=i)
				a[index++]=num/i;//����num/i�����ӵĽϴ��� 
		} 
	} 
	
	cout<<"index="<<index<<endl; 

	for(int i=0;i<index;i++)
		for(int j=0;j<index;j++)
			for(int k=0;k<index;k++)
			{
				if(a[i]*a[j]*a[k]==num)
					count++;
			}	
			
	cout<<count;		
			
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
	long long num=2021041820210418;
	
	long long count=0;

	//���num�����ӣ����������� 
	set<long long>a; 
	
	//***����֪ʶ***
	//��num�����ӵļ���ΪA��
	//��a*b*c=num��a��b��c�����Լ���A 
	
	int index=0;
	for(long long i=1;i*i<=num;i++)
	{
		if(num%i==0)//��i������ 
		{
			a.insert(i);//���㵽900000009���������ʱ��ǳ��� 
//							//���Բ���Ҫi*i<num��һ�ж����� 
			a.insert(num/i); 
		} 
	} 
	
	for(auto p=a.begin();p!=a.end();p++)
	cout<<*p<<endl; 

	for(auto i=a.begin();i!=a.end();i++)
		for(auto j=a.begin();j!=a.end();j++)
			for(auto k=a.begin();k!=a.end();k++)
			{
				if((*i)*(*j)*(*k)==num)
					count++;
			}	
			
	cout<<count;		
			
	return 0;
} 
#endif



























