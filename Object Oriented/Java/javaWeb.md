## XML
* Extensible Markup Language(可扩展标记语言)
	* 1、保存数据
	* 2、用做配置文件
	* 3、数据传输载体

* 1、文档声明 

* 所有 XML 文档中的文本均会被解析器解析。
* 只有 CDATA 区段（CDATA section）中的文本会被解析器忽略。

## JSP
* Java Server Page
* 从程序上看是一个java类，它继承了servlet。

* jsp动作标签
```bash
<jsp:include page="other.jsp"></jsp:include> 包含
<jsp:forward page="other.jsp"></jsp:forward> 前往
```

## jsp内置对象
pageContext
request
session
application

out
exception
page
config
response

## EL
* 为了简化jsp代码，主要是java代码
* ${表达式}

## JSTL
* JSP Standard Tag Library 	JSP标准标签库

## 事务
* Transaction 指一组操作，里面包含许多单一的逻辑，只要有一个逻辑没有执行成功，就算失败，数据回归最初状态（回滚）
* 为了确保逻辑的成功。如银行转账

## 数据库连接池
先在内存中开辟一块空间，往池子里放置多个连接对象，需要连接直接从池子里去，不需要自己创建连接。使用完毕后，归还连接，确保连接对象能循环使用

## MVC
M：model 模型层，封装数据java bean
V：view  视图层，jsp显示
C：Controller 控制层，Servlet接收页面请求，找模型层处理，响应数据


## CRUD
* insert
	* INSERT INTO t_stu (name,age) VALUES('zhang',19)
* delete
	* DELETE FROM t_stu WHERE id=1
* query
	* SELECT * FROM t_stu
* update
	* UPDATE t_stu SET age=39 WHERE id=1

## Dao模式
* Data Access Object 数据访问对象

## Servlet
一个java程序，运行在我们web服务器上，用于接收和响应客户端的http请求。
是一个接口，Interface Servlet

1、找到tomcat应用
2、找到项目
3、找web.xml，找到url-pattern元素
4、找到servlet-mapping元素中的servlet-name
5、servlet元素的servlet-name
7、找servlet-class，创建该类的实例