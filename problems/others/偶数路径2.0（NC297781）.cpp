#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> a;                  //每个节点权值奇偶性
vector<bool> check;             //记录每个节点是否被访问的标记数组
vector<vector<int>> graph;      //邻接表
vector<int> arr;                //每个节点连接的路径gcd为偶数的个数

int ans = 0;
int dfs(int x,int sum) {                //深度优先遍历,返回路径gcd偶数和
    for (auto& p : graph[x]) {
        if (check[p]) {
            continue;
        }
        check[p] = 1;
        int tmp = dfs(p, sum);
        sum += tmp;
    }
    ans += sum;
    if (a[x] & 1) {
        return 0;
    }
    return sum + 1;
}

int main() {
    int n;
    cin >> n;
    a.resize(n + 1);
    graph.resize(n + 1);
    check.resize(n + 1, 0);
    arr.resize(n + 1);
    for (int i = 1; i < a.size(); ++i) {
        int tmp;
        cin >> tmp;
        a[i] = tmp & 1;
    }
    for (int i = 1; i < a.size() - 1; ++i) {    //构造邻接表
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    check[1] = 1;
    dfs(1, 0);
    cout << ans + 1;
    return 0;
}