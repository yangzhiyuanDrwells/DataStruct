#include "SCList.h"

static void Swap(SLTDataType* a, SLTDataType* b)
{
	SLTDataType tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)
{
	SListNode* s = BuySListNode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->size = 0;
}


void SListShow(SList* plist)
{
	if (plist->first == NULL && plist->first == plist->last)
	{
		printf("the single list was be destoried\n");
		return;
	}
	if (plist->first != NULL && plist->first == plist->last) printf("the single list is empty\n");  //plist->size == 0
	SListNode* p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");
}




void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist != NULL);
	SListNode* s = BuySListNode(x);
	assert(s != NULL);
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist != NULL);
	SListNode* s = BuySListNode(x);
	assert(s != NULL);
	plist->last->next = s;
	s->next = plist->first;
	plist->last = s;
	plist->size++;
}

void SListPopFront(SList* plist)
{
	if (plist->size == 0)return;
	SListNode* p = plist->first->next;
	plist->first->next = plist->first->next->next; 
	free(p);
	plist->size--;
}

void SListPopBack(SList* plist)
{
	if (plist->size == 0)return;
	SListNode* p = plist->first->next;
	if (p->next == NULL)
	{
		plist->first->next = p->next;
		plist->last = plist->first;
		free(p);
	}
	else
	{
		while (p->next->next != plist->first) p = p->next;
		free(p->next);
		p->next = plist->first;
		plist->last = p;
	}
	plist->size--;
}


SListNode* SListFind(SList* plist, SLTDataType x)
{
	SListNode* p = plist->first->next;
	while (p != plist->first)
	{
		if (x == p->data) return p;
		p = p->next;
	}
	return NULL;
}

// 在pos的后面进行插入
void SListInsertAfter(SList* plist, SListNode** pos, SLTDataType x)
{
	if (*pos == NULL) return;
	SListNode* p = BuySListNode(x);
	p->next = (*pos)->next;
	if ((*pos)->next == plist->first)
	{
		plist->last = p;
		p->next = plist->first;
	}
	assert(p != NULL);
	(*pos)->next = p;
	plist->size++;
}

// 在pos的前面进行插入
void SListInsertFront(SList* plist, SListNode** pos, SLTDataType x)
{
	SListInsertAfter(plist, pos, x);
	Swap(&((*pos)->data), &((*pos)->next->data));
}


void SListEraseAfter(SList* plist, SListNode** pos)
{
	if (*pos == NULL || (*pos)->next == NULL) return;

	SListNode* p = (*pos)->next;
	if (p->next == plist->first)
	{
		plist->last = p;
		p->next = plist->first;
	}
	(*pos)->next = (*pos)->next->next;
	free(p);
	p = NULL;
	plist->size--;
}

void SListErasePos(SList* plist, SListNode** pos)
{
	if (*pos == NULL) return;
	SListNode* q = (*pos)->next;
	if ((*pos)->next == plist->first)
	{
		SListPopBack(plist);
		return;
	}
	else
	{
		if ((*pos)->next->next == NULL) 
			plist->last = *pos;
		Swap(&(*pos)->data, &(q->data));
		(*pos)->next = q->next;
		free(q); q = NULL;
	}
	plist->size--;
}

size_t SListLength(SList* plist)
{
	return plist->size;
}


void SListRemove(SList* plist, SLTDataType x)
{
	SListNode* ret = SListFind(plist, x);
	SListErasePos(plist, &ret);
}



void SListReverse(SList* plist)
{
	if (plist->first->next == NULL || (plist->first->next)->next == NULL) return;
	SListNode* p = plist->first->next;
	SListNode* q = plist->first->next->next;
	while (p != plist->first && q != plist->first)
	{
		p->next = q->next;
		q->next = plist->first->next;
		plist->first->next = q;
		q = p->next;
	}
}

void SListSort(SList* plist)  //排序（冒泡排序的方法）
{
	size_t len = SListLength(plist);
	if (len <= 1)return;
	SListNode* start = plist->first->next;
	int i = len - 1, j = len;
	while (i--)
	{
		start = plist->first->next;
		j = i + 1;
		while (j--)
		{
			if (start->data > start->next->data)
				Swap(&(start->data), &(start->next->data));
			start = start->next;
		}
	}
}



void SListRemoveAll(SList* plist, SLTDataType x)
{
	if (plist->size == 0) return;
	SListNode* p = plist->first->next;
	while (p != plist->first)
	{
		if (x == p->data && p->next == NULL)
		{
			SListPopBack(plist);
			return;
		}
		if (x == p->data)
			SListErasePos(plist, &p);

		if (p->data != x)
			p = p->next;
	}
}

void SListClear(SList* plist)
{
	SListNode* pre = plist->first->next;
	SListNode* tmp = plist->first->next;
	while (tmp != plist->first)
	{
		tmp = tmp->next;
		free(pre);
		pre = tmp;
	}
	plist->last = plist->first;
	plist->first->next = plist->first;
	plist->size = 0;
}

void SListDestory(SList* plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

