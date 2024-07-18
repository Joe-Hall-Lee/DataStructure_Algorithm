#define MAXQSIZE 100 // 最大队列长度
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // 初始化的动态分配存储空间
	int front; // 头指针，若队列不空，指向队列头元素
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQuene;

Status DeQuene(SqQuene& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // 队空
	e = Q.base[Q.front]; // 保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针 + 1
	return OK;
}
