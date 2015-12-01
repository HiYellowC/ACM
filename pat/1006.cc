#include <bits/stdc++.h>
using namespace std;

string name[1010];
vector <pair<int, int> > V;

bool cmp(pair <int, int> x, pair <int, int> y) {
	return x.second < y.second;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		V.clear();
		int a, b, c;
		for(int i = 1; i <= n; i++) {
			cin >> name[i];
			scanf("%d:%d:%d", &a, &b, &c);
			V.push_back(make_pair(i, a * 3600 + b * 60 + c));
			scanf("%d:%d:%d", &a, &b, &c);
			V.push_back(make_pair(i, a * 3600 + b * 60 + c));
		}	
		sort(V.begin(), V.end(), cmp);
		int size = (int)V.size() - 1;
		cout << name[V[0].first] << " " << name[V[size].first] << endl;
}
	return 0;
}
