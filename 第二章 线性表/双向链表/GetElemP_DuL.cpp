#include "GetElemP_DuL.h"

DuLinkList GetElemP_DuL(DuLinkList L, int i)
{
	DuLinkList p = L->next;
	int j = 1; // ��ʼ��
	while (p && j < 1) // ���ɨ�裬ֱ�� p ָ��� i ��Ԫ�ػ� p Ϊ��
	{
		p = p->next;
		++j;
	}
	if (!p || j > 1)
		return ERROR; // �� i ��Ԫ�ز�����

	return p;
}
