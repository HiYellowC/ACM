#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 2010
using namespace std;

int fa[Max], rank[Max];
bool flag;

int GetFa(int x) {
	int xx = fa[x];
	if(x == xx) return xx;
	int par = GetFa(xx);
	fa[x] = par;
	rank[x] = (rank[x] + rank[xx]) % 2;
	return par;
}

bool Check(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	if(xx != yy) return false;
	if((rank[x] + rank[y]) % 2 == 1) return false;
	return true;
}

void Union(int x, int y) {
	if(Check(x, y)) {
		flag = false;
		return ;
	}
	int xx = GetFa(x);
	int yy = GetFa(y);
	fa[yy] = xx;
	rank[yy] = (rank[x] - rank[y] + 1) % 2;
}

int main() {
	int t, tt = 1;
	int n, m;
	int x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			fa[i] = i, rank[i] = 0;
		flag = true;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			if(flag)
				Union(x, y);
		}
		printf("Scenario #%d:\n", tt++);
		if(flag)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}

