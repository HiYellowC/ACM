#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const double eps = 1e-4;
const double pi = acos(-1);

double sumx, sumy;

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
};
Point points[10];

inline void getline(Point x,Point y,double &a,double &b,double &c){
     a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}

inline Point intersect(Point x,Point y,double a,double b,double c){
     double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    return Point( (x.x * v + y.x * u) / (u + v) , (x.y * v + y.y * u) / (u + v) );
}

double getdis(int i) {
	return sqrt((sumx - points[i].x) * (sumx - points[i].x) + (sumy - points[i].y) * (sumy - points[i].y));
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		sumx = sumy = 0.0;
		for(int i = 1; i <= 5; i++)	points[i].input(), sumx += points[i].x, sumy += points[i].y;
		sumx /= 5, sumy /= 5;
		bool flag = false;
		double dis = getdis(1);
		for(int i = 2; i <= 5; i++) {
			if(fabs(getdis(i) - dis) < eps) {
				continue;
			}
			else flag = true;
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
    return 0;
}

