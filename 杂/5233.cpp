#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define Max 100000
using namespace std;

struct Node {
	int val, cur;
};
Node node[Max + 10];

vector <int> V[Max + 10];
map <int, int> M;

bool cmp(Node a, Node b) {
	return a.val < b.val;
}

int main() {
	int n, m, num;
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &node[i].val);
			node[i].cur = i;
		}
		stable_sort(node + 1, node + n + 1, cmp);
		V[1].push_back(node[1].cur);
		M[node[1].val] = 1;
		int s = 1;
		for(int i = 2; i <= n; i++) {
			if(node[i].val == node[i - 1].val)
				V[s].push_back(node[i].cur);
			else {
				V[++s].push_back(node[i].cur);
				M[node[i].val] = s;
			}
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d", &num);
			if(M[num] == 0 || V[M[num]].size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", V[M[num]][0]);
				vector <int> :: iterator k = V[M[num]].begin();
				V[M[num]].erase(k);
			}
		}
		M.clear();
		for(int i = 1; i <= Max; i++)
			V[i].clear();
	}
	return 0;
}
