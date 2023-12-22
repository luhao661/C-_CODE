#include <iostream>

#if 0
int main()
{	
	std::cout<<"Hello World !\n";
	
	return 0;
}
#endif


#if 0

#include <string>
#include <iterator>//back_insert_iterator��insert_iterator
#include <vector>
#include <algorithm>//copy()
#include "cxqd.h"

int main()
{
    using namespace std;

    string s1[4] = { "fine", "fish", "fashion", "fate" };
    string s2[2] = { "busy", "bats" };
    string s3[2] = { "silly", "singers" };

    //����һ��vector���飬�京4��Ԫ�أ�ÿ��Ԫ�����;�Ϊstring
    vector<string> words(4);

    //***ע***s1 + 4�ǳ�β����������ʶ��β��λ��
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous back_insert_iterator object
    //����������back_insert_iterator������
    copy(s2, s2 + 2,
        back_insert_iterator<vector<string> >(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous insert_iterator object
    //����������insert_iterator������
    copy(s3, s3 + 2, 
        insert_iterator<vector<string> >(words, words.begin()));
    copy(words.begin(), words.end(), 
        std::ostream_iterator<string, char>(cout, " "));//ʹ�õ��������
    cout << endl;           //***ע***
                                      //���͸���������������ͣ�string
    // cin.get();               //�����ʹ�õ��ַ����ͣ�char
    return 0;
}

#endif


#if 1
#include <iterator>
#include <list>//��Ա����insert()��
#include <algorithm>//STL����(�ǳ�Ա����)��for_each()

void outint(int n) 
{
    std::cout << n << " "; 
}

int main()
{
    using namespace std;

    //����һ����5��int���͵�ֵ2��ɵ�����
    list<int> one(5, 2); // list of 5 2s

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //����һ��������
    list<int> two;

    //������stuff��������ݲ��뵽two����Ԫ��ǰ
    int stuff[5] = { 1,2,4,8, 6 };
    //��һ��(ʹ��insert()��Ա����)
    two.insert(two.begin(), stuff, stuff + 5);
    //������(ʹ��insert_iterator���������)
    /*copy(stuff,stuff+5,
        insert_iterator<list<int>>(two,two.end()));*/
    
    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);
    
    //���ø��ƹ��캯���������͸���
    list<int> three(two);

    int more[6] = { 6, 4, 2, 4, 6, 5 };
    three.insert(three.end(), more, more + 6);
    
    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);
    
    //��˫��������ɾ��ֵΪ2������ʵ��
    three.remove(2);
    cout << endl << "List three (ɾ����ֵΪ2��ʵ��): ";
    for_each(three.begin(), three.end(), outint);

    //������one�����ݲ��뵽threeͷ����ǰ��
    //***ע***one�����
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //����������ͬԪ��ѹ��Ϊ����Ԫ��
    three.unique();
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    //����(Ĭ�ϵ���)
    three.sort();
    //***ע***
    //����ʹ��STL����sort()��
    //��Ϊ�ǳ�Ա����sort()��Ҫ������ʵ�������
    //��list��֧���������
    //sort(three.begin(),three.end());

    //�ϲ�ͬ����
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    //����(Ĭ�ϵ���)
    two.sort();
    //����������ϲ�
    //***ע***ǰ�᣺������������Ѿ�����
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);

    cout << endl;
    // cin.get();

    return 0;
}

#endif

