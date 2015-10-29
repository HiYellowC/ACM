#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int a1[55];
int a2[55];
int b[55];
vector <int> V;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) scanf("%d", &a1[i]);
	for(int i = 1; i < n; i++) a1[i] += a1[i - 1];
	for(int i = 1; i < n; i++) scanf("%d", &a2[i]);
	for(int i = n - 1; i >= 1; i--) a2[i] += a2[i + 1];
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) V.push_back(b[i] + a1[i - 1] + a2[i]);
	sort(V.begin(), V.end());
	printf("%d\n", V[0] + V[1]);
	return 0;
}
