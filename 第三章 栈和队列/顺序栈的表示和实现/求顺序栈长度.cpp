typedef int SElemType;

typedef struct
{
	SElemType* base; //ջ��ָ��
	SElemType* top; //ջ��ָ��
	int stacksize; //ջ�����������
}SqStack;

int StackLength(SqStack S)
{
	return S.top - S.base;
}