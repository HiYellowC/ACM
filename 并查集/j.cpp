#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 100010
using namespace std;

typedef long long LL;

int n, m;
int fa[Max], son[Max];
LL sum[Max];

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
		sum[xx] += sum[yy];
	}
	else {
		fa[xx] = yy;
		son[yy] += son[xx];
		sum[yy] += sum[xx];
	}
}

void Move(int x, int y) {
	
}

int main() {
	int d, x, y;
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++)
			fa[i] = i, son[i] = 1, sum[i] = i;
		for(int i = 1; i <= m; i++) {
			scanf("%d", &d);
			if(d == 1) {
				scanf("%d%d", &x, &y);	
				Union(x, y);
			}
			else if(d == 2) {
				scanf("%d%d", &x, &y);	
				Move(x, y);
			}
			else {
				scanf("%d", &x);		
				printf("%d %lld\n", son[GetFa(x)], sum[GetFa(x)]);
			}
		}
	}
	return 0;
}
