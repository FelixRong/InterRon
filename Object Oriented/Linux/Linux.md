* Linux目录结构
	* 只有一个目录，根目录
	* usr:存放共享的系统资源，相当于program files
	* root：超级用户根目录
	* home:存放其他用户目录
	* bin：存放二进制可执行文件
	* sbin：只有root才能访问，二进制可执行文件
	* etc：系统配置文件存放目录，不建议在此目录下存放可执行文件

* 命令
	* cd/：切换到跟目录
	* pwd：打印当前目录
	* ll：查看当前目录下的内容
	* mkdir：创建目录
		* mkdir -pv c/d/e    //生成一系列目录
	* . :当前目录
	* clear：清除屏幕
	* more：分页显示文件内容 	more a.txt
	* cp：复制文件或目录。
* 复制目录(无论是单层目录还是多层目录都可以复制):
	* cp  -r  ./a  ./b
	* cp  -r  /root/a  /root/z

* mv剪切文件
	* mv  /root/install.log  /root/a/
* 重命名文件
	* mv  /root/install.log  /root/test.log
* 删除文件
	* rm -f  文件名称
	* rm -f  /root/文件名称
* 删除目录
	* rm -rf 目录名称
	* rm -rf  /root/目录名称
* vim
	* vim 文件名
	* i 为插入内容
	* esc：退出插入模式到一般模式
	* ：wq：写入内容到文件