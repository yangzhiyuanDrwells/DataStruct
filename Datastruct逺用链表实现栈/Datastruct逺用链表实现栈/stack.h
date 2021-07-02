#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include <stdbool.h>
#define StackDataType int

typedef struct StackNode
{
	StackDataType data;
	struct StackNode* next;
}StackNode, * StackP;

typedef struct stack
{
	StackP StackTop;
	size_t size;
}stack;

static StackP _BuyNode(StackDataType x)
{
	StackP s = (StackP)malloc(sizeof(StackNode));
	if (s != NULL)
	{
		s->next = NULL;
		s->data = x;
		return s;
	}
}
void StackInital(stack *pst);
void StackPush(stack* pst, StackDataType x);
StackDataType StackTop(stack* pst);
void StackPop(stack* pst);
void StackClear(stack* pst);
void StackDestory(stack* pst);
void StackShow(stack* pst);

