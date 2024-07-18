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
}SqList; // 定义顺序表类型

Status InitList_Sq(SqList& L) // 创造一个空的顺序表 L
{
	L.elem = new ElemType[MAXSIZE]; // 为顺序表分配空间
	if (!L.elem)
		exit(OVERFLOW); // 存储分配失败
	L.length = 0; // 空表长度为 0
	return OK;
}