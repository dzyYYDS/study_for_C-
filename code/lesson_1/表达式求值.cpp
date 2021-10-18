/*

给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

注意：

数据保证给定的表达式合法。
题目保证符号 - 只作为减号出现，不会作为负号出现，例如，-1+2,(2+2)*(-(1+1)+2) 之类表达式均不会出现。
题目保证表达式中所有数字均为正整数。
题目保证表达式在中间计算过程以及结果中，均不超过 231−1。
题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 5/3=1，对于小于 0 的结果向上取整，例如 5/(1−4)=−1。
C++和Java中的整除默认是向零取整；Python中的整除//默认向下取整，因此Python的eval()函数中的整除也是向下取整，在本题中不能直接使用。
输入格式
共一行，为给定表达式。

输出格式
共一行，为表达式的结果。

数据范围
表达式的长度不超过 105。

输入样例：
(2+2)*(1+1)
输出样例：
8
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;
stack<int> num;
stack<char> op;
void eval()
{
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}
int main()
{
    string str;
    cin >> str;
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (isdigit(c))
        {
            int x = 0, j = i;
            while (isdigit(str[j]) && j < str.size())
                x = x * 10 + str[j++] - '0';
            i = j - 1;
            num.push(x);
        }
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(')
                eval();
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size())
        eval();

    cout << num.top() << endl;
    return 0;
}