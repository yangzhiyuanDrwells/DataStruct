#include "circlequeue.h"

void TestQueue(Queue* pst)
{
	QueuePush(pst, 2);
	QueuePush(pst, 6);
	QueuePush(pst, 10);
	QueuePush(pst, 12);
	QueuePush(pst, 16);
	QueuePush(pst, 404);
	QueueShow(pst);

	printf("front = %d \n", QueueFront(pst));
	QueuePop(pst);
	QueueShow(pst);
}

int main(int argc, char* argv[])
{
	Queue st;
	QueueInit(&st, 6);
	TestQueue(&st);
	return 0;
}