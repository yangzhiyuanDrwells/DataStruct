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

//�ð�����ָ���������ͷָ�뼰ͷβ��ָ��ά������
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

// ��pos�ĺ�����в���
void SCDListInsertAfter(SCDList* plist, SCDListNode** pos, SCDLDataType x);

// ��pos��ǰ����в���
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

