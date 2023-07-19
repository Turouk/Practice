#define _CRT_SECURE_NO_WARNINGS 1

/*
	ʱ�䣺2023/7/19
	�ص㣺����¥110
	��Ŀ������һ��ͨѶ¼��Ҫ��
		  1.ͨѶ¼���ܴ��1000���˵���Ϣ
			ÿ���˵���Ϣ�У�����+����+�Ա�+�绰+��ַ
		  2.��ɾ�Ĳ��˵���Ϣ
		  3.����ͨѶ¼����Ϣ
	˼·��
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
	//����ͨѶ¼
	Contact con;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}