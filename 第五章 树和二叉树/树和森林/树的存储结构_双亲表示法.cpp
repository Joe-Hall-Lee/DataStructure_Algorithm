#define MAX_TREE_SIZE 100
typedef char TElemType;
typedef struct PTNode
{
	TElemType data;
	int parent; // 双亲位置域
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; // 根结点的位置和结点个数
}PTree;
