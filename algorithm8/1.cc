#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n;
int p[MAXN], tmp[MAXN];

bool Place(int k) {
	for(int j = 1; j < k; j++)
		if((abs(k - j) == abs(p[j] - p[k])) || (p[j] == p[k])) return false;
	return true;
}

bool QueensLV() {
	srand(time(NULL));
	int k = 1;
	int count = 1;
	while((k <= n) && (count > 0)) {
		count = 0;
		for(int i = 1; i <= n; i++) {
			p[k] = i;
			if(Place(k)) tmp[count++] = i;
		}
		if(count > 0) p[k++] = tmp[rand() % count];
	}
	return count;
}

int main() {
	scanf("%d", &n);
	memset(p, 0, sizeof(p));
	memset(tmp, 0, sizeof(tmp));
	while(!QueensLV());
	for(int i = 1; i <= n; i++) printf("%d: %d\n", i, p[i]);
	return 0;
}
