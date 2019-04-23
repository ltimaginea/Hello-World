#include <cstdio>
#include <cstring>
#pragma warning (disable:4996)
struct
{
	int a;
	int b;
}n[10010];
bool hashTable[100000];
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &n[i].a, &n[i].b);
	}
	for (int i = 0; i < M; i++)
	{
		memset(hashTable, false, sizeof(hashTable));
		int t, temp;
		scanf("%d", &t);
		for (int j = 0; j < t; j++)
		{
			scanf("%d", &temp);
			hashTable[temp] = true;
		}
		int z;
		for ( z = 0; z < N; z++)
		{
			if (hashTable[n[z].a] == true && hashTable[n[z].b] == true) break;
		}
		if (z == N) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
