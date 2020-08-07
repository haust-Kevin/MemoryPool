

/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 *
 *
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *            佛祖保佑       永不宕机     永无BUG
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <chrono>
#include "ALLOCATOR.HPP"
/**
 * 以下测试在visual studio 2019 环境下以 X64 Release 运行
 * Debug模式无法正常运行，因为Debug模式附加了一些调试代码的片段
 */
using namespace std;
int main(int argc, char* argv[])
{
    std::allocator<int> a1;
    Kevin::Allocator<int> a2;

    int freqency1 = 100000;
    int freqency2 = 1000000;

    auto start = chrono::high_resolution_clock::now();
    while (freqency1--)
    {
        /*---------------------------------------------------*
         *      0.73243     0.824995     0.775182
         **/
// 		list<int, std::allocator<int>> ivec1;
//         for (size_t i = 0; i < 100; i++)
//         {
//             ivec1.push_back(i);
//         }

        /*---------------------------------------------------*
         *      0.0627199        0.0609521        0.0586306
         **/
        list<int, Kevin::Allocator<int>> ivec2;
        for (size_t i = 0; i < 100; i++)
        {
            ivec2.push_back(i);
        }
    }

    int* p[10];
    int num = 10;
    while (freqency2--)
    {

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
// 		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
//             p[i] = a1.allocate(num);
// 		}
// 		for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
//             a1.deallocate(p[i], num);
// 		}

        /*---------------------------------------------------*
         *      0.0333378     0.0324148     0.0310159
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
