#define MAXLEN 255
typedef struct
{
	char ch[MAXLEN + 1]; // 存储串的一维数组
	int length; // 串的当前长度
}SString;

void get_next(SString T, int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

void get_nextval(SString T, int nextval[])
{
	int i = 1;
	nextval[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}
int Index_KMP(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	int next[MAXLEN + 1];
	get_next(T, next);
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
			j = next[j]; /* i 不变，j 后退 */
		if (j > T.length)
			return i - T.length; /* 匹配成功 */
		else
			return 0; /* 返回不匹配标志 */
	}
}
