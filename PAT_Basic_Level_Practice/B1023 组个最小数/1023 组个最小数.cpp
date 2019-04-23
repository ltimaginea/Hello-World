#include <iostream>
//#include <cstdio>
//#pragma warning(disable:4996)
using namespace std;
int main()
{
	int n[12];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &n[i]);
	}
	int flag = 0;
	for (int i = 1; i < 10; i++)
	{
		if (n[i] == 0) continue;
		printf("%d", i);
		if (flag == 0)
		{
			if (n[0] != 0) {
				for (int z = 1; z <= n[0]; z++)
				{
					printf("%d", 0);
				}
			}
		}
		flag = 1;
		for (int j = 1; j < n[i]; j++)
		{
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}