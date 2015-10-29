#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAXN 125
using namespace std;

int n, k;
string ma[3];
bool d[3][MAXN][MAXN];
bool dp[3][MAXN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);	
		memset(dp, 0, sizeof(dp));
		memset(d, 0, sizeof(d));
		for(int i = 0; i < 3; i++) cin >> ma[i];
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				if(ma[i][j] <= 'Z' && ma[i][j] >= 'A')
					for(int k = j, t = 0; k >= 0; k -=2, t++)
						d[i][k][t] = 1;
		for(int i = 0; i < 3; i++) dp[i][0] = ('s' == ma[i][0]);
		for(int j = 0; j < n - 1; j++) {
			for(int i = 0; i < 3; i++) {
				if(dp[i][j]) {
					if(d[i][j + 1][j]) continue;
					for(int k = 0; k < 3; k++)
						if(d[k][j + 1][j] == 0 && d[k][j + 1][j + 1] == 0 && abs(k - i) <= 1) dp[k][j + 1] = 1;
				}	
			}	
		}
		bool ans = 0;
		for(int i = 0; i < 3; i++) ans |= dp[i][n - 1];
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
