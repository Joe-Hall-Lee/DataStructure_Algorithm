typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode* next;
} LNode, * LinkList;

LinkList Connect(LinkList Ta, LinkList Tb) // 假设 Ta、Tb 都是非空的单循环链表
{
	LinkList p = Ta->next;	   // ① p 存表头结点
	Ta->next = Tb->next->next; // ② Tb 表头连结 Ta 表尾
	delete Tb->next; // ③ 释放 Tb 表头结点，或 free(Tb->next)
	Tb->next = p; // ④ 修改指针
	return Tb;
}