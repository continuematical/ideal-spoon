#include"game.h"
void Initeboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------扫雷-------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷-------\n");
}
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_system;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int Countmine(char mine[ROWS][COLS], int a, int b)
{
	return mine[a - 1][b - 1] + mine[a - 1][b] + mine[a - 1][b + 1] + mine[a][b - 1] + mine[a][b + 1] + mine[a + 1][b - 1] + mine[a + 1][b] + mine[a + 1][b + 1] - 8 * '0';
}
void boom_board(char mine[ROWS][COLS], char show[ROWS][COLS], int a, int b)
{
	if (a<1 || a>ROWS-1 || b<1 || b>COLS-1)
	{
		return;
	}
	if (show[a][b] == '*')
	{
		int ret = Countmine(mine, a, b);
		show[a][b] = ret+'0';
		if (ret == '0')
		{
			boom_board(mine, show, a - 1, b - 1);
			boom_board(mine, show, a - 1, b);
			boom_board(mine, show, a - 1, b + 1);
			boom_board(mine, show, a, b - 1);
			boom_board(mine, show, a, b + 1);
			boom_board(mine, show, a + 1, b - 1);
			boom_board(mine, show, a + 1, b);
			boom_board(mine, show, a + 1, b + 1);
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int a, b;
	while (1)
	{
		printf("请输入查找坐标");
		scanf_s("%d %d", &a, &b);
		if (a >= 1 && a <= row && b >= 1 && b <= col)
		{
			if (mine[a][b] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				printf("游戏结束\n");
				break;
			}
			else
			{
				boom_board(mine, show, a, b);
				Displayboard(show, row, col);
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入");
		}
	}
}