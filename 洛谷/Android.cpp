#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MOD=1e9+7;

//快速幂 
int fast(int x, int k){
	int res=1;
	while(k){
		if(k&1)	res=res*x%MOD;
		x=x*x%MOD; 
		k >>= 1;
	}
	return res;
}

int n;

solve(){
	cin>>n;//n为输入字符串的个数 
	int m=7*n;//m为字母的个数 
	vector<int> fac(m+1),ind(m+1);
	fac[0]=ind[0]=1;
	for(int i=1;i<=m;i++){
		fac[i]=fac[i-1]*i%MOD;
	}
	ind[m]=fast(fac[m], MOD-2)%MOD;
	for(int i=m-1;i>=1;i--){
		ind[i]=ind[i+1]*(i+1)%MOD;
	}
	int ans=fac[m]*ind[2*n]%MOD*ind[n]%MOD*ind[n]%MOD*ind[n]%MOD*ind[n]%MOD*ind[n]%MOD;
	cout<<ans<<endl;
}

signed main(){
	solve();
	return 0;
} 
