#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 1010;

char str1[MAXN], str2[MAXN];
int dp[MAXN][10][10];

int main() {
	while(~scanf("%s%s", str1, str2)) {
		int len = strlen(str1);
		memset(dp, INF, sizeof(dp));
		dp[0][0][0] = 0;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < 10; j++)
				for(int k = 0; k < 10; k++) {
					int s = (str2[i] - str1[i] - j + 20) % 10;
					for(int a = 0; a <= s; a++)
						for(int b = 0; b <= a; b++)
							dp[i + 1][(k + a) % 10][b] = min(dp[i + 1][(k + a) % 10][b], dp[i][j][k] + s);
					s = (10 - s) % 10;
					for(int a = 0; a <= s; a++)
						for(int b = 0; b <= a; b++)
							dp[i + 1][(k - a + 10) % 10][(10 - b) % 10] = min(dp[i + 1][(k - a + 10) % 10][(10 - b) % 10], dp[i][j][k] + s);
				}
		printf("%d\n", dp[len][0][0]);
	}
	return 0;
}
