#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int length; // ��ǰ����
}SqList;

void MergeList_Sq(SqList LA, SqList LB, SqList& LC)
{
	ElemType* pa = LA.elem;
	ElemType* pb = LB.elem; //ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ��
	LC.length = LA.length + LB.length; //�±���Ϊ���ϲ�����ĳ���֮��

	LC.elem = new ElemType[LC.length]; //Ϊ�ϲ�����±����һ������ռ�
	ElemType* pc = LC.elem; //ָ��pcָ���±�ĵ�һ��Ԫ��
	ElemType* pa_last = LA.elem + LA.length - 1; // ָ�� pa_lastָ�� LA ������һ��Ԫ��
	ElemType* pb_last = LB.elem + LB.length - 1; //ָ�� pb_last ָ�� LB ������һ��Ԫ��

	while (pa <= pa_last && pb <= pb_last) // �������ǿ�
	{
		if (*pa <= *pb)
			*pc++ = *pa++; // �Դˡ�ժȡ��������ֵ��С�Ľ��
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++; // LB ���ѵ����β���� LA ��ʣ��Ԫ�ؼ��� LC
	while (pb <= pb_last)
		*pc++ = *pb++; // LA ���ѵ����β���� LB ��ʣ��Ԫ�ؼ��� LC
} // MergeList_Sq
