/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×105,
图中涉及边长均不小于 0，且不超过 10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3

*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e6 + 10;
// 通过小根堆
typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;

int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // heap 中存储 dist(距离) ，ver(第i个点)
    heap.push({0, 1});
    dist[1] = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int distance = t.first, ver = t.second;
        if (!st[ver])
        {
            for (int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (dist[j] > dist[ver] + w[i])
                {
                    dist[j] = dist[ver] + w[i];
                    heap.push({dist[j], j});
                }
            }
        }
        st[ver] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{

    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        /* code */
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;

    return 0;
}