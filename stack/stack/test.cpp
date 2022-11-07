#include "stack.h"
int main()
{
	stack ps;
	stackInit(&ps);
	stackPush(&ps, 1);
	stackPush(&ps, 2);
	stackPush(&ps, 3);
	stackPush(&ps, 4);

	printf("%d ", stackTop(&ps));
	stackPop(&ps);
	printf("%d ", stackTop(&ps));
	stackPop(&ps);
	
	stackPush(&ps, 5);
	stackPush(&ps, 6);
	return 0;
}