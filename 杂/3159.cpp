#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#define Max 150010
#define INF1 0x3f3f3f3f
#define INF2 -1
using namespace std;

int Start[30010], Next[Max], End[Max], Val[Max];
int dis[30010];
bool book[30010];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b, c;
	memset(Start, INF2, sizeof(Start));
	memset(dis, INF1, sizeof(dis));
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		Next[i] = Start[a];
		Start[a] = i;
		End[i] = b;
		Val[i] = c;
	}	
	stack <int> Q;
	Q.push(1);
	dis[1] = 0;
	book[1] = 1;
	while(!Q.empty()) {
		int t = Q.top();
		int s = Start[t];
		Q.pop();
		book[t] = 0;
		while(s != -1) {
			int e = End[s];
			if(dis[e] > dis[t] + Val[s]) {
				dis[e] = dis[t] + Val[s];
				if(!book[e]) {
					Q.push(e);
					book[e] = 1;
				}
			}
			s = Next[s];
		}
	}
	printf("%d\n", dis[n]);
	return 0;
}
