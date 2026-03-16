#include<bits/stdc++.h>
using namespace std;

vector<int>a;

bool calc(double ave, int L) {		//计算当前平均值是否可行
	int n = 0;
	int sum = 0;
	int asum = 0;
	for (int i = 0; i < a.size(); ++i) {
		++n;
		sum += a[i];
		if (n > L) {
			asum += a[i - L];
			if (double(asum) / (n - L) < ave) {		//减去前n-L个已选的数
				n = L;
				sum -= asum;
				asum = 0;
			}
			
		}
		if (n >= L && double(sum) / n >= ave) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, L;
	cin >> n >> L;
	a.resize(n);
	double l = 2000.0f, r = 0.0f;
	double m;
	for (auto& p : a) {
		cin >> p;
		l = l > p ? p : l;
		r = r < p ? p : r;
	}
	while (l + 0.00001 < r) {		//二分答案
		m = (l + r) / 2.0f;
		if (calc(m, L)) {
			l = m;
		}
		else {
			r = m;
		}
	}
	cout << int(r * 1000);
	return 0;
}