#include <cstdio>
#include <algorithm>
int main(void) {
	int a = 1, b, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		b = ((a << 1) + 1) % 1200007, std::swap(a, b);
	printf("%d\n", a);
	return 0;
}

