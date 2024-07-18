#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int length; // 当前长度
}SqList;

void MergeList_Sq(SqList LA, SqList LB, SqList& LC)
{
	ElemType* pa = LA.elem;
	ElemType* pb = LB.elem; //指针pa和pb的初值分别指向两个表的第一个元素
	LC.length = LA.length + LB.length; //新表长度为待合并两表的长度之和

	LC.elem = new ElemType[LC.length]; //为合并后的新表分配一个数组空间
	ElemType* pc = LC.elem; //指针pc指向新表的第一个元素
	ElemType* pa_last = LA.elem + LA.length - 1; // 指针 pa_last指向 LA 表的最后一个元素
	ElemType* pb_last = LB.elem + LB.length - 1; //指针 pb_last 指向 LB 表的最后一个元素

	while (pa <= pa_last && pb <= pb_last) // 两个表都非空
	{
		if (*pa <= *pb)
			*pc++ = *pa++; // 以此“摘取”两表中值较小的结点
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++; // LB 表已到达表尾，将 LA 中剩余元素加入 LC
	while (pb <= pb_last)
		*pc++ = *pb++; // LA 表已到达表尾，将 LB 中剩余元素加入 LC
} // MergeList_Sq
