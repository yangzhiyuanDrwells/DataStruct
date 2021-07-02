#include "SList.h"

static void Swap(SLTDataType* a, SLTDataType* b)
{
	SLTDataType tmp = 0;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
}

void SListInit(SList* head)
{
	*head = NULL;
}

void SListDestory(SList* head)
{
	SList pre = *head;
	SList tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(pre);
		pre = tmp;
	}
	*head = NULL;
}

void SListShow(const SList* head)
{
	if (*head == NULL)
	{
		printf("没有节点\n");
		return;
	}
	SList tmp = *head;
	while (tmp->next != NULL)
	{
		printf("%d->",tmp->data);
		tmp = tmp->next;
	}
	printf("%d->", tmp->data);
	printf("Over\n");
}

void SListShowRet(const SList* pos)
{
	printf("\n%d->\n", (*pos)->data);
	printf("pos->%p\n", *pos);
}

SListNode* BuySListNode(SLTDataType x)
{
	SList s = (SList)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListPushFront(SList* head, SLTDataType x)
{
	SList p = BuySListNode(x);
	assert(p);
	if (*head == NULL)
		p->next = NULL;
	else
	p->next = *head;

	(*head) = p;
}

void SListPushBack(SList* head, SLTDataType x)
{
	SList p = BuySListNode(x);
	assert(p != NULL);
	SListNode* tmp = *head;
	if (*head == NULL)
		*head = p;
	else
	{
		while (tmp->next != NULL)
			tmp = (tmp)->next;
		tmp->next = p;
	}
	p->next = NULL;
}

void SListPopFront(SList* head)
{
	if (*head == NULL)return;
	SList tmp = *head;
	*head = (*head)->next;
	free(tmp);
	tmp = NULL;
}

void SListPopBack1(SList* head)
{
	if (*head == NULL)return;
	SList tmp = *head;
	SList pre = NULL;
	while (tmp->next != NULL)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	if (pre != NULL)
	pre->next = NULL;
	else
		*head = NULL;
	tmp = NULL;
}

void SListPopBack2(SList* head)
{
	if (*head == NULL)return;
	SList tmp = *head;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;

	tmp = NULL;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	SList cur = *plist;
	while (cur != NULL)
	{
		if (x == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

// 在pos的后面进行插入
void SListInsertAfter(SList* pos, SLTDataType x)
{
	if(*pos == NULL) return; 
	SList tmp = *pos;
	SList p = BuySListNode(x);
	p->next = (*pos)->next;
	assert(p != NULL);
	(*pos)->next = p;
}

// 在pos的前面进行插入
void SListInsertFront(SList* pos, SLTDataType x)
{
	SListInsertAfter(pos, x);
	Swap(&((*pos)->data), &((*pos)->next->data));
}


void SListEraseAfter(SList* pos)
{
	if (*pos == NULL || (*pos)->next == NULL) return;

	SList p = (*pos)->next;
	(*pos)->next = (*pos)->next->next;
	free(p);
	p = NULL;
}

void SListErasePos(SList* pos, SList* head)
{
	if (*pos == NULL ) return;
	SList q = (*pos)->next;
	if (NULL == (*pos)->next) SListPopBack1(head);
	else
	{
		(*pos)->data = q->data;
		(*pos)->next = q->next;
		free(q); q = NULL;
	}
}

size_t SListLength(SList* head)
{
	int count = 0;
	SList tmp = *head;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}


void SListRemove1(SList* head, SLTDataType x)
{
	if (*head == NULL)return;
	SList tmp = *head;
	SList pre = *head;
	while (tmp != NULL && x != tmp->data)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	if (tmp == *head) SListPopFront(head);
	else if (tmp != NULL)
		SListEraseAfter(&pre);
}

void SListRemove2(SList* head, SLTDataType x)
{
	if (*head == NULL)return;
	SList tmp = *head;
	SList pre = *head;
	while (tmp != NULL && (x != tmp->data && x != tmp->next->data))
	{
		tmp = tmp->next;
	}
	if (tmp == *head) SListPopFront(head);
	if (tmp != NULL)
		SListEraseAfter(&tmp);
}

void SListReverse(SList* head)
{
	if (*head == NULL || (*head)->next == NULL) return;
	SList p = *head;
	SList q = (*head)->next;
	while (p != NULL && q != NULL)
	{
		p->next = q->next;
		q->next = *head;
		*head = q;
		q = p->next;
	}
}

void SListSort(SList* head)  //排序（冒泡排序的方法）
{
	size_t len = SListLength(head);
	SList start = *head;
	int i = len-1, j = len;
	while (i--)
	{
		start = *head;
		j = i+1;
		while (j--)
		{
			if (start->data > start->next->data)
				Swap(&(start->data), &(start->next->data));
			start = start->next;
		}
	}
}



void SListRemoveAll(SList* head, SLTDataType x)
{
	if (*head == NULL) return;
	SList p = *head;
	while (p != NULL)
	{
		if (x == p->data && p->next == NULL)
		{
			SListPopBack1(head);
			return;
		}
		if (x == p->data)
			SListErasePos(&p, head);
		/*	if (x == p->data)
		{
			if (p->next == NULL)
			{
				SListPopBack1(head);
				return;
			}
			SListErasePos(&p, head);
		}*/
		if(p->data != x)
		p = p->next;
	}
}


void SListRemoveAll2(SList* head, SLTDataType x)
{
	if (*head == NULL) return;
	SList q = *head;
	while (q != NULL)
	{
		if (q->data == x && q->next == NULL)
		{
			SListErasePos(&q, head);
			return;
		}
		if (q->data == x)
			SListErasePos(&q, head);
		if(q->data != x)
		q = q->next;
	}
}





