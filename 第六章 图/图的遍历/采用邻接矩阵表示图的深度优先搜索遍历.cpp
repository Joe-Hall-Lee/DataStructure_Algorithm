#include <iostream>
using namespace std;
#define OK 1
#define OVERFLOW -2
#define MaxInt 1000000
#define MVNum 100 // 最大顶点数
typedef char VerTexType; // 设顶点的数据类型位字符型
typedef int ArcType; // 假设边的权值类型为整型
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum];	// 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum; // 图的当前点数和边数
} AMGraph; // Adjacency Matrix Graph

int LocateVex(AMGraph G, VerTexType u)
{
	// 图 G 中查找顶点 u，存在则返回顶点表中的下标；否则返回 -1
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
	// 采用邻接矩阵表示法，创建无向网 G
	cin >> G.vexnum >> G.arcnum; // 输入总顶点数，总边数
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i]; // 依次输入点的信息
	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt; // 边的权值均置为极大值
	}

	for (int k = 0; k < G.arcnum; ++k) // 构造邻接矩阵
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w; // 输入一条边所依附的顶点及边的权值
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2); // 确定 v1 和 v2 在 G 中的位置
		G.arcs[i][j] = w; // 边 <v1, v2> 的权值置为 w
		G.arcs[j][i] = G.arcs[i][j]; // 置 <v1, v2> 的对称边 <v2, v1> 的权值为 w
	} // for
	return OK;
} // CreateUDN

void DFS(AMGraph G, int v) // 图 G 为邻接矩阵类型
{
	cout << v;
	bool* visited = new bool[G.vexnum];
	if (!visited)
		exit(OVERFLOW);
	visited[v] = true; // 访问第 v 个结点
	for (int w = 0; w < G.vexnum; w++) // 依次检查邻接矩阵 v 所在的行
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
			DFS(G, w);
		// w 是 v 的邻接点，如果 w 未访问，则递归调用 DFS
	}
}