typedef char ElemType;
typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, *CSTree;
