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


