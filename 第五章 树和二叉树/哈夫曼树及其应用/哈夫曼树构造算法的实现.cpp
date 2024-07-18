#include <iostream>
using namespace std;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

void Select(HuffmanTree HT, int m, int& s1, int& s2) // ���� m �������ѡ����С�� 2 ��
{
	int i; //���±�Ϊ 1 ��λ�ÿ�ʼ���� 
	int min1 = 1000;
	int min2 = 1000; // �涨һ���ر����� 

	for (i = 1; i <= m; i++) {
		if (HT[i].parent == 0 && min1 > HT[i].weight)
		{
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (i != s1 && HT[i].parent == 0 && HT[i].weight < min2) // ע����� i != s1 ��� min 
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
	int m = 2 * n - 1; // ���鹲 2n - 1 ��Ԫ��
	HT = new HTNode[m + 1]; // 0 �ŵ�Ԫδ�ã�HT[m] ��ʾ�����
	for (int i = 1; i <= m; ++i) // �� 2n - 1 ��Ԫ�ص� lch��rch��parent ��Ϊ 0
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> HT[i].weight; //����ǰ n ��Ԫ�ص� weight ֵ
	}
	int s1, s2;
	// ��ʼ�����������濪ʼ������������
	for (int i = n + 1; i <= m; i++) // �ϲ����� n - 1 ����㡪������ Huffman ��
	{
		Select(HT, i - 1, s1, s2); // �� HT[k] (i <= k <= i - 1) ��ѡ��������˫����Ϊ 0����Ȩֵ��С�Ľ�㣬������������ HT �е���� s1 �� s2
		HT[s1].parent = i;
		HT[s2].parent = i; // ��ʾ�� F ��ɾ�� s1��s2
		HT[i].lch = s1;
		HT[i].rch = s2; // s1��s2 �ֱ���Ϊ i �����Һ���
		HT[i].weight = HT[s1].weight + HT[s2].weight; // i ��ȨֵΪΪ���Һ���Ȩֵ֮��
	}
}
