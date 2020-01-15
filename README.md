# goods
## 商品管理系统

*编程语言：C语言*
### 所实现的功能：
		1. 添加商品信息（name，number，price）
		2. 删除指定商品信息
		3. 查找只读商品信息
		4. 修改指定商品信息
		5. 查看所有商品信息
		6. 销毁所有商品信息
		7. 退出系统
编程原理：
	1. 基于链表的知识，对数据的增删查改
	2. 利用文件io （read，write）对数据的保存，和读取
#### 项目目的
加深对链表存储数据的理解

#### 项目体会
	**特点**：数据的保存，可以在链表销毁的同时，做到对数据的保存，防止了内存泄漏 

#### 程序运行
- 在linux 系统下 执行Makefile 命令 在bin目录下会生成一个 commodity 可执行程序直接运行就可以了（在终端输入 ./commodity）