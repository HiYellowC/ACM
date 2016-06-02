#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 510;

LL a[MAXN][MAXN];

int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf("%lld", &a[i][j]);
			a[i][j] += a[i - 1][j];
		}
	LL Max = 0x8000000000000000;
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			LL con = 0;
			for(int k = 1; k <= m; k++) {
				con += (a[j][k] - a[i][k]);	
				Max = max(con, Max);
				if(con < 0) con = 0;
			}
		}
	printf("%lld\n", Max);
	return 0;
}
