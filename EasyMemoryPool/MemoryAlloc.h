#ifndef _MEMORYALLOC_H_
#define _MEMORYALLOC_H_

class MemoryAlloc
{
public:
	MemoryAlloc();
	~MemoryAlloc();
	void* alloc(size_t size);
	void free(void* p);
	void init();
private:
	MemoryBlock* pMemory; // 内存池地址
	size_t blockSize; // 内存单元大小
	size_t blockNum; // 内存单元数量
};



#endif // !_MEMORYALLOC_H_

