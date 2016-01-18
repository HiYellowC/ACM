#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int fa[MAXN], son[MAXN];

int getfa(int x) {
	return x == fa[x] ? x : getfa(fa[x]);
}

void Join(int x, int y) {
	int xx = getfa(x);
	int yy = getfa(y);
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
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) fa[i] = i, son[i] = 1;
		int a, b, c;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if(c == 0) Join(a, b);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(getfa(i) == i) {
				if(son[i] % 2) ans ^= son[i];	
			}	
		}
		printf("%d\n", ans);
	}
	return 0;
}
