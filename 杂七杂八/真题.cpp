//https://www.lanqiao.cn/problems/89/learning/?page=1&first_category_id=1&second_category_id=3
//#include<bits/stdc++.h>
//using namespace std;
//
//int N, a[21], b[21], vis[21][21], res[401], k1=0, k2=0, flag, num;
////结果数组
//int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//
//void dfs(int x, int y, int k){
//	if(x<1 || x>N || y<1 || y>N)	return;
//	if(b[x]<0 || a[y]<0 || flag)	return;
//	res[k]=(x-1)*N+(y-1);
//	if(x==N && y==N && k1==1 && k2==1){
//		flag=1;
//		num=k;
//		return;
//	}
//	for(int i=0;i<4;i++){
//		int xx=x+dir[i][0];
//		int yy=y+dir[i][1];
//		if(vis[xx][yy])	continue; 
//		b[xx]--;
//		a[yy]--;
//		k1--;
//		k2--;
//		vis[xx][yy]=1;
//		dfs(xx, yy, k+1);
//		b[xx]++;
//		a[yy]++;
//		k1++;
//		k2++;
//		vis[xx][yy]=0;
//	}
//} 
//
//int main(){
//	cin>>N;
//	for(int i=1;i<=N;i++){
//		cin>>a[i];
//		k1+=a[i];
//	}
//	for(int i=1;i<=N;i++){
//		cin>>b[i];
//		k2+=b[i];
//	}
//	flag=0;
//	vis[1][1]=1;
//	dfs(1,1,1);
//	for(int i=1;i<=num;i++)
//		cout<<res[i]<<" ";
//	return 0;
//} 


//https://www.lanqiao.cn/problems/130/learning/?page=1&first_category_id=1&second_category_id=3
//#include<bits/stdc++.h>
//using namespace std;
//
//int w,m,n,res;
//
//int getl(int x){
//	return (x-1)/w+1;
//}
//
//int getr(int x){
//	int l=getl(x); 
//	int r=x%w;
//	if(l%2==0)	r=w-r+1;
//	return r;
//}
//
//int main(){
//	cin>>w>>m>>n;
//	int x1=getl(m), y1=getr(m); 
//	int x2=getl(n), y2=getr(n);
//	int res=abs(x1-x2)+abs(y1-y2);
//	cout<<res<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/2417/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023
//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string t="lanqiao";
//	string s;cin>>s;
//	int flag=0;
//	for(int i=0;i<s.length();i++)
//		if(tolower(s[i])!=t[i])	flag=1;
//	if(flag)	cout<<"no"<<endl;
//	else	cout<<"yes"<<endl;
//	return 0;
//}

//https://www.lanqiao.cn/problems/3505/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023 
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,w[31],f[31],ans=31;
//
//void dfs(int sum, int pos, int cnt){
//	if(cnt>=ans)	return;
//	if(sum==m)	ans=min(ans,cnt); 
//	if(pos>n || sum>=m || sum+f[pos]<m)	return; 
//	dfs(sum,pos+1,cnt);
//	dfs(sum+w[pos]/2,pos+1,cnt+1);
//	dfs(sum+w[pos],pos+1,cnt);
//}
//
//int main(){
//	cin>>n>>m;m<<=1;
//	for(int i=1;i<=n;i++)	cin>>w[i],w[i]<<=1;
//	sort(w+1,w+n+1,greater<int>());
//	for(int i=n;i>=1;i--)	 f[i]=f[i+1]+w[i];
//	dfs(0,1,0);
//	cout<<ans<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/3511/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//
//typedef struct Plane{
//	ll t,d,l;
//}Plane; 
//
//int vis[20], flag=0;
//
//void dfs(ll n, ll cnt, ll last, vector<Plane> plane){
//	if(cnt==n){
//		flag=1;
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!vis[i] && plane[i].t+plane[i].d>=last){
//			vis[i]=1;
//			dfs(n, cnt+1, max(last,plane[i].t)+plane[i].l, plane);
//			vis[i]=0;
//		}
//	}
//}
//
//void clear(){
//	for(int i=1;i<=20;i++)	vis[i]=0;
//}
//
//int main(){
//	ll t;cin>>t;
//	while(t--){
//		ll n;cin>>n;
//		vector<Plane> plane(n+1);
//		for(int i=1;i<=n;i++)
//			cin>>plane[i].t>>plane[i].d>>plane[i].l;
//		clear();flag=0;
//		dfs(n,0,0,plane);
//		if(flag)	cout<<"YES"<<endl;
//		else	cout<<"NO"<<endl;
//	}
//	return 0;
//}


//https://www.lanqiao.cn/problems/98/learning/?page=1&first_category_id=1&second_category_id=3
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long 
//const ll N=1e7; 
//ll n, num[101], dp[N];
//
//int main(){
//	ll res=0;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>num[i];
//		dp[num[i]]++;
//	} 
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=n;j++){
//			if(i-num[j]<=0)	continue;
//			dp[i]=dp[i-num[j]]+dp[i];
//			if(dp[i])	break;
//		}
//		if(!dp[i])	res++;
//	}
//	if(res>10000)	cout<<"INF"<<endl;
//	else	cout<<res<<endl;
//	return 0;
//} 

//https://www.lanqiao.cn/problems/209/learning/?page=1&first_category_id=1&tags=%E8%B4%AA%E5%BF%83
//#include<bits/stdc++.h>
//using namespace std;
//
//void change(string& s, int i){
//	if(s[i]=='*')	s[i]='o';
//	else	s[i]='*';
//}
//
//int main(){
//	string s,e;cin>>s>>e;
//	int count=0;
//	for(int i=0;i<s.size();i++){
//		if(s[i]!=e[i]){
//			change(s,i);
//			if(i+1<s.size())	change(s,i+1);
//			count++;
//		}
//	}
//	cout<<count<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/364/learning/?page=1&first_category_id=1&tags=%E8%B4%AA%E5%BF%83
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long 
//const int N=5e4+1;
//
//int l,n,m,arr[N]; 
//
//bool check(int x){
//	int pos=0, cnt=0;//最左端 需要移走的石头数目
//	for(int i=1;i<=n+1;i++){
//		if(arr[i]-arr[pos]<x)	cnt++;
//		else	pos=i;
//	} 
//	if(cnt>m)	return false;
//	else	return true;
//}
//
//signed main(){
//	cin>>l>>n>>m;
//	for(int i=1;i<=n;i++)	cin>>arr[i];
//	arr[n+1]=l;
//	int left=0, right=l;
//	while(left<right){
//		int mid=(left+right+1)>>1;
//		if(check(mid))	left=mid;
//		else	right=mid-1;
//	}
//	cout<<left<<endl;
//	return 0;
//} 


//https://www.luogu.com.cn/problem/CF1675B 
//#include<bits/stdc++.h>
//using namespace std;
//
//int T, arr[31];
//const int N=2e9;
//
//int main(){
//	cin>>T;
//	while(T--){
//		int n, res=0;cin>>n;
//		for(int i=1;i<=n;i++)	cin>>arr[i];
//		for(int i=n-1;i>=1;i--){
//			if(arr[i+1]==0){
//				res=-1;break;
//			}
//			while(arr[i]>=arr[i+1] && arr[i]>0){
//				arr[i]/=2;
//				res++;
//			}
//		}
//		cout<<res<<endl;
//	}
//	return 0;
//} 

#include<bits/stdc++.h>
using namespace std;

class A{
	
};


int main(){
	
}
