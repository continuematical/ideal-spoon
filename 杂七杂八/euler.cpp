//https://www.luogu.com.cn/problem/P5091#submit
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//ll slowmul(ll x, ll y, ll mod){
//    ll ans = 0;
//    while(y){
//        if(y & 1){
//            ans=(ans+x);
//            if(ans>mod) ans%=mod;
//        }
//        x=2*x%mod;
//        y>>=1;
//    }
//    return ans;
//}
//
//ll fastpow(ll base, ll power, ll mod){
//    ll ans = 1;
//    while(power){
//        if(power&1) ans=slowmul(ans, base, mod);
//        base=slowmul(base, base, mod);
//        power>>=1;
//    }
//    return ans;
//}
//ll euler(ll n){
//    ll ans = n;
//    for(ll i=2;i*i<=n;i++){
//        if(n%i==0){
//            ans=ans/i*(i-1);
//            while(n%i==0)	n/=i;
//        }
//    }
//    if(n>1)	ans=ans/n*(n-1);
//    return ans;
//}
//
//inline ll read(){
//    ll x = 0, f = 1;char c = getchar();
//    while(c<'0'||c>'9')	{if(c=='-') f = -1;c = getchar();}
//    while(c>='0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48);c=getchar();}
//    return x*f;
//}
//
//bool flag = false;
//inline ll read(ll MOD){
//    ll x = 0, f = 1;char c = getchar();
//    while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
//    while(c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48);if(x >= MOD){flag = true;x%=MOD;} c=getchar();}
//    return x*f;
//}
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    ll a, m, b;
//    a = read();
//    m = read();
//    ll phi = euler(m);
//    b = read(phi);
//    // cout << a << ' ' << m << ' ' << b << ' ' << phi << '\n';
//    if(flag) b += phi;
//    if(b >= phi) cout << fastpow(a, b % phi + phi, m);
//    else cout << fastpow(a, b, m);
//    return 0;
//}


//https://www.lanqiao.cn/problems/1155/learning/?page=2&first_category_id=1&second_category_id=8
//#include<bits/stdc++.h>
//using namespace std;
//#define long long int
//const int P=1e9+7;
//
//int euler(int x){
//	int ans=x;
//	for(int i=2;i*i<=x;i++){
//		if(x%i==0){
//			ans=ans/i*(i-1);
//			while(x%i==0)	x/=i;
//		}
//	}
//	if(x>1)	ans=ans/x*(x-1);
//	return ans;
//}
//
//int fast(int base, int power){
//	int ans=1;
//	while(power){
//		if(power&1)	ans=ans*base%P;
//		base=base*base%P;
//		power>>=1;
//	}
//	return ans;
//}
//
//int main(){
//	int n,m, lch=1;cin>>n>>m;
//	int phi=euler(P);
//	for(int i=1;i<=m;i++){
//		lch=(lch%phi * i%phi) % phi;
//	} 
//	cout<<fast(n, lch)<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/89/learning/?page=1&first_category_id=1&second_category_id=3
#include<bits/stdc++.h>
using namespace std;
int N, flag=0, res=0, a[21], b[21], s[401], vis[21][21];

void dfs(int x, int y, int k){
	if(x<1 || x>N || y<1 || y>N)	return;
	if(a[k]<0 || b[k]<0 || flag)	return;
	if(x==n && y==n && a[k]==0 && b[k]==0){
		res=k;
		flag=1;
		break;
	}
	for(int i=0;i<)
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++)	cin>>a[i];
	for(int i=1;i<=N;i++)	cin>>b[i];
	
	return 0;
}
