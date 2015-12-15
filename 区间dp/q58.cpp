#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

bool flag[MAXN][MAXN];

char str[MAXN];

int main() {
	while(~scanf("%s", str)) {
		int len = strlen(str);
		memset(flag, 0, sizeof(flag));
		for(int i = 1; i <= len; i++)
			for(int j = 0; j <= len - i; j++) {
				if(i == 1) {
					if(str[j] == 's' || str[j] == 'p' || str[j] == 'y') flag[j][j] = true;	
				}
				else {
					int s = j;
					int e = s + i - 1;
					for(int k = s; k < e; k++) if(flag[s][k] && flag[k + 1][e]) flag[s][e] = true;
					if(str[s] == '(' && str[e] == ')' && flag[s + 1][e - 1]) flag[s][e] = true;
					if(str[s] == '!' && flag[s + 1][e]) flag[s][e] = true;
					for(int k = s + 1; k < e; k++) if((str[k] == '|' || str[k] == '&') && flag[s][k - 1] && flag[k + 1][e]) flag[s][e] = true;
				}
			}
		printf("%s", str);
		if(flag[0][len - 1]) printf(" is a good string\n");
		else printf(" is not a good string\n");
	}
	return 0;
}
