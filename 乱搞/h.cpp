#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

char str[15];
char ans[15];
bool vis[15];

void dfs(int cur, int len) {
	if(cur == len) {
		ans[len] = 0;
		printf("%s\n", ans);
		return ;
	}
	bool flag = false;
	char ch;
	for(int i = 0; i < len; i++) {
		if(flag && str[i] == ch) continue;
		if(!vis[i]) {
			flag = true;
			ch = str[i];
			vis[i] = true;
			ans[cur] = str[i];
			dfs(cur + 1, len);
			vis[i] = false;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str);	
		int len = strlen(str);
		sort(str, str + len);
		dfs(0, len);
		printf("\n");
	}
	return 0;
}
