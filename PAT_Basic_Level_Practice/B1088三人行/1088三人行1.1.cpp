#include <iostream>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int M, X, Y;
	scanf("%d%d%d", &M, &X, &Y);
	int a = 100, A = 100;
	for (a = 99; a >=10;--a )
	{
		A = A - 10;
		//for (--a; a > A; a--)
		{
			if (X * (a % 10 * 10 + a / 10) == Y * fabs(a - a % 10 * 10 - a / 10)) break;
		}
		//if (a != A) break;
	}
	if (a == 9) {
		printf("No Solution\n");
		return 0;
	}
	int b = a % 10 * 10 + a / 10;
	double c = b / (1.0*Y);
	printf("%d", a);
	if (M > a) printf(" Gai");
	else if (M < a) printf(" Cong");
	else printf(" Ping");
	if (M > b) printf(" Gai");
	else if (M < b) printf(" Cong");
	else printf(" Ping");
	if (M > c) printf(" Gai");
	else if (M < c) printf(" Cong");
	else printf(" Ping\n");
	return 0;
}
