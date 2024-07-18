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
}SqList; // 定义顺序表类型

Status ListDelete_Sq(SqList& L, int i)
{
	if (i < 1 || (i > L.length))
		return ERROR; // i值不合法
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
	L.length--; // 表长减 1

	return OK;
}