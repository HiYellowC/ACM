#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int state[150];
long long dp[12][1 << 11];
int num[12];
int n, m;
int p;

bool Check(int x) {
	int i;
	bool flag = 1;
	for(i = 0; i < m; i++)
		if(x & (1 << i))
			if(i + 1 < m && x & (1 << (i + 1)))
				i++;
			else {
				flag = 0;
				break;
			}
	return flag;
}

void Init() {
	int i;
	p = 0;
	memset(dp, 0, sizeof(dp));
	for(i = 0; i < (1 << m); i++)
		if(Check(i))
			state[p++] = i;
}

void fun() {
	int i;
	num[1] = 1;
	for(i = 2; i <= 11; i++)
		num[i] = num[i - 1] << 1 | 1;
}

int main() {
	int i, k, j;
	fun();
	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m)
			break;
		Init();
		for(i = 0; i < p; i++) {
			dp[1][state[i]] = 1;
		}
		for(i = 2; i <= n; i++)
			for(k = 0; k < (1 << m); k++)
				for(j = 0; j < p; j++)
					if(!(~k & state[j])) {
						int s = ~k & num[m];
						dp[i][s | state[j]] += dp[i - 1][k];
					}
		printf("%lld\n", dp[n][(1 << m) - 1]);
	}
	return 0;
}
