#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define QueueDataType int
#define DEFAULT_QUEUE_SIZE 8

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pst, size_t sz);
void QueuePush(Queue* pst, QueueDataType x);
void QueuePop(Queue* pst);
QueueDataType QueueFront(Queue* pst);
void QueueShow(Queue* pst);



