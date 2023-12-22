//1.数据表示
#if 0
#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

int main()
{
	int a=12;

//法一： 
//iomanip中的setbase方法

//错误使用： 
//	setbase(8);

//正确使用：
	
	cout<<setbase(8)<<a<<endl; 

//法二：使用控制符 
	cout<<oct;
	cout<<a<<endl;


//进制转换
//法一： 
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

//法二：
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


//2.闰年
#if 0
#include <iostream>

using namespace std;

int main()
{
	int year;
	cin>>year;
	
	if((year%4==0&&year%100!=0)||year%400==0)
	cout<<"是闰年";
	else
	cout<<"不是闰年"; 

	return 0;
}
#endif 


//3.购物单 
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


//4.明码 
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
	
	//显示第num+1个汉字 
	for(int num=0;num<10;num++)
	{
		//某个汉字的二进制码存入s1 
		string s1;
		s1=show(getdata[num]);
		
		//16行，每行16位显示字形 
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
		
		//每个十进制数都转化为二进制数 
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
		
		//***注***此语句必须写 
		str1.clear();	
	}
		
	return str2;
}
//经验：还是将数据先处理好，再进行排列与解释
//这样比较简便 
#endif


//5.分解质因数 
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
		//存素数的数组从索引0开始遍历，
		//到值小于等于i		
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
//生成素数法一： 
//判断n是否为素数，只需从2到n-1枚举
//是否有数能够被n整除即可 
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
//法二：埃拉托斯特尼筛子(筛选法)
#if 1
//从2开始到N的自然数按次序排列起来 
//然后将2后面能被2整除的数标记为false 
//将3后面能被3整除的数标记为false 
//以此类推
//可以利用数组的索引和值，这两个属性 
//索引代表某个数，而某个索引对应的值代表其是否为素数 
void getzhishu(void)
{
	//将所有值都标记为1 
	fill(zhishu,zhishu+N,true);
	
	//0和1不是素数，这边先标记好 
	zhishu[0]=zhishu[1]=false;
	
	//从数字2开始处理，到N/2 
	//如判断1~21，则i枚举从2到10 
	for(int i=2;i<=N/2;i++)
	{
		//如果数字i是素数 
		if(zhishu[i])
		{
			//将i后面能被i整除的数标记为false 
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


//6.十进制转化成任意进制
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//十进制的数N，转化成base进制的数 
	int N,base;
	cin>>N>>base;

	
	//除后取余倒读，这步是一定要有的，
	//由于十进制的10，对16取余后是10，加上'0'后
	//无法表示成'10'，所以不能用string容器存数据 
	//只能用int型的数组存数据 
	
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
	
	//对10进制以上的进制做二位数用字母表示的处理 
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
		
		//或写成
		if(num[i]<10)
			snum+=num[i]+'0';
		else
			snum+=num[i]-10+'A';
	}
	
	cout<<snum; 
	
	return 0;
}
#endif 


//7.任意进制转化为十进制
#if 0
#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

int main()
{
	//base进制的数N，转化成十进制的数 
	int base;
	string N;
	cin>>base>>N;
	
	//按权展开 
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



//8.回文数
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
	
	//若数字是0，就直接报告是0次 
	if(num==0)
	{
		cout<<0;
		return 0; 
	}
	
//	cout<<num;

	char temp[11]={'\0'};
	sprintf(temp,"%d",num);
	
	string s1(temp);
	string s2(s1.size(),' ');//***注1*** 
	reverse_copy(s1.begin(),s1.end(),s2.begin());
	
//注1：
//复制行为不能根据发送值调整目标容器的长度，
//因此容器一开始就要留好位置，否则会出现 
//terminate called after throwing an instance of 'std::out_of_range'
//运行阶段的错误 

 
//	cout<<s1<<" "<<s2<<endl;
		
	int count=0;
	
	//***注***一个数的首位不能为0 
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
		s2.resize(s1.size());//***注1*** 
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
	//base进制的数N，转化成十进制的数 
	int base;
	string N;
	cin>>base>>N;
	
	//按权展开 
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


//9.统计单词个数
//法一：用vector<string>存数据
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
	//用transform()和tolower()将字符都转化为小写 
	//***注***
	//::tolower表示使用全局的tolower名称 
	transform(target.begin(),target.end(),
	target.begin(),tolower);
	
	
	string temp;
	vector<string> vs;
	while(1)
	{
		cin>>temp;
		transform(temp.begin(),temp.end(),
		temp.begin(),::tolower);//如果前面写了using namespace std
		//此处可以这样写，或者写(int (*)(int))tolower 



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

                        //***可以使用<运算符 
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
//法二：尺取法 
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
	//用transform()和tolower()将字符都转化为小写 
	//***注***
	//::tolower表示使用全局的tolower名称 
	transform(target.begin(),target.end(),
	target.begin(),::tolower);
	
	//消耗掉换行符 
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
	
	//定义左指针i，右指针j被左指针加跨度len代替 
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


//10.解码 
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
//		if(isdigit(str[i]))//***注***是字符的0~9 
//		{
//			temp=str[i-1];
//			//push_back()方法不支持下面的功能 
//			res.append(str[i]-'0',temp);
//		}

		if(isalpha(str[i]))
		{
			if(isdigit(str[i+1]))//***注***是字符的0~9 
			{
				temp=str[i];
				//push_back()方法不支持下面的功能 
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


//11.日志统计
//方法：尺取法 
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
	//行数N，时间长度D,K个赞 
	L N,D,K;
	cin>>N>>D>>K;
	
	//若单单用索引来表示时间，会造成空间很大的浪费 
//	L (*log)[2]=new L [N][2];
//		
//	for(L i=0;i<N;i++)
//	{
//		cin>>log[i][0]>>log[i][1];
//	}
	
	//***注*** 
	//后续需要对每行的数据进行从大到小的排序，因此
	//单纯的二维数组存数据的方法不可行 
	

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
	//理解：
	//使用unique()后保持剩余元素的相对顺序，
	//且不更改容器的物理大小。
	//指向范围的新逻辑结尾和物理结尾之间元素的迭代器
	//仍然可解引用，但元素自身拥有未指定值。
	//调用 unique 后有时会调用容器的 erase 成员函数，
	//它擦除未指定值并减小容器的物理大小，
	//以匹配其新的逻辑大小。
	 
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


//12.卡片 
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


//13.杨辉三角
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
	
	//这样分配动态内存，会有很大的空间浪费，
	//而且二维数组也不能很大，否则会造成分配内存失败 
//	int (*yanghui) [MAXN]=new int [MAXN][MAXN];
	
	
	//创建一个金字塔形的数组空间，使用索引值1~MAXN行 
	//第i行使用索引值1~i 
	L **yanghui=new L* [MAXN+1];
	
	for(L i=1;i<MAXN+1;i++)
	{
		yanghui[i]=new L [i+1]{0};
	} 
	
	//第i行 
	for(L i=1;i<MAXN+1;i++)
	{
		yanghui[i][1]=yanghui[i][i]=1;
		
		//第i行第2个数开始，到倒数第2个数结束 
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
//查看输出，得知在70行左右就发生整数溢出 
	
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
//测试输入：71523144
//测试输出：4956
//************超时，用时9秒****** 
//测试输入：515927503
//测试输出：515959629
//*******************************
//数据所在杨辉三角的位置是在第100行 
//最后的遍历修改为j从1到100 
//经验：
//即使杨辉三角中间的数据有整数溢出，但三角的两侧
//数据仍可能未溢出，可能作为测试输入。 
#endif 
//13.改
#if 0
#include <iostream>

using namespace std;

typedef long long L;
const L MAXN=1e4;		//改成5e4，所有测试输入都会超时 

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
	
	//第i行 
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
		
		//第i行第2个数开始，到倒数第2个数结束 
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
//将后面的双重for循环去掉，将判断语句块移到前面的
//双重for循环内，减少时间复杂度
//但还是超时了 
//const L MAXN=5e4;
//************超时，用时6s******* 
//测试输入：515927503
//测试输出：515959629
//*******************************
#endif 


//14.报数游戏
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int);
int main()
{
	//人数n，编号m，第k次拍手
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
			//若数字到特例，且轮到编号m 
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
				//若数字到特例，且轮到编号m 
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
				//若数字到特例，且轮到编号m 
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


//15.报数问题
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
	//按索引值循环遍历 
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
//法二：利用STL的queue容器
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
			//***将首元素移动到队列尾部*** 
			q.push(q.front());
			q.pop();
		}
		
		//队列首元素对应的编号的这个人叫号 
		num++;
	}
	
	cout<<q.front();
	
	return 0;
}
#endif
//快速随机访问：vector、deque (vector会更快)
//元素快速插入与删除：list (deque适用于头与尾元素的插入与删除)  


//16.猴子选大王
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
				//***将首元素移动到队列尾部*** 
				q.push(q.front());
				q.pop();
			}
			
			//叫号 
			num++;
		}
		
		res.push_back(q.front());
		
		//清空队列中的元素 
		q.pop();
		
		cin>>n>>m;
	}
	
	for(auto x:res)
		cout<<x<<endl; 

	return 0;
}
#endif 


//17.等差素数数列 
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
//错误写法： 
//				gongcha*=2;
//举例：:30 60 120 240 
				
//正确写法： 
				gongcha2+=gongcha;
//举例:30 60 90 120  
				if(count==10)
				goto RES;
			}
		}
		
		//由于公差很大的情况也可能符合要求，于是要 
		//***找出所有情况的最小值***	
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
//时间复杂度太高，运行了82秒 
#endif 
//17.改
//修改一：用模块化编程，好处是不用在循环中设置多个变量
//然后在不符合条件时将变量重置 
//修改二： 
//思考：公差肯定是比生成的素数数组元素小的
//一个不确定的数，因此考虑将公差循环放到最外面,
//好处是不用在内循环规定公差的循环结束的值 
//***深入理解：*** 
//外层循环是sushu数组的索引值->寻找符合要求的
//最小起始素数数字 
//外层循环是gongcha->寻找符合要求的
//最小公差 
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


//18.完全二叉树的权值
//某完全二叉树有N个元素 
//树的深度deep=log2(N)+1;
//某个深度值i(i为1到deep)，元素的编号是从pow(2,i-1)到pow(2,i)-1 


//19.求4个数的最大公约数与最小公倍数
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


//20.货物摆放
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

//***注***
//改成这样会减少很多时间复杂度 
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
//测试set容器中元素的存放顺序
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
//结论：set中的元素pair<pair<int,int>,int>
//排列顺序也遵循从小到大，且若首个成员值相同，则比较
//下一个成员的值 
#endif 


//22.生日蜡烛
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


//23.奖券数目
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

//为什么这段语句不需要？			
//		fill(tmp,tmp+6,'\0');
 
	}
	
	cout<<count;

	return 0;
}
#endif 


//24.深入理解sprintf() 
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

//为什么这段语句不需要？			
//		fill(tmp,tmp+6,'\0');

//测试tmp数组中存的元素
		for(int i=0;i<6;i++)
		{
			if(tmp[i]=='\0')
			cout<<'\\';
			else
			cout<<tmp[i];
		}
		cout<<endl; 
		
//解释：
//1. 
//对于递增或递减的数字，其占用的字符数组长度只会
//越来越长或越来越短，但长度变化始终是一位一位地变，
//所以可以通过在进入循环前先赋好空字符等编程技巧
//以防止出现空字符后面还有数字字符的情况。
//2.
//每次循环时使用的字符数组，其超过数字长度的
//空间只有数字后的一个空间用空字符填充，其余
//空间内容不变，这是sprintf()附带的功能。 

//错误理解： 
//而且每次循环时使用的字符数组，其超过数字长度的
//空间都用空字符填充了，可能是sprintf()的功能 
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


//25.选数
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
		
		//去重 
		s.insert(sum);	


	}while(next_permutation(getdata,getdata+n));
	
	
	//***更简洁的代码*** 
	//for_each()配合lambda函数 
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


//26.火柴棍等式
//问题：每个等式的火柴棍的消耗数怎么计算,
//数字怎么与火柴棍数相关联 
#if 0
#include <iostream>

using namespace std;

//数字0~9对应的火柴数 
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
	
	//***注***
	//对于char数组，部分初始化一个元素后，其余的元素
	//会自动初始化为空字符 
	char tmp[6]={'\0'};

//	for(auto x:tmp)
//	{
//		if(x=='\0')
//		cout<<'\\'<<" ";	
//		else
//		cout<<x;
//	}

	sprintf(tmp,"%d",num);
	
//错误写法： 
//	for(int i=0;tmp[i];i++)
//tmp[i]若为0或者为\0，循环都会终止 


//正确写法： 
	for(int i=0;tmp[i]!='\0';i++)
	{
		sum+=huochai[tmp[i]-'0'];
	}
	
	return sum;
}
#endif


//27.区分赋给ch型变量的数字0和字符'\0' 
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


//28.比例简化 
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
			//a和b要互质 
			if(__gcd(i,j)!=1)
			continue;
			
			//a/b要大于等于A/B 
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
//28.改
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
			//a和b要互质 
			if(__gcd(i,j)!=1)
			continue;
			
			//a/b要大于等于A/B 
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


//29.组合数
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


//30.李白打酒 
//经典的递归问题
//递归的终止条件为酒1斗和花1支 
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
//30.法二：DFS
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
	dfs(wine * 2,i + 1,store + 1,flower);	//逢店加一倍
	str[i] = 'b';
	dfs(wine - 1,i + 1,store,flower + 1);	//遇花喝一斗
			
}
#endif 


//31.组合数 
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
		
		//记录出现的数字 
		for(int index=0;tmp[index]!='\0';index++)
		{
			mark[tmp[index]-'0']=1;
		}
		
		//不允许出现0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
			
		j=2*i;
		sprintf(tmp,"%d",j);
		
		//记录出现的数字 
		for(int index=0;tmp[index]!='\0';index++)
		{
			//若之前已经记录过该数字，则i的数字轮到下一个 
			if(mark[tmp[index]-'0']==1)
				goto NEXT;			
			else
			mark[tmp[index]-'0']=1;
		}
		
		//不允许出现0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
		
		k=3*i;
		sprintf(tmp,"%d",k);
		
		//记录出现的数字 
		for(int index=0;tmp[index]!='\0';index++)
		{
			if(mark[tmp[index]-'0']==1)
				goto NEXT;			
			else
			mark[tmp[index]-'0']=1;
		}	
		
		//不允许出现0 
		if(find(tmp,tmp+4,'0')!=tmp+4)
			continue;
			
		cout<<i<<" "<<j<<" "<<k<<endl;
		
NEXT:
		fill(mark,mark+10,0);		
	} 

	return 0;
}
#endif
//31.改
//可以最后对记录数字出现的数组的元素求和，
//看加起来是不是9，从而判断1~9每个数字
//是否只出现了一次 
//***注***
//该方法有局限性
//若三个数字的位数之和不是9，那就不适用 
#if 0
#include<iostream>
using namespace std;
int main()
{
	int s[10];//定义一个数组记录0~9出现的次数 
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
		//将1~9每个数字出现次数加起来，如果等于9则每个数字都出现了一次 
		if(sum==9) 
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
	return 0;
} 
#endif 


//32.带分数 
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
		//若之前已经记录过该数字，则直接判为false 
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
		//若之前已经记录过该数字，则直接判为false 
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
//严重超时 
#endif
//32.改
//n=a+b/c
//思路一：(即上面的做题思路)
//先确定a，再遍历b和c，直到找到符合条件的数 
//思路二：
//由于表达式a+b/c中的数字由1~9组成，
//那么可以对1~9进行排列组合，
//然后在其中插入+号和/号 
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
		//取a的长度，因为b和c最短是1，所以a最长为7 
		for(i=1;i<=7;i++)
		{
			//截取a 
			tmp=s.substr(0,i); 
			//字符串变成数字
			a=stoi(tmp); 
			
			//若a大于等于n，则退出for循环
			if(a>=n)
				break; 
			
			//取b的长度，c最短是1，所以9减c的长度
			//再减a的长度 
			for(j=1;j<=9-1-i;j++)
			{
				tmp=s.substr(i,j);
				b=stoi(tmp);
			
			
				//取c的长度 
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
//32.法二： 
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
               continue;  //假分数肯定不行 
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


//状态压缩dp
//熟悉4种位运算
//1.判断一个数字x二进制下第i位是否为1
//if(((1<<(i-1))&x)>0)
//2.将一个数字x二进制下第i位改为1
//x=x|(1<<(i-1))
//3.将一个数字x二进制下最靠右的第一个1去掉
//x=x&(x-1) 


//33.状态压缩dp例题：小国王 
//在n*n的棋盘上放k个国王，国王可以攻击
//相邻的8个格子，求使他们无法相互攻击的方案总数
//思考： 
//(状态压缩存储：二进制表示状态，十进制存储状态) 
//以3*3棋盘为例，可以用二进制表示每行的放置情况
//每行的所有状态：000，001，010，011，100，101，110，111
//每行的合法状态：000，001，010，100，101 
//判断行内合法：
//  !(i&i>>1)为真则合法
//判断行间兼容(行间合法)
//  !(a&b)&&!(a&b>>1)&&!(a&b<<1)为真则合法
//状态表示：
//dp[i,j,a]表示前i-1行号放置了j个国王，
//第i行号的第a个状态的方案数 
//状态计算：
//dp[i,j,a]=∑dp[i-1,j-c[a],b] 
//总方案数 
//ans=∑dp[n,k,a]
#if 0
#include <iostream>

using namespace std;

//同一行的合法状态个数 
int cnt=0;
//同一行的合法状态集
int s[1<<12];
//每个合法状态包含的国王数
int num[1<<12];

//第i行号放置的国王的状态是a，前1~i-1行号放了j个国王
//            i   j     a 
long long dp[12][144][1<<12];
//dp最大能存12*12的棋盘，最多共放144个国王，
//一行的状态最多有2的12次种 

int main()
{	
	//n*n的棋盘，国王总数k 
	int n,k;
	cin>>n>>k;	

	
	//预处理：
	//枚举一行的所有状态 
	for(int i=0;i<(1<<n);i++)
	{
		//判断行内合法：
	   if(!(i&i>>1))
		{
			s[cnt++]=i;
		}
		
		//统计每个合法状态包含的国王数
		for(int j=0;j<n;j++)
		{
			num[i]+=(i>>j&0x01);
		} 
	} 
	
	//状态计算：
	//不放国王也是一种方案
	dp[0][0][0]=1;
	
	//枚举行号 
	for(int i=1;i<=n+1;i++)
	{
		//枚举国王数 
		for(int j=0;j<=k;j++)
		{
			//枚举第i行号的合法状态 
			for(int a=0;a<cnt;a++)
			{
				//枚举第i-1行号的合法状态 
				for(int b=0;b<cnt;b++)
				{
					//第i行号第a个合法状态的国王数 
					int c=num[s[a]]; 
					
					//可以继续放国王，不存在同列为1
					//且不存在斜对角为1的情况
					if((j>=c)&&!(s[a]&s[b])&&!(s[a]&s[b]>>1)
					&&!(s[a]&s[b]<<1))
					//                ***注1*** 
					dp[i][j][a]+=dp[i-1][j-c][b]; 
				} 
			}
		}
	} 

//***难点*** 
//注1：国王数j减去第i行号第a个合法状态的国王数得到的国王数
//就是第i-1行号放国王的状态，且1~n-2行号共放了j-c个国王

//用背包问题的物品重量与价值的dp表达式关系来理解  


	//第n+1行号放0个国王，且1~n行号共放了k个国王 
	cout<<dp[n+1][k][0]<<endl; 
	//***注***
	//此句相当于
//	int ans=0;
//	for(int i=0;i<cnt;i++)
//	{
//		ans+=dp[n][k][i];
//	} 
//	cout<<ans<<endl;
	
	return 0;
}
//每行包含若干个类，
//每个类累加上一行的兼容类
//每行的类之间无关 

//二进制表示状态，十进制存储状态
//用位运算筛选出合法状态，
//用位运算判断状态转移的条件，
//计算时每个类累加上一行的兼容类 
#endif


//34.理解三维数组 
#if 0
#include<stdio.h>
int main(void)
{
	//将i、j、k想成x、y、z轴 
	
	int a[2][2][2],i,j,k;
	
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
			{
				scanf("%d",&a[i][j][k]);
			}
	
	//三维坐标应该是层号行号列号	
	//相当于是个正方体，其有8个顶点，
	//每个顶点都有一个值 
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


//35.八皇后问题
//朴素的算法 
#if 0
#include <iostream>

using namespace std;

int main()
{
	int count = 0;//计数器
	
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
	printf("一共有%d种方法", count);
	return 0;
}
#endif 
//35.回溯的算法思想，使用递归来解
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
	//从第1行开始 
	solve(0);	

	cout<<count;
	
	return 0;
}
void solve(int r)
{
	//从第1列开始 
	for(int c=0;c<SIZE;c++)
	{		
		if(check(r,c)) 
		{
			qipan[r][c]=true;

			//若下的这颗皇后是在最后一行 
			if(r+1==SIZE)
			{
				show();
				count++;
			}
			else
			solve(r+1);
		}
		//***注***此处不能写else 
		qipan[r][c]=false;
	}
}
bool check(int r,int c)
{
	//若下的是第一行 
	if(r==0)
		return true;
	
	int i,j;
	
	//判断纵向是否有冲突
	for(i=0;i<r;i++) 
	{
		if(qipan[i][c])
			return false;
	}
	
	//判断\对角线是否有冲突
	i=r-1;
	j=c-1;
	
	while(i>=0&&j>=0)
	{
//***注***以下写法错误 
//		if(qipan[i--][j--])
//			return false;
//涉及副作用与序列点的知识 
		if(qipan[i][j])
			return false;
			
		i--;
		j--;
	} 
	
	//判断/对角线是否有冲突
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


//36.输出八皇后的第x种摆放方法 
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
	//从第1行开始 
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
	//从第1列开始 
	for(int c=0;c<SIZE;c++)
	{		
		if(check(r,c)) 
		{
			qipan[r][c]=true;

			//若下的这颗皇后是在最后一行 
			if(r+1==SIZE)
			{
				show();
				count++;
			}
			else
			solve(r+1);
		}
		//***注***此处不能写else 
		qipan[r][c]=false;
	}
}
bool check(int r,int c)
{
	//若下的是第一行 
	if(r==0)
		return true;
	
	int i,j;
	
	//判断纵向是否有冲突
	for(i=0;i<r;i++) 
	{
		if(qipan[i][c])
			return false;
	}
	
	//判断\对角线是否有冲突
	i=r-1;
	j=c-1;
	
	while(i>=0&&j>=0)
	{
//***注***以下写法错误 
//		if(qipan[i--][j--])
//			return false;
//涉及副作用与序列点的知识 
		if(qipan[i][j])
			return false;
			
		i--;
		j--;
	} 
	
	//判断/对角线是否有冲突
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


//37.删数 
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
	
	//把最大的几个数字删掉 
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


//38.分糖果
//先找到最多糖果的人，其分给左右侧较少糖果的那一人 
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
		//迭代器内容相减，得到的是两个迭代器之间的距离
		//即迭代器之间相隔多少个该种类型的元素 
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

//用条件运算符速度更快 
	right=(index==n)?1:index+1;
	
	//分配糖果 
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


//39.推销员 
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
	
	//维护一个结构体数组 
	attributeTypeDef *p=new attributeTypeDef[N+1]{{0,0}};
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].dis;
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>p[i].tire;
	}
	
	//当只向一家住户推销时	
	LL* x1=new LL[N+1]{0};	
	for(int i=1;i<=N;i++)
	{
		//往返加上疲劳值 
		x1[i]=2*(p[i].dis)+p[i].tire; 
	}
	
	auto px1=max_element(x1+1,x1+N+1);
	ans[1]=*px1;
	
	//当向二家及以上住户推销时 
	
	//***难点***
	//路程远的推销疲劳值不一定大
	//路程近的推销疲劳值不一定小 
		
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
//39.解
//贪心+前缀和 
#if 0
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

PII a[N];

int tire[N]; //tire[i]表示前i户Ai的和
int f[N]; //表示前i户Si的最大值
int g[N]; //表示i~n中2Si + Ai的最大值

int main()
{
   int n;
   scanf("%d", &n);
   
   //输入每户到入口的距离Si
   for(int i = 1; i <= n; i ++) 
		scanf("%d", &a[i].first);
   //输入推销产品的疲劳值Ai
   for(int i = 1; i <= n; i ++) 
		scanf("%d", &a[i].second);
   
   //***
   //按照Ai从大到小排序
   //***住户号打乱没有关系的*** 
   sort(a + 1, a + n + 1,
	[](PII p1,PII p2){	return p1.second>p2.second;	});
//   reverse(a + 1, a + n + 1);
   
   //预处理tire[i],表示向前i家住户推销产品的疲劳值前缀和
   for(int i = 1; i <= n; i ++)
		tire[i] = tire[i - 1] + a[i].second;
   
   //预处理f[i],表示从入口到前i家住户距离Si的最大值
   for(int i = 1; i <= n; i ++)
		f[i] = max(f[i - 1], a[i].first);
   
   //预处理g[i],表示2 * Si + Ai的最大值
   //注意，这里从后向前计算, 先计算出小Ai值对应的g[i]
   //因为g[i]表示的是从i~n家2*Si +Ai最大值
   for(int i = n; i >= 1; i --)
		g[i] = max(g[i + 1], 2 * a[i].first + a[i].second);
   
   //输出
   for(int i = 1; i <= n; i ++)
   {
      printf("%d\n", 
		max(tire[i] + 2 * f[i], tire[i - 1] + g[i]));
   }
   
   //阿明向x家住户推销产品的能积累最大疲劳值只有两种情况
   //1.Ai值最大的x家
	//2.Ai值最大的x-1家，然后最后一家尽可能离得远 
   
   return 0;
}
//5
//1 2 3 4 5
//5 4 3 2 1
#endif


//40.排座位 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;

const int SIZE=1010;
bool zuowei[SIZE][SIZE];

//存某行号的出现次数，及某行号的行号值 
typedef struct 
{
	int m_jishu;
	int m_index;
}hangTypeDef;

//存某列号的出现次数，及某列号的列号值 
typedef struct 
{
	int m_jishu;
	int m_index;
}lieTypeDef;

int main()
{
	int M,N,K,L,D;
	cin>>M>>N>>K>>L>>D;
	
	//一定要记得初始化结构体中数据的内容 
	hangTypeDef* ph=new hangTypeDef[M+1]{{0,0}};
	lieTypeDef* pl=new lieTypeDef[N+1]{{0,0}};
	
	int r1,c1,r2,c2;
	for(int i=1;i<=D;i++)
	{
		
		cin>>r1>>c1>>r2>>c2;

//这样标记没用的 
//		zuowei[r1][c1]=zuowei[r2][c2]=true;
		
		if(r1==r2)
		{
			int liehao=min(c1,c2);
			(pl[liehao].m_jishu)++;//某列的权值加一
			pl[liehao].m_index=liehao;//记录列号 
		}
		
		if(c1==c2)
		{
			int hanghao=min(r1,r2);
			(ph[hanghao].m_jishu)++;//某行的权值加一	
			ph[hanghao].m_index=hanghao;//记录行号 
		}
	}
	
	
	//按照某个行号或某个列号出现的次数对结构体进行排序	
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


//41.分纸牌
//对比分糖果
//区别一：分糖果每次只能分一颗，
//此题每次能移动可能不止一张纸牌
//区别二：纸牌堆不是围成一圈的， 
//第一堆只能移到第二堆， 
//最后一堆只能移到倒数第二堆 
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
		//迭代器内容相减，得到的是两个迭代器之间的距离
		//即迭代器之间相隔多少个该种类型的元素 
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

//用条件运算符速度更快 
	right=(index==n)?1:index+1;
	
	//分配纸牌 
	int pos=(v[left]>v[right])?right:left;
	
	//错误思路：每次只分配per_sum-v[pos]张
	//纸牌给左或右侧 
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
//41.解
//我们用贪心算法，按照从左到右的顺序移动纸牌。
//如第i堆的纸牌数不等于平均值，则移动一次，
//分两种情况移动：
//1．若a[i]>v，则将a[i]-v张从第i堆移动到第i+1堆；
//2．若a[i]<v，则将v-a[i]张从第i+1堆移动到第i堆。
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
//进阶： 
//三堆纸牌移动的次数在0~2。
//那什么原因导致移动的次数不同呢？ 总结：
//0次：3堆都为平均数
//1次：第一堆或者第三堆为平均数
//2次：其它情况 
//为1次时，有一堆为平均数不用移动，
//那这时和两堆也没有区别啊，三堆可以分解成两堆+一堆，
//到这里，已经隐约感觉到了有子问题的存在。
//***
//想象这种场景，N堆纸牌，从中间某位置分开，
//左右两边都刚好够分，那么把每一边都看成整体时，
//一定不会有互相移动。因为如果你从左边移x张到右边，
//你必然还会从右边移x张回来，属于多余操作。
//这样两边其实可以看成两个完全独立的子问题
//原文：https://zhuanlan.zhihu.com/p/401123895 


//42.人物相关性分析
//尺取法
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
		//找Alice，将找到的A字母对应的索引值存储进容器A
		//将e字母存储进容器e
		
		//***
		//先保证i值，不让substr()超过字符串的末尾 
		if(i+4>=s.size()||s.substr(i,5)!="Alice") 
			continue;
		
		//(运算符优先级：先与再或)
		if(i-1>=0&&check(s[i-1])||i+5<s.size()&&check(s[i+5]))
			continue;
		
		A.push_back(i); 
		e.push_back(i+4);
	}
	
	for(int i=0;i<s.size();i++)
	{
		//找Bob，将找到的B字母对应的索引值存储进容器B
		//将b字母存储进容器b
		
		//***
		//先保证i值，不让substr()超过字符串的末尾 
		if(i+2>=s.size()||s.substr(i,3)!="Bob") 
			continue;
		
		//(运算符优先级：先与再或)
		if(i-1>=0&&check(s[i-1])||i+3<s.size()&&check(s[i+3]))
			continue;
		
		B.push_back(i); 
		b.push_back(i+2);
	}	
	
	long long ans=0;
	
	//Alice在前，Bob在后的情况
	int left,right;
	left=right=0;
	
	//遍历容器e，容器中存的是每次Alice的e出现的索引值 
	for(int i=0;i<e.size();i++)
	{
		//找到与e配对的索引值最小的B，left为B容器的索引值 
		while(left<B.size()&&B[left]<e[i])
		left++;
		
		//先让right移动到left位置 
		right=max(right,left);
		
		//找到与e配对的索引值最大的B，right为B容器的索引值
		//right-1就得到与e配对的索引值最大的B
		while(right<B.size()&&B[right]-k<=e[i])
		right++;
		
		//最后的+1，理解：1到2，那么有2-1+1即2个Bob 
		ans+=right-1-left+1;
	} 

	//Alice在后，Bob在前的情况
	left=right=0;
	
	//遍历容器A，容器中存的是每次Alice的A出现的索引值 
	for(int i=0;i<A.size();i++)
	{
		//找到与A配对的索引值最小的b，left为b容器的索引值 
		while(left<b.size()&&b[left]+k<A[i])
		left++;
		
		//先让right移动到b和A相聚小于等于K的距离内 
		right=max(right,left);
		
		//找到与A配对的索引值最大的b，right为b容器的索引值
		//right-1就得到与A配对的索引值最大的b
		while(right<b.size()&&b[right]<A[i])
		right++;
		
		//最后的+1，理解：1到2，那么有2-1+1即2个Bob 
		ans+=right-1-left+1;
	}
	
	cout<<ans;
	
	return 0;
}
#endif


//43.K倍区间 
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
//缺陷：
//只能通过2个测试点，其他全部超时 
//枚举法就是有时间复杂度高的缺点 
#endif
//43.改
//我们假设n=5；k=2；
//输入的5个数为1,2,3,4,5的话
//程序输出6，这6种情况分别是123  1234  2345  345  2  4;
//从每一种前缀和(所选两个数的中间的数的和)的情况中
//任意选择两个数组成的区间都满足是k倍区间，
//其计算方法其实就是排列组合，
//上面的例子即可表示为C2 2加上C2 3结果为1+3=4，但实际结果有6种，是由于区间是左开右闭的，加上add[0]的所有结果也就是2和4两种，相当于区间左闭右闭，这两个数本身构成一个k倍区间，4+2=6，刚好是正确答案。
//https://blog.csdn.net/qq_53763705/article/details/123583960
#if 0
#include <iostream>

using namespace std;

int mod[100010];
int add[100010];

int main()
{
	//n个数字，k的倍数，每个数字num 
	int n,k,num;

	cin>>n>>k;

	long long cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		
		//存从第1个数字到第i个数字对应的模值
		mod[i]=(mod[i-1]+num)%k;
		
		//该模值计数加一 
		add[mod[i]]++; 
	} 
	
	//求全排列 
	for(int i=0;i<n;i++)
	{
		cnt+=add[i]*(add[i]-1)/2;
	}
	
	cout<<cnt+add[0]; 

	return 0;
}
#endif 


//44.砝码称重
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const long MAX=1e5;
int dp[110][MAX];
 
int main()
{
	int N;

//错误写法顺序：
//会导致程序运行起来出现难以排查的突然崩溃 
//	long* fama=new long[N+1];	
//	cin>>N;
	
	cin>>N; 
	long* fama=new long[N+1]{0};	
	
	for(int i=1;i<=N;i++)
	{
		cin>>fama[i];
	}

//错误写法：
//由于fama[0]是垃圾值，这样程序运行后也会出现难以排查的突然崩溃	
//	sort(fama,fama+N+1);

	sort(fama+1,fama+N+1); 

	long sum=0;
	for(int i=1;i<=N;i++)
	{
		//第1个到i个砝码的重量的累计值 
		sum+=fama[i];
		
		for(long w=1;w<=sum;w++)
		{
			//砝码重量对应的重量可测 
			if(w==fama[i])
				dp[i][w]=1;			
			else if(w<fama[i])
			{
				//先复制上一行 
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


//45.玩具蛇
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
			//标定可放置的区域 
			space[i][j]=true;
		}
	}
	
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			//***注***
			//必须写以下语句 
			//进入dfs前的初始的位置要标记为已访问 
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
//可以添加代码段
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



















