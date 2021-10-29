/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes

*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int e[N], w[N], ne[N], h[N], idx;
int dist[N];
bool st[N]; //标记是否在队列中;
int cnt[N];

void add(int a, int b, int c)
{

    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool psfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n)
                    return true;
                if (!st[j])
                    q.push(j);
                st[j] = true;
            }
        }
    }
    return false;
}
int main()
{

    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if (psfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}