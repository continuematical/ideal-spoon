#include<bits/stdc++.h>
using namespace std;

//https://www.lanqiao.cn/problems/6267/learning/?problem_list_id=23&page=1
//int main(){
//	int sum=0, num=0;
//	while(sum<23){
//		num++;
//		int one=0;
//		for(int i=num;i>0;i=i>>1){
//			if(i&1)	one++;
//		}
//		if(one==3)	sum++;
//	}
//	cout<<num<<endl;
//	return 0;
//} 

//https://www.lanqiao.cn/problems/2412/learning/?problem_list_id=23&page=1
//int vis[101][101];
//
//double dis(double x1, double y1, double x2, double y2){
//	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//
//int main(){
//	double W,H,n,R;
//	scanf("%lf %lf %lf %lf", &W, &H, &n, &R);
//	for(int i=0;i<n;i++){
//		int x,y;cin>>x>>y;
//		int left=max(0.0,x-R);
//		int right=min(x+R,W);
//		int height=min(H,y+R);
//		int bottom=max(0.0,y-R);
//		for(int m=left;m<=right;m++){
//			for(int k=bottom;k<=height;k++){
//				if(dis(m,k,x,y)<=R)	vis[m][k]=1;
//			}
//		}
//	}
//	int sum=0;
//	for(int i=0;i<=W;i++){
//		for(int j=0;j<=H;j++){
//			if(vis[i][j])	sum++;
//		}
//	}
//	cout<<sum<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/6276/learning/?problem_list_id=23&page=2
//int arr[1001];
//int main(){
//	int n;cin>>n;
//	for(int i=0;i<n;i++)	cin>>arr[i];
//	int maxx=0;
//	for(int i=1;i<n-1;i++)
//		if(arr[i]<arr[i-1] && arr[i]<arr[i+1])	
//			maxx=max(maxx, (arr[i-1]-arr[i])*(arr[i+1]-arr[i]));
//	cout<<maxx<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/2410/learning/?problem_list_id=23&page=1
//int dis[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//int vis[35][65]={0};
//char ch[35][65];
//int num=0, res=0;
//
//void dfs(int x, int y){
//	if(x<1 || x>30 || y<1 || y>60 || vis[x][y] || ch[x][y]=='0')	return;
//	vis[x][y]=1;num++;
//	for(int i=0;i<4;i++){
//		int tx=x+dis[i][0];
//		int ty=y+dis[i][1];
//		dfs(tx,ty);
//	}
//} 
//
//int main(){
//	for(int i=1;i<=30;i++)
//		for(int j=1;j<=60;j++)
//			cin>>ch[i][j];
//	//对每个位置进行连通
//	for(int i=1;i<=30;i++)
//		for(int j=1;j<=60;j++){
//			num=0;
//			dfs(i,j);
//			res=max(res, num);
//		} 
//	cout<<res<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/1135/learning/?page=1&first_category_id=1&second_category_id=8
//并查集
//const int N=2e5+1; 
//int f[N];
//
//int find(int x){
//	if(f[x]==x)	return x;
//	else	return find(f[x]);
//}
//
//void merge(int x, int y){
//	f[find(x)]=find(y);
//}
//
//int main(){
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)	f[i]=i;
//	while(m--){
//		int op,a,b;cin>>op>>a>>b;
//		if(op==1){
//			merge(a,b);
//		}else{
//			if(find(a)==find(b))	cout<<"YES"<<endl;
//			else	cout<<"NO"<<endl;
//		}
//	}
//	return 0;
//} 


//https://www.luogu.com.cn/problem/P3367 
//const int N=5001;
//int f[N];
//
//int find(int x){
//	if(f[x]==x)	return x;
//	else	return find(f[x]);
//}
//
//void merge(int x, int y){
//	f[find(x)]=find(y);
//}
//
//int main(){
//	int n,m,p;
//	cin>>n>>m>>p;
//	for(int i=1;i<=n;i++)	f[i]=i;
//	while(m--){
//		int x,y;cin>>x>>y;
//		merge(x,y);
//	}
//	while(p--){
//		int x,y;cin>>x>>y;
//		if(find(x)==find(y))	cout<<"Yes"<<endl;
//		else	cout<<"No"<<endl;
//	}
//	return 0;
//}


//https://www.luogu.com.cn/problem/P1536
//const int N=1001;
//int f[N], n, m, x, y; 
//
//int find(int x){
//	if(f[x]==x)	return x;
//	else	return find(f[x]);
//}
//
//void merge(int x, int y){
//	f[find(x)]=find(y);
//}
//
//void init(int n){
//	for(int i=1;i<=n;i++)	f[i]=i;
//}
//
//int main(){
//	while(true){
//		int ans=0;//答案
//		cin>>n;
//		if(!n)	break;
//		cin>>m;
//		init(n);
//		//合并
//		for(int i=1;i<=m;i++){
//			cin>>x>>y;
//			merge(x,y);
//		} 
//		for(int i=1;i<=n;i++)
//			if(f[i]==i)	ans++;
//		cout<<ans-1<<endl;
//	} 
//	return 0;
//}


//https://www.lanqiao.cn/problems/141/learning/?page=3&first_category_id=1&second_category_id=3
//char ch[101][101];
//int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}}, vis[101][101], n, ax,ay;
//
//int dfs(int x, int y){
//	vis[x][y]=1;
//	int res=n*n;
//	if(ch[x][y]=='B')	return 0;
//	for(int i=0;i<4;i++){ 
//		int tx=x+dir[i][0];
//		int ty=y+dir[i][1];
//		if(tx<1 || tx>n || ty<1 || ty>n || vis[tx][ty])	continue; 
//		if(ch[x][y] != ch[tx][ty]){
//			int num=dfs(tx, ty)+1;
//			res=res<num ? res : num;
//			vis[tx][ty]=0;
//		}
//	}
//	return res;
//}
//
//void init(int n){
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			vis[i][j]=0;
//}
//
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++){
//			cin>>ch[i][j]; 
//			if(ch[i][j]=='A'){
//				ax=i,ay=j;
//			}
//		}
//	init(n);
//	int res=dfs(ax, ay);
//	if(res==n*n)	cout<<-1<<endl;
//	else	cout<<res<<endl;
//	return 0;
//}


//char ch[101][101];
//int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}}, vis[101][101], res, n, ax,ay;
//
//void dfs(int x, int y, int num){
//	vis[x][y]=1;
//	if(ch[x][y]=='B'){ 
//		res=min(res, num);
//		return;
//	}
//	for(int i=0;i<4;i++){ 
//		int tx=x+dir[i][0];
//		int ty=y+dir[i][1];
//		if(tx<1 || tx>n || ty<1 || ty>n || vis[tx][ty])	continue; 
//		if(ch[x][y] != ch[tx][ty]){
//			dfs(tx, ty, num+1);
//			vis[tx][ty]=0;
//		}
//	}
//}
//
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++){
//			cin>>ch[i][j]; 
//			if(ch[i][j]=='A'){
//				ax=i,ay=j;
//			}
//		}
//	res=n*n;
//	dfs(ax, ay, 0);
//	if(res==n*n)	cout<<-1<<endl;
//	else	cout<<res<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/1136/learning/?page=1&first_category_id=1&second_category_id=8
//int main(){
//	
//	return 0;
//} 


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


//https://www.lanqiao.cn/problems/1231/learning/?page=2&first_category_id=1&second_category_id=8
//double x_1, y_1, x_2, y_2, x_3, y_3;
//
//double getDis(double x1, double y1, double x2, double y2){
//	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//} 
//
//double getS(double a, double b, double c){
//	double p=(a+b+c)/2;
//	return sqrt(p*(p-a)*(p-b)*(p-c));
//}
//
//int main(){
//	int T;cin>>T;
//	while(T--){
//		scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3);
//		double a=getDis(x_1, y_1, x_2, y_2);
//		double b=getDis(x_2, y_2, x_3, y_3);
//		double c=getDis(x_1, y_1, x_3, y_3);
//		printf("%.2lf\n", getS(a, b, c));
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


//https://www.lanqiao.cn/problems/324/learning/?page=2&first_category_id=1&second_category_id=6
//int main(){
//	int N;cin>>N;
//	int h=1;
//	for(int i=1;i<=N;i++){
//		if(i%2)	h*=2;
//		else	h+=1;
//	}
//	cout<<h<<endl;
//	return 0;
//}

//https://www.lanqiao.cn/problems/153/learning/?page=2&first_category_id=1&second_category_id=3

//int get(int x){
//	while(x){
//		int a=x%10;
//		if(a==2)	return 0;
//		x/=10;
//	}
//	return 1;
//}
//
//int main(){
//	int n, res=0;cin>>n;
//	for(int i=1;i<=n;i++){
//		if(get(i))	res++;
//	}
//	cout<<res<<endl;
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


//https://www.luogu.com.cn/problem/P3379
//LCA
//#define int long long
//const int N=5e5+1;
//
//struct e{
//	int next;
//	int to;
//}e[N<<1];
//
//int n,m,s, cnt=0, f[N][21], head[N], depth[N];
//
//void add(int u, int v){
//	e[++cnt].next=head[u];
//	head[u]=cnt;
//	e[cnt].to=v;
//}
//
//void dfs(int now, int fath){
//	f[now][0]=fath;depth[now]=depth[fath]+1;
//	for(int i=1;(1<<i)<=depth[now];i++)
//		f[now][i]=f[f[now][i-1]][i-1];
//	for(int i=head[now];i;i=e[i].next)
//		if(e[i].to != fath)	dfs(e[i].to, now);
//}
//
//int LCA(int u, int v){
//	if(depth[u]<depth[v])	swap(u,v);
//	for(int i=20;i>=0;i--)
//		if(depth[v]<=depth[u]-(1<<i))
//			u=f[u][v];
//	if(u==v)	return u;
//	for(int k=20;k>=0;k--)
//		if(f[u][k]!=f[v][k])
//			u=f[u][k], v=f[u][k];
//	return f[u][0];
//} 
//
//void init(){
//	for(int i=1;i<n;i++){
//		int u,v;cin>>u>>v;
//		add(u, v);add(u, v);
//	}
//} 
//
//signed main(){
//	cin>>n>>m>>s;
//	init();
//	dfs(s,0);
//	for(int i=1;i<=m;i++){
//		int u,v;cin>>u>>v;
//		cout<<LCA(u,v)<<endl;
//	}
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


//https://www.lanqiao.cn/problems/1371/learning/?page=1&first_category_id=1&second_category_id=8
//int main(){
//	string st;cin>>st;
//	int s=0, e=st.length()-1;
//	while(s<e){
//		if(st[s] != st[e]){
//			cout<<"N"<<endl;
//			return 0;
//		}
//		s++;
//		e--;
//	}
//	cout<<"Y"<<endl;
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


//https://www.lanqiao.cn/problems/108/learning/?page=1&first_category_id=1&second_category_id=3
//const int N=1e5+1;
//vector<int> ins[N];
//int g[N]; 
//
//int add(int u, int v){
//	g[u]++;
//	g[v]++;
//	ins[u].push_back(v);
//	ins[v].push_back(u);
//}
//
//int main(){
//	int n;cin>>n;
//	for(int i=1;i<=n;i++){
//		int u, v;cin>>u>>v;
//		add(u,v);
//	}
//	queue<int> q;
//	for(int i=1;i<=n;i++)
//		if(g[i]==1)
//			q.push(i);
//	
//	while(!q.empty()){
//		int x=q.front();q.pop();
//		for(int i=0;i<ins[i].size();i++){
//			g[ins[x][i]]--;
//			if(g[ins[x][i]]==1)	q.push(ins[x][i]);
//		}
//	}
//	
//	for(int i=1;i<=n;i++){
//		if(g[i]>1)	cout<<i<<" ";
//	}
//	return 0;
//} 


//https://www.lanqiao.cn/problems/110/learning/?page=1&first_category_id=1&second_category_id=3
//const int N=1e6+1;
//int f[N], m, n, k;
//set<int> s;
//
//int find(int x){
//	return f[x]==x ? x : f[x]=find(f[x]);
//}
//
//void merge(int x, int y){
//	f[find(x)]=find(y);
//}
//
//void init(){
//	for(int i=1;i<=m*n;i++)	f[i]=i;
//}
//
//int main(){
//	cin>>m>>n>>k;
//	init();
//	while(k--){
//		int x, y;cin>>x>>y;
//		merge(x, y);
//	}
//	for(int i=1;i<=m*n;i++)
//		s.insert(find(i));
//	cout<<s.size()<<endl;
//	return 0;
//}


int main(){
	
	return 0;
} 
