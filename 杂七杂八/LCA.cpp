//https://www.luogu.com.cn/problem/P3379
//LCA

#include<bits/stdc++.h>
using namespace std; 

#define int long long
const int N=5e5+1;

struct e{
	int next;
	int to;
}e[N<<1];

int n,q, res=0, cnt=0, f[N][21], head[N], depth[N];

void add(int u, int v){
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}

void dfs(int now, int fath){
	f[now][0]=fath;depth[now]=depth[fath]+1;
	for(int i=1;(1<<i)<=depth[now];i++)
		f[now][i]=f[f[now][i-1]][i-1];
	for(int i=head[now];i;i=e[i].next)
		if(e[i].to != fath)	dfs(e[i].to, now);
}

int LCA(int u, int v){
	if(depth[u]<depth[v])	swap(u,v);
	for(int i=20;i>=0;i--)
		if(depth[v]<=depth[u]-(1<<i))
			u=f[u][i];
	if(u==v)	return u;
	for(int k=20;k>=0;k--)
		if(f[u][k]!=f[v][k])
			u=f[u][k], v=f[u][k];
	return f[u][0];
} 

void init(){
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u, v);add(u, v);
	}
} 

signed main(){
	cin>>n>>q;
	init();
	return 0;
} 
