/*
维护一个集合，初始时集合为空，支持如下几种操作：

I x，插入一个数 x;
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 k 个插入的数；
C k x，修改第 k 个插入的数，将其变为 x；
现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

输入格式
第一行包含整数 N。

接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

输出格式
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

数据范围
1≤N≤105
−109≤x≤109
数据保证合法。

输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
输出样例：
-10
6
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int n, cnt;
int heap[N], hp[N], ph[N];
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

void up(int u)
{
    while (u / 2 && heap[u / 2] > heap[u])
    {
        heap_swap(u, u / 2);
        u = u >> 1;
    }
}
void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}
int main()
{
    cin >> n;
    int m = 0;
    string op;
    int k, x;
    while (n--)
    {
        cin >> op;
        if (op == "PM")
            cout << heap[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (op == "D")
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else if (op == "I")
        {
            scanf("%d", &x);
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            heap[cnt] = x;
            up(cnt);
        }
        else if (op == "C")
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;