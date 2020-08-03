#ifndef _ALLOCTOR_H_
#define _ALLOCTOR_H_
#include "MemoryMgr.h"

class Allocator
{
public:
	void* operator new(size_t size);
	void operator delete(void* p);

	void* operator new[](size_t size);
	void operator delete[](void* p);
private:

};




#endif // !_ALLOCTOR_H_
