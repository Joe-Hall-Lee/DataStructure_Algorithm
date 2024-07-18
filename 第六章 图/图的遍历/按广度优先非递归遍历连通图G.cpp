#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXQSIZE 100 // 最大队列长度
#define MaxInt 1000000
#define MVNum 100 // 最大顶点数
typedef char VerTexType; // 设顶点的数据类型位字符型
typedef int ArcType; // 假设边的权值类型为整型
typedef int Status;
typedef int QElemType;
typedef int OtherInfo;
typedef struct
{
	QElemType* base; // 初始化的动态分配存储空间
	int front; // 头指针
	int rear;  // 尾指针
} SqQueue;

Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return OK; // 队空
	else
		return ERROR;
}

Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // 分配数组空间
	if (!Q.base)
		exit(OVERFLOW); // 存储分配失败
	Q.front = Q.rear = 0; // 头指针、尾指针置为 0，队列为空
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // 队满
	Q.base[Q.rear] = e; // 新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; // 队尾指针 + 1
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // 队空
	e = Q.base[Q.front]; // 保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针 + 1
	return OK;
}

typedef struct ArcNode // 边结点
{
	int adjvex;  // 该边所指向的顶点的位置
	struct ArcNode* nextarc; // 指向下一条边的指针
	OtherInfo info; // 和边相关的信息
} ArcNode;

typedef struct VNode
{
	VerTexType data; // 顶点信息
	ArcNode* firstarc; // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; // AdjList 表示邻接表类型

typedef struct
{
	AdjList vertices; // vertices——vertex 的复数
	int vexnum, arcnum; // 图的当前顶点数和弧数
} Graph;

int LocateVex(Graph G, VerTexType u)
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

Status CreateUDG(Graph& G) // 采用邻接表表示法，创建无向图
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
		p1->adjvex = j;			   // 邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1; // 将新结点 *p1 插入顶点 vi 的边表头部
		ArcNode* p2 = new ArcNode;	 // 生成另一个对称的新的边结点 *p2
		p2->adjvex = i; // 邻接点序号为i
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices->firstarc = p2; // 将新结点 *p2 插入顶点 vj 的边表头部
	} // for

	return OK;
} // CreateUDG

int FirstAdjVex(Graph G, int v)
{
	int i;
	if (!G.vertices[v].firstarc) // 判断是否有临界点
		return 0;
	return G.vertices[v].firstarc->adjvex; // 如果有返回该点的位置
}

int NextAdjVex(Graph G, int u, int w) // 表示 u 相对于 w 的下一个临界点，w >= 0 表示存在临界点
{
	ArcNode* p;
	p = G.vertices[u].firstarc;
	while (p && p->adjvex != w)
		p = p->nextarc; // 找到w点的位置
	p = p->nextarc;	// w 位置的下一个位置

	if (p) // 如果该位置不为 NULL 说明和 u 位置还有相连的
		return p->adjvex;

	return -1; // 该位置为 NULL，说明与 u 位置有关系的点已经遍历完
}

void BFS(Graph G, int v) // 按广度优先非递归遍历连通图G
{
	cout << v;
	bool* visited = new bool[G.vexnum];
	if (!visited)
		exit(OVERFLOW);
	visited[v] = true; // 访问第 v 个结点
	SqQueue Q;
	int u;
	InitQueue(Q); // 辅助队列 Q 初始化，置空
	EnQueue(Q, v); // v 进队
	while (!QueueEmpty(Q)) // 队列非空
	{
		DeQueue(Q, u); // 队头元素出队并置为u
		for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if (!visited[w]) // w 为 u 的尚未访问的邻接顶点
			{
				cout << w;
				visited[w] = true;
				EnQueue(Q, w); // 进队
			} // if
		}
	} // while
} // BFS