#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	ll tmp1, tmp2;
	ll pos = 0;		//正数和
	ll neg = 0;		//负数和的绝对值
	cin >> tmp1;
	for (int i = 1; i < n; ++i) {
		cin >> tmp2;
		tmp1 = tmp2 - tmp1;		//计算差分
		if (tmp1 > 0) {
			pos += tmp1;
		}
		if (tmp1 < 0) {
			neg -= tmp1;
		}
		tmp1 = tmp2;
	}
	cout << max(pos, neg) << '\n' << (pos > neg ? pos - neg : neg - pos) + 1;
	return 0;
}