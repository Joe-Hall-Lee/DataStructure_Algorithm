struct Book
{
	char id[20]; // ISBN
	char name[50]; //书名
	int price; // 定价
};

typedef struct // 顺序表 
{
	Book* elem;
	int length;
}SqList;

typedef struct LNode // 链表
{
	Book data;
	struct LNode* next;
}LNode, * LinkList;