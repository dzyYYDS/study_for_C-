/*

给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，表示整个数列。

输出格式
共一行，包含 n 个整数，其中的第 i 个数表示数列中的第 i 个数的二进制表示中 1 的个数。

数据范围
1≤n≤10 0000,
0≤数列中元素的值≤109
输入样例：
5
1 2 3 4 5
输出样例：
1 1 2 1 2

*/

#include <iostream>
#include <algorithm>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int res = 0;
        while (x)
            x -= lowbit(x), res++;
        cout << x;
    }
}