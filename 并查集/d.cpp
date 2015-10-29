#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 30010
using namespace std;

int fa[Max], rank[Max], son[Max];

int GetFa(int x) {
	int xx = fa[x];
	if(x == xx) return xx;
	int par = GetFa(xx);
	fa[x] = par;
	rank[x] = rank[x] + rank[xx];
	return par;
}

void Union(int x, int y) {
	int xx = GetFa(x);
	int yy = GetFa(y);
	//printf("xx: %d yy: %d\n", xx, yy);
	if(xx == yy) return ;
	rank[yy] = son[xx];
	fa[yy] = xx;
	son[xx] += son[yy];
}

int Query(int x) {
	int xx = GetFa(x);
	return son[xx] - rank[x] - 1;
}

int main() {
	for(int i = 1; i <= 30000; i++)
		fa[i] = i, son[i] = 1;
	int p;
	char str[2];
	int x, y;
	scanf("%d", &p);
	for(int i = 1; i <= p; i++) {
		scanf("%s", str);
		if(str[0] == 'M') {
			scanf("%d%d", &x, &y);	
			Union(x, y);
		}
		else {
			scanf("%d", &x);	
			printf("%d\n", Query(x));
		}
		/*for(int k = 1; k <= 6; k++)
			printf("fa%d: %d ", k, fa[k]);
		printf("\n");
		for(int k = 1; k <= 6; k++)
			printf("rank%d: %d ", k, rank[k]);
		printf("\n");
		for(int k = 1; k <= 6; k++)
			printf("son%d: %d ", k, son[k]);
		printf("\n");*/
	}
	return 0;
}
