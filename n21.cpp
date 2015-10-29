#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

struct sta {
	int x, y, z, time;
};

bool flag[100][100][100];
int v[3];
int e1, e2, e3;
int ans;

void bfs() {
	sta s = (sta){v[0], 0, 0, 0};
	queue<sta>Q;
	Q.push(s);
	flag[v[0]][0][0] = true;
	int n1, n2;
	while(!Q.empty()) {
		int a[3], t, i, k;
		a[0] = Q.front().x;
		a[1] = Q.front().y;
		a[2] = Q.front().z;
		t = Q.front().time;
		if(a[0] == e1 && a[1] == e2 && a[2] == e3) {
			ans = t;
			break;
		}
		t += 1;
		Q.pop();
		for(i = 0; i < 3; i++)
			for(k = 0; k < 3; k++) {
				if(i != k) {
					n1 = a[i] + a[k] > v[k] ? a[i] + a[k] - v[k] : 0;
					n2 = a[i] + a[k] > v[k] ? v[k] : a[i] + a[k];
					if(n1 != a[i] || n2 != a[k]) {
						if(i == 0 && k == 1 && !flag[n1][n2][a[2]]) {
							flag[n1][n2][a[2]] = 1;
							Q.push((sta){n1, n2, a[2], t});
						}
						else if(i == 0 && k == 2 && !flag[n1][a[1]][n2]) {
							flag[n1][a[1]][n2] = 1;
							Q.push((sta){n1, a[1], n2, t});
						}
						else if(i == 1 && k == 0 && !flag[n2][n1][a[2]]) {
							flag[n2][n1][a[2]] = 1;
							Q.push((sta){n2, n1, a[2], t});
						}
						else if(i == 1 && k == 2 && !flag[a[0]][n1][n2]) {
							flag[a[0]][n1][n2] = 1;
							Q.push((sta){a[0], n1, n2, t});
						}
						else if(i == 2 && k == 0 && !flag[n2][a[1]][n1]) {
							flag[n2][a[1]][n1] = 1;
							Q.push((sta){n2, a[1], n1, t});
						}
						else if(i == 2 && k == 1 && !flag[a[0]][n2][n1]){
							flag[a[0]][n2][n1] = 1;
							Q.push((sta){a[0], n2, n1, t});
						}
					}
				}
			}
	}
}

int main() {
	int total;
	scanf("%d", &total);
	while(total--) {
		memset(flag, 0, sizeof(flag));
		scanf("%d%d%d", &v[0], &v[1], &v[2]);
		scanf("%d%d%d", &e1, &e2, &e3);
		ans = -1;
		bfs();
		printf("%d\n", ans);
	}
	return 0;
}
