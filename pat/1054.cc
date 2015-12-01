#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int num;
	int icon = 0;
	int inum = -1;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++) {
			scanf("%d", &num);
			if(num == inum) icon++;
			else {
				icon--;
				if(icon == -1) {
					inum = num;	
					icon = 0;
				}
			}
		}
	printf("%d\n", inum);
	return 0;
}
