//��C++��׼�⡷


//��C-Style array ʹ�û��ڷ�Χ��forѭ��
#if 0
#include <iostream>

using namespace std;

int main()
{
    int array[] = { 1,2,3,4,5 };

    for (const auto& x : array)
        cout << x << " ";

    return 0;
}
#endif


//shared_ptr��use_count()
#if 0
#include <iostream>

using namespace std;

int main()
{
    auto pNico = make_shared<string>("Nico");

    cout << pNico.use_count();

    return 0;
}
#endif


//shared_ptr��unique_ptr�÷�����
#if 0
#include <iostream>

int main()
{
    // shared_ptr
    // get and attach shared memory for 100 ints:
    //д��һ��
    std::shared_ptr<int> sp(new int[100], [](int* p)
        { delete[]p; }
    );
    //д������
    std::shared_ptr<int> sp1(new int[100], std::default_delete<int[]>());

    // unique_ptr
    //д��һ��
    std::unique_ptr<int[]> up(new int[100]);
    //д������
    std::unique_ptr<int, void (*)(int*)> up1(new int[100], [](int* p) {
        delete[]p;
        });
    //����д����
    /*std::unique_ptr<int[], void(*)(int*)> up1(new int[100], []() {
        });*/

    for (int i = 0; i < 100; ++i) {
        sp.get()[i] = i * 42;
        //����д����
        //*(smp + i) = i * 42;
    }

    for (int i = 0; i < 100; ++i) {
        //д��һ��
        up.get()[i] = i * 42;
        //д������
        up[i] = i * 42;
    }

    // deal with shared memory somewhere else:
    //...
    std::cout << "<return>" << std::endl;
    std::cin.get();

    // release shared memory here:
    sp.reset();
    //...
}
#endif


//ԭ�Ӳ���
#if 0
#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> atomicInt;

    // ʹ�� store ��ֵԭ�ӵش洢�� atomicInt ������
    atomicInt.store(10);

    std::cout << "Value in atomicInt: " << atomicInt.load() << std::endl;

    return 0;
}
#endif


//����㽫ͬһ����̬������ڴ��ַ���ݸ���� shared_ptr ʵ��������
//�ᵼ�³������δ�������Ϊ��
//������Ϊ��� shared_ptr ʵ������Գ����ͷ�ͬһ���ڴ��ַ��
//���ܵ����ظ��ͷ��ڴ棬�Ӷ���������
//һ����̬������ڴ�ռ�ֻ���ɡ�һ�顿shared_ptr����
#if 0
#include <iostream>

using namespace std;

int main()
{
    //��ȷд��
    //shared_ptr<int>sp1(new int);
    //shared_ptr<int>sp2(sp1);

    //����д����
    //һ����̬������ڴ�ռ��ɡ����顿shared_ptr����
    int* p = new int;
    shared_ptr<int>sp1(p);
    shared_ptr<int>sp2(p);

    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;

    return 0;
}
#endif


//��������ִ��ʱ��
#if 0
#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;

int main()
{
    auto system_start = chrono::system_clock::now();

    Sleep(5000);

    auto diff = chrono::system_clock::now() - system_start;
    //                                                               ΢��
    auto sec = chrono::duration_cast<chrono::microseconds>(diff);

    cout << sec.count() << endl;

    return 0;
}
#endif


//ʹ��array���洫ͳ����
#if 0
#include <iostream>
#include <array>
using namespace std;

void Print(const array<int, 5>& myarray);

int main()
{
    array<int, 5>myarray{ 1,2 };

    Print(myarray);

    return 0;
}
void Print(const array<int, 5>& myarray)
{
    for (auto x : myarray)
        cout << x << " ";
}
#endif


//�ӱ�׼�����ȡstring������Ȼ���ӡ(ȥ���ظ����ַ���)
//�Լ�д�ķ�����
#if 0
#include <iostream>
#include <string>
#include <set>
//#include <algorithm>
using namespace std;

int main()
{
    string str[10];

    string tmp;
    int index = 0;
    while (cin >> tmp)
    {
        str[index++].append(tmp);
    }

    //qsort(str,index,);//ÿ��Ԫ�ش�С��һ��������qsort()
   /* sort(str,str+index);

    for (const auto& x : str)
        cout << x << endl;*/

    set<string> se;

    for (int i = 0; i < index; ++i)
    {
        se.insert(str[i]);
    }

    for (const auto& x : se)
        cout << x << endl;

    return 0;
}
#endif
//��һ��
#if 0
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<string> coll;

    //ʹ�ô���������
    // read all words from the standard input
    // - source: all strings until end-of-file (or error)
    // - destination: coll (inserting)
    copy(istream_iterator<string>(cin),    // start of source
        istream_iterator<string>(),       // end of source 
        back_inserter(coll));             // destination

    //istream_iterator<string>(cin)
    //�����һ���ɴӡ���׼���봮��(standard input stream) cin����ȡ���ݵ� stream iterator��
    //���е� template ʵ�� string��ʾ��� stream iteratorר˾��ȡ�������͵�Ԫ��(string ��
    // �ͽ��ڵ�13�½���)����ЩԪ��ͨ��һ��� operator >>����ȡ���������ÿ���㷨��ͼ
    //������һԪ��ʱ��istream iterator �ͻὫ������ͼת��Ϊ�����ж���
    //cin >> string
    //��� string ��ִ�е� input������ͨ����ȡ�Կհ׷ָ�������(�� 13.2.10 �ڵ� 677ҳ),
    //��������㷨����Ϊ���ǡ����ֶ�ȡ��(word by word)��

    //istream_iterator<string>()
    //�����istream iterator�� default ���캯��������һ������������������(end - of - stream)
    //�ĵ������������������������ǣ��㲻���ٴ��ж�ȡ�κζ�����

    // sort elements
    sort(coll.begin(), coll.end());

    // print all elements without duplicates
    // - source: coll
    // - destination: standard output (with newline between elements)
    unique_copy(coll.cbegin(), coll.cend(),           // source
        ostream_iterator<string>(cout, "\n")); // destination
}
#endif
//������
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    // create a string set
    // - initialized by all words from standard input
    set<string> coll((istream_iterator<string>(cin)),
        istream_iterator<string>());

    // print all elements
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}
#endif
//������
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    // create a string vector
    // - initialized by all words from standard input
    vector<string> coll((istream_iterator<string>(cin)),
        istream_iterator<string>());

    // sort elements
    sort(coll.begin(), coll.end());

    // print all elements ignoring subsequent duplicates
    unique_copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}
#endif
//�Ƚ�
// 1. ʹ�� copy() �� ostream_iterator�� 2. ʹ�û��ڷ�Χ��forѭ��
//�����������
//1.�ǳ���࣬һ�д��뼴��������񡣿���֧����ͨ������copy(flag,flag+10000,ostream_iterator<bool>(cout));
// ���ǣ�����Щ�����ԣ������޷����и����ӵĴ����ת�������
//2.��������ֱ�ۡ���ʹ������׶�������������Ҫ��������и�����ƻ�ת��ʱ��
// �������ѭ���ڲ�����߼�����������и�ʽ�����������������


//ɾ�������е�Ԫ�أ�Ҫ��֤��ն�ݳ�������
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> coll;

    // insert elements from 6 to 1 and 1 to 6
    for (int i = 1; i <= 6; ++i)
    {
        coll.push_front(i);
        coll.push_back(i);
    }

    // print all elements of the collection
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 3
    // - retain new end
    list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

    // print resulting elements of the collection
    copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
    cout << endl;

    // print number of removed elements
    cout << "number of removed elements: "
        << distance(end, coll.end()) << endl;

    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //��ն�ݳ�����
    // remove "removed" elements 
    coll.erase(end, coll.end());

    // print all elements of the modified collection
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "));

    cout << endl;
}
//�õ�һ�����ɾ��Ԫ��
//coll.erase(remove(coll.begin(),coll.end(),3),coll.end());

//***ע***
//���ڷǹ���ʽ��������ʹ��remove����ɾ��ָ����Ԫ��
//remove���������ı伯����Ԫ�صĸ�����
//�߼�����Ҫ��ɾ����Ԫ�ر�����Ԫ�ظ��ǣ���ĩβ��Щδ�����ǵ�Ԫ��ԭ�ⲻ��
//���߼����Ѿ����������������
//��remove()��������erase()��������ն�ݳ���

//���ڹ���ʽ��������ֱ��ʹ��erase����ɾ��Ԫ��

//���
//����list��������������ר�ŵ��Ż�Ч�ʵ�remove()��remove_if()������
//��˶����㷨vs��Ա����
//����ѡ�ó�Ա����������
#endif


//ʵ����ִ��ʱȷ������
#if 0
#include <list>
#include <algorithm>
#include <iostream>

#include <string>

// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

using namespace std;

// function object that adds the value with which it is initialized
class AddValue
{
private:
    int theValue;    // the value to add
public:
    // constructor initializes the value to add
    AddValue(int v) : theValue(v)
    {}

    // the "function call" for the element adds the value
    void operator() (int& elem) const
    {
        elem += theValue;
    }
};

int main()
{
    list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    PRINT_ELEMENTS(coll, "initialized:                ");

    // add value 10 to each element
    for_each(coll.begin(), coll.end(),    // range
        AddValue(10));               // operation

    PRINT_ELEMENTS(coll, "after adding 10:            ");

    // add value of first element to each element
    for_each(coll.begin(), coll.end(),    // range
        AddValue(*coll.begin()));    // operation

    PRINT_ELEMENTS(coll, "after adding first element: ");

    retunr 0;
}
#endif


//����������bind
#if 0
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

using namespace std;
using namespace std::placeholders;//����ʹ��ռλ����_1

int main()
{
    set<int, greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    deque<int> coll2;

    // Note: due to the sorting criterion greater<>() elements have reverse order:
    PRINT_ELEMENTS(coll1, "initialized: ");

    // transform all elements into coll2 by multiplying them with 10
    transform(coll1.cbegin(), coll1.cend(),      // source
        back_inserter(coll2),             // destination
        bind(multiplies<int>(), _1, 10));   // operation

    PRINT_ELEMENTS(coll2, "transformed: ");

    // replace value equal to 70 with 42
    replace_if(coll2.begin(), coll2.end(),       // range
        bind(equal_to<int>(), _1, 70),     // replace criterion
        42);                             // new value

    PRINT_ELEMENTS(coll2, "replaced:    ");

    // remove all elements with values between 50 and 80
#if 0
    coll2.erase
    (
        remove_if
        (
            coll2.begin(), coll2.end(),
            bind
            (
                logical_and<bool>(), bind(greater_equal<int>(), _1, 50), bind(less_equal<int>(), _1, 80)
            )
        ),
        coll2.end()
    );
#endif

#if 1
    coll2.erase(
        remove_if
        (coll2.begin(), coll2.end(),
            [](int num)
            {
                return num >= 50 && num <= 80;
            }
        ),
        coll2.end()
    );
#endif

    PRINT_ELEMENTS(coll2, "removed:     ");

    return 0;
}
#endif


//����array����Ҫ�Ե��������֡���һԪ�صĵ�ַ��
#if 0
#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5>myarray{ 0 };

    //cout << (int*)(myarray.begin() )<< endl;
    cout << myarray.data() << endl;

    *(myarray.data()) = 1;

    cout << myarray[0] << endl;

    return 0;
}
#endif


//ʹ��tuple
#if 0
#include <iostream>
#include <tuple>
#include <array>
using namespace std;

int main()
{
    tuple<int, int, int> tuple1{ 1,2,3 };
    cout << get<0>(tuple1) << endl;

    tuple1 = make_tuple(4, 5, 6);
    cout << get<1>(tuple1) << endl;

    //array�ṩ��tuple�ӿ�
    array<int, 5>a1{ 1,2,3 };
    cout << get<1>(a1) << endl;

    return 0;
}
#endif


//accumulate() �����ֵ     �����÷�
//��ݴ�ӡ��
// 1-2-3-4-5-6-7-8-9-10 �� 10-9-8-7-6-5-4-3-2-1
#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <string>

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = std::accumulate(v.begin(), v.end(), 0);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    auto dash_fold = [](std::string a, int b) {
        return std::move(a) + '-' + std::to_string(b);
        };

    //����д����
    /*
    auto dash_fold = [](int a, int b) {
        return std::to_string(a) + '-' + std::to_string(b);
        };
    */
    //ԭ��
    //accumulate()ʵ�ַ�����
    /*
template<class InputIt, class T, class BinaryOperation>
constexpr // C++20 ��
T accumulate(InputIt first, InputIt last, T init,
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // C++20 ���� std::move //����������һ�� unique_ptr �Ͳ���Ҫmove()
    }
    return init;
}
    */

    std::string s = std::accumulate(std::next(v.begin(), 1), v.end(),
        std::to_string(v[0]), // ����Ԫ�ؿ�ʼ
        dash_fold);

    // ʹ��������������۵�
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
        std::to_string(v.back()), // ����Ԫ�ؿ�ʼ
        dash_fold);

    std::cout << "sum: " << sum << '\n'
        << "product: " << product << '\n'
        << "dash-separated string: " << s << '\n'
        << "dash-separated string (right-folded): " << rs << '\n';
}
#endif
//Ҳ������transform()�����accumulate()ʵ����ͬ����
#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <algorithm>

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::string firstElement = std::to_string(v[0]);

    // ʹ�� std::transform ������ת��Ϊ�ַ���
    //***ע***
    //��Ϊaccumulate()��ԭ����
    //�ǻ��õ�����v�ĵ�һ��Ԫ�أ���������ۻ���
    //���Բ���ֻ��������v�еڶ���Ԫ�ص�ĩβԪ��
    std::vector<std::string> stringValues(v.size() - 1);
    std::transform(std::next(v.begin(), 1), v.end(), stringValues.begin(),
        [](int value) { return std::to_string(value); });

    // ʹ�� std::accumulate ���ַ�����������
    std::string s = std::accumulate(stringValues.begin(), stringValues.end(),
        firstElement,
        [](std::string a, std::string b)
        {
            return std::move(a) + '-' + std::move(b);
        });

    // ʹ��������������۵�
    std::vector<std::string> reversedStringValues(v.size() - 1);
    std::transform(std::next(v.rbegin()), v.rend(),
        reversedStringValues.begin(),
        [](int value) { return std::to_string(value); });

    std::string rs = std::accumulate(reversedStringValues.begin(), reversedStringValues.end(),
        std::to_string(v.back()),
        [](std::string a, std::string b) {
            return std::move(a) + '-' + std::move(b);
        });

    std::cout
        << "dash-separated string: " << s << '\n'
        << "dash-separated string (right-folded): " << rs << '\n';
}
#endif


//swap()��vector���������á�ָ�롢��������ʧЧ��
//��Ϊ��Щ������ָ��ԭ��λ��
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>v1{ 1,2,3 };
    vector<int>v2{ 4,5 };

    auto it1 = next(v1.begin());
    auto it2 = next(v2.begin());

    cout << *it1 << " " << *it2 << endl;

    v1.swap(v2);

    //����������������ñ�������ԭ����Ԫ�ع���
    cout << *it1 << " " << *it2 << endl;

    return 0;
}
#endif


//deque�÷�
#if 0
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // create empty deque of strings
    deque<string> coll;

    // insert several elements
    coll.assign(3, string("string"));
    coll.push_back("last string");
    coll.push_front("first string");

    // print elements separated by newlines
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
    cout << endl;

    // remove first and last element
    coll.pop_front();
    coll.pop_back();
    //��������3��Ԫ��

    // insert "another" into every element but the first
    for (unsigned i = 1; i < coll.size(); ++i) {
        coll[i] = "another " + coll[i];
    }

    // change size to four elements
    coll.resize(4, "resized string");
    //��һ������ָ���µĴ�С
    //�ڶ�������ָ��������������С�������ܻᴴ�����κ���Ԫ�ص�ֵ��
    //���ַ�����resized string�������Ԫ�س��� 4 ���������Ԫ�ؽ���ɾ����ʹ��СΪ 4��

    // print elements separated by newlines
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}
#endif


//list�÷�
#if 0
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
    cout << "list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << "list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

int main()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i = 0; i < 6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // insert all elements of list1 before the first element with value 3 of list2
    // - find() returns an iterator to the first element with value 3
    list2.splice(
        find(list2.begin(), list2.end(), 3),// destination position       
        list1);                          // source list
    printLists(list1, list2);

    // move first element of list2 to the end
    list2.splice(
        list2.end(),        // destination position
        list2,              // source list
        list2.begin());     // source position
    printLists(list1, list2);

    // sort second list, assign to list1 and remove duplicates
    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    // merge both sorted lists into the first list
    list1.merge(list2);
    printLists(list1, list2);
}
#endif


//forward_list�÷�
#if 0
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void printLists(const string& s, const forward_list<int>& l1,
    const forward_list<int>& l2)
{
    cout << s << endl;
    cout << " list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << " list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    // create two forward lists
    forward_list<int> list1 = { 1, 2, 3, 4 };
    forward_list<int> list2 = { 77, 88, 99 };
    printLists("initial:", list1, list2);

    // insert six new element at the beginning of list2
    list2.insert_after(list2.before_begin(), 99);
    list2.push_front(10);
    list2.insert_after(list2.before_begin(), { 10,11,12,13 });
    printLists("6 new elems:", list1, list2);

    // insert all elements of list2 at the beginning of list1
    list1.insert_after(list1.before_begin(),
        list2.begin(), list2.end());
    printLists("list2 into list1:", list1, list2);

    // delete second element and elements after element with value 99
    list2.erase_after(list2.begin());
    list2.erase_after(
        find(list2.begin(), list2.end(), 99),
        list2.end());
    printLists("delete 2nd and after 99:", list1, list2);

    // sort list1, assign it to list2, and remove duplicates
    list1.sort();
    list2 = list1;
    list2.unique();
    printLists("sorted and unique:", list1, list2);

    // merge both sorted lists into list1
    list1.merge(list2);
    printLists("merged:", list1, list2);
}
#endif


//lower_bound()��upper_bound()��equal_range()
#if 0
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> c;

    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);

    //lower_bound(3) ����һ����������ָ���һ�� >= 3 ��Ԫ�ء�
    //�ڼ����У���һ��>= 3 ��Ԫ���� 4��
    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    //upper_bound(3) ���ص�һ�� > 3 ��Ԫ�صĵ�������
    // �ڼ����У���һ�� > 3 ��Ԫ��Ҳ�� 4��
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    //***���***
    //equal_range(3) ����һ�Ե���������ʾֵΪ 3 ��Ԫ�ط�Χ��
    //�ڱ����У����ڲ�����ֵΪ 3 ��Ԫ�أ�
    //���������������ָ���һ����С�� 3 ��Ԫ�أ��� 4��
    cout << "equal_range(3): " << *c.equal_range(3).first << " "
        << *c.equal_range(3).second << endl;
    cout << endl;

    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " "
        << *c.equal_range(5).second << endl;
}
#endif


//���ڹ���������ʵ��������ָ������׼��
#if 0
#include <iostream>
#include <set>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

// type for runtime sorting criterion
class RuntimeCmp
{
public:
    enum cmp_mode { normal, reverse };
private:
    cmp_mode mode;
public:
    // constructor for sorting criterion
    // - default criterion uses value normal
    RuntimeCmp(cmp_mode m = normal) : mode(m)
    {}
    // comparison of elements
    // - member function for any element type
    template <typename T>
    bool operator() (const T& t1, const T& t2) const
    {
        return mode == normal ? t1 < t2 : t2 < t1;
    }
    // comparison of sorting criteria
    bool operator== (const RuntimeCmp& rc) const
    {
        return mode == rc.mode;
    }
};

// type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp> IntSet;

int main()
{
    // create, fill, and print set with normal element order
    // - uses default sorting criterion
    IntSet coll1 = { 4, 7, 5, 1, 6, 2, 5 };
    PRINT_ELEMENTS(coll1, "coll1: ");

    // create sorting criterion with reverse element order
    RuntimeCmp reverse_order(RuntimeCmp::reverse);

    // create, fill, and print set with reverse element order
#if 0 
    IntSet coll2(reverse_order);
    coll2 = { 4, 7, 5, 1, 6, 2, 5 };
#endif

    //����дΪ��
#if 1
    set<int, RuntimeCmp> coll2({ 4, 7, 5, 1, 6, 2, 5 }, reverse_order);
#endif

    PRINT_ELEMENTS(coll2, "coll2: ");

    // assign elements AND sorting criterion
    coll1 = coll2;
    coll1.insert(3);
    PRINT_ELEMENTS(coll1, "coll1: ");

    // just to make sure...
    //����set��˵������ std::set �����Ϊ����Ψһ�ļ�����ͬʱҲ��ֵ��
    // ��ˣ����� std::set ���������ڴ��������»���ʹ�� key_comp �� value_comp ��
    // ������������Բ���
    //key_comp ����������һ���ȽϺ������ú������Ƚϼ�����Ԫ�صļ�
    //value_comp ����������һ���Ƚ�ֵ�ıȽϺ���
    if (coll1.value_comp() == coll2.value_comp())
    {
        cout << "coll1 and coll2 have the same sorting criterion"
            << endl;
    }
    else
    {
        cout << "coll1 and coll2 have a different sorting criterion"
            << endl;
    }
}
#endif


//ʹ���㷨��lambda������mapԪ��
//lambda���βε���ʽд��
#if 0
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, float> strmap{ {"abc",1.1188},{"def",2.1} };

    //д��һ��
    for_each(strmap.begin(), strmap.end(),
        [](const pair<const string, float>& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    //д������
    for_each(strmap.begin(), strmap.end(),
        [](const map<string, float>::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    //д������
    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    return 0;
}
#endif


//���ַ�����map��multimap�ڰ�������
#if 0
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, float> strmap{ {"abc",1.1188},{"def",2.1} };

    strmap.insert({ "a",1.1 });
    strmap.insert(map<string, float>::value_type("b", 2.2));
    strmap.insert(decltype(strmap)::value_type("c", 3.3));
    strmap.insert(pair<const string, float>("d", 4.4));
    strmap.insert(make_pair("e", 5));
    strmap["f"] = 6;//***ע***
    //����Ԫ�ذ��巽ʽ�ȹ߳��� map���巽ʽ����7.8.2�ڵ�340ҳ
    //����̸����ԭ������Ԫ�ر�����ʹ��default ���캯���� value ��ʼ����
    //���ó�ֵ�����ֱ������� value ���ǡ�

    strmap["g"];
    //��operator[]���������Ͳ���������������������Ѱ�� array Ψһ��֮ͬ���������
    //ѡ��ĳ key ��Ϊ������������ȴû����ӦԪ�أ���ômap���Զ�����һ����Ԫ�أ���value
    //���������͵� default ���캯����ʼ������ˣ��㲻����ָ��һ�������� default ���캯����
    //��value ���͡�ע�⣬�������Ͷ���һ�� default ���캯����������ֵ0(�� 3.2.1 �ڵ� 37ҳ)��

    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    return 0;
}
#endif


//�Ƴ�Ԫ�أ�������ʹ��һ������ʱ����Ч�ĵ�����
//(��Ϊ�õ�����ָ����һ����ɾ����Ԫ�ص�λ��)
//***ע***
//���ĳԪ�ر�ɾ������������(����vector �� deque����Ϊ���ܵ����ڴ����·���)
//����֤�������Լ�����ָ��δ��ɾ����Ԫ�ء���reference����������Ч��
//��ָ��ɾ����Ԫ�صĵ�������Ҫ���иöδ���չʾ�Ĳ�����
#if 0
#include <iostream>
#include <map>
#include <algorithm>
#include <vector> 
using namespace std;

int main()
{
    map<string, float> strmap{ {"abc",1.1188},{"def",2.1} };

    strmap.insert({ "a",1.1 });
    strmap.insert(map<string, float>::value_type("b", 2.2));
    strmap.insert(decltype(strmap)::value_type("c", 3.3));
    strmap.insert(pair<const string, float>("d", 4.4));
    strmap.insert(make_pair("e", 5));

    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });
    cout << endl;

    //������Ƴ�Ԫ��д����
#if 0
    for (auto pos = strmap.begin(); pos != strmap.end(); ++pos)
    {
        if (pos->first == "a")
        {
            strmap.erase(pos);//pos�᲻�ٳ�Ϊһ����Ч�ĵ��������˺�δ��pos
        }                                 //������ֵ��ֱ��ʹ�ã�����������ڼ����
    }
#endif

    //����Ĵ���д����
#if 0
    for (auto pos = strmap.begin(); pos != strmap.end(); ++pos)
    {
        if (pos->first == "a")
        {
            pos = strmap.erase(pos);
        }

        if (abs(pos->second - 4.4) <= 0.00001)
        {
            pos = strmap.erase(pos);
        }

        //***ע***
        //���´�������ʱ�ᱨ��
        /*
        if (abs(pos->second - 5) <= 0.00001)
        {
            //��Ϊerase()���ú�posֵΪstrmap.end()��++pos��ָ����Чλ�á�
            pos = strmap.erase(pos);
        }
        */
    }
#endif

    //��ȷд����
    for (auto pos = strmap.begin(); pos != strmap.end(); )
    {
        if (pos->first == "a" || abs(pos->second - 4.4) <= 0.00001)
        {
            //***���***
            //ָ�򱻲���Ԫ�ص����ú͵��������Ƿ������������ú͵���������Ӱ�졣
            //erase()����һ��������ָ�����̵ġ�Ԫ��
            //pos�ɴ˵õ�����
            pos = strmap.erase(pos);
        }
        else
            ++pos;
    }

    for (auto pos = strmap.begin(); pos != strmap.end(); )
    {
        if (abs(pos->second - 5) <= 0.00001)
        {
            pos = strmap.erase(pos);
        }
        else
        {
            ++pos;
        }
    }


    strmap.erase("abc");

    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    cout << endl;

    vector<int> vec{1,2,3,4,5,6,7,8,9};

    for (auto i = vec.begin(); i != vec.end();)
    {
        if (*i == 3 || *i == 8)
            i = vec.erase(i);
        else
            ++i;
    }

    //����д����
    // for (auto i = vec.begin(); i != vec.end();++i)
    // {
    //     if (*i == 3 || *i == 8)
    //         i = vec.erase(i);
    // }

    copy(vec.cbegin(), vec.cend(),
        ostream_iterator<int>(cout, "\n"));

    return 0;
}
#endif


//multimap�����ֵ�
#if 0
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // create multimap as string/string dictionary
    multimap<string, string> dict;

    // insert some elements in random order
    dict.insert({ {"day","Tag"}, {"strange","fremd"},
                    {"car","Auto"}, {"smart","elegant"},
                    {"trait","Merkmal"}, {"strange","seltsam"},
                    {"smart","raffiniert"}, {"smart","klug"},
                    {"clever","raffiniert"} });

    // print all elements
    cout.setf(ios::left, ios::adjustfield);
    cout << ' ' << setw(10) << "english "
        << "german " << endl;

    cout << setfill('-') << setw(20) << ""
        << setfill(' ') << endl;

    for (const auto& elem : dict) {
        cout << ' ' << setw(10) << elem.first
            << elem.second << endl;
    }
    cout << endl;

    // print all values for key "smart"
    //����key��Ӧ������valueֵ��ǰ���������key����û���򲻺��ʣ������//lower_bound()��upper_bound()��equal_range()����
    string word("smart");
    cout << word << ": " << endl;
    for (auto pos = dict.lower_bound(word); pos != dict.upper_bound(word);
        ++pos)
    {
        cout << "    " << pos->second << endl;
    }

    // print all keys for value "raffiniert"
    //����value��Ӧ������keyֵ
    word = ("raffiniert");
    cout << word << ": " << endl;
    for (const auto& elem : dict)
    {
        if (elem.second == word)
        {
            cout << "    " << elem.first << endl;
        }
    }
}
#endif


//ʹ��map��string����������ָ������׼��
#if 0
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// function object to compare strings
// - allows you to set the comparison criterion at runtime
// - allows you to compare case insensitive
class RuntimeStringCmp
{
public:
    // constants for the comparison criterion
    //                        ��ͨģʽ    ��Сд�޹�ģʽ
    enum cmp_mode { normal, nocase };
private:
    // actual comparison mode
    const cmp_mode mode;

    // auxiliary function to compare case insensitive
    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }
public:
    // constructor: initializes the comparison criterion
    RuntimeStringCmp(cmp_mode m = normal) : mode(m)
    {}

    // the comparison
    bool operator() (const string& s1, const string& s2) const
    {
        if (mode == normal)
        {
            return s1 < s2;
        }
        else
        {
            //lexicographical_compare() �ֵ���Ƚ�
            return lexicographical_compare(s1.begin(), s1.end(),
                s2.begin(), s2.end(), nocase_compare);
        }
    }
};

// container type:
// - map with
//       - string keys
//       - string values
//       - the special comparison object type
typedef map<string, string, RuntimeStringCmp> StringStringMap;

// function that fills and prints such containers
void fillAndPrint(StringStringMap& coll);

int main()
{
    // create a container with the default comparison criterion
    StringStringMap coll1;//ʹ��һ��RuntimeStringCmp�ĺ���������Ĭ�ϵ�normalΪ��ֵ
    fillAndPrint(coll1);

    // create an object for case-insensitive comparisons
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
    // create a container with the case-insensitive comparisons criterion
    StringStringMap coll2(ignorecase);
    //***���***
    //ʹ�õ���   explicit map(const Compare & comp, const Allocator & alloc = Allocator());
    //ʹ��һ������ΪRuntimeStringCmp�ĺ������󣬲���nocaseΪ��ֵ��nocase����
    //������������ԡ���Сд�޹ء�ģʽ����ַ����ıȽϺ�����

    fillAndPrint(coll2);
}

void fillAndPrint(StringStringMap& coll)
{
    // insert elements in random order
    coll["Deutschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";

    // print elements
    cout.setf(ios::left, ios::adjustfield);
    for (const auto& elem : coll)
    {
        cout << setw(15) << elem.first << " "
            << elem.second << endl;
    }
    cout << endl;
}
#endif


//������������Ĳ��ֲ���
#if 0
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_multiset<int>unset;

    //��������ӣ����ӡ�����ϣ��ռ������ʡ������ܿ��ܡ���
    unset.max_load_factor(0.7);

    //׼��100/��������Ӹ�Ԫ�صĴ�С��bucket���Ա�����û����100��Ԫ�ؾ�rehash()
    unset.rehash(100 / 0.7);
    //׼��100��Ԫ�ش�С��bucket
    unset.reserve(100);

    return 0;
}
#endif


//��������������ṩ�Լ���Hash�����͵ȼ�׼��
#if 0
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

#include <functional>

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
template <typename T>
inline void hash_combine(std::size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val(std::size_t& seed, const T& val)
{
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types&... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

// auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template <typename... Types>
inline std::size_t hash_val(const Types&... args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
private:
    string fname;
    string lname;
    long   no;
public:
    Customer(const string& fn, const string& ln, long n)
        : fname(fn), lname(ln), no(n)
    {}

    friend ostream& operator << (ostream& strm, const Customer& c)
    {
        return strm << "[" << c.fname << "," << c.lname << ","
            << c.no << "]";
    }

    friend class CustomerHash;
    friend class CustomerEqual;
};

class CustomerHash
{
public:
    std::size_t operator() (const Customer& c) const
    {
        return hash_val(c.fname, c.lname, c.no);
    }
};

class CustomerEqual
{
public:
    bool operator() (const Customer& c1, const Customer& c2) const
    {
        return c1.no == c2.no;
    }
};

int main()
{
    // unordered set with own hash function and equivalence criterion
    unordered_set<Customer, CustomerHash, CustomerEqual> custset;

    custset.insert(Customer("nico", "josuttis", 42));

    PRINT_ELEMENTS(custset);
}
#endif


//ʹ��Lambda��ΪHash�����͵ȼ�׼��
#if 0
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
template <typename T>
inline void hash_combine(std::size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val(std::size_t& seed, const T& val)
{
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types&... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

// auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template <typename... Types>
inline std::size_t hash_val(const Types&... args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
private:
    string fname;
    string lname;
    long   no;
public:
    Customer(const string& fn, const string& ln, long n)
        : fname(fn), lname(ln), no(n)
    {}

    string firstname() const
    {
        return fname;
    };

    string lastname() const
    {
        return lname;
    };

    long number() const
    {
        return no;
    };

    friend ostream& operator << (ostream& strm, const Customer& c)
    {
        return strm << "[" << c.fname << "," << c.lname << ","
            << c.no << "]";
    }
};

int main()
{
    // lambda for user-defined hash function
    auto hash = [](const Customer& c) {
        return hash_val(c.firstname(), c.lastname(), c.number());
        };

    // lambda for user-defined equality criterion
    auto eq = [](const Customer& c1, const Customer& c2) {
        return c1.number() == c2.number();
        };

    // create unordered set with user-defined behavior
    unordered_set<Customer, decltype(hash), decltype(eq)>
        custset(10, hash, eq);
    //***���***
    //����ʹ��decltype���� lambda���ͣ�ʹ���Դ�������Ϊ unordered ��������ʽ��
    //template ʵ�Ρ�
    //�� lambda�������� default ���캯���� assignment ��������
    //��ˣ���Ҳ���뽫lambda�������캯����
    //���������Ǳ����Ϊ�ڶ��͵���ʵ�Σ������������������ָ������� bucket ��С��
    //����Ϊ10��

    custset.insert(Customer("nico", "josuttis", 42));
    PRINT_ELEMENTS(custset);

}
#endif


//ʹ��Bucket�ӿ�
//���Է����ڲ���Ͱ��buckets����
//ÿ��Ͱ��һ���洢Ԫ�ص����������Խ����С���ͬ��ϣֵ��Ԫ�ء��洢��ͬһ��Ͱ�С�
//***ע***
// ��ͬ��ϣֵ��Ԫ�ء�Ҳ�����ǲ�ͬ�ļ���������ֻ�Ƿ����˹�ϣ��ͻ��
// ����ϣ����ڲ�����ȷ��������ͬһ��Ͱ�еõ��洢���ڲ���Ԫ��ʱ��
// ��ϣ�����ݼ����������ȷ���������ĸ�Ԫ�ء�
// 
// �� std::unordered_multimap �У�
// ��ͬ��ϣֵ��Ԫ�ر��洢��ͬһ��Ͱ�У���ͬһ��Ͱ�е�Ԫ�ؿ��ܾ��в�ͬ�ļ���
// ��ˣ�ͬһ��Ͱ�д洢��Ԫ�صļ���һ����ͬ�������Ǿ�����ͬ�Ĺ�ϣֵ��
#if 0
#include <iostream>
#include <iomanip>
#include <iterator>
#include <typeinfo>

#include <unordered_set>
#include <unordered_map>
#include <string>

// generic output for pairs (map elements)
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p)
{
    return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState(const T& cont)
{
    // basic layout data:
    std::cout << "size:            " << cont.size() << "\n";
    std::cout << "buckets:         " << cont.bucket_count() << "\n";
    std::cout << "load factor:     " << cont.load_factor() << "\n";
    std::cout << "max load factor: " << cont.max_load_factor() << "\n";

    // iterator category:
    if (typeid(typename std::iterator_traits<typename T::iterator>::iterator_category)
        == typeid(std::bidirectional_iterator_tag))
    {
        std::cout << "chaining style:  doubly-linked" << "\n";
    }
    else
    {
        std::cout << "chaining style:  singly-linked" << "\n";
    }

    // elements per bucket:
    std::cout << "data: " << "\n";
    for (auto idx = 0u; idx != cont.bucket_count(); ++idx)
    {
        std::cout << " b[" << std::setw(2) << idx << "]: ";

        for (auto pos = cont.begin(idx); pos != cont.end(idx); ++pos)
        {
            std::cout << *pos << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


int main()
{
    // create and initialize an unordered set
    std::unordered_set<int> intset = { 1,2,3,5,7,11,13,17,19 };
    printHashTableState(intset);

    // insert some additional values (might cause rehashing)
    intset.insert({ -7,17,33,4 });
    printHashTableState(intset);

    using std::string;
    // create and initialize an unordered multimap as dictionary
    std::unordered_multimap<string, string> dict = {
                  {"day","Tag"},
                  {"strange","fremd"},
                  {"car","Auto"},
                  {"smart","elegant"},
                  {"trait","Merkmal"},
                  {"strange","seltsam"}
    };
    printHashTableState(dict);

    // insert some additional values (might cause rehashing)
    dict.insert({ {"smart","raffiniert"},
                 {"smart","klug"},
                 {"clever","raffiniert"}
        });
    printHashTableState(dict);

    // modify maximum load factor (might cause rehashing)
    dict.max_load_factor(0.7);
    printHashTableState(dict);
}
#endif


//������ʽ�������ʹC-Style Array��Ϊһ��STL����
#if 0
#include <iterator>
#include <vector>
#include <iostream>

int main()
{
    int vals[] = { 33, 67, -4, 13, 5, 2 };

    // use begin() and end() for ordinary C arrays
    std::vector<int> v(std::begin(vals), std::end(vals));

    //�ȼ�������д�� ��������C++11֮ǰ��
    //std::vector<int> v(vals, vals+sizeof(vals)/sizeof(vals[0]));

    // use global begin() and end() for containers:
    std::copy(std::begin(v), std::end(v),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
#endif


//ͨ��STL�����ṩ����value���壬������reference����
//STL����Ҫʵ��Reference����
//����һ�����á�����ָ�롿
#if 0
#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>

class Item
{
private:
    std::string name;
    float  price;

public:
    Item(const std::string& n, float p = 0) : name(n), price(p)
    {}

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string& n)
    {
        name = n;
    }

    float getPrice() const
    {
        return price;
    }

    float setPrice(float p)
    {
        price = p;
        return p;
    }
};

template <typename Coll>
void printItems(const std::string& msg, const Coll& coll)
{
    std::cout << msg << std::endl;

    for (const auto& elem : coll)
    {
        std::cout << ' ' << elem->getName() << ": "
            << elem->getPrice() << std::endl;
    }
}

int main()
{
    using namespace std;

    // two different collections sharing Items
    typedef shared_ptr<Item> ItemPtr;

    set<ItemPtr> allItems;
    deque<ItemPtr> bestsellers;

    // insert objects into the collections
    // - bestsellers are in both collections
    bestsellers = {
        ItemPtr(new Item("Kong Yize",20.10)),
         ItemPtr(new Item("A Midsummer Night's Dream",14.99)),
         ItemPtr(new Item("The Maltese Falcon",9.88))
    };

    allItems = {
        ItemPtr(new Item("Water",0.44)),
        ItemPtr(new Item("Pizza",2.22))
    };
    allItems.insert(bestsellers.begin(), bestsellers.end());

    // print contents of both collections
    printItems("bestsellers:", bestsellers);
    printItems("all:", allItems);
    cout << endl;

    // double price of bestsellers
    for_each(bestsellers.begin(), bestsellers.end(),
        [](shared_ptr<Item>& elem) {
            elem->setPrice(elem->getPrice() * 2);
        });

    // print contents of both collections
    printItems("bestsellers:", bestsellers);
    printItems("all:", allItems);
    cout << endl;

    // replace second bestseller by first item with name "Pizza"
    bestsellers[1] = *(find_if(allItems.begin(), allItems.end(),
        [](shared_ptr<Item> elem)
        {
            return elem->getName() == "Pizza";
        }));

    //***ע***
    //ʹ��shared_ptr<>��������临�ӡ����磬���set ʹ��find(),���ҳ�ӵ�����
    //value ��Ԫ�أ����ڱȽϵ�ȴ���ڲ�(��new����)�� pointer 
    // allItems.find(ItemPtr(new Item("Pizza",2.22)))   //can'tbe successful
    //����д��Ҳ������
    //bestsellers[1] = find(allItems.begin(), allItems.end(),string("Pizza"));

    // set price of first bestseller
    bestsellers[0]->setPrice(44.77);

    // print contents of both collections
    printItems("bestsellers:", bestsellers);
    printItems("all:", allItems);
}
#endif


//Reference Wrapper �������⸲����
//������<functional>�е� class std::reference_wrapper<>��Ҫ����
//��ι�� reference ��function template, ����ԭ����by value��ʽ���ܲ�����
// ����һ����������T, ��� class�ṩref()������ʽת��ΪT&, 
// һ�� cref()������ʽת��Ϊ const T&, ���������� 
// function template ���Բ��� reference ������Ҫ��д�ػ��汾��
#if 0
#include <iostream>

using namespace std;

template<typename T>
void f1(T val);

int main()
{
    int num = 1;

    f1<int>(num);
    cout << num << endl;

    f1(ref(num));//ref()
    cout << num << endl;

    return 0;
}

template<typename T>
void f1(T val)
{
    ++val;
}
#endif


//ʵ��Reference����
//��������ʹ�� class reference_wrapper<> 
//�ŵ㣺����Ҫ����ָ��
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Item
{
private:
    std::string name;
    float  price;

public:
    Item(const std::string& n, float p = 0) : name(n), price(p)
    {}

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string& n)
    {
        name = n;
    }

    float getPrice() const
    {
        return price;
    }

    float setPrice(float p)
    {
        price = p;
        return p;
    }
};

template <typename Coll>
void printItems(const std::string& msg, const Coll& coll)
{
    std::cout << msg << std::endl;

    for (const auto& elem : coll)
    {
        //��Ҫʹ��get()���������ʴ洢������
        std::cout << ' ' << elem.get().getName() << ": "
            << elem.get().getPrice() << std::endl;
    }
}

int main()
{
    using namespace std;

    //reference_wrapper<Item>: ����һ��ģ���࣬����װ�˶� Item ���Ͷ�������á�
    // reference_wrapper ����������Ϊ������д��ݣ�
    // �����Ǵ�������ʱ���Զ������Ľ����á�
    // ������������д洢�����Ǻ����õģ���Ϊ����ͨ��Ҫ��Ԫ���ǿɸ��Ƶģ�
    // ��������ͨ�����ǿɸ��Ƶġ�
    //������Ƴ���������Ҫ�������д洢���ö����Ǹ��ƶ���������
    // ���磬������Ҫ�������б����������ã�����ϣ��ͨ�������޸�ԭʼ����ʱ��
    vector<reference_wrapper<Item>>books;

    Item book1("bookname", 12.99);
    //����������Ԫ�أ����ǰ�����Ǹ�����
    books.push_back(book1);

    printItems("books:", books);
    cout << endl;

    //***ע***
    //ֱ���޸�book1��������ݣ�
    //��vector�����д�Ĳ��Ǹö�������ã�Ĭ�ϴ���ǿ�����value�������Ķ���
    //�ǾͲ���Ӱ��vector�����еĸö����д�����ݡ�
    //����������Ǹö�������ã��Ǿͻ�Ӱ��vector�����еĸö����д�����ݡ�
    book1.setPrice(9.99);

    cout << books[0].get().getPrice() << endl;

    printItems("books:", books);
    cout << endl;

    //***ע***
    //��������vector�ĳ��ԣ��޷�ͨ������
    //vector<Item&>books_test;
    //books_test.push_back(book1);
    //book1.setPrice(10.5);
    //cout << books_test[0].getPrice() << endl;
}
#endif


//С�᣺
//����������ʹ��ʱ��

//Ĭ�������Ӧ��ʹ�� vector��Vector���ڲ��ṹ��򵥣�������������ʣ�
//�������ݵķ���ʮ�ַ��������ݵĴ���Ҳ���졣

//�������Ҫ������ͷ����β��������Ƴ�Ԫ�أ�Ӧ�ò���deque�������ϣ��Ԫ��
//���Ƴ�ʱ�������ܹ��Զ������ڲ��ڴ���������ôҲ�ò���deque��

//�����Ҫ�����������ж�ִ��Ԫ�صİ��塢�Ƴ����ƶ����ɿ���ʹ��list��

//����㾭����Ҫ����ĳ��׼�����Ԫ�أ�Ӧ��ʹ�á����ݸ�׼�����hash����
//unordered set �� multiset

//����봦�� key/value pair,�����unordered(multi)map�����Ԫ�ش������Ҫ���ɲ���
//(multi)map


//������ʵ���������������
#if 0
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> coll;

    // insert elements from -3 to 9
    for (int i = -3; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    // print number of elements by processing the distance between beginning and end
    // - NOTE: uses operator - for iterators
    cout << "number/distance: " << coll.end() - coll.begin() << endl;

    // print all elements
    // - NOTE: uses operator < instead of operator !=
    vector<int>::iterator pos;
    for (pos = coll.begin(); pos < coll.end(); ++pos)
    {
        cout << *pos << ' ';
    }
    cout << endl;

    // print all elements
    // - NOTE: uses operator [] instead of operator *
    for (int i = 0; i < coll.size(); ++i)
    {
        cout << coll.begin()[i] << ' ';
    }
    cout << endl;

    // print every second element
    // - NOTE: uses operator +=
    for (pos = coll.begin(); pos < coll.end() - 1; pos += 2)
    {
        cout << *pos << ' ';
    }
    cout << endl;
    //***ע***
    //��2����λΪ�������ǰ���ӵ�������λ��ʱҪע��
    //��дΪ
    //for(pos= coll.begin();pos< coll.end(); pos += 2)
    //�������к�������Ԫ�أ����в���ȷ��Ϊ
    //ԭ��
    //������������������ǰ�桱�ᵼ�²���ȷ��Ϊ��ͬ������
    //������ʽpos += 2������������end()֮��Ҳ�ᵼ�²���ȷ��Ϊ��
}
#endif


//����������ظ�������
//����vector��array��string�ĵ�����
//ͨ����ʵ��ΪѰ��pointer, �� C++�����������޸��κλ�������
//(���� pointer)����ʱֵ�������� struct ��class ������
//��ˣ������������ʵ��ΪѰ�� pointer, �����ʧ�ܣ������ʵ��Ϊ class, �����ɹ���
//Ϊ�˱�֤��ֲ������ʹ��C++11�ṩ��next()
//next()�ô�֮һ��
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v{ 3, 4, 1 };

    auto it = v.begin();
    auto nx = std::next(it, 2);
    std::cout << *it << ' ' << *nx << '\n';

    std::sort(std::next(v.begin()), v.end());
    for (auto x : v)
        std::cout << x << ' ';

    //***ע***
    // ���ܱ��ʽ ++c.begin() ͨ���ܱ��룬Ȼ������֤����ô���� 
    // c.begin() ����ֵ���ʽ��������ʽ��������� (LegacyInputIterator) 
    // Ҫ��ָ����ֵ��������֤���С�
    // �����ǵ�������ָ��ʵ�ֻ��� operator++ Ϊ����ֵ�����޶���ʱ��
    //  ++c.begin() ���ܱ��룬�� std::next(c.begin()) ���ԡ�
}
#endif


//���ݵ��������࣬ѡ����ѵ�ǰ��/���˷�����advance()
//***ע***
//ǰ����next()    ���ˣ�prev()       ����
//�ڲ�����һ����ʱ�������advance()
#if 0
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    list<int>::iterator pos = coll.begin();

    // print actual element
    cout << *pos << endl;

    // step three elements forward
    advance(pos, 3);

    // print actual element
    cout << *pos << endl;

    // step one element backward
    advance(pos, -1);

    // print actual element
    cout << *pos << endl;
}
#endif


//next()�ô�֮����
//����û��operator +��operator -  ����Щ����
//������next()��ȷ��������ĳ��λ��ʱֹͣ
#if 0
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> coll;//����˫�������

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    auto pos = coll.begin();
    while (pos != coll.end() && std::next(pos) != coll.end())
    {
        cout << *pos << ' ';

        ++pos;
    }
    cout << endl;

    //forward �� bidirectional ���������ṩ operator +�� -
    //�������next()�������Ҫ����һ����ʱ�����Э�����ж�
    auto pos_1 = coll.begin();
    auto nextPos = pos_1;
    ++nextPos;
    while (pos_1 != coll.end() && nextPos != coll.end())
    {
        cout << *pos_1 << ' ';

        ++pos_1;
        ++nextPos;
    }

}
#endif


//���ݵ��������࣬ѡ����ѵļ������ķ�����distance()


//����������������ָ��Ԫ�ص�ֵ
#if 0
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    PRINT_ELEMENTS(coll);

    // swap first and second value
    iter_swap(coll.begin(), next(coll.begin()));

    PRINT_ELEMENTS(coll);

    // swap first and last value
    iter_swap(coll.begin(), prev(coll.end()));

    PRINT_ELEMENTS(coll);
}
#endif


//������������(iterator adapter)
//�������ĵ�����ת���ɷ��������
#if 0
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // create list with elements from 1 to 9
    vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // find position of element with value 5
    vector<int>::const_iterator pos;
    pos = find(coll.cbegin(), coll.cend(), 5);

    // print value to which iterator pos refers
    cout << "pos:  " << *pos << endl;

    // convert iterator to reverse iterator rpos
    vector<int>::const_reverse_iterator rpos(pos);

    // print value to which reverse iterator rpos refers
    cout << "rpos: " << *rpos << endl << endl;

    //***ע***
    //ת��ǰ��������߼�λ�÷����˱仯
    //�����ǰ�pos ת��Ϊrpos,���ǵ�����λ��ָ��ͬһ�㣬�����������������
    //(��˵������������߼�λ��)��ͬ��

    //***���***
    //rbegin()ָ����������ĩԪ�ص���һ��λ�ã�����������ú�ֵΪ��ĩԪ�ص�ֵ
    //rend()ָ�������ĵ�һ��Ԫ�ص�λ�ã�����������ú�ֵΪ��һ��Ԫ��ǰ��һ��λ��

    //Ϊʲôrend()ָ�������ĵ�һ��Ԫ�ص�λ�ã�
    //��Ϊ����������һ��������Ҫ���á���ĩԪ�ص���һλ�á���
    // Ȼ���� reverse ���������ԣ����λ��λ�ڵ�һԪ��֮ǰ��
    // �����ǣ����λ�ÿ��ܲ������ڣ���Ϊ��������Ҫ�����һԪ��֮ǰ��λ�úϷ�
    //���Զ��ڷ����������������rend()ָ�������ĵ�һ��Ԫ�ص�λ��(��λ��һ���Ϸ�)��
    //�����߼��Ͻ���Ϊ��һ��Ԫ��ǰ��һ��λ�á�
    //��������������߼����岻ͬ���������ý�����߼����壬
    //����߼����� value(Ҳ��������ָԪ��ֵ)Ҳ���Ƶ���ǰһ��Ԫ�����ϡ�
}
#endif


//�����������Ӧ��
//ʹ��һ�Ե�����������������ӡ�ҳ���Ԫ��
#if 0
#include <iterator>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(int elem)
{
    cout << elem << ' ';
}

int main()
{
    // create deque with elements from 1 to 9
    deque<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // find position of element with value 2
    deque<int>::const_iterator pos1;
    pos1 = find(coll.cbegin(), coll.cend(),  // range
        2);                          // value

    // find position of element with value 7
    deque<int>::const_iterator pos2;
    pos2 = find(coll.cbegin(), coll.cend(),  // range
        7);                          // value

    // print all elements in range [pos1,pos2)
    for_each(pos1, pos2,     // range
        print);         // operation
    cout << endl;

    // convert iterators to reverse iterators
    deque<int>::const_reverse_iterator rpos1(pos1);
    deque<int>::const_reverse_iterator rpos2(pos2);

    cout << "*rpos1=" << *rpos1 << endl;

    // print all elements in range [pos1,pos2) in reverse order
    for_each(rpos2, rpos1,   // range
        print);         // operation
    cout << endl;
    //***���***
    //����λ�ò��䣬�����߼�λ�øı䣬��ӡ�����������÷���Ԥ�ڡ�

    //ʹ��base()�����������ת��Ϊ����������
    deque<int>::const_iterator rrpos1(rpos1.base());

    cout << "*rrpos1=" << *rrpos1 << endl;
}
#endif


//back_insert_iterator��back_inserter()��Ӧ��
//ֻ������vector��deque��list��string��
#if 0
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    vector<int> coll;

    // create back inserter for coll
    // - inconvenient way
    back_insert_iterator<vector<int> > iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;
    PRINT_ELEMENTS(coll);

    // create back inserter and insert elements
    // - convenient way
    back_inserter(coll) = 44;
    back_inserter(coll) = 55;
    PRINT_ELEMENTS(coll);


    // use back inserter to append all elements again
    // - reserve enough memory to avoid reallocation
    //***ע***
    //�����͵�����ȷʵ�ܰ���Ԫ�ص������У�
    //���ǡ�����vector���ڴ������Ҫ���·����������
    //back inserter �ڰ���Ԫ��ʱ�����ܻ����ָ��� vector������������ʧЧ��
    //��ˣ������ǰ�������㹻�ռ䣬����㷨���ܻ��γɡ�Դ�˵�����ʧЧ��״̬��
    coll.reserve(2 * coll.size());

    copy(coll.begin(), coll.end(), back_insert_iterator<vector<int>>(coll));
    PRINT_ELEMENTS(coll);

    coll.reserve(2 * coll.size());

    copy(coll.begin(), coll.end(), back_inserter(coll));
    PRINT_ELEMENTS(coll);

    //������ʹ��vector�����Լ���insert����
    //��������Ǹ�ָ�������ĳ��Ԫ�صĵ�����ʱ��ҲҪע���������������ܻ�ʧЧ��
}
#endif


//front_insert_iterator��front_inserter()��Ӧ��
//ֻ������deque��list��forward list
#if 0
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    list<int> coll;

    // create front inserter for coll
    // - inconvenient way
    front_insert_iterator<list<int> > iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    PRINT_ELEMENTS(coll);

    // create front inserter and insert elements
    // - convenient way
    front_inserter(coll) = 44;
    front_inserter(coll) = 55;

    PRINT_ELEMENTS(coll);

    // use front inserter to insert all elements again
    copy(coll.begin(), coll.end(),    // source
        front_inserter(coll));       // destination

    PRINT_ELEMENTS(coll);
}
#endif


//insert_iterator��inserter()Ӧ��
//general inserter �������б�׼���������á�(ֻ�� array �� forward list ����),
// ��Ϊ��Щ�������ṩ��insert()��Ա����(��8.7.1�ڵ�413ҳ)��
// Ȼ���� associative �� unordered �������ԣ�����λ��ֻ�Ǹ���ʾ��
// ��Ϊ��������������Ԫ�ص�����λ������value������
#if 0
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    set<int> coll;

    // create insert iterator for coll
    // - inconvenient way
    insert_iterator<set<int> > iter(coll, coll.begin());

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    PRINT_ELEMENTS(coll, "set:  ");

    // create inserter and insert elements
    // - convenient way
    inserter(coll, coll.end()) = 44;
    inserter(coll, coll.end()) = 55;

    PRINT_ELEMENTS(coll, "set:  ");

    // use inserter to insert all elements into a list
    list<int> coll2;
    copy(coll.begin(), coll.end(),           // source
        inserter(coll2, coll2.begin()));     // destination

    PRINT_ELEMENTS(coll2, "list: ");

    // use inserter to reinsert all elements into the list before the second element
#if 0
    copy(coll.begin(), coll.end(),           // source
        inserter(coll2, ++coll2.begin()));   // destination
#endif
    copy(coll.begin(), coll.end(),           // source
        inserter(coll2, next(coll2.begin())));   // destination

    PRINT_ELEMENTS(coll2, "list: ");

    auto pos = coll2.end();
    for (int i = 1; i < 9; ++i)
    {
        //����д����
        //coll2.insert(pos,i);
        //��ȷд����
        pos = coll2.insert(pos, i);
        ++pos;
    }

    //***ע***
    //���嶯����ɺ�general inserter ��øձ�������Ǹ�Ԫ�ص�λ�ã��൱��
    //pos = container.insert(pos,value);
    //++pos;
    //����ʹΪ��ȷ���õ�������λ��ʼ����Ч�����
    //û����һ��ֵ�������� deque��vector �� string�У�
    //�� general inserter������ܻ�ʧЧ����Ϊÿһ�ΰ��嶯������
    //(�����ٿ��ܻ�)ʹָ�����������е�����ʧЧ��

    PRINT_ELEMENTS(coll2, "list: ");
}
#endif


//ʹ��ostream_iterator
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    // create ostream iterator for stream cout
    // - values are separated by a newline character
    ostream_iterator<int> intWriter(cout, "\n");

    // write elements with the usual iterator interface
    *intWriter = 42;
    intWriter++;
    *intWriter = 77;
    intWriter++;
    *intWriter = -5;

    // create collection with elements from 1 to 9
    vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // write all elements without any delimiter
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout));
    cout << endl;

    // write all elements with " < " as delimiter
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " < "));
    cout << endl;
}
#endif


//ʹ��istream_iterator
#if 0
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    // create istream iterator that reads integers from cin
    istream_iterator<int> intReader(cin);

    // create end-of-stream iterator
    istream_iterator<int> intReaderEOF;

    // while able to read tokens with istream iterator
    // - write them twice
    while (intReader != intReaderEOF)
    {
        cout << "once:       " << *intReader << endl;
        cout << "once again: " << *intReader << endl;
        ++intReader;
    }

    //***ע***
    // �������ַ�a�����³�����������ڸ�ʽ����stream���ٴ��� good ״̬��
    // ���� istream������ intReader �ͺ� end - of - stream ������ intReaderEOF ��ͬ��
    // ʹ��ѭ������Ϊ false, ��������ѭ����
}
#endif


//����advance()��istream_iterator������ָ����������������
#if 0
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    istream_iterator<string> cinPos(cin);
    ostream_iterator<string> coutPos(cout, " ");

    // while input is not at the end of the file
    // - write every third string
    while (cinPos != istream_iterator<string>())
    {
        // ignore the following two strings
        advance(cinPos, 2);
        //***ע***
        //��ָ��EOF�ĺ�һ��λ�ã���������

        // read and write the third string
        if (cinPos != istream_iterator<string>())
        {
            *coutPos++ = *cinPos++;
        }
    }
    cout << endl;

    //***ע***  �����룺
/*
a
b
c
d
e
f
g
h
*/
//����������뵽dʱ���������c
//������
//while ѭ����ʼ���������С���ȡ�ˡ� a �������ԣ�ͬ��bҲ������
//��ȡ��c��ͨ������������������Ļ������������������Խ�������������
//��˲����������c���ȵ�����������ٶ�ȡһ��string��ʽ�����ݺ󣬲����c
//����ֱ�Ӽ���^Z�����c

//�����룺
/*
a b c d e f g h
*/
//�����c f
}
#endif


//�Ժ�������Ϊ����׼��
#if 0
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Person
{
private:
    string fn;    // first name
    string ln;    // last name
public:
    Person()
    {}
    Person(const string& f, const string& n)
        : fn(f), ln(n)
    {}
    string firstname() const;
    string lastname() const;
    // ...
};

inline string Person::firstname() const
{
    return fn;
}

inline string Person::lastname() const
{
    return ln;
}

ostream& operator<< (ostream& s, const Person& p)
{
    s << "[" << p.firstname() << " " << p.lastname() << "]";
    return s;
}


/* class for function predicate
 * - operator () returns whether a person is less than another person
 */
class PersonSortCriterion
{
public:
    bool operator() (const Person& p1, const Person& p2) const {
        /* a person is less than another person
         * - if the last name is less
         * - if the last name is equal and the first name is less
         */
        return p1.lastname() < p2.lastname() ||
            (p1.lastname() == p2.lastname() &&
                p1.firstname() < p2.firstname());
    }
};

int main()
{
    Person p1("nicolai", "josuttis");
    Person p2("ulli", "josuttis");
    Person p3("anica", "josuttis");
    Person p4("lucas", "josuttis");
    Person p5("lucas", "otto");
    Person p6("lucas", "arm");
    Person p7("anica", "holle");

    // declare set type with special sorting criterion
    typedef set<Person, PersonSortCriterion> PersonSet;

    // create such a collection
    PersonSet coll;
    //***���***
    //coll���캯�����Զ����� class PersonSortCriterion��һ��ʵ��(instance),
    // ����Ԫ�ض����Դ�Ϊ����׼���������

    //д������
    /*
    PersonSortCriterion PSC;
    set<Person, PersonSortCriterion> coll(PSC);
    */
    //��ϸ��//���ڹ���������ʵ��������ָ������׼��

    coll.insert(p1);
    coll.insert(p2);
    coll.insert(p3);
    coll.insert(p4);
    coll.insert(p5);
    coll.insert(p6);
    coll.insert(p7);

    // do something with the elements
    // - in this case: output them
    cout << "set:" << endl;
    PersonSet::iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos)
    {
        cout << *pos << endl;
    }
}
#endif


//��������ӵ���ڲ�״̬(Internal State)
#if 0
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

class IntSequence
{
private:
    int value;
public:
    IntSequence(int initialValue)    // constructor
        : value(initialValue)
    {}

    int operator() ()
    {               // "function call"
        return value++;
    }
};

int main()
{
    list<int> coll;

    // insert values from 1 to 9
    generate_n(back_inserter(coll),  // start
        9,                    // number of elements
        IntSequence(1));      // generates values, starting with 1

    PRINT_ELEMENTS(coll);

    // replace second to last element but one with values starting at 42
    generate(next(coll.begin()),     // start
        prev(coll.end()),       // end
        IntSequence(42));       // generates values, starting with 42

    PRINT_ELEMENTS(coll);
}
#endif


//for_each()���ž��������Դ����亯������
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function object to process the mean value
class MeanValue
{
private:
    long num;    // number of elements
    long sum;    // sum of all element values
public:
    // constructor
    MeanValue() : num(0), sum(0)
    {}

    // "function call"
    // - process one more element of the sequence
    void operator() (int elem)
    {
        ++num;          // increment count
        sum += elem;    // add value

        std::cout << "num=" << num << " sum=" << sum << std::endl;
    }

    // return mean value
    double value()
    {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
};

int main()
{
    vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // process and print mean value
    MeanValue mv = for_each(coll.begin(), coll.end(),  // range
        MeanValue());              // operation

    cout << "mean value: " << mv.value() << endl;

    //***���***
    //for_each()��ʵ�֣�
    /*
    template<class InputIt, class UnaryFunction>
    UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
    {
        for (; first != last; ++first) {
            f(*first);
        }
        return f; // C++11 ����ʽ�ƶ�
    }               // (�����е���MeanValue���Զ��ṩ�ĸ��ƹ��캯��)
    */
}
#endif


//remove_if()���Ϻ���������Ϊν�� (Predicate)����ֵ�����
#if 0
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

class Nth {    // function object that returns true for the nth call
private:
    int nth;       // call for which to return true
    int count;     // call counter
public:
    Nth(int n) : nth(n), count(0)
    {}
    bool operator() (int)
    {
        return ++count == nth;
    }
};

int main()
{
    list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    PRINT_ELEMENTS(coll, "coll:        ");

    // remove third element
    list<int>::iterator pos;
    pos = remove_if(coll.begin(), coll.end(),  // range
        Nth(3));                  // remove criterion
    coll.erase(pos, coll.end());

    PRINT_ELEMENTS(coll, "3rd removed: ");

    //���Ϊ��1 2 4 5 7 8 9 10
    //��⣺
    //remove_if()��ʵ��
    /*
    template <typename ForwIter,typename Predicate>
    ForwIter std::remove_if(ForwIter beg,ForwIter end,
    Predicate op)
    {
        beg = find_if(beg,end,op);

        if(beg == end){
        return beg;
        }
        else {
        ForwIter next = beg;
        return remove_copy_if(++next,end,beg,op);//��ߴ���ĸ����Ժ���ѭ��һ����ԭ��
        }
    }
    */
    // ʹ��find_if()����Ӧ���Ƴ��ĵ�һ��Ԫ�ء�Ȼ����
    // ������remove_copy_if()ʹ�ô���� predicate op�Ŀ���ȥ����ʣ��Ԫ�أ�
    // ��ʱԭʼ״̬�µ�Nth�ٴα�ʹ�ã����
    // ���Ƴ�ʣ��Ԫ���еĵ�3��Ԫ�أ�Ҳ��������ĵ�6��Ԫ�ء�

    //���������ʹ��remove_copy_if()
    pos = remove_copy_if(coll.begin(), coll.end(),  // range
        coll.begin(), Nth(3));                  // remove criterion
    coll.erase(pos, coll.end());

    PRINT_ELEMENTS(coll, "3rd removed: ");

    //ʹ��lambda��ֱ�ۣ�
    int cnt = 0;
    pos = remove_if(coll.begin(), coll.end(), [&cnt](int)
        {
            return ++cnt == 3;
        });
    coll.erase(pos, coll.end());

    PRINT_ELEMENTS(coll, "3rd removed: ");
}
/*
remove_copy_if��ʵ�֣�
template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt remove_copy_if
(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (!p(*first)) {
            *d_first++ = *first;
        }
    }
    return d_first;
}
*/
#endif
//����
//remove_if ���ڴ��������Ƴ�Ԫ�أ��� remove_copy_if ���ǽ�������������Ԫ��
//���Ƶ���һ�������С���Ҫע����ǣ�remove_if ��������ɾ��Ԫ�أ�
//���ǽ������Ƶ�����ĩβ����Ҫ��� erase ����������ɾ����


//bind()Ƕ�׺ϳɸ����ӵĺ�������
#if 0
#include <functional>
#include <iostream>

int main()
{
    auto plus10 = std::bind(std::plus<int>(),
        std::placeholders::_1,
        10);
    std::cout << "+10:    " << plus10(7) << std::endl;

    auto plus10times2 = std::bind(std::multiplies<int>(),
        std::bind(std::plus<int>(),
            std::placeholders::_1,
            10),
        2);
    std::cout << "+10 *2: " << plus10times2(7) << std::endl;

    auto pow3 = std::bind(std::multiplies<int>(),
        std::bind(std::multiplies<int>(),
            std::placeholders::_1,
            std::placeholders::_1),
        std::placeholders::_1);
    std::cout << "x*x*x:  " << pow3(7) << std::endl;

    auto inversDivide = std::bind(std::divides<double>(),
        std::placeholders::_2,
        std::placeholders::_1);
    std::cout << "invdiv: " << inversDivide(49, 7) << std::endl;
}
#endif
//����Lambda��ʵ�ָ����ӵļ���
#if 0
#include <iostream>

int main()
{
    auto plus10 = [](int i) {
        return i + 10;
        };
    std::cout << "+10:    " << plus10(7) << std::endl;

    auto plus10times2 = [](int i) {
        return (i + 10) << 1;
        };
    std::cout << "+10 *2: " << plus10times2(7) << std::endl;

    auto pow3 = [](int i) {
        return i * i * i;
        };
    std::cout << "x*x*x:  " << pow3(7) << std::endl;

    auto inversDivide = [](double d1, double d2) {
        return d2 / d1;
        };
    std::cout << "invdiv: " << inversDivide(49, 7) << std::endl;
}
#endif


//bind()����ȫ�ֺ���
//ʹ��search()��������һ���ַ����Ƿ�����һ���ַ������Ӵ���
//�����ҵ�һ��������
//***ע***
//search() ǿ�����ǲ��ҵ�һ��ƥ�䣬�� find_end() ǿ�����ǲ������һ��ƥ��
#if 0
#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>
#include <string>
using namespace std;
using namespace std::placeholders;

char myToupper(char c)
{
    /*
    std::locale loc;
    return std::use_facet<std::ctype<char> >(loc).toupper(c);
    */
    return toupper(c);
}

int main()
{
    string s("Internationalization");
    string sub("Nation");

    // search substring case insensitive
    string::iterator pos;
    pos = search(s.begin(), s.end(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
        bind(equal_to<char>(),       // compar. criterion
            bind(myToupper, _1),
            bind(myToupper, _2)));
    if (pos != s.end()) {
        cout << "\"" << sub << "\" is part of \"" << s << "\""
            << endl;
    }
}
#endif
//��lambda��ʵ�ֵ���ȫ�ֺ���
#if 0
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
using namespace std;

char myToupper(char c)
{
 
    return toupper(c);
}

int main()
{
    string s("Internationalization");
    string sub("Nation");

    // search substring case insensitive
    string::iterator pos;
    pos = search(s.begin(), s.end(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
        [](char c1, char c2) {      // compar. criterion
            return myToupper(c1) == myToupper(c2);
        });
    if (pos != s.end()) {
        cout << "\"" << sub << "\" is part of \"" << s << "\""
            << endl;
    }

    //find_first_of   ���ƺ���Ҳ���ԣ�
    pos = find_first_of(s.begin(), s.end(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
        [](char c1, char c2) {      // compar. criterion
            return myToupper(c1) == myToupper(c2);
        });

    if (pos != s.end()) {
        cout << "\"" << sub << "\" is part of \"" << s << "\""
            << endl;
    }
}
#endif


//search()��find_first_of()������
#if 0
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello world";
    std::string sub_str = "world";

    // ʹ�� find_first_of() 
    //Ѱ�ҵ��� str ���ַ�֮һ���׸��ַ���
    size_t pos = str.find_first_of(sub_str);
    if (pos != std::string::npos) {
        std::cout << "Substring found at position: " << pos << std::endl;
    }
    else {
        std::cout << "Substring not found" << std::endl;
    }

    //***ע***
    //û��find_last_of()��������string�и÷���
    //��Ҫʵ��Ѱ�����һ������ str ���ַ�֮һ���׸��ַ���Ԫ��λ��
    //���ڷ�string���󣬿�����STL����
    /*
    find_first_of(s.rbegin(), s.rend(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
    */
    //�������������

    // ʹ�� find()�����൱��ʹ��search() 
    //  ���ַ����в�����ȫƥ��ָ���Ӵ��ĵ�һ��λ��
    pos = str.find(sub_str);
    if (pos != std::string::npos) {
        std::cout << "Substring found at position: " << pos << std::endl;
    }
    else {
        std::cout << "Substring not found" << std::endl;
    }

    return 0;
}
#endif


//bind()���ó�Ա����
//��ֱ�ۣ����˸�ϲ����lambda
#if 0
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

class Person {
private:
    string name;
public:
    Person(const string& n) : name(n) {
    }
    void print() const {
        cout << name << endl;
    }
    void print2(const string& prefix) const {
        cout << prefix << name << endl;
    }
    //...
};

int main()
{
    vector<Person> coll
        = { Person("Tick"), Person("Trick"), Person("Track") };

    // call member function print() for each person
    for_each(coll.begin(), coll.end(),
        bind(&Person::print, _1));
    cout << endl;

    // call member function print2() with additional argument for each person
    for_each(coll.begin(), coll.end(),
        bind(&Person::print2, _1, "Person: "));
    cout << endl;

    // call print2() for temporary Person
    bind(&Person::print2, _1, "This is: ")(Person("nico"));
}
#endif
//��lambdaʵ�ֵ��ó�Ա����
#if 0
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
public:
    Person(const string& n) : name(n) {
    }
    void print() const {
        cout << name << endl;
    }
    void print2(const string& prefix) const {
        cout << prefix << name << endl;
    }
    //...
};

int main()
{
    vector<Person> coll
        = { Person("Tick"), Person("Trick"), Person("Track") };

    // call member function print() for each person
    for_each(coll.begin(), coll.end(),
        [](const Person& p) {
            p.print();
        });
    cout << endl;

    // call member function print2() with additional argument for each person
    for_each(coll.begin(), coll.end(),
        [](const Person& p) {
            p.print2("Person: ");
        });
}
#endif


//function<>
#if 0
#include <iostream>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;

bool check(int elem);

int main()
{
    list<int> link_list{1,2,3,4,5,6};

    //auto pos=find_if(link_list.begin(),link_list.end(),check);
    auto pos=find_if(link_list.begin(),link_list.end(),
        function<bool (int)>(check));
    //���Բ�ʹ��function<>
    //����Ҫ�洢��ͬ���͵Ŀɵ��ö���
    // ��������Ϊ�������ݸ�������ͨ�����ݿɵ��ö���Ϊ
    // �û��ṩ�Զ�����Ϊ�������ʱ�� std::function ��ʹ�ñ�ø������

    cout << *pos << endl;

    return 0;
}
bool check(int elem)
{
    if (elem == 3)
        return true;
    else
        return false;
}
#endif


//search_n()
//�ڷ�Χ [first, last) ������ count ����ͬԪ�ص����У�
//ÿ�������ڸ�����ֵ value ���� �����Ԫν��
#if 0
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
    std::cout << optstr;

    for (const auto& elem : coll)
    {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    deque<int> coll;

    coll = { 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
    PRINT_ELEMENTS(coll);

    // find three consecutive elements with value 7
    deque<int>::iterator pos;
    pos = search_n(coll.begin(), coll.end(),    // range
        3,                           // count
        7);                          // value

    // print result
    if (pos != coll.end()) 
    {
        cout << "three consecutive elements with value 7 "
            << "start with Num." << distance(coll.begin(), pos) + 1
            << ". element" << endl;
    }
    else 
    {
        cout << "no four consecutive elements with value 7 found"
            << endl;
    }

    // find four consecutive odd elements
    pos = search_n(coll.begin(), coll.end(),    // range
        4,                           // count
        0,                           // value
        [](int elem, int value) // criterion   ***ע***
        {     
            return elem % 2 == 1;
        });
    //***ע***
    // ����д�ɶ�Ԫν��
    //����д��
    /*
    pos = search_n(coll.begin(), coll.end(),    // range
        4,                           // count
        0,                           // value
        [](int elem) // criterion
        {
            return elem % 2 == 1;
        });
        */
    
    //��Ϊ������д����
    //�ҳ��ĸ�ֵ����3������Ԫ��
#if 0
    pos = search_n(coll.begin(), coll.end(), // range
        4, // count
        3, // value
        greater<int>()); // criterion   ��Ԫν��
#endif

    // print result
    if (pos != coll.end())
    {
        cout << "first four consecutive odd elements are: ";
        for (int i = 0; i < 4; ++i, ++pos)
        {
            cout << *pos << ' ';
        }
    }
    else 
    {
        cout << "no four consecutive elements with value > 3 found";
    }
    cout << endl;
}
#endif


//search()�Ը����ӵ�׼�����ĳ��������
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

// checks whether an element is even or odd
bool checkEven(int elem, bool even)
{
    if (even) {
        return elem % 2 == 0;
    }
    else {
        return elem % 2 == 1;
    }
}

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // arguments for checkEven()
    // - check for: "even odd even"
    bool checkEvenArgs[3] = { true, false, true };

    // search first subrange in coll
    vector<int>::iterator pos;
    pos = search(coll.begin(), coll.end(),       // range
        checkEvenArgs, checkEvenArgs + 3, // subrange values
        checkEven);                     // subrange criterion

    // loop while subrange found
    while (pos != coll.end()) 
    {
        // print position of first element
        cout << "subrange found starting with element "
            << distance(coll.begin(), pos) + 1
            << endl;

        // search next subrange in coll
        pos = search(++pos, coll.end(),              // range
            checkEvenArgs, checkEvenArgs + 3, // subr. values
            checkEven);                     // subr. criterion
    }
}
#endif


//�������һ�������䣨search()����ǵ�һ�������䣩��find_end() 
#if 0
#include <iostream>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    deque<int> coll;
    list<int> subcoll;

    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(coll, 1, 7);

    INSERT_ELEMENTS(subcoll, 3, 6);

    PRINT_ELEMENTS(coll, "coll:    ");
    PRINT_ELEMENTS(subcoll, "subcoll: ");

    // search last occurrence of subcoll in coll
    deque<int>::iterator pos;
    pos = find_end(coll.begin(), coll.end(),         // range
        subcoll.begin(), subcoll.end());  // subrange

    // loop while subcoll found as subrange of coll
    deque<int>::iterator end(coll.end());
    while (pos != end) {
        // print position of first element
        cout << "subcoll found starting with element "
            << distance(coll.begin(), pos) + 1
            << endl;

        //�ҵ����ڶ������ϵ����ַ���λ��
        // search next occurrence of subcoll
        end = pos;
        pos = find_end(coll.begin(), end,               // range
            subcoll.begin(), subcoll.end()); // subrange
    }
}
#endif


//˳������ν����£��������Ԫ���Ƿ���ȣ�is_permutation() 
#if 0
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

using namespace std;

bool bothEvenOrOdd(int elem1, int elem2)
{
    return elem1 % 2 == elem2 % 2;
}

int main()
{
    vector<int> coll1;
    list<int> coll2;
    deque<int> coll3;

    coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    coll2 = { 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    coll3 = { 11, 12, 13, 19, 18, 17, 16, 15, 14, 11 };

    PRINT_ELEMENTS(coll1, "coll1: ");
    PRINT_ELEMENTS(coll2, "coll2: ");
    PRINT_ELEMENTS(coll3, "coll3: ");

    // check whether both collections have equal elements in any order
    if (is_permutation(coll1.cbegin(), coll1.cend(), // first range
        coll2.cbegin())) {            // second range
        cout << "coll1 and coll2 have equal elements" << endl;
    }
    else {
        cout << "coll1 and coll2 don't have equal elements" << endl;
    }

    // check for corresponding number of even and odd elements
    if (is_permutation(coll1.cbegin(), coll1.cend(), // first range
        coll3.cbegin(),               // second range
        bothEvenOrOdd)) {             // comparison criterion
        cout << "numbers of even and odd elements match" << endl;
    }
    else {
        cout << "numbers of even and odd elements don't match" << endl;
    }
}
#endif


//��������㷨��all_of()��any_of()��none_of()
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    vector<int> coll;
    vector<int>::iterator pos;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // define an object for the predicate (using a lambda)
    auto isEven = [](int elem)
        {
        return elem % 2 == 0;
        };

    // print whether all, any, or none of the elements are/is even
    cout << boolalpha << "all even?:  "
        << all_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "any even?:  "
        << any_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "none even?: "
        << none_of(coll.cbegin(), coll.cend(), isEven) << endl;
}
#endif


//ʹ��copy()��Ϊ��׼�����豸�ͱ�׼����豸֮�������ɸ�����
//�����ȡ string, ����һ��һ���ķ�ʽ��ӡ����
#if 0
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

int main()
{
    copy(istream_iterator<string>(cin),         // beginning of source
        istream_iterator<string>(),            // end of source
        ostream_iterator<string>(cout, "\n"));  // destination
}
#endif


//unique_ptr�ĸ��ƹ��캯������ֵ��������غ�����ʵ����Ҫʹ��move()
// move() �������ƶ������ϸ��
#if 0
#include <iostream>
#include <vector>
#include <list>

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    vector<string> coll1 = { "Hello", "this", "is", "an", "example" };
    list<string> coll2;

    // copy elements of coll1 into coll2
    // - use back inserter to insert instead of overwrite
    // - use copy() because the elements in coll1 are used again
    copy(coll1.cbegin(), coll1.cend(),         // source range
        back_inserter(coll2));                // destination range

    // print elements of coll2
    // - copy elements to cout using an ostream iterator
    // - use move() because these elements in coll2 are not used again
    //ʹ��move()����Ϊcoll2�е���ЩԪ�ز����ٴ�ʹ��
    move(coll2.cbegin(), coll2.cend(),         // source range
        ostream_iterator<string>(cout, " "));  // destination range
    cout << endl;
    //***ע***
    //coll2��Ԫ�������ǳ��α������״̬�ͱ�á���ȷ������
    // ��Ϊ�����õ���move()��
    //Ȼ��������ζ��coll2���������ٳ������Ժ�Ĵ����У�
    //coll2�Ĵ�С��Ȼ��5, �������ǿ����ٴε���move()����(overwrite)��ЩԪ�ء�

    //��֤�����
    copy(coll2.cbegin(), coll2.cend(),        
        ostream_iterator<string>(cout, " "));
    cout << endl;
    //����������������������
    //move() �������ǻ��ƶ�Ԫ�ء�
    // ��ֻ�Ǹ��߱���������������ܵĻ�������ʹ���ƶ�������������
    // ������������£�ostream_iterator ��Ԫ�ؽ��������
    // ��û���������ƶ�Ԫ�ء�
    //��ˣ���Ȼʹ���� move()����Ԫ����Ȼ������ coll2 �У�
    // ���Եڶ��� copy() ��������� coll2 �е�Ԫ�ء�

    // copy elements of coll1 into coll2 in reverse order
    // - now overwriting (coll2.size() still fits)  ��Ҫ��֤����������������㹻
    // - use move() because the elements in coll1 are not used again
    move(coll1.crbegin(), coll1.crend(),       // source range
        coll2.begin());                       // destination range

    // print elements of coll2 again
    // - use move() because the elements in coll2 are not used again
    move(coll2.cbegin(), coll2.cend(),         // source range
        ostream_iterator<string>(cout, " "));  // destination range
    cout << endl;
}
#endif


//����ĳ���������Ԫ�� swap_ranges
//(���Ҫ����ͬ���͵����������ڵ�����Ԫ�ض�������Ӧʹ��swap()��Ա����)
#if 0
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr<<endl;
    for (auto elem : coll) 
    {
        std::cout <<setw(5)<<right<< elem;
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> coll1;
    deque<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 9);
    INSERT_ELEMENTS(coll2, 11, 23);

    PRINT_ELEMENTS(coll1, "coll1: ");
    PRINT_ELEMENTS(coll2, "coll2: ");

    // swap elements of coll1 with corresponding elements of coll2
    deque<int>::iterator pos;
    pos = swap_ranges(coll1.begin(), coll1.end(),  // first range
        coll2.begin());              // second range

    //***ע***
    //��coll1��Ԫ�غ�coll2�Ķ�ӦԪ�ؽ����� 
    // Ԫ�ظ���Ϊdistance(coll1.begin(), coll1.end())
    // coll2 ֮�ڵ�����Ԫ�ز��䶯�� 
    // swap_ranges()�㷨���ص�һ��δ���Ķ���Ԫ�ء�

    PRINT_ELEMENTS(coll1, "\ncoll1: ");
    PRINT_ELEMENTS(coll2, "coll2: ");
    if (pos != coll2.end()) {
        cout << "first element not modified: "
            << *pos << endl;
    }

    // mirror first three with last three elements in coll2
    swap_ranges(coll2.begin(), coll2.begin() + 3,    // first range
        coll2.rbegin());                   // second range

    PRINT_ELEMENTS(coll2, "\ncoll2: ");
}
#endif


//fill()��generate()������
//std::fill(myVector.begin(), myVector.end(), 5);

//ʹ�� lambda ������Ϊ�������������������������ÿ��Ԫ��
//int value = 0;
//std::generate(myVector.begin(), myVector.end(), [&value]() { return value++; });

//fill() ���ڽ���Χ�ڵ�Ԫ������Ϊ����ֵ��
//�� generate() ������ʹ����������������䷶Χ�ڵ�Ԫ��


//��תԪ��rotate()
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << setw(5) << right << elem;
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:      ");

    // rotate one element to the left
    rotate(coll.begin(),      // beginning of range
        coll.begin() + 1,  // new first element
        coll.end());       // end of range
    PRINT_ELEMENTS(coll, "one left:  ");

    // rotate two elements to the right
    rotate(coll.begin(),      // beginning of range
        coll.end() - 2,    // new first element
        coll.end());       // end of range
    PRINT_ELEMENTS(coll, "two right: ");

    // rotate so that element with value 4 is the beginning
    rotate(coll.begin(),                     // beginning of range
        find(coll.begin(), coll.end(), 4),  // new first element
        coll.end());                      // end of range
    PRINT_ELEMENTS(coll, "4 first:   ");
}
#endif


//��Ԫ������ϴ�� random_shuffle()
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << setw(5) << right << elem;
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:     ");

    // shuffle all elements randomly
    random_shuffle(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll, "shuffled: ");

    // sort them again
    sort(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "sorted:   ");

    // shuffle elements with default engine
    default_random_engine dre;
    shuffle(coll.begin(), coll.end(),  // range
        dre);                      // random-number generator

    PRINT_ELEMENTS(coll, "shuffled: ");
}
#endif


//��Ԫ����ǰ�� partition()��stable_partition()
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << setw(5) << right << elem;
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> coll1;
    vector<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 9);
    INSERT_ELEMENTS(coll2, 1, 9);
    PRINT_ELEMENTS(coll1, "coll1: ");
    PRINT_ELEMENTS(coll2, "coll2: ");
    cout << endl;

    // move all even elements to the front
    vector<int>::iterator pos1, pos2;
    pos1 = partition(coll1.begin(), coll1.end(),         // range
        [](int elem) {                        // criterion
            return elem % 2 == 0;
        });
    pos2 = stable_partition(coll2.begin(), coll2.end(),  // range
        [](int elem) {                // criterion
            return elem % 2 == 0;
        });

    //partition()��stable_partition()����Ԫ�ط�Ϊ����
    //����ֵָ��ڶ���Ԫ����Ԫ�صĵ�������

    //stable_partition()����������Ԫ�غ�ż��Ԫ�ص���Դ���
    // ��һ���partition()��ͬ��

    // print collections and first odd element
    PRINT_ELEMENTS(coll1, "coll1: ");
    cout << "first odd element: " << *pos1 << endl;
    PRINT_ELEMENTS(coll2, "coll2: ");
    cout << "first odd element: " << *pos2 << endl;
}
#endif


//����ν�ʺ������������������� partition_copy()
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << setw(5) << right << elem;
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> coll = { 1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5 };
    PRINT_ELEMENTS(coll, "coll: ");

    // destination collections:
    vector<int> evenColl;
    vector<int> oddColl;

    // copy all elements partitioned accordingly into even and odd elements
    partition_copy(coll.cbegin(), coll.cend(), // source range
        back_inserter(evenColl),   // destination for even elements
        back_inserter(oddColl),    // destination for odd elements
        [](int elem) {              // predicate: check for even elements
            return elem % 2 == 0;
        });

    PRINT_ELEMENTS(evenColl, "evenColl: ");
    PRINT_ELEMENTS(oddColl, "oddColl:  ");
}
#endif


//sort()��stable_sort()������
#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << setw(5) << right << elem;
    }
    std::cout << std::endl;
}

using namespace std;

bool lessLength(const string& s1, const string& s2)
{
    return s1.length() < s2.length();
}

int main()
{
    // fill two collections with the same elements
    vector<string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
                             "7xx", "8xxx", "9xx", "10xxx", "11", "12",
                             "13", "14xx", "15", "16", "17" };
    vector<string> coll2(coll1);

    PRINT_ELEMENTS(coll1, "on entry:\n ");

    // sort (according to the length of the strings)
    sort(coll1.begin(), coll1.end(),           // range
        lessLength);                          // criterion

    stable_sort(coll2.begin(), coll2.end(),    // range
        lessLength);                   // criterion

    //stable_sort()������󱣳���Ԫ�ص����λ��

    PRINT_ELEMENTS(coll1, "\nwith sort():\n ");
    PRINT_ELEMENTS(coll2, "\nwith stable_sort():\n ");
}
#endif


//��������partial_sort()��partial_sort_copy()
#if 0
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << right << elem;
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    deque<int> coll;

    INSERT_ELEMENTS(coll, 3, 7);
    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, 1, 5);
    PRINT_ELEMENTS(coll);

    // sort until the first five elements are sorted
    partial_sort(coll.begin(),      // beginning of the range
        coll.begin() + 5,    // end of sorted range
        coll.end());       // end of full range
    PRINT_ELEMENTS(coll);

    //***ע***
    //partial_sort(coll.begin(), coll.begin() + 5, coll.end())
    //������
    //sort(coll.begin(), coll.begin() + 5)
    //��Ӧ���Ϊ��
    //ȫ���ź��������ȡ��ǰ5��Ԫ�أ�����Ԫ������һ����ʽ���У�
    // ��һ������

    // sort inversely until the first five elements are sorted
    partial_sort(coll.begin(),      // beginning of the range
        coll.begin() + 5,    // end of sorted range
        coll.end(),        // end of full range
        greater<int>());   // sorting criterion
    PRINT_ELEMENTS(coll);

    // sort all elements
    partial_sort(coll.begin(),      // beginning of the range
        coll.end(),        // end of sorted range
        coll.end());       // end of full range
    PRINT_ELEMENTS(coll);
}
#endif


//ֻ��Ҫn��������СԪ�أ�����Ҫ�����Ǳ��봦������״̬(sorted), 
//ʹ��nth_element()
#if 0
#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << right << elem;
    }
    std::cout << std::endl;
}

int main()
{
    deque<int> coll;

    INSERT_ELEMENTS(coll, 3, 7);
    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, 1, 5);
    PRINT_ELEMENTS(coll);

    // extract the four lowest elements
    nth_element(coll.begin(),     // beginning of range
        coll.begin() + 3,   // element that should be sorted correctly
        coll.end());      // end of range

    //***���***
    //�ڶ���ʵ��nth ��ָ���Ԫ�ر�����Ϊ���� [first, last) ������
    //���λ�û���ֵ�Ԫ�ء�
    //����µ� nth Ԫ��ǰ������Ԫ��С�ڻ�����µ� nth Ԫ�غ������Ԫ�ء�

    // ʹ��4��λ���ϵ�Ԫ�ؾ�λ��Ҳ����˵������λ��4֮ǰ��Ԫ��
    // ��С�ڵ�������������λ��n֮���Ԫ�ض����ڵ�������
    // �������͵õ��ˡ�����nλ���ϵ�Ԫ�ء��ָ�������������У�
    // ��һ�����е�Ԫ��ͳͳС�ڵڶ������е�Ԫ�ء�

    // print them
    cout << "the four lowest elements are:  ";
    copy(coll.cbegin(), coll.cbegin() + 4,
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // extract the four highest elements
    nth_element(coll.begin(),     // beginning of range
        coll.end() - 4,     // element that should be sorted correctly
        coll.end());      // end of range

    // print them
    cout << "the four highest elements are: ";
    copy(coll.cend() - 4, coll.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // extract the four highest elements (second version)
    nth_element(coll.begin(),     // beginning of range
        coll.begin() + 3,   // element that should be sorted correctly
        coll.end(),       // end of range
        greater<int>());  // sorting criterion

    // print them
    cout << "the four highest elements are: ";
    copy(coll.cbegin(), coll.cbegin() + 4,
        ostream_iterator<int>(cout, " "));
    cout << endl;
}
#endif


//ʹ��heap����㷨
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
    const std::string& optcstr = "")
{
    std::cout << optcstr << endl;
    for (auto elem : coll)
    {
        std::cout << right << elem<<' ';
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 3, 7);
    INSERT_ELEMENTS(coll, 5, 9);
    INSERT_ELEMENTS(coll, 1, 4);

    PRINT_ELEMENTS(coll, "on entry:           ");

    // convert collection into a heap
    make_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll, "after make_heap():  ");

    // pop next element out of the heap
    pop_heap(coll.begin(), coll.end());
    coll.pop_back();

    PRINT_ELEMENTS(coll, "after pop_heap():   ");

    // push new element into the heap
    coll.push_back(17);
    push_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll, "after push_heap():  ");

    // convert heap into a sorted collection
    // - NOTE: after the call it is no longer a heap
    sort_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll, "after sort_heap():  ");
}
#endif


//����������������㷨
//���ĳ��Ԫ���Ƿ���ڣ�binary_search()
//***ע***
//binary_search()��ʵ����Ҫ����std::lower_bound()
//��std::lower_bound()��ʵ����ʹ�ö��������㷨�����Ҹ���ֵ
//�������������еĲ���λ�á�
//��˿��Խ�binary_search()��Ϊ��ͨ���������㷨�Ĵ���
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll);

    //***ע***
    //ʹ��binary_search()ǰ��������Ѿ�����

    // check existence of element with value 5
    if (binary_search(coll.cbegin(), coll.cend(), 5))
    {
        cout << "5 is present" << endl;
    }
    else
    {
        cout << "5 is not present" << endl;
    }

    // check existence of element with value 42
    if (binary_search(coll.cbegin(), coll.cend(), 42)) 
    {
        cout << "42 is present" << endl;
    }
    else 
    {
        cout << "42 is not present" << endl;
    }
}
#endif


//�����������
//�������Ԫ���Ƿ���ڣ�����2�Ƿ�Ϊ����1���Ӽ�����includes()
//��������Χ [first2, last2) ��������Χ [first1, last1) ���������򷵻� true
//***ע***
//Ҫ��search()����
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    list<int> coll;
    vector<int> search;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:   ");

    search.push_back(3);
    search.push_back(4);
    search.push_back(7);
    PRINT_ELEMENTS(search, "search: ");

    // check whether all elements in search are also in coll
    if (includes(coll.cbegin(), coll.cend(),  //����1
        search.cbegin(), search.cend()))      //����2
    {
        cout << "all elements of search are also in coll"
            << endl;
    }
    else
    {
        cout << "not all elements of search are also in coll"
            << endl;
    }

    auto pos = std::search(coll.cbegin(), coll.cend(), search.cbegin(), search.cend());

    if (pos != coll.end())
        cout << "all elements of search are also in coll"
        << endl;
    else
        cout << "not all elements of search are also in coll"
        << endl;
}
#endif
//***С��***
//���������䣬����2������Ԫ���γɵ������Ƿ�������1�ж���
// (�����в������(����))��includes()
//����2������Ԫ���γɵ������Ƿ�������1����
// (��������Ҫ���(����))��search()
//����2��ĳ��Ԫ���Ƿ�������1���У�find_first_of()


//�����������
//���ҵ�һ�������һ�����ܵ�λ�ã�lower_bound()��upper_bound()
//�������insert()����ʹ�ã�ʵ����ָ��λ�ò���Ԫ�ض����ƻ��������״̬
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    INSERT_ELEMENTS(coll, 1, 9);

    coll.sort();

    PRINT_ELEMENTS(coll);

    // print first and last position 5 could get inserted
    auto pos1 = lower_bound(coll.cbegin(), coll.cend(),
        5);
    auto pos2 = upper_bound(coll.cbegin(), coll.cend(),
        5);

    cout << "5 could get position "
        << distance(coll.cbegin(), pos1) + 1
        << " up to "
        << distance(coll.cbegin(), pos2) + 1
        << " without breaking the sorting" << endl;

    // insert 3 at the first possible position without breaking the sorting
    coll.insert(lower_bound(coll.begin(), coll.end(),
        3),
        3);

    // insert 7 at the last possible position without breaking the sorting
    coll.insert(upper_bound(coll.begin(), coll.end(),
        7),
        7);

    PRINT_ELEMENTS(coll);
}
#endif
//һ���Բ����һ�������һ�����ܵ�λ�ã�equal_range()
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    INSERT_ELEMENTS(coll, 1, 9);
    coll.sort();
    PRINT_ELEMENTS(coll);

    // print first and last position 5 could get inserted
    pair<list<int>::const_iterator, list<int>::const_iterator> range;
    range = equal_range(coll.cbegin(), coll.cend(),
        5);

    cout << "5 could get position "
        << distance(coll.cbegin(), range.first) + 1
        << " up to "
        << distance(coll.cbegin(), range.second) + 1
        << " without breaking the sorting" << endl;
}
#endif


//�����������
//�ϲ��㷨��merge()��set_union()��set_intersection()��
// set_difference()��set_symmetric_difference()
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    vector<int> c1 = { 1, 2, 2, 4, 6, 7, 7, 9 };
    deque<int>  c2 = { 2, 2, 2, 3, 6, 6, 8, 9 };

    // print source ranges
    cout << "c1:                         ";
    copy(c1.cbegin(), c1.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "c2:                         ";
    copy(c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << '\n' << endl;

    // sum the ranges by using merge()
    cout << "merge():                    ";
    merge(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    //�󲢼�
    // unite the ranges by using set_union()
    cout << "set_union():                ";
    set_union(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    //�󽻼�
    // intersect the ranges by using set_intersection()
    cout << "set_intersection():         ";
    set_intersection(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    //��
    // determine elements of first range without elements of second range
    // by using set_difference()
    cout << "set_difference():           ";
    set_difference(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    //����ڵ�һ���б��ж����ڵڶ����б��д��ڵ�Ԫ��

    //������S1,S2�ĶԳƲ
    // determine difference the ranges with set_symmetric_difference()
    cout << "set_symmetric_difference(): ";
    set_symmetric_difference(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    //�����
    // 1 2 3 4 6 7 7 8

    //�ԳƲָ����ֻ����S1��S2,����ͬʱ����S1��S2��

    //***ע***
    //����� 2 ���ֵ�ԭ������Ǽ��� c1 ��������ֵΪ 2 ��Ԫ�أ�
    // ������ c2 ��ֻ��һ��ֵΪ 2 ��Ԫ��
    //�����Ļ� 2 Ҳ�ᱻ��Ϊ���ڶԳƲ
    //ͬ��ԳƲ��Ҳ��6�������
}
#endif


//������������䣬�͵�һ��Ϊ�����кϲ���inplace_merge()
#if 0
#include "algostuff.hpp"
using namespace std;

int main()
{
    list<int> coll;

    // insert two sorted sequences
    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(coll, 1, 8);
    PRINT_ELEMENTS(coll);

    // find beginning of second part (element after 7)
    list<int>::iterator pos;
    pos = find(coll.begin(), coll.end(),    // range
        7);                          // value

    ++pos;

    // merge into one sorted range
    inplace_merge(coll.begin(), pos, coll.end());
    //������Դ���� [beg1,end1beg2) ��[end1beg2,end2)��Ԫ�غϲ���
    // ʹ����    [begl,end2)    ��Ϊ����֮�ܺ�(���γ�������״̬)��

    PRINT_ELEMENTS(coll);
}
#endif


//һ���û��Զ����Stack��
#if 0
#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <exception>

template <typename T>
class Stack
{
protected:
    std::deque<T> c;        // container for the elements

public:
    //***ע***
    // //����Ƕ����
    // exception class for pop() and top() with empty stack
    class ReadEmptyStack : public std::exception
    {
    public:
        //***ע***
        //���д throw() ��ʾ�ú��������׳��κ��쳣
        virtual const char* what() const throw() 
        {
            return "read empty stack";
        }
    };

    // number of elements
    typename std::deque<T>::size_type size() const
    {
        return c.size();
    }

    // is stack empty?
    bool empty() const 
    {
        return c.empty();
    }

    // push element into the stack
    void push(const T& elem) 
    {
        c.push_back(elem);
    }

    // pop element out of the stack and return its value
    T pop() 
    {
        if (c.empty()) 
        {
            throw ReadEmptyStack();
        }

        T elem(c.back());

        c.pop_back();

        return elem;
    }

    // return value of next element
    T& top()
    {
        if (c.empty()) 
        {
            throw ReadEmptyStack();
        }
        return c.back();
    }
};

#endif /* STACK_HPP */
#endif


//һ���û��Զ����Queue��
#if 0
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>
#include <exception>

template <typename T>
class Queue 
{
protected:
    std::deque<T> c;        // container for the elements

public:
    // exception class for pop() and front() with empty queue
    class ReadEmptyQueue : public std::exception
    {
    public:
        virtual const char* what() const throw() 
        {
            return "read empty queue";
        }
    };

    // number of elements
    typename std::deque<T>::size_type size() const
    {
        return c.size();
    }

    // is queue empty?
    bool empty() const 
    {
        return c.empty();
    }

    // insert element into the queue
    void push(const T& elem) 
    {
        c.push_back(elem);
    }

    // remove next element from the queue and return its value
    T pop() 
    {
        if (c.empty())
        {
            throw ReadEmptyQueue();
        }

        T elem(c.front());

        c.pop_front();

        return elem;
    }

    // return value of next element
    T& front() 
    {
        if (c.empty())
        {
            throw ReadEmptyQueue();
        }

        return c.front();
    }
};
#endif /* QUEUE_HPP */
#endif


//��bitset����һ���־
#if 0
#include <bitset>
#include <iostream>
using namespace std;

int main()
{
    // enumeration type for the bits
    // - each bit represents a color
    enum Color {
        red, yellow, green, blue, white, black, //...,
        numColors
    };

    // create bitset for all bits/colors
    bitset<numColors> usedColors;//����bitset�����Ĭ��ÿһλ��Ϊ0

    // set bits for two colors
    usedColors.set(red);
    usedColors.set(blue);
    //***���***
    //bitset���еķ���������bitset& set( std::size_t pos, bool value = true );
    // �β�pos�൱��index
    //usedColors.set(red);��ʾbitset�����ĵ�1��Ԫ��ֵ��Ϊ1

    // print some bitset data
    cout << "bitfield of used colors:   " << usedColors << endl;
    cout << "number   of used colors:   " << usedColors.count() << endl;
    cout << "bitfield of unused colors: " << ~usedColors << endl;//��ת����λ

    //to_string()������
    std::cout << usedColors.to_string() << '\n'
        << usedColors.to_string('*') << '\n'
        << usedColors.to_string('O', 'X') << '\n';

    //***ע***
    //bitset��bitset<N>::all, std::bitset<N>::any, std::bitset<N>::none ��Щ����
    //ʱ�临�Ӷȶ���O(N)
    // if any color is used
    if (usedColors.any()) {
        // loop over all colors
        for (int c = 0; c < numColors; ++c) {
            // if the actual color is used
            if (usedColors[(Color)c]) {
                //...
            }
        }
    }
}
#endif


//bitset����ɫ���ܣ���bitset����������
#if 0
#include <bitset>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    // print some numbers in binary representation
    cout << "267 as binary short:     "
        << bitset<numeric_limits<unsigned short>::digits>(267)
        << endl;

    cout << "267 as binary long:      "
        << bitset<numeric_limits<unsigned long>::digits>(267)
        << endl;

    cout << "10,000,000 with 24 bits: "
        << bitset<24>(1e7) << endl;

    //����ֵ���ͳ�ʼ��bitset�����
    //*** (bitset�����洢������ֵ���͵Ķ����Ʊ�ʾ)***
    //ʹ��to_string()������bitset��������Ϊstring�����
    // write binary representation into string
    string s = bitset<42>(12345678).to_string();
    cout << "12,345,678 with 42 bits: " << s << endl;

    //��C-string���ͳ�ʼ��bitset�����
    //*** (bitset�����洢����C-string����ָʾ�Ķ���������) ***
    //ʹ��to_ullong()������bitset��������Ϊunsigned long long��������
    // transform binary representation into integral number
    cout << "\"1000101011\" as number:  "
        << bitset<100>("1000101011").to_ullong() << endl;
}
#endif


//string����������÷�
//������ʱ�ļ���
#if 0
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string filename, basename, extname, tmpname;

    const string suffix("tmp");

    // for each command-line argument (which is an ordinary C-string)
    for (int i = 1; i < argc; ++i)
    {
        // process argument as filename
        filename = argv[i];

        // search period in filename
        string::size_type idx = filename.find('.');
        //***ע***
        //�˴�����ʹ��string::size_type����
        //������ int�� unsigned ��Ϊ����ֵ���ͣ����򷵻�ֵ��string::npos֮���
        //�ȽϿ����޷���ȷִ�С�������Ϊnpos�����Ϊsize_type���͵� -1
        //���ҵ���size_type(��string�ķ����������)�����Ǹ�����������������
        //����-1 ��ת��Ϊ���������������ͣ�npos Ҳ�ͳ��˸����͵������������ֵ��
        //Ȼ��ʵ��ֵȡ��������size_type����ʵ���塣
        // ���ҵ��Ƕ��ڲ�ͬ�Ĳ���ϵͳ����Щ���ֵ���ͺ�ֵ���ܶ�����ͬ��
        // ��ʵ��(unsigned long) - 1��(unsigned short) - 1 ��ͬ��

        //��ˣ����ڣ�
        //idx == std::string::npos
        //��� idx��ֵΪ - 1, ���� idx���ַ��� string::npos���Ͳ�ͬ��
        // �ȽϽ�����ܻ��� false

        if (idx == string::npos) 
        {
            // filename does not contain any period
            tmpname = filename + '.' + suffix;
        }
        else 
        {
            // split filename into base name and extension
            // - base name contains all characters before the period
            // - extension contains all characters after the period
            basename = filename.substr(0, idx);
            extname = filename.substr(idx + 1);

            //***���***
            //find()��������Ҫ�������ַ���string������е�indexֵ

            //filename.substr(0, idx);
            //���� [0, 0+idx) 
            //filename.substr(idx + 1);
            //���� [pos, size())

            if (extname.empty()) 
            {
                // contains period but no extension: append tmp
                tmpname = filename;
                tmpname += suffix;
            }
            else if (extname == suffix) 
            {
                // replace extension tmp with xxx
                tmpname = filename;
                tmpname.replace(idx + 1, extname.size(), "xxx");
            }
            else
            {
                // replace any extension with tmp
                tmpname = filename;
                tmpname.replace(idx + 1, string::npos, suffix);
                //***ע***
                //string::npos����Ҫд����string
            }
        }

        // print filename and temporary name
        cout << filename << " => " << tmpname << endl;
    }
}
#endif


//�������ʲ������ӡ����ͬʱ�鿴//������58����ת�ַ�����
#if 0
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    //���м���ַ���������һ������� string �����ڣ�
    const string delims(" \t,.;");
    string line;

    // for every line read successfully
    while (getline(cin, line)) 
    {
        string::size_type begIdx, endIdx;

        // search beginning of the first word
        begIdx = line.find_first_not_of(delims);

        // while beginning of a word found
        while (begIdx != string::npos) 
        {
            //***ע***
            //��indexΪbegIdx��ʼ��Ѱ�ҵ���delims����һ�ַ����ַ����ڵ�λ��
            // �˷�Χ�ܰ������ַ���
            // search end of the actual word
            endIdx = line.find_first_of(delims, begIdx);

            if (endIdx == string::npos) 
            {
                // end of word is end of line
                endIdx = line.length();
            }

            // print characters in reverse order
            for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i) 
            {
                cout << line[i];
            }

            cout << ' ';

            // search beginning of the next word
            begIdx = line.find_first_not_of(delims, endIdx);
        }

        cout << endl;
    }
}
#endif


//��C-string�ַ�����ʼ��string����
//��β���������ַ���
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("abc");
    cout << str1.length()<<endl;
    
    //˵��str1һ��ʼ�ͷ����˶���Ŀռ����ڴ洢����
    cout << sizeof(str1) << endl;

    for (int i = 0; i < 4; ++i)
        if (str1[i] == '\0')
            cout << "\\0" << ' ';
        else if (isalpha(str1[i]))
            cout << str1[i] << ' ';
        else
            cout << "?" << ' ';

    cout << endl;

    //***ע***
    //��⣺
    //ֻ�е�ʵ�ε� const char*�汾�Ž��ַ�'\0'��Ϊstring�Ľ�β������ţ�
    // �������������'\0'��������Ϊ�����ַ�
    //std::string s1("nico");      // initializes s1 with:'n'  'i'  'c'  'o'
    //std::string s2("nico", 5);  //initializes s2 with:'n'  'i'  'c'  'o'  '\0'
    //std::string s3(5, '\0');       //initializes s3 with:'\0'  '\0'  '\0'  '\0'  '\0'

    //ǰ��Ĵ�����Ե������ʾ��
    //��ʹs1����4��Ԫ�أ���
    //s1��Ҫ��ʾs1[4]���ǻ᷵��һ�����ַ��ġ�(��C++11�ж�������������Ϊ)

    string str2("abc",4);
    cout << str2.length()<<endl;

    for (int i = 0; i < 5; ++i)
        if (str2[i] == '\0')
            cout << "\\0" << ' ';
        else if (isalpha(str2[i]))
            cout << str2[i] << ' ';
        else
            cout << "?" << ' ';

    //�ش�
    //��C-string�ַ�����ʼ��std::string����ʱ��������п��ַ���\0����
    // std::string�������ݴ����C-string�ַ����ĳ����Զ�ȷ��������ĳ��ȣ�
    // ������Ҫ����Ŀ��ַ�����ʾ������
    //����ʹ������string str2("abc",4);��������ʼ��string����
    //ûָ�������ݻ��ÿ��ַ����롣

    return 0;
}
#endif


//string�İ���Ԫ�ط���
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str{"bc"};

    //�����õ�д����
    //str.insert(0,'a');
    //str.insert('a');
    //str.insert("a");

    //��ȷд����
    str.insert(0,"a");

    cout << str << endl;

    return 0;
}
#endif


//��string������ط��������ַ�����ֵ��ת��
//���䣺
//��to_string()����������ֵ���ַ���ת��
#if 0
#include <string>
#include <iostream>
#include <limits>
#include <exception>

int main()
{
    try {
        // convert to numeric type
        std::cout << std::stoi("  77") << std::endl;
        std::cout << std::stod("  77.7") << std::endl;
        std::cout << std::stoi("-0x77") << std::endl;

        // use index of characters not processed
        std::size_t idx;
        std::cout << std::stoi("  42 is the truth", &idx) << std::endl;
        std::cout << " idx of first unprocessed char: " << idx << std::endl;

        // use bases 16 and 8
        std::cout << std::stoi("  42", nullptr, 16) << std::endl;
        std::cout << std::stol("789", &idx, 8) << std::endl;
        std::cout << " idx of first unprocessed char: " << idx << std::endl;

        // convert numeric value to string
        long long ll = std::numeric_limits<long long>::max();
        std::string s = std::to_string(ll);  // converts maximum long long to string
        std::cout << s << std::endl;

        // try to convert back
        std::cout << std::stoi(s) << std::endl;  // throws out_of_range
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
#endif


//unique()������Ҫ���erase()ʹ��   ��remove()ҲҪ���erase()��
#if 0
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // create constant string
    const string hello("Hello, how are you?");

    // initialize string s with all characters of string hello
    string s(hello.cbegin(), hello.cend());

    // ranged-based for loop that iterates through all the characters
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    // reverse the order of all characters inside the string
    reverse(s.begin(), s.end());
    cout << "reverse:       " << s << endl;

    // sort all characters inside the string
    sort(s.begin(), s.end());
    cout << "ordered:       " << s << endl;

    //����д����
    //unique(s.begin(), s.end());
    //cout << s << endl;

    //��ȷд����
    // remove adjacent duplicates
    // - unique() reorders and returns new end
    // - erase() shrinks accordingly
    s.erase(
        unique(s.begin(), s.end()),
        s.end());
    cout << "no duplicates: " << s << endl;
    //��⣺
    //unique()�����Է�Χ [first, last) ����̵ȼ�Ԫ����������Ԫ�����Ԫ�أ�
    //�����ط�Χ�����߼���β��β���������
    
    //unique()����ʣ��Ԫ�ص����˳���Ҳ����������������С��
    //ָ��Χ�����߼���β�������β֮��Ԫ�صĵ�������Ȼ�ɽ����ã�
    // ��Ԫ������ӵ�С�δָ��ֵ����
    // ���� unique ����ʱ����������� erase ��Ա������
    // ������δָ��ֵ����С�����������С����ƥ�����µ��߼���С��
}
#endif


//��ʹ��getline()����string��������������ݣ��Ҳ����Կհ��ַ��ķ���
#if 0
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <locale>
using namespace std;

int main()
{
    string input;

    //������ str �е� skipws ��־
    //�����и�ʽ���뺯������������ǰ���հ׷���Ĭ�����ã������������Ч����
    // don't skip leading whitespaces
    cin.unsetf(ios::skipws);

    // read all characters while compressing whitespaces
    //const locale& loc(cin.getloc());    // locale

    //ʹ��unique_copy�����ӱ�׼������cin�ж�ȡ�ַ���
    // �����临�Ƶ�����input�У�����ֻ���������Ĳ�ͬ�ַ���
    // ������ض��������У�unique_copy������������һ��ν�ʺ�����Ϊ������
    // ���ڶ����Ϊ"���ڵ��ظ��ַ�"��
    unique_copy(istream_iterator<char>(cin),  // beginning of source
        istream_iterator<char>(),     // end of source
        back_inserter(input),         // destination
        [=](char c1, char c2) {      // criterion for adj. duplicates
            //return isspace(c1, loc) && isspace(c2, loc);
            return isspace(c1) && isspace(c2);
        });

    // process input
    // - here: write it to the standard output
    cout << input;

    cout << endl;
    for (auto it = input.begin(); it != input.end(); ++it)
        if (*it == ' ')
            cout << "[space]";
        else if (*it == '\n')
			cout << "[\\n]";
		else if (*it != '\n')
			cout << *it;
}
//���ԣ�
//���룺
/*
        a          b
      c          d
^Z
*/
//�����
/*
 a b
c d

[space]a[space]b[\n]c[space]d[\n]
*/ 
//***ע***
//�ڶ��п�ʼ�Ŀհ��ַ���������
#endif


//���ļ���ȡ���ݣ���д�����ݵ��ļ�
#if 0
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("DataReceive.txt");

	if (!fin.is_open())
		cout << "Can not open DataReceive.txt !" << endl;

	string str;

	//���õ�д����
#if 0
	while (fin)
	{
		getline(fin, str);

		cout << str << endl;
	}
    //ԭ��
    //����EOFʱeof()Ϊ1��fail()ҲΪ1��fin�Ĳ���ֵ��Ϊfalse
#endif
//�����
/*
            a              b
      c               d
      c               d
*/

    //���ʵ�д����
	getline(fin, str);
	while (fin)
	{
		cout << str << endl;

		getline(fin, str);
	}
//�����
/*
            a              b
      c               d
*/

    //�����־λ
    fin.clear();
    //�ص��ļ���ͷ
    fin.seekg(0);

    ofstream fout("DataOutput.txt",ios_base::out | ios_base::app);
    if(!fout.is_open())
        cout<< "Can not open DataOutput.txt !" << endl;

    getline(fin, str);
    while (fin)
    {
        cout << str << endl;

        fout << str<<'\n';
        //fout << str.c_str()<<'\n';

        getline(fin, str);
    }

    fin.close(); // �ر��ļ���
    fout.close();

    return 0;
}
#endif


//ʹ��string stream
//��;��
//�ԡ���������ʵI/O�豸���⡱�ķ�ʽ������I/O��
// ����output�����ָ�ʽ������ string ���趨��
// Ȼ���ٽ�string������ĳ�����ͨ����
// Ҳ�������ж�ȡ input, ���� string stream ����ÿһ�С�
#if 0
#include <iostream>
#include <sstream>//ostringstream��
#include <bitset>
using namespace std;

int main()
{
    ostringstream os;

    // decimal and hexadecimal value
    os << "dec: " << 15 << hex << " hex: " << 15 << endl;
    //str()�����������������ݵ���һ��string����
    cout << os.str() << endl;

    // append floating value and bitset
    bitset<15> b(5789);
    os << "float: " << 4.67 << " bitset: " << b << endl;

    // overwrite with octal value
    //����seekp()��Ϳдλ������stream ��ʼ����
    // ��ôһ����̵� operator<< �Ͱ����д�� string ͷ����
    // ���Ǹ�����ԭ����string stream ͷ�����ݡ�δ�����ǵ��ַ���Ȼ��Ч��
    os.seekp(0);

    os << "oct: " << oct << 15;
    cout << os.str() << endl;

    //���䣺
    //Ҫɾ�� stream ���������ݣ������ú���str()��ո�����ݸ��軺������
    //strm.str("");
}
#endif


//Input string stream����Ҫ��;
//��ʽ���شӼ���string�ж�ȡ����
//Ӧ�ó�����
//�ļ���ÿ�������ȴ���string�����ٽ�string��������Ϊ����������
//�ٶԻ��������ݽ��и�ʽ���Ķ�ȡ����
#if 0
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int x;
    float f;

    string str = "1.12";

    //��string��������Ϊ����������
    istringstream is(str);

    is >> x >> f;

    cout << x << ' ' << f << endl;

    return 0;
}
#endif


//ʹ��C++�е������
#if 0
#include <random>//��һ������������������
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    //�ڶ������ṩ���������������
    // create default engine as source of randomness
    std::default_random_engine dre;

    //��������ʹ�þ��ȷֲ����õ�ָ����Χ�������
    // uniform_int_distribution�����������������͵��������
    // �����ָ������������ķ�Χ��������Χ�ڵ�����������
    // use engine to generate integral numbers between 10 and 20 (both included)
    std::uniform_int_distribution<int> di(10, 20);
    for (int i = 0; i < 20; ++i) {
        std::cout << di(dre) << " ";
    }
    std::cout << std::endl;

    //uniform_real_distribution���������ɸ��������͵��������
    // �����ָ������������ķ�Χ����ָ���ķ�Χ�����ɾ��ȷֲ��ĸ�������
    // use engine to generate floating-point numbers between 10.0 and 20.0
    // (10.0 included, 20.0 not included)
    std::uniform_real_distribution<double> dr(10, 20);
    for (int i = 0; i < 8; ++i) {
        std::cout << dr(dre) << " ";
    }
    std::cout << std::endl;

    //ʹ���������������������������Ԫ�ش���
    // use engine to shuffle elements
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //...
    std::shuffle(v.begin(), v.end(),  // range
        dre);                // source of randomness
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
#endif
//���䣺
//ʹ��C��׼���ֵ����������ɵ�����(P912)


//�������
//�߼��ӿڣ�async()��future
//�Ͳ�ӿڣ�thread��promise

//��������func1()��func2()
#if 1
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething(char c)
{
    // random-number generator (use c as seed to get different sequences)
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);

    // loop to print character after a random period of time
    for (int i = 0; i < 10; ++i) 
    {
        //��ǰ�߳���ͣʱ��
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}

int func1()
{
    return doSomething('.');
}

int func2()
{
    return doSomething('+');
}

int main()
{
    std::cout << "starting func1() in background"
        << " and func2() in foreground:" << std::endl;

    //������д����
    //int result = func1()+func2();
    //�ĳɣ�

    //��һ����
    // �첽����func1()
    // start func1() asynchronously (now or later or never):
    std::future<int> result1(std::async(func1));
    //��⣺
    //ʹ�� std::async()�������� func1()�ں�̨�����������ֵ��ĳ�� std::future����
    //async()���Խ�������õĺ������̡��첽��������һ�������߳��ڡ�
    // ��˸�����func1()�����ﱻ�����ˣ��������main()ͣ�͡�
    // ��������ԭ�򣬷��� future ���� �Ǳ�Ҫ�ģ�
    /*
        1.��������ȡ�á����� async()���Ǹ���������δ���������
            Ҳ���Ǹ�����ֵ��Ҳ���Ǹ��쳣��
            ��� future object���ܵ����������������������͵��ػ���
            ������������Ǹ����ء�����ĺ�̨����(background task),
            ��ͻ��� std::future<void>��
        2.��������ڣ�ȷ����Ŀ�꺯�����������ջᱻ���á�
            ע����ǰ��˵async()��������Ŀ�꺯����
            �������������û�������Ժ�������Ҫ��� future �������ǿ������֮
            (��������Ҫ���������н����������Ҫȷ���ú�����ִ��ʱ)��
     */

    //�ڶ�����
    //��������func2()��ǰ̨
    int result2 = func2();    // call func2() synchronously (here and now)

    //��������
    // ʹ��get()����
    // print result (wait for func1() to finish and add its result to result2
    int result = result1.get() + result2;

    // get()�����ã�������������֮һ�ᷢ����
    /*
     1.��� func1()�� async()������һ�������߳��в����ѽ�����������̻��������
     2.���func1()����������δ������get()������ͣ��(block)
        �� func1()�������ý����
     3.��� func1()��δ�������ᱻǿ��������ͬһ��ͬ�����ã�
         get()������ͣ��ֱ�����������
     ��������Ϊ����Ҫ����Ϊ��ȷ�����ڵ��̻߳����У�
     ���ǵ�async()�޷��������߳�ʱ(���ۻ����κ�����), ����������Ч������
     */

    /*
    ��ˣ�
    std::future<int> result1(std::async(func1));
    ��
    result1.get()
    �������������ĳ�ַ�ʽ�Ż�����
    (1)������ܣ��� main �̵߳���һ����䱻����ʱfunc1()���������У�
    (2)����޷��������У���ôfunc1()���� get()������ʱ
    ��ѭ�����(called sequentially)��
    �����ζ��������ζ��ܱ�֤������ get()ִ�к�һ�������
    func1()���������첽����ͬ����
    */

    //���䣺
    /*
    ���»�������Ҫ�ģ�
    std::future<int> result1(std::async(func1));

    int result = func2()+ result1.get();//might call func2() after func1() ends

    ���������ڶ�������Ҳ�ĺ���˳��result1.get()�п����� func2()֮ǰ������
    */

    //��������ʱ����func1()��func2()����ʱ���еĽϴ���  ���� �����ܺ͵�ʱ��
    std::cout << "\nresult of func1()+func2(): " << result
        << std::endl;
}
#endif