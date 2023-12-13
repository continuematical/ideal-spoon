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
const int N=2e5+1; 
int f[N];

int find(int x){
	if(f[x]==x)	return x;
	else	return find(f[x]);
}

void merge(int x, int y){
	f[find(x)]=find(y);
}

int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)	f[i]=i;
	while(m--){
		int op,a,b;cin>>op>>a>>b;
		if(op==1){
			merge(a,b);
		}else{
			if(find(a)==find(b))	cout<<"YES"<<endl;
			else	cout<<"NO"<<endl;
		}
	}
	return 0;
} 
