#include <bits/stdc++.h>
using namespace std;

struct Cake {
	double a, b;
};

Cake cake[1010];

bool cmp(Cake x, Cake y) {
	return (x.b / x.a) > (y.b / y.a);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lf", &cake[i].a);
	for(int i = 1; i <= n; i++) scanf("%lf", &cake[i].b);
	sort(cake + 1, cake + 1 + n, cmp);
	double ans = 0;
	for(int i = 1; i <= n; i++) {
		if(m > cake[i].a) ans += cake[i].b, m -= cake[i].a;
		else {
			ans += cake[i].b / cake[i].a * m;
			break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}
