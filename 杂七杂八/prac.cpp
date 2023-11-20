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


