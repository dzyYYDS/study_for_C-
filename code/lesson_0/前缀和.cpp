#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int N = 1e6 + 10;
int a[N], s[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    while (m--)
    {
        int r, l;
        cin >> l >> r;
        cout << s[r] - s[l - 1];
    }
    return 0;
}