typedef int KeyType;
typedef int ElemType;
typedef struct
{
	KeyType key;
}ElemType;

typedef struct // ˳���ṹ���Ͷ���
{
	ElemType* R;  // ���ַ
	int length; // ��
}SSTable;  // Sequential Search Table

// int Search_Seq(SSTable ST, KeyType key) // ���ɹ�������λ����Ϣ�����򷵻� 0
// {
// 	for (int i = ST.length; i >= 1; --i)
// 	{
// 		if (ST.R[i].key == key)
// 			return i;
// 	}
// 	return 0;
// }

// // ������ʽ
// int Search_Seq(SSTable ST, KeyType key)
// {
// 	int i;
// 	for (i = ST.length; ST.R[i].key != key; --i)
// 	{
// 		if (i <= 0)
// 			break;
// 	}
// 	if (i > 0)
// 		return i;
// 	else
// 		return 0;

// }

// int Search_Seq(SSTable ST, KeyType key)
// {
// 	int i;
// 	for (i = ST.length; ST.R[i].key && i > 0; --i);
// 	if (i > 0)
// 		return i;
// 	else
// 		return 0;
// }

// ���ü����ڵ�˳�����
int Search_Seq(SSTable ST, KeyType key)
{
	int i = 0;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; --i)
		return i;
}
