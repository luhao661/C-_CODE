//7.1 ��̬�滮
//������������ֽ�����������⣬��˳����������� 
//ǰһ��������Ľ�Ϊ��һ�������������ṩ�����õ���Ϣ
//***�ȳ���дdp����ٳ��Խ���״̬ת�Ʒ���***
//���ǳ�ʼ�����ͱ߽����

//������̰���㷨
//̰���㷨���ܱ�֤��õ����������Ž⣬
//̰���㷨ʹ�õ�ǰ���Ǿֲ����Ž��ܲ���ȫ�����Ž� 

//�һ�Ӳ������ 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=65535;
int main()
{
	int n=21;
	int a[3]={2,5,9};
	
	int cc[21];//0~21ΪҪ�õ���Ӳ������ֵ 
	
	cc[0]=0;
	for(int i=1;i<=n;i++)//Ӳ�ҵ�����ֵ 
	{
		cc[i]=MAX;//��Ĭ�ϴղ��� 
		for(int j=0;j<=2;j++)
		{
			//����ֵ���ڵ������е�Ӳ�ҵ���ֵ��
			//����ֵ��ȥ������ֵ���ܹ���֮ǰ������յ� 
			if(i>=a[j]&&cc[i-a[j]]!=MAX)
				cc[i]=min(cc[i-a[j]]+1,cc[i]);//algorithmͷ�ļ��е�min() 
		}
	}

	cout<<cc[21]<<endl;

	return 0;
}
#endif 
//***ע***
//algorithmͷ�ļ���ʵ�õĺ�����
//min()��max()��abs()
//swap()��reverse()��sort() 
//find()��upper_bound()��lower_bound()
//fill()��count()��foreach() 
//__gcd()
//set_intersection()��set_union()��set_difference() 
//next_permutation()


//01�������� 
//��N����Ʒ��һ������ܴ�����ΪW�ı�����
//��i����Ʒ��������weight[i]���õ��ļ�ֵ��value[i]
//***ÿ����Ʒֻ����һ��***��
//��⽫��Щ��Ʒװ�뱳������Ʒ��ֵ�ܺ���� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items,num_weight;
	
	int value[100][100];
	int w[100],v[100];//�����������ֵ

	cin>>num_items>>num_weight;
	
	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//�����һ�У� 
	//��ά����ĵ�һ��ȫΪ0����ʾ��0����Ʒ��������Ϊ
	//0~num_weight�ı�������ֵΪ0	
	fill(value[0],&value[0][num_weight],0); 

//	for(int i=0;i<=num_weight;i++)
//		cout<<value[0][i]<<" ";

	//��x����Ʒ�Ƿ���뱳��
	for(int i=1;i<=num_items;i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[i][0]=0;
		
		//��x����Ʒ��������Ϊ1~num_weight�ı��� 
		for(int j=1;j<=num_weight;j++)
		{	
			//��������ǰ����(����)С�ڵ�x����Ʒ��������
			//�򱳰���ǰ�����������Ʒ��ֵ��Ϊ�ϼ���Ʒ�����
			//�ļ�ֵ 
			if(j<w[i])			 
			value[i][j]=value[i-1][j];//***ע***��û�д˾䣬�����ֲ���Ԫ����0�Ĳ��������
			
			//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			else 
			value[i][j]=
			max(value[i-1][j],
			value[i-1][j-w[i]]+v[i]);
			//����װ��i����Ʒ����
			//��ֵ��װ��i-1����Ʒ������Ϊj��
			//����ʱ�ļ�ֵ��
			//��װ��i����Ʒ����
			//��ֵ��װ��i-1����Ʒ������Ϊj-w[i]��
			//����ʱ�ļ�ֵ���ϵ�i����Ʒ�ļ�ֵ 
			
			//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
			//����ѡ���µļ�ֵ��ȡ���ֵ	
		} 												
	}
	
	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout<<value[num_items][num_weight]<<endl;
	
	//����dp�� 
	for(int i=0;i<=num_items;i++)
	{	for(int j=0;j<=num_weight;j++)
		{
			printf("%4d",value[i][j]); 
		}
		cout<<endl;
	}
	
	//��ʾnum_items����Ʒ����num_weight������
	//��������ֵ���ʱ��������ļ�����Ʒ 
	while(value[num_items][num_weight]!=0)
	{
		if(value[num_items][num_weight]>
		value[num_items-1][num_weight])
		{
			cout<<num_items<<" ";
			num_weight-=w[num_items];
		} 
		
		num_items--;
	} 
	cout<<num_items; 
	
	return 0;
} 
//5 10
//5 10
//3 5
//4 8
//4 9
//2 6
#endif
//dp��ά����ĸĽ���(�Ż��ռ临�Ӷ�)
//����ά����ѹ����һά���飬
//ÿ��ѭ�����Ƕ�һά������Ԫ�ص�ֵ�ġ�ˢ�¡� 
//value[i][j]=
//			max(value[i-1][j],
//			value[i-1][j-w[i]]+v[i]); 
			
//value[j]=
//			max(value[j],
//			value[j-w[i]]+v[i]);
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//�����������ֵ

	cin>>num_items>>num_weight;
	
	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value,value+100,0); 

	//��x����Ʒ�Ƿ���뱳��
	for(int i=1;i<=num_items;i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0]=0;
		
		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***
		//ѭ���������Ϊ���� 
		//����ʱҪ�Ӻ���ǰ����
		//��Ϊ����Ԫ��ֵʱҪ�õ�����ǰ�����(������) 
		for(int j=num_weight;j>=1;j--)
		{	
			//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			if(j>=w[i])
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		} 							  //����ѡ���µļ�ֵ��ȡ���ֵ				
	
		//��ʾÿ��״̬���º��dp�� 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout<<value[num_weight]<<endl;
	
	//��ʾ����״̬��dp�� 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
#endif


//��ȫ�������� 
//��N����Ʒ��һ������ܴ�����ΪW�ı�����
//��i����Ʒ��������weight[i]���õ��ļ�ֵ��value[i]
//***ÿ����Ʒ��������ʹ��***��
//��⽫��Щ��Ʒװ�뱳������Ʒ��ֵ�ܺ����
//˼���� 
//������ʵ�����ޣ�����Ϊ��ǰ��������
//���Ը���Ʒ����������˵õ�
//������ȫ�����㷨 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//�����������ֵ

	cin>>num_items>>num_weight;
	
	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value,value+100,0); 

	//��x����Ʒ�Ƿ���뱳��
	for(int i=1;i<=num_items;i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0]=0;
		
		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***(С����) 
		//����ʱҪ�Ӻ���ǰ����
		//��Ϊ����Ԫ��ֵʱҪ�õ�����ǰ����� 
		for(int j=num_weight;j>=1;j--)
		{	
			//��i����Ʒ��1����ʼ�ã�
			//�õ�j/w[i]��Ϊֹ 
			for(int k=1;k<=j/w[i];k++) 
			{
				//��������ǰ�������ڵ���k����x����Ʒ������ 
				if(j>=k*w[i])
				value[j]=
				max(value[j],
				value[j-k*w[i]]+k*v[i]);
			}
		} 									
	
		//��ʾÿ��״̬���º��dp�� 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout<<value[num_weight]<<endl;
	
	//��ʾ����״̬��dp�� 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
//4 10
//2 1
//3 3
//4 5
//7 9
#endif
//������ȫ�����㷨�Ľ���
//дdp���Ƶ�״̬ת�Ʒ���
//***ע***
//����01������״̬ת�Ʒ�������ȫ������һ��(����P121) 
//����άdp�����Ż���һά���� 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  ��Ʒ����  ���������� 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//�����������ֵ

	cin>>num_items>>num_weight;
	
	//***ע***
	//����dp(dynamic programming��̬�滮)��
	//״̬ת�Ʒ��̣���������
	//i-1������ֵ����������Դ˴�����������
	//��1��ʼ�ȽϺ� 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//һά����Ԫ�ض��ȸ�ֵΪ0 
	fill(value,value+100,0); 

	//��x����Ʒ�Ƿ���뱳��
	for(int i=1;i<=num_items;i++)
	{
		//�����һ�У� 
		//��x����Ʒ��������Ϊ0�ı�������ֵΪ0 
		value[0]=0;
		
		//��x����Ʒ��������Ϊ1~num_weight�ı���
		//***ע***
		//ѭ���������Ϊ˳�� 
		//����ʱҪ��ǰ���󸲸�
		//��Ϊ����Ԫ��ֵʱҪ�õ��µ�����
		#if 0 
		for(int j=1;j<=num_weight;j++)
		{	
			//��������ǰ����(����)���ڵ��ڵ�x����Ʒ������ 
			if(j>=w[i])
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		} 							  //����ѡ���µļ�ֵ��ȡ���ֵ				
		#endif
	
		//�ٴ��Ż��� 
		for(int j=w[i];j<=num_weight;j++)
		{	
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//�Ƚϲ�װ���x����Ʒ����װ���x����Ʒ�� 
		}
	
		//��ʾÿ��״̬���º��dp�� 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//���num_items����Ʒ����num_weight������
	//��������ֵ����Ƕ��� 
	cout<<value[num_weight]<<endl;
	
	//��ʾ����״̬��dp�� 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
#endif 


//7.2 ���Ӵ���
//***˼·***
//��Ŀ˵����ÿ�����ӵĸ���������ÿ������������
//�����޵ģ��ɴ��뵽��ȫ�������⡣���Ҫ�ճ�
//����������Ҫ����a1x1+a2x2+a3x3+��+anxn=c��
//���಻�����̡�
//���ۣ�����nά��ʽ�ӣ����£�
//a1x1+a2x2+a3x3+��+anxn=c�����a1,a2,a3��an
//���ʣ���x1,x2,x3��xnһ���н����������� 
//����x1,x2,...xn>=0�Ҷ�Ϊ����ʱ,���·��̽�ĸ������ޣ�
//���޽⡣ 
//���a1,a2,a3��an������,��ô����������cʹ��
//�����޽⡣
//�����Լ����Ϊ1���������޸��ղ���
//�����Լ��Ϊ1�����迼������ȫ����˼�����
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	//��ͬ���������� 
	int N;
	cin>>N;
	
	//��ͬ�������İ��Ӹ��� 
	int zhenglong[N]={0};
	
	//��x���������İ��Ӹ��� 
	for(int i=1;i<=N;i++)
		cin>>zhenglong[i];
	
	int gongyinshu;
	for(int i=1;i<N;i++)
	{
		gongyinshu=__gcd(zhenglong[i],zhenglong[i+1]);
	} 
	
	if(gongyinshu!=1)
	{
		cout<<"INF";
		return 0;
	}
	
	int dp[20000];
	fill(dp,dp+20000,0);
	
	//***ע***
	//��ȫ��������ı����ļ�ֵ����Ӧ
	//����dp[x]��0��1��
	//���õ�Ҫ��İ���������1�����ܾ���0 
	
	//Ҫ0�����ӿ϶��ܴճ� 
	dp[0]=1;
	
	//��x�� 
	for(int i=1;i<=N;i++)
	{
		//��ǰҪ�İ����� 
		for(int j=1;j<=20000;j++)
		{
			//����ǰҪ�İ��������ڵ��ڵ�x�����İ����� 
			if(j>=zhenglong[i])
				dp[j]=max(dp[j],dp[j-zhenglong[i]]);//��ȫ����������Ż�д�� 
		}
	}

	int count=0;
	for(int i=0;i<20000;i++)
	{
		if(!dp[i])
			count++;
	}
	cout<<count;

	return 0;
}
#endif
//������
//for(int i=1;i<N;i++)
//	for(int j=0;j<20000;j++) 
//	{
//		if(dp[j])
//			dp[j+zhenglong[i]]=1;
//	}


//7.3 K������ 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	
	vector<int>shulie(N+1);
	for(int i=1;i<=N;i++)
		cin>>shulie[i];	
	
	int count=0;	
	//�ӵ�1��������N���� 
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)//��i��������i��������N���� 
		{
			int sum=0;
			
			//��ֻȡһ���� 
			if(i==j)
			{
				if(shulie[i]%K==0)
				count++;
			}
			else//��ȡ2��j-i+1���� 
			{ 
				int temp=i;
				
				do
				sum+=shulie[temp];
				while(temp++!=j);
				
				if(sum%K==0)
					count++;
			}
		} 

	cout<<count;

	return 0;
}
//5 2
//1
//2
//3
//4
//5
#endif


//7.4 ���Դ��� 
//***˼·***
//Ҫ������������Ѳ��� 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000;

int main()
{
	//����һ���ֻ��������ֻ��������ֻ�
	//�ӵ�һ�㵽��N����Ե�dp���� 
	int dp[4][N+1];	

//***ע***
//��fill()�Զ�ά���鸳ֵ 
//����Ĳ���� 
//	fill(&dp[0][0],&dp[4][N+1],0);
//��ȷ��� 
//	fill(&dp[0][0],&(dp[0][0])+4*(N+1),0);

	//�����ֻ��Ĵ�����ֵΪ¥����(����ֻ��һ���ֻ������) 
	for(int i=1;i<=3;i++)
		for(int j=0;j<=N;j++)
			dp[i][j]=j;
		
	//��i���ֻ� 
	for(int i=2;i<=3;i++)
	{	
		//Ҫ���j�� 
		for(int j=1;j<=N;j++)
		{
			//�ڲ��k��¥ʱ 
			for(int k=1;k<=j;k++)
				dp[i][j]=
				//�����������ѡ���ŵľ���(ѡ���ٵĲ��Դ���) 
				min(dp[i][j],
				//ȡ�������   +1:��ʾ�Ѿ�����һ�β��� 
				1+max
				//�ֻ�ˤ��������1~k-1�� 
				(dp[i-1][k-1],
				//�ֻ�û��������k+1~j�㣬��j-(k+1)+1�� 
				dp[i][j-(k+1)+1]));
		} 
	}
	
	cout<<dp[3][N];

	return 0;
}
#endif


//7.5 ���� 
//***�����*** 
#if 0
#include <iostream> 

using namespace std;
int dp[2030][1020];

int main()
{
	int n=2020;
	
   dp[1][1]=1;
   
   //��ǰ����i������ 
   for(int i=2;i<=n;i++)
   {
      for(int j=1;j<=i;j++)
      {
         dp[i][j]+=dp[i-1][j-1];
         
         if(i-j<=j)
			   dp[i][j]+=dp[i-1][j];
			   
			dp[i][j]%=n;
      }
   }
   
   printf("%d\n",dp[2020][1010]);
   return 0;
}
#endif


//7.6�߷��� 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

long dp[10000][100];

int main()
{
	long n,m;
	cin>>n>>m;
	
	//��һ���߷�ֻ��һ�� 
	fill(&dp[1][1],&dp[1][1]+99,1);
	
	//�ӵڶ��п�ʼ 
	for(int i=2;i<=n;i++)
	{  
		//��i�е�һ���߷�ֻ��һ�� 
		dp[i][1]=1;
		//�ӵ�i�еڶ��п�ʼ 
		for(int j=2;j<=m;j++)
		{
			//��i��j��Ϊż�� 
			if(i%2==0&&j%2==0)
				dp[i][j]=0;
			//��������Ԫ�ص�ǰ��һ��Ԫ��Ϊ0 
			else if(dp[i][j-1]==0)
			{
				dp[i][j]=dp[i-1][j];
			}
			//��������Ԫ�ص�����һ��Ԫ��Ϊ0 
			else if(dp[i-1][j]==0)
			{
				dp[i][j]=dp[i][j-1];	
			}
			//��������Ԫ��ǰ��һ��Ԫ�غ�����һ��Ԫ�ؾ���Ϊ0
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];//�������⹫ʽ���� 
			}			 
		}
	}	
	
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//			printf("%6d",dp[i][j]);
//		cout<<endl;
//	}

	cout<<dp[n][m];
	
	return 0;
}
#endif


//7.7 ������� 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[110][200010];

int main()
{
	int N;
	cin>>N;
	
	vector<int> fama(N+1);
	
	for(int i=1;i<=N;i++)
		cin>>fama[i];		
		
	//��i������ 
	for(int i=1;i<=N;i++)
	{
		//��һ�е����ݿ�������ǰ�� 
		for(int j=1;j<=200010;j++)
		{
			dp[i][j]=dp[i-1][j];
		}
		
		//��¼1~i�������ܱ�ʾ��������� 
		int Max=0;
		for(int index=1;index<=i;index++)
			Max+=fama[index];
		
		//Ҫ�յ����� 
		for(int j=1;j<=Max;j++)
		{
			if(j==fama[i])
				dp[i][j]=1;
				
			if(fama[i]-j>=1&&dp[i-1][fama[i]-j])//����01��������Ĺ�ʽ 
				dp[i][j]=1;
			
			if(j-fama[i]>=1&&dp[i-1][j-fama[i]])
				dp[i][j]=1;
		} 
	}
	
//	for(int i=0;i<=N;i++)
//	{
//		for(int j=0;j<=15;j++)
//			printf("%6d",dp[i][j]);
//		cout<<endl;
//	}	
	 
	int count=0;
	for(int j=0;j<=200010;j++)
		if(dp[N][j])
			count++;
	
	cout<<count;			
	 
	return 0;
}
#endif


//7.8 �������� 
//***�����*** 
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin>>str;

	string::iterator p;
	int l_count=0,r_count=0;
	for(p=str.begin();p!=str.end();p++)
	{
		if(*p=='(')
			l_count++;
		if(*p==')')
			r_count++;
	}
	
	cout<<l_count<<" "<<r_count;	

	return 0;
} 
#endif
























