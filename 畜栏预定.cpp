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

}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}