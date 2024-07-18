#include <iostream>
#define MAXQSIZE 100 // �����г���
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ��,�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} SqQuene;

Status InitQuene(SqQuene& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // �� ������ռ�
	// Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType);
	if (!Q.base)
		exit(OVERFLOW);	  // �洢����ʧ��
	Q.front = Q.rear = 0; // ͷָ�롢βָ����Ϊ 0������Ϊ��
	return OK;
}
