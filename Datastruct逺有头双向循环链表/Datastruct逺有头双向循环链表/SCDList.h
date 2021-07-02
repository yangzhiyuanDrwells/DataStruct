#pragma once
#define SCDLDataType int
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct SCDListNode
{
	SCDLDataType data;
	struct SCDListNode* pre;
	struct SCDListNode* next;
}SCDListNode;

//用包含了指向链表结点的头指针及头尾的指针维护链表
typedef struct SCDList
{
	SCDListNode* first;
	SCDListNode* last;
	size_t     size;
}SCDList;



static void Swap(SCDLDataType* a, SCDLDataType* b);

SCDListNode* BuySCDListNode(SCDLDataType x);

void SCDListInit(SCDList* plist);

void SCDListShow(SCDList* plist);

void SCDListPushFront(SCDList* plist, SCDLDataType x);

void SCDListPushBack(SCDList* plist, SCDLDataType x);

void SCDListPopFront(SCDList* plist);

void SCDListPopBack(SCDList* plist);

SCDListNode* SCDListFind(SCDList* plist, SCDLDataType x);

// 在pos的后面进行插入
void SCDListInsertAfter(SCDList* plist, SCDListNode** pos, SCDLDataType x);

// 在pos的前面进行插入
void SCDListInsertFront(SCDList* plist, SCDListNode** pos, SCDLDataType x);

void SCDListEraseAfter(SCDList* plist, SCDListNode** pos);

void SCDListErasePos(SCDList* plist, SCDListNode** pos);

size_t SCDListLength(SCDList* plist);

void SCDListRemove(SCDList* plist, SCDLDataType x);

void SCDListReverse(SCDList* plist);

void SCDListSort(SCDList* plist);

void SCDListRemoveAll(SCDList* plist, SCDLDataType x);

void SCDListClear(SCDList* plist);

void SCDListDestory(SCDList* plist);

