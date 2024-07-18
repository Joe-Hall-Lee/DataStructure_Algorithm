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

Status ListInsert_Sq(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR; // i 值不合法
	if (L.length == MAXSIZE)
		return ERROR; //  当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; // 插入位置及以后的元素后移
	L.elem[i - 1] = e; // 将新元素 e 放入第 i 个位置
	L.length++; // 表长增 1
	return OK;
}
