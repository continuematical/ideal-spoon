 // head.h (������)
 #include <string.h>
 #include <ctype.h>
 #include <malloc.h> // malloc()��
 #include <limits.h> // INT_MAX��
 #include <stdio.h> // EOF(=^Z��F6),NULL
 #include <stdlib.h> // atoi()
 #include <io.h> // eof()
 #include <math.h> // floor(),ceil(),abs()
 #include <process.h> // exit()
 #include <iostream> // cout,cin 
 
 // �������״̬����
 
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define LIST_INIT_SIZE 100
 #define LISTINCREMENT 1
 
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 typedef char TElemType;
 
 typedef struct BiTNode{
	TElemType data;//ֵ
	BiTNode* lchild,*rchild; 
}BiTNode, *BiTree;

typedef BiTNode* ElemType;
 
 using namespace std;
