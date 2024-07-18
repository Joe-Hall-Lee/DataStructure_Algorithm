#include <iostream>
using namespace std;
#define MVNum 100 // ��󶥵���
#define OK 1
typedef int Status;
typedef int OtherInfo;
typedef char VerTexType;

typedef struct ArcNode // �߽��
{
	int adjvex; // �ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc; // ָ����һ���ߵ�ָ��
	OtherInfo info; // �ͱ���ص���Ϣ
}ArcNode;

typedef struct VNode
{
	VerTexType data; // ������Ϣ
	ArcNode* firstarc; // ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum]; // AdjList ��ʾ�ڽӱ�����

typedef struct
{
	AdjList vertices; // vertices����vertex �ĸ���
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
}ALGraph;

int LocateVex(ALGraph G, VerTexType u)
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

Status CreateUDG(ALGraph& G) // �����ڽӱ��ʾ������������ͼ
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
		p1->adjvex = j; // �ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1; // ���½�� *p1 ���붥�� vi �ı߱�ͷ��
		ArcNode* p2 = new ArcNode; // ������һ���ԳƵ��µı߽�� *p2
		p2->adjvex = i; // �ڽӵ����Ϊi
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices->firstarc = p2; // ���½�� *p2 ���붥�� vj �ı߱�ͷ��
	} // for
	return OK;
} // CreateUDG
