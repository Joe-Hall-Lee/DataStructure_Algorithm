#define MAX_TREE_SIZE 100
typedef struct CTNode
{
	int child;
	struct CTNode* next;
} *ChildPtr;

typedef char TElemType;
typedef struct
{
	TElemType data;
	ChildPtr firstchild; // 孩子链表头指针
} CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r; // 结点数和根节点的位置
} CTree;
