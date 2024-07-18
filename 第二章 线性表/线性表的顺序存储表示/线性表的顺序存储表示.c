#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
typedef int ElemType;
typedef struct
{
    ElemType elem[LIST_INIT_SIZE];
    int length; // 当前长度
}SqList;
