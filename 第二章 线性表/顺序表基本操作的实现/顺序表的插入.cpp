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

Status ListInsert_Sq(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR; // i ֵ���Ϸ�
	if (L.length == MAXSIZE)
		return ERROR; //  ��ǰ�洢�ռ�����
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; // ����λ�ü��Ժ��Ԫ�غ���
	L.elem[i - 1] = e; // ����Ԫ�� e ����� i ��λ��
	L.length++; // ���� 1
	return OK;
}
