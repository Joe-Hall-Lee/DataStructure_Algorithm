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
}SqList;  // 定义顺序表类型

void ClearList(SqList& L)
{
	L.length = 0;  // 将线性表的长度置为 0
}
