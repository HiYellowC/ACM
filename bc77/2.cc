#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int MAXN = 1010;
const int MOD = 1000000007;

char str[MAXN];
int con[30];
LL C[510][510];

void init() {
	for(int i = 0; i <= 500; i++) C[i][i] = C[0][i] = 1;
	for(int i = 1; i <= 500; i++)
		for(int j = i + 1; j <= 500; j++) C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % MOD;
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		memset(con, 0, sizeof(con));
		for(int i = 1; i <= len; i++) con[str[i] - 'a']++;
		int sum = 0;
		for(int i = 0; i < 26; i++) if(con[i] % 2) sum++;
		if(sum > 1) printf("0\n");
		else {
			for(int i = 0; i < 26; i++) con[i] /= 2;
			len /= 2;
			LL ans = 1;
			for(int i = 0; i < 26; i++) if(con[i]) ans = (ans * C[con[i]][len]) % MOD, len -= con[i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}

