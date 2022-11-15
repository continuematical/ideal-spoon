//ÅĞ¶Ï×Ö·û´®ÊÇ·ñÎªÁíÒ»¸ö×Ö·û´®µÄ×Ó´® 
#include <string.h>
#include <stdio.h>
int is_string_rotate(char* str1,char*str2){
	int len=strlen(str1);
	str1=strncat(str1,str1,len);
	char* ret=strstr(str1,str2);
	if(ret){
		return 1;
	}else{
		return 0;
	}
}
int main()
{
	char str1[20]="ABCDFF";
	char str2[20]="BCDFFA";
	if(is_string_rotate(str1,str2)){
		printf("true");
	}
	return 0;
}
