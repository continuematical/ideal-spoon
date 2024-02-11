//https://www.lanqiao.cn/problems/3539/learning/?page=1&first_category_id=1&second_category_id=3&problem_id=3539 
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=5e5+1;
//
//int n, arr[N], buy[N];
//queue<int> nums, f;//免费商品队列 
//
//signed main(){
//	cin>>n;
//	for(int i=1;i<=n;i++)	cin>>arr[i];
//	sort(arr+1,arr+n+1,greater<int>());
//	for(int i=1;i<=n;i++)	nums.push(arr[i]);
//	int res=0, i=0;//购买总价钱 
//	while(!nums.empty()){
//		int x=nums.front();nums.pop();
//		if(!f.empty() && x<=f.front()){
//			f.pop();
//			continue;
//		}
//		buy[++i]=x;
//		if(i>=2){
//			res+=buy[1]+buy[2];
//			f.push(min(buy[1],buy[2])/2);
//			i=0;
//		}
//	}
//	while(i>=1){
//		res+=buy[i--];
//	}
//	cout<<res<<endl;
//	return 0;
//} 


//https://www.lanqiao.cn/problems/3541/learning/?page=1&first_category_id=1&second_category_id=3&problem_id=3541
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;

typedef struct Node{
	int k;
	int b;
	int x;
	int increase;
	
	bool operator < (const Node& other) const {
		return this->increase<other.increase;
	} 
	
}Node;

int n,m;
priority_queue<Node> q;

signed main(){
	cin>>n>>m;
	Node node{0,0,0,0};
	for(int i=1;i<=m;i++){
		cin>>node.k>>node.b;
		node.increase=node.k+node.b;
		if(node.increase<0)	continue;
		node.x=1;
		q.push(node);
	}
	int res=0;
	//i表示人数 
	for(int i=0;i<n && !q.empty();i++){
		Node node=q.top();q.pop();
		res+=node.increase;
		node.increase=node.k*(2*node.x+1)+node.b;
		if(node.increase<0)	continue;
		node.x+=1;
		q.push(node); 
	} 
	cout<<res<<endl;
	return 0;
} 
