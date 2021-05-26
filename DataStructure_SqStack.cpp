#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAXSIZE 100

typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
}SqStack;

void main();

Status InitStack(SqStack& S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status ClearStack(SqStack& S);
Status DestroyStack(SqStack& S);
Status Push(SqStack& S, SElemType x);
Status Pop(SqStack& S, SElemType* x);
Status GetTop(SqStack* S, SElemType* x);
void PrintStack(SqStack S);

void main() {
	SqStack S;
	int i, i_push;
	SElemType x;
	InitStack(S);
	printf("请输入要压入多少个的数据：");
	scanf("%d", &i_push);
	for ( i = 1; i <= i_push; i++)
	{
		printf("第%d个元素：", i);
		scanf("%d",&x);
		Push(S, x);
	}
	printf("长度为：%d\n",StackLength(S));
	PrintStack(S);
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

void PrintStack(SqStack S) {
	int length,i;
	length = StackLength(S);
	for ( i = length; i >0; i--)
	{
		S.top--;
		printf("第%d个位置的元素：%d\n", i, *S.top);
	}
}
