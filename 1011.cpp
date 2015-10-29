#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define Max 65

int lenth[Max], flag[Max];
int num_of_sticks;
int key;

bool cmp(const int a, const int b) {
	return a > b;
}

void fun(int cur, int len, int con) {
	int i;
	int new_len;
	int s = 0;
	int repeat;
	if(cur == num_of_sticks + 1 && len == 0) {
		key = 1;
		return ;
	}
	else if(key == 0) {
		for(i = 1; i <= num_of_sticks; i++) {
			new_len = len + lenth[i];
			if(s && new_len == repeat)
				continue;
			repeat = new_len;
			s = 0;
			if(!flag[i] && new_len <= con) {
				flag[i] = 1;
				if(new_len == con)
					new_len = 0;
				fun(cur + 1, new_len, con);
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
	int sum_of_lenth;
	int i;
	int max;
	while(scanf("%d", &num_of_sticks)) {
		if(!num_of_sticks)
			break;
		sum_of_lenth = 0;
		key = 0;
		max = 0;
		memset(flag, 0, sizeof(flag));
		for(i = 1; i <= num_of_sticks; i++) {
			scanf("%d", &lenth[i]);
			if(lenth[i] > max)
				max = lenth[i];
			sum_of_lenth += lenth[i];
		}
		sort(lenth + 1, lenth + 1 + num_of_sticks, cmp);
		for(i = num_of_sticks; i >= 1; i--) {
			if(sum_of_lenth % i == 0 && max <= sum_of_lenth / i)
				fun(1, 0, sum_of_lenth / i);
			if(key)
				break;
		}
		printf("%d\n", sum_of_lenth / i);
	}
	return 0;
}
