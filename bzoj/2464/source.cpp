#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
namespace Solve {
	const int MAXN = 505;

	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};
	int f[MAXN][MAXN], m, n, x1, x2, y1, y2; bool a[MAXN][MAXN], hash[MAXN][MAXN];

	std::deque<std::pair<int,int> > Q;

	inline void solve(void) {
		Q.clear();
		for (int i = 0; i < n; i++, getchar())
			for (int j = 0; j < m; j++) a[i][j] = (getchar() == '#');
		scanf("%d%d%d%d\n", &x1, &y1, &x2, &y2);
		memset(hash, 0, sizeof hash);
		memset(f, 60, sizeof f);
		hash[x1][y1] = !(f[x1][y1] = 0);
		Q.push_back(std::make_pair(x1, y1));
		while (!Q.empty()) {
			std::pair<int, int> now = Q.front(); Q.pop_front();
			for (int i = 0; i < 4; i++) {
				int lx = now.first + dx[i], ly = now.second + dy[i];
				if (lx < 0 || ly < 0 || lx >= n || ly >= m) continue;
				if (f[lx][ly] > f[now.first][now.second] + (a[lx][ly] != a[now.first][now.second])) {
					f[lx][ly] = f[now.first][now.second] + (a[lx][ly] != a[now.first][now.second]);
					if (!hash[lx][ly]) {
						hash[lx][ly] = true;
						Q.push_back(std::make_pair(lx, ly));
					}
				}
			}
			hash[now.first][now.second] = false;
		}
		printf("%d\n", f[x2][y2]);
	}
}
int main(void) {
	freopen("in", "r", stdin);
	while (scanf("%d%d\n", &Solve::n, &Solve::m), Solve::m || Solve::n)
		Solve::solve();
	return 0;
}
