
# 对前面两个章节内容一个总结

``` C++
#include <iostream>
#include <cstring>
#include <queue>
using namespace  std;
const int N=1e6+10;
// h[N] 存储邻接表的头节点
// idx 相当于每个数字唯一的id
// e[N] 存储元素data
// ne[N] 存储的的指针 指向下一个元素
int e[N],ne[N],h[N],idx;
// 在dijstra最短路问题中 记录起始点到 第i个点距离
int dist[N]; //  初始值设置为最大
bool st[N]; // 用来标记是否被遍历过

// 直接可以构建 链表、树或图的临界表;通用模板 将a添加在b的后面
void  add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
// 可返回额外的信息
int bfs(){
    // 一般是跟固定起点的搜素有关 最短路问题
    queue<int> q;
    // 从元素为1的点开始bfs遍历  可以根据需求改成入度为0的点
    q.push(1);
    while(q.size()){
        int temp = q.front();
        q.pop();
        // 访问temp为头结点元素的邻接表
        for(int i=h[temp];i != -1;i=ne[i]){
            int j =e[i];
            // 标记是否访问过 避免出现死循环
            if(!st[j]){
                // 进行相关的数据操作

                // 将 j 作为新的元素 进入队列 等待进行搜索子树
                q.push(j);
            }
        }
    }
}
int dfs(int u){
    st[u]=true ;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            int temp = dfs(j);// 递归搜索 知道搜索到尽头 自动返回 形成深度优先搜索
        }
    }
}
int main() {
    int n,m;
    memset(h,-1,sizeof (h));
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    //数和图的各种操作
    // 宽搜
    bfs();
    memset(st,0,sizeof (st));
    // 深搜
    dfs(1);

    return 0;
}


```
