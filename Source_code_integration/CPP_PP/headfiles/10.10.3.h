#define _CRT_SECURE_NO_WARNINGS 1

#ifndef class_Golf
#define class_Golf

class Golf
{
	enum {Len=40};
	struct golf
	{
		char fullname[Len];
		int handicap;						//错误理解：
	}golf_structure;						//此处创建的结构变量并没有存储在对象中
												    //正确理解：
													//没有对结构变量进行初始化操作，这里仍只描述了如何分配内存，但并不分配内存
													//***注***
													// 要将类内声明与一般的类外的声明区别开
													//一般的声明在声明时就为变量分配空间了
													
	//***注***也可以不用结构，直接用基本数据类型
	/*char fullname[Len];
	int handicap;*/

public:
	//非交互版本
	Golf(const char* p_data,const int hc);
	//交互版本
	Golf();
	~Golf();
	void handicap(const int hc);
	void showgolf() const;
};

#endif  /*class_Golf*/