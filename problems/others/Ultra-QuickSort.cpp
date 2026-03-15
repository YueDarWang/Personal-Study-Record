#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define mian main
#define retrun return
#define endl '\n'

using namespace std;

vector<ll> a;

void merge(ll l, ll mid, ll r, ll& cnt) { // 归并排序求逆序对
    ll i = l;
    ll j = mid + 1;
    vector<ll> b(r - l + 1);
    for (ll k = 0;k <= r - l;++k) {
        if (j > r || i <= mid && a[i] <= a[j]) { b[k] = a[i++]; }
        else {
            b[k] = a[j++];
            cnt += mid - i + 1;
        }
    }
    for (int i = 0;i <= r - l;++i) {
        a[l + i] = b[i];
    }
}

void solve(ll n) {
    a.resize(n);
    for (auto& p : a)
        cin >> p;
    ll cnt = 0;
    ll d = 1;
    while (d < n) {
        d <<= 1;
        for (ll i = 0; i < n; i += d) {
            ll mid = (i + i + d - 1) >> 1;
            merge(i, mid, min(i + d - 1, n - 1), cnt);
        }
    }
    cout << cnt << endl;
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    while (n) {
        solve(n);
        cin >> n;
    }
}