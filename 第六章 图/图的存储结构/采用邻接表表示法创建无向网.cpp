#include <iostream>
using namespace std;
#define MVNum 100 // 最大顶点数
#define OK 1
typedef int Status;
typedef int OtherInfo;
typedef char VerTexType;

typedef struct ArcNode // 边结点
{
	int adjvex; // 该边所指向的顶点的位置
	struct ArcNode* nextarc; // 指向下一条边的指针
	OtherInfo info; // 和边相关的信息
}ArcNode;

typedef struct VNode
{
	VerTexType data; // 顶点信息
	ArcNode* firstarc; // 指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum]; // AdjList 表示邻接表类型

typedef struct
{
	AdjList vertices; // vertices——vertex 的复数
	int vexnum, arcnum; // 图的当前顶点数和弧数
}ALGraph;

int LocateVex(ALGraph G, VerTexType u)
{
	// 图 G 中查找顶点 u，存在则返回顶点表中的下标；否则返回 -1
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	return -1;
}

Status CreateUDG(ALGraph& G) // 采用邻接表表示法，创建无向图
{
	cin >> G.vexnum >> G.arcnum; // 输入总顶点数、总边数
	for (int i = 0; i < G.vexnum; i++) // 输入各点，构造表头结点表
	{
		cin >> G.vertices[i].data; // 输入顶点值
		G.vertices[i].firstarc = NULL; // 初始化表头结点的指针域
	} // for
	for (int k = 0; k < G.arcnum; ++k) // 输入各边，构造邻接表
	{
		int v1, v2;
		cin >> v1 >> v2; // 输入一条边依附的两个顶点
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode; // 生成一个新的边结点 *p1
		p1->adjvex = j; // 邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1; // 将新结点 *p1 插入顶点 vi 的边表头部
		ArcNode* p2 = new ArcNode; // 生成另一个对称的新的边结点 *p2
		p2->adjvex = i; // 邻接点序号为i
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices->firstarc = p2; // 将新结点 *p2 插入顶点 vj 的边表头部
	} // for
	return OK;
} // CreateUDG
