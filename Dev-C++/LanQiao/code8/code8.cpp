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
    int i,j;
    
    memset(a,0,sizeof(int)*N*N);
    
    int max = 0;
    for(i=1; i<=len1; i++)
	 {
        for(j=1; j<=len2; j++)
		  {
            if(s1[i-1]==s2[j-1]) 
				{
                a[i][j] = a[i-1][j-1]+1; 
                if(a[i][j] > max) 
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
	LL X,Y;
	cin>>X>>Y;
	
	//����õ��ڵ�n����������
	LL n=max(abs(X),abs(Y));
	
	//����Ҫ�ȼ��ϵ�n-1�������εĳ���	
	LL dis=(0+8*(n-1))*n/2;
	
	//��y>=xʱ
	if(Y>=X)
		dis+=2*n+X+Y;
	else//��y<xʱ
		dis+=6*n-X-Y;
		
	cout<<dis;	 

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

long f1(vector<long> v,long d);

int main()
{
	//N����¼��D��ʱ�䳤�ȣ�K���� 
	long N,D,K;
	cin>>N>>D>>K;
	
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

	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //�� ֵ 
		record.insert(pair<long,long>(id,ts));
	}
	
	#if 0
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	#endif
	
	set <long> id;
	vector<long> v1;
	for(auto p=record.begin();p!=record.end();p++)
	{
		//�ҵ�����id�ļ�¼�ķ�Χ 
		auto range=record.equal_range((*p).first); 
		
//		for(auto it=range.first;it!=range.second;it++)
//		cout<<(*it).first<<" "<<(*it).second<<endl;
		
		int count=0;
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
		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***��д*** 

		if(count>=K)
			id.insert((*p).first);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
		cout<<*i<<endl;

	return 0;
}

long f1(vector<long> v,long d)
{
	long count=1;//***ע***��1����0 
	
	sort(v.begin(),v.end());
	
	for(auto it=v.begin();it+1!=v.end();it++)
	{
		if(*(it+1)-*it<d)//������ʱ��ļ��С��d   
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
long f1(vector<long> v,long d);

int main()
{
	//N����¼��D��ʱ�䳤�ȣ�K���� 
	long N,D,K;
	cin>>N>>D>>K;
	
	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //�� ֵ 
		record.insert(pair<long,long>(id,ts));
	}
	
	#if 0
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	#endif
	
	//�����ڱ���multimap���ļ� 
	set<long> ID;	
	for(auto p=record.begin();p!=record.end();p++)
	{
		ID.insert((*p).first);
	} 
	
	//�����������id�� 
	set <long> id;
	//��id�Ŷ�Ӧ�ĸ���ʱ�� 
	vector<long> v1;
	//��set�����Ԫ�ؽ��б��� 
	for(auto p=ID.begin();p!=ID.end();p++)
	{
		//��multimap���ҵ�����ID�ļ�¼�ķ�Χ 
		auto range=record.equal_range((*p)); 
		
		int count=0;

		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***��д*** 

		if(count>=K)
			id.insert(*p);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
//		cout<<*i<<endl;
		printf("%ld\n",*i); 

//***ע***
//Ҫ�����������ʱcout��printf����Ϊ�˲�Ӱ�����������˴���printf() 
	return 0;
}

long f1(vector<long> v,long d)
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

	sort(v.begin(),v.end());
	
	long max_count=1;
	long count=1;
	for(auto it1=v.begin();it1!=v.end();it1++)
	{
		for(auto it2=it1+1;it2!=v.end();it2++) 
		{
			if(*it2-*it1<d)
			{	
				count++;
				max_count=max_count>count?max_count:count;
			}
		}
		
		count=1;
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

const int N=3e5+3;

ll a[N],s[N];
bool vis[N];
int n;

int main()
{
   int T;
   scanf("%d",&T);
   
   while(T--)
	{
      memset(vis,0,sizeof(vis));
   
	   scanf("%d",&n);
   
	   s[0]=0;
   
	   for(int i=1;i<=n;++i)
		{
         scanf("%lld",&s[i]);
         s[i]+=s[i-1];
      }
      
      ll s0=0,sn=s[n];
      
      if(s0>sn) swap(s0,sn);//ǰС���Ϊ����ȡ�����ɱ�������ȡ��ʱ�ظ�ȡ�����⡣ 
      	sort(s,s+n+1);
      	
      int l=0,r=n;
      for(int i=lower_bound(s,s+n+1,s0)-s;i>=0;i-=2)
		{
         a[l++]=s[i],vis[i]=1;
      }
      
      for(int i=lower_bound(s,s+n+1,sn)-s;i<=n;i+=2)
		{
         a[r--]=s[i],vis[i]=1;
      }
      
      for(int i=0;i<=n;++i)
		{
         if(!vis[i]) 
				a[l++]=s[i];
      }
      
      ll res=0;
      
		for(int i=1;i<=n;++i)
         res=max(res,abs(a[i]-a[i-1]));
         
      printf("%lld\n",res);
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

bool mycompare(const long& a,const long& b);

int main()
{
	//���г��ȣ���������
	long n,m;
	cin>>n>>m;
	
	vector<long>v1;
	for(long i=0;i<=n;i++)//0~n��Ϊ�������е��±��Ӧ��
		v1.push_back(i);	 //����0��Ԫ�ز�ʹ�� 
	
//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;
	
	//ʹ��new������ά����
	long (*caozuo)[3]=new long[m+1][3]; 
	
	fill(&caozuo[0][0],&caozuo[0][0]+(m+1)*3,0L);
	
	for(long i=1;i<=m;i++)
	{
		cin>>caozuo[i][1]>>caozuo[i][2];
	}
	
	int i=1;
	while(m--)
	{		
		if(caozuo[i][1]==0)//***ע***sort()�Ƕ�[ )�ķ�Χ������ 
			sort(&v1[1],&v1[caozuo[i][2]]+1,mycompare);
	
		if(caozuo[i][1]==1)
			sort(&v1[caozuo[i][2]],&v1[n]+1);	
				
		i++;
		
		for(auto x:v1)
			cout<<x<<" ";			
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
		cout<<v1[i]<<" ";

	delete []caozuo;

	return 0;
}  
bool mycompare(const long& a,const long& b)
{
	return a>b;
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

bool mycompare(const long& a,const long& b);

int main()
{
	//���г��ȣ���������
	long n,m;
	cin>>n>>m;
	
	vector<long>v1;
	for(long i=0;i<=n;i++)//0~n��Ϊ�������е��±��Ӧ��
		v1.push_back(i);	 //����0��Ԫ�ز�ʹ�� 
	
//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;
	
	//ʹ��new������ά����
	long (*caozuo)[3]=new long[m+2][3]; 
	
	fill(&caozuo[0][0],&caozuo[0][0]+(m+1)*3,2L);
	
	int p,q,max_q=0;
	int count_p_0=0,count_p_1=0;
	for(long i=1;i<=m;i++)
	{
//		cin>>caozuo[i][1]>>caozuo[i][2];
		cin>>p>>q;
		
		//��¼p=0��p=1�������� 
		if(!p)
		{
			count_p_0++;
			count_p_1=0; 
		}	
		else
		{
			count_p_1++;
			count_p_0=0;
		}
		
		//��p=0��p=1���ֵĵ�һ�ε�q����max_q 
		if(count_p_0==1||count_p_1==1)
			max_q=q;
		
		//��p=0���������������ٶ��� 
		if(!p&&count_p_0>=2)
		{
			max_q=max_q>=q?max_q:q;
		}
		else if(p&&count_p_1>=2) 
		{
			max_q=max_q>=q?max_q:q;
		}
		
		caozuo[i][1]=p;
		caozuo[i][2]=max_q;
		
		if(count_p_0>=2||count_p_1>=2)
		{//�����ֵĵ�һ�ε�qҲ��max_q���ǵ� 
			caozuo[i-1][2]=max_q;
		}
	}
	
	int i=1;
	long m1=m;
	while(m1--)
	{		
		if(caozuo[i][1]==0&&caozuo[i+1][1]!=0)
		//***ע***sort()�Ƕ�[ )�ķ�Χ������ 
			sort(&v1[1],&v1[caozuo[i][2]]+1,mycompare);
	
		if(caozuo[i][1]==1&&caozuo[i+1][1]!=1)
			sort(&v1[caozuo[i][2]],&v1[n]+1);	
				
		i++;
		
		for(auto x:v1)
			cout<<x<<" ";			
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
		cout<<v1[i]<<" ";

	delete []caozuo;

	return 0;
}  
bool mycompare(const long& a,const long& b)
{
	return a>b;
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
bool visit[100010]={0};	
//��ĳ�η�������Ϣ���ļ����ڵ��洢��Ϣ 
set<int>s1;
//����������� 
void dfs(int n1);

int main()
{
	//�ڵ��������������� 
	int m;
	cin>>n>>m;
	
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
	long *message=new long[n+1];
	
	fill(message,message+n+1,0);
	
	//����� 
	queue<CaozuoTypeDef>q1;
	
	for(int i=0;i<m;i++)
	{
		CaozuoTypeDef CaozuoStruct;
		cin>>CaozuoStruct.a>>
		CaozuoStruct.b>>CaozuoStruct.c;
		
		q1.push(CaozuoStruct);
	}	
	
	while(!q1.empty())
	{
		//�ж�ĳ�β�����1����2 
		if(q1.front().a==1)
		{
			//�ڽӾ���Խ���Ԫ�ض���1����ʾ��ͨ 
			net[q1.front().b][q1.front().c]=1;
			net[q1.front().c][q1.front().b]=1;
		}
		else
		{
			//DFS�����ļ����ڵ��洢��Ϣ�����ڵ�Ŵ���set���� 
			dfs(q1.front().b);
			
			for(auto it=s1.begin();it!=s1.end();it++)
			{
				message[*it]+=q1.front().c;
			}
			
			//***ע***
			//�������䲻���٣���
			//ÿ��ִ�в���2ʱ��set�������ݾ�Ϊ��
			//�ҷ��ʱ��Ҳ��Ϊ0��Ϊ��dfs���������� 
			s1.clear();
			fill(visit,visit+100010,0);
		}
		
		q1.pop();
	}
	
	for(int i=1;i<=n;i++)
		cout<<message[i]<<" ";
	
	delete []message; 

	return 0;
} 

void dfs(int n1)
{	
	if(!visit[n1])
	{		
		visit[n1]=1;
		s1.insert(n1);//ע��˾�ŵ�λ�� 

		for(int i1=1;i1<=n;i1++)
		{
			if(net[n1][i1])//��n1����i1������ͨ 
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

void merge(int a,int b);
int get(int x);

int main()
{
	//�ڵ��������������� 
	int n,m;
	cin>>n>>m;
	
	//1.��ʼ��
	//ÿ���ڵ����Ϊһ�����ϣ�
	//�Ҽ��ϵĸ��ڵ�Ϊ�Լ� 
	for(int i=1;i<=n;i++) 
		fa[i]=i;      

	//���������ڵ�a���ڵ�b 
	int id,a,b;
	
	for(int i=0;i<m;i++)
	{
		cin>>id>>a>>b;
		
		if(id==1)
		{
			merge(a,b);
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				//ÿ��һ���ڵ���a���ڵļ����� 
				if(get(a)==get(j))
					message[j]+=b; 
			}
		}
	}

	for(int i=1;i<=n;i++)
	{	
		printf("%lld",message[i]);
		
		if(i<n)
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
void merge(int a,int b)
{
	int aa=get(a);
	int bb=get(b);
	
	if(aa!=bb)
		fa[aa]=bb;
}

//3.��
//���ҽڵ����ڼ��ϵĸ��ڵ㣬
//�˴���·��ѹ���Ĳ��ҷ��� 
int get(int x)
{
	if(fa[x]==x)
		return x;
	else
	{
		fa[x]=get(fa[x]);
		
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
	if (b==0)
		return a;
	else 
	   return measure(b,a%b); 

	//������algorithmͷ�ļ��а�����__gcd() 
	//return __gcd(a, b);

	//���䣺��С������=�����˻�/���Լ��
}

int main()
{
	MGraph* G=new MGraph;
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

	cout << Dis[0][MAXVEX-1];

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
				G->arc[i][j] = (i+1) * (j+1) / __gcd(i+1,j+1);
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
					G->arc[i][j] = (i+1) * (j+1) / __gcd(i+1,j+1);
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





























