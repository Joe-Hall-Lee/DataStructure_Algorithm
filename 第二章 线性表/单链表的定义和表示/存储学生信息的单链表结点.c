// typedef struct student
// {
// 	char num[8]; // ������
// 	char name[8]; // ������
// 	int score; // ������
// 	struct student* next; // ָ����
// }Lnode, * LinkList;

//Ϊ��ͳһ����Ĳ�����ͨ���������壺
typedef struct
{
	char num[8]; // ������
	char name[8]; // ������
	int score; // ������
}ElemType;

typedef struct Lnode
{
	ElemType data; // ������
	struct Lnode* next; // ָ����
}Lnode, * LinkList;


LinkList L;