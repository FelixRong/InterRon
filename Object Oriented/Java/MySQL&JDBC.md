* JDBC
* JAVA Database Connectivity java数据库连接
* SUN公司提供的一种数据库访问规则、规范

* 基本步骤
	* 1、注册驱动
	* 2、建立连接
	* 3、创建Statement
	* 4、执行sql，得到ResultSet
	* 5、遍历结果集
	* 6、释放资源
```bash
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Connection con=null;
		Statement st=null;
		ResultSet rs=null;
		try {
			//1、注册驱动
			DriverManager.registerDriver(new com.mysql.jdbc.Driver());
			//2、建立连接
			con=DriverManager.getConnection("jdbc:mysql://localhost/Student", "root", "3451");
			//3、创建Statement,跟数据库打交道，一定需要这个对象
			st=con.createStatement();
			//4、执行查询
			String sql="select * from t_stu";
			rs=st.executeQuery(sql);
			//5、遍历结果集
			while(rs.next()) {
				int id=rs.getInt("id");
				String str=rs.getString("name");
				int age=rs.getInt("age");
				System.out.println(id+"..."+str+"..."+age);
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			//6、释放资源
			try {
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				st.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				con.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
```
* 1、注册驱动，Driver这个类里面有静态代码块，已经执行了，等同于我们注册了两次驱动。
	* DriverManager.registerDriver(new com.mysql.jdbc.Driver());
	* Class.forName("com.mysql.jdbc.Driver");


## CRUD
* insert
	* INSERT INTO t_stu (name,age) VALUES('zhang',19)
* delete
	* DELETE FROM t_stu WHERE id=1
* query
	* SELECT * FROM t_stu
* update
	* UPDATE t_stu SET age=39 WHERE id=1

