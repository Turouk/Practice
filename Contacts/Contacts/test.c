#define _CRT_SECURE_NO_WARNINGS 1

/*
	时间：2023/7/19
	地点：立言楼110
	题目：建立一个通讯录，要求：
		  1.通讯录中能存放1000个人的信息
			每个人的信息有：名字+年龄+性别+电话+地址
		  2.增删改查人的信息
		  3.排序通讯录的信息
	思路：
*/

#include "contact.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********     1.add         2.del    *********\n");
	printf("**********     3.search      4.modify *********\n");
	printf("**********     5.print       0.exit   *********\n");
	printf("***********************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	PRINT
};

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;//通讯录
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break; 
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}