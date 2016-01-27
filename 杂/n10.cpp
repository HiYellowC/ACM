#include <stdio.h>
#include <string.h>

int r, c;
int res;
int high[102][102];
int ans[102][102];
int cur[4][2] = {0, 1, 0 , -1, 1, 0, -1, 0};

int dp(int a, int b) {
	int & n = ans[a][b];
	if(n > 0)
		return n;
	n = 1;
	int i, k;
	for(i = 0; i < 4; i++)
		if(a + cur[i][0] <= r && b + cur[i][1] <= c && high[a + cur[i][0]][b + cur[i][1]] > high[a][b]) {
			int num = dp(a + cur[i][0], b + cur[i][1]);
			n = num + 1 > n ? num + 1 : n;
		}
	return n;
}

int main() {
	int total;
	int i, k, num;
	scanf("%d", &total);
	while(total--) {
		res = 0;
		memset(ans, 0, sizeof(ans));
		scanf("%d%d", &r, &c);
		for(i = 1; i <= r; i++)
			for(k = 1; k <= c; k++)
				scanf("%d", &high[i][k]);
		for(i = 1; i <= r; i++)
			for(k = 1; k <= c; k++) {
				num = dp(i, k);
				res = res > num ? res : num;
			}
		printf("%d\n", res);
	}
	return 0;
}
