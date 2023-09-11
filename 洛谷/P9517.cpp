#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],l,r;

signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i])	r=i;
	}
	for(int i=0;i<n;i++){
		if(a[i]){
			l=i;
			break;
		}
	}
	if(!l&&!r)	cout<<0<<endl;
	else	cout<<r-l+1<<endl;
	return 0;
} 
