#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int change(int n,int *a,int *b)
{
	int N[4] = { 0 };
	*a = 0; *b = 0;
	for (int i = 0; i < 4; i++)
	{
		N[i] = n % 10;
		n /= 10;
	}
	sort(N, N + 4);
	int product = 1000;
	for (int i = 0; i < 4; i++) {

		*b += N[i] * product;
		product /= 10;
	}
	sort(N, N + 4, cmp);
	*a = N[0] * 1000 + N[1] * 100 + N[2] * 10 + N[3];
	n = *a - *b;
	return n;
}
int main()
{
	int N;
	cin >> N;
	if (N / (N % 10) == 1111) {
		printf("%4d - %4d = 0000\n", N, N);
		return 0;
	}
	int a = 0, b = 0;
	do {
		N = change(N, &a, &b);
		printf("%04d - %04d = %04d\n", a, b, N);
	} while (N != 6174);
	return 0;
}