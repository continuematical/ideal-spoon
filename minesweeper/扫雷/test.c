#include"game.h"
menu()
{
	printf("1.play 0.exit\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	Initeboard(mine, ROWS, COLS,'0');
	Initeboard(show, ROWS, COLS,'*');
	//打印棋盘
	Displayboard(show, ROW, COL);
	//设置雷
	Setmine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	//查找雷
	Findmine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}