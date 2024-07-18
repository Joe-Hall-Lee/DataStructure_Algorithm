#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList; // ����˳�������

Status ListDelete_Sq(SqList& L, int i)
{
	if (i < 1 || (i > L.length))
		return ERROR; // iֵ���Ϸ�
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j]; // ��ɾ��Ԫ��֮���Ԫ��ǰ��
	L.length--; // ���� 1

	return OK;
}