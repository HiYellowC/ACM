#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

char str[MAXN];

bool solve() {
	int len = strlen(str);
	if(len & 1) return false;
	for(int i = 0; i < len / 2; i++)
		if(str[i] != str[len / 2 + i]) return false;
	return true;
}

int main() {
	while(~scanf("%s", str)) {
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
