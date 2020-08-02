#ifndef _MEMORYBLOCK_H_
#define _MEMORYBLOCK_H_
#include "MemoryAlloc.h"
class MemoryBlock
{
public:
	MemoryBlock();
	~MemoryBlock();

private:
	int nID; // 编号
	size_t nRef; // 引用次数
	MemoryAlloc* pAlloc; // 所属内存池
	MemoryBlock* pNext; // 下一个可用内存块
	bool inPool; // 是否在内存池中
//	char reserve[7]; // 字节对齐，预留位置
};



#endif // !_MEMORYBLOCK_H_

