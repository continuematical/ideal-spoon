#include<bits/stdc++.h>
using namespace std;
const int N=101;
int a[N], f[2][N];

int main(){
	int n,maxx=0;cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];//赋值
	//1-n最大升序列
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i])	f[0][i]=max(f[0][i],f[0][j]+1);
		}
	} 
	//n-1最大生序列
	for(int i=n-1;i>0;i--){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[i])	f[1][i]=max(f[1][i],f[1][j]+1);
		}
	}  
	for(int i=0;i<n;i++){
		maxx=max(maxx,f[0][i]+f[1][i]+1);
	}
	printf("%d",n-maxx);
	return 0;
} 
