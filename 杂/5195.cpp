#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
#define Max 100010
using namespace std;

priority_queue<int>Q;
int dex;
int in[Max];
int s[Max], Next[Max], to[Max];
bool flag[Max];

void BuildG(int a, int b) {
	Next[dex] = s[a];
	s[a] = dex;
	to[dex++] = b;
	in[b]++;
}

int main() {
	int i, n, m, k;
	int a, b;
	int v;
	int num;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		dex = 1;
		num = 0;
		for(i = 1; i <= n; i++) {
			s[i] = -1;
			in[i] = 0;
			flag[i] = 0;
		}
		for(i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			BuildG(a, b);
		}
		for(i = 1; i <= n; i++)
			if(in[i] <= k) {
				Q.push(i);
				flag[i] = 1;
			}
		while(!Q.empty()) {
			v = Q.top();
			Q.pop();
			flag[v] = 0;
			if(in[v] <= k) {
				printf("%d", v);
				num++;
				if(num < n)
					printf(" ");
				else
					printf("\n");
				k -= in[v];
				flag[v] = 1;
				for(i = s[v]; i != -1; i = Next[i]) {
					in[to[i]]--;
					if(!flag[to[i]] && in[to[i]] <= k) {
						flag[to[i]] = 1;
						Q.push(to[i]);
					}
				}
			}
		}
	}
	return 0;
}
