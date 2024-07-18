#define MAXSIZE 20 // 设记录不超过 20 个
typedef int KeyType; // 设关键字为整型量（int 型）
typedef int InfoType;

typedef struct // 定义每个记录（数据元素）的结构
{
	KeyType key;  // 关键字
	InfoType otherinfo;  // 其它数据项
}RedType; // Record Type

typedef struct // 定义顺序表的结构
{
	RedType r[MAXSIZE + 1];  // 存储顺序表的向量，r[0] 一般作哨兵或缓冲区
	int length;  // 顺序表的结构
}SqList;

void bubble_sort1(SqList& L, int n) // 冒泡排序算法
{
	int m, i, j;
	RedType x; // 交换时临时存储
	for (m = 1; m <= n - 1; m++) // 总共需 m 趟
	{
		for (j = 1; j <= n - m; j++)
		{
			if (L.r[j].key > L.r[j + 1].key)  // 发生逆序
			{
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x; // 交换
			} // endif
		} // forif
	}
}