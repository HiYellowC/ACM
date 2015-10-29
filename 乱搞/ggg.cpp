#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

set <int> S;

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int high;
		S.clear();
		for(int i = 1; i <= n; i++) {
			scanf("%d", &high);
			set <int> :: iterator it = S.begin();
			for(; it != S.end(); it++)
				if(*it >= high) {
					S.erase(it);
					break;
				}
			S.insert(high);
		}	
		printf("%d\n", (int)S.size());
	}
	return 0;
}
