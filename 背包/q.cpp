#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> M;
vector <int> V[110];
int dp[100010];

int fun(int dex) {
	int sum = 0;
	for(int i = 0; i < V[dex].size(); i++)
		sum += V[dex][i];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < V[dex].size(); i++)
		for(int k = sum / 2; k >= V[dex][i]; k--)
			dp[k] = max(dp[k], dp[k - V[dex][i]] + V[dex][i]);
	return sum - dp[sum / 2];
}

int main() {
	int m, n;
	while(~scanf("%d%d", &m, &n)) {
		if(m == 0 || n == 0) break;
		M.clear();
		string str;
		for(int i = 1; i <= m; i++) {
			cin >> str;
			M[str] = i;
		}
		int num;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			cin >> str;
			V[M[str]].push_back(num);
		}
		int ans = 0;
		for(int i = 1; i <= m; i++)
			ans += fun(i);
		for(int i = 1; i <= m; i++)
			V[i].clear();
		printf("%d\n", ans);
	}
	return 0;
}
