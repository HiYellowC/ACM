#include <bits/stdc++.h>
using namespace std;

pair <int, double> a1[15], a2[15];
double ans[2010];

int main() {
	int n1, n2;
	scanf("%d", &n1);
	for(int i = 1; i <= n1; i++) scanf("%d%lf", &a1[i].first, &a1[i].second);
	scanf("%d", &n2);
	for(int i = 1; i <= n2; i++) scanf("%d%lf", &a2[i].first, &a2[i].second);
	int Max = 0;
	for(int i = 1; i <= n1; i++)
		for(int j = 1; j <= n2; j++)
			ans[a1[i].first + a2[j].first] += (a1[i].second * a2[j].second), Max = max(Max, a1[i].first + a2[j].first);
	int con = 0;
	for(int i = 0; i <= Max; i++)
		if(fabs(ans[i]) > 1e-8) con++;
	printf("%d", con);
	if(con) printf(" ");
	for(int i = Max; i >= 0; i--) {
		if(!con) break;
		if(fabs(ans[i]) > 1e-8) {
			con--, printf("%d %.1lf", i, ans[i]);
			if(con) printf(" ");
		}
	}
	printf("\n");	
	return 0;
}
