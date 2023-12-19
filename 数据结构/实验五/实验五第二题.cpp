#include<bits/stdc++.h>
using namespace std;

int findNumber(int* num, int size){
	int temp[size+2];
	memset(temp, 0, sizeof(temp));
	for(int i=0;i<size;i++)	
		if(num[i]>0 && num[i]<=size)	temp[num[i]]=1;
	int flag;
	for(int i=1;i<=size+1;i++){
		if(temp[i]==0){
			flag=i;
			break;
		} 
	} 
	return flag;
}

int main(){
	int size;
	printf("数组大小：\n");
	cin>>size;int num[size];
	for(int i=0;i<size;i++)	cin>>num[i];
	cout<<findNumber(num, size)<<endl;
	return 0;
} 
