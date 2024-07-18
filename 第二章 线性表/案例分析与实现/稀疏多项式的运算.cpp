#include <iostream>
using namespace std;
typedef struct PNode
{
	float coef; // 系数
	int expn; // 指数
	struct PNode* next; // 指针域
}PNode, * Polynomial;

void CreatePolyn(Polynomial& P, int n) // 输入 n 项的系数和指数，建立表示多项式的有序链表 P
{
	P = new PNode;
	P->next = NULL; // 先建立一个带头结点的单链表
	for (int i = 1; i <= n; ++i)
	{
		Polynomial s = new PNode; // 生成新结点
		cin >> s->coef >> s->expn; // 输入系数和指数
		Polynomial pre = P; // pre 用于保存 q 的前驱，初值为头结点
		Polynomial q = P->next; // q 初始化，指向首元结点
		while (q && q->expn < s->expn) // 找到第一个大于输入项指数的项 *q
		{
			pre = q;
			q = q->next;
		}
		s->next = q; // 将输入项 s 插入到 q 和其前驱结点 pre 之间
		pre->next = s;
	}
}