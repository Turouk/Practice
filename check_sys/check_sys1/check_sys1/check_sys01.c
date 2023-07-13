#define _CRT_SECURE_NO_WARNINGS 1
/*
	时间：2023/7/13
	地点：立言楼110
	题目：设计一个小程序来判断当前机器的字节序
	思路：大端字节序：
				把数据的低位字节序的内容存放在高地址处，高位字节序存放在低地址处
		  小端字节序：
				把数据的高位字节序的内容存放在低地址处，低位字节序存放在高地址处
		  1在内存中存放的是4个字节，要拿到4个字节中的第一个字节，使用char*
*/
#include <stdio.h>
check_sys()
{
	int a = 1;
	char* p = (char*)&a;
	return *p;			//返回1表示小端，返回0表示大端

}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;

}