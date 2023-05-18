#include<stdio.h>

int isLeapYear(int year);
void show(int months[], int day);

int main() {
	int year;
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年份：");
	scanf_s("%d", &year);
	int sum = 0;
	//总天数
	for (int i = 1; i < year; i++) {
		sum += 365;
		if (isLeapYear(i)) {
			sum += 1;
		}
	}
	//判断这一年一月一日星期几
	int day = (sum + 1) % 7;

	//判断这一年是否为闰年
	if (isLeapYear(year)) {
		months[1] = 29;
	}
	show(months, day);
	return 0;
}

//判断是否为闰年
int isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	return 0;
}

void show(int months[], int day) {
	char mon[12][10] = { "JANUARY","FEBRUARY","MARCH","APRIL","MAY"
		,"JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	int begin;
	for (int i = 0; i < 12; i++) {
		printf("                %s                  \n", mon[i]);
		printf("  Sun  Mon  Tue  Wed  Thur  Fri  Sat\n");
		begin = 1;
		for (int j = 0; j < day; j++) {
			printf("     ");
		}
		while (begin <= months[i]) {
			printf("%5d", begin);
			begin++;
			day = (day + 1) % 7;
			if (day % 7 == 0) {
				printf("\n");
			}
		}
		printf("\n\n");
	}
}