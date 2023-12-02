#include<bits/stdc++.h>
using namespace std;

//第十章例题 

void five(){
	double PI=3.1415926535;
	cout<<fixed;
	cout<<PI<<endl;
	//只对下面一个输出有效 
	cout.width(8);
	cout.fill('0');
	for(int precision=0;precision<=9;precision++){
		cout.precision(precision);
		cout<<PI<<endl;
	}
	cout<<PI<<endl; 
	cout<<setw(8)<<setfill('0');
	for(int precision=0;precision<=9;precision++){
		cout.precision(precision);
		cout<<PI<<endl;
	}
	cout<<PI<<endl; 
}

//测试get()函数
void seven(){
	int count;
	int max_char=5;
	char line[100];
	//1234567890
	while(cin.get(line, max_char)){
		count=cin.gcount();
		cout<<line<<'\t'<<count<<endl;
		if(count<max_char-1)	cin.ignore();
	}
} 

//测试getline()函数 
void eight(){
	int max_char=5, i=0;
	char line[100];
	while(cin.getline(line, max_char)){
		cout<<i<<":"<<line<<'\t'<<cin.gcount()<<endl;
		i++;
	}
	cout<<i<<":"<<line<<'\t'<<cin.gcount()<<endl;
} 

//文本文件和二进制文件的输出
void ten(){
	char* name[3]={"Antony", "John", "Tom"};
	double score[3]={85.5, 90, 60};
	fstream txtfile("D:\\record.txt", ios::out|ios::trunc);
	fstream binfile("D:\\record.bat", ios::binary|ios::out|ios::trunc);
	while(!txtfile){
		cerr<<"record.txt open or create wrong!"<<endl;
		exit(1);
	}
	while(!txtfile){
		cerr<<"record.bat open or create wrong!"<<endl;
		exit(1);
	}
	for(int i=0;i<3;i++){
		txtfile<<name[i]<<'\t'<<score[i]<<endl;
		binfile.write(name[i],8*sizeof(char));
		binfile.write((char*)&score[i], sizeof(float));
	}
	txtfile.close();
	binfile.close();
} 

void nine(){
	int number;
	cout<<"cin.rdstate()="<<cin.rdstate()<<endl;
	while(true){
		cin>>number;
		if(cin.rdstate()==ios::goodbit){
			cout<<"Input is correct!"<<endl;
			break;
		}
		if(cin.rdstate()==ios_base::failbit){
			cout<<"Input is error!"<<endl;
			cin.clear(ios::goodbit);
			cout<<"cin.rdstate()="<<cin.rdstate()<<endl;
			break;
		}
	}
} 

//文本文件的输入 
void twelve(){
	char name[8], score[6];
	ifstream txtfile("D:\\record.txt");
	if(!txtfile){
		cerr<<"record.txt open wrong"<<endl;
		exit(1);
	}
	while(!txtfile.eof()){
		txtfile>>name>>score;
		cout<<name<<'\t'<<score<<endl;
	}
	
	//getline() 
//	char line[100];
//	while(txtfile.getline(line, 100))
//		cout<<line<<endl;
	txtfile.close();
} 

int main(){
	nine();
	return 0;
} 
