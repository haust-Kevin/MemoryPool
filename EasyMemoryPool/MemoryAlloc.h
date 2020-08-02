#ifndef _MEMORYALLOC_H_
#define _MEMORYALLOC_H_
class MemoryBlock;

class MemoryAlloc
{
public:
	MemoryAlloc();
	~MemoryAlloc();
	void* alloc(size_t size);
	void free(void* p);
	void init();
private:
	void* pMemory; // �ڴ�ص�ַ
	MemoryBlock* pHeader; // ���õ��ڴ���ַ
	size_t blockSize; // �ڴ浥Ԫ��С
	size_t blockNum; // �ڴ浥Ԫ����
};



#endif // !_MEMORYALLOC_H_
