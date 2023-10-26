#include<bits/stdc++.h>
using namespace std;

const int MAXM=10000001;
queue<int> q, last[301];
int group[MAXM];

int read(int &n){
	char c='.';
	int x=0,flag=0;
	while(c<'0'||c>'9'){
		c=getchar();
		if(c=='-')	flag=1;
	}
	while(c>'0'&&c<'9'){
		x=x*10+(c-48);
		c=getchar();
	}
	if(flag==1)	n=-x;
	else	n=x;
}

int main(){
	int n,m,T,p;
	read(n);read(m);
	for(int i=0;i<n;i++)	read(group[i]);
	read(T);
	while(T--){
		string s;cin>>s;
		if(s=="push"){
			read(p);
			if(last[group[p]].empty())	q.push(group[p]);
			last[group[p]].push(p);
		} else{
			printf("%d\n",last[q.front()].front());
			last[q.front()].pop();
			if(last[q.front()].empty())	q.pop();
		}
	}
	return 0;
}
