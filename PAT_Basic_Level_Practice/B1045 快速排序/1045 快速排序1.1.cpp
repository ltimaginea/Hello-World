//此枚举法部分测试用例会超时！ 
#include <iostream>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
int n[100010] = { 0 }, need[100010] = { 0 }, cnt = 0;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
	}
	int left_max = -1, right_min = (int)1E9 + 10;
	int flag_min = 0;
	for (int j = 0; j < N; j++)
	{
		flag_min = 0;
		if (j == 0) {
			for (int i = 1; i < N; i++)
			{
				right_min = min(n[i], right_min);
			}
			if (n[j] < right_min) { need[cnt++] = n[j]; }
		}
		else if (j == N - 1) {
			left_max = max(left_max, n[j - 1]);
			if (n[j] > left_max) need[cnt++] = n[j];
		}
		else {
			left_max = max(left_max, n[j - 1]);
			if (n[j] != right_min) flag_min = 1;
			else right_min = (int)1E9 + 10;
			if (flag_min == 0) {
				for (int i = j + 1; i < N; i++) {
					right_min = min(right_min, n[i]);
				}
			}
			if (left_max<n[j] && right_min>n[j]) need[cnt++] = n[j];
		}
	}
	printf("%d\n", cnt);
	sort(need,need+cnt);//排序步骤其实可以没有，根据题意“比左大，比右小”，则按序输出必定属于增序 
	for (int z = 0; z < cnt; z++) {
		if (z == 0)printf("%d", need[z]);
		else printf(" %d", need[z]);
	}
	printf("\n");
	return 0;
}
