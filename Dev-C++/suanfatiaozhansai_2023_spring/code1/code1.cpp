//1.���ݱ�ʾ
#if 0
#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

int main()
{
	int a=12;

//��һ�� 
//iomanip�е�setbase����

//����ʹ�ã� 
//	setbase(8);

//��ȷʹ�ã�
	
	cout<<setbase(8)<<a<<endl; 

//������ʹ�ÿ��Ʒ� 
	cout<<oct;
	cout<<a<<endl;


//����ת��
//��һ�� 
	int num=10;
	
	int erjinzhi[8]={0};
	int index=7;
	while(num)
	{
		int temp=num%2;
		erjinzhi[index--]=temp;
		
		num/=2;
	} 
	
	for(auto x:erjinzhi)
	cout<<x;
	cout.put('\n');

//������
	string s1;
	
	num=10;
	while(num)
	{
		s1=char((num%2)+'0')+s1;
		num/=2;	
	}
	
	while(s1.size()<8)
	{
		s1='0'+s1;		
	}
	
	cout<<s1<<endl;	

	return 0;
}
#endif


//2.����
#if 0
#include <iostream>

using namespace std;

int main()
{
	int year;
	cin>>year;
	
	if((year%4==0&&year%100!=0)||year%400==0)
	cout<<"������";
	else
	cout<<"��������"; 

	return 0;
}
#endif 


//3.���ﵥ 
#if 0
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

const int MAXN=50;

int main()
{
	ifstream fin("3.txt");
	
	valarray<double> arr1(MAXN);
	valarray<double> arr2(MAXN);
	
	int index=0;
	while(!fin.fail())
	{
		fin>>arr1[index];
		fin>>arr2[index];

		++index;
	}
	
//	for(auto x:arr1)
//	{
//		cout<<x<<endl;
//	}

	for(int i=0;i<MAXN;i++)
	{
		if(arr2[i]<10)
		arr2[i]*=0.1;
		else
		arr2[i]*=0.01;
	}
	
//	for(auto x:arr2)
//	{
//		cout<<x<<endl;
//	}

	valarray<double> arr3(MAXN);
	arr3=arr1*arr2;
	
	double sum=arr3.sum();
	
	cout<<sum;

	return 0;
}  
#endif


//4.���� 
#if 0
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string show(int *p);

int main()
{
	ifstream fin("4.txt",ios_base::in);
	
	int getdata[10][32]={0};
	int ir=0,ic=0;
	
	while(!fin.eof())
	{
		fin>>getdata[ir][ic++];
		
		if(ic==32)
		{
			ic=0;
			++ir;
		}
	}
	
	fin.close(); 
	
//	for(int i=0;i<10;i++)
//	{
//		for(int j=0;j<32;j++)
//		{
//			cout<<getdata[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	//��ʾ��num+1������ 
	for(int num=0;num<10;num++)
	{
		//ĳ�����ֵĶ����������s1 
		string s1;
		s1=show(getdata[num]);
		
		//16�У�ÿ��16λ��ʾ���� 
		for(int hang=0;hang<16;hang++)
		{
			for(int lie=hang*16;lie<hang*16+16;lie++)
			cout<<s1[lie];
			
			cout<<endl;
		}
		
		cout<<endl<<endl;
	} 

	return 0;
}

string show(int* p)
{
	string str1;
	string str2;
	
	for(int i=0;i<32;i++)
	{		
		int temp=p[i];
		
		if(temp<0)
		{
			temp+=256;		
		}
		
		//ÿ��ʮ��������ת��Ϊ�������� 
		while(temp)
		{
			str1=char(temp%2+'0')+str1;
			temp/=2;	
		}
		
//		cout<<str1<<endl;
		
		while(str1.size()<8)
		{
			str1='0'+str1;
		}
		
		str2+=str1;	
		
		//***ע***��������д 
		str1.clear();	
	}
		
	return str2;
}
//���飺���ǽ������ȴ���ã��ٽ������������
//�����Ƚϼ�� 
#endif


//5.�ֽ������� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

const int N=2e7;
int zhishu[N];
int zhishu2[N];
void getzhishu(void);

int main()
{
	getzhishu();
	
//	for(auto x:zhishu)
//	cout<<x<<' ';
	
//	int index=0;
//	for(auto x:zhishu)
//	{
//		if(x==1)
//			cout<<index<<' ';
//		
//		++index;
//	}

	int index=0;
	for(int i=0;i<N;i++)
	{
		if(zhishu[i])
		{
			zhishu2[index++]=i;
		}
	}

//	for(auto x:zhishu2)
//	cout<<x<<' ';

	int a,b;
	cin>>a>>b;
	
	int count=0;
	for(int i=a;i<=b;i++)
	{		
		//�����������������0��ʼ������
		//��ֵС�ڵ���i		
		for(int j=0;zhishu2[j]<=i;j++)
		{
			int temp=a;

				while(temp%zhishu2[j]==0)
				{
					count++;
					
					temp/=zhishu2[j];
				}
			
		}
	}
	
	cout<<count;

	return 0;
}
//����������һ�� 
//�ж�n�Ƿ�Ϊ������ֻ���2��n-1ö��
//�Ƿ������ܹ���n�������� 
#if 0
void getzhishu(void)
{
	zhishu[0]=2;
	int index=1;
	bool flag=1;
	for(int i=3;i<999;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{	
				flag=0;
				break;
			}
		}
		
		if(flag)
		{
			zhishu[index++]=i;
		}
		
		flag=1;
	}
}
#endif
//������������˹����ɸ��(ɸѡ��)
#if 1
//��2��ʼ��N����Ȼ���������������� 
//Ȼ��2�����ܱ�2�����������Ϊfalse 
//��3�����ܱ�3�����������Ϊfalse 
//�Դ�����
//�������������������ֵ������������ 
//��������ĳ��������ĳ��������Ӧ��ֵ�������Ƿ�Ϊ���� 
void getzhishu(void)
{
	//������ֵ�����Ϊ1 
	fill(zhishu,zhishu+N,true);
	
	//0��1��������������ȱ�Ǻ� 
	zhishu[0]=zhishu[1]=false;
	
	//������2��ʼ������N/2 
	//���ж�1~21����iö�ٴ�2��10 
	for(int i=2;i<=N/2;i++)
	{
		//�������i������ 
		if(zhishu[i])
		{
			//��i�����ܱ�i�����������Ϊfalse 
			for(int j=2*i;j<=N;j+=i)
			{
				zhishu[j]=false;
			}
		}
	}	
	
	return; 
}
#endif 
#endif 


//6.ʮ����ת�����������
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ʮ���Ƶ���N��ת����base���Ƶ��� 
	int N,base;
	cin>>N>>base;

	
	//����ȡ�൹�����ⲽ��һ��Ҫ�еģ�
	//����ʮ���Ƶ�10����16ȡ�����10������'0'��
	//�޷���ʾ��'10'�����Բ�����string���������� 
	//ֻ����int�͵���������� 
	
//	string num;
//	int temp=N;
//	while(temp)
//	{
//		num=char(temp%base+'0')+num;
//		temp/=base;
//	}
	
	
	int num[32]={0};
	int temp=N;
	int index=31;
	while(temp)
	{
		num[index--]=temp%base;
		temp/=base;
	}	
	 
	for(auto x:num)
	cout<<x;	

	cout<<endl;
	
	//��10�������ϵĽ�������λ������ĸ��ʾ�Ĵ��� 
	string snum;
	
	for(int i=0;i<32;i++)
	{
		#if 0
		if(base<10)
			snum+=num[i]+'0';
		else
		{
			if(num[i]<10)
			snum+=num[i]+'0';
			else
			snum+=num[i]-10+'A';//***	
		}
		#endif
		
		//��д��
		if(num[i]<10)
			snum+=num[i]+'0';
		else
			snum+=num[i]-10+'A';
	}
	
	cout<<snum; 
	
	return 0;
}
#endif 


//7.�������ת��Ϊʮ����
#if 0
#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

int main()
{
	//base���Ƶ���N��ת����ʮ���Ƶ��� 
	int base;
	string N;
	cin>>base>>N;
	
	//��Ȩչ�� 
	int num=0;	
	for(int i=0;i<N.size();i++)
	{
		if(N[i]<='9')
			num+=(N[i]-'0')*pow(base,N.size()-1-i);
		else
			num+=(N[i]-'A'+10)*pow(base,N.size()-1-i);
	}
	
	cout<<num;
	
	return 0;
}
#endif 



//8.������
#if 0
#include <iostream>
#include <string>
#include <cmath> 
#include <algorithm>
using namespace std;

int getnum(void);

int main()
{
	int num = getnum();
	
	//��������0����ֱ�ӱ�����0�� 
	if(num==0)
	{
		cout<<0;
		return 0; 
	}
	
//	cout<<num;

	char temp[11]={'\0'};
	sprintf(temp,"%d",num);
	
	string s1(temp);
	string s2(s1.size(),' ');//***ע1*** 
	reverse_copy(s1.begin(),s1.end(),s2.begin());
	
//ע1��
//������Ϊ���ܸ��ݷ���ֵ����Ŀ�������ĳ��ȣ�
//�������һ��ʼ��Ҫ����λ�ã��������� 
//terminate called after throwing an instance of 'std::out_of_range'
//���н׶εĴ��� 

 
//	cout<<s1<<" "<<s2<<endl;
		
	int count=0;
	
	//***ע***һ��������λ����Ϊ0 
	while(s2[0]==0||s1!=s2)
	{
		int n1=stoi(s1);
		int n2=stoi(s2);
		int n3=n1+n2;
		
//		cout<<n1<<" "<<n2<<" "<<n3<<endl;
		
		sprintf(temp,"%d",n3);
		s1.clear();
		s2.clear();
		
		s1=temp;
		s2.resize(s1.size());//***ע1*** 
		reverse_copy(s1.begin(),s1.end(),s2.begin());
		
		count++;
		
		if(count>30)
			break;
	}
	
	cout<<(count<=30?count:-1);

	return 0;
}
int getnum(void)
{
	//base���Ƶ���N��ת����ʮ���Ƶ��� 
	int base;
	string N;
	cin>>base>>N;
	
	//��Ȩչ�� 
	int num=0;	
	for(int i=0;i<N.size();i++)
	{
		if(N[i]<='9')
			num+=(N[i]-'0')*pow(base,N.size()-1-i);
		else
			num+=(N[i]-'A'+10)*pow(base,N.size()-1-i);
	}
	
	return num;
}
#endif 


//9.ͳ�Ƶ��ʸ���
//��һ����vector<string>������
#if 0
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <cctype>

//using namespace std;

using std::string;
using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	string target;
	
	cin>>target;	
	//��transform()��tolower()���ַ���ת��ΪСд 
	//***ע***
	//::tolower��ʾʹ��ȫ�ֵ�tolower���� 
	transform(target.begin(),target.end(),
	target.begin(),tolower);
	
	
	string temp;
	vector<string> vs;
	while(1)
	{
		cin>>temp;
		transform(temp.begin(),temp.end(),
		temp.begin(),::tolower);//���ǰ��д��using namespace std
		//�˴���������д������д(int (*)(int))tolower 



		vs.push_back(temp);
		
		//***		
		if(cin.peek()=='\n')
		{
			break;
		}
	}
	
//	for(auto x:vs)
//	cout<<x<<endl;

	int count=0;
	bool flag=1;
	vector<string>::iterator save; 

                        //***����ʹ��<����� 
	for(auto i=vs.begin();i<vs.end();i++)
	{
		if(*i==target&&flag)
		{
			save=i;
			count++;
			flag=0;
		} 
		else if(*i==target)
		{
			count++;
		}
		
	}
	
	cout<<count<<endl<<save-vs.begin();
	
	return 0;
}
#endif 
//��������ȡ�� 
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int cal_weizhi(string , int);

int main()
{
	string target;
	
	cin>>target;	
	//��transform()��tolower()���ַ���ת��ΪСд 
	//***ע***
	//::tolower��ʾʹ��ȫ�ֵ�tolower���� 
	transform(target.begin(),target.end(),
	target.begin(),::tolower);
	
	//���ĵ����з� 
	cin.get();
	
	string src;
	getline(cin,src);
	transform(src.begin(),src.end(),
	src.begin(),::tolower);
		
//	cout<<src<<endl;

	int len=target.size(); 
	string sub;
	
	bool flag=1;
	int count=0;
	int save;
	
	//������ָ��i����ָ��j����ָ��ӿ��len���� 
	for(int i=0;i+len<=src.size();i++)
	{
		sub=src.substr(i,len);
		
		if(target==sub&&flag)
		{
			count++;
			save=cal_weizhi(src,i);
			flag=0;
		}
		else if(target==sub)
		{
			count++;
			
		}
	}
	
	cout<<save<<endl<<count;
	
	return 0;
}
int cal_weizhi(string s, int pos)
{
	int weizhi=0;
	
	for(int i=0;i<pos;i++)
	{
		if(s[i]==' ')
		weizhi++;
	}
	
	return weizhi;
}
#endif 


//10.���� 
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	string res;
	
	char temp;
	for(int i=0;i<str.size();i++)
	{
//		if(isdigit(str[i]))//***ע***���ַ���0~9 
//		{
//			temp=str[i-1];
//			//push_back()������֧������Ĺ��� 
//			res.append(str[i]-'0',temp);
//		}

		if(isalpha(str[i]))
		{
			if(isdigit(str[i+1]))//***ע***���ַ���0~9 
			{
				temp=str[i];
				//push_back()������֧������Ĺ��� 
				res.append(str[i+1]-'0',temp);
			}
			else
			res.push_back(str[i]);		
			
		}
	}
	
	cout<<res;

	return 0;
}
#endif


//11.��־ͳ��
//��������ȡ�� 
#if 0
#include <iostream> 
#include <algorithm>
using namespace std;

typedef long L;

typedef struct
{
	L ts;
	L id;
}dataTypeDef; 

bool mycompare(dataTypeDef,dataTypeDef);

int main()
{
	//����N��ʱ�䳤��D,K���� 
	L N,D,K;
	cin>>N>>D>>K;
	
	//����������������ʾʱ�䣬����ɿռ�ܴ���˷� 
//	L (*log)[2]=new L [N][2];
//		
//	for(L i=0;i<N;i++)
//	{
//		cin>>log[i][0]>>log[i][1];
//	}
	
	//***ע*** 
	//������Ҫ��ÿ�е����ݽ��дӴ�С���������
	//�����Ķ�ά��������ݵķ��������� 
	

	dataTypeDef* log=new dataTypeDef[N]{{0},{0}};
	
	for(L i=0;i<N;i++)
	{
		cin>>log[i].ts>>log[i].id;
	}	
	
	sort(log,log+N,mycompare);
	
//	for(L i=0;i<N;i++)
//	{
//		cout<<log[i].ts<<" "<<log[i].id<<endl;	
//	}

	L* zan=new L [100010]{0}; 
	vector<L> retie;
	for(int i=0,j=0;j<N;j++)
	{
		while(log[j].ts-log[i].ts>=D)
		{
			zan[log[i].id]--;
			i++;
		}
		
		zan[log[j].id]++;
		
		if(zan[log[j].id]>=K)
			retie.push_back(log[j].id);
	}
		
	sort(retie.begin(),retie.end());	

	//***
	auto last=unique(retie.begin(),retie.end());
	retie.erase(last,retie.end());
	//��⣺
	//ʹ��unique()�󱣳�ʣ��Ԫ�ص����˳��
	//�Ҳ����������������С��
	//ָ��Χ�����߼���β�������β֮��Ԫ�صĵ�����
	//��Ȼ�ɽ����ã���Ԫ������ӵ��δָ��ֵ��
	//���� unique ����ʱ����������� erase ��Ա������
	//������δָ��ֵ����С�����������С��
	//��ƥ�����µ��߼���С��
	 
	for(auto x:retie)
	{
		cout<<x<<endl;
	}

	return 0;
}
bool mycompare(dataTypeDef d1,dataTypeDef d2)
{
	bool res;
	
	if(d1.ts<d2.ts)
	{
		return true;
	}
	else if(d1.ts==d2.ts&&d1.id<d2.id)
	{
		return true; 
	}
	else
	return false;
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


//12.��Ƭ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int kapian[10];
	fill(kapian,kapian+10,2021); 
	
	int count=1;
	char temp[10]={'\0'};
	bool flag=1;
	while(flag)
	{
		sprintf(temp,"%d",count);
		
		for(int i=0;temp[i];i++)
		{
			if(--kapian[temp[i]-'0']<=0)
			flag=0;
		}
		
		count++;
	}
	
	cout<<count-1;

	return 0;
}
#endif


//13.�������
#if 0
#include <iostream>

using namespace std;

typedef long long L;
const L MAXN=5e4;

//int yanghui[MAXN][MAXN];
int main()
{
	L num;
	cin>>num;
	
	//�������䶯̬�ڴ棬���кܴ�Ŀռ��˷ѣ�
	//���Ҷ�ά����Ҳ���ܴܺ󣬷������ɷ����ڴ�ʧ�� 
//	int (*yanghui) [MAXN]=new int [MAXN][MAXN];
	
	
	//����һ���������ε�����ռ䣬ʹ������ֵ1~MAXN�� 
	//��i��ʹ������ֵ1~i 
	L **yanghui=new L* [MAXN+1];
	
	for(L i=1;i<MAXN+1;i++)
	{
		yanghui[i]=new L [i+1]{0};
	} 
	
	//��i�� 
	for(L i=1;i<MAXN+1;i++)
	{
		yanghui[i][1]=yanghui[i][i]=1;
		
		//��i�е�2������ʼ����������2�������� 
		for(L j=2;j<=i-1;j++)
		{
			yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j];
		}
	} 

//	for(L i=1;i<70;i++)
//	{
//		for(L j=1;j<=i;j++)
//		{
//			cout<<yanghui[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
//�鿴�������֪��70�����Ҿͷ���������� 
	
	L count=1;
	for(L i=1;i<MAXN+1;i++)
	{
		for(L j=1;j<=i;j++)
		{
			if(yanghui[i][j]==num)
			{
				cout<<count;
				return 0;
			}
			
			++count;
		}
	}
	
	cout<<-1; 

	return 0;
}
//�������룺71523144
//���������4956
//************��ʱ����ʱ9��****** 
//�������룺515927503
//���������515959629
//*******************************
//��������������ǵ�λ�����ڵ�100�� 
//���ı����޸�Ϊj��1��100 
//���飺
//��ʹ��������м����������������������ǵ�����
//�����Կ���δ�����������Ϊ�������롣 
#endif 
//13.��
#if 0
#include <iostream>

using namespace std;

typedef long long L;
const L MAXN=1e4;		//�ĳ�5e4�����в������붼�ᳬʱ 

int main()
{
	L num;
	cin>>num;

	L **yanghui=new L* [MAXN+1];
	
	for(L i=1;i<MAXN+1;i++)
	{
		yanghui[i]=new L [i+1]{0};
	} 
	
	L count=0;
	
	//��i�� 
	for(L i=1;i<MAXN+1;i++)
	{
		//***
		++count;		
		yanghui[i][1]=1;
		
		if(num==1)
		{
			cout<<1;
			return 0;
		}
		
		//��i�е�2������ʼ����������2�������� 
		for(L j=2;j<=i-1;j++)
		{
			//***
			++count;

			
			yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j];
			
			if(yanghui[i][j]==num)
			{
				cout<<count;
				return 0;
			}
			
		}
		
		//***
		if(i>1)
		{
			++count;
			yanghui[i][i]=1;
		}
		
	} 
	
	cout<<-1; 

	return 0;
}
//�������˫��forѭ��ȥ�������ж������Ƶ�ǰ���
//˫��forѭ���ڣ�����ʱ�临�Ӷ�
//�����ǳ�ʱ�� 
//const L MAXN=5e4;
//************��ʱ����ʱ6s******* 
//�������룺515927503
//���������515959629
//*******************************
#endif 


//14.������Ϸ
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int);
int main()
{
	//����n�����m����k������
	int n,m,k;
	cin>>n>>m>>k;
	
	int res[10]{0};
	int res_index=0;
	
	while(n!=0||m!=0||k!=0)
	{
		int num=1;
		bool flag=0;
		int paishou=0;
		
		for(int i=1;i<=n;i++)
		{
			//�����ֵ����������ֵ����m 
			if((flag=check(num))&&i==m)
			{
				if(++paishou==k)
				{
					res[res_index++]=num;
					goto NEXT;
				}
			}	
			
			flag=0;
			++num;			
		}
		
		while(1)
		{
					
			for(int i=n-1;i>0;i--)
			{
				//�����ֵ����������ֵ����m 
				if((flag=check(num))&&i==m)
				{
					if(++paishou==k)
					{
						res[res_index++]=num;
						goto NEXT;
					}
				}	
				
				flag=0;
				++num;
				
			}
			
			for(int i=2;i<=n;i++)
			{
				//�����ֵ����������ֵ����m 
				if((flag=check(num))&&i==m)
				{
					if(++paishou==k)
					{
						res[res_index++]=num;
						goto NEXT;
					}
				}	
				
				flag=0;
				++num;
				
			}		
		
		}
			
NEXT:		cin>>n>>m>>k;
	} 
	
	for(auto x:res)
	{
		if(x!=0)
		cout<<x<<endl; 
	}
	
	return 0;
}
bool check(int num)
{
	bool flag=0;
	
	if(num%7==0)
	{
		flag=1;
		return flag;
	}
	
	char temp[11]={'\0'};
	sprintf(temp,"%d",num);
	
	if(find(temp,temp+11,'7')!=temp+11)
	flag=1;	
	
	return flag;
}
#endif 


//15.��������
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<int> v(n+1);
	
	int input=-1;
	transform(v.begin(),v.end(),v.begin(),
	[&input](int a){return ++input;});

//	for(auto x:v)
//	cout<<x<<endl;

	
	int num=1;
	//������ֵѭ������ 
	for(int index=1;v.size()!=2;index++)
	{
		if(index>n)
			index=1;
		
		if(num==3)
		{
			v.erase(v.begin()+index);
			n--;
			num=1;
			index--;//***
		}
		else
		{
			num++;
		}
			
	}
	
	cout<<v[1];
	
	return 0;
}
#endif 
//����������STL��queue����
#if 0
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}	
	
//	cout<<q.size();
	
	int num=1;
	while(q.size()!=1)
	{
		if(num==3)
		{
			q.pop();
			num=0; 
		}
		else
		{		
			//***����Ԫ���ƶ�������β��*** 
			q.push(q.front());
			q.pop();
		}
		
		//������Ԫ�ض�Ӧ�ı�ŵ�����˽к� 
		num++;
	}
	
	cout<<q.front();
	
	return 0;
}
#endif
//����������ʣ�vector��deque (vector�����)
//Ԫ�ؿ��ٲ�����ɾ����list (deque������ͷ��βԪ�صĲ�����ɾ��)  


//16.����ѡ����
#if 0
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	queue<int> q;
	vector<int> res;
	
	while(n!=0||m!=0)
	{	
		for(int i=1;i<=n;i++)
		{
			q.push(i);
		}	
		
		//	cout<<q.size();
		
		int num=1;
		while(q.size()!=1)
		{
			if(num==m)
			{
				q.pop();
				num=0; 
			}
			else
			{		
				//***����Ԫ���ƶ�������β��*** 
				q.push(q.front());
				q.pop();
			}
			
			//�к� 
			num++;
		}
		
		res.push_back(q.front());
		
		//��ն����е�Ԫ�� 
		q.pop();
		
		cin>>n>>m;
	}
	
	for(auto x:res)
		cout<<x<<endl; 

	return 0;
}
#endif 


//17.�Ȳ��������� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN=5e4;
bool sushu[MAXN]; 

void create_sushu(void);
int main()
{
	create_sushu();
	
//	LL index=0;
//	for(auto x:sushu)
//	{
//		if(x==true)
//		cout<<index<<" ";
//		
//		++index;
//	}

	//	LL index=0;
//	for(auto x:sushu)
//	{
//		if(x==true)
//		cout<<index<<" ";
//		
//		++index;
//	}

//	int len=1;
	int gongcha=0;
	int gongcha2;
	int count=1;
	
	int gc_MAX=MAXN;
	
	for(LL index=1;index<=MAXN;index++)
	{
		for(gongcha=1;gongcha<MAXN;gongcha++)
		{
			count=1;
			gongcha2=gongcha; 
			
			while((index+gongcha2<MAXN)&&sushu[index+gongcha2])
			{
				count++;
//����д���� 
//				gongcha*=2;
//������:30 60 120 240 
				
//��ȷд���� 
				gongcha2+=gongcha;
//����:30 60 90 120  
				if(count==10)
				goto RES;
			}
		}
		
		//���ڹ���ܴ�����Ҳ���ܷ���Ҫ������Ҫ 
		//***�ҳ������������Сֵ***	
RES:	
		gongcha<gc_MAX?gc_MAX=gongcha:gc_MAX;
	}

	cout<<gc_MAX;

	return 0;
}
void create_sushu(void)
{
	fill(sushu,sushu+MAXN,1);
	
	sushu[0]=sushu[1]=0;
	
	for(LL i=2;i<MAXN/2;i++)
	{
		if(sushu[i]==true)
		{
			for(LL j=2*i;j<MAXN;j+=i)
			{
				sushu[j]=false;
			}
		}
	}
	
	return;
}
//ʱ�临�Ӷ�̫�ߣ�������82�� 
#endif 
//17.��
//�޸�һ����ģ�黯��̣��ô��ǲ�����ѭ�������ö������
//Ȼ���ڲ���������ʱ���������� 
//�޸Ķ��� 
//˼��������϶��Ǳ����ɵ���������Ԫ��С��
//һ����ȷ����������˿��ǽ�����ѭ���ŵ�������,
//�ô��ǲ�������ѭ���涨�����ѭ��������ֵ 
//***������⣺*** 
//���ѭ����sushu���������ֵ->Ѱ�ҷ���Ҫ���
//��С��ʼ�������� 
//���ѭ����gongcha->Ѱ�ҷ���Ҫ���
//��С���� 
#if 0
#include <iostream>

using namespace std;

typedef long long LL;
const int MAXN=5e4;
bool sushu[MAXN]; 

void create_sushu(void); 
bool isOK(LL num,int gc);

int main()
{
	create_sushu();
	
	int gongcha;
	bool flag=0;
	for(gongcha=1;   ;gongcha++)
	{
		for(LL index=2;index<MAXN;index++)
		{
			if(flag=isOK(index,gongcha))
			{
				break;
			}
		}
		
		if(flag)
			break;
	}
	
	cout<<gongcha;
	
	return 0;
}
void create_sushu(void)
{
	fill(sushu,sushu+MAXN,1);
	
	sushu[0]=sushu[1]=0;
	
	for(LL i=2;i<MAXN/2;i++)
	{
		if(sushu[i]==true)
		{
			for(LL j=2*i;j<MAXN;j+=i)
			{
				sushu[j]=false;
			}
		}
	}
	
	return;
}
bool isOK(LL num,int gc)
{
	for(int i=1;i<=9;i++)
	{
		if(sushu[num+gc*i])
			continue;
		else
			return false;
	}
	
	return true;
}
#endif 


//18.��ȫ��������Ȩֵ
//ĳ��ȫ��������N��Ԫ�� 
//�������deep=log2(N)+1;
//ĳ�����ֵi(iΪ1��deep)��Ԫ�صı���Ǵ�pow(2,i-1)��pow(2,i)-1 


//19.��4���������Լ������С������
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	int gongyue=__gcd(__gcd(__gcd(a,b),c),d);
	int gongbei=a*b*c*d/gongyue;
	
	cout<<gongyue<<endl<<gongbei;

	return 0;
}
#endif 


//20.����ڷ�
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL n=2021041820210418;

int main()
{
	vector<LL> yinzi;

//	for(LL i=1;i<=n/2;i++)

//***ע***
//�ĳ���������ٺܶ�ʱ�临�Ӷ� 
	for(LL i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i!=i)
			{
				yinzi.push_back(i);
				yinzi.push_back(n/i);
			}
			else
			yinzi.push_back(i);
		}
	}

	sort(yinzi.begin(),yinzi.end());

//	for(auto x:yinzi)
//	cout<<x<<" ";
//	cout<<endl;

	LL count=0;

	for(auto i=yinzi.begin();i!=yinzi.end();i++)
	{
		for(auto j=yinzi.begin();j!=yinzi.end();j++)
		{
			if(n%(*i**j)==0)
			{
				++count;
			}
		}	
	}
	
	cout<<count;
	
	return 0;
}
#endif 


//21.set<pair< pair<int,int>,int> > s 
//����set������Ԫ�صĴ��˳��
#if 0
#include <iostream>
#include <set> 
using namespace std;

int main()
{
	set<	pair<pair<int,int>,int> >se;
	
	pair<pair<int,int>,int> pa;
	
	pa.first.first=1;
	pa.first.second=3;
	pa.second=2;

	pair<pair<int,int>,int> pb;
	
	pb.first.first=1;
	pb.first.second=2;
	pb.second=3;

	se.insert(pa);
	se.insert(pb);
	
	for(auto it=se.begin();it!=se.end();it++)
	{
		cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
	}

	return 0;
}
//���ۣ�set�е�Ԫ��pair<pair<int,int>,int>
//����˳��Ҳ��ѭ��С���������׸���Աֵ��ͬ����Ƚ�
//��һ����Ա��ֵ 
#endif 


//22.��������
#if 0
#include <iostream>

using namespace std;

bool test(int num);

int main()
{		
	int begin;	
	bool flag=false;
	
	for(begin=1;  ;begin++)
	{
		flag=test(begin);
		
		if(!flag)
			continue;
		else
			break;
	}
	
	cout<<begin;

	return 0;
}
bool test(int num)
{
	int sum=0;
	
	while(sum<236)
	{
		sum+=num;
		num++;
	}
	
	return (sum==236);
}
#endif


//23.��ȯ��Ŀ
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int begin=10000;
	int end=99999;
	int count=0;
	
	char tmp[6];
	fill(tmp,tmp+6,'\0');
	
	for(int i=begin;i<=end;i++)
	{
		sprintf(tmp,"%d",i);
		
		if(find(tmp,tmp+6,'4')!=tmp+6)
		{
			continue;
		}
		else
		count++;

//Ϊʲô�����䲻��Ҫ��			
//		fill(tmp,tmp+6,'\0');
 
	}
	
	cout<<count;

	return 0;
}
#endif 


//24.�������sprintf() 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int begin=101;
	int end=1000;
	int count=0;
	
	char tmp[6];
	fill(tmp,tmp+6,'\0');
	
	for(int i=end;i>=begin;i--)
	{
		
		for(int i=0;i<6;i++)
		{
			if(tmp[i]=='\0')
			cout<<'\\';
			else
			cout<<tmp[i];
		}
		cout<<endl; 
		
		
		sprintf(tmp,"%d",i);
		
		if(find(tmp,tmp+6,'4')!=tmp+6)
		{
			continue;
		}
		else
		count++;

//Ϊʲô�����䲻��Ҫ��			
//		fill(tmp,tmp+6,'\0');

//����tmp�����д��Ԫ��
		for(int i=0;i<6;i++)
		{
			if(tmp[i]=='\0')
			cout<<'\\';
			else
			cout<<tmp[i];
		}
		cout<<endl; 
		
//���ͣ�
//1. 
//���ڵ�����ݼ������֣���ռ�õ��ַ����鳤��ֻ��
//Խ��Խ����Խ��Խ�̣������ȱ仯ʼ����һλһλ�ر䣬
//���Կ���ͨ���ڽ���ѭ��ǰ�ȸ��ÿ��ַ��ȱ�̼���
//�Է�ֹ���ֿ��ַ����滹�������ַ��������
//2.
//ÿ��ѭ��ʱʹ�õ��ַ����飬�䳬�����ֳ��ȵ�
//�ռ�ֻ�����ֺ��һ���ռ��ÿ��ַ���䣬����
//�ռ����ݲ��䣬����sprintf()�����Ĺ��ܡ� 

//������⣺ 
//����ÿ��ѭ��ʱʹ�õ��ַ����飬�䳬�����ֳ��ȵ�
//�ռ䶼�ÿ��ַ�����ˣ�������sprintf()�Ĺ��� 
	}
	
	cout<<count<<endl;
	
	sprintf(tmp,"%d",1); 
	
	for(int i=0;i<6;i++)
	{
		if(tmp[i]=='\0')
		cout<<'\\';
		else
		cout<<tmp[i];
	}

	return 0;
}
#endif 


//25.ѡ��
#if 0
#include <iostream> 
#include <algorithm>
#include <set>
using namespace std;

int sushu[10010];
void generate_sushu(void);
int cal(const int* p,int); 

int main()
{
	generate_sushu();
	
	int n,k;
	cin>>n>>k;
	
	int* getdata=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>getdata[i];
	}
	
	int count=0;
	int sum;
	set <int> s;
	
	sort(getdata,getdata+n);
	
	do
	{
//		for(int i=0;i<n;i++)
//		{
//			cout<<getdata[i]<<" ";
//		}
//		cout<<endl<<endl;

		sum=cal(getdata,k);
		
		//ȥ�� 
		s.insert(sum);	


	}while(next_permutation(getdata,getdata+n));
	
	
	//***�����Ĵ���*** 
	//for_each()���lambda���� 
	for_each(s.begin(),s.end(),
	[&count](int a){	if(sushu[a])	count++;	});	

	cout<<count;

	return 0;
}
void generate_sushu(void)
{
	fill(sushu,sushu+10010,1);
	
	sushu[0]=sushu[1]=0;
	
	for(int i=2;i<10010/2;i++)
	{
		if(sushu[i]==1)
		{
			for(int j=2*i;j<10010;j+=i)
			{
				sushu[j]=0;
			}
		}
	}
	
//	for(auto x:sushu)
//	{
//		cout<<x<<" ";
//	}
}
int cal(const int* p,int k)
{
	int sum=0;

	for(int i=0;i<k;i++)
	{
		sum+=p[i];
	}	
		
	return sum;
}
//4 3
//3 7 12 19
#endif


//26.������ʽ
//���⣺ÿ����ʽ�Ļ�������������ô����,
//������ô������������ 
#if 0
#include <iostream>

using namespace std;

//����0~9��Ӧ�Ļ���� 
int huochai[10]={6,2,5,5,4,5,6,3,7,6}; 

const int MAXN=100;

int cal(int num);

int main()
{
	int n;
	cin>>n;
	
	int count=0;
	
	for(int a=0;a<MAXN;a++)
	{
		for(int b=0;b<MAXN;b++)
		{
			if(cal(a)+cal(b)+cal(a+b)==n-4)
				count++;
		}
	} 
	
	cout<<count;

	return 0;
}
int cal(int num)
{
	int sum=0;
	
	//***ע***
	//����char���飬���ֳ�ʼ��һ��Ԫ�غ������Ԫ��
	//���Զ���ʼ��Ϊ���ַ� 
	char tmp[6]={'\0'};

//	for(auto x:tmp)
//	{
//		if(x=='\0')
//		cout<<'\\'<<" ";	
//		else
//		cout<<x;
//	}

	sprintf(tmp,"%d",num);
	
//����д���� 
//	for(int i=0;tmp[i];i++)
//tmp[i]��Ϊ0����Ϊ\0��ѭ��������ֹ 


//��ȷд���� 
	for(int i=0;tmp[i]!='\0';i++)
	{
		sum+=huochai[tmp[i]-'0'];
	}
	
	return sum;
}
#endif


//27.���ָ���ch�ͱ���������0���ַ�'\0' 
#if 0
#include <iostream>

using namespace std;

int main()
{
	char ch=0;
//	char ch='\0';
	
	printf("%d%c",ch,ch);
	printf("aabbcc");
	printf("aa");
	
	cout.put('\n');
	
	cout<<"aa"<<'\0'<<"bb";
	
	return 0;
}
#endif


//28.������ 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
	int a;
	int b;
	double l;
}numInfoTypedef;

int main()
{
	int A,B,L;
	cin>>A>>B>>L;
	
	double t1=(double)A/B;
	double t2;
		
	vector<numInfoTypedef> vn;
	
	numInfoTypedef tmp;
	
	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=L;j++)
		{
			//a��bҪ���� 
			if(__gcd(i,j)!=1)
			continue;
			
			//a/bҪ���ڵ���A/B 
			t2=(double)i/j;
			if(t2<t1)
			continue;
			
			tmp.a=i;
			tmp.b=j;
			tmp.l=t2;			
			
			vn.push_back(tmp); 
		}
	}
	
	double cha=999;
	int pos;
	for(int i=0;i<vn.size();i++)
	{
		double t=vn[i].l-t1;
//		cha=(t<cha)?t:cha;
		if(t<cha)
		{
			cha=t;
			pos=i;
		}
	}
	
	cout<<vn[pos].a<<" "<<vn[pos].b;

	return 0;
}
#endif
//28.��
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int A,B,L;
	cin>>A>>B>>L;
	
	double t1=(double)A/B;
	double t2;
		
	double cha=999;

	int ta,tb;

	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=L;j++)
		{
			//a��bҪ���� 
			if(__gcd(i,j)!=1)
			continue;
			
			//a/bҪ���ڵ���A/B 
			t2=(double)i/j;
			if(t2<t1)
			continue;
			
			if(t2-t1<cha)
			{
				ta=i;
				tb=j;
				cha=t2-t1;
			}
			
		}
	}
	
	cout<<ta<<" "<<tb;

	return 0;
}
#endif 


//29.�����
#if 0
#include <iostream>

using namespace std;
int f(int n,int m);
int main()
{
	int n,m;
	
	cin>>n>>m;
	
	cout<<f(n,m);

	return 0;
} 
int f(int n,int m)
{
	if(n<m)
		return 0;
	if(m==0)
		return 1;
		
	return f(n-1,m-1)+f(n-1,m);
}
#endif


//30.��״�� 
//����ĵݹ�����
//�ݹ����ֹ����Ϊ��1���ͻ�1֧ 
#if 0
#include <iostream>

using namespace std;

int dajiu(int,int,int);

int main()
{
	int res=dajiu(2,5,10);

	cout<<res;

	return 0;
}

int sum;

int dajiu(int wine,int store,int flower)
 {
 	if(store>0)
 	{
	 	dajiu(wine*2,store-1,flower);
	}
	if(flower>0)
	{
		dajiu(wine-1,store,flower-1);
	}
	if(wine==1&&store==0&&flower==1)
	{
		sum++;
	}
	
	return sum;
 }
#endif
//30.������DFS
#if 0
#include <iostream>
#include <string>
using namespace std;

int count;
char str[15];

void dfs(int,int, int, int);

int main()
{
	dfs(2,0,0,0);

	cout<<count;
	
	return 0;
}
void dfs(int wine,int i, int store, int flower)
{
	if(wine<0||store>5||flower>10)
		return;

   if(i == 15 && store == 5 && flower == 10)
	{
    	if(str[14] == 'b' && wine == 0)
		{
			count++;
			
			for(auto x:str)
			{
				cout<<x;
			}
			cout<<endl;
		}
		
		return;
	}

	str[i] = 'a';
	dfs(wine * 2,i + 1,store + 1,flower);	//����һ��
	str[i] = 'b';
	dfs(wine - 1,i + 1,store,flower + 1);	//������һ��
			
}
#endif 


//31.����� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool mark[10];

int main()
{
	char tmp[4]={'\0'};
	
	int j,k;
	for(int i=123;i<=333;i++)
	{
		sprintf(tmp,"%d",i);
		
		//��¼���ֵ����� 
		for(int index=0;tmp[index]!='\0';index++)
		{
			mark[tmp[index]-'0']=1;
		}
		
		//���������0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
			
		j=2*i;
		sprintf(tmp,"%d",j);
		
		//��¼���ֵ����� 
		for(int index=0;tmp[index]!='\0';index++)
		{
			//��֮ǰ�Ѿ���¼�������֣���i�������ֵ���һ�� 
			if(mark[tmp[index]-'0']==1)
				goto NEXT;			
			else
			mark[tmp[index]-'0']=1;
		}
		
		//���������0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
		
		k=3*i;
		sprintf(tmp,"%d",k);
		
		//��¼���ֵ����� 
		for(int index=0;tmp[index]!='\0';index++)
		{
			if(mark[tmp[index]-'0']==1)
				goto NEXT;			
			else
			mark[tmp[index]-'0']=1;
		}	
		
		//���������0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
			
		cout<<i<<" "<<j<<" "<<k<<endl;
		
NEXT:
		fill(mark,mark+10,0);		
	} 

	return 0;
}
#endif
//31.��
//�������Լ�¼���ֳ��ֵ������Ԫ����ͣ�
//���������ǲ���9���Ӷ��ж�1~9ÿ������
//�Ƿ�ֻ������һ�� 
//***ע***
//�÷����о�����
//���������ֵ�λ��֮�Ͳ���9���ǾͲ����� 
#if 0
#include<iostream>
using namespace std;
int main()
{
	int s[10];//����һ�������¼0~9���ֵĴ��� 
	for(int i=123;i<333;i++)
	{
		for(int m=0;m<10;m++)
			s[m]=0;
	
		s[i/100]=1;
		s[i/10%10]=1;
		s[i%10]=1;
	
		int j=i*2;
		s[j/100]=1;
		s[j/10%10]=1;
		s[j%10]=1;
	
		int k=i*3;
		s[k/100]=1;
		s[k/10%10]=1;
		s[k%10]=1;
	
		int sum=0;
	
		for(int m=1;m<10;m++)
			sum+=s[m];
		//��1~9ÿ�����ֳ��ִ������������������9��ÿ�����ֶ�������һ�� 
		if(sum==9) 
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
	return 0;
} 
#endif 


//32.������ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int mark[10];

bool isOK(LL, LL, LL);
int main()
{
	LL N;
	cin>>N;
	
	char tmp[10]={'\0'};
	LL N1;
	int count=0;
	
	for(LL i=1;i<N;i++)
	{
		sprintf(tmp,"%d",i);

		for(int index=0;tmp[index]!='\0';index++)
		{
			mark[tmp[index]-'0']=1;
		}			
		
		N1=N-i;
		
		for(LL j=1;j<100000;j++)
		{
			for(LL k=1;k<j;k++)
			{
				if((double)j/k==N1)
				{
					if(isOK(i,j,k))
					{
						count++;
						cout<<i<<' '<<j<<' '<<k<<endl;
					}

					for(int index=0;tmp[index]!='\0';index++)
					{
						mark[tmp[index]-'0']=1;
					}
					
				}
			}	
		}
		
		fill(mark,mark+10,0);	
	}

	cout<<count;
	
	return 0;
}
bool isOK(LL i, LL j, LL k)
{
	char tmp[10]={'\0'};
	
	sprintf(tmp,"%d",j);

	for(int index=0;tmp[index]!='\0';index++)
	{
		//��֮ǰ�Ѿ���¼�������֣���ֱ����Ϊfalse 
		if(mark[tmp[index]-'0']==1)
		{
			fill(mark,mark+10,0);

			return false;			
		}
		else
		mark[tmp[index]-'0']=1;
	}
	
	sprintf(tmp,"%d",k);

	for(int index=0;tmp[index]!='\0';index++)
	{
		//��֮ǰ�Ѿ���¼�������֣���ֱ����Ϊfalse 
		if(mark[tmp[index]-'0']==1)
		{
			fill(mark,mark+10,0);

			return false;			
		}
		else
		mark[tmp[index]-'0']=1;
	}
	
	int sum=0;
	for(int i=1;i<10;i++)
	{
		sum+=mark[i];
	}
	
	fill(mark,mark+10,0);
	
	return sum==9;
}
//���س�ʱ 
#endif
//32.��
//n=a+b/c
//˼·һ��(�����������˼·)
//��ȷ��a���ٱ���b��c��ֱ���ҵ������������� 
//˼·����
//���ڱ��ʽa+b/c�е�������1~9��ɣ�
//��ô���Զ�1~9����������ϣ�
//Ȼ�������в���+�ź�/�� 
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	string s="123456789";
	string tmp; 
	int i,j,a,b,c,count=0;
	
	do
	{
		//ȡa�ĳ��ȣ���Ϊb��c�����1������a�Ϊ7 
		for(i=1;i<=7;i++)
		{
			//��ȡa 
			tmp=s.substr(0,i); 
			//�ַ����������
			a=stoi(tmp); 
			
			//��a���ڵ���n�����˳�forѭ��
			if(a>=n)
				break; 
			
			//ȡb�ĳ��ȣ�c�����1������9��c�ĳ���
			//�ټ�a�ĳ��� 
			for(j=1;j<=9-1-i;j++)
			{
				tmp=s.substr(i,j);
				b=stoi(tmp);
			
			
				//ȡc�ĳ��� 
				tmp=s.substr(i+j,9-i-j);
				c=stoi(tmp);
				
				if(b%c==0&&n==a+b/c)
					count++; 
				
			}
		}
	
	}while(next_permutation(s.begin(),s.end()));
	
	cout<<count;

	return 0;
} 
#endif 
//32.������ 
//DFS
#if 0
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int n;
int res = 0;
int arr[9] ;
int book[10];
 
int getNum(int s, int e, int* arr) 
{
   int ans = 0;
//   for (int i = s; i <= e; i++) 
//	{
//      ans = ans * 10 + arr[i];
//   }

	int j=0;
	for(int i=e;i>=s;i--,j++)
	{
		ans+=arr[i]*pow(10,j);
	}
   
   return ans;
}
 
int length(int n) 
{
   int len = 0;
   while (n)
	{
      len++;
      n /= 10;
   }
   return len;
}

void dfs(int step)
{
	if(step==9)
	{
		for (int i = 0; i < length(n); i++) 
		{    
         for (int j = i+1; j < 8; j++) 
			{
            if (j - i < 8 - j)
				{
               continue;  //�ٷ����϶����� 
            }
            int a = getNum(0, i, arr);
            int b = getNum(i + 1, j, arr);
            int c = getNum(j + 1, 8, arr);
            
            if (b%c == 0 && a + b / c == n) 
				{
                res++;
          //cout << a << " + " << b << "/" << c << endl;
            }
         }
      }
	}
	
	for(int i=1;i<=9;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			
			arr[step]=i;
			dfs(step+1);
			
			book[i]=0;
		}
	}
}
int main()
{
   cin >> n;
   
   dfs(0); 
   cout << res << endl;
    
   return 0;
}
#endif


//״̬ѹ��dp
//��Ϥ4��λ����
//1.�ж�һ������x�������µ�iλ�Ƿ�Ϊ1
//if(((1<<(i-1))&x)>0)
//2.��һ������x�������µ�iλ��Ϊ1
//x=x|(1<<(i-1))
//3.��һ������x����������ҵĵ�һ��1ȥ��
//x=x&(x-1) 


//33.״̬ѹ��dp���⣺С���� 
//��n*n�������Ϸ�k���������������Թ���
//���ڵ�8�����ӣ���ʹ�����޷��໥�����ķ�������
//˼���� 
//(״̬ѹ���洢�������Ʊ�ʾ״̬��ʮ���ƴ洢״̬) 
//��3*3����Ϊ���������ö����Ʊ�ʾÿ�еķ������
//ÿ�е�����״̬��000��001��010��011��100��101��110��111
//ÿ�еĺϷ�״̬��000��001��010��100��101 
//�ж����ںϷ���
//  !(i&i>>1)Ϊ����Ϸ�
//�ж��м����(�м�Ϸ�)
//  !(a&b)&&!(a&b>>1)&&!(a&b<<1)Ϊ����Ϸ�
//״̬��ʾ��
//dp[i,j,a]��ʾǰi-1�кŷ�����j��������
//��i�кŵĵ�a��״̬�ķ����� 
//״̬���㣺
//dp[i,j,a]=��dp[i-1,j-c[a],b] 
//�ܷ����� 
//ans=��dp[n,k,a]
#if 0
#include <iostream>

using namespace std;

//ͬһ�еĺϷ�״̬���� 
int cnt=0;
//ͬһ�еĺϷ�״̬��
int s[1<<12];
//ÿ���Ϸ�״̬�����Ĺ�����
int num[1<<12];

//��i�кŷ��õĹ�����״̬��a��ǰ1~i-1�кŷ���j������
//            i   j     a 
long long dp[12][144][1<<12];
//dp����ܴ�12*12�����̣���๲��144��������
//һ�е�״̬�����2��12���� 

int main()
{	
	//n*n�����̣���������k 
	int n,k;
	cin>>n>>k;	

	
	//Ԥ����
	//ö��һ�е�����״̬ 
	for(int i=0;i<(1<<n);i++)
	{
		//�ж����ںϷ���
	   if(!(i&i>>1))
		{
			s[cnt++]=i;
		}
		
		//ͳ��ÿ���Ϸ�״̬�����Ĺ�����
		for(int j=0;j<n;j++)
		{
			num[i]+=(i>>j&0x01);
		} 
	} 
	
	//״̬���㣺
	//���Ź���Ҳ��һ�ַ���
	dp[0][0][0]=1;
	
	//ö���к� 
	for(int i=1;i<=n+1;i++)
	{
		//ö�ٹ����� 
		for(int j=0;j<=k;j++)
		{
			//ö�ٵ�i�кŵĺϷ�״̬ 
			for(int a=0;a<cnt;a++)
			{
				//ö�ٵ�i-1�кŵĺϷ�״̬ 
				for(int b=0;b<cnt;b++)
				{
					//��i�кŵ�a���Ϸ�״̬�Ĺ����� 
					int c=num[s[a]]; 
					
					//���Լ����Ź�����������ͬ��Ϊ1
					//�Ҳ�����б�Խ�Ϊ1�����
					if((j>=c)&&!(s[a]&s[b])&&!(s[a]&s[b]>>1)
					&&!(s[a]&s[b]<<1))
					//                ***ע1*** 
					dp[i][j][a]+=dp[i-1][j-c][b]; 
				} 
			}
		}
	} 

//***�ѵ�*** 
//ע1��������j��ȥ��i�кŵ�a���Ϸ�״̬�Ĺ������õ��Ĺ�����
//���ǵ�i-1�кŷŹ�����״̬����1~n-2�кŹ�����j-c������

//�ñ����������Ʒ�������ֵ��dp���ʽ��ϵ�����  


	//��n+1�кŷ�0����������1~n�кŹ�����k������ 
	cout<<dp[n+1][k][0]<<endl; 
	//***ע***
	//�˾��൱��
//	int ans=0;
//	for(int i=0;i<cnt;i++)
//	{
//		ans+=dp[n][k][i];
//	} 
//	cout<<ans<<endl;
	
	return 0;
}
//ÿ�а������ɸ��࣬
//ÿ�����ۼ���һ�еļ�����
//ÿ�е���֮���޹� 

//�����Ʊ�ʾ״̬��ʮ���ƴ洢״̬
//��λ����ɸѡ���Ϸ�״̬��
//��λ�����ж�״̬ת�Ƶ�������
//����ʱÿ�����ۼ���һ�еļ����� 
#endif


//34.�����ά���� 
#if 0
#include<stdio.h>
int main(void)
{
	//��i��j��k���x��y��z�� 
	
	int a[2][2][2],i,j,k;
	
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
			{
				scanf("%d",&a[i][j][k]);
			}
	
	//��ά����Ӧ���ǲ���к��к�	
	//�൱���Ǹ������壬����8�����㣬
	//ÿ�����㶼��һ��ֵ 
	//(0,0,0) (0,0,1)
	//(0,1,0) (0,1,1)
	//(1,0,0) (1,0,1)
	//(1,1,0) (1,1,1) 
			
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
			{
				printf("%5d",a[i][j][k]);
			}
			
}
#endif


//35.�˻ʺ�����
//���ص��㷨 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int count = 0;//������
	
	for (int q1 = 0; q1 < 8; q1++)
	{
		for (int q2 = 0; q2 < 8; q2++)
		{
			if (q1 == q2 || q1 == q2 + 1 || q1 == q2 - 1)
			{
				continue;
			}
			for (int q3 = 0;q3 < 8; q3++)
			{
				if (q1 == q3 || q1 == q3 + 2 || q1 == q3-2
					|| q2 == q3 || q2 == q3 + 1|| q2 == q3 - 1)
				{
					continue;
				}
				for (int q4 = 0; q4 < 8; q4++)
				{
					if (q1 == q4 || q1 == q4 + 3 || q1 == q4 - 3 
						|| q2 == q4 || q2 == q4 + 2|| q2 == q4- 2 
						|| q3 == q4 || q3 == q4 + 1 || q3== q4- 1)
					{
						continue;
					}
					for (int q5 = 0; q5 < 8; q5++)
					{
						if (q1 == q5 || q1 == q5 + 4 || q1 == q5 - 4 
							|| q2 == q5 || q2 == q5 + 3|| q2 == q5 - 3 
							|| q3 == q5 || q3 == q5 + 2 || q3 == q5- 2 
							|| q4 == q5 || q4 == q5 + 1 || q4 == q5 - 1)
						{
							continue;
						}
						for (int q6 = 0; q6 < 8; q6++)
						{
							if (q1 == q6 || q1 == q6 + 5 || q1 == q6 - 5
								|| q2 == q6 || q2 == q6 + 4 || q2 == q6 - 4
								|| q3 == q6 || q3 == q6 + 3 || q3 == q6 - 3
								|| q4 == q6 || q4 == q6 + 2 || q4 == q6 - 2
								|| q5 == q6 || q5 == q6 + 1 || q5 == q6 - 1)
							{
								continue;
							}
							for (int q7 = 0; q7 < 8; q7++)
							{
								if (q1 == q7 || q1 == q7 + 6 || q1 == q7 - 6
									|| q2 == q7 || q2 == q7 + 5 || q2 == q7 - 5
									|| q3 == q7 || q3 == q7 + 4 || q3 == q7 - 4
									|| q4 == q7 || q4 == q7 + 3 || q4 == q7 - 3
									|| q5 == q7 || q5 == q7 + 2 || q5 == q7 - 2
									|| q6 == q7 || q6 == q7 + 1 || q6 == q7 - 1)
								{
									continue;
								}
								for (int q8 = 0; q8 < 8; q8++)
								{
									if (q1 == q8 || q1 == q8 + 7 || q1 == q8 - 7
										|| q2 == q8 || q2 == q8 + 6 || q2 == q8 - 6
										|| q3 == q8 || q3 == q8 + 5 || q3 == q8 - 5
										|| q4 == q8 || q4 == q8 + 4 || q4 == q8 - 4
										|| q5 == q8 || q5 == q8 + 3 || q5 == q8 - 3
										|| q6 == q8 || q6 == q8 + 2 || q6 == q8 - 2
										|| q7 == q8 || q7 == q8 + 1 || q7 == q8 - 1)
									{
										continue;
									}
									count++;
									printf("%d,%d,%d,%d,%d,%d,%d,%d\n", q1, q2, q3, q4,q5, q6, q7, q8);                        
								}
							}
						}
					}
				}
			}
		}
	}
	printf("һ����%d�ַ���", count);
	return 0;
}
#endif 
//35.���ݵ��㷨˼�룬ʹ�õݹ�����
#if 0
#include <iostream>

using namespace std;

const int SIZE=8;
bool qipan[SIZE][SIZE];
int count;

void solve(int);
bool check(int,int);
void show(void);

int main()
{
	//�ӵ�1�п�ʼ 
	solve(0);	

	cout<<count;
	
	return 0;
}
void solve(int r)
{
	//�ӵ�1�п�ʼ 
	for(int c=0;c<SIZE;c++)
	{		
		if(check(r,c)) 
		{
			qipan[r][c]=true;

			//���µ���Żʺ��������һ�� 
			if(r+1==SIZE)
			{
				show();
				count++;
			}
			else
			solve(r+1);
		}
		//***ע***�˴�����дelse 
		qipan[r][c]=false;
	}
}
bool check(int r,int c)
{
	//���µ��ǵ�һ�� 
	if(r==0)
		return true;
	
	int i,j;
	
	//�ж������Ƿ��г�ͻ
	for(i=0;i<r;i++) 
	{
		if(qipan[i][c])
			return false;
	}
	
	//�ж�\�Խ����Ƿ��г�ͻ
	i=r-1;
	j=c-1;
	
	while(i>=0&&j>=0)
	{
//***ע***����д������ 
//		if(qipan[i--][j--])
//			return false;
//�漰�����������е��֪ʶ 
		if(qipan[i][j])
			return false;
			
		i--;
		j--;
	} 
	
	//�ж�/�Խ����Ƿ��г�ͻ
	i=r-1;
	j=c+1;
	
	while(i>=0&&j<SIZE)
	{
		if(qipan[i][j])
			return false;
			
		i--;
		j++;
	}
	
	return true;
}
void show(void)
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(qipan[i][j])
			cout<<j+1;
		}		
	}
	cout<<endl;
}
#endif 


//36.����˻ʺ�ĵ�x�ְڷŷ��� 
#if 0
#include <iostream>
#include <vector>
using namespace std;

const int SIZE=8;
bool qipan[SIZE][SIZE];
int count;

void solve(int);
bool check(int,int);
void show(void);

vector<int> v [92];
int index;

int main()
{	
	//�ӵ�1�п�ʼ 
	solve(0);	

	int n;
	cin>>n;
	
	int* p=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	} 
	
	for(int i=0;i<n;i++)
	{
		for(auto x:v[p[i]-1])
			cout<<x;
		
		cout<<endl;
	}
		
	return 0;
}
void solve(int r)
{
	//�ӵ�1�п�ʼ 
	for(int c=0;c<SIZE;c++)
	{		
		if(check(r,c)) 
		{
			qipan[r][c]=true;

			//���µ���Żʺ��������һ�� 
			if(r+1==SIZE)
			{
				show();
				count++;
			}
			else
			solve(r+1);
		}
		//***ע***�˴�����дelse 
		qipan[r][c]=false;
	}
}
bool check(int r,int c)
{
	//���µ��ǵ�һ�� 
	if(r==0)
		return true;
	
	int i,j;
	
	//�ж������Ƿ��г�ͻ
	for(i=0;i<r;i++) 
	{
		if(qipan[i][c])
			return false;
	}
	
	//�ж�\�Խ����Ƿ��г�ͻ
	i=r-1;
	j=c-1;
	
	while(i>=0&&j>=0)
	{
//***ע***����д������ 
//		if(qipan[i--][j--])
//			return false;
//�漰�����������е��֪ʶ 
		if(qipan[i][j])
			return false;
			
		i--;
		j--;
	} 
	
	//�ж�/�Խ����Ƿ��г�ͻ
	i=r-1;
	j=c+1;
	
	while(i>=0&&j<SIZE)
	{
		if(qipan[i][j])
			return false;
			
		i--;
		j++;
	}
	
	return true;
}
void show(void)
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(qipan[i][j])
			v[index].push_back(j+1);
		}		
	}
	index++;
}
#endif 


//37.ɾ�� 
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//bool mycompare(char ch1,char ch2);
int main()
{
	int n;
	string str;
	cin>>str>>n;
	
	sort(str.begin(),str.end());
	
	//�����ļ�������ɾ�� 
	str.erase(str.size()-n,n);
	
	long long res=stol(str);
	
	cout<<res;
	
	return 0;
}
//bool mycompare(char ch1,char ch2)
//{
//	return ch1>ch2;
//}
#endif


//38.���ǹ�
//���ҵ�����ǹ����ˣ���ָ����Ҳ�����ǹ�����һ�� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int n;
void process(vector<LL>& ,int);
bool check(vector<LL>&); 

int main()
{
	cin>>n;
	
	vector<LL> v(n+1);
	v[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	
	int count=0;
	
	vector<LL>::iterator mi;
	int max_i;

	while(1)
	{
		mi=max_element(v.begin()+1,v.end());
		//����������������õ���������������֮��ľ���
		//��������֮��������ٸ��������͵�Ԫ�� 
		max_i=mi-v.begin();
	//	cout<<max_i;
		
		process(v,max_i);
		count++; 
		
		if(check(v))
			break;
	}
	
	cout<<count;
	
	return 0;
}
void process(vector<LL>& v,int index)
{	
	int left,right;

	left=(index==1)?n:index-1;

//	if(index==n)
//	{
//		right=1;
//	}
//	else
//	{
//		right=index+1;
//	}

//������������ٶȸ��� 
	right=(index==n)?1:index+1;
	
	//�����ǹ� 
	(v[left]>v[right])?(++v[right]):(++v[left]);
	--v[index];
}
bool check(vector<LL> & v)
{
	LL temp=v[1];
	
	for(int i=2;i<=n;i++)
	{
		if(v[i]!=temp)
			return false;		
	}
	
	return true;
}
#endif 


//39.����Ա 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

typedef struct
{
	LL	dis;
	int tire;
}attributeTypeDef;

int qian_tire[100010];

int main()
{
	int N;
	cin>>N;
	
	LL* ans = new LL [N+1]{0}; 
	
	//ά��һ���ṹ������ 
	attributeTypeDef *p=new attributeTypeDef[N+1]{{0,0}};
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].dis;
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].tire;
	}
	
	//��ֻ��һ��ס������ʱ	
	LL* x1=new LL[N+1]{0};	
	for(int i=1;i<=N;i++)
	{
		//��������ƣ��ֵ 
		x1[i]=2*(p[i].dis)+p[i].tire; 
	}
	
	auto px1=max_element(x1+1,x1+N+1);
	ans[1]=*px1;
	
	//������Ҽ�����ס������ʱ 
	
	//***�ѵ�***
	//·��Զ������ƣ��ֵ��һ����
	//·�̽�������ƣ��ֵ��һ��С 
		
	LL max_dis=p[1].dis;
	
	for(int i=2;i<=N;i++)
	{
		max_dis=p[i].dis>max_dis?p[i].dis:max_dis;
	}	
		
	sort(p+1,p+N+1,
	[](attributeTypeDef a1,attributeTypeDef a2)
	{	return a1.tire>a2.tire;	}    );
	
	for(int i=1;i<=N;i++)
	{
		qian_tire[i]=qian_tire[i-1]+p[i].tire;
	}
	
	for(int i=2;i<=N;i++)
	{
		ans[i]=2*max_dis+qian_tire[i];
	} 
		
	for(int i=1;i<=N;i++)
	{
		cout<<ans[i]<<endl;
	}
			
	return 0;
}
//5
//1 2 3 4 5
//1 2 3 4 5
#endif
//39.��
//̰��+ǰ׺�� 
#if 0
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

PII a[N];

int tire[N]; //tire[i]��ʾǰi��Ai�ĺ�
int f[N]; //��ʾǰi��Si�����ֵ
int g[N]; //��ʾi~n��2Si + Ai�����ֵ

int main()
{
   int n;
   scanf("%d", &n);
   
   //����ÿ������ڵľ���Si
   for(int i = 1; i <= n; i ++) 
		scanf("%d", &a[i].first);
   //����������Ʒ��ƣ��ֵAi
   for(int i = 1; i <= n; i ++) 
		scanf("%d", &a[i].second);
   
   //***
   //����Ai�Ӵ�С����
   //***ס���Ŵ���û�й�ϵ��*** 
   sort(a + 1, a + n + 1,
	[](PII p1,PII p2){	return p1.second>p2.second;	});
//   reverse(a + 1, a + n + 1);
   
   //Ԥ����tire[i],��ʾ��ǰi��ס��������Ʒ��ƣ��ֵǰ׺��
   for(int i = 1; i <= n; i ++)
		tire[i] = tire[i - 1] + a[i].second;
   
   //Ԥ����f[i],��ʾ����ڵ�ǰi��ס������Si�����ֵ
   for(int i = 1; i <= n; i ++)
		f[i] = max(f[i - 1], a[i].first);
   
   //Ԥ����g[i],��ʾ2 * Si + Ai�����ֵ
   //ע�⣬����Ӻ���ǰ����, �ȼ����СAiֵ��Ӧ��g[i]
   //��Ϊg[i]��ʾ���Ǵ�i~n��2*Si +Ai���ֵ
   for(int i = n; i >= 1; i --)
		g[i] = max(g[i + 1], 2 * a[i].first + a[i].second);
   
   //���
   for(int i = 1; i <= n; i ++)
   {
      printf("%d\n", 
		max(tire[i] + 2 * f[i], tire[i - 1] + g[i]));
   }
   
   //������x��ס��������Ʒ���ܻ������ƣ��ֵֻ���������
   //1.Aiֵ����x��
	//2.Aiֵ����x-1�ң�Ȼ�����һ�Ҿ��������Զ 
   
   return 0;
}
//5
//1 2 3 4 5
//5 4 3 2 1
#endif


//40.����λ 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

const int SIZE=1010;
bool zuowei[SIZE][SIZE];

//��ĳ�кŵĳ��ִ�������ĳ�кŵ��к�ֵ 
typedef struct 
{
	int m_jishu;
	int m_index;
}hangTypeDef;

//��ĳ�кŵĳ��ִ�������ĳ�кŵ��к�ֵ 
typedef struct 
{
	int m_jishu;
	int m_index;
}lieTypeDef;

int main()
{
	int M,N,K,L,D;
	cin>>M>>N>>K>>L>>D;
	
	//һ��Ҫ�ǵó�ʼ���ṹ�������ݵ����� 
	hangTypeDef* ph=new hangTypeDef[M+1]{{0,0}};
	lieTypeDef* pl=new lieTypeDef[N+1]{{0,0}};
	
	int r1,c1,r2,c2;
	for(int i=1;i<=D;i++)
	{
		
		cin>>r1>>c1>>r2>>c2;

//�������û�õ� 
//		zuowei[r1][c1]=zuowei[r2][c2]=true;
		
		if(r1==r2)
		{
			int liehao=min(c1,c2);
			(pl[liehao].m_jishu)++;//ĳ�е�Ȩֵ��һ
			pl[liehao].m_index=liehao;//��¼�к� 
		}
		
		if(c1==c2)
		{
			int hanghao=min(r1,r2);
			(ph[hanghao].m_jishu)++;//ĳ�е�Ȩֵ��һ	
			ph[hanghao].m_index=hanghao;//��¼�к� 
		}
	}
	
	
	//����ĳ���кŻ�ĳ���кų��ֵĴ����Խṹ���������	
	sort(ph,ph+M+1,[](const hangTypeDef &a, const hangTypeDef& b)
	{
		if(a.m_jishu>b.m_jishu)
			return true;
		else if(a.m_jishu==b.m_jishu&&a.m_index<b.m_index)
			return true;	
		else
			return false ;});
			
	sort(pl,pl+N+1,[](const lieTypeDef &a, const lieTypeDef& b)
	{
		if(a.m_jishu>b.m_jishu)
			return true;
		else if(a.m_jishu==b.m_jishu&&a.m_index<b.m_index)
			return true;	
		else
			return false ;});	
	
	for(int i=1;i<=K;i++)
	{
		cout<<ph[i-1].m_index;
		
		if(i!=K)
			cout<<' ';
		else
			cout<<endl;
	}
	
	for(int i=1;i<=L;i++)
	{
		cout<<pl[i-1].m_index;
		
		if(i!=L)
			cout<<' ';
		else
			cout<<endl;
	}

	return 0;
}
//4 5 1 2 3
//4 2 4 3
//2 3 3 3
//2 5 2 4
#endif


//41.��ֽ��
//�Աȷ��ǹ�
//����һ�����ǹ�ÿ��ֻ�ܷ�һ�ţ�
//����ÿ�����ƶ����ܲ�ֹһ��ֽ��
//�������ֽ�ƶѲ���Χ��һȦ�ģ� 
//��һ��ֻ���Ƶ��ڶ��ѣ� 
//���һ��ֻ���Ƶ������ڶ��� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int n;
LL sum;
LL per_sum;

void process(vector<LL>& ,int);
bool check(vector<LL>&); 

int main()
{
	cin>>n;
	
	vector<LL> v(n+1);
	v[0]=0;
	
	sum=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	
	per_sum=sum/n;
	
	int count=0;
	
	vector<LL>::iterator mi;
	int max_i;

	while(1)
	{
		mi=max_element(v.begin()+1,v.end());
		//����������������õ���������������֮��ľ���
		//��������֮��������ٸ��������͵�Ԫ�� 
		max_i=mi-v.begin();
	//	cout<<max_i;
		
		process(v,max_i);
		count++; 
		
		if(check(v))
			break;
	}
	
	cout<<count;
	
	return 0;
}
void process(vector<LL>& v,int index)
{	
	int left,right;

	left=(index==1)?n:index-1;

//	if(index==n)
//	{
//		right=1;
//	}
//	else
//	{
//		right=index+1;
//	}

//������������ٶȸ��� 
	right=(index==n)?1:index+1;
	
	//����ֽ�� 
	int pos=(v[left]>v[right])?right:left;
	
	//����˼·��ÿ��ֻ����per_sum-v[pos]��
	//ֽ�Ƹ�����Ҳ� 
	int shuliang=per_sum-v[pos];
	v[pos]+=shuliang;
	v[index]-=shuliang;
}
bool check(vector<LL> & v)
{
	LL temp=v[1];
	
	for(int i=2;i<=n;i++)
	{
		if(v[i]!=temp)
			return false;		
	}
	
	return true;
}
#endif 
//41.��
//������̰���㷨�����մ����ҵ�˳���ƶ�ֽ�ơ�
//���i�ѵ�ֽ����������ƽ��ֵ�����ƶ�һ�Σ�
//����������ƶ���
//1����a[i]>v����a[i]-v�Ŵӵ�i���ƶ�����i+1�ѣ�
//2����a[i]<v����v-a[i]�Ŵӵ�i+1���ƶ�����i�ѡ�
#if 0
#include <iostream>

using namespace std;
int cards[10010];

int main()
{
	int N;
	cin>>N;
	
	int sum=0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cards[i];
		sum+=cards[i];
	}
	
	int average=sum/N;
	
	int tmp,count=0;	
	
	for(int i=1;i<=N;i++)
	{
		if(cards[i]==average)
			continue;
			
		if(cards[i]<average)
		{
			tmp=average-cards[i];
			cards[i]+=tmp;
			cards[i+1]-=tmp;
		}
		else
		{
			tmp=cards[i]-average;
			cards[i+1]+=tmp;
			cards[i]-=tmp;			
		}
		
		++count;
	}
	
	cout<<count<<endl;

	return 0;
}
#endif
//���ף� 
//����ֽ���ƶ��Ĵ�����0~2��
//��ʲôԭ�����ƶ��Ĵ�����ͬ�أ� �ܽ᣺
//0�Σ�3�Ѷ�Ϊƽ����
//1�Σ���һ�ѻ��ߵ�����Ϊƽ����
//2�Σ�������� 
//Ϊ1��ʱ����һ��Ϊƽ���������ƶ���
//����ʱ������Ҳû�����𰡣����ѿ��Էֽ������+һ�ѣ�
//������Ѿ���Լ�о�������������Ĵ��ڡ�
//***
//�������ֳ�����N��ֽ�ƣ����м�ĳλ�÷ֿ���
//�������߶��պù��֣���ô��ÿһ�߶���������ʱ��
//һ�������л����ƶ�����Ϊ�����������x�ŵ��ұߣ�
//���Ȼ������ұ���x�Ż��������ڶ��������
//����������ʵ���Կ���������ȫ������������
//ԭ�ģ�https://zhuanlan.zhihu.com/p/401123895 


//42.��������Է���
//��ȡ��
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> A,B,e,b;

bool check(char ch)
{
	if(isalpha(ch)||isdigit(ch))
		return true;
	
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k;
	string s;
	
	cin>>k;
	cin.get();
	
	getline(cin,s);
	
	for(int i=0;i<s.size();i++)
	{
		//��Alice�����ҵ���A��ĸ��Ӧ������ֵ�洢������A
		//��e��ĸ�洢������e
		
		//***
		//�ȱ�֤iֵ������substr()�����ַ�����ĩβ 
		if(i+4>=s.size()||s.substr(i,5)!="Alice") 
			continue;
		
		//(��������ȼ��������ٻ�)
		if(i-1>=0&&check(s[i-1])||i+5<s.size()&&check(s[i+5]))
			continue;
		
		A.push_back(i); 
		e.push_back(i+4);
	}
	
	for(int i=0;i<s.size();i++)
	{
		//��Bob�����ҵ���B��ĸ��Ӧ������ֵ�洢������B
		//��b��ĸ�洢������b
		
		//***
		//�ȱ�֤iֵ������substr()�����ַ�����ĩβ 
		if(i+2>=s.size()||s.substr(i,3)!="Bob") 
			continue;
		
		//(��������ȼ��������ٻ�)
		if(i-1>=0&&check(s[i-1])||i+3<s.size()&&check(s[i+3]))
			continue;
		
		B.push_back(i); 
		b.push_back(i+2);
	}	
	
	long long ans=0;
	
	//Alice��ǰ��Bob�ں�����
	int left,right;
	left=right=0;
	
	//��������e�������д����ÿ��Alice��e���ֵ�����ֵ 
	for(int i=0;i<e.size();i++)
	{
		//�ҵ���e��Ե�����ֵ��С��B��leftΪB����������ֵ 
		while(left<B.size()&&B[left]<e[i])
		left++;
		
		//����right�ƶ���leftλ�� 
		right=max(right,left);
		
		//�ҵ���e��Ե�����ֵ����B��rightΪB����������ֵ
		//right-1�͵õ���e��Ե�����ֵ����B
		while(right<B.size()&&B[right]-k<=e[i])
		right++;
		
		//����+1����⣺1��2����ô��2-1+1��2��Bob 
		ans+=right-1-left+1;
	} 

	//Alice�ں�Bob��ǰ�����
	left=right=0;
	
	//��������A�������д����ÿ��Alice��A���ֵ�����ֵ 
	for(int i=0;i<A.size();i++)
	{
		//�ҵ���A��Ե�����ֵ��С��b��leftΪb����������ֵ 
		while(left<b.size()&&b[left]+k<A[i])
		left++;
		
		//����right�ƶ���b��A���С�ڵ���K�ľ����� 
		right=max(right,left);
		
		//�ҵ���A��Ե�����ֵ����b��rightΪb����������ֵ
		//right-1�͵õ���A��Ե�����ֵ����b
		while(right<b.size()&&b[right]<A[i])
		right++;
		
		//����+1����⣺1��2����ô��2-1+1��2��Bob 
		ans+=right-1-left+1;
	}
	
	cout<<ans;
	
	return 0;
}
#endif


//43.K������ 
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
//ȱ�ݣ�
//ֻ��ͨ��2�����Ե㣬����ȫ����ʱ 
//ö�ٷ�������ʱ�临�Ӷȸߵ�ȱ�� 
#endif
//43.��
//���Ǽ���n=5��k=2��
//�����5����Ϊ1,2,3,4,5�Ļ�
//�������6����6������ֱ���123  1234  2345  345  2  4;
//��ÿһ��ǰ׺��(��ѡ���������м�����ĺ�)�������
//����ѡ����������ɵ����䶼������k�����䣬
//����㷽����ʵ����������ϣ�
//��������Ӽ��ɱ�ʾΪC2 2����C2 3���Ϊ1+3=4����ʵ�ʽ����6�֣����������������ұյģ�����add[0]�����н��Ҳ����2��4���֣��൱����������ұգ���������������һ��k�����䣬4+2=6���պ�����ȷ�𰸡�
//https://blog.csdn.net/qq_53763705/article/details/123583960
#if 0
#include <iostream>

using namespace std;

int mod[100010];
int add[100010];

int main()
{
	//n�����֣�k�ı�����ÿ������num 
	int n,k,num;

	cin>>n>>k;

	long long cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		
		//��ӵ�1�����ֵ���i�����ֶ�Ӧ��ģֵ
		mod[i]=(mod[i-1]+num)%k;
		
		//��ģֵ������һ 
		add[mod[i]]++; 
	} 
	
	//��ȫ���� 
	for(int i=0;i<n;i++)
	{
		cnt+=add[i]*(add[i]-1)/2;
	}
	
	cout<<cnt+add[0]; 

	return 0;
}
#endif 


//44.�������
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const long MAX=1e5;
int dp[110][MAX];
 
int main()
{
	int N;

//����д��˳��
//�ᵼ�³��������������������Ų��ͻȻ���� 
//	long* fama=new long[N+1];	
//	cin>>N;
	
	cin>>N; 
	long* fama=new long[N+1]{0};	
	
	for(int i=1;i<=N;i++)
	{
		cin>>fama[i];
	}

//����д����
//����fama[0]������ֵ�������������к�Ҳ����������Ų��ͻȻ����	
//	sort(fama,fama+N+1);

	sort(fama+1,fama+N+1); 

	long sum=0;
	for(int i=1;i<=N;i++)
	{
		//��1����i��������������ۼ�ֵ 
		sum+=fama[i];
		
		for(long w=1;w<=sum;w++)
		{
			//����������Ӧ�������ɲ� 
			if(w==fama[i])
				dp[i][w]=1;			
			else if(w<fama[i])
			{
				//�ȸ�����һ�� 
//				dp[i][w]=dp[i-1][w];
				

				dp[i][w]=max(dp[i-1][w],dp[i-1][fama[i]-w]);
			}
			else
			{
	 			dp[i][w]=max(dp[i-1][w],dp[i-1][w-fama[i]]);	
			}
		}
				
	}
	
//	for(int i=1;i<4;i++)
//	{
//		for(int j=1;j<=11;j++)
//		{
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<"     ";
//	}
	
	long count=0;
	for_each(&dp[N][0],&dp[N][sum+1],[&count](int num)
	{	if(num)	++count;	});

//	for(long i=1;i<=sum;i++)
//	{
//		if(dp[N][i])
//			++count;
//	}

	cout<<count;

	return 0;
}
#endif 


//45.�����
#if 0
#include <iostream>

using namespace std;

bool space [20][20];
bool visit [20][20];
int count;
void dfs(int x, int y, int jieshu);

int main()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			//�궨�ɷ��õ����� 
			space[i][j]=true;
		}
	}
	
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			//***ע***
			//����д������� 
			//����dfsǰ�ĳ�ʼ��λ��Ҫ���Ϊ�ѷ��� 
			visit[i][j]=1; 
			
			dfs(i,j,1);
			
			visit[i][j]=0;
		}
	}

	cout<<count;
	
	return 0;
}

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int x, int y, int jieshu)
{
//������Ӵ����
//	if(x>4||x<1||y>4||y<1)
//	return; 
		
	if(jieshu==16)
	{
		count++;
		
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		
		if(space[x1][y1]&&!visit[x1][y1])
		{
			visit[x1][y1]=1;
			
			dfs(x1,y1,jieshu+1);
			
			visit[x1][y1]=0;
		}
		 
	}
}
#endif 



















