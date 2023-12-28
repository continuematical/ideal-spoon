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


#include<bits/stdc++.h>
using namespace std;
const int N=1e10;

int main(){
	long long int sum=0, temp=1;
	int i=1;
	while(i<=202320232023){
		temp=(temp*i)%N;
		sum=(sum+temp)%N;
		i++;
	}
	cout<<sum<<endl;
	return 0;
} 
