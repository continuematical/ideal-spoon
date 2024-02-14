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
//	//count���Ѿ���ջ��Ԫ�ظ��� 
//	while(count+s.size()<n){
//		int min=2e9;
//		//ѡ��c-s.size()��Ԫ������С��Ԫ�� 
//		for(int i=k;i<k+c-s.size() && i<n;i++){
//			if(arr[i]<min){
//				min=arr[i];
//				pos=i;
//			} 
//		} 
//		//��ջ
//		if(s.empty() || s.top()>=min){
//			//�ѱ�posС��Ԫ����ջ 
//			for(int i=k;i<=pos;i++)	s.push(arr[i]);
//			k=pos+1;
//		} 
//		cout<<s.top()<<" ";
//		s.pop();count++; 
//	}
//	//��ʣ���Ԫ�����
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
