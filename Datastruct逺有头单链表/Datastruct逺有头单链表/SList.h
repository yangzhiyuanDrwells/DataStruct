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



//��ָ���������ָ��ά������
//typedef struct SListNode* SList;//#define  SList struct SListNode* 


//�ð���ָ���������ͷָ��ṹ��ά������
//typedef struct SList
//{
//	SListNode* _head;
//}SList;


//�ð�����ָ���������ͷָ�뼰ͷβ��ָ��ά������
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

SListNode* SListFind(SList* plist, SLTDataType x);//��ֵ�ҽ�㣬���ؽ���ַ
// ��pos�ĺ�����в���
void SListInsertAfter(SList* plist, SListNode** pos, SLTDataType x);
// ��pos��ǰ����в���
void SListInsertFront(SList* plist, SListNode** pos, SLTDataType x);
void SListEraseAfter(SList* plist, SListNode** pos);
void SListErasePos(SList* plist, SListNode** pos);   //������ַɾ�����
size_t SListLength(SList* plist);
void SListRemove(SList* plist, SLTDataType x);  //��ֵɾ�����

void SListReverse(SList* plist); //��ת������
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, SLTDataType x);//��ֵɾ�����н��
void SListClear(SList* plist);
void SListDestory(SList* plist);

