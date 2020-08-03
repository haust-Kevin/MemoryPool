#include "Allocator.h"
#include <cstdlib>

#include "MemoryMgr.h"

void* Allocator::operator new(size_t size)
{
	return MemoryMgr::getInstance()->alloc(size);
}

void Allocator::operator delete(void* p)
{
	MemoryMgr::getInstance()->free(p);
}

void* Allocator::operator new[](size_t size)
{
	return MemoryMgr::getInstance()->alloc(size);
}

void Allocator::operator delete[](void* p)
{
	MemoryMgr::getInstance()->free(p);
}

