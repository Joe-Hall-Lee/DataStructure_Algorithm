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

void BInsertSort(SqList& L)
{
	for (int i = 2; i <= L.length; ++i)  // 依次插入第 2~第 n 个元素
	{
		L.r[0] = L.r[i];  // 当前插入元素存到“哨兵”位置
		int low = 1;
		int high = i - 1;  // 采用二分查找法查找插入位置
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}  // 循环结束，high + 1 则为插入位置
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j];  // 移动元素
		L.r[high + 1] = L.r[0];  // 插入到正确位置
	}
}  // BInsertSort