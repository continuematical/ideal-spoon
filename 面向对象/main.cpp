#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=100;

//单词查询 
bool compareEnglish(char line[], string input){
	for(int i=0;i<input.length();i++){
		if(line[i]!=input[i])	return false;
	}
	return true;
}

bool check(string input){
	if(( input[0]>='a' && input[0]<='z') || (input[0]>='A' && input[0]<='Z'))	return true;
	else	return false; 
} 

int main(){
	fstream file("D:\\四级.txt", ios::in);
	if(!file){
		cerr<<"File open wrong!"<<endl;
		exit(-1); 
	}
	char line[MAX_SIZE];
	string input;cin>>input;
	while(!file.eof()){
		file.getline(line,100);
		if(compareEnglish(line, input))	cout<<line<<endl; 
	}
	file.close();
	return 0;
} 
