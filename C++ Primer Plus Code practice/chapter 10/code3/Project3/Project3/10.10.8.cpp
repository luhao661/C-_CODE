#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.8.h" 
#include <stdio.h>//������NULLΪ0

List::List()
{
	plist->head = NULL;//��ͷָ��head=NULL
	plist->end = NULL;
}

bool List::ListIsFull()const
{
	bool full;
	Node* p;
	p =new Node;//�����ܷ�Ϊ�������ռ�
	if (p == NULL)
		full = true;
	else
		full = false;
	delete p;

	return full;
}

bool List::AddItem(Item item)
{
	Node* begin, * current;

	begin = plist->head;

	current = new Node;//����Ϊ�½ڵ����ռ�
										//currentָ���½ڵ㣬���½ڵ�ĵ�ַ
	if (current == NULL)//���û�δ����ListIsFull()��������ô�����Ҳ�ܼ���ܷ�Ϊ�������ռ�
		return false;

	current->item = item;//������ɹ������������½ڵ���(�����ṹ)
//***ע***�˴���ͬ������Ϊ1.����������������ͬ 2.�Ⱥ�������Ա����ǽṹ�е�item��Ա���Ⱥ��Ҳ����Ա������β�item������������塣

	current->next = NULL;//�����ýڵ�����������һ���ڵ�

	if (begin == NULL)//�����������ͷָ��
		plist->head = current;//���ͷָ������Ϊָ���һ���ڵ�
	else
	{
		plist->end->next = current;
	}

	plist->end = current;//����endָ��ָ��Ľڵ�

	return true;
}

bool List::ListIsEmpty()const
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

void List::Visit(void(*pf)(Item&))const
{
	Node* begin = plist->head;

	while (begin != NULL)
	{
		(*pf)(begin->item);
		begin = begin->next;
	}
}

unsigned int List::ListItemCount()const
{
	unsigned int count = 0;
	Node* begin = plist->head;

	while (begin != NULL)
	{
		count++;
		begin = begin->next;
	}
	return count;
}

void List::EmptyTheList()
{
	Node* temp = (Node *)0x01;

	while (plist->head != NULL)
	{
		temp = (plist->head)->next;//������һ�ڵ�ĵ�ַ
		delete(plist->head);
		plist->head = temp;//ǰ������һ�ڵ�
	}
}

#endif