#include<bits/stdc++.h>
using namespace std; 

signed main(){
	int a1,a2;
	cin>>a1>>a2;
	if(a1==1 && a2==1){
		cout<<0<<endl;
		return 0;
	}
	int ans=0;
	while( a1>0 && a2>0 ){
		if(a1>a2){
			a1-=2;
			a2+=1;
		}else{
			a1+=1;
			a2-=2;
		}
		ans+=1;
	}
	cout<<ans<<endl;
	return 0;
} 
