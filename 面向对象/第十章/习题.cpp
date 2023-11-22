#include<bits/stdc++.h>
using namespace std;

//1.�ϲ������ļ� 

//2.ͳ��һƪӢ�������е��ʵĸ��������� 

//���� 
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
	//������������
	int line=0, number=0;
	char word[100];
	while(file.getline(word, 100)){
		number += words(word);
		line++;
	} 
	file.close();
	printf("����Ϊ:\n");
	cout<<line<<endl;
	printf("����Ϊ:\n");
	cout<<number<<endl;
}

//ʹ��mapͳ��ÿ�����ʳ��ֵĸ��� 
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
	//����
	map<string, int> ::iterator ite; 
	for(ite=res.begin();ite!=res.end();ite++)
		cout<<ite->first<<":"<<ite->second<<endl;
} 

//3.��c++Դ����ÿһ��ǰ�����һ���кźͿո�
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
	int i=1;//�к� 
	while(sourcefile.getline(line,100)){
		targetfile<<i<<" "<<line<<endl;
		i++;
	}
	sourcefile.close();
	targetfile.close();
} 

//4.���ASCII��ֵ��20��127���ַ�����ʽΪÿ��ʮ��

//6.����һ��student�࣬���ұ��浽�ļ���
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
	//������д���ļ�
	for(int i=0;i<3;i++){
		file.write((char*)&s[i],sizeof(s[i]));
	} 
	//���ļ��ж�ȡ����
	Student st;
	file.seekg(0,ios::beg); 
	//Ϊ�˱����ظ����ȶ�ȡһ�� 
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
