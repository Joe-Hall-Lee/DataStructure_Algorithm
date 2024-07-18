#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top;	// 栈顶指针
	int stacksize; // 栈可用最大容量
} SqStack;

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) // 栈满
		return ERROR;
	*S.top++ = e;
	return OK;
}