#define ERROR 0
#define OK 1
typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

int GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1]; // 第 i - 1 的单元存储着第 i 个数据
	return OK;
}
