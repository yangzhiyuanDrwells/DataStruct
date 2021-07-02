#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define StackDataType int
#define DEFAULT_STACK_SIZE 8
typedef struct stack
{
	StackDataType* base;
	size_t capacity;
	size_t top;
}stack;

void StackInit(stack *pst, size_t sz);
void StackPush(stack* pst, StackDataType x);
void StackPop(stack* pst);
StackDataType StackTop(stack* pst);
void StackClear(stack* pst);
void StackDestroy(stack* pst);
void StackShow(stack* pst);
static bool StackIsFull(stack* pst)
{
	return pst->top >= pst->capacity;
}
static bool StackIsEmpty(stack* pst)
{
	return pst->top == 0;
}
void TestStack(stack* pst);