//2.1 ģ�ⷨ 
//���ջ����������ֵ�ķ��� 
#if 0
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int>v1;
	
	int a,b;
	int c;
	while(cin>>a>>b)
	{
		c=a+b;
		v1.push_back(c);
	}
	
	int day=0;
	int day1=0;
	int max=v1[0];
	vector<int>::iterator p;
	for(p=v1.begin();p!=v1.end();p++)
	{
		day++;
		if(*p>max)
		{
			max=*p;
			day1=day;
		}
	}
	
	if(max<=8) 
	cout<<"����";
	else
	cout<<"��"<<day1<<"�������"; 

	return 0;
}
#endif


//2.2 �������� 
#if 0
#include <iostream>
#include <stdio.h> 
using namespace std;

int main()
{
	int diyibufen,dierbufen,disanbufen;
	
	char temp;
	cin>>diyibufen;
	cin>>temp;
	cin>>dierbufen;
	cin>>temp;
	cin>>disanbufen;
	
//	cout<<diyibufen<<" "<<dierbufen<<" "<<disanbufen<<endl;

	printf("%d-%02d-%02d\n",2000+diyibufen,dierbufen,disanbufen);
	printf("%d-%02d-%02d\n",2000+disanbufen,diyibufen,dierbufen);
	printf("%d-%02d-%02d\n",2000+disanbufen,dierbufen,diyibufen);

//***����***
//û�г�����ú���Ŀ����
//������������1960��1��1����2059��12��31�� 
//Ҫ�󣺶�����ڰ����絽��˳������
 
	return 0;
}
#endif
//����
#if 0
#include <iostream>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct da
{
   int x, y, z, flag = 0;
}date[5];

int main()
{
    int y, m, d;
    char c;

    cin >> y >> c >> m >> c >> d;
    int num = 0;

    //��������ѭ�����������������ı��浽�ṹ�������У�
    //***ע***˳��������ĿҪ��Ĵ����ڴ�С�����˳��

    for (int nian = 1960; nian <= 2059; nian++)
    {

        if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
            mon[2] = 29;
        else mon[2] = 28;

        for (int yue = 1; yue <= 12; yue++)
        {
            for (int ri = 1; ri <= mon[yue]; ri++)
            {
                //������ѭ������ʱ�õ�������ƥ��������յ�����ʱ

                //�������������
                if (nian % 100 == y && m == yue && d == ri)
                {
                    date[++num].x = nian;
                    date[num].y = m;
                    date[num].z = d;
                }

                //���������(y)��(m)��(d)
                if (nian % 100 == d && y == yue && m == ri)
                {
                    date[++num].x = nian;
                    date[num].y = y;
                    date[num].z = m;
                }

                //���������(y)��(m)��(d)
                if (nian % 100 == d && m == yue && y == ri)
                {
                    date[++num].x = nian;
                    date[num].y = m;
                    date[num].z = y;
                }
                
            }
        }

    }

    //ȥ�أ����ظ������ڱ��һ��
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            if (date[i].x == date[j].x && 
                date[i].y == date[j].y && 
                date[i].z == date[j].z)

                date[j].flag = 1;
        }
    }

    //�������
    for (int i = 1; i <= num; i++)
        if (!date[i].flag)
            printf("%d-%02d-%02d\n", date[i].x, date[i].y, date[i].z);
    return 0;
}
#endif 
//ʹ��set�������� 
#if 0
#include <iostream>
#include <set>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

typedef struct a  //***ע***a���ܲ�д����Ϊ�ᵼ�±���
{
    int x, y, z;
}RiQiTypeDef;

//������Ԫ��operator��:��type*����������������Ԥ����������ɽ������͵�ת��
//ԭ��ʹ���Զ���ļ�ʱ��Ҫ����<�����
//***const����д***
bool operator<(const RiQiTypeDef&, const RiQiTypeDef&);

int main()
{
    int y, m, d;
    char c;

    cin >> y >> c >> m >> c >> d;
    int num = 0;

    //��������ѭ�����������������ı��浽�ṹ�������У�
    //***ע***˳��������ĿҪ��Ĵ����ڴ�С�����˳��

    RiQiTypeDef RiQiStruct;
    set<RiQiTypeDef>RiQiSet;

    for (int nian = 1960; nian <= 2059; nian++)
    {

        if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
            mon[2] = 29;
        else mon[2] = 28;

        for (int yue = 1; yue <= 12; yue++)
        {
            for (int ri = 1; ri <= mon[yue]; ri++)
            {
                //������ѭ������ʱ�õ�������ƥ��������յ�����ʱ

                //�������������
                if (nian % 100 == y && m == yue && d == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = m;
                    RiQiStruct.z = d;
                    RiQiSet.insert(RiQiStruct);
                }

                //���������(y)��(m)��(d)
                if (nian % 100 == d && y == yue && m == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = y;
                    RiQiStruct.z = m;
                    RiQiSet.insert(RiQiStruct);
                }

                //���������(y)��(m)��(d)
                if (nian % 100 == d && m == yue && y == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = m;
                    RiQiStruct.z = y;
                    RiQiSet.insert(RiQiStruct);
                }

            }
        }

    }

    //ȥ�أ����ظ������ڱ��һ��
//    for (int i = 1; i <= num; i++)
//    {
//        for (int j = i + 1; j <= num; j++)
//        {
//            if (date[i].x == date[j].x && 
//                date[i].y == date[j].y && 
//                date[i].z == date[j].z)
//
//                date[j].flag = 1;
//        }
//    }

    //�������
    for (auto p = RiQiSet.begin(); p != RiQiSet.end(); p++)
    {
        printf("%d-%02d-%02d\n", p->x,p->y,p->z);
    }
    return 0;
}

bool operator<(const RiQiTypeDef& RiQiStruct1, const RiQiTypeDef& RiQiStruct2)
{
    bool status=0;
    
    if (RiQiStruct1.x < RiQiStruct2.x)
        status = 1;
    else if (RiQiStruct1.x == RiQiStruct2.x &&
        RiQiStruct1.y < RiQiStruct2.y)
        status = 1;
    else if (RiQiStruct1.x == RiQiStruct2.x &&
        RiQiStruct1.y == RiQiStruct2.y &&
        RiQiStruct1.z < RiQiStruct2.z)
        status = 1;
    
    return status;
}
#endif 


//2.3 REPEAT���� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	int num=0;
//	cin>>num;
	
	for(int i=0;i<2;i++)
	{
		num+=4;
		for(int j=0;j<5;j++)
		{	
			for(int k=0;k<6;k++)
				num+=5;
			num+=7;
		}
		num+=8;
	}
	num+=9;
	
	cout<<num;
//***����***
//prog.txt�ļ����г����ĳ���ƪ�����޷�ͨ�������ĳ�����⡣ 
 
	return 0;
}
#endif
//������ 
//ʹ��ջ���� 
#if 0
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	int space;
	int zongxunhuanshu=1;
	int result=0;
	
	freopen("2.3.txt","r",stdin);
	
	stack<int> xunhuancishu_stack;
	stack<int> kongbaizifushu_stack;
	
	xunhuancishu_stack.push(1);//����Ϊ0������ѭ����Ϊ1 
	kongbaizifushu_stack.push(-1);//ѡһ��������ֵ0��ҪС�������˴�ѡ-1 
	
	string st;
	getline(cin,st);//��ȡ��������
	
	while(getline(cin,st))
	{
		//����ո����� 
		space=0;
		while(st[space]==' ')
			space++;
		
		//���ݴ洢�հ��ַ�����ջ�ж��Ƿ�Ҫ����ѭ��
		//***ע***Ҫ��while��� 
		while(space<=kongbaizifushu_stack.top()) 
		{
			zongxunhuanshu/=xunhuancishu_stack.top();
			xunhuancishu_stack.pop();
			kongbaizifushu_stack.pop();
		}
		
		//�ж��Ƿ���REPEAT��� 
		if(st[st.size()-1]==':')
		{
			int xunhuanshu=st[st.size()-2]-'0';
			zongxunhuanshu*=xunhuanshu; 
			
			xunhuancishu_stack.push(xunhuanshu);
			kongbaizifushu_stack.push(space);
		}
		else//������REPEAT��� 
		{	//Ҫ���ϵ��� 
			int jiashu=st[st.size()-1]-'0';
			result+=jiashu*zongxunhuanshu; 
		} 		
		
	} 
	
	cout<<result;

	return 0;
}
#endif


//2.4 �������� 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num=0;
	
	cin>>num;
	
	if(num%2!=0)
	return 0;
	
	while(num>=1)
	{
		cout<<num<<" ";
		num/=2;
	}
//�����������������<<��ÿ�γ��Զ��൱������һλ�����λ���Ƿ���������0��1 
	return 0;
}
#endif


//2.5 ���� 
#if 0
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	char data[500][2];
	
	for(int i=0;i<100;i++)
	{
		data[i][0]='\0';
		data[i][1]='\0';
	}
	
	int i=0;
	int j=0;
	for(int index=0;index<str.size();index++)
	{
		if(isdigit(str[index]))
		continue;
		
		data[i][0]=str[index];
		
		if(isdigit(str[index+1]))
			data[i][1]=str[index+1];
		else
			data[i][1]='1';
		
		i++;
	}
	
//��ʾ���������		
//	for(int i=0;i<100;i++)
//	{
//		cout<<data[i][0]<<" ";
//		cout<<data[i][1]<<endl;
//	}

	i=0;
	while(1)
	{				//***ע***char��ת��Ϊint�� 
		for(int cishu=data[i][1]-'0';cishu>0;cishu--)
		cout<<data[i][0];
		
		i++;
		
		if(data[i][0]=='\0') 
		break;
	}

	return 0;
} 
#endif


//2.6 ����ƴ�� 
#if 0
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int CheckNumber(int num);

int main()
{
	int n;
	cin>>n;
	int* shuzu1=new int[n];//��������� 
	int* shuzu2=new int[(n-1+1)*(n-1)];//ƴ�Ӻú������ 
	
	int k;
	cin>>k;
	
	int index=0;
	int n1=n;
	do
	{		
		cin>>shuzu1[index++];
		n1--;
	}while(n1);
	
	
	int temp=0;
	int m=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			temp=shuzu1[i]* pow(10,CheckNumber(shuzu1[j]))+shuzu1[j];
			shuzu2[m++]=temp;
			temp=shuzu1[j]* pow(10,CheckNumber(shuzu1[i]))+shuzu1[i];
			shuzu2[m++]=temp; 
		}
	}

//��ʾ���������		
//	for(int i=0;i<(n-1+1)*(n-1);i++)
//	cout<<shuzu2[i]<<" ";
	
	//���� 
	//***ע*** 
	//ʹ��set��������ȥ���ظ���ֵ 
	set<int>shuzi_set;
	for(int i=0;i<(n-1+1)*(n-1);i++)
		shuzi_set.insert(shuzu2[i]);
	
	int geshu=0;
	for(auto p=shuzi_set.begin();p!=shuzi_set.end();p++)
		(*p%k==0)?geshu++:geshu;
		
	cout<<geshu;
		
	return 0;
} 

int CheckNumber(int num)
{
	int weishu = 0;
	for ( int num1 = num; num1; )
	{
	   //��numΪһλʱ ѭ������һ�� ��numΪ��λʱ ���� ,��λʱ ����
	   num1 = num1 / 10;
	   weishu++;								//ѭ������һ��,λ����һ
	}
//	cout<< weishu;
	return weishu;
}
//��������
//4 2
//1 2 3 4 
//5 2
//1 12 123 1234 12345
#endif


//2.7 ��Ƭ 
#if 0
#include <iostream>
#include <vector>
#include <stdio.h>//sprintf() 
using namespace std;

void meiweideshuzi(vector<int>& ,int num);
int main()
{
	vector<int> data[10];
	
	for(int i=0;i<10;i++)
	{
		data[i].push_back(i);
		data[i].push_back(2021);
	}
	
//��ʾ�������� 
//	for(int i=0;i<10;i++)
//	{
//		cout<<data[i][0]<<" "<<data[i][1];
//		cout<<endl;
//	}

	vector<int> shuzi;
	
	//Ҫƴ������ 
	int pindezhengshu=1;
	int result;
	
	while(1)
	{
		meiweideshuzi(shuzi,pindezhengshu);
		
		for(auto p=shuzi.begin();p!=shuzi.end();p++)
			for(int i=0;i<10;i++)
				if(*p==data[i][0])
				{
					if(data[i][1])
						data[i][1]--;
					else
						{
							result=pindezhengshu-1;
							goto step1;
						}
				}
		
		pindezhengshu++;
	}	 
	
step1:cout<<result;

	return 0;
}

//����ÿλ�ϵ����� 
void meiweideshuzi(vector<int>& data,int num)
{
//	int num1=num;
//	int weishu=0;
//	do
//	{
//		num1/=10;
//		weishu++;
//	}while(num1);

//***ע***���������ַ���	
//��һ��ѭ����ȡ�� 
// data.clear();
//	while(num)
//	{					//***ע***Ҫ���뵽ͷ�� 
//		data.insert(data.begin(),num%10);
//		num/=10;	
//	}
//	for(auto p=data.begin();p!=data.end();p++)
//		cout<<*p<<" ";
//������ʹ��sprintf()ֱ�ӽ�����ת��Ϊ�ַ�����
//Ȼ�����ѡ�����ַ�����ʽ�����Ҳ����ѡ����int�������ÿλ������ 
	char str[100]={'\0'};
	sprintf(str,"%d",num);
	
	int index=0;
	int weishu=0;
	while(str[index++])
	{
		weishu++;
	}
	
	//������ 
	//***ע***��ÿ�ε��ô˺���ʱ��vector���鶼Ҫ�Ȼָ���ʼ״̬ 
	data.clear();
	for(index=0;index<weishu;index++)
		data.push_back(str[index]-'0');
		
//	for(auto p=data.begin();p!=data.end();p++)
//		cout<<*p<<" ";
}
#endif


//2.8 ������� 
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin>>N;
	
	long long yanghui[100][100];
	
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			yanghui[i][j]=0;
			
	yanghui[0][0]=1;
	yanghui[1][0]=yanghui[1][1]=1;
	for(int i=2;i<100;i++)//�ӵ����㿪ʼ 
	{
		yanghui[i][0]=yanghui[i][i]=1;
		for(int j=1;j<=i-1;j++)
			yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j]; 
	}
		
//	for(int i=0;i<100;i++)
//	{
//		for(int j=0;j<100;j++)
//			if(yanghui[i][j]!=0)
//				cout<<yanghui[i][j]<<" ";
//		cout<<endl;
//	}

	int jishu=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{	
			if(yanghui[i][j]==0)
				continue;
				
			++jishu;
			if(yanghui[i][j]==N)
				goto step;
		}	
	}

step:cout<<jishu;

	return 0;
}
#endif
























