//《C++标准库》


//对C-Style array 使用基于范围的for循环
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


//shared_ptr的use_count()
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


//shared_ptr和unique_ptr用法区别
#if 0
#include <iostream>

int main()
{
    // shared_ptr
    // get and attach shared memory for 100 ints:
    //写法一：
    std::shared_ptr<int> sp(new int[100], [](int* p)
        { delete[]p; }
    );
    //写法二：
    std::shared_ptr<int> sp1(new int[100], std::default_delete<int[]>());

    // unique_ptr
    //写法一：
    std::unique_ptr<int[]> up(new int[100]);
    //写法二：
    std::unique_ptr<int, void (*)(int*)> up1(new int[100], [](int* p) {
        delete[]p;
        });
    //错误写法：
    /*std::unique_ptr<int[], void(*)(int*)> up1(new int[100], []() {
        });*/

    for (int i = 0; i < 100; ++i) {
        sp.get()[i] = i * 42;
        //错误写法：
        //*(smp + i) = i * 42;
    }

    for (int i = 0; i < 100; ++i) {
        //写法一：
        up.get()[i] = i * 42;
        //写法二：
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


//原子操作
#if 0
#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> atomicInt;

    // 使用 store 将值原子地存储到 atomicInt 对象中
    atomicInt.store(10);

    std::cout << "Value in atomicInt: " << atomicInt.load() << std::endl;

    return 0;
}
#endif


//如果你将同一个动态分配的内存地址传递给多个 shared_ptr 实例来管理，
//会导致程序出现未定义的行为，
//这是因为多个 shared_ptr 实例会各自尝试释放同一个内存地址，
//可能导致重复释放内存，从而引发问题
//一个动态分配的内存空间只能由【一组】shared_ptr管理
#if 0
#include <iostream>

using namespace std;

int main()
{
    //正确写法
    //shared_ptr<int>sp1(new int);
    //shared_ptr<int>sp2(sp1);

    //错误写法：
    //一个动态分配的内存空间由【两组】shared_ptr管理
    int* p = new int;
    shared_ptr<int>sp1(p);
    shared_ptr<int>sp2(p);

    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;

    return 0;
}
#endif


//计算程序的执行时间
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
    //                                                               微秒
    auto sec = chrono::duration_cast<chrono::microseconds>(diff);

    cout << sec.count() << endl;

    return 0;
}
#endif


//使用array代替传统数组
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


//从标准输入读取string，排序然后打印(去掉重复的字符串)
//自己写的方法：
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

    //qsort(str,index,);//每个元素大小不一，不能用qsort()
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
//法一：
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

    //使用串流迭代器
    // read all words from the standard input
    // - source: all strings until end-of-file (or error)
    // - destination: coll (inserting)
    copy(istream_iterator<string>(cin),    // start of source
        istream_iterator<string>(),       // end of source 
        back_inserter(coll));             // destination

    //istream_iterator<string>(cin)
    //会产生一个可从“标准输入串流(standard input stream) cin”读取数据的 stream iterator。
    //其中的 template 实参 string表示这个 stream iterator专司读取该种类型的元素(string 类
    // 型将在第13章介绍)。这些元素通过一般的 operator >>被读取进来。因此每当算法企图
    //处理下一元素时，istream iterator 就会将这种企图转化为以下行动：
    //cin >> string
    //针对 string 而执行的 input操作符通常读取以空白分隔的文字(见 13.2.10 节第 677页),
    //因此上述算法的行为将是“逐字读取”(word by word)。

    //istream_iterator<string>()
    //会调用istream iterator的 default 构造函数，产生一个代表“串流结束符”(end - of - stream)
    //的迭代器，这个东西代表的意义是：你不能再从中读取任何东西。

    // sort elements
    sort(coll.begin(), coll.end());

    // print all elements without duplicates
    // - source: coll
    // - destination: standard output (with newline between elements)
    unique_copy(coll.cbegin(), coll.cend(),           // source
        ostream_iterator<string>(cout, "\n")); // destination
}
#endif
//法二：
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
//法三：
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
//比较
// 1. 使用 copy() 和 ostream_iterator与 2. 使用基于范围的for循环
//两种输出方法
//1.非常简洁，一行代码即可完成任务。可以支持普通数组如copy(flag,flag+10000,ostream_iterator<bool>(cout));
// 但是，它有些局限性，例如无法进行更复杂的处理或转换输出。
//2.更加灵活和直观。它使代码更易读，尤其是在需要对输出进行更多控制或转换时。
// 你可以在循环内部添加逻辑，对输出进行格式化或添加其他操作。


//删除容器中的元素（要保证“斩草除根”）
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
    //“斩草除根”
    // remove "removed" elements 
    coll.erase(end, coll.end());

    // print all elements of the modified collection
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "));

    cout << endl;
}
//用单一语句来删除元素
//coll.erase(remove(coll.begin(),coll.end(),3),coll.end());

//***注***
//对于非关联式容器可以使用remove方法删除指定的元素
//remove方法【不改变集合中元素的个数】
//逻辑上是要被删除的元素被其后的元素覆盖，而末尾那些未被覆盖的元素原封不动
//但逻辑上已经不属于这个集合了
//用remove()函数搭配erase()方法可以斩草除根

//对于关联式容器可以直接使用erase方法删除元素

//最后
//对于list容器，其类中有专门的优化效率的remove()、remove_if()方法，
//因此对于算法vs成员函数
//优先选用成员函数即方法
#endif


//实现在执行时确定函数
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


//函数适配器bind
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
using namespace std::placeholders;//可以使用占位符如_1

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


//对于array，不要以迭代器表现“第一元素的地址”
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


//使用tuple
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

    //array提供了tuple接口
    array<int, 5>a1{ 1,2,3 };
    cout << get<1>(a1) << endl;

    return 0;
}
#endif


//accumulate() 求积累值     进阶用法
//快捷打印：
// 1-2-3-4-5-6-7-8-9-10 和 10-9-8-7-6-5-4-3-2-1
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

    //错误写法：
    /*
    auto dash_fold = [](int a, int b) {
        return std::to_string(a) + '-' + std::to_string(b);
        };
    */
    //原因：
    //accumulate()实现方法：
    /*
template<class InputIt, class T, class BinaryOperation>
constexpr // C++20 起
T accumulate(InputIt first, InputIt last, T init,
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // C++20 起有 std::move //当函数返回一个 unique_ptr 就不需要move()
    }
    return init;
}
    */

    std::string s = std::accumulate(std::next(v.begin(), 1), v.end(),
        std::to_string(v[0]), // 用首元素开始
        dash_fold);

    // 使用逆向迭代器右折叠
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
        std::to_string(v.back()), // 用首元素开始
        dash_fold);

    std::cout << "sum: " << sum << '\n'
        << "product: " << product << '\n'
        << "dash-separated string: " << s << '\n'
        << "dash-separated string (right-folded): " << rs << '\n';
}
#endif
//也可以用transform()来配合accumulate()实现相同功能
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

    // 使用 std::transform 将整数转换为字符串
    //***注***
    //因为accumulate()的原理上
    //是会用到容器v的第一个元素，并在其后【累积】
    //所以不妨只处理容器v中第二个元素到末尾元素
    std::vector<std::string> stringValues(v.size() - 1);
    std::transform(std::next(v.begin(), 1), v.end(), stringValues.begin(),
        [](int value) { return std::to_string(value); });

    // 使用 std::accumulate 将字符串连接起来
    std::string s = std::accumulate(stringValues.begin(), stringValues.end(),
        firstElement,
        [](std::string a, std::string b)
        {
            return std::move(a) + '-' + std::move(b);
        });

    // 使用逆向迭代器右折叠
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


//swap()后，vector的所有引用、指针、迭代器都失效了
//因为这些东西都指向原本位置
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

    //交换后迭代器与引用保持与其原来的元素关联
    cout << *it1 << " " << *it2 << endl;

    return 0;
}
#endif


//deque用法
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
    //最终余下3个元素

    // insert "another" into every element but the first
    for (unsigned i = 1; i < coll.size(); ++i) {
        coll[i] = "another " + coll[i];
    }

    // change size to four elements
    coll.resize(4, "resized string");
    //第一个参数指定新的大小
    //第二个参数指定用于填充调整大小操作可能会创建的任何新元素的值，
    //即字符串“resized string”。如果元素超过 4 个，多余的元素将被删除以使大小为 4。

    // print elements separated by newlines
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}
#endif


//list用法
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


//forward_list用法
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


//lower_bound()、upper_bound()、equal_range()
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

    //lower_bound(3) 返回一个迭代器，指向第一个 >= 3 的元素。
    //在集合中，第一个>= 3 的元素是 4。
    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    //upper_bound(3) 返回第一个 > 3 的元素的迭代器。
    // 在集合中，第一个 > 3 的元素也是 4。
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    //***理解***
    //equal_range(3) 返回一对迭代器，表示值为 3 的元素范围。
    //在本例中，由于不存在值为 3 的元素，
    //因此两个迭代器都指向第一个不小于 3 的元素，即 4。
    cout << "equal_range(3): " << *c.equal_range(3).first << " "
        << *c.equal_range(3).second << endl;
    cout << endl;

    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " "
        << *c.equal_range(5).second << endl;
}
#endif


//对于关联容器，实现运行期指定排序准则
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

    //或者写为：
#if 1
    set<int, RuntimeCmp> coll2({ 4, 7, 5, 1, 6, 2, 5 }, reverse_order);
#endif

    PRINT_ELEMENTS(coll2, "coll2: ");

    // assign elements AND sorting criterion
    coll1 = coll2;
    coll1.insert(3);
    PRINT_ELEMENTS(coll1, "coll1: ");

    // just to make sure...
    //对于set来说，由于 std::set 被设计为具有唯一的键，键同时也是值。
    // 因此，对于 std::set ，您可以在大多数情况下互换使用 key_comp 或 value_comp ，
    // 而不会出现明显差异
    //key_comp 方法：返回一个比较函数，该函数仅比较集合中元素的键
    //value_comp 方法：返回一个比较值的比较函数
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


//使用算法和lambda来操作map元素
//lambda的形参的新式写法
#if 0
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, float> strmap{ {"abc",1.1188},{"def",2.1} };

    //写法一：
    for_each(strmap.begin(), strmap.end(),
        [](const pair<const string, float>& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    //写法二：
    for_each(strmap.begin(), strmap.end(),
        [](const map<string, float>::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    //写法三：
    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    return 0;
}
#endif


//六种方法向map或multimap内安插内容
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
    strmap["f"] = 6;//***注***
    //这种元素安插方式比惯常的 map安插方式慢，7.8.2节第340页
    //曾经谈过，原因是新元素必须先使用default 构造函数将 value 初始化，
    //而该初值马上又被真正的 value 覆盖。

    strmap["g"];
    //“operator[]的索引类型不必是整数”并不是它和寻常 array 唯一不同之处。如果你
    //选择某 key 作为索引，容器内却没有相应元素，那么map会自动安插一个新元素，其value
    //将被其类型的 default 构造函数初始化。因此，你不可以指定一个“不具 default 构造函数”
    //的value 类型。注意，基础类型都有一个 default 构造函数，设立初值0(见 3.2.1 节第 37页)。

    for_each(strmap.begin(), strmap.end(),
        [](const decltype(strmap)::value_type& pa)
        {
            cout << pa.first << " " << pa.second << endl;
        });

    return 0;
}
#endif


//移除元素，并避免使用一个【暂时】无效的迭代器
//***注***
//如果其他元素被删除，所有容器(除了vector 和 deque，因为可能导致内存重新分配)
//都保证迭代器以及用以指向元素的reference继续保持有效。
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

    //错误的移除元素写法：
#if 0
    for (auto pos = strmap.begin(); pos != strmap.end(); ++pos)
    {
        if (pos->first == "a")
        {
            strmap.erase(pos);//pos会不再成为一个有效的迭代器，此后未对pos
        }                                 //重新设值就直接使用，会造成运行期间错误
    }
#endif

    //错误的处理写法：
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

        //***注***
        //以下代码运行时会报错
        /*
        if (abs(pos->second - 5) <= 0.00001)
        {
            //因为erase()作用后，pos值为strmap.end()。++pos后指向无效位置。
            pos = strmap.erase(pos);
        }
        */
    }
#endif

    //正确写法：
    for (auto pos = strmap.begin(); pos != strmap.end(); )
    {
        if (pos->first == "a" || abs(pos->second - 4.4) <= 0.00001)
        {
            //***理解***
            //指向被擦除元素的引用和迭代器被非法化。其他引用和迭代器不受影响。
            //erase()返回一个迭代器指向【其后继的】元素
            //pos由此得到更新
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


//multimap当做字典
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
    //查找key对应的所有value值（前提是有这个key，若没有则不合适（详见：//lower_bound()、upper_bound()、equal_range()））
    string word("smart");
    cout << word << ": " << endl;
    for (auto pos = dict.lower_bound(word); pos != dict.upper_bound(word);
        ++pos)
    {
        cout << "    " << pos->second << endl;
    }

    // print all keys for value "raffiniert"
    //查找value对应的所有key值
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


//使用map、string并于运行期指定排序准则
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
    //                        普通模式    大小写无关模式
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
            //lexicographical_compare() 字典序比较
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
    StringStringMap coll1;//使用一个RuntimeStringCmp的函数对象，以默认的normal为初值
    fillAndPrint(coll1);

    // create an object for case-insensitive comparisons
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
    // create a container with the case-insensitive comparisons criterion
    StringStringMap coll2(ignorecase);
    //***理解***
    //使用的是   explicit map(const Compare & comp, const Allocator & alloc = Allocator());
    //使用一个类型为RuntimeStringCmp的函数对象，并以nocase为初值。nocase会令
    //这个函数对象以“大小写无关”模式完成字符串的比较和排序。

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


//无序关联容器的布局操作
#if 0
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_multiset<int>unset;

    //最大负载因子（因子↑，哈希表空间利用率↑，性能可能↓）
    unset.max_load_factor(0.7);

    //准备100/最大负载因子个元素的大小的bucket，以避免在没超过100个元素就rehash()
    unset.rehash(100 / 0.7);
    //准备100个元素大小的bucket
    unset.reserve(100);

    return 0;
}
#endif


//无序关联容器，提供自己的Hash函数和等价准则
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


//使用Lambda作为Hash函数和等价准则
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
    //***理解***
    //必须使用decltype产生 lambda类型，使得以传递它作为 unordered 容器声明式的
    //template 实参。
    //而 lambda并不存在 default 构造函数和 assignment 操作符。
    //因此，你也必须将lambda传给构造函数。
    //而由于它们被设计为第二和第三实参，因此这种情况下你必须指明最初的 bucket 大小，
    //本例为10。

    custset.insert(Customer("nico", "josuttis", 42));
    PRINT_ELEMENTS(custset);

}
#endif


//使用Bucket接口
//可以访问内部的桶（buckets）。
//每个桶是一个存储元素的容器，可以将具有【相同哈希值的元素】存储在同一个桶中。
//***注***
// 相同哈希值的元素【也可能是不同的键】，它们只是发生了哈希冲突，
// 而哈希表的内部机制确保它们在同一个桶中得到存储。在查找元素时，
// 哈希表会根据键的相等性来确定具体是哪个元素。
// 
// 在 std::unordered_multimap 中，
// 相同哈希值的元素被存储在同一个桶中，而同一个桶中的元素可能具有不同的键。
// 因此，同一个桶中存储的元素的键不一定相同，但它们具有相同的哈希值。
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


//非入侵式或包裹法使C-Style Array作为一种STL容器
#if 0
#include <iterator>
#include <vector>
#include <iostream>

int main()
{
    int vals[] = { 33, 67, -4, 13, 5, 2 };

    // use begin() and end() for ordinary C arrays
    std::vector<int> v(std::begin(vals), std::end(vals));

    //等价于以下写法 （适用于C++11之前）
    //std::vector<int> v(vals, vals+sizeof(vals)/sizeof(vals[0]));

    // use global begin() and end() for containers:
    std::copy(std::begin(v), std::end(v),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
#endif


//通常STL容器提供的是value语义，而不是reference语义
//STL容器要实现Reference语义
//方法一：采用【智能指针】
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

    //***注***
    //使用shared_ptr<>会让事情变复杂。例如，面对set 使用find(),会找出拥有相等
    //value 的元素，现在比较的却是内部(由new返回)的 pointer 
    // allItems.find(ItemPtr(new Item("Pizza",2.22)))   //can'tbe successful
    //以下写法也不适用
    //bestsellers[1] = find(allItems.begin(), allItems.end(),string("Pizza"));

    // set price of first bestseller
    bestsellers[0]->setPrice(44.77);

    // print contents of both collections
    printItems("bestsellers:", bestsellers);
    printItems("all:", allItems);
}
#endif


//Reference Wrapper （引用外覆器）
//声明于<functional>中的 class std::reference_wrapper<>主要用来
//“喂” reference 给function template, 后者原本以by value方式接受参数。
// 对于一个给定类型T, 这个 class提供ref()用以隐式转换为T&, 
// 一个 cref()用以隐式转换为 const T&, 这往往允许 
// function template 得以操作 reference 而不需要另写特化版本。
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


//实现Reference语义
//方法二：使用 class reference_wrapper<> 
//优点：不需要智能指针
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
        //需要使用get()方法，访问存储的引用
        std::cout << ' ' << elem.get().getName() << ": "
            << elem.get().getPrice() << std::endl;
    }
}

int main()
{
    using namespace std;

    //reference_wrapper<Item>: 这是一个模板类，它包装了对 Item 类型对象的引用。
    // reference_wrapper 允许将引用作为对象进行传递，
    // 而不是传递引用时会自动发生的解引用。
    // 这对于在容器中存储引用是很有用的，因为容器通常要求元素是可复制的，
    // 而引用则通常不是可复制的。
    //这种设计常常用于需要在容器中存储引用而不是复制对象的情况，
    // 例如，当你想要在容器中保存对象的引用，并且希望通过引用修改原始对象时。
    vector<reference_wrapper<Item>>books;

    Item book1("bookname", 12.99);
    //向容器安插元素，但是安插的是个引用
    books.push_back(book1);

    printItems("books:", books);
    cout << endl;

    //***注***
    //直接修改book1对象的内容，
    //若vector容器中存的不是该对象的引用，默认存的是拷贝的value即拷贝的对象
    //那就不会影响vector容器中的该对象中存的内容。
    //而该例存的是该对象的引用，那就会影响vector容器中的该对象中存的内容。
    book1.setPrice(9.99);

    cout << books[0].get().getPrice() << endl;

    printItems("books:", books);
    cout << endl;

    //***注***
    //创建以下vector的尝试，无法通过编译
    //vector<Item&>books_test;
    //books_test.push_back(book1);
    //book1.setPrice(10.5);
    //cout << books_test[0].getPrice() << endl;
}
#endif


//小结：
//各种容器的使用时机

//默认情况下应该使用 vector。Vector的内部结构最简单，并允许随机访问，
//所以数据的访问十分方便灵活，数据的处理也够快。

//如果经常要在序列头部和尾部安插和移除元素，应该采用deque。如果你希望元素
//被移除时，容器能够自动缩减内部内存用量，那么也该采用deque。

//如果需要经常在容器中段执行元素的安插、移除和移动，可考虑使用list。

//如果你经常需要根据某个准则查找元素，应当使用“依据该准则进行hash”的
//unordered set 或 multiset

//如果想处理 key/value pair,请采用unordered(multi)map。如果元素次序很重要，可采用
//(multi)map


//随机访问迭代器的特殊能力
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
    //***注***
    //以2个单位为跨度来向前增加迭代器的位置时要注意
    //若写为
    //for(pos= coll.begin();pos< coll.end(); pos += 2)
    //而容器中含奇数个元素，会有不明确行为
    //原因：
    //将迭代器移至“起点更前面”会导致不明确行为。同样道理，
    //如果表达式pos += 2将迭代器移至end()之后，也会导致不明确行为。
}
#endif


//迭代器的相关辅助函数
//由于vector、array、string的迭代器
//通常被实现为寻常pointer, 而 C++并不允许你修改任何基础类型
//(包括 pointer)的临时值，但对于 struct 和class 则允许。
//因此，如果迭代器被实现为寻常 pointer, 则编译失败；如果被实现为 class, 则编译成功。
//为了保证移植，可以使用C++11提供的next()
//next()好处之一：
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

    //***注***
    // 尽管表达式 ++c.begin() 通常能编译，然而不保证会这么做： 
    // c.begin() 是右值表达式，而无老式输入迭代器 (LegacyInputIterator) 
    // 要求指定右值的自增保证进行。
    // 尤其是迭代器以指针实现或其 operator++ 为【左值引用限定】时，
    //  ++c.begin() 不能编译，而 std::next(c.begin()) 可以。
}
#endif


//根据迭代器种类，选择最佳的前进/后退方案：advance()
//***注***
//前进：next()    后退：prev()       函数
//内部将对一个临时对象调用advance()
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


//next()好处之二：
//对于没有operator +和operator -  的这些容器
//可以用next()来确定遍历到某个位置时停止
#if 0
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> coll;//仅有双向迭代器

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

    //forward 和 bidirectional 迭代器不提供 operator +和 -
    //如果不用next()，你就需要创建一个临时对象的协助来判断
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


//根据迭代器种类，选择最佳的计算距离的方案：distance()


//交换两个迭代器所指的元素的值
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


//迭代器适配器(iterator adapter)
//将正常的迭代器转化成反向迭代器
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

    //***注***
    //转换前后迭代器逻辑位置发生了变化
    //当我们把pos 转换为rpos,它们的物理位置指向同一点，但它们所代表的意义
    //(或说它们所代表的逻辑位置)不同了

    //***理解***
    //rbegin()指向容器的最末元素的下一个位置，而对其解引用后值为最末元素的值
    //rend()指向容器的第一个元素的位置，而对其解引用后值为第一个元素前的一个位置

    //为什么rend()指向容器的第一个元素的位置？
    //因为遍历容器，一般我们需要采用“最末元素的下一位置”。
    // 然而对 reverse 迭代器而言，这个位置位于第一元素之前。
    // 糟糕的是，这个位置可能并不存在，因为容器并不要求其第一元素之前的位置合法
    //所以对于反向迭代器，物理上rend()指向容器的第一个元素的位置(该位置一定合法)，
    //但是逻辑上解释为第一个元素前的一个位置。
    //由于物理意义和逻辑意义不同，而解引用解的是逻辑意义，
    //因此逻辑上其 value(也就是其所指元素值)也就移到了前一个元素身上。
}
#endif


//反向迭代器的应用
//使用一对迭代器，正向和逆向打印找出的元素
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
    //***理解***
    //物理位置不变，但是逻辑位置改变，打印出的内容正好符合预期。

    //使用base()将反向迭代器转化为正常迭代器
    deque<int>::const_iterator rrpos1(rpos1.base());

    cout << "*rrpos1=" << *rrpos1 << endl;
}
#endif


//back_insert_iterator、back_inserter()的应用
//只能用在vector、deque、list、string上
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
    //***注***
    //安插型迭代器确实能安插元素到容器中，
    //但是【对于vector等内存可能需要重新分配的容器】
    //back inserter 在安插元素时，可能会造成指向该 vector的其他迭代器失效。
    //因此，如果提前不申请足够空间，这个算法可能会形成“源端迭代器失效”状态。
    coll.reserve(2 * coll.size());

    copy(coll.begin(), coll.end(), back_insert_iterator<vector<int>>(coll));
    PRINT_ELEMENTS(coll);

    coll.reserve(2 * coll.size());

    copy(coll.begin(), coll.end(), back_inserter(coll));
    PRINT_ELEMENTS(coll);

    //还可以使用vector容器自己的insert方法
    //（传入的是个指向自身的某个元素的迭代器时，也要注意操作后迭代器可能会失效）
}
#endif


//front_insert_iterator、front_inserter()的应用
//只能用在deque、list、forward list
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


//insert_iterator、inserter()应用
//general inserter 【对所有标准容器均适用】(只有 array 和 forward list 除外),
// 因为那些容器都提供有insert()成员函数(见8.7.1节第413页)。
// 然而对 associative 和 unordered 容器而言，安插位置只是个提示，
// 因为在这两种容器中元素的真正位置视其value而定。
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
        //错误写法：
        //coll2.insert(pos,i);
        //正确写法：
        pos = coll2.insert(pos, i);
        ++pos;
    }

    //***注***
    //安插动作完成后，general inserter 获得刚被安插的那个元素的位置，相当于
    //pos = container.insert(pos,value);
    //++pos;
    //这样使为了确保该迭代器的位置始终有效。如果
    //没有这一赋值动作，在 deque、vector 和 string中，
    //该 general inserter本身可能会失效。因为每一次安插动作都会
    //(或至少可能会)使指向容器的所有迭代器失效。

    PRINT_ELEMENTS(coll2, "list: ");
}
#endif


//使用ostream_iterator
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


//使用istream_iterator
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

    //***注***
    // 若输入字符a将导致程序结束。由于格式错误，stream不再处于 good 状态，
    // 于是 istream迭代器 intReader 就和 end - of - stream 迭代器 intReaderEOF 相同，
    // 使得循环条件为 false, 进而结束循环。
}
#endif


//利用advance()和istream_iterator来跳过指定个数的输入内容
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
        //***注***
        //若指向EOF的后一个位置，程序会崩溃

        // read and write the third string
        if (cinPos != istream_iterator<string>())
        {
            *coutPos++ = *cinPos++;
        }
    }
    cout << endl;

    //***注***  若输入：
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
//程序会在输入到d时，立即输出c
//分析：
//while 循环开始，从输入中【读取了】 a 但被忽略，同理b也被忽略
//读取到c，通过输出迭代器输出到屏幕，但由于输入迭代器仍将检测输入的内容
//因此不会马上输出c。等到输入迭代器再读取一个string格式的内容后，才输出c
//或者直接键入^Z后，输出c

//若输入：
/*
a b c d e f g h
*/
//则输出c f
}
#endif


//以函数对象为排序准则
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
    //***理解***
    //coll构造函数会自动产生 class PersonSortCriterion的一个实例(instance),
    // 所有元素都将以此为排序准则进行排序

    //写法二：
    /*
    PersonSortCriterion PSC;
    set<Person, PersonSortCriterion> coll(PSC);
    */
    //详细见//对于关联容器，实现运行期指定排序准则

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


//函数对象拥有内部状态(Internal State)
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


//for_each()独门绝技：可以传回其函数对象
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

    //***理解***
    //for_each()的实现：
    /*
    template<class InputIt, class UnaryFunction>
    UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
    {
        for (; first != last; ++first) {
            f(*first);
        }
        return f; // C++11 起隐式移动
    }               // (此例中调用MeanValue的自动提供的复制构造函数)
    */
}
#endif


//remove_if()碰上函数对象作为谓词 (Predicate)会出现的问题
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

    //结果为：1 2 4 5 7 8 9 10
    //理解：
    //remove_if()的实现
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
        return remove_copy_if(++next,end,beg,op);//提高代码的复用性和遵循单一责任原则
        }
    }
    */
    // 使用find_if()查找应被移除的第一个元素。然而，
    // 接下来remove_copy_if()使用传入的 predicate op的拷贝去处理剩余元素，
    // 这时原始状态下的Nth再次被使用，因而
    // 会移除剩余元素中的第3个元素，也就是整体的第6个元素。

    //解决方法：使用remove_copy_if()
    pos = remove_copy_if(coll.begin(), coll.end(),  // range
        coll.begin(), Nth(3));                  // remove criterion
    coll.erase(pos, coll.end());

    PRINT_ELEMENTS(coll, "3rd removed: ");

    //使用lambda更直观：
    int cnt = 0;
    pos = remove_if(coll.begin(), coll.end(), [&cnt](int)
        {
            return ++cnt == 3;
        });
    coll.erase(pos, coll.end());

    PRINT_ELEMENTS(coll, "3rd removed: ");
}
/*
remove_copy_if的实现：
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
//区别：
//remove_if 用于从容器中移除元素，而 remove_copy_if 则是将不满足条件的元素
//复制到另一个容器中。需要注意的是，remove_if 不会真正删除元素，
//而是将它们移到容器末尾，需要结合 erase 操作来真正删除。


//bind()嵌套合成更复杂的函数对象
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
//改用Lambda来实现更复杂的计算
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


//bind()调用全局函数
//使用search()函数检验一个字符串是否是另一个字符串的子串，
//即查找第一个子区间
//***注***
//search() 强调的是查找第一个匹配，而 find_end() 强调的是查找最后一个匹配
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
//用lambda来实现调用全局函数
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

    //find_first_of   ”似乎“也可以？
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


//search()和find_first_of()的区别
#if 0
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello world";
    std::string sub_str = "world";

    // 使用 find_first_of() 
    //寻找等于 str 中字符之一的首个字符。
    size_t pos = str.find_first_of(sub_str);
    if (pos != std::string::npos) {
        std::cout << "Substring found at position: " << pos << std::endl;
    }
    else {
        std::cout << "Substring not found" << std::endl;
    }

    //***注***
    //没有find_last_of()函数，仅string有该方法
    //想要实现寻找最后一个等于 str 中字符之一的首个字符的元素位置
    //对于非string对象，可以用
    /*
    find_first_of(s.rbegin(), s.rend(),           // string to search in
        sub.begin(), sub.end(),       // substring to search
    */
    //（反向迭代器）

    // 使用 search() 
    //  在字符串中查找完全匹配指定子串的第一个位置
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


//bind()调用成员函数
//不直观，个人更喜欢用lambda
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
//用lambda实现调用成员函数
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
    //可以不使用function<>
    //当需要存储不同类型的可调用对象、
    // 将它们作为参数传递给函数或通过传递可调用对象为
    // 用户提供自定义行为的灵活性时， std::function 的使用变得更加相关

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
//在范围 [first, last) 中搜索 count 个等同元素的序列，
//每个都等于给定的值 value 或者 满足二元谓词
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
        [](int elem, int value) // criterion   ***注***
        {     
            return elem % 2 == 1;
        });
    //***注***
    // 必须写成二元谓词
    //不能写成
    /*
    pos = search_n(coll.begin(), coll.end(),    // range
        4,                           // count
        0,                           // value
        [](int elem) // criterion
        {
            return elem % 2 == 1;
        });
        */
    
    //因为有如下写法：
    //找出四个值大于3的连续元素
#if 0
    pos = search_n(coll.begin(), coll.end(), // range
        4, // count
        3, // yalue
        greater<int>()); // criterion   二元谓词
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


//search()以更复杂的准则查找某个子序列
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


//find_end() 查找最后一个子区间   （search()查的是第一个子区间）
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

        //找倒数第二个符合的子字符串位置
        // search next occurrence of subcoll
        end = pos;
        pos = find_end(coll.begin(), end,               // range
            subcoll.begin(), subcoll.end()); // subrange
    }
}
#endif


//is_permutation() 顺序无所谓情况下，两区间的元素是否相等
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


//all_of()、any_of()、none_of() 属于检验类的算法
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


//使用copy()作为标准输入设备和标准输出设备之间的数据筛检程序。
//程序读取 string, 并以一行一个的方式打印它们：
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


//unique_ptr的复制构造函数、赋值运算符重载函数的实参需要使用move()
// move() 来体现移动语义的细节
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
    //使用move()，因为coll2中的这些元素不会再次使用
    move(coll2.cbegin(), coll2.cend(),         // source range
        ostream_iterator<string>(cout, " "));  // destination range
    cout << endl;
    //***注***
    //coll2的元素在它们初次被输出后，状态就变得【不确定】，
    // 因为这里用的是move()。
    //然而并不意味着coll2容器不能再出现在以后的代码中，
    //coll2的大小仍然是5, 所以我们可以再次调用move()覆盖(overwrite)这些元素。

    //验证输出：
    copy(coll2.cbegin(), coll2.cend(),        
        ostream_iterator<string>(cout, " "));
    cout << endl;
    //输出内容正常，结果表明：
    //move() 并不总是会移动元素。
    // 它只是告诉编译器，【如果可能的话，可以使用移动语义来处理。】
    // 但在这种情况下，ostream_iterator 对元素进行输出，
    // 并没有真正的移动元素。
    //因此，虽然使用了 move()，但元素仍然保留在 coll2 中，
    // 所以第二个 copy() 调用输出了 coll2 中的元素。

    // copy elements of coll1 into coll2 in reverse order
    // - now overwriting (coll2.size() still fits)  先要保证移入的容器的容量足够
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


//互换某两个区间的元素 swap_ranges
//(如果要将相同类型的两个容器内的所有元素都互换，应使用swap()成员函数)
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

    //***注***
    //将coll1的元素和coll2的对应元素交换。 
    // 元素个数为distance(coll1.begin(), coll1.end())
    // coll2 之内的其余元素不变动。 
    // swap_ranges()算法返回第一个未被改动的元素。

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


//fill()和generate()的区别
//std::fill(myVector.begin(), myVector.end(), 5);

//使用 lambda 函数作为生成器函数，依次填充向量的每个元素
//int value = 0;
//std::generate(myVector.begin(), myVector.end(), [&value]() { return value++; });

//fill() 用于将范围内的元素设置为给定值，
//而 generate() 则用于使用生成器函数来填充范围内的元素


//旋转元素rotate()
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


//对元素重新洗牌 random_shuffle()
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


//将元素向前搬 partition()、stable_partition()
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

    //partition()和stable_partition()都将元素分为两组
    //返回值指向第二组元素首元素的迭代器。

    //stable_partition()保持了奇数元素和偶数元素的相对次序，
    // 这一点和partition()不同。

    // print collections and first odd element
    PRINT_ELEMENTS(coll1, "coll1: ");
    cout << "first odd element: " << *pos1 << endl;
    PRINT_ELEMENTS(coll2, "coll2: ");
    cout << "first odd element: " << *pos2 << endl;
}
#endif


//划分两个子区间 partition_copy()
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