#include <iostream>
using namespace std;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;	// �����������ָ������

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) //��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ���� HC ��
{
	HC = new char* [n + 1]; // ���� n ���ַ������ͷָ��ʸ��
	char* cd = new char[n]; // ������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\0'; // ���������
	for (int i = 1; i <= n; ++i) // ����ַ������������
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) // ��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
		{
			--start; // ����һ�� start ��ǰָһ��λ��
			if (HT[f].lch == c)
				cd[start] = '0'; // ��� c �� f �����ӣ������ɴ��� 0
			else
				cd[start] = '1'; // ��� c �� f ���Һ��ӣ������ɴ��� 1
			c = f;
			f = HT[f].parent; // �������ϻ���
		} // ����� i ���ַ��ı���
		HC[i] = new char[n - start]; // Ϊ�� i ���ַ����������ռ�
		strcpy(HC[i], &cd[start]); // ����õı������ʱ�ռ� cd ���Ƶ� HC �ĵ�ǰ����
	}
	delete cd; //�ͷ���ʱ�ռ�
} // CreatHuffmanCode
