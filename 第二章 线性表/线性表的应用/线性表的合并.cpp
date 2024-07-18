#define OK 1
#define ERROR 0
#define MAXSIZE 50
typedef int Status;
typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}List; // 定义顺序表类型

int ListLength(List L)
{
	return (L.length);
}

int GetElem(List L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1]; // 第 i - 1 的单元存储着第 i 个数据
	return OK;
}

int LocateElem(List L, ElemType e)
{
	// 在线性表 L 中查找值为 e 的数据元素，返回其序号（是第几个元素）
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1; // 查找成功，返回序号
		return 0; // 查找失败，返回 0
	}
}

Status ListInsert(List& L, int i, ElemType e)
{
	if (i < 1 || i>L.length + 1)
		return ERROR; // i 值不合法
	if (L.length == MAXSIZE)
		return ERROR; // 当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; // 插入位置及以后的元素后移
	L.elem[i - 1] = e; // 将新元素 e 放入第 i 个位置
	L.length++; // 表长增 1
	return OK;
}

void union_list(List& La, List& Lb)
{
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);

	for (int i = 1; i <= Lb_len; i++)
	{
		ElemType e = GetElem(Lb, i, e);
		if (!LocateElem(La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}

}
