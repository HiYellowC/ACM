#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

int p[MAXN], pos[MAXN];
int T[MAXN * 3];
int dp[MAXN];

void Build(int l, int r, int i) {
	if(l == r) {
		T[i] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, i << 1);
	Build(mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int Query(int x, int l, int r, int i) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(x <= T[i << 1]) return Query(x, l, mid, i << 1);
	else return Query(x - T[i << 1], mid + 1, r, i << 1 | 1);
}

void Update(int x, int l, int r, int i) {
	if(l == r) {
		T[i] = 0;
		return ;
	}	
	int mid = (l + r) >> 1;
	if(x <= mid) Update(x, l, mid, i << 1);
	else Update(x, mid + 1, r, i << 1 | 1);
	T[i] = T[i << 1] + T[i << 1 | 1];
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		Build(1, n, 1);
		for(int i = 1; i <= n; i++) 
			scanf("%d", &p[i]);
		for(int i = n; i >= 1; i--) {
			pos[i] = Query(p[i] + 1, 1, n, 1);	
			Update(pos[i], 1, n, 1);
		}
		memset(dp, 0, sizeof(dp));
		printf("Case #%d:\n", tt++);
		int Max = 0;
		printf("1\n");
		dp[Max++] = pos[1];
		for(int i = 2; i <= n; i++) {
			int dex = lower_bound(dp, dp + Max, pos[i]) - dp;
			if(dp[dex] == 0) dp[Max++] = pos[i];
			else if(dp[dex] > pos[i]) dp[dex] = pos[i];
			printf("%d\n", Max);
		}
		printf("\n");
	}
	return 0;
}
