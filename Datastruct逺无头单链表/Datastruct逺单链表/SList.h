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
typedef struct SListNode* SList;//#define  SList struct SListNode* 

//�ð���ָ��������Ľṹ��ά������
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
SListNode* SListFind(SList* plist, SLTDataType x);//��ֵ�ҽ�㣬���ؽ���ַ
// ��pos�ĺ�����в���
void SListInsertAfter(SList* pos, SLTDataType x);
// ��pos��ǰ����в���
void SListInsertFront(SList* pos, SLTDataType x);
void SListEraseAfter(SList* pos);
void SListErasePos(SList* pos, SList* head);   //������ַɾ�����
size_t SListLength(SList* head);
void SListRemove1(SList* head, SLTDataType x);  //��ֵɾ�����
void SListRemove2(SList* plist, SLTDataType x);  //��ֵɾ�����
void SListReverse(SList* head); //��ת������
void SListSort(SList* head); 
void SListRemoveAll(SList* head, SLTDataType x);//��ֵɾ�����н��
void SListRemoveAll2(SList* head, SLTDataType x);
