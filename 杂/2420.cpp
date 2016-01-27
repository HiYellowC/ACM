#include <stdio.h>
#include <math.h>
#define Max 110
#define P 1e-10

double x[Max], y[Max];
int N;

double get_dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int i, k, j;
	double sum_of_x, sum_of_y;
	double max_of_x, max_of_y;
	double min_of_x, min_of_y;
	double x_now, y_now;
	double x_add, y_add;
	double step;
	double dis, min;
	int con[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
	sum_of_x = sum_of_y = 0;
	max_of_x = max_of_y = 0;
	min_of_x = min_of_y = 99999;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%lf%lf", &x[i], &y[i]);
		sum_of_x += x[i], sum_of_y += y[i];
		if(x[i] > max_of_x)
			max_of_x = x[i];
		if(x[i] < min_of_x)
			min_of_x = x[i];
		if(y[i] > max_of_y)
			max_of_y = y[i];
		if(y[i] < min_of_y)
			min_of_y = y[i];
	}
	x_now = sum_of_x / N;
	y_now = sum_of_y / N;
	step = (max_of_x - min_of_x) + (max_of_y - min_of_y);
	while(step > P) {
		min = INF;
		for(i = 0; i < 4; i++) {
			dis = 0;
			x_add = x_now + con[i][0] * step;
			y_add = y_now + con[i][1] * step;
			for(k = 0; k < N; k++)
				dis += get_dis(x_add, y_add, x[k], y[k]);
			if(min > dis) {
				min = dis;
				j = i;
			}
		}
		dis = 0;
		for(i = 0; i < N; i++)
			dis += get_dis(x_now, y_now, x[i], y[i]);
		if(min < dis)
			x_now = x_now + con[j][0] * step, y_now = y_now + con[j][1] * step;
		else
			step /= 2;
	}
	printf("%.0lf\n", min);
	return 0;
}
