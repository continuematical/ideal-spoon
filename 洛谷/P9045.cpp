//https://www.luogu.com.cn/problem/P9045
#include<bits/stdc++.h>
using namespace std;
long long n,k,a,ans,d;
//ans��¼�� 
const int N=500001;
bool book[N]; //�洢���ֹ���Ʒ�� 

signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(!book[a]){
			book[a]=1;
			ans+=i-d-1;
			d++;
		}
		if(d==k){
			cout<<ans;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
} 
