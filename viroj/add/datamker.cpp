#include <cstdio>
#include <cstdlib>
#include <ctime>
inline void PrintInt(int Len, bool nev = false) {
	if (nev) putchar('-');
	for (int i = 1; i <= Len; i++) printf("%d", rand()%10);
}
int main(void) {
	srand(size_t(time(NULL)));
	freopen("20.in", "w", stdout);
	PrintInt(2000, true); putchar(' ');
	PrintInt(2000, true);
	return 0;
}
