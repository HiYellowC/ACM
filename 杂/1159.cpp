#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[1010], str2[1010];
int dp[1010][1010];

int main() {
	while(~scanf("%s%s", str1 + 1, str2 + 1)) {
		int len1 = strlen(str1 + 1);
		int len2 = strlen(str2 + 1);
		for(int i = 1; i <= len1; i++)
			for(int k = 1; k <= len2; k++) {
				if(str1[i] == str2[k])
					dp[i][k] = 1 + dp[i - 1][k - 1];
				else
					dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
			}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}
