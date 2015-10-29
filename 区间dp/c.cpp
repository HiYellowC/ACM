#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[110];
int dp[110][110];

bool check(char a, char b) {
	if(a == '(' && b == ')')
		return true;
	if(a == '[' && b == ']')
		return true;
	return false;
}

int main() {
	while(~scanf("%s", str)) {
		if(strcmp(str, "end") == 0) break;
		memset(dp, 0, sizeof(dp));
		int len = strlen(str);
		for(int i = 2; i <= len; i++)
			for(int k = 0; k <= len - i; k++) {
				if(check(str[k], str[k + i - 1]))
					dp[k][k + i - 1] = dp[k + 1][k + i - 2] + 2;
				for(int j = k; j < k + i - 1; j++)
					dp[k][k + i - 1] = max(dp[k][k + i - 1], dp[k][j] + dp[j + 1][k + i - 1]);
			}
		printf("%d\n", dp[0][len - 1]);
	}
	return 0;
}
