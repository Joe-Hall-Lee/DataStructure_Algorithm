#define MAXQSIZE 100 // �����г���
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQuene;

Status DeQuene(SqQuene& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // �ӿ�
	e = Q.base[Q.front]; // �����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; // ��ͷָ�� + 1
	return OK;
}
