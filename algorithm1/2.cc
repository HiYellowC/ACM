#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int array[MAXN];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) scanf("%d", &array[i]);
	sort(array + 1, array + 1 + n);
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		int *it = find(array + 1, array + 1 + n, x - array[i]);
		if(it != array + 1 + n && it != array + i) {
			flag = true;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
