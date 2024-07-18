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

void Insertsort(SqList& L)
{
	int i, j;
	for (i = 2; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - 1].key)  // ����<�����轫 L.r[i] ���������ӱ�
		{
			L.r[0] = L.r[i];  // ����Ϊ�ڱ�
			for (j = i - 1; L.r[0].key < L.r[j].key; --j)
				L.r[j + 1] = L.r[j];  // ��¼����
			L.r[j + 1] = L.r[0];  // ���뵽��ȷλ��
		}
	}
}