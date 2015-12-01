#include <bits/stdc++.h>
using namespace std;

bool flag[10010];
vector <int> V;

void Init() {
	for(int i = 2; i < 10010; i++) {
		if(!flag[i]) {
			V.push_back(i);
			for(int k = i + i; k < 10010; k += i) flag[k] = true;
		}
	}
}

int main() {
	Init();
	int n, m;
	scanf("%d%d", &n, &m);
	int k = *lower_bound(V.begin(), V.end(), n);
	int num;
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= m; i++) {
		scanf("%d", &num);
		int j;
		for(j = 0; j < k; j++) {
			if(flag[(num + j * j) % k] == false) {
				printf("%d", (num + j * j) % k);
				flag[(num + j * j) % k] = true;
				break;
			}	
		}
		if(j == k) printf("-");
		printf("%c", " \n"[i == m]);
	}
	return 0;
}
