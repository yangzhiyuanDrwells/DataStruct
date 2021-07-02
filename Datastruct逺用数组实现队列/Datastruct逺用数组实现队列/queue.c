#include "queue.h"

void QueueInit(queue* pst, size_t sz)
{
	pst->capacity = DEFAULT_QUEUE_SIZE < sz ? sz : DEFAULT_QUEUE_SIZE;
	QueueDataType* s= (QueueDataType*)malloc(sizeof(QueueDataType) * pst->capacity);
	assert(s != NULL);
	pst->base = s;
	pst->front = pst->tail = 0;
}

bool QueueIsEmpty(queue* pst)
{
	return ((pst->tail + 1) % pst->capacity != pst->front)
}

bool QueueIsFull(queue* pst)
{
	return ((pst->tail + 1) % pst->capacity == pst->front)
}

void QueuePush(queue* pst, QueueDataType x)
{
	if (pst->tail == pst->capacity)
		return;
	if (QueueIsEmpty(pst))
	{
		pst->base[pst->tail] = x;
		pst->tail = (pst->tail + 1) % pst->capacity;
	}
}

void QueuePop(queue* pst)
{
	if (pst->front != pst->tail)  //еп╤о╥г©у
		pst->front = (pst->front + 1) % pst->capacity;
}

QueueDataType StackFront(queue* pst)
{
	if (pst->front != pst->tail)
		return pst->base[pst->front];
	return 404;
}

void QueueShow(queue* pst)
{
	size_t i = pst->front;
	for (i; i < pst->tail; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
