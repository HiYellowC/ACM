#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int l;
	scanf("%d", &l);
	int q, p;
	scanf("%d%d", &q, &p);
	printf("%lf\n", (double)(l) * (double)(q) / (double)(q + p));
	return 0;
}
