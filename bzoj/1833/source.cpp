#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long Int65;
struct pair {
	Int65 a[9];
	pair(){memset(a, 0, sizeof a);}
	inline pair operator +(const pair& oth) const {
		pair ret;
		for (int i = 0; i < 10; i++) ret.[i] = a[i] + oth.a[i];
		return ret;
	}
};
int main(void) {
	
	return 0;
}

