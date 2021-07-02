#define _CRT_SECURE_NO_WARNINGS 1
#include "SCDList.h"

//��ͷ��ѭ������

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
			printf("������Ҫβ�������(��-1����):>");
			while ((void)scanf("%d", &data), data != -1)
				SCDListPushBack(&mylist, data);
			break;
		case 2:
			printf("����Ҫͷ�������(��-1����);>\n");
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
			printf("����Ҫ��ѯ��ַ������;>\n");
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, data);
			printf("%d pos -> %p\n", data, ret);
			break;
		case 7:
			printf("����Ҫ��һ�������Լ��������Ҫ���������:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫ����󷽲��������\n");
				return;
			}
			SCDListInsertAfter(&mylist, &ret, data);
			break;
		case 8:
			printf("����Ҫ��һ�������Լ�����ǰ��Ҫ���������:>\n");
			(void)scanf("%d", &find);
			(void)scanf("%d", &data);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫ����ǰ�����������\n");
				return;
			}
			SCDListInsertFront(&mylist, &ret, data);
			break;
		case 9:
			printf("����һ�����ݽ�ִ��ɾ����������ݵĲ���:>\n");
			(void)scanf("%d", &find);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�������\n");
				return;
			}
			SCDListEraseAfter(&mylist, &ret);
			break;
		case 10:
			printf("����һ�����ݽ�ִ��ɾ��������:>\n");
			(void)scanf("%d", &find);
			ret = SCDListFind(&mylist, find);
			if (ret == NULL)
			{
				printf("û���ҵ�Ҫִ��ɾ��������\n");
				return;
			}
			SCDListErasePos(&mylist, &ret);
			break;
		case 11:
			len = SCDListLength(&mylist);
			printf("������ĳ�����:%zu\n", len);
			break;
		case 12:
			printf("����һ�����ݽ�ִ��ɾ��������:>\n");
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
			printf("����һ�����ݽ�ȫ��ִ��ɾ��������:>\n");
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