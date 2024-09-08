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
	} // for
	R[s] = rc; // 插入
}  // HeapAdjust

void HeapSort(elem R[], int n) // 对 R[1] 到 R[n] 进行堆排序
{
	int i;
	for (i = n / 2; i >= 1; i--)
		HeapAdjust(R, i, n); // 建初始堆
	for (i = n; i > 1; i--) // 进行 n - 1 趟排序
	{
		Swap(R[1], R[i]); // 根与最后一个元素交换
		HeapAdjust(R, 1, i - 1); // 对 R[1] 到 R[i - 1] 重新建堆
	}
}  // HeapSort
