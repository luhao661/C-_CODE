//4.1 ���ƺ͵ݹ� 
#if 0
#include <iostream>

using namespace std;
int ditui(int n);
int digui(int n);
int main()
{
	int n;
	cin>>n;
	
	int result1=ditui(n);
	int result2=digui(n);
	
	cout<<result1<<endl<<result2<<endl;

	return 0;
}
int ditui(int n)
{
	int arr[100]={0};
	
	arr[1]=1;
	arr[2]=2;
	
	for(int i=3;i<=n;i++)
		arr[i]=arr[i-1]+arr[i-2];
		
	return arr[n]; 
}
int digui(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	
	return digui(n-1)+digui(n-2);
}
#endif


//4.2 ��ѹ���� 
#if 0
#include <iostream>
#include <valarray>
#include <cmath>
#include <stdio.h>

using namespace std;
int main()
{
	freopen("4.2.txt","r",stdin);
	
	double data_jinzita[30][30];
	
	for(int i=0;i<30;i++)
		for(int j=0;j<30;j++)
			data_jinzita[i][j]=0.0;
	
	int temp;
	for(int i=0;i<29;i++)
		for(int j=0;j<=i;j++)
		{
			cin>>temp;
			data_jinzita[i][j]=temp;
		}
		
	for(int i=0;i<30;i++)
	{	
		for(int j=0;j<30;j++)		
			cout<<data_jinzita[i][j]<<" ";
		cout<<endl;
	}

//***����***
//ֱ����double�������ʹ洢����2֮���ֵ�����������
//��һ������ֵ���ײ��൱��Ҫ����2��29�η���double�ﲻ���˾��� 

	for(int i=0;i<29;i++)
	{	
		for(int j=0;j<=i;j++)		
			data_jinzita[i][j]*=pow(2,29);//����	
	}

	data_jinzita[1][0]+=data_jinzita[0][0]/2.0;				
	data_jinzita[1][1]+=data_jinzita[0][0]/2.0;	

//	�ӵ����㿪ʼ���ֿ�����������������ֺͽ������ڵ����� 
	for(int i=2;i<30;i++)
	{
		//������������������ 
		data_jinzita[i][0]+=data_jinzita[i-1][0]/2.0;
		data_jinzita[i][i]+=data_jinzita[i-1][i-1]/2.0;
		for(int j=1;j<=i-1;j++)
		{
//***����λ�ô���*** 
//			data_jinzita[i][0]+=data_jinzita[i-1][0]/2.0;
//			data_jinzita[i][i]+=data_jinzita[i-1][i-1]/2.0; 				
			
			//����������ڵ�����			
			data_jinzita[i][j]+=data_jinzita[i-1][j-1]/2.0+data_jinzita[i-1][j]/2.0;
		
		}
	}
		
	for(int i=0;i<30;i++)
	{	
		for(int j=0;j<30;j++)		
			cout<<data_jinzita[i][j]<<" ";
		cout<<endl;
	}
	
	valarray<double> a(30);
	for(int i=0;i<30;i++)
		a[i]=data_jinzita[29][i];
		
	cout<<endl<<a.min()<<endl<<a.max()<<endl;	

	printf("%.2f",a.max());
	return 0;
}
#endif


//4.3 ȡ��λ 
#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

int len(int x)
{
	if(x<10)
		return 1;
		
	return len(x/10)+1;
}
//ȡx�ĵ�kλ���� 
int f(int x,int k)
{
	if(len(x)-k==0)
		return x%10;
	
	return f(x/10,k);
}

int main()
{
	int x=23574;
	printf("%d\n",f(x,3));

	return 0;
} 
#endif


//4.4 ���е�ֵ 
#if 0
#include <iostream>

using namespace std;
int main()
{
	const long num=20190324;

//***ע*** 
//�ᵼ�³��������쳣��ֹ�ľ��棺 
//����ʹ�� ��ջ��constant_1 �ֽڣ����� /analyze��stacksize constant_2��
//���ǽ����������Ƶ���	
//	long long shuzu[num]={0};
	
	long long *shuzu=new long long[num]; 
	
	shuzu[0]=shuzu[1]=shuzu[2]=1;
	
	//�ӵ����ʼ 
	for(long i=3;i<num;i++)
	{
		shuzu[i]=shuzu[i-1]+shuzu[i-2]+shuzu[i-3];
		shuzu[i]%=100000000;//����8λ���Կ�����long long�ı�ʾ��Χ�� 
	}
	cout<<shuzu[num-1]; 
	
	delete [] shuzu; 

	return 0;
}
#endif


//4.5 �������� 
#if 0
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
���⣺�������� 
���´�����Դ�����a[]���ҳ���kС��Ԫ�ء�
��ʹ�������ƿ��������еķ����㷨������ʱ�临�Ӷ���O(N)�ġ�
����ϸ�Ķ�����Դ�룬��д���߲���ȱʧ�����ݡ� 
*/
int quick_select(int a[], int l, int r, int k) 
{  
	//����һ�����������ֵ����Ϊ������ 
	int p = rand() % (r - l + 1) + l;  
	
	//x�������ѡ�������� 
	int x = a[p];
	
	{
		int t = a[p];//t�������ѡ�������� 
		a[p] = a[r];//��������������ָ��ָ���Ԫ�� 
		a[r] = t;
	}  
	
	int i = l, j = r;
	while(i < j) 
	{
		//����������飬���ҵ�һ�����ڻ�������������ݵ�
		//��������ֵ 
		while(i < j && a[i] < x) i++;  
		
		//��������ֵ������ĩ�����ݵ�����ֵ 
		if(i < j) 
		{  
		   //�������ݸ��Ƶ���ĩλ                    
			a[j] = a[i]; 
			j--;                          
		}
		
		//����������飬���ҵ�һ��С�ڻ�������������ݵ�
		//��������ֵ 
		while(i < j && a[j] > x) j--; 
		
		if(i < j)
		{
			//�������ݸ��Ƶ���һ�����ڻ�������������ݵ�
			//����λ�� 
			a[i] = a[j];           
			i++;
		}
	}
	
	//ѭ������ʱi��ߵ������������ᴦ����С��
	//i�ұߵ������������ᴦ������ 
	
	//��ԭ�����ᴦ�����ָ��Ƶ�i��λ�� 
	a[i] = x;
	p = i;
	
	if(i - l + 1 == k)//��i-l==k-1 ����ֵ�Ƿ����Ҫ��� 
		return a[i];	//��kС�������ڵ�λ��(��k-1)
							//���ж�����������
							//��˵�������ᴦ�����־��ǵ�kС������ 
	
	//��С��k����˵��k��Ӧ�������������ұߣ�
	//��һ��ֻ���������ұ�ȥ��				
	//***ע***
	//k-i+l-1��k-(i-l+1),��ȥ����i��벿�ֺ�i�Ұ벿�ִ�0��ʼ������ֵ		
	if(i - l + 1 < k)
		return quick_select(a,i+1,r,k-i+l-1); //��� 
	else
		return quick_select(a, l, i - 1, k);
}
int main()
{
	int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};   
	printf("%d\n", quick_select(a, 0, 14, 2));            
	return 0;
}
#endif





























