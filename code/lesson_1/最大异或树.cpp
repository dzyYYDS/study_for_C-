/*
在给定的 N 个整数 A1，A2……AN 中选出两个进行 xor（异或）运算，得到的结果最大是多少？

输入格式
第一行输入一个整数 N。

第二行输入 N 个整数 A1～AN。

输出格式
输出一个整数表示答案。

数据范围
1≤N≤105,
0≤Ai<231
输入样例：
3
1 2 3
输出样例：
3
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = 3000010;

int son[M][2], idx;
int a[N];
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int &s = son[p][x >> i & 1];
        if (!s)
            s = ++idx;
        p = s;
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}