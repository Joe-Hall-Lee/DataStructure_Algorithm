#define CHUNKSIZE 80 // 块的大小可由用户定义
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail; // 串的头指针和尾指针
	int curlen; // 串的当前长度
}LString; // 字符串的块链结构
