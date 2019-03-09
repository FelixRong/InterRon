* JRE:JVM+类库 Java Runtime Environment Java运行环境
* JDK:JRE+JAVA的开发工具
* JRE：包括java虚拟机（JVM）和java程序所需的核心类库等，如果想运行一个开发好的java程序，计算机中只需要安装JRE即可。
* JDK是提供给java开发人员使用的，其中包含了java的开发工具，也包括JRE。
* 编译工具（javac.exe） 打包工具（jar.exe）
* 单引号‘’ ：中放单个数字，单个字母，单个符号。

//----------------------------------------------
## char 可以存储单个中文 java采用的是Unicode编码

* ++ 、 --
```bash
int a=3;
int b;
b=a++;
```
此时，a=4,b=3

* return 返回，作用：不是结束循环的，而是结束方法的。

## 数组：存储同一数据类型多个元素的集合。
```bash
int[] arr=new int[5];
System.out.println(arr.length); 数组中的length是属性
System.out.println(arr);//[I@15db9742
```
* [ 为数组
* I 为int
* @ 固定
* 15db9742 16进制的地址值

* new int[5] 在堆里开辟连续空间，且有个地址值，每个都有个索引，把地址值赋给栈中的变量名

* byte\short\int\long 默认为0
* float、double 默认为0.0
* Boolean 默认为false
* char 默认为\u0000

## static 
* 静态方法中没有this关键字（静态随着类的加载而加载，this随着对象的创建而存在），静态方法只能访问静态的成员变量和静态的成员方法
* 非静态的都可以

* 静态变量和成员变量
	* 1、静态变量属于类，成员变量属于对象
	* 2、内存中的位置不同，静态变量存储于方法的静态区，成员变量存储于堆内存
	* 3、内存出现时间不同，静态变量随着类的加载而加载，随着类的消失而消失；成员变量随着对象的创建而存在，随着对象的消失而消失。
	* 4、调用不同，静态变量可以通过类名调用，也可以通过对象调用。成员变量只能通过对象名调用

## 继承的好处：
	* 1、提高了代码的复用性和可维护性
	* 2、让类与类之间产生了关系，是多态的前提
## 弊端：
	* 类的耦合性增强了

* 1、构造代码块 每创建一次对象就会执行一次，优先于构造函数执行
* 2、静态代码块：随着类的加载而加载，且只执行一次，作用给类进行初始化，一般用来加载驱动。优先于主方法执行，也优先于构造代码块

## 继承的特点
* java中只支持单继承，不支持多继承。支持多重继承 extends
* 继承注意：
	* 子类只能继承父类所有非私有成员
	* 子类不能继承父类的构造方法，但可以通过super关键字去访问父类的构造方法

* 子类中所有的构造方法默认都会访问父类中空参数的构造方法。系统会在子类所有的构造函数（无参或有参）中默认添加super()，用来访问父类中的空参构造函数。因为子类继承父类的数据，在子类初始化之前，一定要先完成父类数据的初始化

## this/super
* 1、this 既可以调用本类也可以调用父类（本类没有的情况）
* 2、super 调用父类的成员。可以添加参数调用父类的有参构造
* 3、this("zzz",20);// 本类的有参构造
* 4、super("zzz",20);// 父类的有参构造
* 5、且俩只能同时存在一个，且在构造方法的第一个语句
```bash
Z z=new Z();
z.print();
z.method();

class F{
	public void print() {
		System.out.println("Fu print");
	}
}
class Z extends F{
	public void method() {
		System.out.println("zi method");
	}
	public void print() {// 重写父类方法
		super.print();
		System.out.println("Zi print");
	}
}
```

* 重写注意：
	* 1、父类中私有方法不能被重写，因为私有方法不能继承
	* 2、子类重写父类方法时，访问权限不能更低
	* 3、父类静态方法，子类也必须通过静态方法进行重写
* Override 重写 子类中出现了和父类中方法声明一模一样的方法。与返回值类型无关，返回值一致
* Overload 重载 本类中出现的方法名一样，参数列表不同的方法，与返回值类型无关

## final：
	* 1、修饰变量，变量就变成了常量，只能赋值一次 public static final double PI=3.14
	* 2、修饰方法，方法不能被重写
	* 3、修饰类，类不能被继承
```bash 
final class M{// 错误，修饰类，类不能被继承
	public void print() {
		System.out.println("M");
	}
}
class T extends M{
	public void print() {
		System.out.println("T");
	}
}
```
```bash
class M{
	public final void print() { //修饰方法，方法不能被重写
		System.out.println("M");
	}
}
class T extends M{
	public void print() {
		System.out.println("T");
	}
}
```

## 面向对象（多态）---------------
* 事物存在的多种形态
* 多态前提:
	* 1、要有继承关系
	* 2、要有方法重写
	* 3、要有父类引用指向子类对象
```bash
public class 多态 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c=new Cat();
		c.eat();
		
		Animal a=new Cat(); // 3、父类引用指向子类对象
		a.eat();
	}
}
class Animal{
	public void eat() {
		System.out.println("动物吃");
	}
}
class Cat extends Animal{ 			//1、继承关系
	public void eat() { 			//2、方法重写
		System.out.println("猫吃");
	}
}
```
* Father f=new Son();
	* 1、访问成员变量时候，编译看左边（父类），执行看左边（父类）中的变量
	* 2、访问成员方法时候，编译看左边（父类），执行看右边（子类）中的变量
	* 3、访问静态方法时候，编译看左边（父类），执行看左边（父类）中的变量

* 只有非静态的成员方法，编译看左边，运行看右边

-------------------
* 多态中的向上转型和向下转型  
	* 1、父类引用指向子类对象就是向上转型 Father f=new Son();
	* 2、向下转型  Son s=(Son)f

* 多态好处和弊端
	* 好处：提高了代码的维护性（继承保证）和扩展性(多态保证)
	* 弊端：不能使用子类的特有属性和行为


## 面向对象（抽象类）------------------
* 特点：
	* 1、抽象类和抽象方法必须用abstract关键字修饰
	* 2、抽象类不一定有抽象方法，有抽象方法的类一定是抽象类或者是接口
	* 3、抽象类不能实例化，所以抽象类必须被继承，才能被使用
 		* 按照多态的方式，由具体的子类实例化，这也是多态的一种，抽象类多态
	* 4、抽象类的子类 要么是抽象类 要么重写抽象类中的所有抽象方法
	* 5、抽修方法的具体实现由它的子类确定。如果一个类包含抽象方法，那么该类必须是抽象类。
	* 6、任何子类必须重写父类的抽象方法，或者声明自身为抽象类。
	* 7、abstract不能和final与static、private共存  final修饰的方法不能重写
```bash
abstract class 类名{}
public abstract void print();
```

```bash
B b=new B();

abstract class AAS{
	public abstract void eat();
}

class B extends AAS{
	public void eat() {
		System.out.println("eat");
	}
}
```

## 面向对象（接口）------------------
* interface
* 从广义上讲对外提供规则的都是接口
	* 1、interface 接口名{}
	* 2、类实现接口用implements表示
		* class 类名 implements 接口名{}
	* 3、接口不能实例化，按照多态的方式实例化
	* 4、接口中所有的方法必须是抽象方法。（默认会加上abstract）,在实现接口的类中重写
	* 5、接口没有构造方法。
	* 6、接口不能包含成员变量，除了 static 和 final 变量。
```bash 
public class interface_class {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Inter i=new Demo1();// 父类引用指向子类对象
		i.print();
		System.out.println(Inter.num);
		System.out.println(i.num);
	}

}
interface Inter{
	public abstract void print();//接口中必须是抽象方法
	final int num=10;
}
class Demo1 implements Inter{
	public void print() { // 必须重写
		System.out.println("Inter");
	}
}
```

## 类与接口

* 1、类与类
	* 继承关系，只能单继承或多重继承
* 2、类与接口
	* 实现关系，单实现、多实现
	* 继承一个类的同时实现多个接口
* 3、接口与接口
	* 继承关系，单继承、多继承
```bash
public class interface_class {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InterA i=new Demo1();
		i.printA();

		Demo1 d=new Demo1();
		d.printB();
	}

}
interface InterA{
	public abstract void printA();//接口中必须是抽象方法
}
interface InterB{
	public abstract void printB();//接口中必须是抽象方法
}
interface InterC extends InterA,InterB{
	public abstract void printC();//接口中必须是抽象方法
}
class Demo1 implements InterA,InterB{
 	public void printA() {
		System.out.println("InterA");
	}
	public void printB() {
		System.out.println("InterB");
	}
}
``` 

## package----------------
* package com.hello;
	* 1、必须是程序的第一条可执行代码
	* 2、一个java文件中只能有一个

* javac -d . demo.java
* java com.zhang.demo



## 内部类
* 内部类可以直接访问外部类的成员，包括私有
* 外部类要访问内部类成员，必须创建对象
```bash
public class demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Outer.Inner i=new Outer().new Inner();// 创建对象方法
		i.print();
	}

}
class Outer{
	private int num=10;
	class Inner{
		public void print() {
			System.out.println(num);
		}
	}
}
```

## 封装：
* 指隐藏对象的属性和实现细节，仅对外提供公共访问方式
* private 只能在本类中访问

* jar 是多个class文件的压缩包
* 可以使用别人写好的东西

API Application Programming Interface

## Object类
	* 类层次结构的根类
	* 所有类都直接或间接继承自该类
```bash
public String toString(){
	return getClass().getName()+"@"+Integer.toHexString(hashCode()); // 调用后显示的不是这种，说明被重写了
}
```
* hashCode()// 返回该对象的哈希码值 结果为int
```bash
Object obj=new Object();
int hashCode=obj.hashCode();
System.out.println(hashCode);
或
Student s=new Student("zzz",19);
System.out.println(s.hashCode());
```

* getClass()// 返回此Object的运行时类 返回class
```bash
Student s=new Student("zzz",19);
Class cl=s.getClass();   
System.out.println(cl);  // 获取该对象的字节码文件 class com.zhang.bean.Student
String str=cl.getName(); 
System.out.println(str); // 获取对象名字 com.zhang.bean.Student
```

* toString()// 返回该对象的字符串表示
```bash
//重写
public String toString() {
	return "我的姓名是"+name+",我的年龄是"+age;
}
```

* equals() //  指示其他某个对象是否与此对象" 相等 "
```bash
public boolean equals(Object obj){
	return (this==obj);
}
```
* Object 中的equals方法是比较对象的地址值的，没有什么意义，需要重写，在开发中通常比较的是对象中的属性值，我们认为相同属性是同一个对象

## == 和equals方法区别
* 共同点：都可以做比较，返回值都是boolean
* 区别
	* 1、==是比较运算符，既可以比较基本数据类型，也可以比较引用数据类型，基本数据类型比较的是值，引用数据类型比较的是地址值。
	* 2、equals方法只能比较的是引用数据类型。在没重写之前，比较的是地址值，底层依赖的是==号，但是比较地址值是没有意义的，我们需要重写equals方法，比较对象中的属性值（内容）。
```bash
public boolean equals(Object obj) {
	Student s=(Student)obj;
	return this.name.equals(s.name) && this.age==s.age ;
}
```
```bash
String s1="abc";
String s2="abc";
System.out.println(s1==s2); //常量池中没有这个字符串，就创建一个，有直接用。
//将此字符串与指定的对象比较。当且仅当该参数不为 null，并且是与此对象表示相同字符序列的 String 对象时，结果才为 true。
System.out.println(s1.equals(s2));
```

## Scanner
```bash
Scanner sc=new Scanner(System.in);
	if(sc.hasNextInt()) { // 若输入的为int 返回true
		int i=sc.nextInt();// 键盘录入一个整数
		System.out.println(i);
	}else {
		System.out.println("输入类型错误");
	}
```

* 两个常用的方法
* public int nextInt() // 获取一个int类型的值  键盘录入整数，当我们录完之后会自动加入\r\n。nextInt只获取值后就结束了

* public String nextLine() // 获取一个String类型的值。键盘接收字符串，可以接收任何类型。通过\r\n证明一行结束。
```bash
Scanner sc_str=new Scanner(System.in);
String str=sc_str.nextLine();
System.out.println(str);
```
* 可以使用nextLine() 再把数字字符串转换为数字


## String
```bash
String str="abc";
System.out.println(str);//默认调用toString()。且是重写的toString方法，返回该对象本身
```
* 会产生2个对象，新创建的字符串是该参数字符串的副本。一个在常量池中，在堆中创建一个副本。

### ==和equals()
```bash
System.out.println(s1.equalsIgnoreCase(s3)); // 比较字符串内容是否相同，不区分大小写
```
```bash
String s1="abc";
String s2="abc";
System.out.println(s1==s2); //常量池中没有这个字符串，就创建一个，有直接用。 true
//将此字符串与指定的对象比较。当且仅当该参数不为 null，并且是与此对象表示相同字符序列的 String 对象时，结果才为 true。
System.out.println(s1.equals(s2)); // true 方法重写后，比较的是内容
```

```bash
String s1=new String("abc"); // 记录的是堆中的内存对象的地址值
String s2="abc";             // 记录的是常量池中的地址值
System.out.println(s1==s2); //常量池中没有这个字符串，就创建一个，有直接用。false( s1此时是堆中的字符串的副本 ) 
//将此字符串与指定的对象比较。当且仅当该参数不为 null，并且是与此对象表示相同字符序列的 String 对象时，结果才为 true。
System.out.println(s1.equals(s2)); // true
```

```bash
String s1="a"+"b"+"c"; 
String s2="abc";
System.out.println(s1==s2); //常量池中没有这个字符串，就创建一个，有直接用。 true java中有常量优化机制
//将此字符串与指定的对象比较。当且仅当该参数不为 null，并且是与此对象表示相同字符序列的 String 对象时，结果才为 true。
System.out.println(s1.equals(s2)); //true 
```

```bash
String s1="ab";
String s2="abc";
String s3=s1+"c";
System.out.println(s3==s2); //常量池中没有这个字符串，就创建一个，有直接用。 false s1为变量， s3用+连接，会在底层【堆中操作】产生StringBuffer对象（abc），使用toString()转换为String。
//将此字符串与指定的对象比较。当且仅当该参数不为 null，并且是与此对象表示相同字符序列的 String 对象时，结果才为 true。
System.out.println(s3.equals(s2)); //true
```

* boolean equals(Object obj):比较字符串的内容是否相同,区分大小写
* boolean equalsIgnoreCase(String str):比较字符串的内容是否相同,忽略大小写
* boolean contains(String str):判断大字符串中是否包含小字符串
* boolean startsWith(String str):判断字符串是否以某个指定的字符串开头
* boolean endsWith(String str):判断字符串是否以某个指定的字符串结尾
* boolean isEmpty():判断字符串是否为空。
```bash
String str1="zhangfanrong";
String str2="zhang";
String str3="z";
String str4="g";
System.out.println(str1.contains(str2));  // 判断大字符串中是否包含小字符串
System.out.println(str1.startsWith(str3)); // 是否以传入的字符串开头
System.out.println(str1.endsWith(str4));   // 是否以传入的字符串结尾
System.out.println(str1.isEmpty()); // 判断字符串是否为空
```

* ""是字符串常量，同时也是一个String类的对象，可以调用String类的方法
* null 是空常量，不能调用任何方法，否则会出现空指针异常，可以给任意的引用数据类型赋值

* length() 数组中是属性，String中是方法
* char charAt(int index) //根据索引获取对应位置的字符
* int indexOf(String str) // 返回指定字符在此字符串中第一次出现处的索引  如果不存在返回-1..
* int indexOf(String str,in fromIndex) // 返回指定字符串在此字符串中从指定位置后第一次出现的索引
* int lastIndexOf(String str,int fromIndex) // 从指定位置向前找
* String substring(int start,int end) //从指定位置开始到指定位置结束截取字符串。int end可不指定，则默认到末尾
```bash
System.out.println(str.substring(0,1));// 取首字符
```
```bash
for (int i = 0; i < strstr.length(); i++) {
	System.out.println(strstr.charAt(i));
}

for (int i = 0; i < arr.length; i++) {
	System.out.println(arr[i]);
}
```

* byte[] getBytes() // 把字符串转换为字节数组
* char[] toCharArray() // 把字符串转换为字符数组
* static String valueOf(char[] chs) //把字符数组转成字符串
* static String valueOf(int i) //把int类型的数据转成字符串  valueOf()可以把任意类型的数据转成字符串

* String toLowerCase() // 把字符串转成小写
* String toUpperCase() //把字符串转成大写
* String concat(String str) // 把字符串拼接
```bash
String str="zhang";
byte[] b=str.getBytes();
for (int i = 0; i < b.length; i++) {
	System.out.println(b[i]);
}
System.out.println(str.toUpperCase());
```
```bash
String str="zhang";
char[] c=str.toCharArray();
for (int i = 0; i < c.length; i++) {
		System.out.println(c[i]);
}
```
```bash
int i=9999;
String s=String.valueOf(i);
System.out.println(s);
```
```bash
String str1="zhang";
String str2="fanrong";
System.out.println(str.concat(str1));
```

* //替换
* String replace(char old,char new)
* String replace(String old,String new)
* //去除字符串两空格
* String trim()
* //按字典顺序比较两个字符串
* int compareTo(String str)
* int compareToIgnoreCase(String str)
```bash
String ss=" zhangfanrong ";
System.out.println(ss.replace('z', 'r'));
System.out.println(ss.replace("zhang", "nihao"));
System.out.println(ss.trim());
System.out.println(ss.compareTo(str1)); // 按照码表值逐个比较，a和aaa 则比较长度
```

## StringBuffer类
* 线程安全（效率低）的可变字符序列，一个类似于String的字符串缓冲区，但不能修改
* 每个字符串缓冲区都有一定的容量。只要字符串缓冲区所包含的字符序列的长度没有超出此容量，就无需分配新的内部缓冲区数组。如果内部缓冲区溢出，则此容量自动增大。从 JDK 5 开始，为该类补充了一个单个线程使用的等价类，即 StringBuilder。与该类相比，通常应该优先使用 StringBuilder 类，因为它支持所有相同的操作，但由于它不执行同步，所以速度更快。
* 与String的区别
	* String是一个不可变的字符序列，StringBuffer是一个可变的字符序列
```bash
StringBuffer sb2=new StringBuffer();
sb2.append(2); // 追加
System.out.println(sb2);

StringBuffer sb3=new StringBuffer("1234");
sb3.insert(2,"ad");
System.out.println(sb3); // 指定位置添加元素
sb3.deleteCharAt(2);// 删除指定位置字符
sb3.delete(1,2);// 删除从指定位置开始指定位置结束的内容
sb3.replace(1,3,"bai");// 用str替换
sb3.reverse(); // 反转
sb3.substring(1,4);// 截取字符串
```

## StringBuffer与StringBuilder
* StringBuffer是jdk1.0版本，是线程安全的，效率低
* StringBuilder是jdk1.5版本，线程不安全，效率高
* String是一个不可变的字符序列
* StringBuffer、StringBuilder是可变的字符序列

## Array
```bash
int[] arr= {1,2,9,7,2,3,4,5};
System.out.println(Arrays.toString(arr));
Arrays.sort(arr);
System.out.println(Arrays.toString(arr));
System.out.println(Integer.toBinaryString(99));
```
```bash
String ss="12 99 77 66";
String[] sArr=ss.split(" ");
int[] Arr=new int[sArr.length];
for (int i = 0; i < sArr.length; i++) {
	Arr[i]=Integer.parseInt(sArr[i]); //将数字字符串转换为数字
}
Arrays.sort(Arr);
for (int i = 0; i < Arr.length; i++) {
	System.out.println(Arr[i]);
}
```

### 为什么会有基本类型包装类
* 将基本数据类型封装成对象的好处在于可以在对象中定义更多的功能方法操作该数据
* 常用操作，用于基本数据类型与字符串之间的转换
* byte 		Byte
* short 	Short
* int 	 	Integer
* long 	 	Long
* float 	Float
* double 	Double
* char 		Character
* boolean 	Boolean

## Integer
* Integer 类在对象中包装了一个基本类型 int 的值。
* 该类提供了多个方法，能在int类型和String类型之间相互转换
* 还提供了处理int类型时非常有用的其他常量和方法

```bash
System.out.println(Integer.MAX_VALUE);
		
Integer i1=new Integer(100);
System.out.println(i1);
Integer i2=new Integer("120"); //为数字字符串
System.out.println(i2);
```
* JDK5新特性
	* 自动装箱：把基本类型转换为包装类类型
	* 自动拆箱：把包装类类型转换为基本类型
```bash
Integer i=100 // 自动装箱
int z=i+100;// 自动拆箱
```

## 正则表达式
* 是指一个用来描述或者匹配一系列符合某个语法规则的字符串的单个字符串。
* 作用：比如注册邮箱，对用户名密码限制长度。。

* [] 代表单个字符  [abc]:为a、b、c中任一个
* [^abc] 任何字符，除了a、b、c
* . 任何字符
* \d 数字 [0-9]
* \D 非数字[^0-9]
* \s 空白字符 [ \t\n\x0B\f\r]
* \S 非空白字符
* \w 单词字符 [a-zA-Z_0-9]
* \W 非单词字符

* 数量词
	* X？ 		X一次或一次也没有
	* X*  		X 零次或多次
	* X+  		X一次或多次
	* X{n} 		X恰好n次
	* X{n,} 	X至少n次
	* X{n,m} 	X至少n次，但不超过m次

```bash
String s="z.f.r";
String[] arr=s.split("\\.");
```

```bash
String str="zhang2fanrong";
String re="\\d";
String sss=str.replaceAll(re, ""); // 正则表达式的替换功能
System.out.println(sss);
```
### 分组
```bash
String regex="(.)\\1(.)\\2";			//\\1代表第一组又出现一次，\\2代表第二组又出现一次
System.out.println("快快乐乐".matches(regex));
```

## Date
* 是util包下的
```bash
Date dt1=new Date();
System.out.println(dt1);
System.out.println(dt1.getTime()); //获取毫秒值
dt1.setTime(1000); //设置毫秒值
Date dt2=new Date(0); // 0代表的是1970年1月1日
System.out.println(dt2);
```

## Collection

### 集合由来
* 数组长度是固定的，当添加的元素超过了数组的长度时需要对数组重新定义，java内部给我们提供了集合类，能存储任意对象，长度是可以改变的，随着元素的增加减少而增加减少

### 数组与集合的区别
* 1、数组既可以存储基本数据类型，也可以存储引用数据类型。基本数据类型存储的值，引用数据类型存储的是地址值
	* 集合只能存储引用数据类型（对象）
* 2、数组长度是固定的，不能自动增长
	* 集合的长度是可变的，可以根据元素增加而增长

* collection：
	* List（有序(存取顺序一致)，有索引，可以存储重复）：ArrayList(数组实现)、LinkedList(链表实现)、Vector(数组实现)
	* Set（无序，没索引，不可以存储重复）:HashSet（哈希算法）、TreeSet（二叉树算法）

```bash
public class Demo_collection {

	// add方法，如果是List集合，一直返回true，因为List集合中是可以存储重复元素的
	//如果是Set集合，当存储重复元素的时候，会返回false
	//ArrayList的父类的父类重写了toString方法。
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Collection c=new ArrayList();			//父类引用指向对象
		boolean b1=c.add("aaa");
		boolean b2=c.add("bbb");
		c.add(100);
		System.out.println(c.toString());
		System.out.println(b1);
		c.remove(100); 							//删除
		System.out.println(c.toString());
		System.out.println(c.contains("aaa"));	//是否包含aaa
		System.out.println(c.isEmpty()); 		//判断是否为空
		System.out.println(c.size());			//返回集合元素个数
		c.clear();								//清空集合
		System.out.println(c.toString());
	}
}
```
### list
```bash
public class Demo_List {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List list=new ArrayList();
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(1, 3);
		System.out.println(list);
		list.remove(1);					//通过索引删除元素
		System.out.println(list);
		Object obj=list.get(0);			//通过索引获取元素
		System.out.println(obj);
		
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));	//索引遍历
		}
		
		list.set(1, "a");				//修改指定位置元素值
		 
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));	//索引遍历
		}
	}
}
```

## 迭代器
* 集合是用来存储元素，存储的元素需要查看，需要迭代遍历
```bash
public class Demo_Iterator {
	public static void main(String[] args) {
		Collection c=new ArrayList();
		c.add(1);
		c.add(2);
		c.add(3);
	
		Iterator it=c.iterator();			//获取迭代器

		while(it.hasNext()) {				//判断集合中是否含有元素
			System.out.println(it.next());
		}
	}
}
```

## LinkedList
```bash
public class Demo_LinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList list=new LinkedList(); // 创建集合对象
		list.addFirst("a");
		list.addFirst("b");
		list.addFirst("c");
		list.addFirst("d");
		list.addFirst("a");
		
		list.addLast("v");
		System.out.println(list);
		
		System.out.println(list.getFirst());
		System.out.println(list.getLast());
		
		list.removeFirst();
		list.removeLast();
		System.out.println(list);
		
		System.out.println(list.get(1));
	}

}
```

## 泛型
* 泛型：一般类型，也就是说可以为任何类型，泛型的本质是“参数化类型”，也就是说所操作的数据类型被指定为一个参数。泛型是在JDK1.5中引入的特性。
* 好处：提高安全性，省去强转的麻烦
* 使用：<>中放的是引用数据类型

* 泛型类   class Person<T>{}
* 泛型接口	interface inter<T>{}
* 泛型通配符<?>	

## HashSet
* 得重写hashCode()和equals()方法才能实现元素唯一

## TreeSet
* 是用来对元素进行排序的，也保证元素的唯一。底层是二叉树
* 根据Comparable 接口的compareTo() 方法，升序排列

```bash
public class Demo_TreeSet {
	public static void main(String[] args) {
		TreeSet<Integer> ts=new TreeSet<Integer>();
		ts.add(10);
		ts.add(1);
		ts.add(1);
		ts.add(3);
		ts.add(5);
		ts.add(2);
		ts.add(7);
		System.out.println(ts);		//[1, 2, 3, 5, 7, 10]
	}
}
```
## TreeMap<K,V>
* 键值对
* 键不能重复
* 每个键只能映射一个值

```bash

```
## 异常
* try：检测异常
* catch：捕获异常
* finally：释放资源，一定会执行

### final/finally/finalize
* final 
	* 1、可以修饰类，不能被继承
	* 2、修饰方法，不能被重写
	* 3、修饰变量，只能赋值一次
* finally
	* 是try语句中的一个语句体，不能单独使用，用来释放资源
	* 如果catch里有return，finally依旧会执行
	* finalize
		* 当垃圾回收器确定不存在对该对象的更多引用时，由对象的垃圾回收器调用此方法

## 多线程
* 线程是程序执行的一条路径，一个进程中可以包含多条线程
* 多线程并发执行可以提高程序的效率，可以同时完成多项工作

### java程序运行原理
* java命令会启动java虚拟机，启动JVM，等于启动了一个应用程序，也就是启动了一个进程，该进程会自动启动一个“主线程”，然后主线程会调用某个类的main方法。
* JVM启动至少启动了垃圾回收线程和主线程，所以是多线程的

```bash
public class Demo_Thread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyThread mt=new MyThread();			//4、创建Thread 的子类
		//mt.run();
		mt.start();							//5、创建并启动一个线程///使该线程开始执行；Java 虚拟机调用该线程的 run 方法。
		
		for (int i = 0; i < 1000; i++) {
			System.out.println("bbbbb");
		}
	}

}
class MyThread extends Thread{ 				//1、继承
	public void run(){						//2、重写run方法
		for (int i = 0; i < 1000; i++) {	//3、执行代码
			System.out.println("aaaaa");
		}
	}
}
```

## 多线程(实现Runnable的原理)(了解)
* 查看源码
	* 1,看Thread类的构造函数,传递了Runnable接口的引用 
	* 2,通过init()方法找到传递的target给成员变量的target赋值
	* 3,查看run方法,发现run方法中有判断,如果target不为null就会调用Runnable接口子类对象的run方法

```bash
public class Demo_Runnable {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyRunnable mr=new MyRunnable();			//4、创建Runnable的子类
		Thread t=new Thread(mr);				//5、将Runnable的引用当作参数传递给Thread的构造函数  target参数
		t.start();								//6、开启线程
		for (int i = 0; i < 1000; i++) {
			System.out.println("bbbbb");
		}
	}

}
class MyRunnable implements Runnable{		//1、定义一个类实现Runnable

	@Override
	public void run() {						//2、重写run方法
		// TODO Auto-generated method stub
		for (int i = 0; i < 1000; i++) {	//3、执行代码
			System.out.println("aaaaa");
		}
	}
}
```
### 匿名类
```bash
public class Demo_Thread_neibulei {
	public static void main(String[] args) {
		new Thread() {													//new Thread("zzzz") 也可以这样设置名字
			public void run() {
				for (int i = 0; i < 1000; i++) {
					System.out.println(this.getName()+".............aaa");
				}
			}
		}.start();
	}

	//------------------------------------------
	Thread t1=new Thread("zzz") {
		public void run() {
			for (int i = 0; i < 1000; i++) {
				System.out.println(this.getName()+".............aaa");
			}
		}
	};
	t1.setName("zhang");
	t1.start();
}
```
### 两种多线程的区别
* 查看源码的区别:
	* a.继承Thread : 由于子类重写了Thread类的run(), 当调用start()时, 直接找子类的run()方法
	* b.实现Runnable : 构造函数中传入了Runnable的引用, 成员变量记住了它, start()调用run()方法时内部判断成员变量Runnable的引用是否为空, 不为空编译时看的是Runnable的run(),运行时执行的是子类的run()方法
	
* 继承Thread
	* 好处是:可以直接使用Thread类中的方法,代码简单
	* 弊端是:如果已经有了父类,就不能用这种方法
* 实现Runnable接口
	* 好处是:即使自己定义的线程类有了父类也没关系,因为有了父类也可以实现接口,而且接口是可以多实现的
	* 弊端是:不能直接使用Thread中的方法需要先获取到线程对象后,才能得到Thread的方法,代码复杂

## 休眠线程
* Thread.sleep(毫秒,纳秒), 控制当前线程休眠若干毫秒1秒= 1000毫秒 1秒 = 1000 * 1000 * 1000纳秒 1000000000

## 单例对象
* 保证类在内存中只有一个对象
```bash
// 饿汉式 
class Singleton{
	//1、私有构造函数，其他类不能访问该构造方法
	private Singleton() {}
	//2、创建私有本类对象 ,防止外界修改
	private static Singleton s=new Singleton();
	//3、对外提高公共的访问方法
	public static Singleton getInstance() {
		return s;
	}
}
```
```bash
//懒汉式 单例的延迟加载模式  多线程有安全隐患
class Singleton2 {
	//1,私有构造函数
	private Singleton2(){}
	//2,声明一个本类的引用
	private static Singleton2 s;
	//3,对外提供公共的访问方法
	public static Singleton2 getInstance() {
		if(s == null)
			//线程1,线程2
			s = new Singleton2();
		return s;
	}
	
	public static void print() {
		System.out.println("11111111111");
	}
}
```
* 饿汉式和懒汉式区别
	* 1、饿汉式是空间换时间，懒汉式是时间换空间
	* 2、在多线程访问时，饿汉式不会创建多个对象，而懒汉式有可能创建多个对象

## 网络编程
* 用来实现网络互联的不同计算机上运行的程序间可以进行数据交换
	* 端口：0-65535
	* mysql：3306
	* Oracle：1521

* UDP：面向无连接，数据不安全，速度快，不区分客户端和服务端（手机短信）
* TCP：面向连接（三次握手），数据安全，速度略低，分为客户端和服务端
	* 三次握手：客户端先向服务端发起请求，服务端响应请求，传输数据（手机打电话）

### Socket
* 网络上具有唯一标识的IP地址和端口号组合在一起才能构成唯一能识别的标识符套接字
* 通信的两端都有Socket
* 网络通信其实就是Socket间的通信
* 数据在两个Socket间通过 IO 流传输
* Socket在应用程序中创建，通过一种绑定机制与驱动程序建立联系，告诉自己所对应的IP和port

## 网络编程(UDP传输)(了解)
* 1.发送Send
	* 创建DatagramSocket, 随机端口号
	* 创建DatagramPacket, 指定数据, 长度, 地址, 端口
	* 使用DatagramSocket发送DatagramPacket
	* 关闭DatagramSocket
* 2.接收Receive
	* 创建DatagramSocket, 指定端口号
	* 创建DatagramPacket, 指定数组, 长度
	* 使用DatagramSocket接收DatagramPacket
	* 关闭DatagramSocket
	* 从DatagramPacket中获取数据
* 3.接收方获取ip和端口号
	* String ip = packet.getAddress().getHostAddress();
	* int port = packet.getPort();
	
## 网络编程(TCP协议)(掌握)
* 1.客户端
	* 创建Socket连接服务端(指定ip地址,端口号)通过ip地址找对应的服务器
	* 调用Socket的getInputStream()和getOutputStream()方法获取和服务端相连的IO流
	* 输入流可以读取服务端输出流写出的数据
	* 输出流可以写出数据到服务端的输入流
* 2.服务端
	* 创建ServerSocket(需要指定端口号)
	* 调用ServerSocket的accept()方法接收一个客户端请求，得到一个Socket
	* 调用Socket的getInputStream()和getOutputStream()方法获取和客户端相连的IO流
	* 输入流可以读取客户端输出流写出的数据
	* 输出流可以写出数据到客户端的输入流

## 反射
* JAVA反射机制是在运行状态中，对于任意一个类，都能知道这个类的所有属性和方法。
* 对于任意一个对象，通过字节码文件，都能够调用它的任意一个方法和属性
* 这种动态获取的信息以及动态调用对象的方法的功能成为java语言的反射机制
* 要想解剖一个类，必须先要获取该类的字节码文件对象。而解剖使用的就是Class类中的方法，所以先要获取到每一个字节码文件对象的class类型的对象

* 源文件阶段（Person.java) 	Class clazz=class.forName("类名")；
* 字节码阶段（Person.class）	Class clazz=Person.class;
* 创建对象阶段（Person p=new Person()）	Class clazz=p.getClass();  //判断是否是同一个字节码文件
```bash
public class Demo_Reflect {

	public static void main(String[] args) throws ClassNotFoundException {
		// TODO Auto-generated method stub
		//通过三种方式获取字节码对象
		Class clazz1=Class.forName("com.zhang.bean.Person");
		System.out.println(clazz1);
		
		Class clazz2=com.zhang.bean.Person.class;
		System.out.println(clazz2);
		
		com.zhang.bean.Person p=new Person();
		Class clazz3=p.getClass();
		System.out.println(clazz3);
	}

}
```
