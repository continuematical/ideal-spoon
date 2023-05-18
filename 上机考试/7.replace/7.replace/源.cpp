#include<string.h>
#include<stdio.h>

char* Replace(char* str, char* substr, char* newstr);

int main() {
	char arr[] = "qweabcdefabcgh";
	char substr[] = "abc";
	char newstr[] = "123";
	char* k = Replace(arr, substr, newstr);
	printf("%s", k);
	return 0;
}

char* Replace(char* str,char* substr, char* newstr) {
	char* temp = strstr(str, substr);
	char* arr = newstr;
	while (temp != NULL) {
		while (*arr) {
			*temp++ = *arr++;
		}
		temp = strstr(str, substr);
		arr = newstr;
	}
	return str;
}