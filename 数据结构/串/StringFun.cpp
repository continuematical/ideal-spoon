#include<bits/stdc++.h>
const int MAX_SIZE=100;

typedef struct string{
	char ch[MAX_SIZE+1];
	int length;
}string; 

void showString(string* s){
	if(s->length==0){
		printf("��ǰ��Ϊ��\n");
		return;
	}
	for(int i=0;i<s->length;i++){
		printf("%c",s->ch[i]);
	}
}

//��s1�еĵ�pos���ַ�ǰ����s2 
void strInsert(string* s1, int pos, string* s2){
	if(pos<1 || pos>s1->length) {
		printf("����pos����\n");
		return;
	}
	//��s1 pos֮����ַ��ƶ�s2->length
	for(int i=pos-1;i<s1->length-pos;i++){
		s1->ch[i+s2->length]=s1->ch[i];
	} 
	for(int i=0;i<s2->length;i++){
		s1->ch[i+pos-1]=s2->ch[i];
	}
	s1->length+=s2->length;
}

void stringAssign(string*s, char num[]){
	int i=0;
	while(num[i]!='\0'){
		s->ch[i]=num[i++];
	}
	s->length=sizeof(num);
	return;
}
