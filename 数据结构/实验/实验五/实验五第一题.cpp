#include<bits/stdc++.h>
using namespace std;

void Reverse(int* R, int left, int right){
	int i=left, j=right;
	while(i<j){
		int temp=R[i];
		R[i]=R[j];
		R[j]=temp;
		i++;
		j--;
	}
}

void leftShift(int* R, int size, int n){
	Reverse(R, 0, n-1);
	Reverse(R, n, size-1);
	Reverse(R, 0, size-1);
}

void show(int* R, int size){
	for(int i=0;i<size;i++)
		cout<<R[i]<<" ";
	cout<<endl;
}

int main(){
	printf("请输入数组长度：\n");
	int size;cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)	cin>>arr[i];
	printf("请输入移动位数：\n");
	int n;cin>>n;
	leftShift(arr, size, n);
	show(arr, size);
	return 0;
} 
