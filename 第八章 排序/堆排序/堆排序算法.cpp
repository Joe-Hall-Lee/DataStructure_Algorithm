typedef int elem;
void Swap(elem& m, elem& n)
{
	elem temp;
	temp = m;
	m = n;
	n = temp;
}

void HeapAdjust(elem R[], int s, int m)
{
	/* ��֪ R[s...m] �м�¼�Ĺؼ��ֳ� R[s] ֮�������ѵĶ��壬���������� R[s] �Ĺؼ��֣�ʹ R[s...m] ��Ϊһ������� */
	int rc = R[s];
	for (int j = 2 * s; j <= m; j *= 2) // �� key �ϴ�ĺ��ӽ������ɸѡ
	{
		if (j < m && R[j] < R[j + 1])
			++j; // j Ϊ key �ϴ�ļ�¼���±�
		if (rc >= R[j])
			break;
		R[s] = R[j];
		s = j; // rc Ӧ������λ�� s ��
	} // for
	R[s] = rc; // ����
}  // HeapAdjust

void HeapSort(elem R[], int n) // �� R[1] �� R[n] ���ж�����
{
	int i;
	for (i = n / 2; i >= 1; i--)
		HeapAdjust(R, i, n); // ����ʼ��
	for (i = n; i > 1; i--) // ���� n - 1 ������
	{
		Swap(R[1], R[i]); // �������һ��Ԫ�ؽ���
		HeapAdjust(R, 1, i - 1); // �� R[1] �� R[i - 1] ���½���
	}
}  // HeapSort
