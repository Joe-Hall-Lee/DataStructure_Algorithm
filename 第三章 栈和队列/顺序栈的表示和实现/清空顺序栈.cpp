#define OK 1
typedef int SElemType;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top;	// ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;

typedef int Status;
Status ClearStack(SqStack S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}