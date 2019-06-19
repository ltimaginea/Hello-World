#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)
#define maxn 100000
using namespace std;
int prime[maxn], num = 0, z = 0;
bool p[maxn];
struct Su{
	int a;
	int cnt;
	Su()
	{
		a = 0;
		cnt = 0;
	}
}n[100];
void findPrime()
{
	fill(p, p + maxn, true);
	for (int i = 2; i < maxn; i++)
	{
		if (p[i])
		{
			prime[num++] = i;
			for (int j = i + i; j < maxn; j += i)
			{
				if (p[j]) p[j] = false;
			}
		}
	}
}
int main()
{
	findPrime();
	p[0] = false; p[1] = false;
	int NN,N;
	scanf("%d", &NN);
	N = NN;
	if (N == 1)
	{
		printf("1=1");
		return 0;
	}
	int sqr = (int)(sqrt(N));
	for (int i = 0; prime[i] <= sqr&&N!=1; i++)
	{
		if (N%prime[i] == 0)
		{
			n[z].a = prime[i];
			for (; N%prime[i] == 0;)
			{
				N /= prime[i];
				n[z].cnt++;
			}
			z++;
		}

	}
	printf("%d=", NN);
	for (int i = 0; i < z; i++)
	{
		if (i == 0) {
			if (n[i].cnt == 1) printf("%d", n[i].a);
			else printf("%d^%d", n[i].a, n[i].cnt);
		}
		else
		{
			if (n[i].cnt == 1) printf("*%d", n[i].a);
			else printf("*%d^%d", n[i].a, n[i].cnt);
		}

	}
	if (N != 1)
	{
		if (z != 0) printf("*%d", N);
		else printf("%d", N);
	}
	return 0;
}
