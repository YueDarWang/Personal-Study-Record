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

const ll MAXN = 2e5 + 10;

struct node {
    bool lazy = 0;
    ll n = 0;                   //区间1的总数
    ll l = 0, r = 0;            //区间范围
    ll l1 = 0, r1 = MAXN + 1;   //两边第一个1出现的位置
    ll ld = 0, rd = 0;          //两边第一个合法连续1出现的公差
    ll ln = 0, rn = 0;          //两边第一个合法连续1出现的次数
    ll ans = 0;                 //该区间的最大合法连续1长度
}sgt[MAXN << 2];                //线段树

bool a[MAXN];

void build_tree(ll p, ll l, ll r) {
    sgt[p].l = l;
    sgt[p].r = r;
    sgt[p].lazy = 0;
    if (l == r) {
        sgt[p].ld = 0;
        sgt[p].rd = 0;
        if (a[l]) {
            sgt[p].n = 1;
            sgt[p].l1 = l;
            sgt[p].r1 = l;
            sgt[p].ln = 1;
            sgt[p].rn = 1;
            sgt[p].ans = 1;
        }
        else {
            sgt[p].n = 0;
            sgt[p].l1 = 0;
            sgt[p].r1 = MAXN + 1;
            sgt[p].ln = 0;
            sgt[p].rn = 0;
            sgt[p].ans = 0;
        }
        return;
    }
    ll mid = (l + r) >> 1;
    ll lc = p << 1;         //左孩子
    ll rc = lc | 1;         //右孩子
    build_tree(lc, l, mid);
    build_tree(rc, mid + 1, r);
    sgt[p].n = sgt[lc].n + sgt[rc].n;
    ll midn = (1 & sgt[lc].n) + (1 & sgt[rc].n);
    sgt[p].l1 = sgt[rc].l1;
    sgt[p].ld = sgt[rc].ld;
    sgt[p].r1 = sgt[lc].r1;
    sgt[p].rd = sgt[lc].rd;
    if (sgt[lc].l1 != 0) {
        sgt[p].l1 = sgt[lc].l1;
        sgt[p].ld = sgt[lc].ld;
    }
    if (sgt[rc].r1 != MAXN + 1) {
        sgt[p].r1 = sgt[rc].r1;
        sgt[p].rd = sgt[rc].rd;
    }
    //上次看到这了
    if (sgt[lc].l1 != 0 && sgt[rc].l1 != 0 &&
        sgt[lc].rd == sgt[rc].ld &&
        sgt[rc].l1 - sgt[lc].r1 - 1 == sgt[lc].rd) {        //左右区间都不全为0且可合并
        midn = sgt[lc].rn + sgt[rc].ln;
        if (sgt[lc].ln == sgt[lc].n) {
            sgt[p].ln = midn;
        }
        else {
            sgt[p].ln = sgt[lc].ln;
        }
        if (sgt[rc].rn = sgt[rc].n) {
            sgt[p].rn = midn;
        }
        else {
            sgt[p].rn = sgt[rc].rn;
        }
    }
    else {

    }
    sgt[p].ans = max(sgt[p].ln, sgt[p].rn, midn);
}

void solve() {
    ll n, q;
    cin >> n >> q;
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