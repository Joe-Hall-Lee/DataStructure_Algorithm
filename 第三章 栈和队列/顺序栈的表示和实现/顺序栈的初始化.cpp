#include <iostream>
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top;	// ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;

Status InitStack(SqStack& S) // ����һ����ջ
{
	S.base = new SElemType[MAXSIZE]; // ��
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); // �洢����ʧ��
	S.top = S.base; // ջ��ָ�����ջ��ָ��
	S.stacksize = MAXSIZE;
	return OK;
}