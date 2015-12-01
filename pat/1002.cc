#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

vector <pair <int, double> > V1, V2, V;

int main() {
	int k1, k2;
	scanf("%d", &k1);
	int a;
	double b;
	for(int i = 1; i <= k1; i++) {
		scanf("%d%lf", &a, &b);
		V1.push_back(make_pair(a, b));
	}
	scanf("%d", &k2);
	for(int i = 1; i <= k2; i++) {
		scanf("%d%lf", &a, &b);
		V2.push_back(make_pair(a, b));
	}
	int l1, l2;
	l1 = l2 = 0;
	while(l1 < k1 && l2 < k2) {
		if(V1[l1].first == V2[l2].first) {
			if(fabs(V1[l1].second + V2[l2].second) > eps) V.push_back(make_pair(V1[l1].first, V1[l1].second + V2[l2].second));	
			l1++, l2++;
		}	
		else if(V1[l1].first < V2[l2].first) {
			V.push_back(V2[l2]);
			l2++;
		}
		else {
			V.push_back(V1[l1]);
			l1++;
		}
	}
	while(l1 < k1) V.push_back(V1[l1]), l1++;
	while(l2 < k2) V.push_back(V2[l2]), l2++;
	printf("%d", (int)V.size());
	if((int)V.size()) printf(" ");
	for(int i = 0; i < V.size(); i++) {
		printf("%d %.1lf", V[i].first, V[i].second);
		if(i < V.size() - 1) printf(" ");
	}
	printf("\n");
	return 0;
}
