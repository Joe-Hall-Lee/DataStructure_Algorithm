#include "GetElemP_DuL.h"

int ListInsert_Dul(DuLinkList& L, int i, ElemType e) //�ڴ�ͷ����˫��ѭ������ L �е� i ��λ��֮ǰ����Ԫ�� e
{
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	DuLinkList s = new DuLNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
} // ListInsert_DuL
