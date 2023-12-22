//6.1 �����㷨 
//������ȱ���(DFS)��������ȱ���(BFS) 
//       ջ						���� 
#if 0
#include <iostream>

using namespace std;

const int ROW=14,COL=17;
int migong [ROW][COL];
int mark[ROW][COL];
int ox,oy;
bool seek_path(int ix,int iy);
int main()
{
	freopen("6.1.txt","r",stdin); 
	
//	int XLEN,YLEN;
//	cin>>XLEN>>YLEN;
	
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++)
		{
			cin>>migong[i][j];
			mark[i][j]=0;
		}	
	
	cout<<"������꣺";
	int ix,iy;
//	cin>>ix>>iy;
	ix=1;
	iy=0;
	
	//��ڱ��Ϊ�ѷ���
	mark[1][0]=1; 
	
	cout<<"�������꣺";

//	cin>>ox>>oy;
	ox=12;
	oy=16;
	
	if(seek_path(ix,iy))
		cout<<"("<<ix<<","<<iy<<")"<<endl;//�������������
	else
		cout<<"ERROR";
		
	return 0;
}

//�������� 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool seek_path(int ix,int iy)
{
	if(ix==ox&&iy==oy)
		return true;
	
	int m,n;
	
	for(int i=0;i<4;i++)
	{
		m=ix+dx[i];
		n=iy+dy[i];
		
		//���ͨ����δ�����ʹ� 
		if(migong[m][n]==0&&mark[m][n]==0)
		{
			//���Ϊ�ѷ��ʹ�
			mark[m][n]=1;
			
			//�ݹ���̽
			if(seek_path(m,n))
			{
				//�������·������
				cout<<"("<<m<<","<<n<<")"<<endl;
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
const int N=6;

bool mark[N+1][N+1]; //���δ��ʼ���ⲿ���������ǻᱻ�Զ���ʼ��Ϊ 0����һԭ��Ҳ�������ⲿ���������Ԫ�ء�
void dfs(int x,int y);
int count;

int main()
{	
	//�����ĵ���Ϊ�ѷ��� 
	mark[3][3]=true;
	dfs(3,3);
	cout<<count/4;//��ת�Գ�����ͬһ�ַָ�����Ҫ����������� 

	return 0;
}

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y)
{
	//����һ���ѵ���߽� 
	if (x==0||x==N||y==0||y==N)
	{
		count++;
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		int m=x+dx[i];
		int n=y+dy[i];
		
		if(mark[m][n]==0)
		{
			mark[m][n]=true;
			
			//�õ����(3,3)�Գƴ��ĵ�Ҳ���Ϊ�ѷ���
			mark[N-m][N-n]=true;
			
			dfs(m,n); 
			
			//����·���ϵĵ�����Ϊδ���� 
			mark[m][n]=false;
			mark[N-m][N-n]=false;			
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

int max(int a,int b);
void dfs(int num,int sum);
int main()
{
	freopen("6.3.txt","r",stdin);
	
	int shuzu[20][6];
	
	for(int i=0;i<20;i++)
		for(int j=0;j<6;j++)
			cin>>shuzu[i][j];			
	
//	for(int i=0;i<20;i++)
//	{	for(int j=0;j<6;j++)	
//			cout<<shuzu[i][j]<<' ';
//		cout<<endl;		
//	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<20;j++)
		rates[i].push_back(shuzu[j][i+1]);
	} 
	
//	for(int i=0;i<20;i++)
//	cout<<rates[0][i]<<' ';

	dfs(0,0); 
	cout<<max_sum<<endl;

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
void dfs(int num,int sum)
{
	if(num>4)//num��0��4����5��λ 
	{
//		cout<<sum<<endl;
		max_sum=max(max_sum,sum);
		return;
	}		
	
	for(int i=0;i<20;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
//***ע***
//�ر�ע��Ҫ��ɵݹ�ʱ��Ӧ�ðѵݹ���µ�������
//д�ڱ��������������ڣ��������ں����⴦��ú�
//��д�ڱ��������������� 
//			sum+=rates[num][i];
//       dfs(num+1,sum);

			dfs(num+1,sum+rates[num][i]);
			
			mark[i]=0;
		}
		else
			continue;
	}
	return;
}

int max(int a,int b)
{
	return (a>b)?a:b;
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
 
#endif


//6.4 ȫ���ů 
#if 0
#include <iostream>

using namespace std;

bool mark[1000][1000];
char picture[1000][1000];
int N;

void dfs(int a,int b);
int main()
{
	cin>>N;
	
	char data[N][N];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin>>data[i][j];
		} 
	
	//��data���ݷŵ�picture[1][1]��ʼ��λ�� 
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			picture[i+1][j+1]=data[i][j];		
		}
		
	//��μ��㵺��������
	
	mark[1][1]=1;
	dfs(1,1);
	
	int count=0;
	for(int i=1;i<N+1;i++)
		for(int j=1;j<N+1;j++)	 
		{
			if(picture[i][j]=='#')
			count++;
		}
		
	cout<<count;
		
	return 0;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x,int y)
{
	if(x==7&&y==7)						//------>x�� 
	{										//|
		cout<<"Done! "<<endl;		//|
		return;							//�� y�� 
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(picture[nx][ny]=='.'&&mark[nx][ny]==0)
		{
			mark[nx][ny]=1;
			
			cout<<"("<<nx<<","<<ny<<")"<<" ";
			//1�ź�ˮ��û4�������½�أ�����û���Ϊ* 
			if(picture[nx][ny+1]=='#')
			picture[nx][ny+1]='*';	
			
			if(picture[nx][ny-1]=='#')		
			picture[nx][ny-1]='*';
			
			if(picture[nx-1][ny]=='#')
			picture[nx-1][ny]='*'; 
			
			if(picture[nx+1][ny]=='#')
			picture[nx+1][ny]='*';
			
			dfs(nx,ny);		
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

const int maxn=1005;
int mark[maxn][maxn];

string island[maxn];
int n,flag,sum;

void dfs(int x, int y);

int main()
{
   cin >> n;
   for(int i = 0; i < n; ++i)
   cin >> island[i];
   
   for(int i = 0; i < n; ++i)
   {
       for(int j = 0; j < n; ++j)
       {
           if(island[i][j] =='#'&&mark[i][j]==0)
           {
               flag=0;
               dfs(i,j);
               if(!flag)//���flag=0,��ʾ�����������û���ҵ����ʵģ����ջ���ʧ,sum�ۼ�û���ҵ��ġ� 
               ++sum;	//���flag=1,��ʾ������������ҵ��˺��ʵģ����ǽ�flag��Ϊ1�� 
           } 
       }
   }
   cout<<sum;
   return 0;
}
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; 
void dfs(int x, int y)
{
	//����߹���½�� 
   if(island[x][y] =='#'&&!mark[x][y])
       mark[x][y] = 1;
   else
       return;
       
   //�ж��Ƿ�������� 
   if(island[x][y+1]=='#'&&island[x][y-1]=='#'
	&&island[x+1][y]=='#'&&island[x-1][y]=='#')
   flag = 1;
   
   //������������  
	for(int i=0;i<4;i++)
	{
		dfs(x+dx[i],y+dy[i]);
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
const int ROW=30,COL=50;
char migong[ROW][COL+1];
bool mark[ROW][COL];

//�ṹ��node��¼xy������ߵ�˳��
struct node
{
	int x;
	int y;
	string s;
};

struct node create_node(int x,int y,string s)
{
	struct node temp;
	temp.x=x;
	temp.y=y;
	temp.s=s;
	
	return temp;
}
					//���� ����  ����  ���� 
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char zimu[4]={'D','L','R','U'};
bool visited[100][100];

void bfs(int x,int y); 
int main()
{
	freopen("6.5.txt","r",stdin);
	
	for(int i=0;i<ROW;i++)
		cin.getline(migong[i],COL+1);//***ÿ�ж�COL���ַ�*** 
	
	bfs(0,0); 
	
	return 0; 
}
void bfs(int x,int y)
{
	queue<node> qn;
	
	qn.push(create_node(0,0,""));
	visited[x][y]=1;
	
	while(!qn.empty())
	{
		node t=qn.front();
		qn.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int xn=t.x+dir[i][0];
			int yn=t.y+dir[i][1];
			
			//��δԽ����δ�����Ҳ����ϰ� 
			if(xn>=0&&xn<ROW&&yn>=0&&yn<COL&&
			!visited[xn][yn]&&migong[xn][yn]!='1')
			{
				if(xn==ROW-1&&yn==COL-1)
				{
					cout<<t.s<<zimu[i]<<endl;	//ע��ҲҪ��zimu[i]һ�������Ϊ��ʱ����û�б��ӵ�t.s
					return;
				}
				else
				{
					visited[xn][yn]=1;//Ӧ����string��+��������غ�����ƴ���ַ��� 
					qn.push(create_node(xn,yn,t.s+zimu[i]));
				}
			}
		}	
	}
}
#endif



































