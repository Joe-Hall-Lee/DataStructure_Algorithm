#define MAXSIZE 20 // ���¼������ 20 ��
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

void bubble_sort2(SqList& L, int n) // �Ľ���ð�������㷨
{
	int m, i, j, flag = 1; // flag ��Ϊ�Ƿ��н����ı��
	RedType x; // ����ʱ��ʱ�洢
	for (m = 1; m <= n - 1; m++) // �ܹ��� m ��
	{
		flag = 0;
		for (j = 1; j <= n - m; j++)
		{
			if (L.r[j].key > L.r[j + 1].key) // ��������
			{
				flag = 1; // ����������flag ��Ϊ 1��������û����������flag ����Ϊ 0
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x; // ����
			} // endif
		} // forif
	}
}