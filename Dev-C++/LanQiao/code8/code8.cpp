//8.1 其他算法
//最短路径算法——迪杰斯特拉算法，弗洛伊德算法
//并查集算法


//8.2 最大公共子串
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


//8.3 螺旋折线 
//***思路***
//处理成n个矩形，算距离时先加上矩形的长度
//根据坐标值，
//推算出与起点坐标之间的关系 
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
	
	//计算该点在第n个正方形上
	LL n=max(abs(X),abs(Y));
	
	//计算要先加上的n-1个正方形的长度	
	LL dis=(0+8*(n-1))*n/2;
	
	//当y>=x时
	if(Y>=X)
		dis+=2*n+X+Y;
	else//当y<x时
		dis+=6*n-X-Y;
		
	cout<<dis;	 

	return 0;
}
#endif


//8.4 日志统计 
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
	//N条记录，D的时间长度，K个赞 
	long N,D,K;
	cin>>N>>D>>K;
	
//***注***
//不能使用multiset关联容器，
//因为对于此容器来说，值就是键，即pair对象，
//那么查询也只能查pair对象 

//	multiset<pair<long,long>>record;
	
//	for(int i=0;i<N;i++)
//	{
//		long ts,id;
//		cin>>ts>>id;					 //错误理解： 
//								          //键 值 
//		record.insert(pair<long,long>(id,ts));
//	}
//	
//	for(auto p=record.begin();p!=record.end();p++)
//	{
//		auto range=record.equal_range((*p).first);//编译错误 
//		
//	}

	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //键 值 
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
		//找到含该id的记录的范围 
		auto range=record.equal_range((*p).first); 
		
//		for(auto it=range.first;it!=range.second;it++)
//		cout<<(*it).first<<" "<<(*it).second<<endl;
		
		int count=0;
		//***注***range.second-1无定义 
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
		//由于不能保证同一键对应的值是升序排列的，那么把
		//这些值存入vector中，对数组进行排序后计算时间间隔 
		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***必写*** 

		if(count>=K)
			id.insert((*p).first);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
		cout<<*i<<endl;

	return 0;
}

long f1(vector<long> v,long d)
{
	long count=1;//***注***是1不是0 
	
	sort(v.begin(),v.end());
	
	for(auto it=v.begin();it+1!=v.end();it++)
	{
		if(*(it+1)-*it<d)//若两个时间的间隔小于d   
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
//改进：
//用set的元素值来对multimap的记录进行查找，
//减少对multimap重复查找的次数 
#if 0
#include <iostream>
#include <set>
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std;

//计算符合时间间隔的赞的数量 
long f1(vector<long> v,long d);

int main()
{
	//N条记录，D的时间长度，K个赞 
	long N,D,K;
	cin>>N>>D>>K;
	
	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //键 值 
		record.insert(pair<long,long>(id,ts));
	}
	
	#if 0
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	#endif
	
	//存用于遍历multimap键的键 
	set<long> ID;	
	for(auto p=record.begin();p!=record.end();p++)
	{
		ID.insert((*p).first);
	} 
	
	//存符合条件的id号 
	set <long> id;
	//存id号对应的各个时间 
	vector<long> v1;
	//对set对象的元素进行遍历 
	for(auto p=ID.begin();p!=ID.end();p++)
	{
		//在multimap中找到含该ID的记录的范围 
		auto range=record.equal_range((*p)); 
		
		int count=0;

		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***必写*** 

		if(count>=K)
			id.insert(*p);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
//		cout<<*i<<endl;
		printf("%ld\n",*i); 

//***注***
//要输出大量数据时cout比printf慢，为了不影响评测结果，此处用printf() 
	return 0;
}

long f1(vector<long> v,long d)
{
	//***注***
	//错误理解：
	//只要两个赞的时间间隔小于d，则满足条件 
	
//	//赞的数量 
//	long count=1;//***注***是1不是0 
//	
//	sort(v.begin(),v.end());
//	
//	for(auto it=v.begin();it+1!=v.end();it++)
//	{
//		if(*(it+1)-*it<d)//若两个时间的间隔小于d   
//		{
//			count++;
//		}		
//	}

	//正确理解： 
	//记录的某一时刻开始的d时间段内的赞的数量，
	//在另一个时刻开始的d时间段记录时赞要回到1 

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


//8.5 灵能传输 
//***理解有难度*** 
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
      
      if(s0>sn) swap(s0,sn);//前小后大，为方便取数，可避免讨论取数时重复取的问题。 
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


//8.6 双向排序 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(const long& a,const long& b);

int main()
{
	//序列长度，操作次数
	long n,m;
	cin>>n>>m;
	
	vector<long>v1;
	for(long i=0;i<=n;i++)//0~n，为了与序列的下标对应，
		v1.push_back(i);	 //索引0的元素不使用 
	
//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;
	
	//使用new创建二维数组
	long (*caozuo)[3]=new long[m+1][3]; 
	
	fill(&caozuo[0][0],&caozuo[0][0]+(m+1)*3,0L);
	
	for(long i=1;i<=m;i++)
	{
		cin>>caozuo[i][1]>>caozuo[i][2];
	}
	
	int i=1;
	while(m--)
	{		
		if(caozuo[i][1]==0)//***注***sort()是对[ )的范围的排序 
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
//重复的操作数量太多，不能AC程序
//考虑对于连续的几个同样的操作，取范围最大的那个操作 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(const long& a,const long& b);

int main()
{
	//序列长度，操作次数
	long n,m;
	cin>>n>>m;
	
	vector<long>v1;
	for(long i=0;i<=n;i++)//0~n，为了与序列的下标对应，
		v1.push_back(i);	 //索引0的元素不使用 
	
//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;
	
	//使用new创建二维数组
	long (*caozuo)[3]=new long[m+2][3]; 
	
	fill(&caozuo[0][0],&caozuo[0][0]+(m+1)*3,2L);
	
	int p,q,max_q=0;
	int count_p_0=0,count_p_1=0;
	for(long i=1;i<=m;i++)
	{
//		cin>>caozuo[i][1]>>caozuo[i][2];
		cin>>p>>q;
		
		//记录p=0和p=1连续几次 
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
		
		//将p=0和p=1出现的第一次的q赋给max_q 
		if(count_p_0==1||count_p_1==1)
			max_q=q;
		
		//若p=0，且连续出现至少二次 
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
		{//将出现的第一次的q也用max_q覆盖掉 
			caozuo[i-1][2]=max_q;
		}
	}
	
	int i=1;
	long m1=m;
	while(m1--)
	{		
		if(caozuo[i][1]==0&&caozuo[i+1][1]!=0)
		//***注***sort()是对[ )的范围的排序 
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
//修改：
//利用栈，栈元素是pair<int,int>
//这样可以很方便地对连续的p值对应的不同的q取最大的q值，
//并把旧数据弹出，新数据加入 


//8.7 网络分析 
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

//已访问标记 
bool visit[100010]={0};	
//存某次发送完消息后哪几个节点会存储信息 
set<int>s1;
//深度优先搜索 
void dfs(int n1);

int main()
{
	//节点数量，操作数量 
	int m;
	cin>>n>>m;
	
//建立邻接矩阵 
//***注***
//建立二维数组 
//失败： （二维数组的列值必须为常量） 
//	int (*net)[n]=new int[n][n];
//成功： 
//	int (*net)[3]=new int[n][3];

//	fill(&net[0][0],&net[0][0]+n*n,0);
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			cout<<net[i][j]<<" ";
//		cout<<endl;
//	}
	
	//创建各节点存储信息大小的数组 
	long *message=new long[n+1];
	
	fill(message,message+n+1,0);
	
	//存操作 
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
		//判断某次操作是1还是2 
		if(q1.front().a==1)
		{
			//邻接矩阵对角线元素都置1，表示连通 
			net[q1.front().b][q1.front().c]=1;
			net[q1.front().c][q1.front().b]=1;
		}
		else
		{
			//DFS搜索哪几个节点会存储信息，将节点号存入set对象 
			dfs(q1.front().b);
			
			for(auto it=s1.begin();it!=s1.end();it++)
			{
				message[*it]+=q1.front().c;
			}
			
			//***注***
			//以下两句不能少！！
			//每次执行操作2时，set对象内容均为空
			//且访问标记也都为0，为了dfs能正常进行 
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
		s1.insert(n1);//注意此句放的位置 

		for(int i1=1;i1<=n;i1++)
		{
			if(net[n1][i1])//若n1点与i1点有连通 
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
//并查集法
#if 0
#include <iostream>

using namespace std;

int fa[10010];
long long message[10010];

void merge(int a,int b);
int get(int x);

int main()
{
	//节点数量，操作数量 
	int n,m;
	cin>>n>>m;
	
	//1.初始化
	//每个节点各自为一个集合，
	//且集合的根节点为自己 
	for(int i=1;i<=n;i++) 
		fa[i]=i;      

	//操作数，节点a，节点b 
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
				//每有一个节点在a所在的集合内 
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

//2.并
//***错误理解*** 
//将a的根节点设置为b 
//正确理解：
//将a所在的集合和b所在的集合进行合并
//若两个集合不为同一个集合，则 
//将a所在集合的根节点设置为b所在的根节点 
void merge(int a,int b)
{
	int aa=get(a);
	int bb=get(b);
	
	if(aa!=bb)
		fa[aa]=bb;
}

//3.查
//查找节点所在集合的根节点，
//此处用路径压缩的查找方法 
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


//8.8 路径 
#if 0
#include <iostream>
#include <cmath>
#include <algorithm>
							//***注***不能设的太小 
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

	//法二：algorithm头文件中包含的__gcd() 
	//return __gcd(a, b);

	//补充：最小公倍数=两数乘积/最大公约数
}

int main()
{
	MGraph* G=new MGraph;
	CreateMGraph(G);

	//函数使用堆叠的 "49021384" 字节。请考虑将一些数据移动到堆。
	//	//最短路径矩阵 
	//	long Path[MAXVEX][MAXVEX];
	//	//最短路径权值和矩阵 
	//	int D[MAXVEX][MAXVEX]; /* 求某点到其余各点的最短路径 */

	//最短路径矩阵path
	int(*Path)[MAXVEX] = new int[MAXVEX][MAXVEX];
	//最短路径权值和矩阵distance
	long(*Dis)[MAXVEX] = new long[MAXVEX][MAXVEX];

	ShortestPath_Floyd(G, Path, Dis);

	cout << Dis[0][MAXVEX-1];

	delete[]Path;
	delete[]Dis;

	return 0;
}
void CreateMGraph(MGraph* G)
{
	//顶点数 
	G->numVertexes = MAXVEX;

	/* 初始化顶点 */
//	for (int i = 0; i < G->numVertexes; i++)
//	{
//		G->vertex[i] = i+1;
//	}

	for (int i = 0; i < MAXVEX; i++)
	{
		for (int j = 0; j < MAXVEX; j++)
		{
		//***注*** 
		//错误写法：	
		#if 0 
			//顶点到本身的边不存在 
			if (i == j)
				G->arc[i][j] = 0;
			else//顶点到其他顶点的边默认无限长 
				G->arc[i][j] = GRAPH_INFINITY;

			if (abs(i - j) > 21)
				continue;
			else				//***注***必须要写+1 
				G->arc[i][j] = (i+1) * (j+1) / __gcd(i+1,j+1);
		#endif
		
		//正确写法： 
			//顶点到本身的边不存在 
			if (i == j)
				G->arc[i][j] = 0;
			else//顶点到其他顶点的边默认无限长 
			{
				G->arc[i][j] = GRAPH_INFINITY;

				if (abs(i - j) > 21)
					continue;
				else				//***注***必须要写+1 
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
	//初始化P和D
	for (int v = 0; v < G->numVertexes; v++)
	{
		for (int w = 0; w < G->numVertexes; w++)
		{
			P[v][w] = w;
			D[v][w] = G->arc[v][w];
		}
	}

	//中转顶点
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





























