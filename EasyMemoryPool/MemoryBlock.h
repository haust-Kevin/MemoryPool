#ifndef _MEMORYBLOCK_H_
#define _MEMORYBLOCK_H_
class MemoryAlloc;

class MemoryBlock
{
	friend class MemoryAlloc;
public:
	MemoryBlock();
	~MemoryBlock();
private:
	int nId; // ���
	size_t refCount; // ���ô���
	MemoryAlloc* pAlloc; // �����ڴ��
	MemoryBlock* pNext; // ��һ�������ڴ��
	bool inPool; // �Ƿ����ڴ����
//	char reserve[7]; // �ֽڶ��룬Ԥ��λ��
};


#endif // !_MEMORYBLOCK_H_
