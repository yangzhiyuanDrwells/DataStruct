#include "queue.h"

void QueueInit(Queue* pst, size_t sz)
{
	pst->front = pst->tail = NULL;
}

QueueNode* BuyQueueNode(int x)
{
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	s->data = x;
	return s;
}

void QueuePush(Queue* pst, QueueDataType x)
{
	QueueNode* s = BuyQueueNode(x);

	if (pst->tail == NULL)
		pst->front = pst->tail = s;
	else
	{
		pst->tail->next = s;
		pst->tail = s;
	}
}

void QueuePop(Queue* pst)
{
	QueueNode* p = pst->front;
	if (p != NULL)
	{
		pst->front = p->next;
		free(p);
	}
}

QueueDataType QueueFront(Queue* pst)
{
	if (pst->front != NULL)
		return pst->front->data;
	return 404;
}

void QueueShow(Queue* pst)
{
	if (pst->front == NULL)
	{
		printf("Á´±í¿Õ\n");
		return;
	}
	QueueNode* p = pst->front;
	
	while (p != pst->tail)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d->NULL\n", p->data);
}
