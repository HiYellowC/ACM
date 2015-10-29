#include <stdio.h>
#include <string.h>

int P, N;
int body[301];
bool match[101][301];
bool vis[301];

bool fun(int u) {
	int i;
	for(i = 1; i <= N; i++) {
		if(!vis[i] && match[u][i]) {
			vis[i] = 1;
			if(!body[i] || fun(body[i])) {
				body[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int i, k;
	int con, stu, total, sum;
	scanf("%d", &total);
	while(total--) {
		scanf("%d%d", &P, &N);
		sum = 0;
		memset(match, 0, sizeof(match));
		memset(body, 0, sizeof(body));
		for(i = 1; i <= P; i++) {
			scanf("%d", &con);
			for(k = 1; k <= con; k++) {
				scanf("%d", &stu);
				match[i][stu] = 1;
			}
		}
		for(i = 1; i <= P; i++) {
			memset(vis, 0, sizeof(vis));
			if(fun(i))
				sum++;
		}
		if(sum == P)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
