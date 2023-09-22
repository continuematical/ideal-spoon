#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

signed main(){
	int n,m,c,k;
	ULL flag=0,res=0,ans=1;
	
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++){
		ULL x;cin>>x;
		flag |= x;
	}
	while(m--){
		int i,x;cin>>i>>x;
		//将第 i 位赋值为零 
		if((flag >> i & 1)==0)	res |= (1ULL<<i);
	}
	for(int i=0;i<k;i++){
		if((res >> i & 1)==0)	ans<<=1;
	}
	if(ans==0 && n==0){
		printf("18446744073709551616");
	}else{
		ans-=n;
		printf("%llu",ans);
	}
	return 0;
} 
