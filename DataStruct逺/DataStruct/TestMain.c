#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"seqlist.h"


int compare(const void* a, const void*  b)
{
	return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[])
{
	SeqList mylist;
	SeqListInit(&mylist, 8);

	DataType item;
	DataType find = 0;  // find_pos
	DataType select = 1;
	DataType find_ret = 0;
	DataType n = 0;     // insert_index   delete_index
	DataType data = 0;  // insert_data    delete_data
	DataType which = 0; // delete_index + 1
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_pos    [9] delete_val *\n");
		printf("* [10] delete_pos   [11]length     *\n");
		printf("* [12] remove_all   [13] reverse   *\n");
		printf("* [14] sort         [15] clear     *\n");  //15 destory
		printf("************************************\n");
		printf("��ѡ��:>");
		(void)scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while ((void)scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while ((void)scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			(void)scanf("%d", &find);
			find_ret = SeqListFindPos(&mylist, find);
			if (find_ret == -1)
				printf("%dû���ҵ�\n", find);
			else
				printf("%d�ҵ��ˣ��±�Ϊ��%d\n", find, find_ret);
			break;
		case 7:
			(void)scanf("%d", &find);
			find_ret = SeqListFindVal(&mylist, find);
			if (find_ret == 0)
				printf("%dû���ҵ�\n", find);
			else
				printf("%d�ҵ���,���ҳ�����%d��\n", find, find_ret);
				SeqListFindAllPos(&mylist, (DataType*)mylist.base, find);
			break;
		case 8:
			(void)scanf("%d %d", &n, &data);
			SeqListInsertPos(&mylist, n, data);
			break;
		case 9:
			(void)scanf("%d", &find);
			SeqListFindAllPos(&mylist,(DataType*) mylist.base, find);
			(void)scanf("%d", &which);
			if (which > (int)mylist.size - 1)
				printf("�Ƿ����룬Խ������ˣ�����������Ҫɾ���������ǵڼ���\n");
			while (which > (int)mylist.size - 1)
				(void)scanf("%d", &which);
			SeqListDeletVal(&mylist, which);
			break;
		case 10:
			(void)scanf("%d", &which);
			if (which > (int)mylist.size - 1)
				printf("�Ƿ����룬Խ������ˣ�����������Ҫɾ���������ǵڼ���\n");
			while (which > (int)mylist.size - 1)
				(void)scanf("%d", &which);
			SeqListDeletPos(&mylist, which);
			break;
		case 11:
			printf("�ѱ������Ч������%d��\n", mylist.size);
			break;
		case 12:
			SeqListRemoveAll(&mylist, mylist.capacity);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			qsort(
				(void*)mylist.base,
				mylist.size, 
				sizeof(DataType),
				compare
			);
			break;
		case 15:
			SeqListClear(&mylist);
			break;
		}
	}
	return 0;
}