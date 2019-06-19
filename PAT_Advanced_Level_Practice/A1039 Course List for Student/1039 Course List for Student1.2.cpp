#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int N, K;
	map<string, set<int> >name;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int ni, ki;
		scanf("%d%d", &ki, &ni);
		for (int j = 0; j < ni; j++)
		{
			char s[10];
			scanf("%s", s);
			name[s].insert(ki);
		}
	}
	for (int i = 0; i < N; i++)
	{
		char str[10];
		int n;
		scanf("%s", str);
		n = name[str].size();
		printf("%s %d", str, n);
		set<int> ::iterator it1 = name[str].begin(), it2 = name[str].end();
		//sort(it1, it2);
		for (;it1!=it2;it1++)
		{
			printf(" %d", *it1);
		}
		printf("\n");
	}
	return 0;
}