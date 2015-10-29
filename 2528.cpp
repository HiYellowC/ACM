#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int place[20010][2];
int section[80010];
int result[80010 << 2];
bool vis[20010];
int RES;

bool cmp(const int a, const int b) {
	return a < b;
}

void build_tree(int left, int right, int i) {
	if(left == right)
		return ;
	int mid = (left + right) >> 1;
	build_tree(left, mid, i << 1);
	build_tree(mid + 1, right, i << 1 | 1);
	result[i] = 0;
}

int search(int n, int left, int right) {
	int mid = (left + right) >> 1;
	while(section[mid] != n) {
		if(section[mid] > n)
			right = mid;
		else
			left = mid;
		mid = (left + right) >> 1;
	}
	return mid;
}

void change_tree(int left, int right, int tleft, int tright, int col, int i) {
	if(left == tleft && right == tright) {
		result[i] = col;
		return ;
	}
	if(result[i] > 0) {
		result[i << 1] = result[i << 1 | 1] = result[i];
		result[i] = 0;
	}
	int mid = (tleft + tright) >> 1;
	if(right <= mid)
		change_tree(left, right, tleft, mid, col, i << 1);
	else if(left >= mid + 1)
		change_tree(left, right, mid + 1, tright, col, i << 1 | 1);
	else {
		change_tree(left, mid, tleft, mid, col, i << 1);
		change_tree(mid + 1, right, mid + 1, tright, col, i << 1 | 1);
	}
}

void search_tree(int i) {
	if(result[i]) {
		if(!vis[result[i]]) {
			RES++;
			vis[result[i]] = 1;
		}
		return ;
	}
	search_tree(i << 1);
	search_tree(i << 1 | 1);
}

int main() {
	int total;
	int i, n;
	int new_left, new_right;
	int num_of_section;
	scanf("%d", &total);
	while(total--) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		RES = 0;
		num_of_section = 1;
		for(i = 1; i <= n; i++) {
			scanf("%d%d", &place[i][0], &place[i][1]);
			section[2 * i - 1] = place[i][0];
			section[2 * i] = place[i][1];
		}
		sort(section + 1, section + 2 * n + 1, cmp);
		for(i = 1; i <= 2 * n; i++)
			if(section[i] != section[i - 1])
				section[num_of_section++] = section[i];
		for(i = num_of_section - 1; i > 1; i--)
			if(section[i] - section[i - 1] > 1)
				section[num_of_section++] = section[i] - 1;
		sort(section, section + num_of_section, cmp);
		build_tree(1, num_of_section - 1, 1);
		for(i = 1; i <= n; i++) {
			new_left = search(place[i][0], 1, num_of_section);
			new_right = search(place[i][1], 1, num_of_section);
			change_tree(new_left, new_right, 1, num_of_section - 1, i, 1);
		}
		search_tree(1);
		printf("%d\n", RES);
	}
	return 0;
}
