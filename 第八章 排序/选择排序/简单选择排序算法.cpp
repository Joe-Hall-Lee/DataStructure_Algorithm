#define MAXSIZE 20 // ���¼������ 20��
typedef int KeyType; // ��ؼ���Ϊ��������int �ͣ�
typedef int InfoType;

typedef struct // ����ÿ����¼������Ԫ�أ��Ľṹ
{
	KeyType key; // �ؼ���
	InfoType otherinfo; // ����������
}RedType; // Record Type

typedef struct // ����˳���Ľṹ
{
	RedType r[MAXSIZE + 1]; // �洢˳����������r[0] һ�����ڱ��򻺳���
	int length; // ˳���Ľṹ
}SqList;

void SelectSort(SqList& L)
{
	int k;
	RedType x; // ����ʱ��ʱ�洢
	for (int i = 1; i < L.length; ++i)
	{
		k = i;
		for (int j = i + 1; j <= L.length; j++)
		{
			if (L.r[j].key < L.r[k].key)
				k = j; // ��¼��Сֵλ��
			if (k != i)
			{
				x.key = L.r[k].key;
				L.r[k].key = L.r[i].key;
				L.r[i].key = x.key; // ����
			}
		}
	}
}