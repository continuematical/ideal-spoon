//求最大子字符串 

#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;

int matrix[MAX][MAX];
int m,n,maxLen=0,jpos=-1;
//两个字符串的长度 

void diagscan(int i, int j){
	int len=0,eq=0,sj=0;
	while(i<m && j<n){
		if(matrix[i][j]==1){
			len++;
			//出现的第一个1，记录下标
			if(!eq){
				sj=j;eq=1; 	
			}
		}else if(eq){
			if(len>maxLen){
				maxLen=len;jpos=sj;
			}
			eq=0;len=0;
		}
		i++;j++;
	}
}

//矩阵 最大子字符串长度	字符串起始位置 
void diagmaxl(int mat[][MAX], int &maxLen, int &jpos){
	int istart=0,i,j;
	for(int k=-(m-1);k<=n-1;k++){
		i=istart;
		j=i-k;
		diagscan(i,j);
		if(k>=0)	istart++; 
	}
}

void SubString(char*&sub, char* s1, int jpos, int maxLen){
	int length=sizeof(s1);
	if(jpos<1 || jpos>length-1)	return;
	for(int i=0;i<maxLen;i++){
		sub[i]=s1[i+jpos];
	}
}

//求解字符串1和字符串2的最大子字符串，并存放在sub中 
void getMaxSameSubstring(char* s1, char* s2, char* &sub){
	char* p1=s1;char* p2=s2;
	//初始矩阵赋值 
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(*(p1+i)==*(p2+j))	matrix[i][j]=1;
			else	matrix[i][j]=0;
	diagmaxl(matrix, maxLen, jpos);
	
	if(maxLen==0)	*sub='\0';
	else	SubString(sub,s1,jpos,maxLen);
} 

int main(){
	char s1[]="helloworld";m=strlen(s1); 
	char s2[]="woshihello";n=strlen(s2);
	char *sub="";
	//getMaxSameSubstring(s1,s2,sub);
	//printf("%c",sub); 
	cout<<jpos<<endl;
} 
