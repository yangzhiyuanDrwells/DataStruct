#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//有头单链表

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
	printf("* [14] sort         [15] clear       *\n");
	printf("* [16] RemoveAll    [17] destory     *\n");
	printf("*************************************\n");
	printf("请选择:>");
}


int main()
{
	SList mylist;
	SListInit(&mylist);
	SListNode* ret = NULL;
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
				SListPushBack(&mylist, data);
			break;
		case 2:
			printf("输入要头插的数据(以-1结束);>\n");
			while ((void)scanf("%d", &data), data != -1)
				SListPushFront(&mylist, data);
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("输入要查询地址的数据;>\n");
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, data);
			printf("%d pos -> %p\n", data, ret);
			break;
		case 7:
			printf("输入要在一个数据以及再其后面要插入的数据:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要在其后方插入的数据\n");
				return;
			}
			SListInsertAfter(&mylist, &ret, data);
			break;
		case 8:
			printf("输入要在一个数据以及再其前面要插入的数据:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要在其前方插入的数据\n");
				return;
			}
			SListInsertFront(&mylist, &ret, data);
			break;
		case 9:
			printf("输入一个数据将执行删除其后面数据的操作:>\n");
			(void)scanf("%d", &find);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到该数据\n");
				return;
			}
			SListEraseAfter(&mylist, &ret);
			break;
		case 10:
			printf("输入一个数据将执行删除的数据:>\n");
			(void)scanf("%d", &find);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要执行删除的数据\n");
				return;
			}
			SListErasePos(&mylist, &ret);
			break;
		case 11:
			len = SListLength(&mylist);
			printf("单链表的长度是:%zu\n", len);
			break;
		case 12:
			printf("输入一个数据将执行删除的数据:>\n");
			(void)scanf("%d", &data);
			SListRemove(&mylist, data);
			break;
		case 13:
			SListReverse(&mylist);
			break;
		case 14:
			SListSort(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			break;
		case 16:
			printf("输入一个数据将全部执行删除的数据:>\n");
			(void)scanf("%d", &data);
			SListRemoveAll(&mylist, data);
			break;
		case 17:
			SListDestory(&mylist);
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