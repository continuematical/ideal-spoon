#include<bits/stdc++.h>
using namespace std;  
const int N=3e6+1;
stack<int> s;
int n, arr[N], f[N]; 

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)	scanf("%d", &arr[i]);
	for(int i=n;i>0;i--){
		while(!s.empty() && arr[s.top()]<=arr[i])	s.pop();
		f[i]=s.empty() ? 0 : s.top();
		s.push(i);
	}
	for(int i=1;i<=n;i++)	printf("%d ",f[i]);
} 
