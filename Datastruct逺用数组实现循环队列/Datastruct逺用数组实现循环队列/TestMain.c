#include "CircleQueue.h"

void TestQueue(queue* pst)
{
	QueuePush(pst, 2);
	QueuePush(pst, 4);
	QueuePush(pst, 6);
	QueuePush(pst, 8);
	QueuePush(pst, 10);
	QueuePush(pst, 12);
	QueuePush(pst, 14);
	QueuePush(pst, 16);
	QueuePush(pst, 404);
	QueueShow(pst);

	printf("front = %d \n", QueueFront(pst));
	QueuePop(pst);

	QueuePop(pst);
	QueuePop(pst);

	QueuePush(pst, 404);
	QueuePush(pst, 323);
	QueuePush(pst, 323);
	QueuePush(pst, 404);
	QueueShow(pst);
}

int main(int argc, char* argv[])
{
	queue st;
	QueueInit(&st, 6);
	TestQueue(&st);
	return 0;
}