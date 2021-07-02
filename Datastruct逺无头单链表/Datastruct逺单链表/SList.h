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
typedef struct SListNode* SList;//#define  SList struct SListNode* 

//用包了指向链表结点的结构体维护链表
//typedef struct SList
//{
//	SListNode* _head;
//}SList;





void SListInit(SList* head);
void SListDestory(SList* head);
void SListShow(const SList* head);
void SListShowRet(const SList* pos);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* head, SLTDataType x);
void SListPushBack(SList* head, SLTDataType x);
void SListPopFront(SList* head);
void SListPopBack1(SList* head);
void SListPopBack2(SList* head);
SListNode* SListFind(SList* plist, SLTDataType x);//按值找结点，返回结点地址
// 在pos的后面进行插入
void SListInsertAfter(SList* pos, SLTDataType x);
// 在pos的前面进行插入
void SListInsertFront(SList* pos, SLTDataType x);
void SListEraseAfter(SList* pos);
void SListErasePos(SList* pos, SList* head);   //按结点地址删除结点
size_t SListLength(SList* head);
void SListRemove1(SList* head, SLTDataType x);  //按值删除结点
void SListRemove2(SList* plist, SLTDataType x);  //按值删除结点
void SListReverse(SList* head); //逆转单链表
void SListSort(SList* head); 
void SListRemoveAll(SList* head, SLTDataType x);//按值删除所有结点
void SListRemoveAll2(SList* head, SLTDataType x);
