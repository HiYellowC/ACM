#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 310;

int a[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, num;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			a[num]++;
		}
		for(int i = 1; i <= 300; i++) a[i] += a[i - 1];
		int total = 0;
		for(int i = 1; i <= 300; i++)
			if(a[i] - a[i - 1]) total += (a[i] - a[i - 1]) * (a[i - 1]);
		double ans = (double)total / (double)n / (double)(n - 1);
		printf("%.6lf\n", ans);
	}
	return 0;
}

