typedef int ElemType;
typedef struct Lnode // �����������ͺ�ָ�����ָ������
{
	ElemType data; // ����������
	struct Lnode* next; // ����ָ����
}Lnode, * LinkList; // LinkList Ϊָ��ṹ�� Lnode ��ָ������