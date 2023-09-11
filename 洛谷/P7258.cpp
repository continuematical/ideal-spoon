//https://www.luogu.com.cn/problem/P7285
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,res,arr[N];
signed main(){
	cin>>T;
	while(T--){
		res=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(!arr[i])	res++;
		}
		cout<<n-res<<endl;
		for(int i=1;i<=n;i++)	cout<<1<<" ";
		cout<<endl;
	}
	return 0;
} 
