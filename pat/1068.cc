#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int n, m;
int a[MAXN];
bool dp[MAXN][110];
vector <int> V;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, cmp);
	dp[0][0] = true;
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j];
			if(j >= a[i] && dp[i - 1][j - a[i]]) dp[i][j] = true;
		}
	if(dp[n][m]) {
		while(m) {
			if(dp[n - 1][m - a[n]]) V.push_back(a[n]), m -= a[n], n--;
			else n--;
		}	
		for(int i = 0; i < V.size(); i++) printf("%d%c", V[i], " \n"[i == (int)V.size() - 1]);
	}
	else printf("No Solution\n");
	return 0;
}
