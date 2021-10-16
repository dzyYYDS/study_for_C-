/*
假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。

现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。

接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含两个整数 x 和 c。

再接下来 m 行，每行包含两个整数 l 和 r。

输出格式
共 m 行，每行输出一个询问中所求的区间内数字和。

数据范围
−109≤x≤109,
1≤n,m≤105,
−109≤l≤r≤109,
−10000≤c≤10000
输入样例：
3 3
1 2
3 6
7 5
1 3
4 6
7 8
输出样例：
8
0
5
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3e6 + 10;
int n, m;
typedef pair<int, int> PII;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1; //
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c; // 分别位下标以及对应的值
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i > m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去除重复出现的点
    for (auto item : add)
    {
        // 没有使用find() 函数
        int x = find(item.first);
        a[x] += item.second;
    }
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto item : query)
    {
        cout << "ok";
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1];
    }
    return 0;
}