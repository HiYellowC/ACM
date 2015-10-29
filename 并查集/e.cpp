#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define Max 1010
using namespace std;

int n, d;
int px[Max], py[Max];
int fa[Max], son[Max];
bool vis[Max];

int GetFa(int x) {
	return x == fa[x] ? x : GetFa(fa[x]);
}

double GetDis(int x1, int y1, int x2, int y2) {
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return pow((double)(x * x + y * y), 0.5);
}

void Join(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	if(xx == yy) return ;
	if(son[xx] > son[yy]) {
		fa[yy] = xx;
		son[xx] += son[yy];
	}
	else {
		fa[xx] = yy;
		son[yy] += son[xx];
	}
}

void Union(int x) {
	vis[x] = true;
	int xx = GetFa(x);
	for(int i = 1; i <= n; i++)
		if(vis[i] && GetDis(px[x], py[x], px[i], py[i]) <= (double)d)
			Join(i, x);
}

bool Check(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	return xx == yy;
}

int main() {
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++)
		fa[i] = i, son[i] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &px[i], &py[i]);
	char str[2];
	int x, y;
	while(~scanf("%s%d", str, &x)) {
		if(str[0] == 'O')
			Union(x);
		else {
			scanf("%d", &y);
			if(Check(x, y))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
		/*for(int k = 1; k <= 4; k++)
			printf("fa%d: %d ", k, GetFa(k));
		printf("\n");*/
	}
	return 0;
}
