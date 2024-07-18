// typedef struct student
// {
// 	char num[8]; // 数据域
// 	char name[8]; // 数据域
// 	int score; // 数据域
// 	struct student* next; // 指针域
// }Lnode, * LinkList;

//为了统一链表的操作，通常这样定义：
typedef struct
{
	char num[8]; // 数据域
	char name[8]; // 数据域
	int score; // 数据域
}ElemType;

typedef struct Lnode
{
	ElemType data; // 数据域
	struct Lnode* next; // 指针域
}Lnode, * LinkList;


LinkList L;