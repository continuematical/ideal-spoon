#include"game.h"
menu()
{
	printf("1.play 0.exit\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	Initeboard(mine, ROWS, COLS,'0');
	Initeboard(show, ROWS, COLS,'*');
	//��ӡ����
	Displayboard(show, ROW, COL);
	//������
	Setmine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	//������
	Findmine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�����룺\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);
	return 0;
}