#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double xx1, xx2, yy1, yy2;
double maxv, t;
double vx, vy, wx, wy;

struct liang {
	double x, y;
	friend double operator * (liang a, liang b) {
		return a.x * b.x + a.y * b.y;	
	}
	double len() {
		return sqrt(x * x + y * y);	
	}
};

int main() {
	scanf("%lf%lf%lf%lf", &xx1, &yy1, &xx2, &yy2);
	scanf("%lf%lf", &maxv, &t);
	scanf("%lf%lf", &vx, &vy);
	scanf("%lf%lf", &wx, &wy);
	liang xtox = (liang){xx2 - xx1, yy2 - yy1};
	liang windv = (liang){vx, vy};
	double jiao = acos(xtox * windv / xtox.len() / windv.len());
	double windx = sin(jiao) * windv.len();	
	double windy = cos(jiao) * windv.len();
	double tox = sqrt(maxv * maxv - windx * windx) + windy;
	double t1 = xtox.len() / tox;
	printf("%lf\n", t1);
	return 0;
}
