typedef int elem;
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
	}  // for
	R[s] = rc; // ����
}  // HeapAdjust
