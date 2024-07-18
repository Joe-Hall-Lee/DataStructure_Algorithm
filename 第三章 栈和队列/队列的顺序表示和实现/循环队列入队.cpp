#define MAXQSIZE 100 // 最大队列长度
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // 初始化的动态分配存储空间
	int front; // 头指针，若队列不空，指向队列头元素
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQuene;


Status EnQuene(SqQuene& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // 队满
	Q.base[Q.rear] = e; // 新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; // 队尾指针 + 1 
}
