#include<bits/stdc++.h> 

class String{
	protected:
		char* str;
		int length;
		
	public:
		String(){
			length=0;
			str=NULL;
		}
		
		String(const char* p){
			length=strlen(p);
			str=new char[length+1];
			strcpy(str,p);
		}
		
		String(String& r){
			length=r.length;
			if(length){
				str=new char[length+1];
				strcpy(str,r.str);
			}
		}
		
		~String(){
			if(str!=NULL){
				delete[] str;
				str=NULL;
				length=0;
			}
		}
		
		char* getStr() const{
			return str;	
		}
		
		//�жϵ�ǰ�ַ����Ƿ�Ϊ�ַ������Ӵ� 
		bool IsSubstring(const char* newStr){
			int i,j;
			for(i=0;i<length;i++){
				int k=i;
				for(j=0;newStr[j];j++,k++)
					if(str[j]!=str[k])	break;
				if(!str[j])	return true;
			} 
			return false;
		}
};

//���ַ������б༭ 
class EditString:public String{
	public:
		EditString():String(){}
		EditString(const char* p):String(p){}
		void EditChar(char s, char d);
		void EditSub(char* subs, char* subd);
		void DeleteChar(char ch);
		void DeleteSub(char* sub);
		int IsSubstring(int start, const char* str);
};



//ɾ���ַ����е� ch �ַ� 
void EditString::DeleteChar(char ch){
	
}

//ɾ���ַ����е� sub �ַ���
void EditString::DeleteSub(char* sub){
	
} 

//��start����ʼ�ж��Ӵ��������򷵻ص�һ�����ڵ��±�λ�ã����򷵻�-1
int EditString::IsSubstring(int start, const char* newStr){
	int j;
	for(int i=start;i<length;i++){
		int k=i;
		for(j=0;j<strlen(newStr);j++,k++)
			if(str[j]!=newStr[k])	break;
		if(!str[j])	return true;
	}
	return false;
} 

//���ַ� d �����ַ� s 
void EditString::EditChar(char s, char d){
	for(int i=0;i<length;i++){
		if(*(str+i)==s)	*(str+i)=d;
	} 
}

//���ַ���subd�����ַ���subs 
void EditString::EditSub(char* subs, char* subd){
	char* temp=new char[3*length];
	int i=0;
	while(i<length){
		
	} 
}
