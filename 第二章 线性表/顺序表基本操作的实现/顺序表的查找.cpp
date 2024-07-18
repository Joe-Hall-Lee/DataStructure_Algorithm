typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

int LocateElem(SqList L, ElemType e)
{
	// 在线性表 L 中查找值为 e 的数据元素，返回其序号（是第几个元素）
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1; // 查找成功，返回序号
		return 0; // 查找失败，返回 0
	}
}