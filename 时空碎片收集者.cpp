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
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n + m + 2, 0);
    vector<ll> s(n + m + 2, 0);
    for (ll i = 1;i <= n;++i) {
        cin >> a[i];
    }
    for (ll i = 1;i <= n + m + 1;++i) {
        s[i] = s[i - 1] + a[i];
    }
    vector<vector<ll>>dp(n + m + 2, vector<ll>(k + 2, 0));
    for (ll i = 1;i <= n + m + 1;++i) {
        dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - 1][1]) + a[i]);
        dp[i][k + 1] = max(dp[i][k + 1], max(dp[i - 1][0], dp[i - 1][1]) + 2 * a[i]);
        for (ll j = 1;j <= k;++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a[i] / 2);
        }
        // for (ll j = 0;j <= k + 1;++j) {
        //     dp[min(i + m, n + 1)][max(0ll, j - m - 1)]
        //         = max(dp[min(i + m, n + 1)][max(0ll, j - m - 1)], dp[i - 1][j] + s[min(i + m, n)] - s[i - 1]);
        // }
        if (i > m)
            for (ll j = 0;j <= k + 1;++j) {
                dp[min(i, n + 1)][j] = max(dp[min(i, n + 1)][j], dp[i - m - 1][min(j + m + 1, k + 1)] + s[i] - s[i - m - 1]);
            }
    }
    ll MAX = 0;
    for (ll i = 0;i <= k + 1;++i) {
        MAX = max(MAX, dp[n + 1][i]);
    }
    cout << MAX;
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
        cout << '\n';
    }
}