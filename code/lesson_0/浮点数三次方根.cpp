/*

给定一个浮点数 n，求它的三次方根。

输入格式
共一行，包含一个浮点数 n。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 6 位小数。

数据范围
−10000≤n≤10000
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    double l = -10000, r = 10000;
    double x = 0;
    cin >> x;
    while (r - l > 1e-8)
    {
        double mid = (r + l) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%lf", l);
    return 0;
}