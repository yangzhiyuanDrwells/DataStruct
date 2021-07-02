#define _CRT_SECURE_NO_WARNINGS 1
#include "SCDList.h"

//有头单循环链表

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
	SCDList mylist;
	SCDListInit(&mylist);
	SCDListNode* ret = NULL;
	SCDLDataType data = 0;

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
			printf("请输入要尾插的数据(以-1结束):>");
			while ((void)scanf("%d", &data), data != -1)
				SCDListPushBack(&mylist, data);
			break;
		case 2:
			printf("输入要头插的数据(以-1结束);>\n");
			while ((void)scanf("%d", &data), data != -1)
				SCDListPushFront(&mylist, data);
			break;
		case 3:
			SCDListShow(&mylist);
			break;
		case 4:
			SCDListPopBack(&mylist);
			break;
		case 5:
			SCDListPopFront(&mylist);
			break;
		case 6:
			printf("输入要查询地址的数据;>\n");
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, data);
			printf("%d pos -> %p\n", data, ret);
			break;
		case 7:
			printf("输入要在一个数据以及再其后面要插入的数据:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要在其后方插入的数据\n");
				return;
			}
			SCDListInsertAfter(&mylist, &ret, data);
			break;
		case 8:
			printf("输入要在一个数据以及再其前面要插入的数据:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要在其前方插入的数据\n");
				return;
			}
			SCDListInsertFront(&mylist, &ret, data);
			break;
		case 9:
			printf("输入一个数据将执行删除其后面数据的操作:>\n");
			(void)scanf("%d", &find);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到该数据\n");
				return;
			}
			SCDListEraseAfter(&mylist, &ret);
			break;
		case 10:
			printf("输入一个数据将执行删除的数据:>\n");
			(void)scanf("%d", &find);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("没有找到要执行删除的数据\n");
				return;
			}
			SCDListErasePos(&mylist, &ret);
			break;
		case 11:
			len = SCDListLength(&mylist);
			printf("单链表的长度是:%zu\n", len);
			break;
		case 12:
			printf("输入一个数据将执行删除的数据:>\n");
			(void)scanf("%d", &data);
			SCDListRemove(&mylist, data);
			break;
		case 13:
			SCDListReverse(&mylist);
			break;
		case 14:
			SCDListSort(&mylist);
			break;
		case 15:
			SCDListClear(&mylist);
			break;
		case 16:
			printf("输入一个数据将全部执行删除的数据:>\n");
			(void)scanf("%d", &data);
			SCDListRemoveAll(&mylist, data);
			break;
		case 17:
			SCDListDestory(&mylist);
			break;
		default:
			printf("input error!\n");
			break;
		}
	} while (input);

	return 0;
}