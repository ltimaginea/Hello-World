#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
bool isPrime(ll m)
{
	if (m < 2) return false;
	else
	{
		ll sqr = (ll)(sqrt(m));
		for (int i = 2; i <= sqr; i++)
		{
			if (m%i == 0) return false;
		}
		return true;
	}
}
int main()
{
	ll N, D;
	ll n[100]={0}, num = 0;
	scanf("%lld", &N);
	for (; N >= 0;)
	{
		num = 0;
		scanf("%lld", &D);
		if (isPrime(N) == false)
		{
			printf("No\n");
		}
		else
		{
			do {
				n[num++] = N % D;
				N /= D;
			} while (N != 0);
			ll product = 1;
			for (ll z = --num; z >= 0; z--)
			{
				N += n[z] * product;
				product *= D;
			}
			if (isPrime(N)) printf("Yes\n");
			else printf("No\n");
		}
		scanf("%lld", &N);
	}
	return 0;
}
