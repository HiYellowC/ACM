#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int Array[1010];
int ans[1010][1010];

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++)
		scanf("%d", &Array[i]);
	memset(ans, 0, sizeof(ans));
	for(int i = 2; i <= N; i++) {
		int num = 0;
		for(int k = 1; k <= i; k++)
			if(Array[k] > Array[i])
				num++;
			ans[1][i] = ans[1][i - 1] + num;
	}
	for(int i = 2; i <= N; i++) {
		int num = 0;
		for(int k = i; k <= N; k++) {
			if(Array[k] < Array[i - 1])
				num++;
			ans[i][k] = ans[i - 1][k] - num;	
		}	
	}
	int a, b;
	for(int i = 1; i <= Q; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", ans[a][b]);
	}
	return 0;
}
