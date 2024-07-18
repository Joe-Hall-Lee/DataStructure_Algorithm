#include <iostream>
using namespace std;
typedef struct PNode
{
	float coef; // ϵ��
	int expn; // ָ��
	struct PNode* next; // ָ����
}PNode, * Polynomial;

void CreatePolyn(Polynomial& P, int n) // ���� n ���ϵ����ָ����������ʾ����ʽ���������� P
{
	P = new PNode;
	P->next = NULL; // �Ƚ���һ����ͷ���ĵ�����
	for (int i = 1; i <= n; ++i)
	{
		Polynomial s = new PNode; // �����½��
		cin >> s->coef >> s->expn; // ����ϵ����ָ��
		Polynomial pre = P; // pre ���ڱ��� q ��ǰ������ֵΪͷ���
		Polynomial q = P->next; // q ��ʼ����ָ����Ԫ���
		while (q && q->expn < s->expn) // �ҵ���һ������������ָ������ *q
		{
			pre = q;
			q = q->next;
		}
		s->next = q; // �������� s ���뵽 q ����ǰ����� pre ֮��
		pre->next = s;
	}
}