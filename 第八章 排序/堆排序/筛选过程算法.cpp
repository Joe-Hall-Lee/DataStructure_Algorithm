typedef int elem;
void HeapAdjust(elem R[], int s, int m)
{
	/* 已知 R[s...m] 中记录的关键字除 R[s] 之外均满足堆的定义，本函数调整 R[s] 的关键字，使 R[s...m] 成为一个大根堆 */
	int rc = R[s];
	for (int j = 2 * s; j <= m; j *= 2) // 沿 key 较大的孩子结点向下筛选
	{
		if (j < m && R[j] < R[j + 1])
			++j; // j 为 key 较大的记录的下标
		if (rc >= R[j])
			break;
		R[s] = R[j];
		s = j; // rc 应插入在位置 s 上
	}  // for
	R[s] = rc; // 插入
}  // HeapAdjust
