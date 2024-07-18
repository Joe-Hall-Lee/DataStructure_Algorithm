#define MAXQSIZE 100 //最大队列长度
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, *QuenePtr;

typedef struct
{
	QuenePtr front; //队头指针
	QuenePtr rear; //队尾指针
}LinkQuene;
