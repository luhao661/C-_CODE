#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <array>
#include <string>
#include <cstring>//strcmp()
//
#if 1
#endif


//5.9�����ϰ
//1.
#if 0
int main(void)
{
	using namespace std;
	cout << "����������������";
	
	int start, end;
	cin >> start;
	cin >> end;

	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;

	cout << start << "~" << end << "֮�����������ĺ�Ϊ" << sum;

	return 0;
}
#endif


//2.
#if 0
const int ArSize = 100;      // example of external declaration

int main()
{
	std::array<long double, ArSize>factorials;

	factorials[1] = factorials[0] = 1.0L;//0!=1��1!=1

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;
	// std::cin.get();
	return 0;
}
#endif


//3.
#if 0
int main(void)
{
	using namespace std;

	cout << "���������֣�";
	int num,sum=0;
	
	while (1)
	{
		cin >> num;
		sum += num;
		
		if (num != 0)
		{
			cout << "����������ۼƺ�Ϊ" << sum << endl;
			cout << "���������֣�";
		}
		else
			break;
	}
	//������
	/*do
	{
		cin >> num;
		sum += sum;
	} while (num!=0);
	cout << "����������ۼƺ�Ϊ" << sum << endl;*/
	return 0;
}
#endif


//4.
#if 0
//#define JUST_CHECKING
int main(void)
{
	using namespace std;

	double benjin_dap = 100.0, benjin_cle = 100.0;
	const double lilv_dap = 0.1;
	const double lilv_cle = 0.05;

	double lixi_dap, lixi_cle;

	double money_dap = benjin_dap ;
	double money_cle= benjin_cle;
	int years=0;

	do
	{
		years++;

		lixi_dap = lilv_dap * benjin_dap;
		money_dap += lixi_dap;

#ifdef JUST_CHECKING//��������
		cout << "��" << years << "�꣺" << "Daphne " << money_dap<<"\t";
#endif

		lixi_cle = lilv_cle * money_cle;
		money_cle += lixi_cle;
#ifdef JUST_CHECKING
		cout << "��" << years << "�꣺" << "Cleo " << money_cle<<endl;
#endif

	} while (money_cle<= money_dap);

	cout << "��" << years << "�꣺" << "Daphne " << money_dap << "\t";
	cout << "Cleo " << money_cle << endl;

	return 0;
}
#endif


//5.
#if 0
int main(void)
{
	using namespace std;

	int xiaoshouliang[12];
	//���󣺡�const char *�� ���͵�ֵ�������ڳ�ʼ�� ��char *�� ���͵�ʵ��
	//char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
	//***ע***��ȷд����
	const char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
	//д������
	//const string yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };

	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << "������" << yuefen[i] << "����������";
		cin >> xiaoshouliang[i];
		sum += xiaoshouliang[i];
	}

	cout << "��һ��������Ϊ" << sum<<"��"<<endl;
	
	return 0;
}
#endif


//6.
#if 0
int main(void)
{
	using namespace std;

	int xiaoshouliang[3][12];
	//���󣺡�const char *�� ���͵�ֵ�������ڳ�ʼ�� ��char *�� ���͵�ʵ��
	//char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
	//***ע***��ȷд����
	const char* nianfen[3] = { "1999��","2000��","2001��" };
	const char* yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };
	//д������
	//const string yuefen[12] = { "һ��","����","����","����","����","����","����","����","����","ʮ��","ʮһ��","ʮ����" };

	int sum[3 + 1] = {};
	int i, j;
	
	for ( i = 0; i < 3; i++)
	{
		cout << nianfen[i] << "��" << endl;

		for ( j = 0; j < 12; j++)
		{
			cout << "������" << yuefen[j] << "����������";
			cin >> xiaoshouliang[i][j];
			sum[i] += xiaoshouliang[i][j];
		}
	}

	cout.put('\n');
	for (int i = 0;i < 3; i++)
	{
		cout << nianfen[i] << "������Ϊ" << sum[i] << "��" << endl;
		sum[3] += sum[i];
	}
	cout << "��������Ϊ" << sum[3] << "��" << endl;

	return 0;
}
#endif


//7.
#if 0
struct car
{
	std::string manufacturer;
	int year;
};

int main(void)
{
	using namespace std;

	cout << "How many cars do you wish to catalog ?";
	int num;
	cin >> num;
	cin.get();//���ĵ����з�

	struct car* p_car = new car[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i +1<< "��" << endl;
		cout << "Please enter the make :";
		getline(cin, (p_car+i)->manufacturer);
		cout << "Please enter the year made :";
		cin >> (p_car + i)->year;
		cin.get();
	}

	if (num != 0)
	{
		cout << "Here is your collection :"<<endl;
			for (int i = 0; i < num; i++)
			{
				cout<< (p_car + i)->year<<" ";
				cout << (p_car + i)->manufacturer<<endl;
			}
	}
	else
		cout << "No data entered !";

	delete[]p_car;

	return 0;
}
#endif


//8.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter words (to stop, type the word done) :"<<endl;
	char shuju[20];
	int count = 0;

	/*do
	{
		cin >> shuju;
		++count;
	} while (strcmp(shuju, "done"));
	count -= 1;*/

	/*shuju[0] =0;
	for (; strcmp(shuju, "done"); ++count)
	{
		cin >> shuju;
	}
	count -= 1;*/

	while (1)
	{
		cin >> shuju;
		if (strcmp(shuju, "done"))
			++count;
		else
			break;
	}

	cout << "You entered a total of "<<count<<" words";

	return 0;
}
#endif


//9.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter words (to stop, type the word done) :" << endl;
	string shuju;
	int count = 0;	

	while (1)
	{
		cin >> shuju;
		if (shuju!= "done")
			++count;
		else
			break;
	}

	cout << "You entered a total of " << count << " words";

	return 0;
}
#endif


//10.
#if 0
int main(void)
{
	using namespace std;

	cout<<"Enter number of rows : ";
	int num;
	cin >> num;//***ע***�����뻺�����л���'\n'

	int i, j,k;
	for (i = 1; i <= num; i++)//�к�
	{
		for (j = 1; j <= num - i; j++)
			cout << ". ";
		for (k = 1; k <= i; k++)
			cout << "* ";
		cout << endl;
	}
	return 0;
}
#endif