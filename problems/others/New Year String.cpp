#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> ans;
	string s;
	int n;
	string str = "2026";
	while (t--) {
		cin >> n;
		cin >> s;
		bool mark2025 = false;
		int MAX = 0;
		for (int i = 0; i < n - 3; ++i) {
			int cnt = 0;
			if (s[i] == '2') { ++cnt; }
			if (s[i + 1] == '0') { ++cnt; }
			if (s[i + 2] == '2') { ++cnt; }
			if (s[i + 3] == '6') { ++cnt; }
			else if (cnt == 3 && s[i + 3] == '5') { mark2025 = true; }
			MAX = max(MAX, cnt);
			if (cnt == 4) {
				cout << "0\n";
				break;
			}
		}
		if (MAX == 4) {
			continue;
		}
		if (!mark2025) {
			cout << "0\n";
		}
		else {
			cout << "1\n";
		}
	}
}