#include <cstdio>
#include <algorithm>
#define LL "%I64d"
#define Fuck
typedef long long Int64;
class Edge {
	int y, z; Edge *next, *opt;
}*a;
inline int o(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = a * r;
		b >>= 1;
		a = a * a;
	}
	return r;
}
int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b);
	printf("%d\n", o(2, 10));

	return 0;
}
