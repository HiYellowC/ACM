#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 10010
using namespace std;

int maxn[Max], tmp[Max];
int maxid[Max], tmpid[Max];
int Start[Max], Next[Max * 2], Length[Max * 2], End[Max * 2];
int dex;

void Init() {
	dex = 0;
	memset(Start, 0, sizeof(Start));
}

void BuildG(int a, int b, int c) {
	Next[++dex] = Start[a];
	Start[a] = dex;
	End[dex] = b;
	Length[dex] = c;
}

void dfs1(int x, int fa) {
	maxn[x] = tmp[x] = 0;
	for(int i = Start[x]; i; i = Next[i]) {
		int to = End[i];
		if(to != fa) {
			dfs1(to, x);
			if(maxn[to] + Length[i] > maxn[x])
				tmp[x] = maxn[x], tmpid[x] = maxid[x], maxn[x] = maxn[to] + Length[i], maxid[x] = to;
			else if(maxn[to] + Length[i] > tmp[x])
				tmp[x] = maxn[to] + Length[i], tmpid[x] = to;
		}
	}
}

void dfs2(int x, int fa) {
	for(int i = Start[x]; i; i = Next[i]) {
		int to = End[i];
		if(to == fa) continue;
		if(to == maxid[x]) {
			if(tmp[x] + Length[i] > maxn[to])
				tmp[to] = maxn[to], tmpid[to] = maxid[to], maxn[to] = tmp[x] + Length[i], maxid[to] = x;
			else if(tmp[x] + Length[i] > tmp[to])
				tmp[to] = tmp[x] + Length[i], tmpid[to] = x;
		}
		else {
			if(maxn[x] + Length[i] > maxn[to])
				tmp[to] = maxn[to], tmpid[to] = maxid[to], maxn[to] = maxn[x] + Length[i], maxid[to] = x;
			else if(maxn[x] + Length[i] > tmp[to])
				tmp[to] = maxn[x] + Length[i], tmpid[to] = x;
		}
		dfs2(to, x);
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int a, b;
		Init();
		for(int i = 2; i <= n; i++) {
			scanf("%d%d", &a, &b);
			BuildG(i, a, b);
			BuildG(a, i, b);
		}	
		dfs1(1, -1);
		dfs2(1, -1);
		for(int i = 1; i <= n; i++)
			printf("%d\n", maxn[i]);
	}
	return 0;
}
