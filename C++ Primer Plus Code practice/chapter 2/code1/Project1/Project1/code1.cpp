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
#if 1
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