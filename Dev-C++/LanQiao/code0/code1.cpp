#if 1
#include <iostream>

int main ()
{
	using std::cin;
	using std::cout;
	
	int a,b;
	
	cin>>a>>b;
	
	cout<<a+b;
	
	return 0;
}
#endif


//�����ֽ������� 
//��һ��(�ύʱ����ѡ��C++11) 
#if 0
#include <iostream> 
#include <valarray>
//#include <algorithm>.
using namespace std;

bool mycompare(int a,int b);

int main ()
{
	int len;
	cin>>len;
	
	int temp[len];
	valarray<int>shuzu(len);//valarry����û�����뷽�������Բ�����ͨ�������俽�����ݵķ��� 
	
	for (int index=0;index<len;index++)
	{
		cin>>*(temp+index);
	}
	
	for (int index=0;index<len;index++)
	{
		shuzu[index]=temp[index];
	}
	
	//shuzu.sort();  valarray��û��sort����
	//std::sort(shuzu.begin(),shuzu.end()); valarray��û��begin()��end()���� 
	
	//sort(begin(shuzu),end(shuzu));//Ĭ�ϴ�С���� 
	//�� 
	sort(begin(shuzu),end(shuzu),mycompare);
	
	for (int index=0;index<len;index++)
	{
		cout<<shuzu[index];
	}

	return 0;
} 

bool mycompare(int a,int b)
{
	return a<b;
}
#endif
//������ 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

//***ע***��Ҫ�Ƚ�������е�Ԫ�أ���Ҫ�����º��� 
//bool operator<(int a,int b);

int main()
{
//д��һ��
	int len;
	cin>>len;
	
	vector<int> v1(len);
	
	for(int index=0;index<len;index++)
	{
		cin>>v1[index];
	}

//д������
//	int len;
//	cin>>len;
//	vector<int>v1;
//	
//	int a;
//	for(int index=0;index<len;index++)
//	{
//		cin>>a;
//		v1.push_back(a); 
//	}

//д������
//	int len;
//	cin>>len;
//	
//	vector<int> v1;
//	back_insert_iterator<vector<int>> it(v1);
//	
//	int num;
//	for(int index=0;index<len;index++)	
//	{
//	cin>>num;
//	*(it)=num;
//	}
	sort(v1.begin(),v1.end());
	
	for(int index=0;index<len;index++)
	{
		cout<<v1[index];
	}
	
	return 0;
}
//bool operator<(int a,int b)
//{
//	return a<b;
//}

#endif 


