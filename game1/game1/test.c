#define _CRT_SECURE_NO_WARNINGS 1
/*
	ʱ�䣺2023/7/11
	�ص㣺����¥110
	��Ŀ�����һ����������Ϸ�����û�����Զ��ģ������ǵ����㷨��Ҫ����һ����ʤʱ��ӡ����
	˼·��1.���ȴ�ӡ�˵����Ƿ������Ϸ
*/
#include"game.h"

void menu()
{
	printf("*************************************\n");
	printf("*********    1.play     *************\n");
	printf("*********    0.exit     *************\n");
	printf("*************************************\n");

}

void game()
{
	//�洢����-��ά����
	char board[ROW][COL];
	//��ʼ������Ϊ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*') 
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			//�˳���Ϸ
			break;
		default:
			printf("ѡ��������������룺>");
		}
	}while(input);
	return 0;
}
