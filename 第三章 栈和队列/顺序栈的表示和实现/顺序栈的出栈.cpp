#define OK 1
#define ERROR 0
typedef int SElemType;
typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top;	// ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;

typedef int Status;

Status Pop(SqStack& S, SElemType& e) // ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR
{
	if (S.top == S.base) // �ȼ��� if (StackEmpty(S))
		return ERROR;
	e = *--S.top;
	return OK;
}