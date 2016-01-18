#include <bits/stdc++.h>
using namespace std;

struct Node{
	char str[25];
	int len;
};

Node node[20010];

bool cmp(Node x, Node y) {
	return (x.len < y.len || (x.len == y.len && strcmp(x.str, y.str) < 0));
}

int main() {
	int t, tt = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%s", node[i].str);
			node[i].len = strlen(node[i].str);
		}
		sort(node + 1, node + 1 + n, cmp);
		int q;
		printf("Case %d:\n", tt++);
		scanf("%d", &q);
		while(q--) {
			char str[25];
			scanf("%s", str);
			int i;
			for(i = 1; i <= n; i++) {
				if(strstr(node[i].str, str) == node[i].str) {
					printf("%s\n", node[i].str);
					break;
				}
			}
			if(i == n + 1) printf("-1\n");
		}
	}
	return 0;
}
