#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class WhichDay {public:
	#define M(c,b) (a[i][0] == c && a[i][1] == b)
	string getDay(std::vector<string> a) {
		bool hash[8] = {0};
		for (int i = 0; i < 6; i++) {
			if (a[i][0] == 'S' && a[i][1] == 'u')
				hash[0] = true;
			if (a[i][0] == 'M' && a[i][1] == 'o')
				hash[1] = true;
			if (M('T', 'u'))
				hash[2] = true;
			if (M('W', 'e')) hash[3] = true;
			if (M('T', 'h')) hash[4] = true;
			if (M('F', 'r')) hash[5] = true;
			if (M('S', 'a')) hash[6] = true;
		}
		int k = 0;
		for (int i = 0; i <= 6; i++) if (!hash[i]) k = i;
		if (k == 0) return "Sunday";
		if (k == 1) return "Monday";
		if (k == 2) return "Tuesday";
		if (k == 3) return "Wednesday";
		if (k == 4) return "Thursday";
		if (k == 5) return "Friday";
		if (k == 6) return "Saturday";
	}
};
int main(void) {
	return 0;
}

