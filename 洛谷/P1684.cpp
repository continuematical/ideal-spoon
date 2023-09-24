#include<bits/stdc++.h>
using namespace std;

map<int, int> f;
int n,s=0,ans=0;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		f[x]++;//该编号出现的次数加一
		if(f[x]==2)	s++;
		if(s==2){
			f.clear();
			ans++;
			s=0;
		}
		if(f[x]==4){
			ans++;
			s=0;
			f.clear();
		}
	} 
	printf("%d",ans);
	return 0;
} 
