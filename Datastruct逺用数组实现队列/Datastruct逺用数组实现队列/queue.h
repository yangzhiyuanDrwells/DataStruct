#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define QueueDataType int
#define DEFAULT_QUEUE_SIZE 8
typedef struct queue
{
	QueueDataType* base;
	size_t capacity;
	size_t front;
	size_t tail;
}queue;

void QueueInit(queue* pst, size_t sz);
void QueuePush(queue* pst, QueueDataType x);
void QueuePop(queue* pst);
QueueDataType StackFront(queue* pst);
void QueueShow(queue* pst);



