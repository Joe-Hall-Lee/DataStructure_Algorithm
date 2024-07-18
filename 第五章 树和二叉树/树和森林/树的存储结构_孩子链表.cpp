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
	ChildPtr firstchild; // ��������ͷָ��
} CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r; // ������͸��ڵ��λ��
} CTree;
