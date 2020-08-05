#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <chrono>
#include "ALLOCATOR.HPP"

using namespace std;
int main(int argc, char* argv[])
{
    std::allocator<int> a1;
    Kevin::Allocator<int> a2;
    vector<int, std::allocator<int>> ivec;
    vector<int, Kevin::Allocator<int>> ivec2;
    

    int freqency1 = 1000000;
    int freqency2 = 1000000;

//     while (freqency1)
//     {
//         for (size_t i = 0; i < 100; i++)
//         {
//             ivec2.push_back(freqency1);
//         }
//         for (size_t i = 0; i < 100; i++)
//         {
//             ivec2.pop_back();
//         }
//     }

    auto start = chrono::high_resolution_clock::now();
    while (freqency2--)
    {
        int* p[10];
        int num = 10;
     
        /*---------------------------------------------------*
         *      1.11289     1.15869     1.11694 
         **/
//         for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
//             p[i] = new int[num];
//         }
//         for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
//             delete p[i];
//         }

        /*---------------------------------------------------*
         *      1.16758     1.18962     1.18962
         **/
		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
            p[i] = a1.allocate(num);
		}
		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
            a1.deallocate(p[i], num);
		}

		/*---------------------------------------------------*
		 *      0.0438533     0.0417142     0.0394432
		 **/
// 		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
// 			p[i] = a2.allocate(num);
// 		}
// 		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
// 			a2.deallocate(p[i], num);
// 		}
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::nanoseconds(end - start).count() / (1000.0 * 1000 * 1000) << endl;





	return 0;
}
