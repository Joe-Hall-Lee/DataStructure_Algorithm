#include <iostream>
#define MAXQSIZE 100 // 最大队列长度
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // 初始化的动态分配存储空间
	int front; // 头指针,若队列不空，指向队列头元素
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQuene;

Status InitQuene(SqQuene& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // 分 配数组空间
	// Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType);
	if (!Q.base)
		exit(OVERFLOW);	  // 存储分配失败
	Q.front = Q.rear = 0; // 头指针、尾指针置为 0，队列为空
	return OK;
}
