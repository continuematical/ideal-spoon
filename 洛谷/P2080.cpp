#include<bits/stdc++.h>
//https://www.luogu.com.cn/problem/P2080
using namespace std;
#define long long int
const int N=31;

int n,v,a[N],b[N],vis[N],minn=100000;//��������Сֵ 

//��ǰ���ѵ��Ľڵ� 
void dp(int deep, int ga, int gb){
	if(minn==0)	return;
	if(deep>n){
		if(ga+gb>v)
			minn=min(abs(ga-gb),minn);
		return;
	}
	dp(deep+1, ga, gb); //��ȡ
	dp(deep+1,ga+a[deep],gb+b[deep]);//ȡ 
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
