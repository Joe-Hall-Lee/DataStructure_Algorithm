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

Status InitList_Sq(SqList& L) // ����һ���յ�˳��� L
{
	L.elem = new ElemType[MAXSIZE]; // Ϊ˳������ռ�
	if (!L.elem)
		exit(OVERFLOW); // �洢����ʧ��
	L.length = 0; // �ձ���Ϊ 0
	return OK;
}