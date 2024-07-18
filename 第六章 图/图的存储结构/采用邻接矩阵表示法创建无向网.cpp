#include <iostream>
using namespace std;
#define OK 1
#define MaxInt 1000000
#define MVNum 100 // ��󶥵���
typedef char VerTexType; // �趥�����������λ�ַ���
typedef int ArcType; // ����ߵ�Ȩֵ����Ϊ����
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum]; // �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum; // ͼ�ĵ�ǰ�����ͱ���
}AMGraph; // Adjacency Matrix Graph

int LocateVex(AMGraph G, VerTexType u)
{
	// ͼ G �в��Ҷ��� u�������򷵻ض�����е��±ꣻ���򷵻� -1
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}

Status CreateUDN(AMGraph& G)
{
	// �����ڽӾ����ʾ�������������� G
	cin >> G.vexnum >> G.arcnum; // �����ܶ��������ܱ���
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i]; // ������������Ϣ

	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt; // �ߵ�Ȩֵ����Ϊ����ֵ
	}

	for (int k = 0; k < G.arcnum; ++k) // �����ڽӾ���
	{
		VerTexType v1, v2;
		int w;
		cin >> v1 >> v2 >> w; // ����һ�����������Ķ��㼰�ߵ�Ȩֵ
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2); // ȷ�� v1 �� v2 �� G �е�λ��
		G.arcs[i][j] = w; // �� <v1, v2> ��Ȩֵ��Ϊ w 
		G.arcs[j][i] = G.arcs[i][j]; // �� <v1, v2> �ĶԳƱ� <v2, v1> ��ȨֵΪ w
	} // for
	return OK;
} // CreateUDN
