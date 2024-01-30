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
//***ע***
//�������Ԫ�ر�ɾ������������(����vector �� deque����Ϊ���ܵ����ڴ����·���)
//����֤�������Լ�����ָ��Ԫ�ص�reference����������Ч��
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
    //���ڷ�string���󣬿�����
    /*
    find_first_of(s.rbegin(), s.rend(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
    */
    //�������������

    // ʹ�� search() 
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
        3, // yalue
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
    while (pos != coll.end()) {
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


//find_end() �������һ��������   ��search()����ǵ�һ�������䣩
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


//is_permutation() ˳������ν����£��������Ԫ���Ƿ����
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


//all_of()��any_of()��none_of() ���ڼ�������㷨
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
//�����ȡ string, ����һ��һ���ķ�ʽ��ӡ���ǣ�
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


//�������������� partition_copy()
#if 1
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