#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//添加一个人的信息
void AddContact(Contact* pc)
{
	//通讯录空间有限，判断是否已满
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	//增加一个人的信息
	printf("请输入名字：>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].addr);
	
	pc->sz++;
	printf("增加成功\n");
}

//打印联系人信息
void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");

	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
			printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name, 
			pc->data[i].age, 
			pc->data[i].sex, 
			pc->data[i].tele, 
			pc->data[i].addr);
	}
}

static int Finf_by_name(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name )== 0)
		{
			return i;
		}
	}
	return -1;
}

//删除一个人的信息
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	//1.查找联系人是否在通讯录
	//有/没有
	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不在通讯录内\n");
		return;
	}
	//有，删除
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("删除成功\n");
}

//查找联系人
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字：>");
	scanf("%s", name);

	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不在通讯录内\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

//修改指定联系人
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字：>");
	scanf("%s", name);

	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不在通讯录内\n");
		return;
	}
	else
	{ 
		printf("请输入名字：>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	} 
}
