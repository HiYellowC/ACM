#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

double fun(double a, double b, double c, double d) {
	return a * d - b * c;
}

double getdis(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		double ans = 0;
		scanf("%d", &n);
		int x, y, sx, sy, xx, yy;
		scanf("%d%d", &sx, &sy);
		xx = sx, yy = sy;
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			ans += 0.5 * fun(sx, sy, x, y);
			sx = x, sy = y;
		}
		ans += 0.5 * fun(sx, sy, xx, yy);
		ans = fabs(ans);
		double x1, y1, r1, x2, y2, r2;
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
		double dis = getdis(x1, y1, x2, y2);
		if(dis + min(r1, r2) < max(r1, r2) || fabs(dis + min(r1, r2) - max(r1, r2)) < eps) ans += pi * max(r1, r2) * max(r1, r2);	
		else if(dis > r1 + r2 || fabs(dis - r1 - r2) < eps) ans += pi * (r1 * r1 + r2 * r2);
		else {
			double angle1 = (r1 * r1 + dis * dis - r2 * r2)	/ 2.0 / r1 / dis;
			double angle2 = (r2 * r2 + dis * dis - r1 * r1) / 2.0 / r2 / dis;
			angle1 = acos(angle1) * 2.0, angle2 = acos(angle2) * 2.0;
			double sum = 0;
			sum += angle1 * 0.5 * r1 * r1 - 0.5 * r1 * r1 * sin(angle1);
			sum += angle2 * 0.5 * r2 * r2 - 0.5 * r2 * r2 * sin(angle2);
			ans += (pi * (r1 * r1 + r2 * r2) - sum);
		}
		ans += 10000;
		printf("Case #%d: %.2lf\n", tt++, ans);	
	}
	return 0;
}
