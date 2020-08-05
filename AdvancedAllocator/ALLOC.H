#ifndef _ALLOC_H_

#define _KEVIN_BEGIN namespace Kevin {
#define _KEVIN_END   }
#define _KEVIN       ::Kevin::


_KEVIN_BEGIN
class Alloc {
private:
	struct Node { struct Node* next; };

private:
	enum :size_t { __ALIGN = 8 };
	enum :size_t { __MAX_BYTES = 128 };
	enum :size_t { __NFREELISTS = __MAX_BYTES / __ALIGN };

private:
	static size_t ROUND_UP(size_t bytes) {
		return (bytes + __ALIGN - 1) & ~(__ALIGN - 1);
	}

	static size_t FREELIST_INDEX(size_t bytes) {
		return (bytes + __ALIGN - 1) / __ALIGN - 1;
	}

private:
	static void* refill(size_t n);
	static void* chunkAlloc(size_t size, int& nObjs);

public:
	static void* allocate(size_t size);
	static void deallocate(void* p, size_t size);
	static void reallocate(void* p, size_t oldSize, size_t newSize);

private:
	static Node* freeList[__NFREELISTS];
	static char* pStart;
	static char* pEnd;
	static size_t heapTotalSize;
};
_KEVIN_END

#endif // !_ALLOC_H_
