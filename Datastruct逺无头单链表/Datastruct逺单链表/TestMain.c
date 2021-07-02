#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//无头单链表

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
	printf("请选择:>");
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
		printf("没有找到\n");

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
				printf("请输入要插入的数据(以-1结束):>");
				while ((void)scanf("%d", &data), data != -1)
					SListPushBack(&head, data);
				break;
			case 2:
				printf("输入要头插的数据(以-1结束);>\n");
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
				printf("输入要查询地址的数据;>\n");
				(void)scanf("%d", &data);
				ret = SListFind(&head, data);
				printf("%d pos -> %p\n", data, ret);
				break;
			case 7:
				printf("输入要在一个数据以及再其后面要插入的数据:>\n");
				(void)scanf("%d", &find);
				(void)scanf("%d", &data);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("没有找到要在其后方插入的数据\n");
					return;
				}
				SListInsertAfter(&ret, data);
				break;
			case 8:
				printf("输入要在一个数据以及再其前面要插入的数据:>\n");
				(void)scanf("%d", &find);
				(void)scanf("%d", &data);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("没有找到要在其前方插入的数据\n");
					return;
				}
				SListInsertFront(&ret, data);
				break;
			case 9:
				printf("输入一个数据将执行删除其后面数据的操作:>\n");
				(void)scanf("%d", &find);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("没有找到该数据\n");
					return;
				}
				SListEraseAfter(&ret);
				break;
			case 10:
				printf("输入一个数据将执行删除的数据:>\n");
				(void)scanf("%d", &find);
				ret = SListFind(&head, find);
				if (ret == NULL)
				{
					printf("没有找到要执行删除的数据\n");
					return;
				}
				SListErasePos(&ret, &head);
				break;
			case 11:
				len = SListLength(&head);
				printf("单链表的长度是:%u\n", len);
				break;
			case 12:
				printf("输入一个数据将执行删除的数据:>\n");
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
				printf("输入一个数据将全部执行删除的数据:>\n");
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