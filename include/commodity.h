#ifndef _COMMODITY_H_
#define _COMMODITY_H_

//常量定义
#define SIZE 20

enum judge
{
	ERROR = -1,
	OK,
};


//类型定义
struct goods 
{
	char name [SIZE];
	int num;
	float price;
};

typedef struct goods dataType;

//定义一个结构体
typedef struct list
{
	dataType data;
	struct list *pNext;
}LIST;

LIST lis;

//全局变量声明

//函数声明
/*
函数名：creation
函数功能：创建一个空结点
函数参数：无
函数返回值：创建成功返回结点的地址，失败返回NULL
*/
LIST * creation ( );


/*
函数名：insert
函数功能：添加商品信息
函数参数： 
		LIST *pList 链表的首地址		
函数返回值：添加成功返回0，失败返回-1
*/
int insert ( LIST * pList );


/*
函数名：delDate
函数功能：删除商品信息
函数参数：LIST *pList 链表的首地址	
函数返回值：删除成功返回0，失败返回-1
*/
int delDate ( LIST * pList );


/*
函数名：findData
函数功能：查找数据的信息
函数参数： 
		LIST *pList 链表的首地址
函数返回值：查找成功返回 0,失败返回 -1
*/
int findData ( LIST *pList );


/*
函数名：update
函数功能：修改商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：修改成功返回 0,失败返回 -1
*/

int update ( LIST *pList );



/*
函数名：destory
函数功能：销毁商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void destory ( LIST *pList );



/*
函数名：menu
函数功能：菜单的显示，所选选项
函数参数： 无
函数返回值：返回所输入的选项
*/

int menu ( );


/*
函数名：goodsKinds
函数功能：查看商品的种类
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

int goodsKinds ( LIST *pList );



/*
函数名：saveData
函数功能：保存数据
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void saveData ( LIST *pList );



/*
函数名：readData
函数功能：读取数据
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void readData ( LIST *pList );


#endif //_COMMODITY_H_