#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//��ͷ������

static void menu()
{
	printf("*************************************\n");
	printf("* [0]  quit_system  [1]  push_back   *\n");
	printf("* [2]  push_front   [3]  show_list   *\n");
	printf("* [4]  pop_back     [5]  pop_front   *\n");
	printf("* [6]  find_by_val  [7]  insert_after*\n");
	printf("* [8]  insert_front [9]  erase_after *\n");
	printf("* [10] delete_pos   [11] length      *\n"); 
	printf("* [12] remove       [13] reverse     *\n");
	printf("* [14] sort         [15] destory     *\n");
	printf("* [16] RemoveAll                     *\n");
	printf("*************************************\n");
	printf("��ѡ��:>");
}

static void Test1(SList* head, SList* ret)
{
	SListInit(head);
	SListPushFront(head, 4);
	SListPushBack(head, 8);
	SListPushFront(head, 3);
	SListPushBack(head, 6);
	SListShow(head);

	SListPopFront(head);
	SListShow(head);

	SListPopBack1(head);
	SListShow(head);

	SListPopBack2(head);
	SListShow(head);

	SListPushFront(head, 4);
	SListPushBack(head, 8);
	SListPushBack(head, 6);
	SListPushFront(head, 3);
	SListPushBack(head, 6);
	SListShow(head);

	*ret = SListFind(head, 6);
	if (*ret != NULL)
		SListShowRet(ret);
	else
		printf("û���ҵ�\n");

	SListInsertAfter(ret, 66);
	SListShow(head);

	SListInsertFront(ret, 998);
	SListShow(head);

	*ret = SListFind(head, 6);
	SListEraseAfter(ret);
	SListShow(head);
	
	SListRemove1(head, 6);
	SListShow(head);

	SListRemoveAll(head, 6);
	SListShow(head);

	SListDestory(head);
	SListShow(head);
}



int main()
{
	SList head;
	SList ret = NULL;
	Test1(&head, &ret);
	SLTDataType data = 0;

	int input = 0;
	int find = 0;
	size_t len = 0;
	do {
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{
		    case 0:
				break;
			case 1:
				printf("������Ҫ���������(��-1����):>");
				while ((void)scanf("%d", &data), data != -1)
					SListPushBack(&head, data);
				break;
			case 2:
				printf("����Ҫͷ�������(��-1����);>\n");
				while ((void)scanf("%d", &data), data != -1)
				SListPushFront(&head, data);
				break;
			case 3:
				SListShow(&head);
				break;
			case 4:
				SListPopBack1(&head);
				break;
			case 5:
				SListPopFront(&head);
				break;
			case 6:
				printf("����Ҫ��ѯ��ַ������;>\n");
				(void)scanf("%d", &data);
				ret = SListFind(&head, data);
				printf("%d pos -> %p\n", data, ret);
				break;
			case 7:
				printf("����Ҫ��һ�������Լ��������Ҫ���������:>\n");
				(void)scanf("%d", &find);
				(void)scanf("%d", &data);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("û���ҵ�Ҫ����󷽲��������\n");
					return;
				}
				SListInsertAfter(&ret, data);
				break;
			case 8:
				printf("����Ҫ��һ�������Լ�����ǰ��Ҫ���������:>\n");
				(void)scanf("%d", &find);
				(void)scanf("%d", &data);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("û���ҵ�Ҫ����ǰ�����������\n");
					return;
				}
				SListInsertFront(&ret, data);
				break;
			case 9:
				printf("����һ�����ݽ�ִ��ɾ����������ݵĲ���:>\n");
				(void)scanf("%d", &find);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("û���ҵ�������\n");
					return;
				}
				SListEraseAfter(&ret);
				break;
			case 10:
				printf("����һ�����ݽ�ִ��ɾ��������:>\n");
				(void)scanf("%d", &find);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("û���ҵ�Ҫִ��ɾ��������\n");
					return;
				}
				SListErasePos(&ret, &head);
				break;
			case 11:
				len = SListLength(&head);
				printf("������ĳ�����:%u\n", len);
				break;
			case 12:
				printf("����һ�����ݽ�ִ��ɾ��������:>\n");
				(void)scanf("%d", &data);
				SListRemove1(&head, data);
				break;
			case 13:
				SListReverse(&head);
				break;
			case 14:
				SListSort(&head);
				break;
			case 15:
				SListDestory(&head);
				break;
			case 16:
				printf("����һ�����ݽ�ȫ��ִ��ɾ��������:>\n");
				(void)scanf("%d", &data);
				SListRemoveAll(&head, data);
				break;
			default:
				printf("input error!\n");
				break;
		}
	} while (input);


	/*int input = 1;
	while (input)
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;


		default:
			break;
		}

	} */

	return 0;
}