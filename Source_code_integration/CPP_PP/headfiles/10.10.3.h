#define _CRT_SECURE_NO_WARNINGS 1

#ifndef class_Golf
#define class_Golf

class Golf
{
	enum {Len=40};
	struct golf
	{
		char fullname[Len];
		int handicap;						//������⣺
	}golf_structure;						//�˴������Ľṹ������û�д洢�ڶ�����
												    //��ȷ��⣺
													//û�жԽṹ�������г�ʼ��������������ֻ��������η����ڴ棬�����������ڴ�
													//***ע***
													// Ҫ������������һ����������������
													//һ�������������ʱ��Ϊ��������ռ���
													
	//***ע***Ҳ���Բ��ýṹ��ֱ���û�����������
	/*char fullname[Len];
	int handicap;*/

public:
	//�ǽ����汾
	Golf(const char* p_data,const int hc);
	//�����汾
	Golf();
	~Golf();
	void handicap(const int hc);
	void showgolf() const;
};

#endif  /*class_Golf*/