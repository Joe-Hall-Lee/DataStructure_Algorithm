#include <iostream>
using namespace std;
#define OK 1
#define OVERFLOW -2
#define MaxInt 1000000
#define MVNum 100 // ��󶥵���
typedef char VerTexType; // �趥�����������λ�ַ���
typedef int ArcType; // ����ߵ�Ȩֵ����Ϊ����
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum];	// �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum; // ͼ�ĵ�ǰ�����ͱ���
} AMGraph; // Adjacency Matrix Graph

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
		int v1, v2, w;
		cin >> v1 >> v2 >> w; // ����һ�����������Ķ��㼰�ߵ�Ȩֵ
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2); // ȷ�� v1 �� v2 �� G �е�λ��
		G.arcs[i][j] = w; // �� <v1, v2> ��Ȩֵ��Ϊ w
		G.arcs[j][i] = G.arcs[i][j]; // �� <v1, v2> �ĶԳƱ� <v2, v1> ��ȨֵΪ w
	} // for
	return OK;
} // CreateUDN

void DFS(AMGraph G, int v) // ͼ G Ϊ�ڽӾ�������
{
	cout << v;
	bool* visited = new bool[G.vexnum];
	if (!visited)
		exit(OVERFLOW);
	visited[v] = true; // ���ʵ� v �����
	for (int w = 0; w < G.vexnum; w++) // ���μ���ڽӾ��� v ���ڵ���
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DFS(G, w);
		// w �� v ���ڽӵ㣬��� w δ���ʣ���ݹ���� DFS
	}
}