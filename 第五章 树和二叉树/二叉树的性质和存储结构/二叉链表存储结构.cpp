typedef int TElemType;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // ���Һ���ָ��
}BiNode, * BiTree;
