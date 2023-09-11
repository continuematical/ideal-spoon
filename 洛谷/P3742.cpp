//https://www.luogu.com.cn/record/124466012

#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n;
char x[N],y[N];

signed main(){
	cin>>n>>x>>y;
	for(int i=0;i<n;i++){
		if(x[i]<y[i]){
			cout<<-1<<endl;
			return 0;
		}
	} 
	for(int i=0;i<n;i++){
		cout<<y[i];
	} 
	return 0;
} 
