#include "stack.h"

void Test(stack* pst)
{
	StackDataType data = 0;
	StackPush(pst, 1);
	StackPush(pst, 2);
	StackPush(pst, 3);
	StackPush(pst, 4);
	StackShow(pst);
	printf("StackTop = %d\n", StackTop(pst));
	printf("size = %d\n", StackSize(pst));
	StackPop(pst);
	StackShow(pst);
	printf("StackTop = %d\n", StackTop(pst));
	printf("size = %d\n", StackSize(pst));
	StackPop(pst);
	StackShow(pst);
	printf("StackTop = %d\n", StackTop(pst));
	printf("size = %d\n", StackSize(pst));
	StackPop(pst);
	StackShow(pst);

	StackClear(pst);
	printf("size = %d\n", StackSize(pst));
	StackPop(pst);
	StackShow(pst);

}

int main()
{
	stack st;
	StackInital(&st);
	Test(&st);
	return 0;
}