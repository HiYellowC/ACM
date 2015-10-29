#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Block {
	int h, c, a;
};

Block block[410];

bool cmp(Block x, Block y) {
	return x.a < y.a;
}

int dp[40010];

void comp(int dex) {
	for(int i = block[dex].h; i <= block[dex].a; i++)
		dp[i] = max(dp[i], dp[i - block[dex].h] + block[dex].h);
}

void zero(int v, int w) {
	for(int i = v; i >= w; i--)
		dp[i] = max(dp[i], dp[i - w] + w);
}

void fun(int dex) {
	if(block[dex].h * block[dex].c >= block[dex].a)
		comp(dex);
	else {
		int k = 1; 
		while(k < block[dex].c) {
			zero(block[dex].a, k * block[dex].h);
			block[dex].c -= k;
			k *= 2;
		}
		zero(block[dex].a, block[dex].c * block[dex].h);
	}
}

int main() {
	int K;
	while(~scanf("%d", &K)) {
		for(int i = 1; i <= K; i++)
			scanf("%d%d%d", &block[i].h, &block[i].a, &block[i].c);
		sort(block + 1, block + K + 1, cmp);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= K; i++) {
			fun(i);
		}
		int ans = 0;
		for(int i = 0; i <= block[K].a; i++)
			ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}

