#pragma once
#define _CRT_SECURT_NO_WARNINGS 1
#define SLTDataType int
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;



//用指向链表结点的指针维护链表
//typedef struct SListNode* SList;//#define  SList struct SListNode* 


//用包了指向链表结点的头指针结构体维护链表
//typedef struct SList
//{
//	SListNode* _head;
//}SList;


//用包含了指向链表结点的头指针及头尾的指针维护链表
typedef struct SList
{
	SListNode* first;
	SListNode* last;
	size_t     size;
}SList;



SListNode* BuySListNode(SLTDataType x);
void SListInit(SList* plist);

void SListShow(SList* plist);
void SListShowRet(const SList* pos);
void SListPushFront(SList* plist, SLTDataType x);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPopBack(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);//按值找结点，返回结点地址
// 在pos的后面进行插入
void SListInsertAfter(SList* plist, SListNode** pos, SLTDataType x);
// 在pos的前面进行插入
void SListInsertFront(SList* plist, SListNode** pos, SLTDataType x);
void SListEraseAfter(SList* plist, SListNode** pos);
void SListErasePos(SList* plist, SListNode** pos);   //按结点地址删除结点
size_t SListLength(SList* plist);
void SListRemove(SList* plist, SLTDataType x);  //按值删除结点

void SListReverse(SList* plist); //逆转单链表
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, SLTDataType x);//按值删除所有结点
void SListClear(SList* plist);
void SListDestory(SList* plist);

