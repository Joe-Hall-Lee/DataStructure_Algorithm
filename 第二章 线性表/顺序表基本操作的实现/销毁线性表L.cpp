#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList; // ����˳�������

void DestroyList(SqList& L)
{
	if (L.elem)
		delete L.elem; // �ͷŴ洢�ռ�
}