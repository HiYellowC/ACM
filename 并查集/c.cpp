#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 100010
using namespace std;

int fa[Max], rank[Max];

int GetFa(int x) {
	int xx = fa[x];
	if(xx == x) return xx;
	int par = GetFa(xx);
	fa[x] = par;
	rank[x] = (rank[x] + rank[xx]) % 2;
	return par;
}

void Union(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	if(xx == yy) return ;
	fa[xx] = yy;
	rank[xx] = (rank[y] + 1 - rank[x]) % 2;
}

void Check(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	if(xx != yy)
		printf("Not sure yet.\n");
	else if(rank[x] == rank[y])
		printf("In the same gang.\n");
	else
		printf("In different gangs.\n");
}

int main() {
	int t;
	int n, m;
	int x, y;
	char str[2];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			fa[i] = i, rank[i] = 0;
		for(int i = 1; i <= m; i++) {
			scanf("%s%d%d", str, &x, &y);	
			if(str[0] == 'A')
				Check(x, y);
			else
				Union(x, y);
		}
	}
	return 0;
}
