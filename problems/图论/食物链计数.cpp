#pragma GCC optimize(2)

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define mian main
#define retrun return
#define endl '\n'

using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    vector<ll> in(n + 1, 0), out(n + 1, 0);
    for (int i = 0;i < m;++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    queue<ll> qe;
    vector<ll> a(n + 1, 0);
    for (ll i = 1;i <= n;++i) {
        if (in[i] == 0 && out[i] != 0) {
            qe.push(i);
            a[i] = 1;
        }
    }

    while (!qe.empty()) {
        ll top = qe.front();
        qe.pop();
        for (auto& p : graph[top]) {
            a[p] += a[top];
            if (--in[p] == 0) {
                qe.push(p);
            }
        }
    }

    ll ans = 0;
    for (int i = 1;i <= n;++i) {
        if (out[i] == 0) {
            ans += a[i];
        }
    }
    cout << ans;
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}