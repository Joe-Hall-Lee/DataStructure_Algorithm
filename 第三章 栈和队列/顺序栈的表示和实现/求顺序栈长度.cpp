typedef int SElemType;

typedef struct
{
	SElemType* base; //栈底指针
	SElemType* top; //栈顶指针
	int stacksize; //栈可用最大容量
}SqStack;

int StackLength(SqStack S)
{
	return S.top - S.base;
}