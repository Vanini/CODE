#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define R(l, r) (rand()%((r) - (l) + 1ll) + (l))
int main(void) {
	freopen("walk10.in", "w", stdout);
	srand((size_t)time(NULL));
	int n = 100000, m = n;long long r = 1000000000, l = r - 1000;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", R(1, n));
	}
	for (int i = 1; i <= m; i++) {
		printf("%d %lld\n", i, (long long )rand() * rand() % 1000000000000000000ll);
	}
	return 0;
}

