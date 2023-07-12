#define _CRT_SECURE_NO_WARNINGS 1
/*
	时间：2023/7/11
	地点：立言楼110
	题目：设计一个三子棋游戏，让用户与电脑对弈（不考虑电脑算法）要求当有一方获胜时打印棋盘
	思路：1.首先打印菜单，是否进行游戏
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
	//存储数据-二维数组
	char board[ROW][COL];
	//初始化棋盘为空格
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*') 
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			//退出游戏
			break;
		default:
			printf("选择错误，请重新输入：>");
		}
	}while(input);
	return 0;
}
