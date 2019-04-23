#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int temp[100010], t[5000][5000];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", temp + i);
	}
	sort(temp, temp + N);
	reverse(temp, temp + N);
	int n, m;
	int sqr = (int)sqrt(N);
	n = sqr; m = sqr;
	while (m*n != N)
	{
		if (m*n < N) {
			m++;
		}
		if (m*n > N) {
			n--;
		}
	}
	if (n == 1)
	{
		for (int i = 0; i < N; i++)
			printf("%d\n", temp[i]);
		return 0;
	}
	int s = 0, I;
	for (int i = 0,j=0;;i++)
	{
		for (j = i; j < n - i; j++)
		{
			t[i][j] = temp[s++];
		}
		j--;
		if (s == N) {  break; }
		I = i;
		for (I++; I < m - i;I++)
		{
			t[I][j] = temp[s++];
		}
		I--;
		if (s == N) {  break; }
		for (j--; j >= i; j--)
		{
			t[I][j] = temp[s++];
		}
		j++;
		if (s == N) {  break; }
		for (I--; I > i; I--)
		{
			t[I][j] = temp[s++];
		}
		if (s == N) {  break; }
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0) printf("%d", t[i][j]);
			else printf(" %d", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}
