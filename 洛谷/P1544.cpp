#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=101;
int n,k,a[N][N],dp[N][N][5055],maxx=-3e9;
//层数 个数 
signed main(){
	cin>>n>>k;
	
	//初始化
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int l=0;l<=k;l++){
				dp[i][j][l]=-3e9;
			}
		}
	} 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
			for(int l=0;l<=k && l<=i;l++){
				if(!l)	dp[i][j][l]=max(dp[i-1][j][l], dp[i-1][j-1][l])+a[i][j];
				else{
					dp[i][j][l]=max(dp[i-1][j][l],dp[i-1][j-1][l])+a[i][j];
					dp[i][j][l]=max(dp[i][j][l],max(dp[i-1][j][l-1],dp[i-1][j-1][l-1])+a[i][j]*3);
				}
			}
		}
	}
	
	k=min(k,n);
	for(int j=1;j<=n;j++){
		for(int i=0;i<=k;i++){
			maxx=max(maxx,dp[n][j][i]);
		}
	}
	cout<<maxx<<endl;
	return 0;
} 
