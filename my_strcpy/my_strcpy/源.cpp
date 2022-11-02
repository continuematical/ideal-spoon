//模拟实现strcpy函数
#include<stdio.h>
#include<assert.h>
void my_strcpy(char* dest, const char* src)
{
	/*while (*src)
	{
		*dest++ = *src++;
	}*/
	//或者使用报错函数
	assert(src != NULL);
	assert(dest != NULL);
	while (*dest++ = *src++)
	{

	}
}
int main()
{
	char arr1[20] = "*********";
	char arr2[20] = "hello";
	my_strcpy(arr1, NULL);//将arr2复制到arr1中
	printf("%s", arr1);
	return 0;
}