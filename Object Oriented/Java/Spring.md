前言：对于使用Spring框架的开发人员来说，我们主要做的主要有两件事情：①开发Bean;②配置Bean;而Spring帮我们做的就是根据配置文件来创建Bean实例，并调用Bean实例的方法来完成“依赖注入”，可以把Spring容器理解成一个大型工厂，Bean就是该工厂的产品，工厂(Spirng容器)里能生产出来什么样的产品（Bean），完全取决于我们在配置文件中的配置。

* Spring
	* JAVAEE一站式开发框架  有EE开发的每一层解决方案

* WEB层：		SpringMVC
* Service层：	Spring的Bean管理，Spring声明式事务
* DAO层：		Spring的JDBC模板，Spring的ORM模块（叫数据访问层，全称为data access object，属于一种比较底层，比较基础的操作，具体到对于某个表、某个实体的增删改查）

* 控制反转（Inversion of Control，缩写为IoC）
	* 将对象的创建权反转给Spring
	* 优势是分层架构
* AOP为Aspect Oriented Programming的缩写，意为：面向切面编程

## IOC
* 其思想是反转资源获取的方向。
* 传统的资源查找方式要求组件向容器发起请求查找资源，作为回应，容器实时的返回资源。而应用了IOC之后，则是容器主动地将资源推送给它所管理地组件，组件所要做的仅是选择一种合适的方式来接受资源，这种行为也被称为查找的被动形式。
* DI(Dependency Injection)依赖注入--IOC的另一种表述方式：即组件以一些预先定义好的方式（如setter方法）接受来自容器的资源注入。

* 在Spring IOC容器读取Bean配置创建Bean实例之前，必须对它进行实例化，只有在容器实例化后，才可以从IOC容器里获取Bean实例并使用
	* Spring提供了两种类型的IOC容器实现
	* BeanFactory：IOC容器的基本实现
	* ApplicationContext提供了更多的高级特性，是BeanFactory的子接口
	* BeanFactory是Spring框架的基础设施，面向Spring本身，
	* ApplicationContext 面向使用Spring框架的开发者，几乎所有的应用场合都直接使用ApplicationContext而非底层的BeanFactory

ApplicationContext 的主要实现类
ClassPathXmlApplicationContext：从类路径下加载配置文件
FileSystemXmlApplicationContext：从文件系统中加载配置文件
