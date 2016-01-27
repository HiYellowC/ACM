#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> V[510][510];
int a[510], b[510];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);	
		for(int i = 1; i <= m; i++)
			scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) {
			for(int k = 1; k <= m; k++) {
				if(a[i] == b[k]) {
					bool flag = false;
					for(int l = 0; l < V[i - 1][k - 1].size(); l++)
						if(!flag && a[i] <= V[i - 1][k - 1][l])
							V[i][k].push_back(a[i]), flag = 1;
						else
							V[i][k].push_back(V[i - 1][k - 1][l]);
					if(!flag)
						V[i][k].push_back(a[i]);
				}	
				else {
					int size1 = V[i - 1][k].size();
					int size2 = V[i][k - 1].size();
					if(size1 == 0 && size2 == 0) continue;
					if(size1 > size2)
						for(int l = 0; l < size1; l++)
							V[i][k].push_back(V[i - 1][k][l]);
					else if(size1 < size2)
						for(int l = 0; l < size2; l++)
							V[i][k].push_back(V[i][k - 1][l]);
					else {
						if(V[i - 1][k][size1 - 1] < V[i][k - 1][size2 - 1])	
							for(int l = 0; l < size1; l++)
								V[i][k].push_back(V[i - 1][k][l]);
						else
							for(int l = 0; l < size2; l++)
								V[i][k].push_back(V[i][k - 1][l]);
					}
				}
			}	
		}
		printf("%d\n", (int)V[n][m].size());
		if(t)
			printf("\n");
		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= m; k++)
				V[i][k].clear();
	}
	return 0;
}
