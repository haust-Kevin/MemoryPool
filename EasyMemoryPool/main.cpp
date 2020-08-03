#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Allocator.h"
using namespace std;

class Demo :public Allocator
{
public:

private:
	string s;
	char chars[65];
};


int main(int argc, char* argv[])
{
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	Demo* p = new Demo();
	delete p;
	return 0;
}