#define MAXSIZE 20  // 设记录不超过 20 个
typedef int KeyType;  // 设关键字为整型量（int 型）
typedef int InfoType;

typedef struct  // 定义每个记录（数据元素）的结构
{
	KeyType key;  // 关键字
	InfoType otherinfo;
}RedType;  // Record Type

typedef struct  // 定义顺序表的结构
{
	RedType r[MAXSIZE + 1];  // 存储顺序表的向量
	int length;  // 顺序表的长度
}SqList;

void ShellInsert(SqList& L, int dk)  // 对顺序表L进行一趟增量为 dk 的 Shell 排序，dk 为步长因子
{
	int i, j;
	for (i = dk + 1; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - dk].key)
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j = j - dk)
				L.r[j - dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
	}
}

void ShellSort(SqList& L, int dlta[], int t)
{
	// 按增量序列 dlta[0...t-1] 对顺序表 L 作希尔排序。
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);  // 一趟增量为 dlta[k] 的插入排序
}  // ShellSort