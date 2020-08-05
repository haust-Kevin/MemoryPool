#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX_BLOCK_SIZE 10240ULL
#include "Allocator.h"
#include <chrono>

using namespace std;

template<size_t size>
class Demo :public Allocator
{
public:

private:
	char chars[size];
};


int main(int argc, char* argv[])
{
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");

    int n = 1000000;
    auto start = chrono::high_resolution_clock::now();
    while (n--)
    {
        auto p1 = new Demo<100>;
        auto p2 = new Demo<129>;
        auto p3 = new Demo<256>;
        auto p4 = new Demo<522>;
        auto p5 = new Demo<1024>;
        auto p6 = new Demo<2022>;
        auto p7 = new Demo<10239>;
        //cout << "----" << endl;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete p6;
        delete p7;
        delete new Demo<10239>;
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::nanoseconds(end - start).count() / (1000.0 * 1000 * 1000) << endl;
    return 0;
}

