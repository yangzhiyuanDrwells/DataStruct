#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>
#include<stdbool.h>
#include<time.h>

#define DATA_TYPE int 
#define default_capacity 9

typedef struct Seqlist
{
	DATA_TYPE* data;
	int capacity;
	int sz;
}Seqlist;




//创建并初始化顺序表
void CreateSeqlist(Seqlist* sq, int sz)
{
	//sq->capacity = default_capacity > sz ? default_capacity : sz;
	sq->capacity = (sz > 0 && sz > default_capacity) ? sz : default_capacity;
	DATA_TYPE* tmp = (DATA_TYPE*)malloc(sizeof(DATA_TYPE) * sq->capacity);
	assert(tmp != NULL);
	sq->data = tmp;
	memset(sq->data, 0, sq->capacity);
	sq->sz = 0;
}

//给顺序表放入数据
void GetValue2Seqlist(Seqlist* sq, DATA_TYPE* arr, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		sq->data[i] = arr[i];
		sq->sz++;
	}
}



//直接插入排序(稳定)
void _InsSort(DATA_TYPE* arr, int length);
void InsSort(Seqlist* sq)
{
	_InsSort(sq->data, sq->sz);
}

#if 0 //错误
void _ShowSeqlist(DATA_TYPE* arr, int length);
//直接插入排序内方法(无监视哨)
void _InsSort(DATA_TYPE* arr, int length)
{
	int i = 1, j = 0, k = 0, tmp = 0;
	for (; i < length; ++i)
	{
		tmp = arr[i];
		for (j = 0; j < i; ++j)
		{
			if (arr[i] < arr[j])
			{
				for (k = i; k > j; --k)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = tmp;
				//_ShowSeqlist(arr, length);
			}
			else if (arr[i] == arr[j] && arr[i] != arr[j + 1] && j < i)
			{
				for (k = i; k > j - 1; --k)
				{
					arr[k] = arr[k - 1];
				}
				arr[j - 1] = tmp;
				_ShowSeqlist(arr, length);
			}
		}
	}
}
#endif


#if 1
void _ShowSeqlist(DATA_TYPE* arr, int length);
//直接插入排序内方法(无监视哨)
void _InsSort(DATA_TYPE* arr, int length)
{
	int i = 1, j = 0, k = 0, tmp = 0;
	for (; i < length; ++i)
	{
		tmp = arr[i];
		for (j = i-1; j >= 0; --j)
		{
			if (j >= 1 && arr[i] < arr[j] && arr[i] >= arr[j - 1])
			{
				for (k = i; k > j; --k)
					arr[k] = arr[k - 1];
				arr[j] = tmp;
			}
			else if (j == 0 && arr[i] <= arr[j])
			{
				for (k = i; k > 0; --k)
					arr[k] = arr[k - 1];
				arr[j] = tmp;
			}
		}
	}
}
#endif




void ShowSeqlist(Seqlist* sq)
{
	_ShowSeqlist(sq->data, sq->sz);
}
void _ShowSeqlist(DATA_TYPE* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	Seqlist sq;
	int capacity = 0;  //创建顺序表时的容量
	//int arr[] = { 48, 62, 35, 77, 55, 14, 35, 98 };
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int sz = sizeof(arr) / sizeof(DATA_TYPE);  //arr数组元素个数
	CreateSeqlist(&sq, 0);
	GetValue2Seqlist(&sq, arr, sz);
	InsSort(&sq);
	ShowSeqlist(&sq);
	return 0;
}