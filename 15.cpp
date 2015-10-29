#include <stdio.h>
#include <string.h>

int dp[101][101];

int main() {
	int total;
	char str[101];
	int i, j, k, l, len;
	scanf("%d", &total);
	while(total--) {
		scanf("%s", str);
		len = strlen(str);
		for(l = 1; l <= len; l++) {
			for(i = 0; i + l<= len; i++) {
				j = i + l - 1;
				if(i == j)
					dp[i][j] = 1;
				else
					dp[i][j] = 100;
				if((str[j] == ')' && str[i] == '(') || (str[j] == ']' && str[i] == '['))
					dp[i][j] = dp[i + 1][j - 1];
				for(k = i; k < j; k++)
					if(dp[i][k] + dp[k + 1][j] < dp[i][j])
						dp[i][j] = dp[i][k] + dp[k + 1][j];
			}
		}
		printf("%d\n", dp[0][len - 1]);
	}
	return 0;
}
