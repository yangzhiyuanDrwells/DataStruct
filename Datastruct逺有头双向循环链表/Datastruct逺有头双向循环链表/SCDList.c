#include "SCDList.h"

static void Swap(SCDLDataType* a, SCDLDataType* b)
{
	SCDLDataType tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

SCDListNode* BuySCDListNode(SCDLDataType x)
{
	SCDListNode* s = (SCDListNode*)malloc(sizeof(SCDListNode));
	assert(s != NULL);
	s->data = x;
	s->pre = s->next = NULL;
	return s;
}

void SCDListInit(SCDList* plist)
{
	SCDListNode* s = BuySCDListNode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->pre = plist->last;
	plist->size = 0;
}


void SCDListShow(SCDList* plist)
{
	if (plist->first == NULL && plist->first == plist->last)
	{
		printf("the single list was be destoried\n");
		return;
	}

	if (plist->first == plist->last) 
		printf("the single list is empty\n"); 
	//plist->size == 0  
	//plist->first->next == plist->first && plist->first->pre == plist->last


	SCDListNode* p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");
}




void SCDListPushFront(SCDList* plist, SCDLDataType x)
{
	assert(plist != NULL);
	SCDListNode* s = BuySCDListNode(x);
	assert(s != NULL);

	/*plist->first->next->pre = s;
	s->next = plist->first->next;
	plist->first->next = s;
	s->pre = plist->first;*/

	s->next = plist->first->next;
	s->next->pre = s;
	plist->first->next = s;
	s->pre = plist->first;

	if (plist->size == 0)
		plist->last = s;

	plist->size++;
}

void SCDListPushBack(SCDList* plist, SCDLDataType x)
{
	assert(plist != NULL);
	SCDListNode* s = BuySCDListNode(x);
	assert(s != NULL);

	plist->last->next = s;
	s->pre = plist->last;
	plist->last = s;
	s->next = plist->first;
	plist->first->pre = s;

	plist->size++;
}

void SCDListPopFront(SCDList* plist)
{
	if (plist->size == 0)return;
	SCDListNode* p = plist->first->next;

	p->next->pre = plist->first;
	plist->first->next = p->next;
	
	free(p);
	plist->size--;
}

void SCDListPopBack(SCDList* plist)
{
	if (plist->size == 0)return;
	SCDListNode* p = plist->first->next;
	if (p->next == NULL)
	{
		plist->first->next = p->next;
		plist->last = plist->first;
		plist->first->pre = plist->last;
		free(p);
	}
	else
	{
		while (p->next->next != plist->first) p = p->next;
		free(p->next);
		p->next = plist->first;
		plist->last = p;
		plist->first->pre = p;
	}
	plist->size--;
}


SCDListNode* SCDListFind(SCDList* plist, SCDLDataType x)
{
	SCDListNode* p = plist->first->next;
	while (p != plist->first)
	{
		if (x == p->data) return p;
		p = p->next;
	}
	return NULL;
}

// 在pos的后面进行插入
void SCDListInsertAfter(SCDList* plist, SCDListNode** pos, SCDLDataType x)
{
	if (*pos == NULL) return;
	SCDListNode* p = BuySCDListNode(x);
	p->next = (*pos)->next;
	if ((*pos)->next == plist->first)
	{
		SCDListPushBack(plist, x);
		return;
	}
	assert(p != NULL);
	
	p->next = (*pos)->next;
	p->next->pre = p;
	(*pos)->next = p;
	p->pre = *pos;

	plist->size++;
}

// 在pos的前面进行插入
void SCDListInsertFront(SCDList* plist, SCDListNode** pos, SCDLDataType x)
{
	SCDListInsertAfter(plist, pos, x);
	Swap(&((*pos)->data), &((*pos)->next->data));
}


void SCDListEraseAfter(SCDList* plist, SCDListNode** pos)
{
	if (*pos == NULL || (*pos)->next == NULL) return;

	SCDListNode* p = (*pos)->next;
	if (p->next == plist->first)
	{
		SCDListPopBack(plist);
		return;
	}
	p->next->pre = *pos;
	(*pos)->next = p->next;   //p = p->next;      
	free(p);
	p = NULL;
	plist->size--;
}

void SCDListErasePos(SCDList* plist, SCDListNode** pos)
{
	if (*pos == NULL) return;
	SCDListNode* q = (*pos)->next;
	if ((*pos)->next == plist->first)
		SCDListPopBack(plist);
	else
	{
		if ((*pos)->next->next == plist->first)
			plist->last = *pos;
		Swap(&(*pos)->data, &(q->data));
		(*pos)->next = q->next;
		plist->first->pre = *pos;
		free(q); q = NULL;
		plist->size--;
	}
}

size_t SCDListLength(SCDList* plist)
{
	return plist->size;
}


void SCDListRemove(SCDList* plist, SCDLDataType x)
{
	SCDListNode* ret = SCDListFind(plist, x);
	SCDListErasePos(plist, &ret);
}



void SCDListReverse(SCDList* plist)
{
	if (plist->first->next == plist->first || (plist->first->next)->next == plist->first) return;
	SCDListNode* p = plist->first->next;
	SCDListNode* q = plist->first->next->next;
	while (p != plist->first && q != plist->first)
	{
		p->next = q->next;
		q->next->pre = p;
		q->next = plist->first->next;
		plist->first->next->pre = q;  //q->next->pre = q;
		q->pre = plist->first;
		plist->first->next = q;
		q = p->next;
	}
}

void SCDListSort(SCDList* plist)  //排序（冒泡排序的方法）
{
	size_t len = SCDListLength(plist);
	if (len <= 1)return;
	SCDListNode* start = plist->first->next;
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



void SCDListRemoveAll(SCDList* plist, SCDLDataType x)
{
	if (plist->size == 0) return;
	SCDListNode* p = plist->first->next;
	while (p != plist->first)
	{
		if (x == p->data && p->next == plist->first)
		{
			SCDListPopBack(plist);
			return;
		}
		if (x == p->data)
			SCDListErasePos(plist, &p);

		if (p->data != x)
			p = p->next;
	}
}

void SCDListClear(SCDList* plist)
{
	SCDListNode* pre = plist->first->next;
	SCDListNode* tmp = plist->first->next;
	while (tmp != plist->first)
	{
		tmp = tmp->next;
		free(pre);
		pre = tmp;
	}
	plist->last = plist->first;
	plist->first->next = plist->first;
	plist->first->pre = plist->last;
	plist->size = 0;
}

void SCDListDestory(SCDList* plist)
{
	SCDListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

