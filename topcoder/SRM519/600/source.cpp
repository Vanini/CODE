#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;
class TreeTeleports {public:
	typedef long long Int64;
	inline void ScanInt(string s, Int64 a[]) {
		int l = 0;
		for (Int64 i = 0; i < 4; i ++) {
			Int64 r = 0;int n = s.length();
			while (l < n && !isdigit(s[l])) l++;
			while (l < n &&  isdigit(s[l])) r = r * 10 + s[l] -'0', l++;
			a[i] = r;
		}
	}
	struct PoInt64 {
		Int64 x, y;
		void Set(Int64 _x, Int64 _y) {
			x = _x, y = _y;
		}
	};
	inline Int64 abs(Int64 a) {return (a< 0) ? -a : a;}
	int shortestDistance(int x1, int y1, int x2, int y2, vector<string> T) {
		Int64 c[10][10]; PoInt64 a[10]; bool hash[10][10];
		memset(c, 0, sizeof c); memset(hash, 0, sizeof hash); memset(a, 0, sizeof a);
		hash[3][4] = hash[4][3] = hash[5][6] = hash[6][5] = hash[7][8] = hash[8][7] = true;
		a[1].Set(x1, y1); a[2].Set(x2, y2);
		Int64 l = 2;
		for (Int64 i = 0; i < 3; i++) {
			Int64 ret[5] = {0};
			ScanInt(T[i], ret);
			a[++l].Set(ret[0], ret[1]);
			a[++l].Set(ret[2], ret[3]);
		}
		for (Int64 i = 1; i <= l; i++)
			for (Int64 j = 1; j <= l; j++) if (i != j) {
				if (hash[i][j])
					c[i][j] = 10;
				else
					c[i][j] = abs(a[i].x - a[j].x) + abs(a[j].y - a[i].y);
			}
		for (Int64 k = 1; k <= l; k++)
			for (Int64 i = 1; i <= l; i++)
				for (Int64 j = 1; j <= l; j++)
					c[i][j] = std::min(c[i][j], c[i][k] + c[k][j]);
		return c[1][2];
	}
};
int main(void) {
	return 0;
}

