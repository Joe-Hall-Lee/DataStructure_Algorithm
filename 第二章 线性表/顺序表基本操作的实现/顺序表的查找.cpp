typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

int LocateElem(SqList L, ElemType e)
{
	// �����Ա� L �в���ֵΪ e ������Ԫ�أ���������ţ��ǵڼ���Ԫ�أ�
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1; // ���ҳɹ����������
		return 0; // ����ʧ�ܣ����� 0
	}
}