#include "Alloctor.h"
#include <cstdlib>

#include "MemoryMgr.h"

void* operator new(size_t size)
{
	return MemoryMgr::getInstance().alloc(size);
}

void operator delete(void* p)
{
	MemoryMgr::getInstance().free(p);
}

void* operator new[](size_t size)
{
	return MemoryMgr::getInstance().alloc(size);
}

void operator delete[](void* p)
{
	MemoryMgr::getInstance().free(p);
}

