#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//���һ���˵���Ϣ
void AddContact(Contact* pc)
{
	//ͨѶ¼�ռ����ޣ��ж��Ƿ�����
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	//����һ���˵���Ϣ
	printf("���������֣�>");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->sz].addr);
	
	pc->sz++;
	printf("���ӳɹ�\n");
}

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");

	//��ӡ����
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

//ɾ��һ���˵���Ϣ
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//1.������ϵ���Ƿ���ͨѶ¼
	//��/û��
	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲���ͨѶ¼��\n");
		return;
	}
	//�У�ɾ��
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("ɾ���ɹ�\n");
}

//������ϵ��
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);

	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲���ͨѶ¼��\n");
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

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);

	int pos = Finf_by_name(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲���ͨѶ¼��\n");
		return;
	}
	else
	{ 
		printf("���������֣�>");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰��>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	} 
}
