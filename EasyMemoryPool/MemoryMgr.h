#ifndef _MEMORYMGR_H_
#define _MEMORYMGR_H_

class MemoryMgr
{
	MemoryMgr();
public:
	~MemoryMgr();
	void* alloc(size_t size);
	void free(void* p);
	static MemoryMgr& getInstance();
private:

};



#endif // !_MEMORYMGR_H_
