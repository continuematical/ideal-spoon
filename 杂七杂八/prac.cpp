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
int main(){
	int n;
	vector<int> start,ends; 
	for(int i=0;i<n;i++){
		cin>>start[i]>>ends[i];
	} 
	sort(start.begin(), start.end());
	sort(ends.begin(), ends.end());
	int res=0,j=0;
	for(int i=0;i<n;i++){
		if(start[i]>=ends[j])	j++;
		else	res++;
	}
	cout<<res<<endl;
	return 0;
} 
