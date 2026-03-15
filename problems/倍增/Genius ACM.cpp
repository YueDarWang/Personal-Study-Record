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

//题目卡常数太狠了没招了过不了
//QAQ

void solve() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for (auto& p : a) {
        cin >> p;
    }
    ll i = 0;
    ll cnt = 0;

    while (i < n) {
        ll d = 1;
        ll q = 1;
        vector<ll> tmp1;
        vector<ll> tmp2;
        while (q) {
            // append needed elements in sorted batches and merge
            size_t target = min(d + q, n - i);
            if (tmp1.size() < target) {
                size_t oldsz = tmp1.size();
                // collect and sort the new slice
                vector<ll> added;
                added.reserve(target - oldsz);
                for (size_t k = oldsz; k < target; ++k)
                    added.push_back(a[i + k]);
                sort(added.begin(), added.end());
                // merge existing tmp1 (already sorted) with added
                vector<ll> merged;
                merged.reserve(target);
                merge(tmp1.begin(), tmp1.end(), added.begin(), added.end(), back_inserter(merged));
                tmp1.swap(merged);
            }
            ll sum = 0;
            if (tmp1.size() == 1) {
                break;
            }
            for (ll j = 0;j < m && 2 * j + 2 <= tmp1.size();++j) {
                ll x = tmp1[tmp1.size() - j - 1] - tmp1[j];
                sum += x * x;
            }
            if (sum <= t) {
                tmp2 = tmp1;
                d += q;
                q <<= 1;
                if (i + d >= n) {
                    break;
                }
            }
            else {
                q >>= 1;
                tmp1 = tmp2;
            }
        }
        i += d;
        cnt++;
    }
    cout << cnt;
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
}