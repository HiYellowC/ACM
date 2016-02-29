#include <bits/stdc++.h>
using namespace std;

int X[30], Y[30], Z[30];

int main() {
	int t;
	int num = 2;
	scanf("%d", &t);
	while(t--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		memset(Z, 0, sizeof(Z));
		char ch[2];
		int num;
		for(int i = 1; i <= x; i++) {
			scanf("%s%d", ch, &num);
			X[ch[0] - 'A'] += num;
		}
		for(int i = 1; i <= y; i++) {
			scanf("%s%d", ch, &num);
			Y[ch[0] - 'A'] += num;
		}
		for(int i = 1; i <= z; i++) {
			scanf("%s%d", ch, &num);
			Z[ch[0] - 'A'] += num;
		}
		bool flag;
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				flag = true;
				for(int k = 0; k < 26; k++)
					if(i * X[k] + j * Y[k] != Z[k]) {flag = false; break;}
				if(flag) {
					printf("%d %d\n", i, j);	
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}
