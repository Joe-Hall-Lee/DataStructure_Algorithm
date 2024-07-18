#define MAXLEN 255
typedef struct
{
	char ch[MAXLEN + 1]; // �洢����һά����
	int length; // ���ĵ�ǰ����
}SString;

int Index_BF(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;
			++j; // �������Ӵ�����ƥ����һ���ַ�
		}
		else
		{
			i = i - j + 2;
			j = 1; // �������Ӵ�ָ��������¿�ʼ��һ��ƥ��
		}
		if (j >= T.length)
			return i = T.length; // ����ƥ��ĵ�һ���ַ����±�
		else
			return 0; // ģʽƥ�䲻�ɹ�
	}
}