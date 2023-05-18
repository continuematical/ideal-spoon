#include "БъЭЗ.h"

int main() {
	Student* head = NULL;
	char name[5][10] = { "zhangsan","lihao","wangfei","liming","liuqiang" };
	insertNode(&head, name[0], 90.5, 80.0, 88.5);
	insertNode(&head, name[1], 96.0, 89.5, 95.0);
	insertNode(&head, name[2], 90.0, 88.5, 80.0);
	insertNode(&head, name[3], 70.0, 89.0, 92.0);
	insertNode(&head, name[4], 90.0, 85.5, 86.0);

	printList(head);
	return 0;
}