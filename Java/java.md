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

面向对象（多态）
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
class Cat extends Animal{ //1、继承关系
	public void eat() { //2、方法重写
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