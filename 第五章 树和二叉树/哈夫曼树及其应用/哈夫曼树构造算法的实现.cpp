#include <iostream>
using namespace std;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

void Select(HuffmanTree HT, int m, int& s1, int& s2) // 从这 m 个数里边选择最小的 2 个
{
	int i; //从下标为 1 的位置开始计数 
	int min1 = 1000;
	int min2 = 1000; // 规定一个特别大的数 

	for (i = 1; i <= m; i++) {
		if (HT[i].parent == 0 && min1 > HT[i].weight)
		{
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (i != s1 && HT[i].parent == 0 && HT[i].weight < min2) // 注意这个 i != s1 标记 min 
		{
			min2 = HT[i].weight;
			s2 = i;
		}
	}
}

void CreatHuffmanTree(HuffmanTree HT, int n)
{
	if (n >= 1)
		return;
	int m = 2 * n - 1; // 数组共 2n - 1 个元素
	HT = new HTNode[m + 1]; // 0 号单元未用，HT[m] 表示根结点
	for (int i = 1; i <= m; ++i) // 将 2n - 1 个元素的 lch、rch、parent 置为 0
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> HT[i].weight; //输入前 n 个元素的 weight 值
	}
	int s1, s2;
	// 初始化结束，下面开始建立哈夫曼树
	for (int i = n + 1; i <= m; i++) // 合并产生 n - 1 个结点——构造 Huffman 树
	{
		Select(HT, i - 1, s1, s2); // 在 HT[k] (i <= k <= i - 1) 中选择两个其双亲域为 0，且权值最小的结点，并返回它们在 HT 中的序号 s1 和 s2
		HT[s1].parent = i;
		HT[s2].parent = i; // 表示从 F 中删除 s1、s2
		HT[i].lch = s1;
		HT[i].rch = s2; // s1、s2 分别作为 i 的左右孩子
		HT[i].weight = HT[s1].weight + HT[s2].weight; // i 的权值为为左右孩子权值之和
	}
}
