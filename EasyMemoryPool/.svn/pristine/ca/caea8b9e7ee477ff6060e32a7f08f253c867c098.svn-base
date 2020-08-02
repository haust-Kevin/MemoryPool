#include "MemoryMgr.h"
#include <cstdlib>

MemoryMgr::MemoryMgr()
{
}

MemoryMgr::~MemoryMgr()
{
}

void* MemoryMgr::alloc(size_t size)
{
	return ::malloc(size);
}

void MemoryMgr::free(void* p)
{
	::free(p);
}

MemoryMgr& MemoryMgr::getInstance()
{
	static MemoryMgr instance;
	return instance;
}