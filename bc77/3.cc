#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 510;

int N, M;
char Map[MAXN][MAXN];

int fa[MAXN * MAXN], son[MAXN * MAXN];
int cnt[8][2] = {1, 1, 1, 0, 1, -1, 0, 1, 0, -1, -1, 1, -1, 0, -1, -1};

struct Node {
	bool OK[MAXN];
};

Node node[MAXN * MAXN];


bool legal(int x, int y) {
	if(x < 0 || x >= N) return false;
	if(y < 0 || y >= M) return false;
	return true;
}

int getFather(int x) {
	return x == fa[x] ? x : getFather(fa[x]);
}

bool Join(int x, int y) {
	bool flag = true;
	int xx = getFather(x);
	int yy = getFather(y);
	if(son[xx] > son[yy]) {
		for(int i = 0; i < M; i++) {node[xx].OK[i] |= node[yy].OK[i]; if(node[xx].OK[i] == false) flag = false;}
		son[xx] += son[yy];
		fa[yy] = xx;
	}
	else {
		for(int i = 0; i < M; i++) {node[yy].OK[i] |= node[xx].OK[i]; if(node[yy].OK[i] == false) flag = false;}
		son[yy] += son[xx];
		fa[xx] = yy;
	}
	return flag;
}

bool solve(int x, int y) {
	bool flag = false;
	for(int i = 0; i < 8; i++)
		if(legal(x + cnt[i][0], y + cnt[i][1]) && Map[x + cnt[i][0]][y + cnt[i][1]] == '1') {
			flag = Join(x * M + y, (x + cnt[i][0]) * M + y + cnt[i][1]);
			if(flag) return true;
		}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) scanf("%s", Map[i]);
		for(int i = 0; i < N * M; i++) son[i] = 0, fa[i] = i, memset(node[i].OK, 0, sizeof(node[i].OK)), node[i].OK[i % M] = true;
		bool flag = false;
		for(int i = 0; i < N * M; i++)
			if(Map[i / M][i % M] == '1') {
				flag = solve(i / M, i % M);
				if(flag) break;
			}
		if(flag) printf("0\n");
		int q;
		scanf("%d", &q);
		int x, y;
		for(int i = 1; i <= q; i++) {
			scanf("%d%d", &x, &y);
			if(flag) continue;
			Map[x][y] = '1';
			flag = solve(x, y);
			if(flag) printf("%d\n", i);
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}

