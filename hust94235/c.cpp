#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[310];
char word[610][30];
int dp[310];

int main() {
	int w, l;
	while(~scanf("%d%d", &w, &l)) {
		scanf("%s", str);
		for(int i = 1; i <= w; i++) scanf("%s", word[i]);
		dp[l] = 0;
		for(int i = l - 1; i >= 0; i--) {
			dp[i] = dp[i + 1] + 1;
			for(int k = 1; k <= w; k++) {
				int len = strlen(word[k]);
				if(len <= l - i && word[k][0] == str[i]) {
					bool flag = false;
					int ans = 0;
					int wp, sp;
					wp = 0, sp = i;
					while(sp <= l - 1 && wp < len) {
						if(word[k][wp] == str[sp]) wp++, sp++;
						else sp++, ans++;
					}
					if(wp == len) flag = true;
					if(flag) dp[i] = min(dp[i], dp[sp] + ans);
				}
			}
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}
