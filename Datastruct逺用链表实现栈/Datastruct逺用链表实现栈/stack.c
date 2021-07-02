#include "stack.h"

void StackInital(stack* pst)
{
	pst->StackTop = NULL;
	pst->size = 0;
}

void StackPush(stack* pst, StackDataType x)
{
	StackP s = _BuyNode(x);
	assert(s != NULL);
	if(pst->StackTop != NULL)
		s->next = pst->StackTop;
	pst->StackTop = s;
	pst->size++;
}

StackDataType StackTop(stack* pst)
{
	return pst->StackTop->data;
}

void StackPop(stack* pst)
{
	if (pst->StackTop == NULL)
		return;
	StackP p = pst->StackTop;
	pst->StackTop = pst->StackTop->next;
	free(p);
	pst->size--;
}

void StackClear(stack* pst)
{
	StackP p = NULL;
	while (pst->StackTop != NULL)
	{
		p = pst->StackTop;
		pst->StackTop = pst->StackTop->next;
		free(p);
	}
	pst->size = 0;
}

void StackDestory(stack* pst)
{
	free(pst);
}

size_t StackSize(stack* pst)
{
	if (pst->StackTop == NULL)
		return 0;
	return pst->size;
}

void StackShow(stack* pst)
{
	StackP p = pst->StackTop;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}