#include <iostream>
using namespace std;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;	// 哈夫曼编码表，指针数组

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) //从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表 HC 中
{
	HC = new char* [n + 1]; // 分配 n 个字符编码的头指针矢量
	char* cd = new char[n]; // 分配临时存放编码的动态数组空间
	cd[n - 1] = '\0'; // 编码结束符
	for (int i = 1; i <= n; ++i) // 逐个字符求哈夫曼编码
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) // 从叶子结点开始向上回溯，直到根结点
		{
			--start; // 回溯一次 start 向前指一个位置
			if (HT[f].lch == c)
				cd[start] = '0'; // 结点 c 是 f 的左孩子，则生成代码 0
			else
				cd[start] = '1'; // 结点 c 是 f 的右孩子，则生成代码 1
			c = f;
			f = HT[f].parent; // 继续向上回溯
		} // 求出第 i 个字符的编码
		HC[i] = new char[n - start]; // 为第 i 个字符串编码分配空间
		strcpy(HC[i], &cd[start]); // 将求得的编码从临时空间 cd 复制到 HC 的当前行中
	}
	delete cd; //释放临时空间
} // CreatHuffmanCode
