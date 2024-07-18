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

void ShellInsert(SqList& L, int dk)  // ��˳���L����һ������Ϊ dk �� Shell ����dk Ϊ��������
{
	int i, j;
	for (i = dk + 1; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - dk].key)
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j = j - dk)
				L.r[j - dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
	}
}

void ShellSort(SqList& L, int dlta[], int t)
{
	// ���������� dlta[0...t-1] ��˳��� L ��ϣ������
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);  // һ������Ϊ dlta[k] �Ĳ�������
}  // ShellSort