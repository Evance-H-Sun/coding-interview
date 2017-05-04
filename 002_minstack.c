#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	int min;
} Node, *pNode;

typedef struct mStack
{
	int maxSize;
	int top;
	pNode vArray;
} MStack, *pMStack;

pMStack initMStack(int maxSize);
void freeMStack(pMStack s);
bool pushMStack(pMStack s, int value);
int getMinValue(pMStack s);
int popMStack(pMStack s);

int main(void)
{
	pMStack s = NULL;
	bool good = true;
	s = initMStack(10);
	if (s == NULL)
	{
		printf("MStack Initializtion FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	good = pushMStack(s, 9);
	if (!good)
	{
		printf("push 1 FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	good = pushMStack(s, 7);
	if (!good)
	{
		printf("push 2 FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	good = pushMStack(s, 9);
	if (!good)
	{
		printf("push 3 FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	good = pushMStack(s, 5);
	if (!good)
	{
		printf("push 4 FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	printf("pop 1: %d\n", popMStack(s));
	printf("Min of Stack is: %d\n", getMinValue(s));
	good = pushMStack(s, 7);
	if (!good)
	{
		printf("push 5 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 9);
	if (!good)
	{
		printf("push 6 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 5);
	if (!good)
	{
		printf("push 7 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 7);
	if (!good)
	{
		printf("push 8 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 9);
	if (!good)
	{
		printf("push 9 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 5);
	if (!good)
	{
		printf("push 10 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 7);
	if (!good)
	{
		printf("push 11 FAILED!\n");
		return -1;
	}
	good = pushMStack(s, 9);
	if (!good)
	{
		printf("push 12 FAILED!\n");
		return -1;
	}
	printf("Min of Stack is: %d\n", getMinValue(s));
	printf("pop 1: %d\n", popMStack(s));
	printf("Min of Stack is: %d\n", getMinValue(s));

	freeMStack(s);
	return 0;
}

pMStack initMStack(int maxSize)
{
	pMStack s = (pMStack)malloc(sizeof(MStack));
	if (s == NULL)
		return NULL;
	s->maxSize = maxSize;
	s->top = -1;
	s->vArray = (pNode)malloc(maxSize * sizeof(Node));
	if (s->vArray == NULL)
	{
		free(s);
		return NULL;
	}

	return s;
}

void freeMStack(pMStack s)
{
	free(s->vArray);
	free(s);
}

bool pushMStack(pMStack s, int value)
{
	if (s->maxSize == (s->top + 1))
		return false;
	pNode n = &(s->vArray[s->top + 1]);
	if (s->top == -1)
	{
		n->min = value;
	}
	else
	{
		n->min = s->vArray[s->top].min < value ? s->vArray[s->top].min : value;
	}
	n->value = value;
	s->top++;

	return true;
}

int getMinValue(pMStack s)
{
	if (s->top == -1)
		return -1;
	return s->vArray[s->top].min;
}

int popMStack(pMStack s)
{
	if (s->top == -1)
		return -1;
	s->top--;
	return s->vArray[s->top + 1].value;
}
