#include "stack.h"

void StackInit(stack* pst, size_t sz)
{
	pst->capacity = DEFAULT_STACK_SIZE < sz ? sz : DEFAULT_STACK_SIZE;
	StackDataType *s = (StackDataType*)malloc(sizeof(StackDataType)*pst->capacity);
	assert(s != NULL);
	pst->base = s;
	pst->top = 0;
}

void StackPush(stack* pst, StackDataType x)
{
	if (!StackIsFull(pst));
		pst->base[pst->top++] = x;
}

void StackPop(stack* pst)
{
	if (!StackIsEmpty(pst));
	pst->top--;
}

StackDataType StackTop(stack* pst)
{
	if (!StackIsEmpty(pst));
	return pst->base[pst->top - 1];
}

void StackClear(stack* pst)
{
	pst->top = 0;
}

void StackDestroy(stack* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

void StackShow(stack* pst)
{
	if (pst->base == NULL) return;
	int i = pst->top - 1;
	for (; i >= 0; i--)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void TestStack(stack* pst)
{
	StackPush(pst, 1);
	StackPush(pst, 2);
	StackPush(pst, 3);
	StackPush(pst, 4);
	StackPush(pst, 5);
	StackShow(pst);
	printf("%d \n", StackTop(pst));
	StackShow(pst);
	StackPop(pst);
	StackShow(pst);
	StackClear(pst);
	StackShow(pst);
	StackDestroy(pst);
	StackShow(pst);
}