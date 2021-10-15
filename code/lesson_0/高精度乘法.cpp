/*

给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共一行，包含 A×B 的值。

数据范围
1≤A的长度≤100000,
0≤B≤10000
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(t);
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
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}