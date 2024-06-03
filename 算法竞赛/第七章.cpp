#include<bits/stdc++.h>
using namespace std;

//7.3 子集生成
//增量构造法，每次选出一个元素放在集合中 
void print_subset1(int n, int* A, int cur){
	for(int i=0;i<cur;i++)	cout<<A[i]<<" ";
	cout<<endl;
	int s=cur ? A[cur-1]+1 : 0;
	for(int i=s;i<n;i++){
		A[cur]=i;
		print_subset1(n,A,cur+1);
	} 
} 

//位向量法
void print_subset2(int n, int* A, int cur){
	if(cur==n){
		for(int i=0;i<n;i++)	cout<<A[i]<<" ";
		cout<<endl;
		return;
	}
	A[cur]=1;
	print_subset2(n,A,cur+1);
	A[cur]=0;
	print_subset2(n,A,cur+1);
} 

//二进制法 

//7.4 回溯

//判断是否为素数
int isp[40], A[40], vis[40];

int is_prime(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x % i==0)	return 0;
	return 1;
} 

//素数环
void dfs_prime(int cur, int n){
	if(cur>n && isp[A[1]+A[n]]){ 
		for(int i=1;i<=n;i++)	printf("%d ",A[i]);
		printf("\n");
		return; 
	}
	for(int i=2;i<=n;i++){
		if(!vis[i] && isp[i+A[cur-1]]){
			A[cur]=i;
			vis[i]=1;
			dfs_prime(cur+1, n);
			vis[i]=0;
		}
	}
} 

void prime_circle(int n){
	//准备素数数组和原数数组 
	for(int i=2;i<=n*2;i++)	isp[i]=is_prime(i);	
	dfs_prime(1,6);
}


//困难的串
 

int main(){
	prime_circle(6);
	return 0;
}
