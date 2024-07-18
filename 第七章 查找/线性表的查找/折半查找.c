typedef int ElemType;
typedef int KeyType;
typedef struct
{
	KeyType key;
}ElemType;

typedef struct // ˳���ṹ���Ͷ���
{
	ElemType* R; // ���ַ
	int length; // ��
}SSTable; // Sequential Search Table

int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length; // �������ֵ
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (ST.R[mid].key == key)
			return mid; // �ҵ�����Ԫ��
		else if (key < ST.R[mid].key) // ��С���ҷ�Χ
			high = mid - 1; // ������ǰ��������в���
		else
			low = mid + 1; // �����ں��������в���
	}
	return 0;  // ˳����в����ڴ���Ԫ��
}  // Search_Bin
