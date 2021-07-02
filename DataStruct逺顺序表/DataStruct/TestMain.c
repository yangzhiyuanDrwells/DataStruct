#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"seqlist.h"


int compare(const void* a, const void*  b)
{
	return (*(int*)a - *(int*)b);
}

void Pushsucceed(SeqList* psl, int flag)
{
	if ((int)psl->size > flag)
		printf("����ɹ�\n");

}

void Popsucceed(SeqList* psl, int flag)
{
	if ((int)psl->size < flag)
		printf("ɾ���ɹ�\n");
}

void SeqListDestory(SeqList* psl)
{
	free(psl->base);
	psl->base = NULL;
}
int main(int argc, char* argv[])
{
	SeqList mylist;
	SeqListInit(&mylist, 8);

	int  item;
	int find = 0;  // find_pos
	int select = 1;
	int find_ret = 0;
	int n = 0;     // insert_index   delete_index
	int data = 0;  // insert_data    delete_data
	int which = 0; // delete_index + 1
	int index = 0;
	int flag = 0;
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
			flag = mylist.size;

			printf("������Ҫ���������(��-1����):>");
			while ((void)scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			Pushsucceed(&mylist, flag);
			break;
		case 2:
			flag = mylist.size;
			printf("������Ҫ���������(��-1����):>");
			while ((void)scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			Pushsucceed(&mylist, flag);
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			flag = mylist.size;
			SeqListPopBack(&mylist);
			Popsucceed(&mylist, flag);
			break;
		case 5:
			flag = mylist.size;
			SeqListPopFront(&mylist);
			Popsucceed(&mylist, flag);
			break;
		case 6:
			printf("������Ҫ��ѯ���±�:>\n");
			
			(void)scanf("%d", &index);
			while (index > (int)mylist.size - 1 || index < 0)
			{
				printf("�Ƿ����룬Խ������ˣ�����������Ҫ���ҵ����ݵ��±�;>\n");
				(void)scanf("%d", &index);
			}

			find_ret = SeqListFindPos(&mylist, index);				
			printf("%d�±�������ǣ�%d\n", index, find_ret);
			break;
		case 7:
			printf("������Ҫ��ѯ�õ�����:>\n");

			(void)scanf("%d", &find);
			find_ret = SeqListFindVal(&mylist, find);
			if (find_ret == 0)
				printf("%dû���ҵ�\n", find);
			else
				printf("%d�ҵ���,���ҳ�����%d��\n", find, find_ret);
				SeqListFindAllPos(&mylist, (DataType*)mylist.base, find);
			break;
		case 8:
			flag = mylist.size;

			printf("������Ҫ��������ݺ�Ҫ������±�:>");
			(void)scanf("%d %d", &n, &data);
			SeqListInsertPos(&mylist, n+1, data);

			Pushsucceed(&mylist, flag);
			break;
		case 9:
			printf("������Ҫɾ��������:>\n");
			(void)scanf("%d", &find);
			if (SeqListDeletVal(&mylist, find))
				printf("ɾ���ɹ�\n");
			else
				printf("ɾ��ʧ��\n");
			break;
		case 10:

			flag = mylist.size;
			printf("������Ҫɾ�����±�:>\n");
			(void)scanf("%d", &index);
			while (index > (int)mylist.size - 1 || index < 0)
			{
				printf("�Ƿ����룬Խ������ˣ�����������Ҫ���ҵ����ݵ��±�;>\n");
				(void)scanf("%d", &index);
			}
			SeqListDeletPos(&mylist, index);
			Popsucceed(&mylist, flag);
			break;
		case 11:
			printf("�ѱ������Ч������%d��\n", mylist.size);
			break;
		case 12:
			flag = mylist.size;
			printf("������Ҫɾ��������:>\n");
			(void)scanf("%d", &find);
			SeqListRemoveAll(&mylist,  find);
			Popsucceed(&mylist, flag);
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
	SeqListDestory(&mylist);
	return 0;
}