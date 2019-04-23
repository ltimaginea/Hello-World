#include <iostream>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
int n[100010] = { 0 }, need[100010] = { 0 }, cnt = 0;
int left_max[100010], right_min[100010];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
	}
	left_max[0] = -1;
	right_min[N - 1] = 10 + (int)1e9;
	for (int i = 1; i < N; i++)
	{
		left_max[i] = max(left_max[i - 1], n[i - 1]);
		right_min[N - 1 - i] = min(n[N - i], right_min[N - i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (left_max[i] < n[i] && n[i] < right_min[i]) need[cnt++] = n[i];
	}
	printf("%d\n", cnt);
	//sort(need, need + cnt);
	for (int z = 0; z < cnt; z++) {
		if (z == 0)printf("%d", need[z]);
		else printf(" %d", need[z]);
	}
	printf("\n");
	return 0;
}
