#include <stdio.h>
//判断是否为闰年
int isleap(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	return 0;
}
//算出日期到1970的天数
int Date(char* date)
{
	int tmp[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	long num = 0;
	int year = (*date - '0') * 1000 + (*(date+1) - '0') * 100 + (*(date+2) - '0') * 10 + (*(date+3) - '0');
	int month = (*(date + 4) - '0') * 10 + (*(date + 5) - '0');
	int day = (*(date + 6) - '0') * 10 + (*(date + 7) - '0');
	for (int i = 1970; i < year; i++) {
		if (isleap(year)){
			num += 366;
		}else {
			num += 365;
		}
	}
	for (int i = 1; i < month; i++) {
		if ((isleap(year) && i == 2)) {
			num += 29;
		}
		else {
			num += tmp[i];
		}
	}
	num += day - 1;
	return num;
}
int main()
{
	char str1[9] = "19710629";
	char str2[9] = "20100923";
	int num1 = Date(str1);
	int num2 = Date(str2);
	printf("%d", num2 - num1);
	return 0;
}