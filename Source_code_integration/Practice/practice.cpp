//
#if 0
#include <iostream>

using namespace std;

int main()
{
	//管理元素
	shared_ptr<int> sp1 = make_shared<int>(100);
	//管理数组
	shared_ptr<int>sp2(new int[100],default_delete<int[]>());
	//注：简化版写法
	shared_ptr<int[]>sp3(new int[100]);

	unique_ptr<int[]>up1(new int [100]);
	
	up1[1] = sp3[1] = 1;
	cout << up1[1] << ' ' << sp3[1]<<endl;

	//cout << *(up1 + 1) <<' ' << *(sp3 + 1) << endl;
	cout << *(up1.get() + 1) << ' ' << *(sp3.get()+ 1) << endl;

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string>vec_str;

	string tmp;
	getline(cin, tmp);

	while (tmp != " "&&!cin.eof())
	{
		vec_str.push_back(tmp);

		getline(cin,tmp);
	}

	copy(vec_str.cbegin(),vec_str.cend(),
		ostream_iterator<string>(cout,"\n"));

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<int> List1{1,3,5};
	List1.remove(3);
	copy(List1.begin(),List1.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	list<int> List2{ 1,3,5,7 };
	//返回范围新结尾的尾后迭代器
	auto it=remove(List2.begin(),List2.end(),3);
	copy(List2.begin(), List2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	List2.erase(it,List2.end());
	copy(List2.begin(), List2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	std::string str1 = "Text with some   spaces";
	//不完整的写法
	std::remove(str1.begin(), str1.end(), ' ');
	cout << str1 << endl;

	str1 = "Text with some   spaces";
	//不完整的写法，错误的写法
	str1.erase(std::remove(str1.begin(), str1.end(), ' '));
	for (auto it = str1.begin(); it != str1.end(); ++it)
		cout << *it;
	std::cout << '\n';

	str1 = "Text with some   spaces";
	//注：正确的写法
	str1.erase(std::remove(str1.begin(), str1.end(), ' '),
		str1.end());
	std::cout << str1 << '\n';

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class A
{
public:
	int a;

	A(int val=0)
	{
		a = val;
	}

	void setVal(int val)
	{
		a = val;
	}

	int getVal(void) const
	{
		return a;
	}

	//注：
	//错误写法：
	//bool operator<(const A& a1)const
	//{
	//	return a <= a1.getVal();
	//}
	//错误原因：
	/*
	operator<实际上是执行了<=操作，这会导致std::sort函数的行为不稳定，
	因为排序算法期望这个运算符提供严格弱序（strict weak ordering）的保证。
	这意味着，对于任何a和b，如果a < b为true，那么b < a必须为false。
	但是，当a和b相等时，你的实现会返回true，违反了这一要求。
	*/

	bool operator<(const A& a1)const
	{
		return a < a1.getVal();
	}
};


int main()
{
	vector<A>a;

	for(int times=1;times<=2;++times)
		for (int i = 0; i < 10; ++i)
		{
			A yuansu(i);

			a.push_back(yuansu);//拷贝副本
		}

	for (auto x : a)
	{
		cout << x.getVal() << ' ';
	}
	cout << endl;

	sort(a.begin(),a.end());
	/*
	若没定义<运算符函数，则报错
	对类类型“std::less<void>”的对象的调用: 未找到匹配的调用运算符
	*/

	//copy(a.begin()->getVal(), a.end()->getVal(), ostream_iterator<int>(cout, "\n"));

	for (auto x : a)
	{
		cout<<x.getVal()<<' ';
	}

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class A
{
public:
	int a;

	A(int val = 0)
	{
		a = val;
	}

	void setVal(int val)
	{
		a = val;
	}

	int getVal(void) const
	{
		return a;
	}

	//bool operator<(const A& a1)const
	//{
	//	return a < a1.getVal();
	//}
};

bool MyCmp(const A& a1,const A&a2)
{
	return a1.getVal() < a2.getVal();
}

int main()
{
	vector<A>a;

	for (int times = 1; times <= 2; ++times)
		for (int i = 0; i < 10; ++i)
		{
			A yuansu(i);

			a.push_back(yuansu);//拷贝副本
		}

	for (auto x : a)
	{
		cout << x.getVal() << ' ';
	}
	cout << endl;

	sort(a.begin(), a.end(),MyCmp);

	for (auto x : a)
	{
		cout << x.getVal() << ' ';
	}

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <set>
using namespace std;

class A
{
private:
	int a;
public:
	explicit A(int val=0)
	{
		a = val;
	}

	int getVal() const
	{
		return a;
	}
};

//bool CmpCriterion(const A& a1, const A& a2)
//{
//	return a1.getVal() < a2.getVal();
//}

class CmpCriterion
{
public:
	bool operator()(const A& a1, const A& a2) const //***注***最后一个const必须加
	{
		return a1.getVal() < a2.getVal();
	}
};

int main()
{
	set<A, CmpCriterion> se1{A(3),A(2),A(1)};

	for (auto x : se1)
	{
		cout << x.getVal() << " ";
	}

	return 0;
}
#endif


//
#if 0
#include <iostream>
#include <numeric>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

class Gen
{
private:
	static int i;

public:
	Gen(int startVal=0)
	{
		i = startVal;
	}

	int operator()()
	{
		int tmp = i;
		++i;
		return tmp;
	}
};

int Gen::i = 0;
/*
注：
不能在类声明中初始化不带const的静态成员变量，因为声明描述了如何分配内存，
但并不分配内存。
*/

int main()
{
	array<int, 9> MyArray{ 0,1,2 };
	generate(MyArray.begin(),MyArray.end(),Gen(1));

	for (auto x : MyArray)
		cout << x << " ";
	cout << endl;

	int res= accumulate(MyArray.begin(), MyArray.end(), 0);
	cout << res << endl;

	string init("0");
	string res1 = accumulate(MyArray.begin(), MyArray.end(), init,
		[](string init,int val) 
		{
			return move(init +"-"+ to_string(val));
		});

	cout << res1;

	return 0;
}
#endif