#define CHUNKSIZE 80 // ��Ĵ�С�����û�����
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail; // ����ͷָ���βָ��
	int curlen; // ���ĵ�ǰ����
}LString; // �ַ����Ŀ����ṹ
