#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		double p, q;
		scanf("%lf%lf", &p, &q);
		double ans1 = (double)x * (1 - q) + (double)(x + y) * q * p * (1 - p) + (double)(x + y) * q * p * p;
		double ans2 = (double)y * q + (double)(x + y) * (1 - q) * p * (1 - p) + (double)(x + y) * (1 - q) * p * p;
		if(ans1 > ans2) printf("tiger %.4lf\n", ans1);
		else printf("wolf %.4lf\n", ans2);
	}
	return 0;
}
