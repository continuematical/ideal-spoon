//https://www.luogu.com.cn/problem/P1750 
//#include<bits/stdc++.h>
//using namespace std; 
//#define int long long
//const int N=1e4+1;
//
//int n,c,arr[N];
//
//signed main(){
//	cin>>n>>c;
//	for(int i=0;i<n;i++)	cin>>arr[i]; 
//	stack<int> s;
//	int k=0, count=0, pos=0;
//	//count是已经出栈的元素个数 
//	while(count+s.size()<n){
//		int min=2e9;
//		//选出c-s.size()个元素中最小的元素 
//		for(int i=k;i<k+c-s.size() && i<n;i++){
//			if(arr[i]<min){
//				min=arr[i];
//				pos=i;
//			} 
//		} 
//		//入栈
//		if(s.empty() || s.top()>=min){
//			//把比pos小的元素入栈 
//			for(int i=k;i<=pos;i++)	s.push(arr[i]);
//			k=pos+1;
//		} 
//		cout<<s.top()<<" ";
//		s.pop();count++; 
//	}
//	//将剩余的元素输出
//	while(!s.empty()){
//		cout<<s.top()<<" ";
//		s.pop(); 
//	} 
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,X,Y,ans, vis[N], mm[N], num[N];
//ans为路径条数 
//num表示每一条路径经过的节点
vector<int> cnt[N];

//到达节点  每一条路径节点个数 
void dfs(int x, int t){
	if(x==Y){
		ans++;//路径条数 
		for(int i=1;i<t;i++)	num[mm[i]]++;
		return;
	}
	for(int i=0;i<cnt[x].size();i++){
		int next=cnt[x][i];
		if(vis[next])	continue;
		vis[next]=1;
		mm[t]=next;
		dfs(next, t+1);
		vis[next]=0;
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int u,v;cin>>u>>v;
		cnt[u].push_back(v);
		cnt[v].push_back(u);
	}
	cin>>X>>Y;//起点和终点
	vis[X]=1;
	dfs(X,1);
	if(ans==0){
		cout<<"-1"<<endl;
	} else{
		int k=0;
		for(int i=1;i<=n;i++){
			if(num[i]==ans)	k++;
		}
		cout<<k-1<<endl;
	}
	return 0;
} 
