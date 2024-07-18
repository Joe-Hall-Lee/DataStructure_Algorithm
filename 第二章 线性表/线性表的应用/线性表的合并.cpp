#define OK 1
#define ERROR 0
#define MAXSIZE 50
typedef int Status;
typedef char ElemType;
typedef struct
{
	ElemType* elem;
	int length;
}List; // ����˳�������

int ListLength(List L)
{
	return (L.length);
}

int GetElem(List L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1]; // �� i - 1 �ĵ�Ԫ�洢�ŵ� i ������
	return OK;
}

int LocateElem(List L, ElemType e)
{
	// �����Ա� L �в���ֵΪ e ������Ԫ�أ���������ţ��ǵڼ���Ԫ�أ�
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1; // ���ҳɹ����������
		return 0; // ����ʧ�ܣ����� 0
	}
}

Status ListInsert(List& L, int i, ElemType e)
{
	if (i < 1 || i>L.length + 1)
		return ERROR; // i ֵ���Ϸ�
	if (L.length == MAXSIZE)
		return ERROR; // ��ǰ�洢�ռ�����
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; // ����λ�ü��Ժ��Ԫ�غ���
	L.elem[i - 1] = e; // ����Ԫ�� e ����� i ��λ��
	L.length++; // ���� 1
	return OK;
}

void union_list(List& La, List& Lb)
{
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);

	for (int i = 1; i <= Lb_len; i++)
	{
		ElemType e = GetElem(Lb, i, e);
		if (!LocateElem(La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}

}
