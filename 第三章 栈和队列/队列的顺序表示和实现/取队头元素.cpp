#define MAXQSIZE 100  // �����г���
typedef int QElemType;
typedef struct
{
	QElemType* base;  // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQuene;

QElemType GetHead(SqQuene Q)
{
	if (Q.front != Q.rear) // ���в�Ϊ��
		return Q.base[Q.front]; // ���ض�ͷָ��Ԫ�ص�ֵ����ͷָ�벻��
}