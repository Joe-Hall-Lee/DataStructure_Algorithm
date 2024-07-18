// 二叉排序树的存储结构
typedef int KeyType;
typedef int InfoType;
typedef int ElemType;
typedef struct
{
	KeyType key; // 关键字项
	InfoType otherinfo; // 其它数据域
}ElemType;

typedef struct BSTNode
{
	ElemType data; // 数据域
	struct BSTNode* lchild, * rchild; // 左右孩子指针
}BSTNode, * BSTree;

BSTree T; // 定义二叉排序树 T

// 二叉排序树的递归查找
BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key); // 在左子树中继续查找
	else
		return SearchBST(T->rchild, key); // 在右子树中继续查找
} // SearchBST
