//https://www.luogu.com.cn/problem/P8082

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500001;
int n,k,num[N],top=0;
char s[N];

signed main(){
	cin>>n>>k>>s+1;
	for(int i=1;i<=n;i++){
		int x=s[i]-'0';
		while(k && top && num[top]<x){
			k--;
			num[top--]=0;
		}
		num[++top]=x;
	}
	for(int i=1;i<=top;i++)	cout<<num[i];
	return 0;
}
