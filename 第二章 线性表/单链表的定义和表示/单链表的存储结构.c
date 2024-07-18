typedef int ElemType;
typedef struct Lnode // 声明结点的类型和指向结点的指针类型
{
	ElemType data; // 结点的数据域
	struct Lnode* next; // 结点的指针域
}Lnode, * LinkList; // LinkList 为指向结构体 Lnode 的指针类型