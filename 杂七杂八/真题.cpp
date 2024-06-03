#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n,m,t,res=0,ts[N],id[N],book[N],arr[N],fit[N];

signed main(){
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)	cin>>ts[i]>>id[i];
	for(int i=1;i<=t;i++){//每一时刻
		//每家店的订单数目 
		for(int k=0;k<=n;k++)	book[i]=0;
		for(int k=1;k<=m;k++){//每一个订单 
			if(ts[k]==i){
				arr[id[k]]+=2;//优先级 
				book[id[k]]+=1;
			}
		}
		//每家店 
		for(int k=1;k<=n;k++){
			if(book[k]==0 && arr[k]>0)	arr[k]--;
			if(book[k]==0 && fit[k]>0)	fit[k]--;
			if(arr[k]>5)	fit[k]=arr[k];
			if(arr[k]<=3)	fit[k]=0;
		} 
	}
	for(int i=1;i<=n;i++){
		if(fit[i])	res++;
	}
	cout<<res<<endl;
	return 0;
}
