#include<bits/stdc++.h>
using namespace std;

const unsigned int u = 0x55555555;      //u=0101......0101;
const unsigned int v = 0xaaaaaaaa;      //v=1010......1010;

int high_bit(unsigned int x) {
    int pos = 0;
    while (x) {
        x >>= 1;
        pos++;
    }
    return pos;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int a1 = a, b1 = b;
        a &= u;
        b &= v;
        int tmp = a + b;
        int MAX;
        a = high_bit(tmp);
        b = high_bit(tmp + 1);
        if (a == b) {
            MAX = a - 1;
        }
        else {
            MAX = a;
        }
        a1 &= v;
        b1 &= u;
        tmp = a1 + b1;
        a1 = high_bit(tmp);
        b1 = high_bit(tmp + 1);
        if (a1 == b1) {
            MAX = max(MAX, a1 - 1);
        }
        else {
            MAX = max(MAX, a);
        }
        cout << MAX << '\n';
    }
}