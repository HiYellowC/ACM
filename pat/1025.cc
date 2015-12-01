#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Stu {
	LL id;
	int score;
	int city;
	friend bool operator< (Stu x, Stu y) {
		return x.score > y.score;	
	}
};

vector <Stu> ALL, V[110];

bool cmp(Stu x, Stu y) {
	return x.score > y.score || (x.score == y.score && x.id < y.id);
}

int main() {
	int n, nn = 1;
	scanf("%d", &n);
	while(n--) {
		int k;
		LL id;
		int score;
		scanf("%d", &k);
		while(k--) {
			scanf("%lld%d", &id, &score);
			V[nn].push_back((Stu){id, score, nn});
			ALL.push_back((Stu){id, score, nn});
		}
		nn++;
	}
	sort(ALL.begin(), ALL.end(), cmp);
	for(int i = 1; i < nn; i++) sort(V[i].begin(), V[i].end(), cmp);
	printf("%d\n", (int)ALL.size());
	for(int i = 0; i < ALL.size(); i++) {
		int c = ALL[i].city;
		printf("%013lld %d %d %d\n", ALL[i].id, (int)(lower_bound(ALL.begin(), ALL.end(), ALL[i]) - ALL.begin() + 1), c, (int)(lower_bound(V[c].begin(), V[c].end(), ALL[i]) - V[c].begin() + 1));	
	}
	return 0;
}
