#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN];
int b[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]]++;
	bool flag = false;
	for(int i = 1; i <= n; i++)
		if(b[a[i]] == 1) {
			printf("%d\n", a[i]);
			flag = true;
			break;
		}
	if(!flag) printf("None\n");
	return 0;
}
