#include <stdio.h>
#define OK 1

typedef int TElemType;
typedef int Status;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // ���Һ���ָ��
}BiNode, * BiTree;

void visit(BiTree T)
{
	printf("%d", T->data);
}

Status InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK; // �ն�����
	else
	{
		InOrderTraverse(T->lchild); // �ݹ����������
		visit(T); // ���ʸ����
		InOrderTraverse(T->rchild); // �ݹ����������
	}
}
