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
    ll minspf;
    ll maxspf;
    bool operator>(const OX& p) const {
        if (minspf == p.minspf)    return maxspf > p.maxspf;
        return minspf > p.minspf;
    }
};

struct SPF {
    ll x;
    ll n;
    bool operator>(const SPF& p) const {
        return x > p.x;
    }
};

void solve() {
    ll c, l;
    cin >> c >> l;
    vector<OX> oxs(c);
    for (auto& p : oxs) {
        cin >> p.minspf >> p.maxspf;
    }
    vector<SPF> spfs(l);
    vector<ll> cover(l);
    for (auto& p : spfs) {
        cin >> p.x >> p.n;
    }
    sort(oxs.begin(), oxs.end(), greater<OX>());
    sort(spfs.begin(), spfs.end(), greater<SPF>());
    ll cnt = 0;
    for (int i = 0;i < c;++i) {
        for (ll j = 0;j < l;++j) {
            if (spfs[j].n > 0 && oxs[i].minspf <= spfs[j].x && spfs[j].x <= oxs[i].maxspf) {
                ++cnt;
                spfs[j].n--;
                break;
            }
        }
    }
    cout << cnt;
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}