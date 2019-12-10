#include <stdio.h>
#include "../include/commodity.h"

int main ( )
{
	//定义指针变量
	LIST *pList = NULL;
	pList = creation ( );
	
	//读数据
	readData ( pList );
	
	while ( 1 )
	{
		int choice = menu ( );
		//从缓存区读取一个字节
		getchar();
		
		switch ( choice )
		{
			case 1:
					//增加商品信息
					insert ( pList );
					break;
			case 2:
					//删除商品信息
					delDate ( pList );
					break;
			case 3:
					//查找商品信息
					findData ( pList );
					break;
			case 4:
					//修改商品信息
					update ( pList );
					break;
			case 5:
					//查看商品种类数
					goodsKinds ( pList );
					break;
			case 6:
					//销毁所有商品信息	
					destory ( pList );
					
					break;
			case 7:
					//退出系统,保存数据
					saveData ( pList );
					return 0;
			default:
					//提示
					printf ( "输入的信息有误,请重新输入！！！\r\n");
					break;			
		}
	}	
	return 0;
}
