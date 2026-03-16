#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
int dif[10001] = { 0 , };		//差分数组

int main() {
	int n, i, h, r;
	cin >> n >> i >> h >> r;
	dif[0] = h;
	while (r--) {
		int x, y;
		cin >> x >> y;
		if (s.find({x,y})!=s.end()) {		//判重
			continue;
		}
		s.insert({ x,y });
		if (x > y) { swap(x, y); }
		dif[x]--;		//区间-1；
		dif[y - 1]++;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += dif[i];		//求原数组
		cout << sum << '\n';
	}
	return 0;
}