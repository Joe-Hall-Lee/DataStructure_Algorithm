#define MAXSIZE 100
typedef int SElemType;

typedef struct
{
	SElemType* base; // ջ��ָ��
	SElemType* top; // ջ��ָ��
	int stacksize; // ջ�����������
} SqStack;