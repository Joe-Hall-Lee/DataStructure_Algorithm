#define MAXSIZE 20  // ���¼������ 20 ��
typedef int KeyType;  // ��ؼ���Ϊ��������int �ͣ�
typedef int InfoType;

typedef struct  // ����ÿ����¼������Ԫ�أ��Ľṹ
{
	KeyType key;  // �ؼ���
	InfoType otherinfo;
}RedType;  // Record Type

typedef struct  // ����˳���Ľṹ
{
	RedType r[MAXSIZE + 1];  // �洢˳��������
	int length;  // ˳���ĳ���
}SqList;

void BInsertSort(SqList& L)
{
	for (int i = 2; i <= L.length; ++i)  // ���β���� 2~�� n ��Ԫ��
	{
		L.r[0] = L.r[i];  // ��ǰ����Ԫ�ش浽���ڱ���λ��
		int low = 1;
		int high = i - 1;  // ���ö��ֲ��ҷ����Ҳ���λ��
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}  // ѭ��������high + 1 ��Ϊ����λ��
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j];  // �ƶ�Ԫ��
		L.r[high + 1] = L.r[0];  // ���뵽��ȷλ��
	}
}  // BInsertSort