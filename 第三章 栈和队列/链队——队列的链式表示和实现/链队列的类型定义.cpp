#define MAXQSIZE 100 //�����г���
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, *QuenePtr;

typedef struct
{
	QuenePtr front; //��ͷָ��
	QuenePtr rear; //��βָ��
}LinkQuene;
