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
	printf("* [14] sort         [15] clear       *\n");
	printf("* [16] RemoveAll    [17] destory     *\n");
	printf("*************************************\n");
	printf("��ѡ��:>");
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
			printf("������Ҫ���������(��-1����):>");
			while ((void)scanf("%d", &data), data != -1)
				SListPushBack(&mylist, data);
			break;
		case 2:
			printf("����Ҫͷ�������(��-1����);>\n");
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
			printf("����Ҫ��ѯ��ַ������;>\n");
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, data);
			printf("%d pos -> %p\n", data, ret);
			break;
		case 7:
			printf("����Ҫ��һ�������Լ��������Ҫ���������:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫ����󷽲��������\n");
				return;
			}
			SListInsertAfter(&mylist, &ret, data);
			break;
		case 8:
			printf("����Ҫ��һ�������Լ�����ǰ��Ҫ���������:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫ����ǰ�����������\n");
				return;
			}
			SListInsertFront(&mylist, &ret, data);
			break;
		case 9:
			printf("����һ�����ݽ�ִ��ɾ����������ݵĲ���:>\n");
			(void)scanf("%d", &find);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�������\n");
				return;
			}
			SListEraseAfter(&mylist, &ret);
			break;
		case 10:
			printf("����һ�����ݽ�ִ��ɾ��������:>\n");
			(void)scanf("%d", &find);
			ret = SListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫִ��ɾ��������\n");
				return;
			}
			SListErasePos(&mylist, &ret);
			break;
		case 11:
			len = SListLength(&mylist);
			printf("������ĳ�����:%zu\n", len);
			break;
		case 12:
			printf("����һ�����ݽ�ִ��ɾ��������:>\n");
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
			printf("����һ�����ݽ�ȫ��ִ��ɾ��������:>\n");
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