#define MAXQSIZE 100  // 最大队列长度
typedef int QElemType;
typedef struct
{
	QElemType* base;  // 初始化的动态分配存储空间
	int front; // 头指针，若队列不空，指向队列头元素
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQuene;

QElemType GetHead(SqQuene Q)
{
	if (Q.front != Q.rear) // 队列不为空
		return Q.base[Q.front]; // 返回队头指针元素的值，队头指针不变
}