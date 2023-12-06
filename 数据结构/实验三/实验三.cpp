#include<bits/stdc++.h>
using namespace std;

typedef char TElemType;
const int N=100;
TElemType g[N];

//23+[87a-45b(a*b)] 17 
//(23+45) 7 
//23+[87a- (45b]5*6) 18 
bool bracketCheck(TElemType num[], int n){
	stack<TElemType> s;
	TElemType v; 
	for(int i=0;i<n;i++){
		switch(num[i]){
			case '(':s.push(num[i]);break;
			case '[':s.push(num[i]);break;
			case '{':s.push(num[i]);break;
			case ')':
				v=s.top();s.pop();
				if(v!='(')	return false;
				break;
			case ']':
				v=s.top();s.pop();
				if(v!='[')	return false;
				break;
			case '}':
				v=s.top();s.pop();
				if(v!='{')	return false;
				break;
		}
	}
	return true;
}

void test1(){
	printf("ÇëÊäÈëÄãµÄ×ÖÄ¸×éºÏÊý×Ö£º\n");
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char ch;scanf("%c", &ch);
		g[i]=ch;
	}
	if(bracketCheck(g, n))	cout<<"Yes";
	else	cout<<"No"<<endl;
} 

void test2(){
	stack<TElemType> s1;
	stack<TElemType> s2;
	stack<TElemType> s3;
	int num, flag=0;
	
	printf("ÇëÊäÈë×Ö·ûÊý×Ö£º\n");
	cin>>num;
	while(num--){
		TElemType ch;scanf("%c", &ch);
		s1.push(ch);
		s2.push(ch);
	}
	while(!s2.empty()){
		TElemType c=s2.top();s2.pop();
		s3.push(c);
	}
	for(int i=0;i<num;i++){
		if(s1.top() != s3.top())	flag=1;
		s1.pop();s3.pop();
	}
	if(flag)	cout<<"No"<<endl;
	else	cout<<"Yes"<<endl;
}

void test3(){
	
} 

int main(){
	test1();
	return 0;
}
