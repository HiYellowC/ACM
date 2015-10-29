#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 100010
using namespace std;

int a[Max];
int Qmin[Max], Qmax[Max];

int main() {
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		int lmax, rmax, lmin, rmin, ans;
		ans = lmax = rmax = lmin = rmin = 0;
		int now = 1;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			while(lmax < rmax && a[i] > a[rmax]) rmax--;
			while(lmin < rmin && a[i] < a[rmin]) rmin--;
			Qmin[rmin++] = i, Qmax[rmax++] = i;
			while(lmax < rmax && lmin < rmin && a[Qmax[lmax]] - a[Qmin[lmin]] > k) {
				if(Qmax[lmax] < Qmin[lmin])	now = Qmax[lmax++] + 1;
				else now = Qmin[lmin++] + 1;
			}
			if(lmax < rmax && lmin < rmin && a[Qmax[lmax]] - a[Qmin[lmin]] >= m)
				ans = max(ans, i - now + 1);
		}	
		printf("%d\n",ans);
	}
	return 0;
}
