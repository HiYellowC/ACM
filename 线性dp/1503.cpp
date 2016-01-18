#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

char str1[MAXN], str2[MAXN];
int dp[MAXN][MAXN];

vector <char> V;

void fun(int x, int y) {
	if(x == 0 && y == 0) return ;
	else if(x == 0) V.push_back(str2[y]), fun(x, y - 1);
	else if(y == 0) V.push_back(str1[x]), fun(x - 1, y);	
	else if(dp[x][y] == dp[x - 1][y]) V.push_back(str1[x]), fun(x - 1, y);
	else if(dp[x][y] == dp[x][y - 1]) V.push_back(str2[y]), fun(x, y - 1);
	else V.push_back(str1[x]), fun(x - 1, y - 1);
}

int main() {
	while(~scanf("%s%s", str1 + 1, str2 + 1)) {
		memset(dp, 0, sizeof(dp));
		V.clear();
		int len1 = strlen(str1 + 1);
		int len2 = strlen(str2 + 1);
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
				if(str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		fun(len1, len2);
		for(int i = (int)V.size() - 1; i >= 0; i--) printf("%c", V[i]);
		puts("");
	}
	return 0;
}
