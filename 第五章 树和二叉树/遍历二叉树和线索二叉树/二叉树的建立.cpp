#include <iostream>
using namespace std;
#define OK 1
typedef char TElemType;
typedef int Status;
typedef struct BiNode
{
	TElemType data;
	struct BiNode* lchild, * rchild; // ���Һ���ָ��
} BiNode, * BiTree;

Status CreateBiTree(BiTree& T)
{
	char ch;
	cin >> ch; // scanf(&ch);
	if (ch == '#')
		T == NULL;
	else
	{
		if (!(T = new BiNode)) // T = (BiNode*)malloc(sizeof(BiNode));
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild); // ����������
		CreateBiTree(T->rchild); // ����������
	}
	return OK;
} // CreateBiTree
