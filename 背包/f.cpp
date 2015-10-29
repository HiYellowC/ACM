#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define Max 10010
using namespace std;

int dp[Max];

vector <int> V[Max];

int main() {
	int v;
	while(~scanf("%d", &v)) {
		int n;
		scanf("%d", &n);
		int val;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &val);
			for(int k = v; k >= val; k--) {
				if(dp[k - val] + val >= dp[k]) {
					V[k].clear();
					for(int j = 0; j < V[k - val].size(); j++)
						V[k].push_back(V[k - val][j]);
					V[k].push_back(val);
					dp[k] = dp[k - val] + val;	
				}	
			}
		}
		for(int i = 0; i < V[v].size(); i++)
			printf("%d ", V[v][i]);
		printf("sum:%d\n", dp[v]);
		for(int i = 0; i <= v; i++)
			V[i].clear();
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
