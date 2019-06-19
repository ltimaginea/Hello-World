#include <iostream>
#pragma warning(disable:4996)
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 1;
set<int> name[maxn];
int change(char *s)
{
	int number = 0, product = 1;
	for (int i = 0; i < 3; i++)
	{
		number += (s[i] - 'A')*product;
		product *= 26;
	}
	number = number * 10 + (s[3] - '0');
	return number;
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int ni, ki;
		scanf("%d%d", &ki, &ni);
		for (int j = 0; j < ni; j++)
		{
			char s[10];
			scanf("%s", s);
			int number = change(s);
			name[number].insert(ki);
		}
	}
	for (int i = 0; i < N; i++)
	{
		char s[10];
		scanf("%s", s);
		int number = change(s);
		int n = name[number].size();
		printf("%s %d", s, n);
		set<int>::iterator it1 = name[number].begin(), it2 = name[number].end();
		for (; it1 != it2;)
		{
			printf(" %d", *it1);
			++it1;
		}
		printf("\n");
	}
	return 0;
}