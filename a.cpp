#include <bits/stdc++.h>
using namespace std;

double Min, Max;
const double eps = 1e-9;


int main() {
	int x, y;
	while(~scanf("%d%d", &x, &y)) {
		if(x > y) {
			printf("-1\n");
			continue;
		}	
		Max = (double)(y + 1 - eps) / (double)x;
		double tmp = 1;
		int cnt = (int) x - 1;
		for(int i = 1; i <= (int)x; i++) {
			double t = i * Max;
			int u = (int) (t - tmp);
			tmp += u;
			tmp = tmp * (i + 1) / i;
			cnt += u;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
