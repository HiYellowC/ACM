#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max 64
using namespace std;

int num_of_sticks;
int key, square;
int start1, start2;
int lenth[Max];
int flag[Max];

bool cmp(const int a, const int b) {
	return a > b;
}

void fun(int len, int cur, int con) {
	int i;
	int s;
	int last = 0;
	if(len == 0) {
		start1++;
		start2 = start1;
	}
	if(cur == num_of_sticks + 1) {
		key = 1;
		return ;
	}
	else if(!key) {
		for(i = start2; i <= num_of_sticks; i++) {
			start2 = i + 1;
			if(lenth[i] == last && s)
				continue;
			last = lenth[i];
			s = 0;
			if(!flag[i] && len + lenth[i] <= con) {
				flag[i] = 1;
				if(len + lenth[i] == con) {
					square++;
					fun(0, cur + 1, con);
				}
				else
					fun(len + lenth[i], cur + 1, con);
				flag[i] = 0;
				s = 1;
			}
			if(key)
				break;
			if(len == 0 && s)
				break;
		}
	}
}

int main() {
	int total;
	int i;
	int max, sum;
	scanf("%d", &total);
	while(total--) {
		square = key = max = sum = start1 = start2 = 0;
		scanf("%d", &num_of_sticks);
		for(i = 1; i <= num_of_sticks; i++) {
			scanf("%d", &lenth[i]);
			if(max < lenth[i])
				max = lenth[i];
			sum += lenth[i];
		}
		memset(flag, 0, sizeof(flag));
		sort(lenth + 1, lenth + 1 + num_of_sticks, cmp);
		if(sum % 4 == 0 && max <= sum / 4) {
			fun(0, 1, sum / 4);
		}
		if(key && square == 4)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
