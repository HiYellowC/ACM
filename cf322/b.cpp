#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

int h[MAXN];
int ans[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	int Max = h[n] - 1;
	for(int i = n; i >= 1; i--) {
		if(h[i] > Max) ans[i] = 0, Max = h[i];
		else ans[i] = Max + 1 - h[i];
	}
	for(int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}
