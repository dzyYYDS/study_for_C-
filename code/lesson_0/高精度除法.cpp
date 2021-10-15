/*
给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共两行，第一行输出所求的商，第二行输出所求余数。

数据范围
1≤A的长度≤100000,
1≤B≤10000,
B 一定不为 0
输入样例：
7
2
输出样例：
3
1
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> div(vector<int> A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    int r = 0;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    cout << endl
         << r << endl;

    return 0;
}