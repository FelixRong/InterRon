## 📑 目录

* C/C++ 

## C/C++

### 引用和指针的区别？
1)	指针是一个实体，需要分配内存空间。引用只是变量的别名，不需要分配内存空间。
2)	引用在定义的时候必须进行初始化，并且不能够改变。指针在定义的时候不一定要初始化，并且指向的空间可变。（注：不能有引用的值不能为NULL）
3)	有多级指针，但是没有多级引用，只能有一级引用。
4)	指针和引用的自增运算结果不一样。（指针是指向下一个空间，引用时引用的变量值加1）
5)	sizeof 引用得到的是所指向的变量（对象）的大小，而sizeof 指针得到的是指针本身的大小。
6)	引用访问一个变量是直接访问，而指针访问一个变量是间接访问。
7)	使用指针前最好做类型检查，防止野指针的出现；
8)	引用底层是通过指针实现的；
9)	作为参数时也不同，传指针的实质是传值，传递的值是指针的地址；传引用的实质是传地址，传递的是变量的地址。


### const

#### 作用

1. 修饰变量，说明该变量不可以被改变；
2. 修饰指针，分为指向常量的指针和指针常量；
3. 常量引用，经常用于形参类型，即避免了拷贝，又避免了函数对值的修改；
4. 修饰成员函数，说明该成员函数内不能修改成员变量。

#### 使用

<details><summary>const 使用</summary> 

```cpp
// 类
class A
{
private:
    const int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    A() : a(0) { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
};

void function()
{
    // 对象
    A b;                        // 普通对象，可以调用全部成员函数
    const A a;                  // 常对象，只能调用常成员函数、更新常成员变量
    const A *p = &a;            // 常指针
    const A &q = a;             // 常引用

    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量
    char* const p3 = greeting;          // 常指针，指向字符数组变量
    const char* const p4 = greeting;    // 常指针，指向字符数组常量
}

// 函数
void function1(const int Var);           // 传递过来的参数在函数内不可变
void function2(const char* Var);         // 参数指针所指内容为常量
void function3(char* const Var);         // 参数指针为常指针
void function4(const int& Var);          // 引用参数在函数内为常量

// 函数返回值
const int function5();      // 返回一个常数
const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();
```

</details>

### static

#### 作用

1. 修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，在 main 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
2. 修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命令函数重名，可以将函数定位为 static。
3. 修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。
4. 修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在 static 函数内不能访问非静态成员。

### inline 内联函数

#### 特征

* 相当于把内联函数里面的内容写在调用内联函数处；
* 相当于不用执行进入函数的步骤，直接执行函数体；
* 相当于宏，却比宏多了类型检查，真正具有函数特性；
* 编译器一般不内联包含循环、递归、switch 等复杂操作的内联函数；
* 在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数。

#### 使用

<details><summary>inline 使用</summary> 


```cpp
// 声明1（加 inline，建议使用）
inline int functionName(int first, int secend,...);

// 声明2（不加 inline）
int functionName(int first, int secend,...);

// 定义
inline int functionName(int first, int secend,...) {/****/};

// 类内定义，隐式内联
class A {
    int doA() { return 0; }         // 隐式内联
}

// 类外定义，需要显式内联
class A {
    int doA();
}
inline int A::doA() { return 0; }   // 需要显式内联
```

</details>

#### 虚函数（virtual）可以是内联函数（inline）吗？

> [Are "inline virtual" member functions ever actually "inlined"?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/inline-virtuals.html)

* 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
* 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
* `inline virtual` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 `Base::who()`），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

<details><summary>虚函数内联使用</summary> 


```cpp
#include <iostream>  
using namespace std;
class Base
{
public:
	inline virtual void who()
	{
		cout << "I am Base\n";
	}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	inline void who()  // 不写inline时隐式内联
	{
		cout << "I am Derived\n";
	}
};

int main()
{
	// 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。 
	Base b;
	b.who();

	// 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。  
	Base *ptr = new Derived();
	ptr->who();

	// 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
	delete ptr;
	ptr = nullptr;

	system("pause");
	return 0;
} 
```

</details>

### assert()

断言，是宏，而非函数。assert 宏的原型定义在 `<assert.h>`（C）、`<cassert>`（C++）中，其作用是如果它的条件返回错误，则终止程序执行。可以通过定义 `NDEBUG` 来关闭 assert，但是需要在源代码的开头，`include <assert.h>` 之前。

<details><summary>assert() 使用</summary> 

```cpp
#define NDEBUG          // 加上这行，则 assert 不可用
#include <assert.h>

assert( p != NULL );    // assert 不可用
```

</details>

### sizeof()

* sizeof 对数组，得到整个数组所占空间大小。
* sizeof 对指针，得到指针本身所占空间大小。


### C++ 中 struct 和 class

总的来说，struct 更适合看成是一个数据结构的实现体，class 更适合看成是一个对象的实现体。

#### 区别

* 最本质的一个区别就是默认的访问控制
    1. 默认的继承访问权限。struct 是 public 的，class 是 private 的。  
    2. struct 作为数据结构的实现体，它默认的数据访问控制是 public 的，而 class 作为对象的实现体，它默认的成员变量访问控制是 private 的。

### C 实现 C++ 类

> [C 语言实现封装、继承和多态](http://dongxicheng.org/cpp/ooc/)

### explicit（显式）关键字

* explicit 修饰构造函数时，可以防止隐式转换和复制初始化
* explicit 修饰转换函数时，可以防止隐式转换，但 [按语境转换](https://zh.cppreference.com/w/cpp/language/implicit_conversion) 除外

<details><summary>explicit 使用</summary> 

```cpp
struct A
{
	A(int) { }
	operator bool() const { return true; }
};

struct B
{
	explicit B(int) {}
	explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main()
{
	A a1(1);		// OK：直接初始化
	A a2 = 1;		// OK：复制初始化
	A a3{ 1 };		// OK：直接列表初始化
	A a4 = { 1 };		// OK：复制列表初始化
	A a5 = (A)1;		// OK：允许 static_cast 的显式转换 
	doA(1);			// OK：允许从 int 到 A 的隐式转换
	if (a1);		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a6（a1）;		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a7 = a1;		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a8 = static_cast<bool>(a1);  // OK ：static_cast 进行直接初始化

	B b1(1);		// OK：直接初始化
	B b2 = 1;		// 错误：被 explicit 修饰构造函数的对象不可以复制初始化
	B b3{ 1 };		// OK：直接列表初始化
	B b4 = { 1 };		// 错误：被 explicit 修饰构造函数的对象不可以复制列表初始化
	B b5 = (B)1;		// OK：允许 static_cast 的显式转换
	doB(1);			// 错误：被 explicit 修饰构造函数的对象不可以从 int 到 B 的隐式转换
	if (b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
	bool b6(b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
	bool b7 = b1;		// 错误：被 explicit 修饰转换函数 B::operator bool() 的对象不可以隐式转换
	bool b8 = static_cast<bool>(b1);  // OK：static_cast 进行直接初始化

	return 0;
}
```

</details>

### friend 友元类和友元函数

* 能访问私有成员  
* 破坏封装性
* 友元关系不可传递
* 友元关系的单向性
* 友元声明的形式及数量不受限制

### using

#### using 声明

一条 `using 声明` 语句一次只引入命名空间的一个成员。它使得我们可以清楚知道程序中所引用的到底是哪个名字。如：

```cpp
using namespace_name::name;
```

#### 构造函数的 using 声明

在 C++11 中，派生类能够重用其直接基类定义的构造函数。

```cpp
class Derived : Base {
public:
    using Base::Base;
    /* ... */
};
```

如上 using 声明，对于基类的每个构造函数，编译器都生成一个与之对应（形参列表完全相同）的派生类构造函数。生成如下类型构造函数：

```cpp
derived(parms) : base(args) { }
```

#### using 指示

`using 指示` 使得某个特定命名空间中所有名字都可见，这样我们就无需再为它们添加任何前缀限定符了。如：

```cpp
using namespace_name name;
```

### 面向对象

面向对象程序设计（Object-oriented programming，OOP）是种具有对象概念的程序编程典范，同时也是一种程序开发的抽象方针。

![面向对象特征](images/面向对象基本特征.png)

面向对象三大特征 —— 封装、继承、多态

### 封装

把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。关键字：public, protected, private。不写默认为 private。

* `public` 成员：可以被任意实体访问
* `protected` 成员：只允许被子类及本类的成员函数访问
* `private` 成员：只允许被本类的成员函数访问

### 继承

* 基类（父类）——&gt; 派生类（子类）

### 多态

* 多态，即多种状态（形态）。简单来说，我们可以将多态定义为消息以多种形式显示的能力。
* 多态是以封装和继承为基础的。
* C++ 多态分类及实现：
    1. 重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
    2. 子类型多态（Subtype Polymorphism，运行期）：虚函数
    3. 参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
    4. 强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换

> [The Four Polymorphisms in C++](https://catonmat.net/cpp-polymorphism)


### 虚析构函数

虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。

<details><summary>虚析构函数使用</summary> 

```cpp
class Shape
{
public:
    Shape();                    // 构造函数不能是虚函数
    virtual double calcArea();
    virtual ~Shape();           // 虚析构函数
};
class Circle : public Shape     // 圆形类
{
public:
    virtual double calcArea();
    ...
};
int main()
{
    Shape * shape1 = new Circle(4.0);
    shape1->calcArea();    
    delete shape1;  // 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
    shape1 = NULL;
    return 0；
}
```

</details>

### 内存分配和管理

#### malloc、calloc、realloc、alloca

1. malloc：申请指定字节数的内存。申请到的内存中的初始值不确定。
2. calloc：为指定长度的对象，分配能容纳其指定个数的内存。申请到的内存的每一位（bit）都初始化为 0。
3. realloc：更改以前分配的内存长度（增加或减少）。当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定。
4. alloca：在栈上申请内存。程序在出栈的时候，会自动释放内存。但是需要注意的是，alloca 不具可移植性, 而且在没有传统堆栈的机器上很难实现。alloca 不宜使用在必须广泛移植的程序中。C99 中支持变长数组 (VLA)，可以用来替代 alloca。

#### malloc、free

用于分配、释放内存

<details><summary>malloc、free 使用</summary> 

申请内存，确认是否申请成功

```cpp
char *str = (char*) malloc(100);
assert(str != nullptr);
```

释放内存后指针置空

```cpp
free(p); 
p = nullptr;
```

</details>

#### new、delete

1. new / new[]：完成两件事，先底层调用 malloc 分了配内存，然后调用构造函数（创建对象）。
2. delete/delete[]：也完成两件事，先调用析构函数（清理资源），然后底层调用 free 释放空间。
3. new 在申请内存时会自动计算所需字节数，而 malloc 则需我们自己输入申请内存空间的字节数。

<details><summary>new、delete 使用</summary> 

申请内存，确认是否申请成功

```cpp
int main()
{
    T* t = new T();     // 先内存分配 ，再构造函数
    delete t;           // 先析构函数，再内存释放
    return 0;
}
```

</details>

### 指针和const的用法
1)	当const修饰指针时，由于const的位置不同，它的修饰对象会有所不同。
2)	int *const p2中const修饰p2的值,所以理解为p2的值不可以改变，即p2只能指向固定的一个变量地址，但可以通过*p2读写这个变量的值。顶层指针表示指针本身是一个常量
3)	int const *p1或者const int *p1两种情况中const修饰*p1，所以理解为*p1的值不可以改变，即不可以给*p1赋值改变p1指向变量的值，但可以通过给p赋值不同的地址改变这个指针指向。底层指针表示指针所指向的变量是一个常量。
4)	int const * const p;

### map、set是怎么实现的，红黑树是怎么能够同时实现这两种容器？ 为什么使用红黑树？
1)	他们的底层都是以红黑树的结构实现，因此插入删除等操作都在O(logn)时间内完成，因此可以完成高效的插入删除；
2)	在这里我们定义了一个模版参数，如果它是key那么它就是set，如果它是map，那么它就是map；底层是红黑树，实现map的红黑树的节点数据类型是key+value，而实现set的节点数据类型是value
3)	因为map和set要求是自动排序的，红黑树能够实现这一功能，而且时间复杂度比较低。

### 说说你对c和c++的看法，c和c++的区别？
1)	第一点就应该想到C是面向过程的语言，而C++是面向对象的语言，一般简历上第一条都是熟悉C/C++基本语法，了解C++面向对象思想，那么，请问什么是面向对象？
2)	C和C++动态管理内存的方法不一样，C是使用malloc/free函数，而C++除此之外还有new/delete关键字；（关于malooc/free与new/delete的不同又可以说一大堆，最后的扩展_1部分列出十大区别）；
3)	接下来就不得不谈到C中的struct和C++的类，C++的类是C所没有的，但是C中的struct是可以在C++中正常使用的，并且C++对struct进行了进一步的扩展，使struct在C++中可以和class一样当做类使用，而唯一和class不同的地方在于struct的成员默认访问修饰符是public,而class默认的是private;
4)	C++支持函数重载，而C不支持函数重载，而C++支持重载的依仗就在于C++的名字修饰与C不同，例如在C++中函数int fun(int ,int)经过名字修饰之后变为 _ fun_int_int ,而C是 
_ fun，一般是这样的，所以C++才会支持不同的参数调用不同的函数；
5)	C++中有引用，而C没有；这样就不得不提一下引用和指针的区别（文后扩展_2）;
6)	当然还有C++全部变量的默认链接属性是外链接，而C是内连接；
7)	C 中用const修饰的变量不可以用在定义数组时的大小，但是C++用const修饰的变量可以（如果不进行&,解引用的操作的话，是存放在符号表的，不开辟内存）；
8)	当然还有局部变量的声明规则不同，多态，C++特有输入输出流之类的，很多，下面就不再列出来了； 
