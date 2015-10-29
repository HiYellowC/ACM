#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 30010
using namespace std;

int par[Max], son[Max];

int Getfa(int x) {
	return x == par[x] ? x : Getfa(par[x]);
}

void Join(int a, int b) {
	int aa = Getfa(a);
	int bb = Getfa(b);
	if(aa == bb) return ;
	par[bb] = aa;
	son[aa] += son[bb];
	son[bb] = 0;
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m) break;
		for(int i = 1; i <= n; i++) 
			par[i] = i, son[i] = 1;
		int k, a, b;
		for(int i = 1; i <= m; i++) {
			scanf("%d", &k);
			if(k > 0)
				scanf("%d", &a);
			for(int j = 2; j <= k; j++) {
				scanf("%d", &b);
				Join(a + 1, b + 1);
			}
		}
		printf("%d\n", son[Getfa(1)]);
	}
	return 0;
}
