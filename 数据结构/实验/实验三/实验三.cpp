#include<bits/stdc++.h>
using namespace std;

typedef char TElemType;
const int N=100;

//23+[87a-45b(a*b)] 17 
//(23+45) 7 
//23+[87a-(45b]5*6) 18 
bool bracketCheck(string g){
	stack<TElemType> s;
	TElemType v; 
	int len=g.length();
	for(int i=0;i<len;i++){ 
		switch(g[i]){
			case '(':
			case '[':
			case '{':
				s.push(g[i]);break; 
			case ')':
				if(s.empty())	return false;
				v=s.top();s.pop();
				if(v!='(')	return false;
				break;
			case ']':
				if(s.empty())	return false;
				v=s.top();s.pop();
				if(v!='[')	return false;
				break;
			case '}':
				if(s.empty())	return false;
				v=s.top();s.pop();
				if(v!='{')	return false;
				break;
			default:
				break; 
		}
	}
	return true;
}

void test1(){
	string g;
	cin>>g; 
	if(bracketCheck(g))	cout<<"Yes";
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

int main(){
	test1();
	return 0;
}
