#include <cstdio>
#include <algorithm>

#ifdef unix
#define LL "%lld"
#else
#define LL "%I64d"
#endif

int f[62][100005], n, m, t, l; long long u;
int main(void) {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &f[0][i]);
	for (int k = 1; k < 62; k++) for (int i = 1; i <= n; i++)
			f[k][i] = f[k - 1][f[k - 1][i]];
	while (m--) {
		for (scanf("%d" LL, &t, &u), l = 0;u;u>>=1,l++) if (u&1) t = f[l][t];
		printf("%d\n", t);
	}
	return 0;
}
