#include "stack.h"


int main(int argc, char *argv[])
{
	stack st;
	StackInit(&st, 6);
	TestStack(&st);
	return 0;
}