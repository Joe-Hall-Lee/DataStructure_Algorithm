#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
typedef int ElemType;
typedef struct
{
    ElemType elem[LIST_INIT_SIZE];
    int length; // ��ǰ����
}SqList;
