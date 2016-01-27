#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 26
#define INF 0x7f7f7f7f
using namespace std;

int num_of_stamps;
int mtotal, mcur, con, nmax, mmax;
int stamps[MAX];
int flag[MAX];
int key, ckey;
int customer[MAX];
int result[5];
int	RES[5];

bool cmp(const int a, const int b) {
	return a < b;
}

void fun(int sum, int cur, int total) {
	int i, num;
	int k;
	if(sum == 0) {
		if(total > mtotal || (total == mtotal && cur < mcur) || (total == mtotal && cur == mcur && nmax > mmax)) {
			key = 1;
			ckey = 0;
			mtotal = total;
			mcur = cur;
			mmax = nmax;
			for(i = 1; i < cur; i++)
				RES[i] = result[i];
		}
		else if(total == mtotal && cur == mcur && nmax == mmax)
			ckey = 1;
	}
	if(cur > 4)
		return ;
	for(i = con; i < num_of_stamps; i++) {
		k = 0;
		if(sum - stamps[i] >= 0) {
			con = i;
			if(nmax < stamps[i]) {
				k = 1;
				num = nmax;
				nmax = stamps[i];
			}
			result[cur] = stamps[i];
			if(flag[i] == 0) {
				flag[i] = 1;
				fun(sum - stamps[i], cur + 1, total + 1);
				flag[i] = 0;
			}
			else
				fun(sum - stamps[i], cur + 1, total);
		}
		if(k)
			nmax = num;
	}
}

int main() {
	int i, k, j;
	int value, request;
	while(~scanf("%d", &value)) {
		for(num_of_stamps = 1; value; num_of_stamps++) {
			stamps[num_of_stamps] = value;
			scanf("%d", &value);
		}
		sort(stamps + 1, stamps + num_of_stamps, cmp);
		for(i = 1; ; i++) {
			scanf("%d", &request);
			if(!request)
				break;
			customer[i] = request;
		}
		for(k = 1; k < i; k++) {
			mmax = nmax = mtotal = key = ckey = 0;
			mcur = INF;
			con = 1;
			fun(customer[k], 1, 1);
			if(key) {
				printf("%d (%d):", customer[k], mtotal - 1);
				if(ckey)
					printf(" tie");
				else {
					for(j = 1; j < mcur; j++)
						printf(" %d", RES[j]);
				}
				printf("\n");
			}
			else
				printf("%d ---- none\n", customer[k]);
		}
	}
	return 0;
}
