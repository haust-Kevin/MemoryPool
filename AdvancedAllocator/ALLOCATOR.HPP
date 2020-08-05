#ifndef _ALLOCATOR_HPP_
#define _ALLOCATOR_HPP_

#include "ALLOC.H"

_KEVIN_BEGIN
template <class T>
class allocator {
public:
	using value_type = T;
	using size_type = size_t;
public:
	T* allocate(size_t n = 1) {
		return  n ? static_cast<T*>(Alloc::allocate(n * sizeof(T))) : nullptr;
	}

	void deallocate(void* p, size_t n = 1) {
		if (n) Alloc::deallocate(p, n);
	}

	void reallocate(void* p, size_t oldSize, size_t newSize) {
		Alloc::reallocate(p, oldSize, newSize);
	}

	template <class... Types>
	void construct(T* const pObj, Types&&... args) {
		::new (static_cast<void*>(pObj)) T(std::forward<Types>(args)...);
	}

	void destroy(T* p) {
		p->~T();
	}
private:

};
_KEVIN_END

#endif // !_ALLOCATOR_HPP_