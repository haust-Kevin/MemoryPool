
#include "ALLOC.H"
#include <cstdlib>
using namespace Kevin;

Alloc::Node* Alloc::freeList[__NFREELISTS] = {
	nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
	nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
};

char* Alloc::pStart = nullptr;
char* Alloc::pEnd = nullptr;
size_t Alloc::heapTotalSize = 0;

void* Alloc::refill(size_t n)
{
	return nullptr;
}

void* Alloc::chunkAlloc(size_t size, int& nObjs)
{
	return nullptr;
}


void* Alloc::allocate(size_t size)
{
	if (size > __MAX_BYTES) {
		return  malloc(size);
	}
	Node** myFreeList = freeList + FREELIST_INDEX(size);
	Node* result = *myFreeList;
	if (result == nullptr) {
		return  refill(ROUND_UP(size));
	}
	*myFreeList = result->next;
	return result;
}

void Alloc::deallocate(void* p, size_t size)
{
	if (size > __MAX_BYTES) {
		return  free(p);
	}
	Node* pFree = static_cast<Node*>(p);
	Node** myFreeList = freeList + FREELIST_INDEX(size);
	pFree->next = *myFreeList;
	*myFreeList = pFree;
}

void Alloc::reallocate(void* p, size_t oldSize, size_t newSize)
{

}