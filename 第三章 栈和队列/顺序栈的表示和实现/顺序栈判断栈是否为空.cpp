#include <iostream>
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top;	// ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;

Status StackEmpty(SqStack S) // ��ջΪ�գ����� TRUE�����򷵻� FALSE
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}