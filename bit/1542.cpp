#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
using namespace std;

struct Line {
	double y1, y2;
	double x;
	int flag;
};
Line line[MAXN * 2];

struct Tree {
	double y1, y2;
	double x;
	int flag;
};
Tree tree[MAXN * 8];

double y[MAXN * 2];
int dex;

bool cmp(Line a, Line b) {
	return a.x < b.x;
}

void Build(int l, int r, int i) {
	if(l == r) {
		tree[i].y1 = y[dex++];
		tree[i].y2 = y[dex];	
		tree[i].flag = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, i << 1);
	Build(mid + 1, r, i << 1 | 1);
	tree[i].y1 = tree[i << 1].y1;
	tree[i].y2 = tree[i << 1 | 1].y2;
	tree[i].flag = 0;
}

double Update(double x, double y1, double y2, int flag, int l, int r, int i) {
	if(l == r) {
		double ans = 0;
		if(tree[i].flag > 0) ans += (y2 - y1) * (x - tree[i].x);
		tree[i].x = x;
		tree[i].flag += flag;
		return ans;
	}	
	int mid = (l + r) >> 1;
	if(y2 <= tree[i << 1].y2) return Update(x, y1, y2, flag, l, mid, i << 1);
	else if(y1 >= tree[i << 1 | 1].y1) return Update(x, y1, y2, flag, mid + 1, r, i << 1 | 1);
	else return Update(x, y1, tree[i << 1].y2, flag, l, mid, i << 1) + Update(x, tree[i << 1 | 1].y1, y2, flag, mid + 1, r, i << 1 | 1);
}

int main() {
	int n, tt = 1;
	while(~scanf("%d", &n) && n) {
		double x1, x2, y1, y2;
		dex = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			y[dex++] = y1, y[dex++] = y2;
			line[i << 1].y1 = y1, line[i << 1].y2 = y2, line[i << 1].x = x1, line[i << 1].flag = 1;	
			line[i << 1 | 1].y1 = y1, line[i << 1 | 1].y2 = y2, line[i << 1 | 1].x = x2, line[i << 1 | 1].flag = -1;	
		}
		sort(y, y + dex);
		dex = 0;
		Build(1, 2 * n - 1, 1);
		double ans = 0;
		sort(line, line + 2 * n, cmp);
		for(int i = 0; i < 2 * n; i++) {
			ans += Update(line[i].x, line[i].y1, line[i].y2, line[i].flag, 1, 2 * n - 1, 1);	
		}
		printf("Test case #%d\n", tt++);	
		printf("Total explored area: %.2lf\n\n", ans);
	}
	return 0;
}
