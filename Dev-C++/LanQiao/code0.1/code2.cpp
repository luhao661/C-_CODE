#include <iostream>

//1.
//��ʾ���������� 
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	char erjinzhi[32];
	char temp;
	for(int i=31;i>=0;i--)
	{
		temp = (0x01&shijinzhi)+'0';//***ע***�˴�����һ��Ҫ�� 
		cout<<temp;
		erjinzhi[i]=temp;
		shijinzhi>>=1;	//�˴�����������ѭ�����ƴ���	
	}
	
	for(int i=0;i<32;i++)
	{
		cout<<erjinzhi[i];
	}
	
	return 0;
}
#endif
//������
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	char erjinzhi[32]={'0'};
	int i=0;
	while(shijinzhi)
	{
		erjinzhi[i++]=shijinzhi%2+'0'; 
		shijinzhi/=2;		
	}
	
	for(int i=32;i>=0;i--)
	{
		cout<<erjinzhi[i];
	}
	
	return 0;
}
#endif 


//2.
//���ַ�ת�������� 
#if 0
#include <string>
using namespace std;

int function(string st);//***ע***char�������Զ�ת����string 
int main()					//string���Ͳ����Զ�ת����char 
{
	char data[10];
	
	cin>>data;
	int num=function(data);	
	cout<<num;

	return 0;
}
int function(string st)
{
	int num=0;
	
	for(int i=0;st[i]!='\0';i++) 
	{
		if(st[i]>='0'&&st[i]<='9')		
		num=num*10+st[i]-'0';//***��*** 
	}
		
	return num;	
}
#endif 


//3.
//ʮ����ת��Ϊ�������� 
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	int qitajinzhi;
	cin>>qitajinzhi;
	
	int result[8]={0};//�洢����ȡ������� 
	int i=0;
	
	do//���ó�������ѭ�� 
	{
		result[i++]=shijinzhi%qitajinzhi;
		shijinzhi/=qitajinzhi;
		
	}while(shijinzhi!=0);
	
	//������� 
	for(int i=7;i>=0;i--)
	 cout<<result[i];

	return 0;
}
#endif


//4.
//���ļ� 
#if 0
#include <fstream>
using namespace std;

int main()
{
	ifstream In;
	In.open("ceshi.txt");
	
	char data[20]={'\0'};
	In>>data;
	
	for(int i=0;i<20;i++)
	{
		cout<<data[i];
	}
	
	return 0;
}
#endif
//������ 
#if 0
#include <iostream>
using namespace std;

int main()
{
	FILE *In;
	In=fopen("ceshi.txt","r");
	
	if(In==NULL)
	cout<<"error";
	
	//ʹ��getc()	
	char ch = getc( In );
   while( ch != EOF ) {
      printf( "%c", ch );
      ch = getc( In );
    }
    
   rewind(In);//���ļ�ָ���Ƶ���stream(��)ָ���Ŀ�ʼ��,
	//ͬʱ���������صĴ����EOF��� 
   
	//ʹ��fscanf() 
	char data[20]={'\0'};
	fscanf(In,"%s",data);
		
	for(int i=0;i<20;i++)
	{
		cout<<data[i];
	}
	
	return 0;
}
#endif








