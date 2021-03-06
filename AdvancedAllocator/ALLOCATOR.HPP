#ifndef _ALLOCATOR_HPP_
#define _ALLOCATOR_HPP_

#include "ALLOC.H"
#include <utility>

_KEVIN_BEGIN
template <class T>
class Allocator {
public:
	using value_type = T;
	using size_type = size_t;
public:
	Allocator() = default;
	~Allocator() = default;
public:
	T* allocate(size_t n = 1) {
		return  n ? static_cast<T*>(Alloc::allocate(n * sizeof(T))) : nullptr;
	}

	void deallocate(void* p, size_t n = 1) {
		if (n) Alloc::deallocate(p, n * sizeof(T));
	}

	void* reallocate(void* p, size_t oldNum, size_t newNum) {
		Alloc::reallocate(p, oldNum * sizeof(T), newNum * sizeof(T));
	}

	template <class... Types>
	void construct(T* const pObj, Types&&... args) {
		new (static_cast<T*>(pObj)) T(std::forward<Types>(args)...);
	}

	void destroy(T* p) {
		p->~T();
	}
private:

};
_KEVIN_END

#endif // !_ALLOCATOR_HPP_

