#include<bits/stdc++.h>
using namespace std;

//门牌制作 

//int calu(int num){
//	int k,res=0;
//	while(num){
//		k=num%10;
//		if(k==2)	res++;
//		num/=10;
//	}
//	return res;
//}
//
//int main(){
//	int res=0;
//	for(int i=1;i<=2020;i++){
//		res+=calu(i);
//	}
//	cout<<res<<endl;
//} 

//既约分数

//int gcd(int x, int y){
//	if(!y)	return x;
//	else	gcd(y, x%y);
//}
//
//int main(){
//	int res=0;
//	for(int i=1;i<=2020;i++){
//		for(int j=1;j<=2020;j++){
//			if(gcd(i,j)==1)	res++;
//		}
//	}
//	cout<<res<<endl;
//	return 0;
//} 


//第三题 蛇形填数

//int main(){
//	int r,c;//行 列
//	cin>>r>>c;
//	r=2*r-1;
//	int ans = 0,sum =  0;
//	for(int i = 1; i<=r ;i++)
//		sum+=i; 
//	ans = (sum+sum-r+1)/2;
// 	cout<<ans<<endl;
//	return 0;
//} 

//成绩统计

//int n, maxx=0, minn=INT_MAX;
//double sum; 
//
//int main(){
//	cin>>n;
//	for(int i=0;i<n;i++){
//		int x;cin>>x;
//		if(x>maxx)	maxx=x;
//		if(x<minn)	minn=x;
//		sum+=x;
//	}
//	cout<<maxx<<endl;
//	cout<<minn<<endl;
//	double avg=sum/n;
//	printf("%.2lf",avg); 
//	return 0;
//} 



//字符串排序 
//获取长度为 m 的字符串的最大逆序对数
//int f[1010],n;
//int get_max(){
//	for(int i=2;i<=26;i++)	f[i]=f[i-1]+i-1;
//	int sum=26,vis[30];
//	//记录当前字符串已经给各个字符串一个了 
//	for(int i=0;i<26;i++)	vis[i]=1;
//	for(int i=27;f[i-1]<n;i++,sum++){
//		int ch=(i%26-1+26)%26;
//		//总字符数目-相同的字符数目 
//		f[i]=f[i-1]+sum-vis[ch];vis[ch]++;
//	}
//} 
//
////cnt代表已经确定的构造符序列 
//int cnt[30],vis[30];
//int get_add(int ch){
//	int add=0;
//	for(int i=0;i<ch;i++)	add+=vis[i];
//	for(int i=ch+1;i<26;i++)	add+=cnt[i]+vis[i];
//	return add;
//}
//
//bool check(int id, int m, int ch, int sum){
//	for(int i=id+1;i<=m;i++){
//		int maxadd=0,chl=0;
//		for(int j=0;j<26;j++){
//			int add=get_add(j);
//			if(maxadd<add){
//				maxadd=add;
//				chl=j;
//			}
//		} 
//		vis[chl]++;
//		sum+=maxadd;
//	}
//	memset(vis,0,sizeof vis);
//	if(sum>=n)	return true;
//	else	false;
//}
//
////m为字符串的长度 
//void solve(int m){
//	int sum=0;string ans;
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<26;j++){
//			int initadd=get_add(j);
//			cnt[j]++;
//			sum+=initadd;
//			if(check(i,m,j,sum)){
//				ans+=('a'+j);
//				break;
//			}
//			cnt[j]--;
//			sum-=initadd;
//		}
//	}
//	cout<<ans<<endl;
//}
//
//int main(){
//	cin>>n;
//	get_max();
//	for(int i=2;i<=n;i++){
//		if(f[i]>=n){
//			solve(i);
//			break;
//		}
//	}
//	return 0;
//}



//贪心
//int main(){
//	int n;
//	vector<int> start,ends; 
//	for(int i=0;i<n;i++){
//		cin>>start[i]>>ends[i];
//	} 
//	sort(start.begin(), start.end());
//	sort(ends.begin(), ends.end());
//	int res=0,j=0;
//	for(int i=0;i<n;i++){
//		if(start[i]>=ends[j])	j++;
//		else	res++;
//	}
//	cout<<res<<endl;
//	return 0;
//} 


//循环输出字符串 
//int main(){
//	int ch;cin>>ch;
//	for(int i=1;i<=ch;i++){
//		for(int j=0;j<ch-i;j++)	cout<<" ";
//		for(int j=0;j<i;j++)	cout<<(char)(j+'A');
//		for(int j=i-2;j>=0;j--)	cout<<(char)(j+'A');
//		for(int j=0;j<ch-i;j++)	cout<<" ";
//		cout<<endl; 
//	} 
//	return 0;
//} 

//int main(){
//	int r,c;cin>>r>>c;
//	for(int i=1;i<=r;i++){
//		for(int j=1;j<=c;j++)	cout<<"+-";
//		cout<<"+"<<endl;
//		for(int j=1;j<=c;j++)	cout<<"|*";
//		cout<<"|"<<endl;
//		if(i==r){
//			for(int j=1;j<=c;j++)	cout<<"+-";
//			cout<<"+"<<endl;
//		}
//	}
//	return 0;
//} 

//质数筛 
//const int N=1e7+1;
//int arr[N], primes[N], cnt=0;
//int main(){
//	for(int i=2;i<=N;i++){
//		if(!arr[i])	primes[cnt++]=i;
//		for(int j=0;primes[j]<=N/i;j++){
//			arr[primes[j]*i]=1;
//			if(i%primes[j]==0)	break;
//		}
//	}
//	
//	cout<<primes[2018]<<endl;
//}interesting 

//int main(){
//	int num[100]={5650,4542, 3554, 473, 946, 4114 ,3871, 9073, 90, 4329,
//                   2758, 7949, 6113, 5659, 5245, 7432, 3051, 4434, 6704, 3594,
//                   9937, 1173, 6866, 3397, 4759, 7557 ,3070, 2287, 1453, 9899,
//                   1486 ,5722, 3135, 1170, 4014, 5510, 5120, 729, 2880, 9019,
//                   2049, 698, 4582, 4346, 4427, 646, 9742, 7340, 1230, 7683,
//                   5693, 7015, 6887, 7381, 4172, 4341, 2909, 2027, 7355, 5649,
//                   6701 ,6645, 1671, 5978, 2704, 9926, 295, 3125, 3878, 6785,
//                   2066 ,4247, 4800, 1578, 6652, 4616, 1113, 6205, 3264, 2915,
//                   3966 ,5291 ,2904 ,1285, 2193, 1428 ,2265 ,8730 ,9436, 7074,
//                   689,5510 ,8243, 6114, 337, 4096, 8199 ,7313 ,3685, 211};
//    int a=0,b=0;
//	for(int i=0;i<100;i++){
//		int ret=num[i];
//		while(ret%2==0){
//			a++;ret/=2;
//		}
//		while(ret%5==0){
//			b++;ret/=5;
//		}
//	}
//	cout<<min(a,b)<<endl;
//	return 0;
//} 

//
//int main(){
//	int i=0,cnt=0;
//	while(1){
//		int t=0;
//		for(int j=0;i<30;j++){
//			if((i>>j)&1)	t++;
//		}
//		if(t==3){
//			++cnt;
//			cout<<i<<endl;
//			if(cnt>23)	break;
//		}
//		i++;
//	}
//	return 0;
//}

//int getHex(int num){
//	int a;
//	while(num){
//		a=num%16;
//		if(a<=9)	return 0;
//		num=num/16;
//	}
//	return 1; 
//}
//int main(){
//	int num=2023;
//	while(1){
//		if(getHex(num))	break;
//		else	num++;
//	}
//	cout<<num<<endl;
//	return 0;
//}

//int main(){
//	int res=0;
//	int num[30]={99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};
//	for(int i=0;i<30;i++){
//		for(int j=i+1;j<30;j++){
//			if(num[i]*num[j]>=2022)	res++;
//		}
//	}
//	cout<<res<<endl;
//	return 0;
//}

//int main(){
//	int n,m,t,r1,c1,r2,c2,res=0;
//	cin>>n>>m;
//	cin>>t;
//	int max[n+1][m+1];
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			max[i][j]=0; 
//	while(t--){
//		cin>>r1>>c1>>r2>>c2;
//		for(int i=r1;i<=r2;i++){
//			for(int j=c1;j<=c2;j++){
//				if(!max[i][j]){
//					max[i][j]=1;
//					res++;
//				}
//			}
//		}
//	}
//	cout<<n*m-res<<endl;
//	return 0;
//} 

//int main(){
//	int n;cin>>n;
//	int num[n+1];
//	for(int i=1;i<=n;i++){
//		cin>>num[i];
//		if(i>=3){
//			sort(num+1,num+i+1);
//			cout<<num[3]<<" ";
//		}
//	}
//}

//int main()
//{
//  // 请在此输入您的代码
//  string s;cin>>s;
//  int res[10];
//  for(int i=0;i<10;i++) res[i]=0;
//  for(int i=0;i<s.length();i++)
//    res[s[i]-'0']++;
//  for(int i=0;i<10;i++)
//    cout<<res[i]<<" ";
//  return 0;
//}


//int main(){
//	int p;cin>>p;
//	switch((p+1)%3){
//		case 0:
//			cout<<"high"<<endl;
//			break;
//		case 1:
//			cout<<"low"<<endl;
//			break;
//		case 2:
//			cout<<"mid"<<endl;
//			break;
//	}
//	return 0;
//}

//
//int w[101], sum=0, dp[101][100001];
////dp[i][j]表示前i个砝码是否能测量出重量j 
//int main(){
//	int n;cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>w[i];
//		sum+=w[i];
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=sum;j++){
//			dp[i][j]=dp[i-1][j];
//			if(!dp[i][j]){
//				if(j==w[i])	dp[i][j]=1;
//				if(dp[i-1][j+w[i]]==1)	dp[i][j]=1;
//				if(dp[i-1][abs(j-w[i])]==1)	dp[i][j]=1;
//			}
//		}
//	}
//	int res=0;
//	for(int i=1;i<=sum;i++)
//		if(dp[n][i]==1)	res++;
//	cout<<res<<endl;
//	return 0;
//}



//https://www.lanqiao.cn/problems/1460/learning/
//int gcd(int x, int y){
//	return !y ? x : gcd(y, x%y);
//}
//
//int main(){
//	int f[2022];//存储1-i的最大公倍数
//	memset(f, 0, sizeof(f));
//	for(int i=1;i<=2021;i++) {
//        for(int j=i+1;j<=i+21;j++) {
//            if(j>2021)	break;
//            if(f[j]==0)	f[j]=f[i]+j*i/gcd(j,i);
//            else    f[j]=min(f[j],f[i]+j*i/gcd(j,i));
//        }
//    } 
//    cout<<f[2021]<<endl;
//	return 0;
//}

//https://www.lanqiao.cn/problems/8735/learning/?contest_id=147
//int check(int x, int y, int z){
//	if(x+y>z && x+z>y && y+z>x && x-y<z && x-z<y && y-z<x)	return 1;
//	else	return 0;
//} 
// 
//int main(){
//	int x,y,z;cin>>x>>y>>z;
//	if(!check(x,y,z)){
//		cout<<-1<<endl;
//		return 0;
//	}
//	int s=(x+y+z)/2;
//	int S=s*(s-x)*(s-y)*(s-z);
//	cout<<S<<endl;
//	return 0;
//}


//https://leetcode.cn/problems/find-the-town-judge/
//int findJudge(int n, vector<vector<int> >& trust) {
//        //第i个人信任的人数，有多少个人信任第i个人
//        vector<int> a(n+1), b(n+1); 
//        for(int i=0;i<n;i++){
//            a[trust[i][0]]++;
//            b[trust[i][1]]++;
//        }
//        for(int i=1;i<=n;i++)
//            if(a[i]==0 && b[i]==n)  return i;
//        return -1;
//}
//
//int main(){
//	int n;cin>>n;
//	vector<vector<int> > trust;
//	cout<<findJudge(n, trust)<<endl;
//	return 0;
//}

//https://leetcode.cn/problems/next-greater-element-i/ 
//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        int m = nums1.size();
//        int n = nums2.size();
//        vector<int> res(m);
//        for (int i = 0; i < m; ++i) {
//            int j = 0;
//            while (j < n && nums2[j] != nums1[i]) {
//                ++j;
//            }
//            int k = j + 1;
//            while (k < n && nums2[k] < nums2[j]) {
//                ++k;
//            }
//            res[i] = k < n ? nums2[k] : -1;
//        }
//        return res;
//    }
//    
//void init(vector<int>& nums1, vector<int>& nums2){
//	nums1.push_back(4);
//	nums1.push_back(1);
//	nums1.push_back(2);
//	
//	nums1.push_back(1);
//	nums1.push_back(3);
//	nums1.push_back(4);
//	nums1.push_back(2);
//	return;
//}
//    
//int main(){
//	vector<int> nums1, nums2;
//	init(nums1, nums2);
//	vector<int> res=nextGreaterElement(nums1, nums2);
//	for(int i=0;i<res.size();i++)	cout<<res[i]<<" "; 
//	return 0;
//} 


//https://www.lanqiao.cn/problems/3711/learning/
//#define N 998244353
//int a[100050];
//long long dp[100050][64];
//int main(){ 
//    int n,x;
//    scanf("%d%d",&n,&x);
//    for(int i=0;i<n;i++)
//    scanf("%d",&a[i]);
//    dp[0][a[0]]=dp[0][0]=1;
//    for(int i=1;i<n;i++)
//    {
//        for(int j=0;j<64;j++)
//        {
//            dp[i][j]=dp[i-1][j]+dp[i-1][j^a[i]];
//            dp[i][j]%=N;
//        }
//    }
//    printf("%lld",dp[n-1][x]);
//}


//https://www.lanqiao.cn/problems/1121/learning/?page=1&first_category_id=1&second_category_id=8
//typedef long long ll;
//ll dis[401][401];
//const int N=0x3f3f3f3f3f3f3f3f;
//int main(){
//	ll n,m,q;cin>>n>>m>>q;
//	memset(dis, 0x3f, sizeof(dis));
//	for(ll i=1;i<=n;i++)	dis[i][i]=0;
//	for(ll i=1;i<=m;i++){
//		ll u,v,st;cin>>u>>v>>st;
//		dis[u][v]=dis[v][u]=min(dis[u][v], st);
//	}
//	for(int k=1;k<=n;k++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
//	for(int i=1;i<=q;i++){
//		int u,v;cin>>u>>v;
//		if(dis[u][v]==N)	cout<<-1<<endl;
//		else	cout<<dis[u][v]<<endl;
//	}
//	return 0;
//} 


//https://www.lanqiao.cn/problems/1122/learning/?page=1&first_category_id=1&second_category_id=8
//typedef long long ll;
//const ll N=1e6+1;
//const ll M=0x3f3f3f3f3f3f3f3f;
//
//struct Edge{
//	ll from;
//	ll to;
//	ll val;
//};
//
//struct Node{
//	ll id;
//	ll dis;
//	bool operator < (const Node& n) const{
//		return n.dis<dis;
//	}
//};
//
//vector<Edge> e[N]; 
//ll dist[N];
//bool done[N];
//
//void dijkstra(){
//	memset(dist, 0x3f, sizeof(dist)); 
//	dist[1]=0;
//	priority_queue<Node> q;
//	q.push({1,0});
//	while(!q.empty()){
//		Node u=q.top();q.pop();
//		if(done[u.id])	continue;
//		done[u.id]=1;
//		for(int i=0;i<e[u.id].size();i++){
//			Edge v=e[u.id][i];
//			if(done[v.to])	continue;
//			if(dist[v.to]>u.dis+v.val){
//				dist[v.to]=u.dis+v.val;
//				q.push({v.to, dist[v.to]});
//			}
//		}
//	}
//}
//int main(){
//	int m,n;cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		int from,to,val;cin>>from>>to>>val;
//		e[from].push_back({from, to, val});
//	}
//	dijkstra();
//	for(int i=1;i<=n;i++)
//		if(dist[i]==M)	cout<<-1<<" ";
//		else	cout<<dist[i]<<" ";
//	return 0;
//} 


//https://www.lanqiao.cn/problems/1151/learning/?page=1&first_category_id=1&second_category_id=8
//typedef long long ll;
//const ll N=3e6+1;
//ll arr[N], primes[N], f[N], cnt=0;
//int main(){
//	for(ll i=2;i<=N;i++){
//		if(!arr[i])	primes[cnt++]=i, f[i]=i;
//		for(ll j=0;primes[j]<=N/i;j++){
//			arr[primes[j]*i]=1;
//			f[primes[j]*i]=primes[j];
//			if(i%primes[j]==0)	break;
//		}
//	}
//	for(ll i=2;i<=N;i++){
//		f[i]+=f[i-1];
//	}
//	ios::sync_with_stdio(false);
//  	cin.tie(0);cout.tie(0);
//	int n;cin>>n;
//	while(n--){
//		int t;cin>>t;
//		cout<<f[t]<<"\n"; 
//	} 
//	return 0; 
//}


//https://www.lanqiao.cn/problems/7936/learning/?problem_list_id=25&page=1
//int get(int x, int radix){
//	int sum=0;
//	while(x){
//		sum+=x%radix;
//		x=x/radix;
//	}
//	return sum;
//}
//
//int main(){
//	int flag=0;
//	for(int i=1;i<=10000;i++)
//		if(get(i, 2)==get(i, 8)){
//			flag++;
//			if(flag==23)	cout<<i<<endl;
//		}
//	return 0;
//}


//https://www.lanqiao.cn/problems/7944/learning/?problem_list_id=25&page=1 
//const int N=1e3+1;
//int main(){
//	int x=0;
//	int n;int arr[N];
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>arr[i];
//		if(i>1 && arr[i]<arr[i-1])	x=max(x, arr[i-1]-arr[i]);
//	} 
//	cout<<x<<endl;
//	return 0;
//}


//https://www.lanqiao.cn/problems/7940/learning/?problem_list_id=25&page=1 
//int main(){
//	string s;cin>>s;
//	int len=s.length();
//	for(int i=len-1;i>=0;i--){
//		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
//			cout<<s[i]<<endl;
//			break;	
//		}
//	}
//	return 0;
//} 


//https://www.lanqiao.cn/problems/7938/learning/?problem_list_id=25&page=1
//char arr[35][45];
//int vis[35][45]={0};
//int dis[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
//int sum=0;
//
//void dfs(int x, int y){
//	if(x<1 || x>30 || y<1 || y>40 || vis[x][y] || arr[x][y]=='1')	return;
//	vis[x][y]=1;
//	sum++;
//	for(int i=0;i<4;i++){
//		int tx=x+dis[i][0];
//		int ty=y+dis[i][1];
//		dfs(tx, ty);
//	}
//}
//
//int main(){
//	for(int i=1;i<=30;i++){
//		for(int j=1;j<=40;j++){
//			cin>>arr[i][j];
//		}
//	}
//	dfs(1,1);
//	cout<<sum;
//	return 0;
//}

//https://www.lanqiao.cn/problems/7942/learning/?problem_list_id=25&page=1 
//struct Node{
//	int x;
//	int y;
//};
//
//const int N=101;
//int n,m,r,c,arr[N][N], sum=0;
//int dis[4][2]={{-1,0},{1,0},{0,1},{0,-1}}, vis[N][N]={0}; 
//queue<Node> q;
//
//int check(int i, int j){
//	if(!j)	return i;
//	else	return check(j, i%j);
//}
//
//void dfs(int x, int y){
//	q.push({x,y});
//	while(!q.empty()){
//		Node node=q.front();q.pop();
//		int xx=node.x;int yy=node.y;
//		for(int i=0;i<4;i++){
//			int tx=xx+dis[i][0];
//			int ty=yy+dis[i][1];
//			if(tx<1 || tx>n || ty<1 || ty>m || vis[tx][ty])	continue;
//			if(check(arr[xx][yy], arr[tx][ty])>1){
//				q.push({tx, ty});
//				vis[tx][ty]=1;
//				sum++;
//			} 
//		}
//	}
//}
//
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cin>>arr[i][j];
//	cin>>r>>c;
//	dfs(r,c);
//	cout<<sum<<endl;
//	return 0;
//}



//https://www.lanqiao.cn/problems/6277/learning/?problem_list_id=23&page=1
//int check(int x){
//	int sum=0;
//	while(x){
//		sum+=x%10;
//		x=x/10;
//	}
//	return sum;
//}
//
//int main(){
//	int minn=60, num=0;
//	for(int i=1;i<=64;i++){
//		int x;cin>>x;
//		if(check(x)<minn){
//			minn=check(x);
//			num=x;
//		} 
//	}
//	cout<<num<<endl;
//	return 0;
//} 


// https://www.luogu.com.cn/problem/P3884
#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;

inline int read(){
	int n=0;char ch=getchar();
	while(!isdigit(ch))	ch=getchar();
	while(isdigit(ch)){
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n;
}

struct Node{
	int to,next,value;
}edge[2*maxN];

int dis[maxN+1], vis[maxN+1], tot, head[maxN+1], box[maxN+1];

void addEdge(int x, int y, int w){
	edge[++tot]={y,head[x],w};
	head[x]=tot;
}

void spfa(int s){
	queue<int> q;q.push(s);
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	vis[s]=1;dis[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i;i=edge[i].next){
			if(dis[edge[i].to]>dis[x]+edge[i].value){
				dis[edge[i].to]=dis[x]+edge[i].value;
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);
				}
			}
		}
	} 
}

int n,u,v,ans;

int main(){
	n=read();
	for(int i=1;i<n;i++){
		u=read();v=read();
		addEdge(u,v,1);addEdge(v,u,2);
	}
	u=read();v=read();spfa(1);
	for(int i=1;i<=n;i++)	box[dis[i]]++,ans=max(ans,dis[i]);
	printf("%d\n",ans+1);ans=0;
	for(int i=1;i<=n;i++)	ans=max(ans,box[i]);
	printf("%d\n",ans);
	spfa(u);printf("%d\n",dis[v]);
	return 0;
}
