#pragma once
//����ͷ�ļ�
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//���峣��
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_system 10
//���ú���
void Initeboard(char board[ROWS][COLS], int row, int col, char set);//���ú���ʱ�������β�Ҫһ��
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
