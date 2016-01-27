#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define Max 150010
using namespace std;

struct Per {
	char name[210];
	int val, cur;
	friend bool operator < (Per x, Per y) {
		if(x.val == y.val)
			return x.cur > y.cur;
		return x.val < y.val;
	}
};

Per per[Max];

pair <int, int> P[Max];

bool cmp(pair <int, int> x, pair <int, int> y) {
	return x.first < y.first;
}

priority_queue <Per> Q;
int ans[Max];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int k, m, q;
		scanf("%d%d%d", &k, &m, &q);
		for(int i = 1; i <= k; i++) {
			scanf("%s%d", per[i].name, &per[i].val);
			per[i].cur = i;
		}
		for(int i = 1; i <= m; i++)
			scanf("%d%d", &P[i].first, &P[i].second);
		sort(P + 1, P + 1 + m, cmp);
		int dex = 1;
		int adex = 0;
		for(int i = 1; i <= k; i++) {
			Q.push(per[i]);
			while(dex <= m && P[dex].first == i) {
				while(P[dex].second-- && !Q.empty()) {
					ans[++adex] = Q.top().cur;
					Q.pop();
				}
				dex++;
			}
		}	
		while(!Q.empty()) ans[++adex] = Q.top().cur, Q.pop();
		while(q--) {
			int T;
			scanf("%d", &T);
			printf("%s%c", per[ans[T]].name, " \n"[!q]);
		}
	}
	return 0;
}
