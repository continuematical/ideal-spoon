#include<bits/stdc++.h>
using namespace std; 
const int N=1e6+1;
int n,p[N];


int main(){
	stack<int> stk;
	scanf("%d", &n);
	vector<int> S;
	for(int i=0;i<n;i++)	scanf("%d", &p[i]); 
	for(int i=0;i<n;i++) {
  		while (!stk.empty() && p[i] <= p[stk.top()]) stk.pop();
  		stk.push(i);
  		S.push_back((int)stk.size());
	}
	for(int i=0;i<n;i++)	printf("%d ",S[i]);
	return 0;
} 
