struct Book
{
	char id[20]; // ISBN
	char name[50]; //����
	int price; // ����
};

typedef struct // ˳��� 
{
	Book* elem;
	int length;
}SqList;

typedef struct LNode // ����
{
	Book data;
	struct LNode* next;
}LNode, * LinkList;