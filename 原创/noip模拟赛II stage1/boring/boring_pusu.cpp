#include <cstdio>

#ifdef unix
#define LL "%lld"
#else
#define LL "%I64d"
#endif

int main(void) {
	long long a = 1, b, n; scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		b = ((long long) a * a + 1ll) % 1200007, a = b;
	}
	printf(LL "\n", a);
	return 0;
}

