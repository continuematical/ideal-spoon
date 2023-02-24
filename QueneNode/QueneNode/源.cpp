#include "БъЭЗ.h"
int main()
{
	Quene q;
	QueneInit(&q);
	QuenePush(&q, 1);
	QuenePush(&q, 2);
	QuenePush(&q, 3);
	QuenePush(&q, 4);

	printf("%d\n", QueneFront(&q));

	int len = QueneSize(&q);

	printf("%d", len);
	return 0;
}