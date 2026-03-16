#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200001], b, lb;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> b;
    int m = 0;
    while (a[m++] < k) {
        cin >> b;
        a[m] += a[m - 1];
    }
    b = 0;
    lb = 0;
    ll* p = &b, * lp = &lb, * q = &a[m], * lq = &a[m - 1];
    for (int i = m; i < n; ++i) {
        cin >> b;
        *q += *lp < k ? *lq : max(*lq, *lp - k);
        *p += *lq < k ? *lp : max(*lp, *lq - k);
        if (*q < *p) { swap(q, p); }
        *lq = *q;
        *lp = *p;
        if (q == &a[i]) { q++; }
        else { p++; }
    }
    cout << *q;
    return 0;
}