#include "MemoryAlloc.h"
#include <cstdlib>
#include <exception>
#include "MemoryBlock.h"

MemoryAlloc::MemoryAlloc()
	:pMemory(nullptr), pHeader(nullptr), blockNum(0), blockSize(0)
{

}

MemoryAlloc::~MemoryAlloc()
{
}

void* MemoryAlloc::alloc(size_t size)
{
	return malloc(size);
}

void MemoryAlloc::free(void* p)
{

}

void MemoryAlloc::init()
{
	if (pMemory != nullptr)
	{
		throw std::exception("内存池已经初始化\n");
	}
	size_t memorySize = blockSize * blockNum; // 计算内存池大小
	pMemory = malloc(memorySize); // 向系统申请内存
 	pHeader = static_cast<MemoryBlock*> (pMemory);
// 	pHeader->inPool = true;
// 	pHeader->nId = 0;
// 	pHeader->refCount = 0;
// 	pHeader->pAlloc = this;
// 	pHeader->pNext = nullptr;
	MemoryBlock* pLast = pHeader;
	for (size_t i = 1; i < blockNum; i++)
	{
		MemoryBlock* pTemp = 
			reinterpret_cast<MemoryBlock*> (static_cast<char*>(pMemory) + (i * blockSize));
		pTemp->inPool = true;
		pTemp->nId = i;
		pTemp->refCount = 0;
		pTemp->pAlloc = this;
		pLast->pNext = pTemp;
		pLast = pTemp;
	}
	pLast->pNext = nullptr;
}