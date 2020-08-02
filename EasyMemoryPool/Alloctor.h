#ifndef _ALLOCTOR_H_
#define _ALLOCTOR_H_
#include "MemoryMgr.h"

void* operator new(size_t size);
void operator delete(void* p);

void* operator new[](size_t size);
void operator delete[](void* p);



#endif // !_ALLOCTOR_H_
