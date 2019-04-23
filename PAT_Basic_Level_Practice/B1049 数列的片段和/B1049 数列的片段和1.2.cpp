#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	double temp, sum = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &temp);
		sum += temp * (n + 1 - i)*i;
	}
	printf("%.2lf\n", sum);
	return 0;
}