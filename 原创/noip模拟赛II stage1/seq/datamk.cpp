#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define R(l, r) (rand()%((r) - (l) + 1) + (l))
int main(void) {
	freopen("seq14.in", "w", stdout);
	srand((size_t)time(NULL));
	int n = 100000, k = 999;
	printf("%d %d\n", n, k);
	for (int i = 1; i <= n; i++)
		printf("%d ", R(0, 20000) * -1);
	return 0;
}

