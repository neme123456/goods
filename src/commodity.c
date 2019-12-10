#include "../include/commodity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
函数名：creation
函数功能：创建一个空结点
函数参数：无
函数返回值：创建成功返回结点的地址，失败返回NULL
*/

LIST * creation ( )
{
	//定义指针变量
	LIST *pList = NULL;
	//申请空间
	pList = ( LIST * ) malloc ( sizeof ( LIST ) );
	//判断，初始化
	if ( NULL == pList )
	{
		return NULL;
	}
	memset ( pList, 0, sizeof ( LIST ) );
	
	return pList;
}

/*
函数名：insert
函数功能：添加商品信息
函数参数： 
		LIST *pList 链表的首地址		
函数返回值：添加成功返回0，失败返回-1
*/

int insert ( LIST * pList )
{
	//判断链表是否存在
	if ( NULL == pList )
	{
		return ERROR;
	}
	//定义指针变量
	LIST *p =  creation ( );
	if ( NULL == p )
	{
		return ERROR;
	}
	
	//赋值
	printf ( "==请输入商品名称==\r\n" );
	scanf ( "%s", p->data.name );

	printf ( "==请输入商品数量==\r\n");
	scanf ( "%d", &p->data.num );
	
	printf ( "==请输入商品价格==\r\n");
	scanf ( "%f", &p->data.price );
	
	//头插法插入节点
	p->pNext = pList->pNext;
	pList->pNext = p;

	printf ( "商品 %s 已经添加成功\r\n", p->data.name );
	return OK;
}



/*
函数名：delDate
函数功能：删除商品信息
函数参数：LIST *pList 链表的首地址	
函数返回值：删除成功返回0，失败返回-1
*/
int delDate ( LIST * pList )
{
	
	//判断链表是否存在,是否为空
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需要删除的商品名称\r\n" );
	scanf ( "%s", str );
	
	//定义指针变量
	LIST *p = pList->pNext;
	LIST *q = pList;

	while ( NULL != p )
	{
		//查找商品，显示商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			q->pNext = p->pNext; 
			free ( p );
			p = NULL;
			printf ( "商品 %s 信息已被删除！！\r\n", str );
			return OK;
		}
		p = p->pNext;
		q = q->pNext;

	}
	
	printf ( "您输入的商品名称没有找到！！\r\n" );
	return ERROR;
}


/*
函数名：findData
函数功能：查找商品的信息
函数参数： 
		LIST *pList 链表的首地址
函数返回值：查找成功返回 OK,失败返回ERROR
*/
int findData ( LIST *pList )
{
	//判断链表是否存在,是否为空
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需要查找的商品名称\r\n" );
	scanf ( "%s", str );
	
	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找商品，显示商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			printf ( "商品的名称：%s\r\n", p->data.name );
			printf ( "商品的数量：%d\r\n", p->data.num );
			printf ( "商品的价格：%f\r\n", p->data.price );	
			return OK;
		}
		//更新结点
		p = p->pNext;
	}
	printf ( "输入的商品信息无效！！！\r\n" );
	return ERROR;
}


/*
函数名：update
函数功能：修改商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：修改成功返回 0,失败返回 -1
*/
int update ( LIST *pList )
{
	//判断链表是否存在,是否为空
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需修改的商品名称\r\n" );
	scanf ( "%s", str );
	
	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找商品，修改商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			
			printf ( "原商品的名称：%s\r\n", p->data.name );
			printf ( "请输入新的商品名称\r\n" );
			scanf ( "%s", p->data.name );
			
			printf ( "原商品的数量：%d\r\n", p->data.num );
			printf ( "请输入新的商品数量\r\n" );
			scanf ( "%d", &p->data.num );
			
			printf ( "原商品的价格：%f\r\n", p->data.price );	
			printf ( "请输入新的商品价格\r\n" );
			scanf ( "%f", &p->data.price );
			
			printf ( "商品信息修改成功 *_* \r\n" );
			return OK;
		}
		p = p->pNext;
	}
	
	
	printf ( "您输入的商品名称没有找到！！\r\n");
	return ERROR;
}

/*
函数名：menu
函数功能：菜单的显示，所选选项
函数参数： 无
函数返回值：返回所输入的选项
*/
int menu ( )
{
	//菜单
	printf ( "	==欢迎来到商品管理系统===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------增加商品信息\r\n" );
	printf ( "  2-------------------删除商品信息\r\n" );
	printf ( "  3-------------------查找商品信息\r\n" );
	printf ( "  4-------------------修改商品信息\r\n" );
	printf ( "  5-------------------查看商品种类列表\r\n" );
	printf ( "  6-------------------销毁所有商品信息！\r\n" );
	printf ( "  7-------------------退出系统！\r\n" );
	printf ( "*******************************************\r\n");
	//输入选项
	printf ( "请输入想要操作的选项*-*\r\n" );
	int choice = 0;
	
	scanf ( "%d", &choice );

	return choice;
}


/*
函数名：destory
函数功能：销毁商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void destory ( LIST *pList )
{
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		free ( pList );
		pList = NULL;
		printf ( "您的商品数据库没有商品，无需销毁！\r\n" );
		return ;
	}
	
	printf ( "您确定要删除您的所有商品信息吗？\r\n" );
	int k = 0;
	printf ( "确定销毁请输入 1 ,退出请输入 2 \r\n" );
	scanf (	"%d",&k );
	
	if ( 1 != k )
	{
		printf ( "成功退出 *~*\r\n");
		return ;
	}
	
	//销毁
	LIST *p = NULL;
	while ( NULL != pList->pNext )
	{
		p = pList->pNext;
		pList->pNext = p->pNext;
		//释放p
		free ( p );	
		p = NULL;
	}
	free ( pList );
	pList = NULL;
	//删除文件
	remove ( "save.txt");
	
	printf ( "您的商品信息已经全部销毁\r\n" );
	return;
}

/*
函数名：goodsKinds
函数功能：查看商品的种类
函数参数： LIST *pList 链表的首地址
函数返回值：成功时返回商品种类数，失败返回-1
*/

int goodsKinds ( LIST *pList )
{
	//判断
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		printf ( "您的数据库内没有商品！\r\n" );
		return ERROR;
	}
	
	int count = 0;
	//定义一个指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		count++;
		printf ( "商品的名称：%s\r\n", p->data.name );
		printf ( "商品的数量：%d\r\n", p->data.num );
		printf ( "商品的价格：%f\r\n", p->data.price );	
		printf ( "\r\n" );
		p = p->pNext;
	}
	printf ( "商品的种类为 %d \r\n", count );
	return count;
}


/*
函数名：saveData
函数功能：保存数据，销毁结点
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void saveData ( LIST *pList )
{
	//判断
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		printf ( "您没有商品信息不用保存\r\n" );
		return ;
	}
	
	//定义一个文件指针
	FILE *fp =NULL;
	fp = fopen ( "save.txt", "w+" );
	if ( NULL == fp )
	{
		printf( "文件打开失败\r\n" );
		return ;
	}
	//定义一个指针变量
	LIST *p = NULL;
	int count = 0;
	//保存完后销毁结点
	while ( NULL != pList->pNext )
	{	
		p = pList->pNext;
		pList->pNext = p->pNext;
		
		//保存数据
		fwrite(&p->data,sizeof(p->data),1,fp);
		//释放p
		free (p);
		p = NULL;
		count++;
	}
	//销毁头结点
	free ( pList );
	pList = NULL;
	
	fclose ( fp );
	printf ( "已经保存 %d 种商品信息\r\n" , count );

	return;
}


/*
函数名：readData
函数功能：读取数据
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void readData ( LIST *pList )
{
	//判断
	if ( NULL == pList )
	{
		printf ( "读取数据失败！\r\n" );
		return ;
	}
	//定义一个文件指针
	FILE *fp = fopen ( "save.txt", "rb" );
	if ( NULL == fp )
	{
		printf( "注意：您的数据库内没有商品信息\r\n" );
		return ;
	}
	
	int count = 0;
	//定义指针变量
	int tmp = 1;
	LIST *p =  NULL;
	
	p = creation ( );
	fread(&p->data,sizeof(p->data),1,fp);
	
	while ( !feof(fp) )
	{	
			//头插法插入节点
			p->pNext = pList->pNext;
			pList->pNext = p;
			count++;
			
			//创建一个结点
			p = creation ( );
			//赋值
			fread(&p->data,sizeof(p->data),1,fp);	
	}
	printf ( "数据库中有 %d 种商品信息\r\n", count );
	fclose ( fp );
	
	return;
}
