// �����������Ĵ洢�ṹ
typedef int KeyType;
typedef int InfoType;
typedef int ElemType;
typedef struct
{
	KeyType key; // �ؼ�����
	InfoType otherinfo; // ����������
}ElemType;

typedef struct BSTNode
{
	ElemType data; // ������
	struct BSTNode* lchild, * rchild; // ���Һ���ָ��
}BSTNode, * BSTree;

BSTree T; // ������������� T

// �����������ĵݹ����
BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key); // ���������м�������
	else
		return SearchBST(T->rchild, key); // ���������м�������
} // SearchBST
