#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef struct SeqList
{
	DataType* base;
	size_t    capacity;
	size_t    size;
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);
void SeqListInsureCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, DataType x);
void SeqListShow(SeqList* psl);
void SeqListPopBack(SeqList* psl);
void SeqListPopFront(SeqList* psl);
int  SeqListFindPos(SeqList* psl, DataType find);
int  SeqListFindVal(SeqList* psl, DataType find);
void SeqListInsertPos(SeqList* psl, DataType n, DataType data);
void SeqListFindAllPos(SeqList* psl, DataType* base, DataType find);
bool SeqListDeletVal(SeqList* psl, DataType find);
void SeqListDeletPos(SeqList* psl, DataType which);
void SeqListRemoveAll(SeqList* psl, DataType find);
void SeqListReverse(SeqList* psl);


void SeqListClear(SeqList* psl);

////////////////////////////////////////////////////////////
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->base = (DataType*)malloc(sizeof(DataType) * capacity);
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListInsureCapacity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		psl->base = (DataType*)realloc(psl->base, sizeof(DataType) * (psl->capacity + 1));
		psl->capacity++;
	}
}
void SeqListPushBack(SeqList* psl, DataType x)
{
	SeqListInsureCapacity(psl);
	if (psl->size >= psl->capacity)
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return;
	}
	psl->base[psl->size++] = x;
}
void SeqListPushFront(SeqList* psl, DataType x)
{
	SeqListInsureCapacity(psl);
	if (psl->size >= psl->capacity)
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return;
	}

	for (int i = psl->size; i > 0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
}

void SeqListShow(SeqList* psl)
{
	for (int i = 0; i < (int)psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList* psl)
{
	if(psl->size > 0)
	psl->size--;
}

void SeqListPopFront(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < (int)psl->size - 1; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
}

int  SeqListFindPos(SeqList* psl, DataType index)
{
	return psl->base[index];
}

int  SeqListFindVal(SeqList* psl, DataType find)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < (int)psl->size; i++)
	{
		if (psl->base[i] == find)
			count++;
	}
	return count;
}

void SeqListInsertPos(SeqList* psl, DataType n, DataType data)
{
	SeqListInsureCapacity(psl);
	int i = psl->size;
	for (;i>=n;i--)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[n - 1] = data;
	psl->size++;
}

void SeqListFindAllPos(SeqList* psl, DataType* base, DataType find)
{
	DataType* tmp = base;
	while (tmp - psl->base  <  (int)psl->size)
	{
		if (*tmp == find)
			printf("%d找到了，为第%d个数据,下标为%d\n", find, tmp - psl->base + 1, tmp - psl->base);
		tmp++;
		if(tmp - psl->base < (int)psl->size)
		SeqListFindAllPos(psl, tmp, find);
		return;
	}
}

bool SeqListDeletVal(SeqList* psl, DataType find)
{
	int i = 0;
	for (; i < (int)psl->size - 1; i++)
	{
		if (find == psl->base[i])
		{
			SeqListDeletPos(psl, i);
			psl->size--;
			return true;
		}
	}
	return false;
}

void SeqListDeletPos(SeqList* psl,DataType which)
{
	int i = which;
	for (; i < (int)psl->size - 1; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
}

void SeqListRemoveAll(SeqList* psl,  DataType find)
{
	int i = 0;
	DataType* tmp = psl->base;
	for (i = 0; i < psl->size; i++)
	{
		if (find != psl->base[i])
			* tmp++ = psl->base[i];
	}
	psl->size = tmp - psl->base;
}

void SeqListReverse(SeqList* psl)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0, j = psl->size - 1; j >= (int)psl->size / 2; i++, j--)
	{
		tmp = psl->base[i];
		psl->base[i] = psl->base[j];
		psl->base[j] = tmp;
	}
}


void SeqListClear(SeqList* psl)
{
	psl->size = 0;
}
#endif /* _SEQLIST_H_ */