#include<bits/stdc++.h>
using namespace std;

#define long long int

int read(){
	int x=0, f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}	
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+c^48;
		c=getchar();
	} 
	return x*f;
}

int euler(int n){
	int ans=n;
	for(int i=2;i*i<=n;i++){
		if(n&i==0){
			ans=ans/i*(i-1);
			while(n%i==0)	n/=i;
		}
	}
	if(n>1)	ans=ans/n*(n-1);
	return ans;
}

bool flag=false; 
int read(int mod){
	int x=0, f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}	
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+c^48;
		if(x>=mod){
			flag=true;
			x%=mod;	
		}
		c=getchar();
	} 
	return x*f;
}

//x*y%mod
int slowmul(int x, int y, int mod){
	int ans=0;
	while(y){
		if(y&1)	ans=(ans+x)%mod;
		x=2*x%mod;
		y>>=1;
	}
	return ans; 
}

int fastpow(int base, int power, int mod){
	int ans=1;
	while(power){
		if(power&1)	ans=slowmul(ans, base, mod);
		base=slowmul(base, base, mod);
		power>>=1;
	}
	return ans;
}

int main(){
	int a,m,b;
	a=read();m=read();
	int phi=euler(m);
	b=read(phi);
	if(flag)	b+=phi;
	if(b>=phi)	cout<<fastpow(a, b%phi+phi, m)<<endl;
	else	cout<<fastpow(a,b,m)<<endl;
	return 0;
} 
