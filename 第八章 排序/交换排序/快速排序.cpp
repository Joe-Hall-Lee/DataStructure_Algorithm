#include <iostream>
using namespace std;
#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量

typedef int KeyType; // 设关键字为整型量（int 型）
typedef int InfoType;
typedef struct // 定义每个记录（数据元素）的结构
{
	KeyType key; // 关键字
	InfoType otherinfo; // 其它数据项
}RedType; // Record Type

typedef struct
{
	RedType r[LIST_INIT_SIZE];
	int length; // 当前长度
}SqList;

int Partition(SqList& L, int low, int high)
{
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int high) // 对顺序表快速排序
{
	if (low < high) // 长度大于 1
	{
		int pivotloc = Partition(L, low, high); // 将 L.[low...high] 一分为二，pivotloc 为枢轴元素排好序的位置
		QSort(L, low, pivotloc - 1); // 对低子表递归排序
		QSort(L, pivotloc + 1, high); // 对高子表递归排序
	} // endif
} // QSort

void main()
{
	SqList L;
	for (int i = 1; i < 11; i++)
	{
		L.r[i].key = 10 - i;
	}
	L.length = 10;
	QSort(L, 1, L.length);
}