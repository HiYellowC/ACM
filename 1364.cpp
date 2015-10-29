#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int S[110], E[110], V[110];
int dis[110];

bool bell() {
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int k = 1; k <= m; k++)
			if(dis[E[k]] > dis[S[k]] + V[k])
				dis[E[k]] = dis[S[k]] + V[k];
	for(int k = 1; k <= m; k++)
		if(dis[E[k]] > dis[S[k]] + V[k])
			return true;
	return false;
}

int main() {
	while(~scanf("%d", &n) && n) {
		scanf("%d", &m);
		int a, b, c;
		char str[10];
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%s%d", &a, &b, str, &c);
			if(str[0] == 'g')
				S[i] = a - 1, E[i] = a + b, V[i] = -c - 1;	
			else
				S[i] = a + b, E[i] = a - 1, V[i] = c - 1;
		}
		if(bell())
			printf("successful conspiracy\n");
		else
			printf("lamentable kingdom\n");
	}
	return 0;
}
