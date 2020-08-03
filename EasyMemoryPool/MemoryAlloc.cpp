#include "MemoryAlloc.h"
#include <cstdlib>
#include <exception>
#include "MemoryBlock.h"


MemoryAlloc::MemoryAlloc(size_t _BlockSize, size_t _BlockNum)
	:pMemory(nullptr), pHeader(nullptr), blockNum(0), blockSize(0)
{
	constexpr size_t BYTE_ALIGN_SIZE = sizeof(void*);
    // 实现字节对齐
	blockSize = _BlockSize * (_BlockSize / BYTE_ALIGN_SIZE)
		+ (_BlockSize % BYTE_ALIGN_SIZE ? BYTE_ALIGN_SIZE : 0);
	blockNum = _BlockNum;
}

MemoryAlloc::~MemoryAlloc()
{
	if (pMemory != nullptr)
	{
		::free(pMemory);
	}
}

void* MemoryAlloc::alloc(size_t size)
{
	if (pMemory == nullptr)
	{
		init();
	}
	MemoryBlock* pResult = nullptr;
	if (pHeader == nullptr)
	{
		pResult = static_cast<MemoryBlock*>(
			malloc(size + sizeof(MemoryBlock))
			);
		pResult->inPool = false;
		pResult->refCount = 1;
		pResult->pAlloc = this;
		pResult->pNext = nullptr;
	}
	else
	{
		pResult = pHeader;
		pHeader = pHeader->pNext;
		pResult->refCount = 1;
	}
	return static_cast<void*>(
		reinterpret_cast<char*>(pResult) + sizeof(MemoryBlock)
		);
}

void MemoryAlloc::free(void* p)
{
	MemoryBlock* pFree = reinterpret_cast<MemoryBlock*>(
		static_cast<char*>(p) - sizeof(MemoryBlock)
		);
		pFree->pNext = pHeader;
		pHeader = pFree;
}

void MemoryAlloc::init()
{
	size_t memorySize = (blockSize + sizeof(MemoryBlock)) * blockNum; // 计算内存池大小
	pMemory = malloc(memorySize); // 向系统申请内存
	pHeader = static_cast<MemoryBlock*> (pMemory);

	MemoryBlock* pLast = nullptr;

	for (size_t i = 0; i < blockNum; i++)
	{
		MemoryBlock* pTemp = reinterpret_cast<MemoryBlock*> (
			static_cast<char*>(pMemory) + i * (blockSize + sizeof(MemoryBlock))
			);
		pTemp->inPool = true;
		pTemp->refCount = 0;
		pTemp->pAlloc = this;
		if (pLast)
		{
			pLast->pNext = pTemp;
		}
		pLast = pTemp;
	}
	pLast->pNext = nullptr;
}