#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
int m[N][N] = { 0, };		//炸弹矩阵

int main() {
	int max_dim = 0;
	int n, r;
	cin >> n >> r;
	int x, y, w;
	for (int i = 0; i < n; ++i) {		//给初始矩阵赋值
		cin >> x >> y >> w;
		m[x][y] += w;
		max_dim = max(max_dim, max(x, y));
	}
	{										//初始化二维前缀和矩阵
		for (int i = 1; i <= max_dim; ++i) {
			m[0][i] = m[0][i - 1] + m[0][i];	//初始化第0行
			m[i][0] = m[i - 1][0] + m[i][0];	//初始化第0列
		}
		for (int i = 1; i <= max_dim; ++i) {		//初始化其余元素
			for (int j = 1; j <= max_dim; ++j) {
				m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + m[i][j];
			}
		}
	}

	if (r == 0) {
		cout << 0;
		return 0;
	}
	if (r > max_dim) {
		cout << m[max_dim][max_dim];
		return 0;
	}

	int MAX = m[r - 1][r - 1];		//初始化最大值
	int tmp;
	for (int i = r; i <= max_dim; ++i) {
		tmp = m[r - 1][i] - m[r - 1][i - r];	//遍历第0行1*r矩阵
		MAX = max(MAX, tmp);
		tmp = m[i][r - 1] - m[i - r][r - 1];	//遍历第0列r*1矩阵
		MAX = max(MAX, tmp);
	}
	for (int i = r; i <= max_dim; ++i) {
		for (int j = r; j <= max_dim; ++j) {
			tmp = m[i][j] - m[i][j - r] - m[i - r][j] + m[i - r][j - r];	//遍历第[i][j]r*r矩阵
			MAX = max(MAX, tmp);
		}
	}
	cout << MAX;
	return 0;
}