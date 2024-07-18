#define MAXQSIZE 100 // �����г���
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQuene;


Status EnQuene(SqQuene& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // ����
	Q.base[Q.rear] = e; // ��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; // ��βָ�� + 1 
}
