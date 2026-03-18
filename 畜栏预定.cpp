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

struct OX {
    ll i;
    ll l;
    ll r;
    bool operator<(const OX& p) const {
        if (l == p.l) {
            return r < p.r;
        }
        return l < p.l;
    }
};

void solve() {
    ll n;
    cin >> n;
    list<OX> ox(n);
    vector<ll> ans(n, 0);
    ll i = 0;
    for (auto p = ox.begin();p != ox.end();++p, ++i) {
        cin >> (*p).l >> (*p).r;
        (*p).i = i;
    }
    ox.sort();
    ll r;
    ll u = 0;
    while (!ox.empty()) {
        ++u;
        r = -1;
        OX mid = { 0,r,0 };
        auto p = upper_bound(ox.begin(), ox.end(), mid);
        while (p != ox.end()) {
            r = (*p).r;
            ans[(*p).i] = u;
            ox.erase(p);
            mid = { 0,r,0 };
            p = upper_bound(ox.begin(), ox.end(), mid);
        }
    };
    cout << u << '\n';
    for (auto& p : ans) {
        cout << p << '\n';
    }
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}