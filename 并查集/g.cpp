#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 50010
using namespace std;

int fa[Max], son[Max];

int GetFa(int x) {
	return x == fa[x] ? x : GetFa(fa[x]);
}

void Union(int x, int y) {
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

int main() {
	int n, m;
	int x, y;
	int tt = 1;
	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m) break;
		for(int i = 1; i <= n; i++)
			fa[i] = i, son[i] = 1;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			Union(x, y);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(i == fa[i])
				ans++;
		printf("Case %d: %d\n", tt++, ans);
	}
	return 0;
}
