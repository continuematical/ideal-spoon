#include<bits/stdc++.h>
//https://www.luogu.com.cn/problem/P2080
using namespace std;
#define long long int
const int N=31;

int n,v,a[N],b[N],vis[N],minn=100000;//保存结果最小值 

//当前深搜到的节点 
void dp(int deep, int ga, int gb){
	if(minn==0)	return;
	if(deep>n){
		if(ga+gb>v)
			minn=min(abs(ga-gb),minn);
		return;
	}
	dp(deep+1, ga, gb); //不取
	dp(deep+1,ga+a[deep],gb+b[deep]);//取 
}

int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	dp(1,0,0);
	if(minn==100000)	printf("-1\n");
	else	cout<<minn<<endl;
	return 0;
} 
