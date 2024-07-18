#include <iostream>
using namespace std;
#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������

typedef int KeyType; // ��ؼ���Ϊ��������int �ͣ�
typedef int InfoType;
typedef struct // ����ÿ����¼������Ԫ�أ��Ľṹ
{
	KeyType key; // �ؼ���
	InfoType otherinfo; // ����������
}RedType; // Record Type

typedef struct
{
	RedType r[LIST_INIT_SIZE];
	int length; // ��ǰ����
}SqList;

int Partition(SqList& L, int low, int high)
{
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int high) // ��˳����������
{
	if (low < high) // ���ȴ��� 1
	{
		int pivotloc = Partition(L, low, high); // �� L.[low...high] һ��Ϊ����pivotloc Ϊ����Ԫ���ź����λ��
		QSort(L, low, pivotloc - 1); // �Ե��ӱ�ݹ�����
		QSort(L, pivotloc + 1, high); // �Ը��ӱ�ݹ�����
	} // endif
} // QSort

void main()
{
	SqList L;
	for (int i = 1; i < 11; i++)
	{
		L.r[i].key = 10 - i;
	}
	L.length = 10;
	QSort(L, 1, L.length);
}