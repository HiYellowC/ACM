#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 1000010
using namespace std;

int a[Max];
int Qmax[Max], Qmin[Max];
int ans1[Max], ans2[Max];

int main() {
	int n, k;
	while(~scanf("%d%d", &n, &k)) {
		int lmax, rmax, lmin, rmin;
		lmax = lmin = 1;
		rmax = rmin = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			while(lmax <= rmax && a[i] > a[Qmax[rmax]]) rmax--;
			while(lmin <= rmin && a[i] < a[Qmin[rmin]]) rmin--;
			Qmax[++rmax] = Qmin[++rmin] = i;
			if(Qmax[lmax] < i - k + 1) lmax++;
			if(Qmin[lmin] < i - k + 1) lmin++;
			ans1[i] = a[Qmax[lmax]];
			ans2[i] = a[Qmin[lmin]];
		}		
		for(int i = k; i <= n; i++) {
			printf("%d", ans2[i]);
			if(i < n) printf(" ");
		}
		printf("\n");
		for(int i = k; i <= n; i++) {
			printf("%d", ans1[i]);
			if(i < n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
