#define OK 1
#define ERROR 0
typedef int SElemType;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top;	// 栈顶指针
	int stacksize; // 栈可用最大容量
} SqStack;

typedef int Status;

Status Pop(SqStack& S, SElemType& e) // 若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK，否则返回 ERROR
{
	if (S.top == S.base) // 等价于 if (StackEmpty(S))
		return ERROR;
	e = *--S.top;
	return OK;
}