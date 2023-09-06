//https://www.luogu.com.cn/problem/P2095

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=201;

struct food{
	int a;//脂肪指数 
	int b;//类别 
}f[N];

int n,m,k,limit[N],ans=0;

bool cmp(food x, food y){
	return x.a>y.a;
}

signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)	cin>>limit[i];
	for(int i=1;i<=n;i++)	cin>>f[i].a>>f[i].b;
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(limit[f[i].b]>0 && m>0){
			ans+=f[i].a;
			m--;
			limit[f[i].b]--;
		}
	}
	cout<<ans<<endl;
}
