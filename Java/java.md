JRE:JVM+类库 Java Runtime Environment Java运行环境
JDK:JRE+JAVA的开发工具
JRE：包括java虚拟机（JVM）和java程序所需的核心类库等，如果想运行一个开发好的java程序，计算机中只需要安装JRE即可。
JDK是提供给java开发人员使用的，其中包含了java的开发工具，也包括JRE。
编译工具（javac.exe） 打包工具（jar.exe）
单引号‘’ ：中放单个数字，单个字母，单个符号。

//----------------------------------------------
char 可以存储单个中文 java采用的是Unicode编码

++ 、 --
int a=3;
int b;
b=a++;
此时，a=4,b=3

return 返回，作用：不是结束循环的，而是结束方法的。

数组：存储同一数据类型多个元素的集合。
int[] arr=new int[5];
System.out.println(arr.length);
System.out.println(arr);//[I@15db9742
[ 为数组
I 为int
@ 固定
15db9742 16进制的地址值

new int[5] 在堆里开辟连续空间，且有个地址值，每个都有个索引，把地址值赋给栈中的变量名

byte\short\int\long 默认为0
float、double 默认为0.0
Boolean 默认为false
char 默认为\u0000

static 静态方法中没有this关键字，静态方法只能访问静态的成员变量和静态的成员方法
非静态的都可以

静态变量和成员变量
1、静态变量属于类，成员变量属于对象
2、内存中的位置不同，静态变量存储于方法的静态区，成员变量存储于堆内存
3、内存出现时间不同，静态变量随着类的加载而加载，随着类的消失而消失；成员变量随着对象的创建而存在，随着对象的消失而消失。
4、调用不同，静态变量可以通过类名调用，也可以通过对象调用。成员变量只能通过对象名调用

继承的好处：
1、提高了代码的复用性和可维护性
2、让类与类之间产生了关系，是多态的前提
弊端：
类的耦合性增强了

构造代码块 每创建一次对象就会执行一次，优先于构造函数执行
静态代码块：随着类的加载而加载，且只执行一次，作用给类进行初始化，一般用来加载驱动。优先于主方法执行，也优先于构造代码块

继承的特点“
java中只支持单继承，不支持多继承。支持多重继承 extends
继承注意：
1、子类只能继承父类所有非私有成员
2、子类不能继承父类的构造方法，但可以通过super关键字去访问父类的构造方法

子类中所有的构造方法默认都会访问父类中空参数的构造方法。系统会在子类所有的构造函数（无参或有参）中默认添加super()，用来访问父类中的空参构造函数。因为子类继承父类的数据，在子类初始化之前，一定要先完成父类数据的初始化

this/super
this 既可以调用本类也可以调用父类（本类没有的情况）
super 调用父类的成员。可以添加参数调用父类的有参构造
this("zzz",20);// 本类的有参构造
super("zzz",20);// 父类的有参构造
且俩只能同时存在一个，且在构造方法的第一个语句
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

重写注意：
1、父类中私有方法不能被重写，因为私有方法不能继承
2、子类重写父类方法时，访问权限不能更低
3、父类静态方法，子类也必须通过静态方法进行重写
Override 重写 子类中出现了和父类中方法声明一模一样的方法。与返回值类型无关，返回值一致
Overload 重载 本类中出现的方法名一样，参数列表不同的方法，与返回值类型无关

final：
1、修饰变量，变量就变成了常量，只能赋值一次 public static final double PI=3.14
2、修饰方法，方法不能被重写
3、修饰类，类不能被继承
```bash 
final class M{//修饰类，类不能被继承
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

面向对象（多态）---------------
事物存在的多种形态
多态前提:
1、要有继承关系
2、要有方法重写
3、要有父类引用指向子类对象
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
Father f=new Son();
访问成员变量时候，编译看左边（父类），执行看左边（父类）中的变量
访问成员方法时候，编译看左边（父类），执行看右边（子类）中的变量
访问静态方法时候，编译看左边（父类），执行看左边（父类）中的变量

只有非静态的成员方法，编译看左边，运行看右边

-------------------
多态中的向上转型和向下转型  
父类引用指向子类对象就是向上转型 Father f=new Son();
向下转型  Son s=(Son)f

多态好处和弊端
好处：提高了代码的维护性（继承保证）和扩展性(多态保证)
弊端：不能使用子类的特有属性和行为


面向对象（抽象类）------------------
特点：
1、抽象类和抽象方法必须用abstract关键字修饰
abstract class 类名{}
public abstract void print();
2、抽象类不一定有抽象方法，有抽象方法的类一定是抽象类或者是接口
3、抽象类不能实例化，所以抽象类必须被继承，才能被使用
 按照多态的方式，由具体的子类实例化，这也是多态的一种，抽象类多态
4、抽象类的子类 要么是抽象类 要么重写抽象类中的所有抽象方法
5、抽修方法的具体实现由它的子类确定。如果一个类包含抽象方法，那么该类必须是抽象类。
6、任何子类必须重写父类的抽象方法，或者声明自身为抽象类。
7、abstract不能和final与static、private共存  final修饰的方法不能重写
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

面向对象（接口）------------------
interface
从广义上讲对外提供规则的都是接口
1、interfa 接口名{}
2、类实现接口用implements表示
	class 类名 implements 接口名{}
3、接口不能实例化，按照多态的方式实例化
4、接口中所有的方法必须是抽象方法。（默认会加上abstract）,在实现接口的类中重写
5、接口没有构造方法。
6、接口不能包含成员变量，除了 static 和 final 变量。
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

类与类
	继承关系，只能单继承或多重继承
类与接口
	实现关系，单实现、多实现
	继承一个类的同时实现多个接口
接口与接口
	继承关系，单继承、多继承
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

package----------------
package com.hello;
1、必须是程序的第一条可执行代码
2、一个java文件中只能有一个

javac -d . demo.java
java com.zhang.demo



内部类
内部类可以直接访问外部类的成员，包括私有
外部类要访问内部类成员，必须创建对象
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