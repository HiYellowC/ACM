#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

char s[300010];
int pos[30];
int p[30];
LL ans[30];

int main() {
	scanf("%s", s);
	memset(pos, -1, sizeof(pos));
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		pos[s[i] - 'a'] = i;
		int cnt = 0;
		for(int j = 0; j < 26; j++)
			if(pos[j] != -1)
				p[cnt++] = pos[j];
		sort(p, p + cnt);
		for(int j = 1; j < cnt; j++)
			ans[cnt - j] += p[j] - p[j - 1];
		ans[cnt] += p[0] + 1;
	}
	for(int i = 26; i >= 1; i--)
		if(ans[i]) {
			printf("%d\n", i);
			for(int j = 1; j <= i; j++)
				printf("%I64d\n", ans[j]);
			return 0;
		}
	return 0;
}
