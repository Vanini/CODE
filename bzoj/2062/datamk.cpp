#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#define R(l,r) ((l) + rand() % ((r) - (l) + 1))
int main(void) {
	srand((size_t)time(NULL));
	freopen("in", "w", stdout);
	int n = 100000; printf("%d\n", n);
	for (int i = 1; i <= n; i++) putchar('a' + R(1, 7)), putchar(' ');
	puts("");
	for (int i = 1; i <= n; i++) printf("%d\n", R(1, n));
	return 0;
}

