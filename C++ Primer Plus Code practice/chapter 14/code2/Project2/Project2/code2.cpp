#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//14.6 ��ϰ��
//4.
#if 0
//��Ŀ�����ɵ�������
//��������
class Stack  <Worker*>                      
{
private:
    enum { MAX = 10 };  // constant specific to class ��ʾ����
    Worker* items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Worker*& item); // add item to stack
    bool pop(Worker*& item);        // pop top into item
};
#endif


//5.
//������
#if 0
#include <string>
#include <valarray>
#include "14.6.5.h"

int main()
{
	std::valarray<std::string>s_shuzu;

    //�����������ɵ���ָ��ջ
	/*double a[20] = {};
	Stack<double *>s1;*/
    //������
    //cxqd14.17.h����ArrayTP��ģ��
    //Stack< ArrayTP<double,100> >  stack;

	//Worker* p_w = Worker w1;//�������������������Ķ���
	Worker* p_w;//��ʱδ����Worker�����P473
	Stack<Worker*>s2[20];

    //��
    //ArrayTP<Stack<Worker*>, 100>arr_stk;

	return 0;
}
#endif