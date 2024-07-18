typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

int GetLength(SqList L)
{
	return (L.length);
}
