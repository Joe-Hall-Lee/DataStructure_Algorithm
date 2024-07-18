typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

int IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}