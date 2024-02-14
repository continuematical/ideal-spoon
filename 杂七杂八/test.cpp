//https://www.luogu.com.cn/problem/P1750 
//#include<bits/stdc++.h>
//using namespace std; 
//#define int long long
//const int N=1e4+1;
//
//int n,c,arr[N];
//
//signed main(){
//	cin>>n>>c;
//	for(int i=0;i<n;i++)	cin>>arr[i]; 
//	stack<int> s;
//	int k=0, count=0, pos=0;
//	//count是已经出栈的元素个数 
//	while(count+s.size()<n){
//		int min=2e9;
//		//选出c-s.size()个元素中最小的元素 
//		for(int i=k;i<k+c-s.size() && i<n;i++){
//			if(arr[i]<min){
//				min=arr[i];
//				pos=i;
//			} 
//		} 
//		//入栈
//		if(s.empty() || s.top()>=min){
//			//把比pos小的元素入栈 
//			for(int i=k;i<=pos;i++)	s.push(arr[i]);
//			k=pos+1;
//		} 
//		cout<<s.top()<<" ";
//		s.pop();count++; 
//	}
//	//将剩余的元素输出
//	while(!s.empty()){
//		cout<<s.top()<<" ";
//		s.pop(); 
//	} 
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int w,n,arr[30001],res=0,temp; 

int main(){
	cin>>w>>n;
	for(int i=1;i<=n;i++)	cin>>arr[i];
	sort(arr+1,arr+1+n);
	int i=1,j=n;
	while(i<=j){
		if(arr[i]+arr[j]<=w){
			i++;j--;
			res++;
		}else{
			j--;res++;
		}
	} 
	cout<<res<<endl;
	return 0;
} 
