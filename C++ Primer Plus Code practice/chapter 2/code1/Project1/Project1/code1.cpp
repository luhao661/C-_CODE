#define _CRT_SECURE_NO_WARNINGS 1
//
#if 1
#endif


//�����嵥2.1 ����C++����
//��һ��ʹ��std::ǰ׺
#if 0
#include <iostream>
int main()
{
	std::cout << "����һ��C++����";
	std::cout << std::endl;
	std::cout << "�㲻���ڵģ�" << std::endl;

	return 0;
}
#endif
//������ʹ��using����ָ��
#if 0
#include <iostream>
int main()
{
	using namespace std;//���ƿռ����ָ��		����std���ƿռ��е��������ƶ�����
	cout << "����һ��C++����";
	cout << endl;
	cout << "�㲻���ڵģ�" << endl;

	return 0;
}
#endif
//����(�Ľ�)��ʹ��using����ָ��
#if 0
#include <iostream>//C++����ͷ�ļ����������ƿռ�std��������cout,endl
int main()
{
	using std::cout;//using����ֻʹ��������ƿ���		ʹ�����ƿռ�std�е�Ԥ�������cout��cout��ʾ���������Ϊ "c out"����׼���
	using std::endl;//ʹ�����ƿռ�std�еĿ��Ʒ�endl

	cout << "����һ��C++����";
	cout << endl;
	cout << "�㲻���ڵģ�" << endl;

	return 0;
}
#endif


//�����嵥2.2 ������ʹ�ñ�����ʹ��cout��ӡ������ֵ
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	carrots = 25;

	cout << "I have ";
	cout << carrots;
	cout << " carrots\n";

	carrots -= 1;
	cout << "����1���������һ���" << carrots << "�����ܲ�(carrots)" << endl;

	return 0;
}
#endif


//�����嵥2.3 ʹ��cin
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	cout << "���ж��ٸ����ܲ��� ";
	cin>> carrots;
	//д��1��
	//cout << "����1���������һ���" << carrots-1 << "�����ܲ�(carrots)" << endl;
	//д��2��(�����ڳ�������)
	cout << "����1���������һ���" 
			<< carrots - 1 
			<< "�����ܲ�(carrots)" 
			<< endl;

	return 0;
}
#endif


//�����嵥2.4 ����C���еĺ���
#if 0
#include <iostream>
#include <cmath>

int main (void)
{
	using namespace std;

	double area;
	cout << "������һ������0��С����";
	cin >> area;

	double side;
	side = sqrt(area);
	cout << "����������ƽ������";
	cout << side<< endl;

	return 0;
}
#endif


//�����嵥2.5 �����û��Զ���ĺ���(1)
#if 0
#include <iostream>
void function(int);
//��дΪ��
//using namespace std;//����д�Ļ��������������ܷ������ƿռ�std

int main(void)
{
	using namespace std;

	function(3);

	cout << "���������֣�";
	int n;										//***ע***���������ܺͺ�������ͬ�������������֪��Ӧ���ñ������Ǹõ��ú���
	cin >> n;									//������ͬһ��������ͬʱ��cout�����������ͱ����������������Ҳ���Ϳ
	function(n);
													//�ؼ���(��int return��)����������
	return 0;
}
void function(int n)
{
	using namespace std;

	cout << "��ʾ��";
	cout << n<<endl;
}
#endif


//�����嵥2.6 �����û��Զ���ĺ���(2)
#if 0
#include <iostream>
int function(int);

int main(void)
{
	using namespace std;

	cout << "���������֣�";
	int n;										
	cin >> n;									
	n=function(n);
	cout << "����2���󣬵õ�" << n << endl;

	return 0;
}
int function(int n)
{
	n *= 2;

	return n;//��return n*=2;
}
#endif

