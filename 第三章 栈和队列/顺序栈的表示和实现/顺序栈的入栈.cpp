#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top;	// ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) // ջ��
		return ERROR;
	*S.top++ = e;
	return OK;
}