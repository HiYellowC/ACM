#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-10
using namespace std;

const int MAXN = 200;
int n;
int cCnt, curCnt;

struct point {
	double x, y;
};
point points[MAXN], p[MAXN], q[MAXN];

void Init() {
	int i;
	for(i = 1; i <= n; i++)
		p[i] = points[i];
	p[n + 1] = p[1];
	p[0] = p[n];
	cCnt = n;
}

void getline(point x, point y, double &a, double &b, double &c) {
	a = y.y - x.y;
	b = x.x - y.x;
	c = y.x * x.y - x.x * y.y;
}

point intersect(point x, point y, double a, double b, double c) {
	double u = fabs(a * x.x + b * x.y + c);
	double v = fabs(a * y.x + b * y.y + c);
	point pt;
	pt.x = (x.x * v + y.x * u) / (u + v);
	pt.y = (x.y * v + y.y * u) / (u + v);
	return pt;
}

void cur(double a, double b, double c) {
	curCnt = 0;
	int i;
	for(i = 1; i <= cCnt; i++) {
		if(a * p[i].x + b * p[i].y + c >= 0)
			q[++curCnt] = p[i];
		else {
			if(a * p[i - 1].x + b * p[i - 1].y + c > 0)
				q[++curCnt] = intersect(p[i], p[i - 1], a, b, c);
			if(a * p[i + 1].x + b * p[i + 1].y + c > 0)
				q[++curCnt] = intersect(p[i], p[i + 1], a, b, c);
		}
	}
	for(i = 1; i <= curCnt; i++)
		p[i] = q[i];
	p[curCnt + 1] = q[1];
	p[0] = p[curCnt];
	cCnt = curCnt;
}

void solve() {
	Init();
	int i, k;
	for(i = 1; i <= n; i++) {
		double a, b, c;
		getline(points[i], points[i + 1], a, b, c);
		cur(a, b, c);
		printf("i: %d\n", i);
		printf("a: %lf b: %lf c: %lf\n", a, b, c);
		printf("---------------cCnt: %d----------------\n", cCnt);
		for(k = 1; k <= cCnt; k++)
			printf("k: %d  x: %lf  y: %lf\n", k, p[k].x, p[k].y);
		printf("---------------------------------------\n");
	}
	double area = 0;
	printf("cCnt: %d\n", cCnt);
	for(i = 1; i <= cCnt; i++) {
		printf("i: %d x: %lf y: %lf\n", i, p[i].x, p[i].y);
		area += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
	}
	area = fabs(area / 2);
	printf("area: %lf\n", area);
}

int main() {
	while(~scanf("%d", &n)) {
		if(n == 0)
			break;
		int i;
		for(i = 1; i <= n; i++)
			scanf("%lf%lf", &points[i].x, &points[i].y);
		/*for(i = 1; i <= (n + 1) / 2; i++) {
			point temp;
			temp = points[i];
			points[i] = points[n - i + 1];
			points[n - i + 1] = temp;
		}*/
		points[n + 1] = points[1];
		solve();
	}
	return 0;
}
