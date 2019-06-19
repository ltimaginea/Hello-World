#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)
int main()
{
	int N, n[200] = { 0 }, num = 0, cnt = 0;
	scanf("%d", &N);
	int NN = N, I = N;
	int sqr = (int)(sqrt(1.0*N));
	for (int i = 2; i <= sqr; i++)
	{
		NN = N; num = 0;
		for (int j = i; (j <= sqr)&&(NN!=1); j++)
		{
			if (NN%j == 0)
			{
				num++;
				NN /= j;
			}
			else break;
			
		}
		if (cnt < num) {
			cnt = num; I = i;
		}
	}
	if (cnt == 0)
	{
		printf("1\n%d\n", I);
		return 0;
	}
	printf("%d\n", cnt);
	
	for (int z = 0; z < cnt; z++)
	{
		if (z == 0) printf("%d", I);
		else printf("*%d", ++I);
	}
	return 0;
}
