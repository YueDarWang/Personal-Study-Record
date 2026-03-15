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
    ll t = log(n) / log(2) + 1;
    vector<ll>a(n + 1);
    vector<vector<ll>> ST(n + 1, vector<ll>(t, 0));
    for (ll i = 1;i <= n;++i)
        cin >> a[i];
    for (ll i = 1;i <= n;++i)
        ST[i][0] = a[i];
    for (ll j = 1;j <= t;++j) {     //通过倍增初始化ST表
        for (ll i = 1;i <= n - (1 << j) + 1;++i) {
            ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (m--) {
        ll l, r;
        cin >> l >> r;
        ll k = log(r - l + 1) / log(2);
        ll ans = max(ST[l][k], ST[r - (1 << k) + 1][k]);
        cout << ans << '\n';
    }
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}