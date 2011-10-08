#include <cstdio>
#include <algorithm>
#include <cstring>
#ifdef unix
#define LL "%lld"
#else
#define LL "%I64d"
#endif
namespace Solve {
	typedef unsigned long long Int65;
	const int MAXN = 165;
	
	inline int Digit_Sum(Int65 u) {
		register int r = 0;
		while (u) r += u % 10, u /= 10;
		return r;
	}
	
	Int65 f[MAXN][19][MAXN][MAXN];
	inline void solve(void) {
		Int65 l, r, Ans = 0; scanf(LL LL, &l, &r);
		Int65 t = r; int n = 0; while (t) n++, t /= 10;
		for (int s = 0; s <= n * 9; s++) {
			f[s][0][0][0] = 1;
			if (!s) continue;
			for (int i = 0; i < n; i++)
				for (int j = 0; j <= i * 9; j++)
					for (int k = 0; k < s; k++)
						if ((t = f[s][i][j][k]) != 0) {
							for (int next = 0; next <= 9; next++)
								f[s][i + 1][j + next][(Int65)((Int65)k * 10ll + (Int65)next) % s] += t;
						}
		}
		while (l <= r) {
			register Int65 pow = 1; register int p = 0;
			while (true) {
				register Int65 t_pow = pow * 10ll;
				if (l + t_pow - 1 <= r && l % t_pow == 0)
					p++, pow = t_pow;
				else break;
			}
			int presum = Digit_Sum(l / pow);
			for (int i = 0; i <= p * 9; i++)
				Ans += f[presum + i][p][i][(presum + i - l % (presum + i)) % (presum + i)];
			l += pow;
		}
		printf(LL "\n", Ans);
	}
}
int main(void) {
	freopen("in", "r", stdin);
	Solve::solve();
	return 0;
}

