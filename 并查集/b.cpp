#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 50010
using namespace std;

int n, k;
int fa[Max], rank[Max];

int GetFa(int x) {
	int xx = fa[x];
	if(xx == x) return x;
	int par = GetFa(xx);
	fa[x] = par;
	rank[x] = (rank[x] + rank[xx]) % 3;
	return par;
}

bool IsTrue(int d, int x, int y) {
	if(x > n || y > n || (d == 2 && x == y)) return false;
	int xx = GetFa(x);
	int yy = GetFa(y);
	//printf("xx: %d yy: %d\n", xx, yy);
	if(xx != yy) return true;
	if((rank[y] - rank[x] + 3) % 3 == d - 1) return true;
	return false;
}

void Union(int d, int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	if(xx == yy) return ;
	fa[yy] = xx;
	rank[yy] = (rank[x] + d - 1 - rank[y] + 3) % 3;
}

int main() {
	int d, x, y;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		scanf("%d%d%d", &d, &x, &y);
		if(IsTrue(d, x, y))
			Union(d, x, y);
		else
			ans++;
		//printf("fa1: %d fa2: %d fa3: %d\n", fa[1], fa[2], fa[3]);
		//printf("rk1: %d rk2: %d rk3: %d\n", rank[1], rank[2], rank[3]);
	}
	printf("%d\n", ans);
	return 0;
}
