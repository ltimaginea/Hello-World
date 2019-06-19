#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
#define maxn 1000000
using namespace std;
typedef long long ll;
ll prime[maxn], num;
bool prim[maxn];
void FindPrime()
{
	fill(prim, prim + maxn, true);
	for (int i = 2; i < maxn; i++)
	{
		if (prim[i])
		{
			prime[num++] = i;
			for (int j = i + i; j < maxn; j += i)
			{
				prim[j] = false;
			}
		}
	}
}
ll change1(ll a,ll D)
{
	ll s = 0, product = 1;
	for (; a != 0;)
	{
		s += a % D*product;
		product *= 10;
		a /= D;
	}
	return s;
}
ll change2(ll a, ll D)
{
	ll s = 0, product = 1;
	for (; a != 0;)
	{
		s += a % 10 * product;
		a /= 10;
		product *= D;
	}
	return s;
}
int main()
{
	FindPrime();
	prim[0] = false; prim[1] = false;
	ll N, D;
	char n[100];
	scanf("%lld", &N);
	for (; N > 0;)
	{
		scanf("%lld", &D);
		if (prim[N] == false)
		{
			printf("No\n");
		}
		else
		{
			N = change1(N, D);
			sprintf(n, "%lld", N);
			ll len = strlen(n);
			reverse(n, n + len);
			sscanf(n, "%lld", &N);
			N = change2(N, D);
			if (prim[N]) printf("Yes\n");
			else printf("No\n");
		}
		scanf("%lld", &N);
	}
	return 0;
}
