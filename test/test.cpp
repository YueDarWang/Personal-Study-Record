#pragma GCC optimize(2)

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define MOD 1000000007
#define mian main
#define retrun return
#define endl '\n'

using namespace std;

struct TP {     // 传送门
    ll w;
    ll x = -1;
    ll y = -1;
    bool operator<(const TP& p) const {
        return w < p.w;
    }
};

struct CELL {   // 单元格
    ll t;
    vector<TP> tp;
};

void solve() {
    ll n, m, money, k;
    cin >> n >> m >> money >> k;
    vector<vector<CELL>> graph(n + 1, vector<CELL>(m + 1));
    ll maxt = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> graph[i][j].t;
            maxt = max(maxt, graph[i][j].t);
        }
    }
    for (ll i = 0; i < k; ++i) {
        ll x, y, p, q, w;
        cin >> x >> y >> p >> q >> w;
        graph[x][y].tp.push_back({ w, p, q });
    }

    const ll INF = 1e18;
    auto can_reach = [&](ll t, ll money_limit) -> bool {
        vector<vector<ll>> dist(n + 1, vector<ll>(m + 1, INF));
        dist[1][1] = 0;
        deque<pair<int, int>> dq;
        dq.push_front({ 1, 1 });
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            ll cost = dist[x][y];
            if (cost > money_limit) continue;
            // 移动到相邻格子（费用0）
            vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && t >= graph[nx][ny].t && dist[nx][ny] > cost) {
                    dist[nx][ny] = cost;
                    dq.push_front({ nx, ny });
                }
            }
            // 使用传送门（费用w）
            for (auto& tp : graph[x][y].tp) {
                int nx = tp.x, ny = tp.y;
                if (t >= graph[nx][ny].t) {
                    ll ncost = cost + tp.w;
                    if (ncost < dist[nx][ny]) {
                        dist[nx][ny] = ncost;
                        dq.push_back({ nx, ny });
                    }
                }
            }
        }
        return dist[n][m] <= money_limit;
        };

    ll l = 0, r = maxt;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (can_reach(mid, money))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}