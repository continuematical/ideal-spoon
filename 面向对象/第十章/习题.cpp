#include<bits/stdc++.h>
using namespace std;

//1.合并两个文件 

//2.统计一篇英文文章中单词的个数和行数 

//迭代 
int words(char* line){
	bool curChar = false;
	bool preChar = false;
	int words=0;
	for(int i=0;i<strlen(line);i++){
		if(line[i]>='A' && line[i]<='Z' || line[i]>='a' && line[i]<='z')	curChar=true;
		else	curChar=false;
		if(!preChar && curChar)	words++;
		preChar = curChar;
	}
	return words;
}

void solve(){
	fstream file("D:\\record.txt");
	if(!file){
		cerr<<"record.txt open wrong!"<<endl;
		exit(1);
	} 
	//行数，单词数
	int line=0, number=0;
	char word[100];
	while(file.getline(word, 100)){
		number += words(word);
		line++;
	} 
	file.close();
	printf("行数为:\n");
	cout<<line<<endl;
	printf("列数为:\n");
	cout<<number<<endl;
}

//使用map统计每个单词出现的个数 
void check(){
	fstream file("D:\\record.txt");
	map<string, int> res;
	if(!file){
		cerr<<"record.txt open wrong!"<<endl;
		exit(1);
	} 
	char line[100];
	while(file.getline(line, 100)){
		if(res.find(line)!=res.end())	res[line]+=1;
		else	res[line]=1;
	}
	file.close();
	//迭代
	map<string, int> ::iterator ite; 
	for(ite=res.begin();ite!=res.end();ite++)
		cout<<ite->first<<":"<<ite->second<<endl;
} 

//3.在c++源程序每一行前面加上一个行号和空格
void add(){
	fstream sourcefile("D:\\record.txt");
	fstream targetfile("D:\\target.txt", ios::out);
	
	if(!sourcefile){
		cerr<<"sourcefile open wrong!"<<endl;
		exit(1);
	} 
	
	if(!targetfile){
		cerr<<"targetfile open or create wrong!"<<endl;
		exit(1);
	} 
	char line[100];
	int i=1;//行号 
	while(sourcefile.getline(line,100)){
		targetfile<<i<<" "<<line<<endl;
		i++;
	}
	sourcefile.close();
	targetfile.close();
} 

//4.输出ASCII码值从20到127的字符表，格式为每行十个

//6.定义一个student类，并且保存到文件中
class Student{
	private:
		long number;
		char* name;
		int score;
	public:
		Student(long=0, char* = NULL, int=0);
		
		void showStudent(){
			cout<<number<<'\t'<<name<<'\t'<<score<<endl;
		}
}; 

Student::Student(long number, char* name, int score):number(number),name(name),score(score){
	
		}

void store(char* filename){
	Student s[3]={Student{20221234,"Zhangsan",97},
				  Student{20221235,"Lisi",84},
				  Student{20221236,"Wangwu",65}};
	fstream file(filename,ios::in|ios::out|ios::binary|ios::trunc);
	if(!file){
		cerr<<"file open or create wrong!"<<endl;
		exit(1);
	} 
	//将对象写入文件
	for(int i=0;i<3;i++){
		file.write((char*)&s[i],sizeof(s[i]));
	} 
	//从文件中读取对象
	Student st;
	file.seekg(0,ios::beg); 
	//为了避免重复，先读取一遍 
	file.read((char*)&st, sizeof(st));
	cout<<"Output object from file:"<<endl;
	while(!file.eof()){
		st.showStudent();
		file.read((char*)&st, sizeof(st));
	}
	file.close();
}

int main(){
	
	return 0;
} 
