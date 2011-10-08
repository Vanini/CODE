#include <cstdio>
#include <algorithm>
using namespace std;
class BinaryCards {public:
	typedef long long Int64;
	Int64 largestNumber(Int64 a, Int64 b) {
		Int64 c = a ^ b;
		int l = 0;
		while (c) l++, c>>=1;
		return b | ((1ll << l) - 1ll);
	}
};
int main(void){
	BinaryCards a;
	printf("%lld\n", a.largestNumber(35ll, 38ll));
	return 0;
}
