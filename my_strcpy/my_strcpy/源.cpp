//ģ��ʵ��strcpy����
#include<stdio.h>
#include<assert.h>
void my_strcpy(char* dest, const char* src)
{
	/*while (*src)
	{
		*dest++ = *src++;
	}*/
	//����ʹ�ñ�����
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
	my_strcpy(arr1, NULL);//��arr2���Ƶ�arr1��
	printf("%s", arr1);
	return 0;
}