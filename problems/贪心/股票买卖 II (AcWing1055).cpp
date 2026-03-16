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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& p : a) {
        cin >> p;
    }
    ll sum = 0;
    bool vis = 0;
    for (ll i = 0;i < n - 1;++i) {
        if (vis) {
            if (a[i] > a[i + 1]) {
                vis = false;
                sum += a[i];
            }
        }
        else {
            if (a[i] < a[i + 1]) {
                vis = true;
                sum -= a[i];
            }
        }
    }
    if (vis) sum += a[n - 1];
    cout << sum;
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}