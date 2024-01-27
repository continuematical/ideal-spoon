//https://www.lanqiao.cn/problems/1124/learning/?page=1&first_category_id=1&second_category_id=8
//typedef struct Edge{
//	int u;
//	int v;
//	int w;
//}Edge;
//
//vector<Edge> edges;
//const int N=1e5+1;
//int n,m, f[N], cnt=0, ans=0;
////cnt表示总路个数，ans表示总长度 
//
//bool compare(Edge x, Edge y){
//	return x.w<y.w;
//}
//
//int find(int x){
//	if(f[x]=x)	return x;
//	else	return f[x]=find(f[x]);
//}
//
//void merge(int x, int y){
//	f[find(x)]=find(y);
//}
//
//int main(){
//	cin>>n>>m;
//	for(int i=0;i<m;i++){
//		int u,v,w;cin>>u>>v>>w;
//		edges.emplace_back(Edge{u,v,w});
//	}
//	sort(edges.begin(), edges.end(), compare);
//	for(int i=1;i<=n;i++)	f[i]=i;
//	for(int i=0;i<m;i++){
//		int u=edges[i].u;
//		int v=edges[i].v;
//		int w=edges[i].w;
//		if(find(u) != find(v)){
//			merge(u, v);
//			cnt++;
//			ans+=w;
//			if(cnt+1 >= n)	break;
//		}
//	}
//	
//	if(cnt+1 >= n)	cout<<ans<<endl;
//	else	cout<<-1<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/1159/learning/?page=2&first_category_id=1&second_category_id=8
//卢卡斯算法 
//typedef long long ll;
//ll n, m, p;
//
//ll fast(ll a, ll b){
//	ll res=1;
//	while(b){
//		if(b&1)	res=res*a%p;
//		a=a*a%p;
//		b>>=1;	
//	}
//	return res; 
//}
//
//ll C(ll n, ll m){
//	if(n<m)	return 0;
//	if(m>n-m)	m=n-m;
//	ll a=1, b=1;
//	for(int i=0;i<m;i++){
//		a=(a*(n-i))%p;
//		b=(b*(i+1))%p;
//	}
//	return a*fast(b, p-2)%p;// a/b
//}
//
//ll Lucas(ll n, ll m){
//	if(m==0)	return 1;
//	return Lucas(n/p,m/p)*C(n%p, m%p)%p;
//}
//
//int main(){
//	ll T;cin>>T;
//	while(T--){
//		scanf("%lld%lld%lld", &n, &m, &p); 
//		printf("%lld\n", Lucas(n, m));
//	} 
//	return 0;
//} 


//https://www.lanqiao.cn/problems/309/learning/?page=2&first_category_id=1&second_category_id=6 
//int f[40];
//
//int main(){
//	int N;cin>>N;
//	f[0]=1,f[1]=1,f[2]=2;
//	for(int i=3;i<=N;i++)	f[i]=f[i-1]+f[i-2]+f[i-3];
//	cout<<f[N]<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/191/learning/?page=2&first_category_id=1&second_category_id=3 
//int get(int x){
//	while(x){
//		int a=x%10;
//		if(a==2 || a==0 || a==1 || a==9)	return 1;
//		x/=10;
//	}
//	return 0;
//}
//
//int main(){
//	int n, res=0;cin>>n;
//	for(int i=1;i<=n;i++){
//		if(get(i))	res+=i;
//	}
//	cout<<res<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/1142/learning/?page=1&first_category_id=1&second_category_id=8
//单调栈 
//const int N=7e5+1;
//int n, f[N], res[N];
//
//void show(){
//	for(int i=1;i<=n;i++){
//		cout<<res[i]<<" ";
//	}
//	cout<<endl;
//}
//
//void solve1(){
//	stack<pair<int, int> > s;
//	memset(res, 0, sizeof(res));
//	res[1]=-1; s.push(make_pair(1, f[1])); 
//	for(int i=2;i<=n;i++){
//		while(!s.empty() && s.top().second < f[i])	s.pop();
//		if(!s.empty())	res[i]=s.top().first;
//		else	res[i]=-1;
//		s.push(make_pair(i, f[i]));
//	}
//	show();
//}
//
//void solve2(){
//	stack<pair<int, int> > s;
//	memset(res, 0, sizeof(res));
//	res[n]=-1; s.push(make_pair(n, f[n])); 
//	for(int i=n-1;i>=1;i--){
//		while(!s.empty() && s.top().second < f[i])	s.pop();
//		if(!s.empty())	res[i]=s.top().first;
//		else	res[i]=-1;
//		s.push(make_pair(i, f[i]));
//	}
//	show();
//} 
//
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++)	cin>>f[i];
//	//左边 
//	solve1();
//	//右边
//	solve2();
//	return 0;
//} 


//https://www.lanqiao.cn/problems/1226/learning/?page=1&first_category_id=1&second_category_id=8
//威佐夫博弈 
//int main(){
//	int T;cin>>T;
//	while(T--){
//		int a,b;cin>>a>>b;
//		if(a>b)	swap(a,b);
//		double c=(sqrt(5.0)+1)/2;
//		if(int((b-a)*c)==a)	cout<<"YES\n"<<endl;
//		else	cout<<"NO\n"<<endl;
//	}
//	return 0;
//} 


//https://www.lanqiao.cn/problems/1174/learning/?page=1&first_category_id=1&second_category_id=8 
//int N, V, w, v, dp[1001]; 
//int main(){
//	cin>>N>>V;
//	for(int i=1;i<=N;i++){
//		cin>>w>>v;
//		for(int j=V;j>=w;j--)	dp[j]=max(dp[j], dp[j-w]+v);
//	} 
//	cout<<dp[V]<<endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std; 
//#define int long long
//const int N=1e5+1;
//
//int arr[N], ans[N<<2], tag[N<<2];
//
//int ls(int p){
//	return p<<1;
//}
//
//int rs(int p){
//	return p<<1|1;
//}
//
//void push_up(int p){
//	ans[p]=ans[ls(p)]+ans[rs(p)];
//}
//
//void f(int p, int l, int r, int k){
//	ans[p]+=k*(r-l+1);
//	tag[p]+=k;
//}
//
//void push_down(int p, int l, int r){
//	int mid=(l+r)>>1;
//	f(ls(p),l,mid,tag[p]);
//	f(rs(p),mid+1,r,tag[p]);
//	tag[p]=0;
//}
//
//void update(int nl, int nr, int l, int r, int p, int k){
//	if(nl<=l && r<=nr){
//		f(p,l,r,k); 
//		return;
//	}
//	push_down(p,l,r);
//	int mid=(l+r)>>1;
//	if(nl<=mid)	update(nl,nr,l,mid,ls(p),k);
//	if(nr>mid)	update(nl,nr,mid+1,r,rs(p),k);
//	push_up(p);
//}
//
//void build(int l, int r, int p){
//	tag[p]=0; 
//	if(l==r){
//		ans[p]=arr[l];
//		return;
//	}
//	int mid=(l+r)>>1;
//	build(l, mid, ls(p));
//	build(mid+1, r, rs(p));
//	push_up(p);
//}
//
//int query(int q_x,int q_y,int l,int r,int p){
//    int res=0;
//    if(q_x<=l&&r<=q_y)	return ans[p];
//    int mid=(l+r)>>1;
//    push_down(p,l,r);
//    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
//    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
//    return res;
//}
//
//signed main(){
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)	cin>>arr[i];
//	build(1,n,1);
//	while(m--){
//		int flag,x,y,k;
//		cin>>flag>>x>>y;
//		if(flag==1){
//			cin>>k;
//			update(x,y,1,n,1,k);
//		}else{
//			cout<<query(x,y,1,n,1)<<endl; 
//		}
//	}
//	return 0;
//}

//https://www.luogu.com.cn/problem/P1750 
//#include<bits/stdc++.h>
//using namespace std; 
//#define int long long
//const int N=1e4+1;
//
//int n,c,arr[N];
//
//signed main(){
//	cin>>n>>c;
//	for(int i=0;i<n;i++)	cin>>arr[i]; 
//	stack<int> s;
//	int k=0, count=0, pos=0;
//	//count是已经出栈的元素个数 
//	while(count+s.size()<n){
//		int min=2e9;
//		//选出c-s.size()个元素中最小的元素 
//		for(int i=k;i<k+c-s.size() && i<n;i++){
//			if(arr[i]<min){
//				min=arr[i];
//				pos=i;
//			} 
//		} 
//		//入栈
//		if(s.empty() || s.top()>=min){
//			//把比pos小的元素入栈 
//			for(int i=k;i<=pos;i++)	s.push(arr[i]);
//			k=pos+1;
//		} 
//		cout<<s.top()<<" ";
//		s.pop();count++; 
//	}
//	//将剩余的元素输出
//	while(!s.empty()){
//		cout<<s.top()<<" ";
//		s.pop(); 
//	} 
//	return 0;
//}


//https://www.luogu.com.cn/problem/P1714
//#include<bits/stdc++.h>
//using namespace std;
//const int N=5e5+1, INF=-1e9;
//int n,m,sum[N],q[N];
//
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		int x;cin>>x;
//		sum[i]=sum[i-1]+x;
//	}
//	//使用单调队列
//	int head=1, tail=1,ans=INF;//头部和尾部指针 
//	for(int i=1;i<=n;i++){
//		while(head<=tail && q[head]<i-m)	head++;
//		ans=max(ans,sum[i]-sum[q[head]]);
//		while(head<=tail && sum[i]<=sum[q[tail]])	tail--;
//		q[++tail]=i;
//	} 
//	cout<<ans<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/3535/learning/?problem_list_id=26&page=1
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int P=1e9+7;
//const int N=1001;
//
//int T,n,sum=0,arr[N],dp[N][2];
////dp[n][0]为偶数个数，dp[n][1]为奇数个数 
//
//int solve(){
//	memset(dp,0,sizeof(dp));
//	dp[0][0]=1;
//	for(int i=0;i<n;i++){
//		//为奇数 
//		if(arr[i]%2){
//			dp[i+1][0]=dp[i][0]+dp[i][1];
//			dp[i+1][1]=dp[i][0]+dp[i][1];
//		}else{
//			dp[i+1][0]=dp[i][0]*2;
//			dp[i+1][1]=dp[i][1]*2; 
//		}
//		dp[i+1][0]%=P;
//		dp[i+1][1]%=P;
//	}
//	return dp[n][0];
//}
//
//signed main(){
//	cin>>T;
//	while(T--){
//		memset(arr,0,sizeof(arr));
//		cin>>n;sum=0;
//		for(int i=0;i<n;i++){
//			cin>>arr[i];
//			sum+=arr[i];
//		}
//		if(sum%2)	cout<<0<<endl;
//		else	cout<<solve()<<endl;
//	}
//	return 0;
//} 


//https://www.lanqiao.cn/problems/12117/learning/?contest_id=160
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=1e5+2;
//int n,sum=0,arr[N],pre[N],back[N];
//
//signed main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>arr[i];
//		pre[i]=max(pre[i-1],arr[i]);
//	}
//	for(int i=n;i>=1;i--)	back[i]=max(back[i+1],arr[i]);
//	for(int i=2;i<n;i++){
//		int x=(pre[i-1]+back[i+1])/arr[i];
//		sum=max(sum,x);
//	}
//	cout<<sum<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/12118/learning/?contest_id=160
//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+1;
//
//int main(){
//	int n,num1,num2,num=0;char s[N];
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>s[i];
//		num1+=(s[i]-'0')*(i-num);
//		num+=s[i]-'0'; 
//	} 
//	num=0;
//	for(int i=n-1;i>=0;i--){
//		num2+=(s[i]-'0')*(n-1-i-num);
//		num+=s[i]-'0';
//	}
//	num=num1>num2?num2:num1;
//	cout<<num<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/12110/learning/?contest_id=160
//#include<bits/stdc++.h>
//using namespace std;
//int T,a,b,c;
//
//int main(){
//	cin>>T;
//	while(T--){
//		cin>>a>>b>>c;
//		int x=(a+c-1)/c;
//		int res=(b+x-1)/x;
//		cout<<res<<endl;
//	}
//	return 0;
//}



//https://www.lanqiao.cn/problems/12116/learning/?contest_id=160
# include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+1;
int n,k,a[N],b[N],minn=1e18,sum=0,ans=1e18;

signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	int m=min(n,k);
	for(int i=1;i<=m;i++){
		sum+=a[i];
		minn=min(minn,a[i]+b[i]);
		ans=min(ans,sum+(k-i)*minn);
	}
	cout<<ans<<endl;
	return 0;
} 
