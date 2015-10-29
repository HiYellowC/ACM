#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, p;
int Map[110];
int dp[110][65][65];
int s[110], num[110];

inline int max(int a, int b) {
	return a > b ? a : b;
}

bool check(int x) {
	if(x & (x >> 1))
		return false;
	if(x & (x >> 2))
		return false;
	return true;
}

int Count(int x) {
	int i = 1, ans = 0;
	while(i <= x) {
		if(x & i)
			ans++;
		i <<= 1;
	}
	return ans;
}

void Init() {
	int i;
	p = 0;
	memset(s, 0, sizeof(s));
	memset(num, 0, sizeof(num));
	for(i = 0; i < (1 << m); i++) {
		if(check(i)) {
			s[p] = i;
			num[p++] = Count(i);
		}
	}
}

int main() {
	char ch;
	int i, k, j, r, total;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &n, &m);
		if(!n && !m) {
			printf("0\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		memset(Map, 0, sizeof(Map));
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++) {
				cin >> ch;
				if(ch == 'H')
					Map[i] = Map[i] | (1 << (m - 1 - j));
			}
		Init();
		for(i = 0; i < p; i++)
			if(!(Map[0] & s[i]))
				dp[0][i][0] = num[i];
		for(i = 0; i < p; i++) {
			if(!(Map[1] & s[i])) {
				for(j = 0; j < p; j++) {
					if(!(s[i] & s[j]))
						dp[1][i][j] = max(dp[1][i][j], dp[0][j][0] + num[i]);
				}
			}
		}
		for(r = 2; r < n; r++)
			for(i = 0; i < p; i++)
				if(!(s[i] & Map[r]))
					for(j = 0; j < p; j++)
						if(!(s[j] & Map[r - 1]) && !(s[i] & s[j]))
							for(k = 0; k < p; k++)
								if(!(s[k] & Map[r - 2]) && !(s[k] & s[j]) && !(s[k] & s[i]))
									dp[r][i][j] = max(dp[r][i][j], dp[r - 1][j][k] + num[i]);
		int ans = 0;
		for(i = 0; i < p; i ++)
			for(j = 0; j < p; j++)
				ans = max(ans, dp[n - 1][i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
