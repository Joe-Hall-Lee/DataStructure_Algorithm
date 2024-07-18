typedef int KeyType;
typedef int ElemType;
typedef struct
{
	KeyType key;
}ElemType;

typedef struct // 顺序表结构类型定义
{
	ElemType* R;  // 表基址
	int length; // 表长
}SSTable;  // Sequential Search Table

// int Search_Seq(SSTable ST, KeyType key) // 若成功返回其位置信息，否则返回 0
// {
// 	for (int i = ST.length; i >= 1; --i)
// 	{
// 		if (ST.R[i].key == key)
// 			return i;
// 	}
// 	return 0;
// }

// // 其它形式
// int Search_Seq(SSTable ST, KeyType key)
// {
// 	int i;
// 	for (i = ST.length; ST.R[i].key != key; --i)
// 	{
// 		if (i <= 0)
// 			break;
// 	}
// 	if (i > 0)
// 		return i;
// 	else
// 		return 0;

// }

// int Search_Seq(SSTable ST, KeyType key)
// {
// 	int i;
// 	for (i = ST.length; ST.R[i].key && i > 0; --i);
// 	if (i > 0)
// 		return i;
// 	else
// 		return 0;
// }

// 设置监视哨的顺序查找
int Search_Seq(SSTable ST, KeyType key)
{
	int i = 0;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; --i)
		return i;
}
