#define _CRT_SECURE_NO_WARNINGS 1

#ifndef LIST_H
#define LIST_H

#define LENGTH 45

//�洢��Ŀ
struct film
{
	char title[LENGTH];
	int rating;
};
typedef struct film Item;//��film�ṹ��������ΪItem
//***ע***���Ѵ˽ṹ���������������У�����й��г�Ա�������Է��ʡ�
//����Ա����ֻ���ɶ�����ʣ�����Ҫʹ�ô˽ṹģ��Ļ������ȴ��������
//����������������ֱ��дList movies;

class List
{
	//ȷ����δ洢�������͵���
	//����Ľڵ�
	typedef struct node
	{
		Item item;							//��������	
		struct node* next;				//ָ����һ���ڵ��ָ��					//��������ʽ�ṹ�洢����

		//***ע***�Ͼ䲻��д��Node* next;ԭ����typedef��û�����������þ�ʹ����Node������ʱ������ܶ����				
		//���Դ˴���typedef������һ���ṹ���ͣ�����ʡ�Խṹ�ı��

	}Node;										//��note�ṹ��������ΪNode		
													/***ÿ�����ڽ����ڵ㣬ÿ���ڵ�����������ݺ�ָ����һ���ڵ��ָ��***/

	struct P_Node
	{
		Node* head;//ָ��ͷ����Node�ṹ�ĵ�ַ������ͷָ��һ��ʼΪNULL
		Node* end;//ָ���β����Node�ṹ�ĵ�ַ
	};//����һ���ṹ���֣���ǩΪP_Node
	 
	P_Node movies;//����һ���ṹ��������������ָ��
	P_Node* plist=&movies;//plistָ��˽ṹ����(C++11���ڳ�ʼ��)
	
public:
	/* ������ ��ʼ��һ������ */
	/* ǰ�������� plist ָ��һ������ */
	/* ���������� �����ʼ��Ϊ�� */
	//void InitializeList(P_Node* plist);
	//����plist����&movies����P_Node�ṹ���ֵĽṹ�ĵ�ַ
	List();

	/*������ ȷ�������Ƿ�������plist ָ��һ���ѳ�ʼ�������� */
	/* ���������� ��������������ú���������;���򷵻ؼ� */
	//bool ListIsFull(const P_Node* plist);
	bool ListIsFull()const;

	/*������ �������ĩβ�����*/
	/*ǰ�������� item��һ���������������plist ָ��һ���ѳ�ʼ�������� */
	/*���������� ������ԣ��ú���������ĩβ���һ����ҷ���true;���򷵻�false*/
	//bool AddItem(Item item, P_Node* plist);
	bool AddItem(Item item);

	/* ������ ȷ�������Ƿ�Ϊ�գ�plist ָ��һ���ѳ�ʼ�������� */
	/*���������� �������Ϊ�գ��ú�������true;���򷵻�false */
	//bool ListIsEmpty(const P_Node* plist);
	bool ListIsEmpty()const;

	/*������ �Ѻ��������������е�ÿһ�plistָ��һ���ѳ�ʼ�������� */
	/*pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ */
	/*���������� pfun ָ��ĺ��������������е�ÿһ��һ�� */
	//void Traverse(const P_Node* plist, void(*pfun)(Item item));
	void Visit(void(*pf)(Item&))const;

	/*������ ȷ�������е�������plist ָ��һ���ѳ�ʼ�������� */
	/* ���������� �ú������������е����� */
	//unsigned int ListItemCount(const P_Node* plist);
	unsigned int ListItemCount()const;

	/*������ �ͷ��ѷ�����ڴ棨����еĻ��� */
	/* plist ָ��һ���ѳ�ʼ�������� */
	/* ���������� �ͷ���Ϊ�������������ڴ棬��������Ϊ�� */
	//void EmptyTheList(P_Node* plist);
	void EmptyTheList();
};

#endif /*LIST_H*/