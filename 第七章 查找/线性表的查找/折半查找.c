typedef int ElemType;
typedef int KeyType;
typedef struct
{
	KeyType key;
}ElemType;

typedef struct // 顺序表结构类型定义
{
	ElemType* R; // 表基址
	int length; // 表长
}SSTable; // Sequential Search Table

int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length; // 置区间初值
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (ST.R[mid].key == key)
			return mid; // 找到待查元素
		else if (key < ST.R[mid].key) // 缩小查找范围
			high = mid - 1; // 继续在前半区间进行查找
		else
			low = mid + 1; // 继续在后半区间进行查找
	}
	return 0;  // 顺序表中不存在待查元素
}  // Search_Bin
