#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXQSIZE 100 // �����г���
#define MaxInt 1000000
#define MVNum 100 // ��󶥵���
typedef char VerTexType; // �趥�����������λ�ַ���
typedef int ArcType; // ����ߵ�Ȩֵ����Ϊ����
typedef int Status;
typedef int QElemType;
typedef int OtherInfo;
typedef struct
{
	QElemType* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ��
	int rear;  // βָ��
} SqQueue;

Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return OK; // �ӿ�
	else
		return ERROR;
}

Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE]; // ��������ռ�
	if (!Q.base)
		exit(OVERFLOW); // �洢����ʧ��
	Q.front = Q.rear = 0; // ͷָ�롢βָ����Ϊ 0������Ϊ��
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; // ����
	Q.base[Q.rear] = e; // ��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; // ��βָ�� + 1
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR; // �ӿ�
	e = Q.base[Q.front]; // �����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; // ��ͷָ�� + 1
	return OK;
}

typedef struct ArcNode // �߽��
{
	int adjvex;  // �ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc; // ָ����һ���ߵ�ָ��
	OtherInfo info; // �ͱ���ص���Ϣ
} ArcNode;

typedef struct VNode
{
	VerTexType data; // ������Ϣ
	ArcNode* firstarc; // ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum]; // AdjList ��ʾ�ڽӱ�����

typedef struct
{
	AdjList vertices; // vertices����vertex �ĸ���
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
} Graph;

int LocateVex(Graph G, VerTexType u)
{
	// ͼ G �в��Ҷ��� u�������򷵻ض�����е��±ꣻ���򷵻� -1
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	return -1;
}

Status CreateUDG(Graph& G) // �����ڽӱ��ʾ������������ͼ
{
	cin >> G.vexnum >> G.arcnum; // �����ܶ��������ܱ���
	for (int i = 0; i < G.vexnum; i++) // ������㣬�����ͷ����
	{
		cin >> G.vertices[i].data; // ���붥��ֵ
		G.vertices[i].firstarc = NULL; // ��ʼ����ͷ����ָ����
	} // for
	for (int k = 0; k < G.arcnum; ++k) // ������ߣ������ڽӱ�
	{
		int v1, v2;
		cin >> v1 >> v2; // ����һ������������������
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode; // ����һ���µı߽�� *p1
		p1->adjvex = j;			   // �ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1; // ���½�� *p1 ���붥�� vi �ı߱�ͷ��
		ArcNode* p2 = new ArcNode;	 // ������һ���ԳƵ��µı߽�� *p2
		p2->adjvex = i; // �ڽӵ����Ϊi
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices->firstarc = p2; // ���½�� *p2 ���붥�� vj �ı߱�ͷ��
	} // for

	return OK;
} // CreateUDG

int FirstAdjVex(Graph G, int v)
{
	int i;
	if (!G.vertices[v].firstarc) // �ж��Ƿ����ٽ��
		return 0;
	return G.vertices[v].firstarc->adjvex; // ����з��ظõ��λ��
}

int NextAdjVex(Graph G, int u, int w) // ��ʾ u ����� w ����һ���ٽ�㣬w >= 0 ��ʾ�����ٽ��
{
	ArcNode* p;
	p = G.vertices[u].firstarc;
	while (p && p->adjvex != w)
		p = p->nextarc; // �ҵ�w���λ��
	p = p->nextarc;	// w λ�õ���һ��λ��

	if (p) // �����λ�ò�Ϊ NULL ˵���� u λ�û���������
		return p->adjvex;

	return -1; // ��λ��Ϊ NULL��˵���� u λ���й�ϵ�ĵ��Ѿ�������
}

void BFS(Graph G, int v) // ��������ȷǵݹ������ͨͼG
{
	cout << v;
	bool* visited = new bool[G.vexnum];
	if (!visited)
		exit(OVERFLOW);
	visited[v] = true; // ���ʵ� v �����
	SqQueue Q;
	int u;
	InitQueue(Q); // �������� Q ��ʼ�����ÿ�
	EnQueue(Q, v); // v ����
	while (!QueueEmpty(Q)) // ���зǿ�
	{
		DeQueue(Q, u); // ��ͷԪ�س��Ӳ���Ϊu
		for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if (!visited[w]) // w Ϊ u ����δ���ʵ��ڽӶ���
			{
				cout << w;
				visited[w] = true;
				EnQueue(Q, w); // ����
			} // if
		}
	} // while
} // BFS