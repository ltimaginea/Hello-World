#include <iostream>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
bool isPrime(int a)
{
	if (a <= 1) return false;
	int sqr = (int)sqrt(a);
	for (int i = 2; i <= sqr; i++)
	{
		if (a%i == 0) return false;
	}
	return true;
}
int change(char* s, int K)
{
	int a = 0;
	for (int i = 0; i < K; ++i)
		a = a * 10 + *(s + i) - '0';
	return a;
}
int main()
{
	int L, K;
	char s1[1010], *s2;
	s2 = s1;
	cin >> L >> K >> s2;
	for (int i = 0; i + K <= L; i++,s2++)
	{
		if (isPrime(change(s2, K)))
		{
			*(s2 + K) = '\0';
			cout << s2;
			return 0;
		}
	}
	cout << "404";
	return 0;
}
