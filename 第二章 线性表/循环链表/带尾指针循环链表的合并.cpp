typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode* next;
} LNode, * LinkList;

LinkList Connect(LinkList Ta, LinkList Tb) // ���� Ta��Tb ���Ƿǿյĵ�ѭ������
{
	LinkList p = Ta->next;	   // �� p ���ͷ���
	Ta->next = Tb->next->next; // �� Tb ��ͷ���� Ta ��β
	delete Tb->next; // �� �ͷ� Tb ��ͷ��㣬�� free(Tb->next)
	Tb->next = p; // �� �޸�ָ��
	return Tb;
}