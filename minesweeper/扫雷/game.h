#pragma once
//引用头文件
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//定义常量
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_system 10
//引用函数
void Initeboard(char board[ROWS][COLS], int row, int col, char set);//引用函数时参数与形参要一致
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
