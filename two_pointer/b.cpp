#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[1000010];
int vis[1000010];

struct Node {
	int val, cur;
};

Node node[1000010];

bool cmp(Node x, Node y) {
	return x.val < y.val;
}

int main() {
	int p;
	while(~scanf("%d", &p)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= p; i++) {
			scanf("%d", &node[i].val);
			node[i].cur = i;
		}	
		sort(node + 1, node + 1 + p, cmp);
		int k = 0;
		a[node[1].cur] = k;
		for(int i = 2; i <= p; i++) {
			if(node[i].val == node[i - 1].val)
				a[node[i].cur] = k;
			else 
				a[node[i].cur] = ++k;
		}
		int ans = INF;
		int l = 1;
		int r = 0;
		int num = 0;
		while(1) {
			if(num == k + 1) {
				if(r - l + 1 < ans) ans = r - l + 1;
				vis[a[l]]--;	
				if(!vis[a[l]]) num--;
				l++;
			}		
			else {
				r++;
				if(r > p) break;
				if(!vis[a[r]]) num++;
				vis[a[r]]++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
