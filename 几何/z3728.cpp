#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1);

struct Lpoint {double x, y;};
struct Ldir{double dx, dy;};
struct Lline{Lpoint p; Ldir dir;};

double Rm, R, r, xx, yy, vx, vy;

void format(Lline ln, double & A, double & B, double & C) {
	A = ln.dir.dy;
	B = -ln.dir.dx;
	C = ln.p.y * ln.dir.dx - ln.p.x * ln.dir.dy;
}

double p2ldis(Lpoint a, Lline ln) {
	double A, B, C;
	format(ln, A, B, C);
	return (fabs(A * a.x + B * a.y + C) / sqrt(A * A + B * B));
}

double fun1(double dis) {
	dis = 2 * sqrt((R + r) * (R + r) - dis * dis);	
	return dis / sqrt(vx * vx + vy * vy);
}

double fun2(double dis) {
	dis = sqrt((R + r) * (R + r) - dis * dis) - sqrt((Rm + r) * (Rm + r) - dis * dis);
	dis *= 2;
	return dis / sqrt(vx * vx + vy * vy);
}

int main() {
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf", &Rm, &R, &r, &xx, &yy, &vx, &vy)) {
		Lpoint a = (Lpoint){xx, yy};
		Ldir dir = (Ldir){vx, vy};
		Lline line;
		line.p = a, line.dir = dir;
		Lpoint b = (Lpoint){0, 0};
		double dis = p2ldis(b, line);
		double ans;
		double flag = -xx * vx - yy * vy;
		if(dis > r + R || flag < 0) ans = 0;
		else if(dis > Rm + r) ans = fun1(dis);
		else ans = fun2(dis);
		printf("%.3lf\n", ans);
	}
	return 0;
}
