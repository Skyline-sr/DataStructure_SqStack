#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAXSIZE 100

typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status ClearStack(SqStack& S);
Status DestroyStack(SqStack& S);
Status Push(SqStack& S, SElemType x);
Status Pop(SqStack& S, SElemType* x);
Status GetTop(SqStack* S, SElemType* x);

void main() {
	SqStack S;
}

Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
	{
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status StackEmpty(SqStack S) {
	if (S.top == S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StackLength(SqStack S) {
	return (S.top - S.base);
}

Status ClearStack(SqStack& S) {
	if (S.base)
	{
		S.top == S.base;
		return OK;
	}
	return ERROR;
}

Status DestroyStack(SqStack& S) {
	if (S.base)
	{
		delete S.base;
		S.base = S.top = NULL;
		S.stacksize = 0;
		return OK;
	}
	return ERROR;
}

Status Push(SqStack& S, SElemType x) {
	if (StackLength(S) == S.stacksize)
	{
		printf("栈已满！");
		return ERROR;
	}
	*S.top = x;
	S.top++;
	return OK;
}

Status Pop(SqStack& S, SElemType* x) {
	if (S.top == S.base)
	{
		printf("栈为空，无元素出栈！");
		return ERROR;
	}
	S.top--;
	*x = *S.top;
	return OK;
}

Status GetTop(SqStack* S, SElemType* x) {
	if (S->top == S->base)
	{
		printf("栈为空！");
		return ERROR;
	}
	*x = *(S->top - 1);
	return OK;
}
