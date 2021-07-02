#include "CircleQueue.h"

void QueueInit(queue* pst, size_t sz)
{
	pst->capacity = DEFAULT_QUEUE_SIZE < sz ? sz : DEFAULT_QUEUE_SIZE;
	QueueDataType* s = (QueueDataType*)malloc(sizeof(QueueDataType) * pst->capacity);
	assert(s != NULL);
	pst->base = s;
	pst->front = pst->tail = 0;
}

static bool QueueIsFull(queue* pst)
{
	return((pst->tail + 1) % pst->capacity == pst->front);
}
static bool QueueIsEmpty(queue* pst)
{
	return((pst->tail + 1) % pst->capacity != pst->front);
}

void QueuePush(queue* pst, QueueDataType x)
{
	if (QueueIsFull(pst))
		return;
	pst->base[pst->tail] = x;
	pst->tail = (pst->tail + 1) % pst->capacity;
}

void QueuePop(queue* pst)
{
	if (pst->front != pst->tail)  //еп╤о╥г©у
		pst->front = (pst->front + 1) % pst->capacity;
}

QueueDataType QueueFront(queue* pst)
{
	if (pst->front != pst->tail)
		return pst->base[pst->front];
	return 404;
}

void QueueShow(queue* pst)
{
	size_t i = 0;
	if (pst->tail > pst->front)
	{
		for (i = pst->front; i < pst->tail; i++)
		{
			printf("%d ", pst->base[i]);
		}
	}
	else
	{
		for (i = pst->front; i < pst->capacity; i++)
		{
			printf("%d ", pst->base[i]);
		}
		for (i = 0; i < pst->tail; i++)
		{
			printf("%d ", pst->base[i]);
		}

	}

	printf("\n");
}
